#include "lemon/fractional_matching.h"
#include "lemon/list_graph.h"
#include "lemon/matching.h"
#include <Rcpp.h>
#include <vector>

typedef int Value;

using namespace lemon;
using namespace std;

using Cost = int;

using Graph = ListGraph;
using Node = Graph::Node;
using Edge = Graph::Edge;

template <typename ValueType> using EdgeMap = ListGraph::EdgeMap<ValueType>;

template <typename ValueType> using NodeMap = ListGraph::NodeMap<ValueType>;

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List MaximumWeightPerfectMatchingRunner(std::vector<int> arcSources,
                                              std::vector<int> arcTargets,
                                              std::vector<int> arcWeights,
                                              int numNodes) {
  ListGraph g;
  std::vector<Node> nodes;
  EdgeMap<Cost> dists(g);
  for (int i = 0; i < numNodes; ++i) {
    Node n = g.addNode();
    nodes.push_back(n);
  }

  std::vector<Edge> arcs;
  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    Edge a = g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    dists[a] = arcWeights[i];
    arcs.push_back(a);
  }
  auto test = MaxWeightedPerfectMatching<ListGraph, EdgeMap<Cost> >(g, dists);
  std::vector<std::vector<int> > arcs_out;
  test.run();
  for (int i = 0; i < NUM_ARCS; i++) {
    if (test.matching(arcs[i])) {
      std::vector<int> arc;
      arc.push_back(g.id(g.u(arcs[i])) + 1);
      arc.push_back(g.id(g.v(arcs[i])) + 1);
      arcs_out.push_back(arc);
    }
  }
  return Rcpp::List::create(test.matchingWeight(), arcs_out);
}

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List MaximumWeightFractionalPerfectMatchingRunner(
    std::vector<int> arcSources, std::vector<int> arcTargets,
    std::vector<int> arcWeights, int numNodes) {
  ListGraph g;
  std::vector<Node> nodes;
  EdgeMap<Cost> dists(g);
  for (int i = 0; i < numNodes; ++i) {
    Node n = g.addNode();
    nodes.push_back(n);
  }

  std::vector<Edge> arcs;
  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    Edge a = g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    dists[a] = arcWeights[i];
    arcs.push_back(a);
  }
  auto test =
      MaxWeightedPerfectFractionalMatching<ListGraph, EdgeMap<Cost> >(g, dists);
  std::vector<std::vector<int> > arcs_out;
  test.run();
  for (int i = 0; i < NUM_ARCS; i++) {
    if (test.matching(arcs[i])) {
      std::vector<int> arc;
      arc.push_back(g.id(g.u(arcs[i])) + 1);
      arc.push_back(g.id(g.v(arcs[i])) + 1);
      arcs_out.push_back(arc);
    }
  }
  return Rcpp::List::create(test.matchingWeight(), arcs_out);
}

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List MaximumWeightFractionalMatchingRunner(std::vector<int> arcSources,
                                                 std::vector<int> arcTargets,
                                                 std::vector<int> arcWeights,
                                                 int numNodes) {
  ListGraph g;
  std::vector<Node> nodes;
  EdgeMap<Cost> dists(g);
  for (int i = 0; i < numNodes; ++i) {
    Node n = g.addNode();
    nodes.push_back(n);
  }
  std::vector<Edge> arcs;

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    Edge a = g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    dists[a] = arcWeights[i];
    arcs.push_back(a);
  }
  auto test =
      MaxWeightedFractionalMatching<ListGraph, EdgeMap<Cost> >(g, dists);
  std::vector<std::vector<int> > arcs_out;
  test.run();
  for (int i = 0; i < NUM_ARCS; i++) {
    if (test.matching(arcs[i])) {
      std::vector<int> arc;
      arc.push_back(g.id(g.u(arcs[i])) + 1);
      arc.push_back(g.id(g.v(arcs[i])) + 1);
      arcs_out.push_back(arc);
    }
  }
  return Rcpp::List::create(test.matchingWeight(), arcs_out);
}

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List MaximumWeightMatchingRunner(std::vector<int> arcSources,
                                       std::vector<int> arcTargets,
                                       std::vector<int> arcWeights,
                                       int numNodes) {
  ListGraph g;
  std::vector<Node> nodes;
  EdgeMap<Cost> dists(g);
  for (int i = 0; i < numNodes; ++i) {
    Node n = g.addNode();
    nodes.push_back(n);
  }

  std::vector<Edge> arcs;

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    Edge a = g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    dists[a] = arcWeights[i];
    arcs.push_back(a);
  }
  auto test = MaxWeightedMatching<ListGraph>(g, dists);
  std::vector<std::vector<int> > arcs_out;
  test.run();
  for (int i = 0; i < NUM_ARCS; i++) {
    if (test.matching(arcs[i])) {
      std::vector<int> arc;
      arc.push_back(g.id(g.u(arcs[i])) + 1);
      arc.push_back(g.id(g.v(arcs[i])) + 1);
      arcs_out.push_back(arc);
    }
  }
  return Rcpp::List::create(test.matchingWeight(), arcs_out);
}

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List MaximumCardinalityMatchingRunner(std::vector<int> arcSources,
                                            std::vector<int> arcTargets,
                                            int numNodes) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One std::vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  ListGraph g;
  std::vector<Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    Node n = g.addNode();
    nodes.push_back(n);
  }
  NodeMap<Cost> dists(g);

  std::vector<Edge> arcs;

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    Edge a = g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    arcs.push_back(a);
  }
  ListGraph::EdgeMap<int> map(g);
  auto test = MaxMatching<ListGraph>(g);
  test.run();
  std::vector<std::vector<int> > arcs_out;
  for (int i = 0; i < NUM_ARCS; i++) {
    if (test.matching(arcs[i])) {
      std::vector<int> arc;
      arc.push_back(g.id(g.u(arcs[i])) + 1);
      arc.push_back(g.id(g.v(arcs[i])) + 1);
      arcs_out.push_back(arc);
    }
  }
  return Rcpp::List::create(test.matchingSize(), arcs_out);
}

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List MaximumCardinalityFractionalMatchingRunner(
    std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One std::vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  ListGraph g;
  std::vector<Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    Node n = g.addNode();
    nodes.push_back(n);
  }
  NodeMap<Cost> dists(g);

  std::vector<Edge> arcs;

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    Edge a = g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    arcs.push_back(a);
  }
  ListGraph::EdgeMap<int> map(g);
  auto test = MaxFractionalMatching<ListGraph>(g);
  test.run();
  std::vector<std::vector<int> > arcs_out;
  for (int i = 0; i < NUM_ARCS; i++) {
    if (test.matching(arcs[i])) {
      std::vector<int> arc;
      arc.push_back(g.id(g.u(arcs[i])) + 1);
      arc.push_back(g.id(g.v(arcs[i])) + 1);
      arcs_out.push_back(arc);
    }
  }
  return Rcpp::List::create(test.matchingSize(), arcs_out);
}
