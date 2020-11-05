#include <vector>
#include <iostream>
#include <lemon/christofides_tsp.h>
#include <lemon/greedy_tsp.h>
#include <lemon/insertion_tsp.h>
#include <lemon/nearest_neighbor_tsp.h>
#include <lemon/opt2_tsp.h>

typedef int Value;

using namespace lemon;
using namespace std;

//' Travelling Salesman Algorithms on Full Graphs
//' @name TSP-Algorithms
//' @param arcSources, a vector corresponding to the source nodes of a graph's edges
//' @param arcTargets, a vector corresponding to the destination nodes of a graph's edges
//' @param arcDistances, a vector corresponding to the distances of a graph's edges
//' @param numNodes, the number of nodes in the graph
//' @param defaultEdgeWeight, the default edge weight if an edge is not-specified (default value 999999)
//' @return a List with 1) the list of tour vertices, and 2) the total tour cost
//> NULL

//' @rdname TSP-Algorithms
//' @description `ChristofidesRunner` runs the Christofides Heuristic
//' @export
// [[Rcpp::export]]
Rcpp::List ChristofidesRunner(std::vector<int> arcSources, std::vector<int> arcTargets, std::vector<int> arcDistances, int numNodes, int defaultEdgeWeight=999999) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One std::vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  // ATTENTION: TSP implemented using fullgraph, so remember that all edges exist
  FullGraph g(numNodes);

  FullGraph::EdgeMap<int> costs(g,defaultEdgeWeight);

  int NUM_ARCS = arcSources.size();

  for(int i = 0; i < NUM_ARCS; ++i) {
      costs[g.arc(g(arcSources[i]),g(arcTargets[i]))] = arcDistances[i];
  }


  ChristofidesTsp<FullGraph::EdgeMap<int>> runner(g,costs);
  runner.run();

  std::vector<int> tour;
  for(int i = 0; i < NUM_ARCS; ++i) {
      tour.push_back(g.id(runner.tourNodes()[i]));
  }

  return Rcpp::List::create(tour,runner.tourCost());
}

//' @rdname TSP-Algorithms
//' @description `GreedyTSPRunner` runs the Greedy Heuristic
//' @export
// [[Rcpp::export]]
Rcpp::List GreedyTSPRunner(std::vector<int> arcSources, std::vector<int> arcTargets, std::vector<int> arcDistances, int numNodes, int defaultEdgeWeight=999999) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One std::vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  // ATTENTION: TSP implemented using fullgraph, so remember that we can't test this for large n.
  FullGraph g(numNodes);

  FullGraph::EdgeMap<int> costs(g,defaultEdgeWeight);

  int NUM_ARCS = arcSources.size();

  for(int i = 0; i < NUM_ARCS; ++i) {
      costs[g.arc(g(arcSources[i]),g(arcTargets[i]))] = arcDistances[i];
  }


  GreedyTsp<FullGraph::EdgeMap<int>> runner(g,costs);
  runner.run();

  std::vector<int> tour;
  for(int i = 0; i < NUM_ARCS; ++i) {
      tour.push_back(g.id(runner.tourNodes()[i]));
  }

  return Rcpp::List::create(tour,runner.tourCost());
}

//' @rdname TSP-Algorithms
//' @description `InsertionTSPRunner` runs the Insertion Heuristic
//' @export
// [[Rcpp::export]]
Rcpp::List InsertionTSPRunner(std::vector<int> arcSources, std::vector<int> arcTargets, std::vector<int> arcDistances, int numNodes, int defaultEdgeWeight=999999) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One std::vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  // ATTENTION: TSP implemented using fullgraph, so remember that we can't test this for large n.
  FullGraph g(numNodes);

  FullGraph::EdgeMap<int> costs(g,defaultEdgeWeight);

  int NUM_ARCS = arcSources.size();

  for(int i = 0; i < NUM_ARCS; ++i) {
      costs[g.arc(g(arcSources[i]),g(arcTargets[i]))] = arcDistances[i];
  }


  InsertionTsp<FullGraph::EdgeMap<int>> runner(g,costs);
  runner.run();

  std::vector<int> tour;
  for(int i = 0; i < NUM_ARCS; ++i) {
      tour.push_back(g.id(runner.tourNodes()[i]));
  }

  return Rcpp::List::create(tour,runner.tourCost());
}


//' @rdname TSP-Algorithms
//' @description `NearestNeighborTSPRunner` runs the Nearest-Neighbor Heuristic
//' @export
// [[Rcpp::export]]
Rcpp::List NearestNeighborTSPRunner(std::vector<int> arcSources, std::vector<int> arcTargets, std::vector<int> arcDistances, int numNodes, int defaultEdgeWeight=999999) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One std::vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  // ATTENTION: TSP implemented using fullgraph, so remember that we can't test this for large n.
  FullGraph g(numNodes);

  FullGraph::EdgeMap<int> costs(g,defaultEdgeWeight);

  int NUM_ARCS = arcSources.size();

  for(int i = 0; i < NUM_ARCS; ++i) {
      costs[g.arc(g(arcSources[i]),g(arcTargets[i]))] = arcDistances[i];
  }


  NearestNeighborTsp<FullGraph::EdgeMap<int>> runner(g,costs);
  runner.run();

  std::vector<int> tour;
  for(int i = 0; i < NUM_ARCS; ++i) {
      tour.push_back(g.id(runner.tourNodes()[i]));
  }

  return Rcpp::List::create(tour,runner.tourCost());
}

//' @rdname TSP-Algorithms
//' @description `Opt2TSPRunner` runs a 2-OPT heuristic
//' @export
// [[Rcpp::export]]
Rcpp::List Opt2TSPRunner(std::vector<int> arcSources, std::vector<int> arcTargets, std::vector<int> arcDistances, int numNodes, int defaultEdgeWeight=999999) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One std::vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  // ATTENTION: TSP implemented using fullgraph, so remember that we can't test this for large n.
  FullGraph g(numNodes);

  FullGraph::EdgeMap<int> costs(g,defaultEdgeWeight);

  int NUM_ARCS = arcSources.size();

  for(int i = 0; i < NUM_ARCS; ++i) {
      costs[g.arc(g(arcSources[i]),g(arcTargets[i]))] = arcDistances[i];
  }


  Opt2Tsp<FullGraph::EdgeMap<int>> runner(g,costs);
  runner.run();

  std::vector<int> tour;
  for(int i = 0; i < NUM_ARCS; ++i) {
      tour.push_back(g.id(runner.tourNodes()[i]));
  }

  return Rcpp::List::create(tour,runner.tourCost());
}
