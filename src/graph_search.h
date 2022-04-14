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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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
