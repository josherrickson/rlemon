#include "lemon/planarity.h"
#include <Rcpp.h>
#include <iostream>
#include <vector>

typedef int Value;

using namespace lemon;
using namespace std;

//' @rdname lemon_runners
// [[Rcpp::export]]
bool PlanarCheckingRunner(std::vector<int> arcSources,
                          std::vector<int> arcTargets, int numNodes) {
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  ListGraph::EdgeMap<Cost> costs(g);
  ListGraph::NodeMap<Cost> dists(g);

  std::vector<Edge> arcs;

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    ListGraph::Edge a =
        g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    arcs.push_back(a);
  }

  // NOTE: While the LEMON Documentation does indicate PlanarityChecking is an algorithm, you need to access it through _planarity_bits, for some reason
  lemon::_planarity_bits::PlanarityChecking<Graph> alg(g);
  return alg.run();
}

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List PlanarEmbeddingRunner(std::vector<int> arcSources,
                                 std::vector<int> arcTargets, int numNodes) {
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  ListGraph::EdgeMap<Cost> costs(g);
  ListGraph::NodeMap<Cost> dists(g);

  std::vector<Edge> arcs;

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    ListGraph::Edge a =
        g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    arcs.push_back(a);
  }

  // NOTE: While the LEMON Documentation does indicate PlanarityChecking is an algorithm, you need to access it through _planarity_bits, for some reason
  lemon::PlanarEmbedding<Graph> runner(g);
  int isplanar = runner.run();
  //ListDigraph::ArcMap < ListDigraph::Arc > EmbeddingMap(g);
  std::vector<int> kuratowskiSubInit;
  std::vector<int> kuratowskiSubFin;
  std::vector<int> planarEmbeddingStart;
  std::vector<int> planarEmbeddingEnd;
  if (!isplanar) {
    // Return the list of edges that are in the Kuratowski Subdivision
    for (int i = 0; i < NUM_ARCS; ++i) {
      if (runner.kuratowski(arcs[i])) {
        kuratowskiSubInit.push_back(g.id(g.u(arcs[i])) + 1);
        kuratowskiSubFin.push_back(g.id(g.v(arcs[i])) + 1);
      }
    }
  } else {
    // This required a lot of random work, but here's what it is:
    // First - Iterate over the nodes

    for (int i = 0; i < numNodes; ++i) {

      ListGraph::Arc current;
      int testMe = 0;
      for (ListGraph::OutArcIt a(g, nodes[i]); a != INVALID; ++a) {
        if (testMe == 0) {
          testMe = 1;
          current = a;
        } else {
          current = runner.next(current);
        }
        planarEmbeddingStart.push_back(g.id(g.source(current)) + 1);
        planarEmbeddingEnd.push_back(g.id(g.target(current)) + 1);
      }
    }
  }
  return Rcpp::List::create(isplanar, planarEmbeddingStart, planarEmbeddingEnd,
                            kuratowskiSubInit, kuratowskiSubFin);
}

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List PlanarColoringRunner(std::vector<int> arcSources,
                                std::vector<int> arcTargets, int numNodes,
                                bool useFiveAlg = true) {
  // Requires: arcSources and arcTargets, which define the graph's edges via the index of the source and target node, respectively.
  // The nodes are 0 indexed, where 0 refers to the first node.
  // numNodes refers to the number of nodes in the possibly unconnected graph.
  // useFiveAlg refers to the choice of algorithm used to coloring the graph. Setting this to false uses a linear time algorithm which can
  // give out six colors instead.
  Graph g;
  std::vector<Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    Node n = g.addNode();
    nodes.push_back(n);
  }

  std::vector<Edge> arcs;

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    Edge a = g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    arcs.push_back(a);
  }

  PlanarEmbedding<Graph> preprocess(g);
  bool isPlanar = preprocess.run();
  auto &embedding = preprocess.embeddingMap();

  std::vector<int> colors;
  if (isPlanar) {
    PlanarColoring<Graph> algorithm(g);
    if (useFiveAlg) {
      algorithm.runFiveColoring(embedding);
    } else {
      algorithm.runSixColoring();
    }

    for (int i = 0; i < numNodes; ++i) {
      colors.push_back(algorithm.colorIndex(nodes[i]));
    }
  }

  return Rcpp::List::create(isPlanar, colors);
}

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List PlanarDrawingRunner(std::vector<int> arcSources,
                               std::vector<int> arcTargets, int numNodes) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: A pair of std::vectors, which return the integers necessary to embed the graph onto a grid, where each edge is a straight line.
  Graph g;
  std::vector<Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    Node n = g.addNode();
    nodes.push_back(n);
  }

  std::vector<Edge> arcs;

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    Edge a = g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    arcs.push_back(a);
  }

  PlanarEmbedding<Graph> preprocess(g);
  bool isPlanar = preprocess.run();

  auto &embedding = preprocess.embeddingMap();

  std::vector<int> x_coords;
  std::vector<int> y_coords;
  if (isPlanar) {
    PlanarDrawing<Graph> algorithm(g);
    algorithm.run(embedding);

    for (int i = 0; i < numNodes; ++i) {
      x_coords.push_back(algorithm[nodes[i]].x);
      y_coords.push_back(algorithm[nodes[i]].y);
    }
  }

  return Rcpp::List::create(isPlanar, x_coords, y_coords);
}
