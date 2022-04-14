#include <lemon/christofides_tsp.h>
#include <lemon/greedy_tsp.h>
#include <lemon/insertion_tsp.h>
#include <lemon/nearest_neighbor_tsp.h>
#include <lemon/opt2_tsp.h>
#include <vector>

typedef int Value;

using namespace lemon;
using namespace std;


//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List ChristofidesRunner(std::vector<int> arcSources,
                              std::vector<int> arcTargets,
                              std::vector<int> arcDistances, int numNodes,
                              int defaultEdgeWeight = 999999) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One std::vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  // ATTENTION: TSP implemented using fullgraph, so remember that all edges exist
  FullGraph g(numNodes);

  FullGraph::EdgeMap<int> costs(g, defaultEdgeWeight);

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    costs[g.arc(g(arcSources[i] - 1), g(arcTargets[i] - 1))] = arcDistances[i];
  }

  ChristofidesTsp<FullGraph::EdgeMap<int> > runner(g, costs);
  runner.run();

  std::vector<int> tour;
  for (int i = 0; i < numNodes; ++i) {
    tour.push_back(g.id(runner.tourNodes()[i]) + 1);
  }

  return Rcpp::List::create(tour, runner.tourCost());
}

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List GreedyTSPRunner(std::vector<int> arcSources,
                           std::vector<int> arcTargets,
                           std::vector<int> arcDistances, int numNodes,
                           int defaultEdgeWeight = 999999) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One std::vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  // ATTENTION: TSP implemented using fullgraph, so remember that we can't test this for large n.
  FullGraph g(numNodes);

  FullGraph::EdgeMap<int> costs(g, defaultEdgeWeight);

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    costs[g.arc(g(arcSources[i] - 1), g(arcTargets[i] - 1))] = arcDistances[i];
  }

  GreedyTsp<FullGraph::EdgeMap<int> > runner(g, costs);
  runner.run();

  std::vector<int> tour;
  for (int i = 0; i < numNodes; ++i) {
    tour.push_back(g.id(runner.tourNodes()[i]) + 1);
  }

  return Rcpp::List::create(tour, runner.tourCost());
}

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List InsertionTSPRunner(std::vector<int> arcSources,
                              std::vector<int> arcTargets,
                              std::vector<int> arcDistances, int numNodes,
                              int defaultEdgeWeight = 999999) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One std::vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  // ATTENTION: TSP implemented using fullgraph, so remember that we can't test this for large n.
  FullGraph g(numNodes);

  FullGraph::EdgeMap<int> costs(g, defaultEdgeWeight);

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    costs[g.arc(g(arcSources[i] - 1), g(arcTargets[i] - 1))] = arcDistances[i];
  }

  InsertionTsp<FullGraph::EdgeMap<int> > runner(g, costs);
  runner.run();

  std::vector<int> tour;
  for (int i = 0; i < numNodes; ++i) {
    tour.push_back(g.id(runner.tourNodes()[i]) + 1);
  }

  return Rcpp::List::create(tour, runner.tourCost());
}

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List NearestNeighborTSPRunner(std::vector<int> arcSources,
                                    std::vector<int> arcTargets,
                                    std::vector<int> arcDistances, int numNodes,
                                    int defaultEdgeWeight = 999999) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One std::vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  // ATTENTION: TSP implemented using fullgraph, so remember that we can't test this for large n.
  FullGraph g(numNodes);

  FullGraph::EdgeMap<int> costs(g, defaultEdgeWeight);

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    costs[g.arc(g(arcSources[i] - 1), g(arcTargets[i] - 1))] = arcDistances[i];
  }

  NearestNeighborTsp<FullGraph::EdgeMap<int> > runner(g, costs);
  runner.run();

  std::vector<int> tour;
  for (int i = 0; i < numNodes; ++i) {
    tour.push_back(g.id(runner.tourNodes()[i]) + 1);
  }

  return Rcpp::List::create(tour, runner.tourCost());
}

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List Opt2TSPRunner(std::vector<int> arcSources,
                         std::vector<int> arcTargets,
                         std::vector<int> arcDistances, int numNodes,
                         int defaultEdgeWeight = 999999) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One std::vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  // ATTENTION: TSP implemented using fullgraph, so remember that we can't test this for large n.
  FullGraph g(numNodes);

  FullGraph::EdgeMap<int> costs(g, defaultEdgeWeight);

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    costs[g.arc(g(arcSources[i] - 1), g(arcTargets[i] - 1))] = arcDistances[i];
  }

  Opt2Tsp<FullGraph::EdgeMap<int> > runner(g, costs);
  runner.run();

  std::vector<int> tour;
  for (int i = 0; i < numNodes; ++i) {
    tour.push_back(g.id(runner.tourNodes()[i]) + 1);
  }

  return Rcpp::List::create(tour, runner.tourCost());
}
