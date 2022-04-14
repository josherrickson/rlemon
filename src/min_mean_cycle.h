#include "lemon/hartmann_orlin_mmc.h"
#include "lemon/howard_mmc.h"
#include "lemon/karp_mmc.h"
#include <Rcpp.h>
#include <iostream>
#include <vector>

using namespace lemon;
using namespace std;

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List HowardMmcRunner(std::vector<int> arcSources,
                           std::vector<int> arcTargets,
                           std::vector<int> arcDistances, int numNodes) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One std::vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  ListDigraph g;
  std::vector<ListDigraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  ListDigraph::ArcMap<int> costs(g);
  ListDigraph::NodeMap<int> dists(g);

  std::vector<ListDigraph::Arc> arcs;

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    ListDigraph::Arc a =
        g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    arcs.push_back(a);
    costs[arcs[i]] = arcDistances[i];
  }

  Path<ListDigraph> finale;

  HowardMmc<ListDigraph>(g, costs).cycle(finale).run();
  std::vector<int> distances;
  std::vector<int> path_nodes;
  for (int i = 0; i < finale.length(); i++) {
    distances.push_back(costs[finale.nth(i)]);
    path_nodes.push_back(g.id(g.source(finale.nth(i))) + 1);
  }
  return Rcpp::List::create(distances, path_nodes);
}

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List KarpMmcRunner(std::vector<int> arcSources,
                         std::vector<int> arcTargets,
                         std::vector<int> arcDistances, int numNodes) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One std::vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  ListDigraph g;
  std::vector<ListDigraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  ListDigraph::ArcMap<int> costs(g);
  ListDigraph::NodeMap<int> dists(g);

  std::vector<ListDigraph::Arc> arcs;

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    ListDigraph::Arc a =
        g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    arcs.push_back(a);
    costs[arcs[i]] = arcDistances[i];
  }

  Path<ListDigraph> finale;

  KarpMmc<ListDigraph>(g, costs).cycle(finale).run();
  std::vector<int> distances;
  std::vector<int> path_nodes;
  for (int i = 0; i < finale.length(); i++) {
    distances.push_back(costs[finale.nth(i)]);
    path_nodes.push_back(g.id(g.source(finale.nth(i))) + 1);
  }
  return Rcpp::List::create(distances, path_nodes);
}

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List HartmannOrlinMmcRunner(std::vector<int> arcSources,
                                  std::vector<int> arcTargets,
                                  std::vector<int> arcDistances, int numNodes) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One std::vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  ListDigraph g;
  std::vector<ListDigraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  ListDigraph::ArcMap<int> costs(g);
  ListDigraph::NodeMap<int> dists(g);

  std::vector<ListDigraph::Arc> arcs;

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    ListDigraph::Arc a =
        g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    arcs.push_back(a);
    costs[arcs[i]] = arcDistances[i];
  }

  Path<ListDigraph> finale;

  HartmannOrlinMmc<ListDigraph>(g, costs).cycle(finale).run();
  std::vector<int> distances;
  std::vector<int> path_nodes;
  for (int i = 0; i < finale.length(); i++) {
    distances.push_back(costs[finale.nth(i)]);
    path_nodes.push_back(g.id(g.source(finale.nth(i))) + 1);
  }
  return Rcpp::List::create(distances, path_nodes);
}
