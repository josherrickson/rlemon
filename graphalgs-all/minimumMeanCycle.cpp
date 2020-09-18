#include <vector>
#include <iostream>
#include "lemon/karp_mmc.h"
#include "lemon/hartmann_orlin_mmc.h"
#include "lemon/howard_mmc.h"

typedef int Value;

using namespace lemon;
using namespace std;

using Cost = int;

using Graph = ListDigraph;
using Node = Graph::Node;
using Arc = Graph::Arc;

template<typename ValueType>
using ArcMap = ListDigraph::ArcMap<ValueType>;

template<typename ValueType>
using NodeMap = ListDigraph::NodeMap<ValueType>;

auto HowardMmcRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcDistances, int numNodes) {
  // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  ListDigraph g;
  vector<Node> nodes;
  for(int i = 0; i < numNodes; ++i){
      Node n = g.addNode();
      nodes.push_back(n);
  }
  ArcMap<Cost> costs(g);
  NodeMap<Cost> dists(g);

  vector<Arc> arcs;

  int NUM_ARCS = arcSources.size();

  for(int i = 0; i < NUM_ARCS; ++i) {
      Arc a = g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
      arcs.push_back(a);
      costs[arcs[i]] = arcDistances[i];
  }

  Path<ListDigraph> finale;
  
  HowardMmc<ListDigraph>(g,costs).cycle(finale).run();
  std::vector<int> distances;
  std::vector<int> path_nodes;
  for(int i = 0; i < finale.length(); i++) {
      distances.push_back(costs[finale.nth(i)]);
      path_nodes.push_back(g.id(g.source(finale.nth(i))));
  }
  return std::tuple<std::vector<int>, std::vector<int>>{distances, path_nodes};
}


auto KarpMmcRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcDistances, int numNodes) {
  // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  ListDigraph g;
  vector<Node> nodes;
  for(int i = 0; i < numNodes; ++i){
      Node n = g.addNode();
      nodes.push_back(n);
  }
  ArcMap<Cost> costs(g);
  NodeMap<Cost> dists(g);

  vector<Arc> arcs;

  int NUM_ARCS = arcSources.size();

  for(int i = 0; i < NUM_ARCS; ++i) {
      Arc a = g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
      arcs.push_back(a);
      costs[arcs[i]] = arcDistances[i];
  }

  Path<ListDigraph> finale;
  
  KarpMmc<ListDigraph>(g,costs).cycle(finale).run();
  std::vector<int> distances;
  std::vector<int> path_nodes;
  for(int i = 0; i < finale.length(); i++) {
      distances.push_back(costs[finale.nth(i)]);
      path_nodes.push_back(g.id(g.source(finale.nth(i))));
  }
  return std::tuple<std::vector<int>, std::vector<int>>{distances, path_nodes};
}


auto HartmannOrlinMmcRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcDistances, int numNodes) {
  // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  ListDigraph g;
  vector<Node> nodes;
  for(int i = 0; i < numNodes; ++i){
      Node n = g.addNode();
      nodes.push_back(n);
  }
  ArcMap<Cost> costs(g);
  NodeMap<Cost> dists(g);

  vector<Arc> arcs;

  int NUM_ARCS = arcSources.size();

  for(int i = 0; i < NUM_ARCS; ++i) {
      Arc a = g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
      arcs.push_back(a);
      costs[arcs[i]] = arcDistances[i];
  }

  Path<ListDigraph> finale;
  
  HartmannOrlinMmc<ListDigraph>(g,costs).cycle(finale).run();
  std::vector<int> distances;
  std::vector<int> path_nodes;
  for(int i = 0; i < finale.length(); i++) {
      distances.push_back(costs[finale.nth(i)]);
      path_nodes.push_back(g.id(g.source(finale.nth(i))));
  }
  return std::tuple<std::vector<int>, std::vector<int>>{distances, path_nodes};
}


auto KarpMmcRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcDistances, int numNodes) {
  // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: One vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
  ListDigraph g;
  vector<Node> nodes;
  for(int i = 0; i < numNodes; ++i){
      Node n = g.addNode();
      nodes.push_back(n);
  }
  ArcMap<Cost> costs(g);
  NodeMap<Cost> dists(g);

  vector<Arc> arcs;

  int NUM_ARCS = arcSources.size();

  for(int i = 0; i < NUM_ARCS; ++i) {
      Arc a = g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
      arcs.push_back(a);
      costs[arcs[i]] = arcDistances[i];
  }

  Path<ListDigraph> finale;
  
  KarpMmc<ListDigraph>(g,costs).cycle(finale).run();
  std::vector<int> distances;
  std::vector<int> path_nodes;
  for(int i = 0; i < finale.length(); i++) {
      distances.push_back(costs[finale.nth(i)]);
      path_nodes.push_back(g.id(g.source(finale.nth(i))));
  }
  return std::tuple<std::vector<int>, std::vector<int>>{distances, path_nodes};
}

int main()
{
    // Example Usage - Example taken from EecsforGeeks
   vector<int> arc_src{0,0,1,2,3,3};
   vector<int> arc_targ{1,2,2,3,0,1};
   vector<int> arc_costs{10,1,3,2,8,0};
   
   // Output vectors - used to get the information from minimum mean cycle
   vector<int> distances;
   vector<int> path_elements;

   // Runs the algorithm,
   auto output = MinimumMeanCycleRunner(arc_src, arc_targ, arc_costs, 9);
   std::cout << "For the given graph, the following is the minimum mean cost cycle" << std::endl;
   distances = std::get<0>(output);
   path_elements = std::get<1>(output);
   // Printing nonsense. For R-impl, return as Rcpp::List instead.
   for(int i = 0; i < distances.size(); i++) {
       if(i != distances.size() -1){
       std::cout << path_elements[i] << " <- ";
   }
       else{
           std::cout << path_elements[i];
       }
   }
   std::cout << std::endl;
   std::cout << "This has the following mean cost cycle length:" << std::endl;
   double mean_cost_cycle = 0;
   for(int i = 0; i < distances.size(); i++) {
       mean_cost_cycle += float(distances[i]);
   }
   std::cout << mean_cost_cycle / distances.size() << std::endl;
   
}
