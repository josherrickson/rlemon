#include "lemon/bellman_ford.h"
#include "lemon/dijkstra.h"
#include "lemon/list_graph.h"
#include "lemon/suurballe.h"

#include <Rcpp.h>
#include <vector>

typedef int Value;

using namespace lemon;
using namespace std;

using Cost = int;
using Graph = ListDigraph;
using Node = Graph::Node;
using Arc = Graph::Arc;

template <typename ValueType> using ArcMap = ListDigraph::ArcMap<ValueType>;
template <typename ValueType> using NodeMap = ListDigraph::NodeMap<ValueType>;

//' Shortest Path Algorithms - Distance
//' @name Shortest-Path-Algorithms-1
//' @param arcSources, a vector corresponding to the source nodes of a graph's edges
//' @param arcTargets, a vector corresponding to the destination nodes of a graph's edges
//' @param actDistances, a vector corresponding to the distances of a graph's edges
//' @param numNodes, the number of nodes in the graph
//' @param startNode, the start node of the path
//' @return A list containing two entries: 1) the distances from each node to the startnode and 2) the predecessor of each vertex in its shortest path.
//> NULL

//' Shortest Path Algorithms - Paths
//' @name Shortest-Path-Algorithms-2
//' @param arcSources, a vector corresponding to the source nodes of a graph's edges
//' @param arcTargets, a vector corresponding to the destination nodes of a graph's edges
//' @param actDistances, a vector corresponding to the distances of a graph's edges
//' @param numNodes, the number of nodes in the graph
//' @param startNode, the start node of the path
//' @param endnode, the end node of the path
//' @return A list containing two entries: 1) the number of paths from the start node to the end node and 2) a list of paths found.
//> NULL

//' @rdname Shortest-Path-Algorithms-2
//' @description `SuurballeRunner` calculates the shortest path between a specificed start and end node and returns a list containing  1) the number of paths from the start node to the end node and 2) a list of paths found.
//' @export
// [[Rcpp::export]]
Rcpp::List SuurballeRunner(std::vector<int> arcSources,
                           std::vector<int> arcTargets,
                           std::vector<int> arcDistances, int numNodes,
                           int startnode, int endnode) {
  ListDigraph g;
  std::vector<Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    Node n = g.addNode();
    nodes.push_back(n);
  }
  ArcMap<Cost> costs(g);
  NodeMap<Cost> dists(g);

  std::vector<Arc> arcs;

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    Arc a = g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
    arcs.push_back(a);
    costs[arcs[i]] = arcDistances[i];
  }

  Suurballe<ListDigraph, DigraphExtender<ListDigraphBase>::ArcMap<int> > s(
      g, costs);
  int NUM_PATHS = s.run(nodes[startnode], nodes[endnode], NUM_ARCS);

  std::vector<int> temp;
  std::vector<std::vector<int> > paths(NUM_PATHS, temp);
  for (int i = 0; i < NUM_PATHS; ++i) {
    auto path = s.path(i);
    int length = path.length();
    for (int j = 0; j < length; ++j) {
      auto arc = path.front();
      auto s = g.source(arc);
      auto t = g.target(arc);
      path.eraseFront();
      paths.at(i).push_back(g.id(s));
      if (j == length - 1)
        paths.at(i).push_back(g.id(t));
    }
  }
  return std::make_tuple(NUM_PATHS, paths);
}

//' @rdname Shortest-Path-Algorithms-1
//' @description `DijkstraRunner` calculates the shortest path from the start node to each node in the graph and returns a list containing 1) the distances from each node to the startnode and 2) the predecessor of each vertex in its shortest path.
//' @export
// [[Rcpp::export]]
Rcpp::List DijkstraRunner(std::vector<int> arcSources,
                          std::vector<int> arcTargets,
                          std::vector<int> arcDistances, int numNodes,
                          int startnode) {
  ListDigraph g;
  std::vector<Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    Node n = g.addNode();
    nodes.push_back(n);
  }
  ArcMap<Cost> costs(g);
  NodeMap<Cost> dists(g);

  std::vector<Arc> arcs;

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    Arc a = g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
    arcs.push_back(a);
    costs[arcs[i]] = arcDistances[i];
  }

  Dijkstra<ListDigraph, DigraphExtender<ListDigraphBase>::ArcMap<int> > bf(
      g, costs);
  bf.run(nodes[startnode]);
  std::vector<int> distances;
  std::vector<int> predecessors;
  for (int i = 0; i < numNodes; i++) {
    distances.push_back(bf.dist(nodes[i]));
    predecessors.push_back(g.id(bf.predNode(nodes[i])));
  }
  return std::make_tuple(distances, predecessors);
}

//' @rdname Shortest-Path-Algorithms-1
//' @description `BellmanFordRunner` calculates the shortest path from the start node to each node in the graph and returns a list containing 1) the distances from each node to the startnode and 2) the predecessor of each vertex in its shortest path.
//' @export
// [[Rcpp::export]]
Rcpp::List BellmanFordRunner(std::vector<int> arcSources,
                             std::vector<int> arcTargets,
                             std::vector<int> arcDistances, int numNodes,
                             int startnode) {
  ListDigraph g;
  std::vector<Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    Node n = g.addNode();
    nodes.push_back(n);
  }
  ArcMap<Cost> costs(g);
  NodeMap<Cost> dists(g);

  std::vector<Arc> arcs;

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    Arc a = g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
    arcs.push_back(a);
    costs[arcs[i]] = arcDistances[i];
  }

  BellmanFord<ListDigraph, DigraphExtender<ListDigraphBase>::ArcMap<int> > bf =
      BellmanFord<ListDigraph, DigraphExtender<ListDigraphBase>::ArcMap<int> >(
          g, costs);
  bf.run(nodes[startnode]);
  std::vector<int> distances;
  std::vector<int> predecessors;
  for (int i = 0; i < numNodes; i++) {
    distances.push_back(bf.dist(nodes[i]));
    predecessors.push_back(g.id(bf.predNode(nodes[i])));
  }
  return std::make_tuple(distances, predecessors);
}