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

auto ChristofidesRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcDistances, int numNodes, int defaultEdgeWeight=999999) {
  // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  // ATTENTION: TSP implemented using fullgraph, so remember that all edges exist
  FullGraph g(numNodes);

  FullGraph::EdgeMap<int> costs(g,defaultEdgeWeight);

  int NUM_ARCS = arcSources.size();

  for(int i = 0; i < NUM_ARCS; ++i) {
      costs[g.arc(g(arcSources[i]),g(arcTargets[i]))] = arcDistances[i];
  }

  
  ChristofidesTsp<FullGraph::EdgeMap<int>> runner(g,costs);
  runner.run();

  for(int i = 0; i < NUM_ARCS; ++i) {
      std::cout << g.id(runner.tourNodes()[i]) << std::endl;
  }

  return runner.tourCost();
}

auto GreedyTSPRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcDistances, int numNodes, int defaultEdgeWeight=999999) {
  // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  // ATTENTION: TSP implemented using fullgraph, so remember that we can't test this for large n. 
  FullGraph g(numNodes);

  FullGraph::EdgeMap<int> costs(g,defaultEdgeWeight);

  int NUM_ARCS = arcSources.size();

  for(int i = 0; i < NUM_ARCS; ++i) {
      costs[g.arc(g(arcSources[i]),g(arcTargets[i]))] = arcDistances[i];
  }

  
  GreedyTsp<FullGraph::EdgeMap<int>> runner(g,costs);
  runner.run();

  for(int i = 0; i < NUM_ARCS; ++i) {
      std::cout << g.id(runner.tourNodes()[i]) << std::endl;
  }

  return runner.tourCost();
}

/*
auto InsertionTSPRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcDistances, int numNodes, int defaultEdgeWeight=999999) {
  // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  // ATTENTION: TSP implemented using fullgraph, so remember that we can't test this for large n. 
  FullGraph g(numNodes);

  FullGraph::EdgeMap<int> costs(g,defaultEdgeWeight);

  int NUM_ARCS = arcSources.size();

  for(int i = 0; i < NUM_ARCS; ++i) {
      costs[g.arc(g(arcSources[i]),g(arcTargets[i]))] = arcDistances[i];
  }

  
  InsertionTsp<FullGraph::EdgeMap<int>> runner(g,costs);
  runner.run();

  for(int i = 0; i < NUM_ARCS; ++i) {
      std::cout << g.id(runner.tourNodes()[i]) << std::endl;
  }

  return runner.tourCost();
}
*/


auto NearestNeighborTSPRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcDistances, int numNodes, int defaultEdgeWeight=999999) {
  // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  // ATTENTION: TSP implemented using fullgraph, so remember that we can't test this for large n. 
  FullGraph g(numNodes);

  FullGraph::EdgeMap<int> costs(g,defaultEdgeWeight);

  int NUM_ARCS = arcSources.size();

  for(int i = 0; i < NUM_ARCS; ++i) {
      costs[g.arc(g(arcSources[i]),g(arcTargets[i]))] = arcDistances[i];
  }

  
  NearestNeighborTsp<FullGraph::EdgeMap<int>> runner(g,costs);
  runner.run();

  for(int i = 0; i < NUM_ARCS; ++i) {
      std::cout << g.id(runner.tourNodes()[i]) << std::endl;
  }

  return runner.tourCost();
}

auto Opt2TSPRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcDistances, int numNodes, int defaultEdgeWeight=999999) {
  // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  // ATTENTION: TSP implemented using fullgraph, so remember that we can't test this for large n. 
  FullGraph g(numNodes);

  FullGraph::EdgeMap<int> costs(g,defaultEdgeWeight);

  int NUM_ARCS = arcSources.size();

  for(int i = 0; i < NUM_ARCS; ++i) {
      costs[g.arc(g(arcSources[i]),g(arcTargets[i]))] = arcDistances[i];
  }

  
  Opt2Tsp<FullGraph::EdgeMap<int>> runner(g,costs);
  runner.run();

  for(int i = 0; i < NUM_ARCS; ++i) {
      std::cout << g.id(runner.tourNodes()[i]) << std::endl;
  }

  return runner.tourCost();
}
