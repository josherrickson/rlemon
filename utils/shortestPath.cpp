#include <vector>
#include <iostream>
#include "lemon/list_graph.h"



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

auto MakeGraph(vector<int> arcSources, vector<int> arcTargets, vector<int> arcDistances, int numNodes) {
  // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: A tuple containing the graph, the graph's nodes, and the arcs of the graph via a copy. 
  // TODO: Change this, as it's most likely unoptimal. 
  ListDigraph g;
  vector<Node> nodes;
  for(int i = 0; i < numNodes; ++i){
      Node n = g.addNode();
      nodes.push_back(n);
  }

  vector<Arc> arcs;

  int NUM_ARCS = arcSources.size();

  for(int i = 0; i < NUM_ARCS; ++i) {
      Arc a = g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
      arcs.push_back(a);
  }
  return std::make_tuple(g,nodes,arcs);

}


