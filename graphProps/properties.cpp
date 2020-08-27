#include <vector>
#include <iostream>
#include "euler.h"
#include "connectivity.h"

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


std::vector<int> BellmanFordRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcDistances, int numNodes, int startnode) {
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

  
  BellmanFord< ListDigraph, DigraphExtender<ListDigraphBase>::ArcMap<int> > bf = BellmanFord<ListDigraph, DigraphExtender<ListDigraphBase>::ArcMap<int> > (g,costs);
  bf.run(nodes[0]);
  vector<int> output;
  for(int i = 0; i < numNodes; i++) {
      output.push_back(bf.dist(nodes[i]));
  }
  return output;
}

int main()
{
    // Example Usage - Works with g++ shortestPath.cpp && ./a.out
   vector<int> arc_src{0, 0, 1, 1, 1, 2, 2, 3, 3,4,4,4,5,5,6};
   vector<int> arc_targ{1, 2, 2, 3, 4, 3, 6, 4, 6,6,7,5,7,8,7};
   vector<int> arc_costs{5, 2, 2, 3, 7, 3, 9, 2, 6,5,7,8,3,4,2};
   auto output = BellmanFordRunner(arc_src, arc_targ, arc_costs, 9, 0);

   for(int i = 0; i < output.size(); i++){
       std::cout << output[i] << std::endl;
   }
   

    return 1;
}
