#include <vector>
#include <iostream>
#include "lemon/planarity.h"

typedef int Value;

using namespace lemon;
using namespace std;

using Cost = int;

using Graph = ListGraph;
using Node = Graph::Node;
using Edge = Graph::Edge;

template<typename ValueType>
using EdgeMap = Graph::EdgeMap<ValueType>;

template<typename ValueType>
using NodeMap = Graph::NodeMap<ValueType>;


auto PlanarDrawingRunner(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
  // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: A pair of vectors, which return the integers necessary to embed the graph onto a grid, where each edge is a straight line.
  Graph g;
  vector<Node> nodes;
  for(int i = 0; i < numNodes; ++i){
      Node n = g.addNode();
      nodes.push_back(n);
  }
  EdgeMap<Cost> costs(g);
  NodeMap<Cost> dists(g);

  vector<Edge> arcs;

  int NUM_ARCS = arcSources.size();

  for(int i = 0; i < NUM_ARCS; ++i) {
      Edge a = g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
      arcs.push_back(a);
  }

  Path<ListDigraph> finale;
  
  PlanarEmbedding<Graph> preprocess(g);
  bool isPlanar = preprocess.run();

  auto & embedding = preprocess.embeddingMap();

  std::vector<int> x_coords;
  std::vector<int> y_coords;
  if(isPlanar) {
  PlanarDrawing<Graph> algorithm(g);
  algorithm.run(embedding);


  for(int i = 0; i < numNodes; ++i) {
      x_coords.push_back(algorithm[nodes[i]].x);
      y_coords.push_back(algorithm[nodes[i]].y);
  }
  }
  
  auto output = std::make_tuple(isPlanar, x_coords, y_coords);
  return output;
}

int main()
{
    // Example Usage - Example taken from EecsforGeeks
   vector<int> arc_src{0,0,1,2,3,3};
   vector<int> arc_targ{1,2,2,3,0,1};
   
   // Output vectors - used to get the information from minimum mean cycle
   vector<int> distances;
   vector<int> path_elements;

   // Runs the algorithm,
   auto output = PlanarDrawingRunner(arc_src, arc_targ, 4);

   if(std::get<0>(output)){
       std::cout << "This graph is planar, with the following embedding:" << std::endl;
   for(int i = 0; i < std::get<1>(output).size(); i++) {
       std::cout << "Node " << i  << " has position " << std::get<1>(output)[i] << ',' << std::get<2>(output)[i] << std::endl;
   }
   }
   else{
       std::cout << "This graph is not planar" << std::endl;
   }
  
}
