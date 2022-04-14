#include "lemon/list_graph.h"
#include <Rcpp.h>
#include <iostream>
#include <lemon/connectivity.h>
#include <lemon/euler.h>
#include <tuple>
#include <vector>
using namespace lemon;

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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

//' @rdname lemon_runners
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
