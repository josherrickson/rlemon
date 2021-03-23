#include "lemon/bfs.h"
#include "lemon/dfs.h"
#include "lemon/dijkstra.h"
#include "lemon/list_graph.h"
#include "lemon/suurballe.h"
#include <lemon/max_cardinality_search.h>

#include <Rcpp.h>
#include <vector>

typedef int Value;

using namespace lemon;
using namespace std;

//' Graph Search Algorithms
//' @name Graph-Search-Algorithms-1
//' @param arcSources, a vector corresponding to the source nodes of a graph's edges
//' @param arcTargets, a vector corresponding to the destination nodes of a graph's edges
//' @param numNodes, the number of nodes in the graph
//' @param startNode, the start node of the path
//' @param endNode, the end node of the path
//' @return A list containing three entries: 1) the predecessor of each vertex in its shortest path, 2) the distances from each node to the startNode , 3) a list containing if a node was reached or not
//> NULL

//' Graph Search Algorithms
//' @name Graph-Search-Algorithms-2
//' @param arcSources, a vector corresponding to the source nodes of a graph's edges
//' @param arcTargets, a vector corresponding to the destination nodes of a graph's edges
//' @param arcCapacities, a vector corresponding to the distances of a graph's edges
//' @param numNodes, the number of nodes in the graph
//' @param startNode, the start node of the path
//' @return A list containing two entries: 1) the cardinality of each node , 2) a list containing if a node was reached or not
//> NULL

//' @rdname Graph-Search-Algorithms-1
//' @description `BfsRunner` calculates the shortest path using Breath-First-Search
// [[Rcpp::export]]
Rcpp::List BfsRunner(std::vector<int> arcSources, std::vector<int> arcTargets,
                     int numNodes, int startNode = -1, int endNode = -1) {
  ListDigraph g;
  std::vector<ListDigraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }

  std::vector<ListDigraph::Arc> arcs;

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    ListDigraph::Arc a =
        g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    arcs.push_back(a);
  }

  Bfs<ListDigraph> runner(g);

  if (startNode != -1 && endNode != -1) {
    runner.run(nodes[startNode - 1], nodes[endNode - 1]);
  } else if (startNode != -1) {
    runner.run(nodes[startNode - 1]);
  } else {
    runner.run();
  }

  std::vector<int> nodePreds;
  std::vector<int> nodeDistances;
  std::vector<int> nodeReached;

  for (int i = 0; i < numNodes; ++i) {
    nodePreds.push_back(g.id(runner.predNode(nodes[i])) + 1);
    nodeDistances.push_back(runner.dist(nodes[i]));
    if (runner.reached(nodes[i])) {
      nodeReached.push_back(1);
    } else {
      nodeReached.push_back(0);
    }
  }

  return Rcpp::List::create(nodePreds, nodeDistances, nodeReached);
}

//' @rdname Graph-Search-Algorithms-1
//' @description `DfsRunner` calculates the shortest path using Depth-First-Search
// [[Rcpp::export]]
Rcpp::List DfsRunner(std::vector<int> arcSources, std::vector<int> arcTargets,
                     int numNodes, int startNode = -1, int endNode = -1) {
  ListDigraph g;
  std::vector<ListDigraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }

  std::vector<ListDigraph::Arc> arcs;

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    ListDigraph::Arc a =
        g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    arcs.push_back(a);
  }

  Dfs<ListDigraph> runner(g);

  if (startNode != -1 && endNode != -1) {
    runner.run(nodes[startNode - 1], nodes[endNode - 1]);
  } else if (startNode != -1) {
    runner.run(nodes[startNode - 1]);
  } else {
    runner.run();
  }

  std::vector<int> nodePreds;
  std::vector<int> nodeDistances;
  std::vector<int> nodeReached;

  for (int i = 0; i < numNodes; ++i) {
    nodePreds.push_back(g.id(runner.predNode(nodes[i])) + 1);
    nodeDistances.push_back(runner.dist(nodes[i]));
    if (runner.reached(nodes[i])) {
      nodeReached.push_back(1);
    } else {
      nodeReached.push_back(0);
    }
  }

  return Rcpp::List::create(nodePreds, nodeDistances, nodeReached);
}

//' @rdname Graph-Search-Algorithms-2
//' @description `MaxCardinalitySearchRunner` runs the Maximum Cardinality Search Algorithm
// [[Rcpp::export]]
Rcpp::List MaxCardinalitySearchRunner(std::vector<int> arcSources,
                                      std::vector<int> arcTargets,
                                      std::vector<int> arcCapacities,
                                      int numNodes, int startNode = -1) {
  ListDigraph g;
  std::vector<ListDigraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }

  std::vector<ListDigraph::Arc> arcs;
  ListDigraph::ArcMap<int> costs(g);
  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    ListDigraph::Arc a =
        g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    costs[a] = arcCapacities[i];
    arcs.push_back(a);
  }

  MaxCardinalitySearch<ListDigraph, ListDigraph::ArcMap<int> > runner(g, costs);

  if (startNode != -1) {
    runner.run(nodes[startNode - 1]);
  } else {
    runner.run();
  }

  std::vector<int> nodeCardinality;
  std::vector<int> nodeDistances;
  std::vector<int> nodeReached;

  for (int i = 0; i < numNodes; ++i) {
    nodeCardinality.push_back(runner.cardinality(nodes[i]));
    if (runner.reached(nodes[i])) {
      nodeReached.push_back(1);
    } else {
      nodeReached.push_back(0);
    }
  }

  return Rcpp::List::create(nodeCardinality, nodeReached);
}
