#include "lemon/list_graph.h"
#include <Rcpp.h>
#include <iostream>
#include <lemon/connectivity.h>
#include <lemon/euler.h>
#include <tuple>
#include <vector>
using namespace lemon;

//' Graph Input Specifications
//' @name Input-Information
//' @description Due to how LEMON operates, and to make the interfaces similar to the actual program,
//' graphs in rlemon use the following 2 vectors:
//' arcSources, and arcTargets
//' to acquire information about how the graph is structured
//' each edge in a graph will consist of a (node id, node id) pair, which is represented
//' by the ith entry in both arcSources and arcTargets.
//' The nodes are 0-indexed, and must be sequential.
//' numNodes must be equal to the number of nodes in the graph, as otherwise there
//' are potentials to error out.
//' As an example, the cycle graph on three vertices would have the following input:
//' arcSources <- c(0,1,2)
//' arcTargets <- c(1,2,0)
//' numNodes <- 3
//' Here, the edges are (0,1), (1,2), (2,0)
//> NULL

//' Connectivity Algorithms - Boolean Return
//' @name Connectivity-Algorithms-1
//' @param arcSources, a vector corresponding to the source nodes of a graph's edges
//' @param arcTargets, a vector corresponding to the destination nodes of a graph's edges
//' @param numNodes, the number of nodes in the graph
//' @return a boolean, stating if a graph has some property
//> NULL

//' Connectivity Algorithms - Integer Return
//' @name Connectivity-Algorithms-2
//' @param arcSources, a vector corresponding to the source nodes of a graph's edges
//' @param arcTargets, a vector corresponding to the destination nodes of a graph's edges
//' @param numNodes, the number of nodes in the graph
//' @return an integer, counting some property of a graph
//> NULL

//' Connectivity Algorithms - List Return
//' @name Connectivity-Algorithms-3
//' @param arcSources, a vector corresponding to the source nodes of a graph's edges
//' @param arcTargets, a vector corresponding to the destination nodes of a graph's edges
//' @param numNodes, the number of nodes in the graph
//' @return a List, returning some set of nodes or edges in a graph
//> NULL

//' @rdname Connectivity-Algorithms-3
//' @return `getBipartitePartitionsRunner` returns an R List containing (1) A boolean stating if the graph is bipartite, and (2) an std::vector of length numNodes, containing the partition for each node
// [[Rcpp::export]]
Rcpp::List getBipartitePartitionsRunner(std::vector<int> arcSources,
                                        std::vector<int> arcTargets,
                                        int numNodes) {
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  ListGraph::NodeMap<int> nodePartition(g);
  bool isBipartite = bipartitePartitions(g, nodePartition);
  std::vector<int> out_partitions;
  if (isBipartite) {
    for (int i = 0; i < numNodes; ++i) {
      out_partitions.push_back(nodePartition[nodes[i]]);
    }
  }
  return Rcpp::List::create(isBipartite, out_partitions);
}

//' @rdname Connectivity-Algorithms-3
//' @return `getAndCheckTopologicalSortRunner` returns an R List containing (1) A boolean stating if the graph is a dag, and (2) a vector of length numNodes, containing the index of vertex i in the ordering at location i
// [[Rcpp::export]]
Rcpp::List getAndCheckTopologicalSortRunner(std::vector<int> arcSources,
                                            std::vector<int> arcTargets,
                                            int numNodes) {
  ListDigraph g;
  std::vector<ListDigraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  ListDigraph::NodeMap<int> nodeOrder(g);
  bool isDAG = checkedTopologicalSort(g, nodeOrder);
  std::vector<int> order;
  if (isDAG) {
    for (int i = 0; i < numNodes; ++i) {
      order.push_back(nodeOrder[nodes[i]]);
    }
  }
  return Rcpp::List::create(isDAG, order);
}

//' @rdname Connectivity-Algorithms-3
//' @return `getTopologicalSortRunner` returns a vector of length numNodes, containing the index of vertex i in the ordering at location i.
// [[Rcpp::export]]
std::vector<int> getTopologicalSortRunner(std::vector<int> arcSources,
                                          std::vector<int> arcTargets,
                                          int numNodes) {
  ListDigraph g;
  std::vector<ListDigraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  ListDigraph::NodeMap<int> nodeOrder(g);
  topologicalSort(g, nodeOrder);
  std::vector<int> order;
  for (int i = 0; i < numNodes; ++i) {
    order.push_back(nodeOrder[nodes[i]]);
  }
  return order;
}

//' @rdname Connectivity-Algorithms-1
//' @description `IsConnected` returns if a graph is connected or not
//' @examples
//' data(small_graph_example)
//' start <- small_graph_example$startnodes
//' end <- small_graph_example$endnodes
//' numnodes <- length(unique(c(start, end)))
//' IsConnected(start, end, numnodes)
// [[Rcpp::export]]
int IsConnectedRunner(std::vector<int> arcSources, std::vector<int> arcTargets,
                      int numNodes) {
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  return connected(g);
}

//' @rdname Connectivity-Algorithms-1
//' @description `IsAcyclic` returns if a graph is acyclic or not
// [[Rcpp::export]]
int IsAcyclicRunner(std::vector<int> arcSources, std::vector<int> arcTargets,
                    int numNodes) {
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  return acyclic(g);
}

//' @rdname Connectivity-Algorithms-1
//' @description `IsTree` returns if a graph is a tree or not
// [[Rcpp::export]]
int IsTreeRunner(std::vector<int> arcSources, std::vector<int> arcTargets,
                 int numNodes) {
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  return tree(g);
}

//' @rdname Connectivity-Algorithms-1
//' @description `IsBipartite` returns if a graph is bipartite or not
// [[Rcpp::export]]
int IsBipartiteRunner(std::vector<int> arcSources, std::vector<int> arcTargets,
                      int numNodes) {
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  return bipartite(g);
}

//' @rdname Connectivity-Algorithms-1
//' @description `IsStronglyConnected` returns if a graph is strongly connected or not
// [[Rcpp::export]]
int IsStronglyConnectedRunner(std::vector<int> arcSources,
                              std::vector<int> arcTargets, int numNodes) {
  ListDigraph g;
  std::vector<ListDigraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  return stronglyConnected(g);
}

//' @rdname Connectivity-Algorithms-1
//' @description `IsDAG` returns if a graph is a DAG or not
// [[Rcpp::export]]
int IsDAGRunner(std::vector<int> arcSources, std::vector<int> arcTargets,
                int numNodes) {
  ListDigraph g;
  std::vector<ListDigraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  return dag(g);
}

//' @rdname Connectivity-Algorithms-1
//' @description `IsBiNodeConnected` returns if a graph is bi-node connected or not
// [[Rcpp::export]]
int IsBiNodeConnectedRunner(std::vector<int> arcSources,
                            std::vector<int> arcTargets, int numNodes) {
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  return biNodeConnected(g);
}

//' @rdname Connectivity-Algorithms-1
//' @description `IsBiEdgeConnected` returns if a graph is bi-edge connected or not
// [[Rcpp::export]]
int IsBiEdgeConnectedRunner(std::vector<int> arcSources,
                            std::vector<int> arcTargets, int numNodes) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: A boolean stating if we have a bi-edge connected graph or not
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  return biEdgeConnected(g);
}

//' @rdname Connectivity-Algorithms-1
//' @description `IsLoopFree` returns if a graph is loop-free or not
// [[Rcpp::export]]
int IsLoopFreeRunner(std::vector<int> arcSources, std::vector<int> arcTargets,
                     int numNodes) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: A boolean stating if the graph has no loop arcs/edges.
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  return loopFree(g);
}

//' @rdname Connectivity-Algorithms-1
//' @description `IsParallelFree` returns if a graph is parallel-free or not
// [[Rcpp::export]]
int IsParallelFreeRunner(std::vector<int> arcSources,
                         std::vector<int> arcTargets, int numNodes) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: A boolean stating if the graph has no parallel arcs/edges.
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  return parallelFree(g);
}

//' @rdname Connectivity-Algorithms-1
//' @description `IsSimpleGraph` returns if a graph is simple or not
// [[Rcpp::export]]
int IsSimpleGraphRunner(std::vector<int> arcSources,
                        std::vector<int> arcTargets, int numNodes) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: A boolean stating if the graph is simple, i.e. it has no loop arcs/edges or parallel arcs/edges
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  return simpleGraph(g);
}

//' @rdname Connectivity-Algorithms-1
//' @description `IsEulerian` returns if a graph is Eulerian or not
// [[Rcpp::export]]
int IsEulerianRunner(std::vector<int> arcSources, std::vector<int> arcTargets,
                     int numNodes) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: A boolean stating if the graph is simple, i.e. it has an Eulerian cycle
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  return eulerian(g);
}

//' @rdname Connectivity-Algorithms-2
//' @description `CountBiEdgeConnectedComponents` returns how many Bi-Edge Connected Components a graph has.
// [[Rcpp::export]]
int CountBiEdgeConnectedComponentsRunner(std::vector<int> arcSources,
                                         std::vector<int> arcTargets,
                                         int numNodes) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: A boolean stating if we have a bi-node connected graph or not
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  return countBiEdgeConnectedComponents(g);
}

//' @rdname Connectivity-Algorithms-2
//' @description `CountConnectedComponents` returns how many Connected Components a graph has.
// [[Rcpp::export]]
int CountConnectedComponentsRunner(std::vector<int> arcSources,
                                   std::vector<int> arcTargets, int numNodes) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: An integer stating the number of connected components of this graph
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  return countConnectedComponents(g);
}

//' @rdname Connectivity-Algorithms-2
//' @description `CountBiNodeConnectedComponents` returns how many Bi-Node Connected Components a graph has.
// [[Rcpp::export]]
int CountBiNodeConnectedComponentsRunner(std::vector<int> arcSources,
                                         std::vector<int> arcTargets,
                                         int numNodes) {
  // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
  //           One std::vector, arcDistances, which assigns for each arc an associated distance
  //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
  // Returns: An integer stating the number of bi-node connected components of this graph
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  return countBiNodeConnectedComponents(g);
}

//' @rdname Connectivity-Algorithms-2
//' @description `CountStronglyConnectedComponents` returns how many Strongly Connected Components a graph has.
// [[Rcpp::export]]
int CountStronglyConnectedComponentsRunner(std::vector<int> arcSources,
                                           std::vector<int> arcTargets,
                                           int numNodes) {
  ListDigraph g;
  std::vector<ListDigraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  return countStronglyConnectedComponents(g);
}

//' @rdname Connectivity-Algorithms-3
//' @description `FindStronglyConnectedComponents` returns a vector containing the component number of each node
// [[Rcpp::export]]
std::vector<int> FindStronglyConnectedComponentsRunner(
    std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
  ListDigraph g;
  std::vector<ListDigraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  ListDigraph::NodeMap<int> ComponentMap(g);
  stronglyConnectedComponents(g, ComponentMap);
  std::vector<int> components;
  for (int i = 0; i < numNodes; i++) {
    components.push_back(ComponentMap[nodes[i]]);
  }

  return components;
}

//' @rdname Connectivity-Algorithms-3
//' @description `FindStronglyConnectedCutArcs` returns an R List containing 1) A list of cut arc sources, and 2) A list of cut arc destinations
// [[Rcpp::export]]
Rcpp::List FindStronglyConnectedCutArcsRunner(std::vector<int> arcSources,
                                              std::vector<int> arcTargets,
                                              int numNodes) {
  // Returns: Two std::vectors containing the source and destination of the cut arcs
  ListDigraph g;
  std::vector<ListDigraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  std::vector<ListDigraph::Arc> arcs;
  for (int i = 0; i < NUM_ARCS; ++i) {
    auto a = g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    arcs.push_back(a);
  }
  ListDigraph::ArcMap<int> ComponentMap(g);

  stronglyConnectedCutArcs(g, ComponentMap);
  std::vector<int> arc_sources;
  std::vector<int> arc_destinations;
  for (int i = 0; i < NUM_ARCS; i++) {
    if (ComponentMap[arcs[i]]) {
      arc_sources.push_back(g.id(g.source(arcs[i])) + 1);
      arc_destinations.push_back(g.id(g.target(arcs[i])) + 1);
    }
  }

  return Rcpp::List::create(arc_sources, arc_destinations);
}

//' @rdname Connectivity-Algorithms-3
//' @description `FindBiEdgeConnectedCutEdges` returns an R List containing 1) A list of cut edge sources, and 2) A list of cut edge destinations
// [[Rcpp::export]]
Rcpp::List FindBiEdgeConnectedCutEdgesRunner(std::vector<int> arcSources,
                                             std::vector<int> arcTargets,
                                             int numNodes) {
  // Returns: Two std::vectors containing the source and destination of the cut arcs
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  std::vector<ListGraph::Edge> arcs;
  for (int i = 0; i < NUM_ARCS; ++i) {
    auto a = g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    arcs.push_back(a);
  }
  ListGraph::EdgeMap<int> ComponentMap(g);

  biEdgeConnectedCutEdges(g, ComponentMap);
  std::vector<int> arc_sources;
  std::vector<int> arc_destinations;
  for (int i = 0; i < NUM_ARCS; i++) {
    if (ComponentMap[arcs[i]]) {
      arc_sources.push_back(g.id(g.u(arcs[i])) + 1);
      arc_destinations.push_back(g.id(g.v(arcs[i])) + 1);
    }
  }
  return Rcpp::List::create(arc_sources, arc_destinations);
}

//' @rdname Connectivity-Algorithms-3
//' @description `FindBiNodeConnectedCutComponents` returns a vector containing the component number of each cut arc.
// [[Rcpp::export]]
std::vector<int>
FindBiNodeConnectedComponentsRunner(std::vector<int> arcSources,
                                    std::vector<int> arcTargets, int numNodes) {
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  std::vector<ListGraph::Edge> arcs;
  for (int i = 0; i < NUM_ARCS; ++i) {
    auto a = g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    arcs.push_back(a);
  }
  ListGraph::EdgeMap<int> ComponentMap(g);
  biNodeConnectedComponents(g, ComponentMap);
  std::vector<int> component_number;
  for (int i = 0; i < NUM_ARCS; i++) {
    component_number.push_back(ComponentMap[arcs[i]]);
  }
  return component_number;
}

//' @rdname Connectivity-Algorithms-3
//' @description `FindBiNodeConnectedCutNodes` returns a vector containing the cut nodes
// [[Rcpp::export]]
std::vector<int> FindBiNodeConnectedCutNodesRunner(std::vector<int> arcSources,
                                                   std::vector<int> arcTargets,
                                                   int numNodes) {
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  std::vector<ListGraph::Edge> arcs;
  for (int i = 0; i < NUM_ARCS; ++i) {
    auto a = g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    arcs.push_back(a);
  }
  ListGraph::NodeMap<int> CutMap(g);
  biNodeConnectedCutNodes(g, CutMap);
  std::vector<int> CutNodes;
  for (int i = 0; i < numNodes; ++i) {
    if (CutMap[nodes[i]]) {
      CutNodes.push_back(g.id(nodes[i]) + 1);
    }
  }
  return CutNodes;
}

//' @rdname Connectivity-Algorithms-3
//' @description `FindConnectedComponents` returns a vector containing the component number of each node
// [[Rcpp::export]]
std::vector<int> FindConnectedComponentsRunner(std::vector<int> arcSources,
                                               std::vector<int> arcTargets,
                                               int numNodes) {
  // Returns: A std::vector containing the component number of each node
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  ListGraph::NodeMap<int> ComponentMap(g);
  connectedComponents(g, ComponentMap);
  std::vector<int> components;
  for (int i = 0; i < numNodes; i++) {
    components.push_back(ComponentMap[nodes[i]]);
  }

  return components;
}

//' @rdname Connectivity-Algorithms-3
//' @description `FindBiEdgeConnectedComponents` returns a vector containing the component number of each node
// [[Rcpp::export]]
std::vector<int>
FindBiEdgeConnectedComponentsRunner(std::vector<int> arcSources,
                                    std::vector<int> arcTargets, int numNodes) {
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }
  ListGraph::NodeMap<int> ComponentMap(g);
  biEdgeConnectedComponents(g, ComponentMap);
  std::vector<int> components;
  for (int i = 0; i < numNodes; i++) {
    components.push_back(ComponentMap[nodes[i]]);
  }

  return components;
}
