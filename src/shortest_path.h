#include "lemon/bellman_ford.h"
#include "lemon/dijkstra.h"
#include "lemon/list_graph.h"
#include "lemon/suurballe.h"

#include <Rcpp.h>
#include <vector>

typedef int Value;

using namespace lemon;
using namespace std;

//' Shortest Path Algorithms - Distance
//' @name Shortest-Path-Algorithms-1
//' @param arcSources Vector corresponding to the source nodes of a graph's edges
//' @param arcTargets Vector corresponding to the destination nodes of a graph's edges
//' @param arcDistances Vector corresponding to the distances of a graph's edges
//' @param numNodes The number of nodes in the graph
//' @param startNode The start node of the path
//' @return A list containing two entries: 1) the distances from each node to the startNode and 2) the predecessor of each vertex in its shortest path.
//> NULL

//' Shortest Path Algorithms - Paths
//' @name Shortest-Path-Algorithms-2
//' @param arcSources Vector corresponding to the source nodes of a graph's edges
//' @param arcTargets Vector corresponding to the destination nodes of a graph's edges
//' @param arcDistances Vector corresponding to the distances of a graph's edges
//' @param numNodes The number of nodes in the graph
//' @param startNode The start node of the path
//' @param endNode The end node of the path
//' @return A list containing two entries: 1) the number of arc disjoint paths from the start node to the end node and 2) a list of paths found.
//> NULL

//' @rdname Shortest-Path-Algorithms-2
//' @description `SuurballeRunner` calculates the shortest path between a specified start and end node and returns a list containing  1) the number of arc disjoint paths from the start node to the end node and 2) a list of paths found.
// [[Rcpp::export]]
Rcpp::List SuurballeRunner(std::vector<int> arcSources,
                           std::vector<int> arcTargets,
                           std::vector<int> arcDistances, int numNodes,
                           int startNode, int endNode) {
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

  Suurballe<ListDigraph, DigraphExtender<ListDigraphBase>::ArcMap<int> > s(
      g, costs);
  int NUM_PATHS = s.run(nodes[startNode - 1], nodes[endNode - 1], NUM_ARCS);

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
      paths.at(i).push_back(g.id(s) + 1);
      if (j == length - 1)
        paths.at(i).push_back(g.id(t) + 1);
    }
  }
  return Rcpp::List::create(NUM_PATHS, paths);
}

//' @rdname Shortest-Path-Algorithms-1
//' @description `DijkstraRunner` calculates the shortest path from the start node to each node in the graph and returns a list containing 1) the distances from each node to the startNode and 2) the predecessor of each vertex in its shortest path.
// [[Rcpp::export]]
Rcpp::List DijkstraRunner(std::vector<int> arcSources,
                          std::vector<int> arcTargets,
                          std::vector<int> arcDistances, int numNodes,
                          int startNode) {
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

  Dijkstra<ListDigraph, DigraphExtender<ListDigraphBase>::ArcMap<int> > bf(
      g, costs);
  bf.run(nodes[startNode - 1]);
  std::vector<int> distances;
  std::vector<int> predecessors;
  for (int i = 0; i < numNodes; i++) {
    distances.push_back(bf.dist(nodes[i]));
    predecessors.push_back(g.id(bf.predNode(nodes[i])) + 1);
  }
  return Rcpp::List::create(distances, predecessors);
}

//' @rdname Shortest-Path-Algorithms-1
//' @description `BellmanFordRunner` calculates the shortest path from the start node to each node in the graph and returns a list containing 1) the distances from each node to the startNode and 2) the predecessor of each vertex in its shortest path.
// [[Rcpp::export]]
Rcpp::List BellmanFordRunner(std::vector<int> arcSources,
                             std::vector<int> arcTargets,
                             std::vector<int> arcDistances, int numNodes,
                             int startNode) {
  ListDigraph g;
  std::vector<ListDigraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  ListDigraph::ArcMap<Cost> costs(g);
  ListDigraph::NodeMap<Cost> dists(g);

  std::vector<ListDigraph::Arc> arcs;

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    ListDigraph::Arc a =
        g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    arcs.push_back(a);
    costs[arcs[i]] = arcDistances[i];
  }

  BellmanFord<ListDigraph, DigraphExtender<ListDigraphBase>::ArcMap<int> > bf =
      BellmanFord<ListDigraph, DigraphExtender<ListDigraphBase>::ArcMap<int> >(
          g, costs);
  bf.run(nodes[startNode - 1]);
  std::vector<int> distances;
  std::vector<int> predecessors;
  for (int i = 0; i < numNodes; i++) {
    distances.push_back(bf.dist(nodes[i]));
    predecessors.push_back(g.id(bf.predNode(nodes[i])) + 1);
  }
  return Rcpp::List::create(distances, predecessors);
}
