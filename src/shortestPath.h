#include <vector>
#include <iostream>
#include "lemon/bellman_ford.h"
#include "lemon/list_graph.h"
#include "lemon/dijkstra.h"
#include "lemon/suurballe.h"



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

auto SuurballeRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcDistances, int numNodes, int startnode, int endnode, int numberOfArcs) {
  // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: Two vectors. The first refers to the distances from each node to the startnode, while the second refers to the predecessors that form the shortest distance tree. 
  // Note: Invalid predecessors are indicated with "-1", and all nodes are 0-indexed
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

  
  Suurballe< ListDigraph, DigraphExtender<ListDigraphBase>::ArcMap<int> > bf(g,costs);
  bf.run(nodes[startnode],nodes[endnode], numberOfArcs);
   
}
 
auto DijkstraRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcDistances, int numNodes, int startnode) {
  // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: Two vectors. The first refers to the distances from each node to the startnode, while the second refers to the predecessors that form the shortest distance tree. 
  // Note: Invalid predecessors are indicated with "-1", and all nodes are 0-indexed
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

  
  Dijkstra< ListDigraph, DigraphExtender<ListDigraphBase>::ArcMap<int> > bf(g,costs);
  bf.run(nodes[startnode]);
  vector<int> distances;
  vector<int> predecessors;
  for(int i = 0; i < numNodes; i++) {
      distances.push_back(bf.dist(nodes[i]));
      predecessors.push_back(g.id(bf.predNode(nodes[i])));
  }
  return std::make_tuple(distances, predecessors);
}



auto BellmanFordRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcDistances, int numNodes, int startnode) {
  // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: Two vectors. The first refers to the distances from each node to the startnode, while the second refers to the predecessors that form the shortest distance tree. 
  // Note: Invalid predecessors are indicated with "-1", and all nodes are 0-indexed
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

  
  BellmanFord< ListDigraph, DigraphExtender<ListDigraphBase>::ArcMap<int> > bf = BellmanFord<ListDigraph, DigraphExtender<ListDigraphBase>::ArcMap<int> > (g,costs);
  bf.run(nodes[startnode]);
  vector<int> distances;
  vector<int> predecessors;
  for(int i = 0; i < numNodes; i++) {
      distances.push_back(bf.dist(nodes[i]));
      predecessors.push_back(g.id(bf.predNode(nodes[i])));
  }
  return std::make_tuple(distances, predecessors);
}
