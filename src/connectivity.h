#include <vector>
#include <iostream>
#include <tuple>
#include "lemon/list_graph.h"
#include "lemon/connectivity.h"
#include "lemon/euler.h"
#include <Rcpp.h>
using namespace lemon;

// TODO: Add Bipartite Partitions


// [[Rcpp::export]]
List getBipartitePartitions(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A std::tuple containing both a std::vector of length numNodes, containing the partition for each node, and if the graph is bipartite.
    ListGraph g;
    std::vector<ListGraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListGraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    ListGraph::NodeMap<int> nodePartition(g);
    bool isBipartite = bipartitePartitions(g, nodePartition);
    std::vector<int> out_partitions;
    if(isBipartite){
    for(int i = 0; i < numNodes; ++i){
        out_partitions.push_back(nodePartition[nodes[i]]);
    }}
    return List::create(isBipartite, out_partitions);
}


// [[Rcpp::export]]
List getAndcheckTopologicalSort(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A std::tuple containing both a std::vector of length numNodes, containing the index of vertex i in the ordering at location i, and if the graph is a dag.
        ListDigraph g;
    std::vector<ListDigraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListDigraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    ListDigraph::NodeMap<int> nodeOrder(g);
    bool isDAG = checkedTopologicalSort(g, nodeOrder);
    std::vector<int> order;
    if(isDAG){
    for(int i = 0; i < numNodes; ++i){
        order.push_back(nodeOrder[nodes[i]]);
    }}
    return List::create(isDAG, order);
}

// [[Rcpp::export]]
std::vector<int> getTopologicalSort(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One std::vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A std::vector of length numNodes, containing the index of vertex i in the ordering at location i.
    ListDigraph g;
    std::vector<ListDigraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListDigraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    ListDigraph::NodeMap<int> nodeOrder(g);
    topologicalSort(g, nodeOrder);
    std::vector<int> order;
    for(int i = 0; i < numNodes; ++i){
        order.push_back(nodeOrder[nodes[i]]);
    }
    return order;
}

// [[Rcpp::export]]
int IsConnected(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One std::vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if we have a connected graph or not
    ListGraph g;
    std::vector<ListGraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListGraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    return connected(g);
}

// [[Rcpp::export]]
int IsAcyclic(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One std::vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if we have an acyclic graph
    ListGraph g;
    std::vector<ListGraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListGraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    return acyclic(g);
}

// [[Rcpp::export]]
int IsTree(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One std::vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if we have a tree 
    ListGraph g;
    std::vector<ListGraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListGraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    return tree(g);
}

// [[Rcpp::export]]
int IsBipartite(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One std::vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if we have a bipartite graph or not
    ListGraph g;
    std::vector<ListGraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListGraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    return bipartite(g);
}

// [[Rcpp::export]]
int IsStronglyConnected(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One std::vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if we have a strongly connected digraph or not.
    ListDigraph g;
    std::vector<ListDigraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListDigraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    return stronglyConnected(g);
}

// [[Rcpp::export]]
int IsDAG(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One std::vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if we have a DAG, or a Directed Acyclic Graph, or not.
    ListDigraph g;
    std::vector<ListDigraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListDigraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    return dag(g);
}

// [[Rcpp::export]]
int IsBiNodeConnected(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One std::vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if we have a bi-node connected graph or not
    ListGraph g;
    std::vector<ListGraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListGraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    return biNodeConnected(g);
}

// [[Rcpp::export]]
int IsBiEdgeConnected(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One std::vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if we have a bi-edge connected graph or not
    ListGraph g;
    std::vector<ListGraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListGraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    return biEdgeConnected(g);
}

// [[Rcpp::export]]
int IsLoopFree(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One std::vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if the graph has no loop arcs/edges. 
    ListGraph g;
    std::vector<ListGraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListGraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    return loopFree(g);
}

// [[Rcpp::export]]
int IsParallelFree(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One std::vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if the graph has no parallel arcs/edges. 
    ListGraph g;
    std::vector<ListGraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListGraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    return parallelFree(g);
}

// [[Rcpp::export]]
int IsSimpleGraph(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One std::vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if the graph is simple, i.e. it has no loop arcs/edges or parallel arcs/edges
    ListGraph g;
    std::vector<ListGraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListGraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    return simpleGraph(g);
}

// [[Rcpp::export]]
int IsEulerian(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One std::vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if the graph is simple, i.e. it has an eulerian cycle
    ListGraph g;
    std::vector<ListGraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListGraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    return eulerian(g);
}


// [[Rcpp::export]]
int CountBiEdgeConnected(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One std::vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if we have a bi-node connected graph or not
    ListGraph g;
    std::vector<ListGraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListGraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    return countBiEdgeConnectedComponents(g);
}

// [[Rcpp::export]]
int CountConnectedComponents(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One std::vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: An integer stating the number of connected components of this graph
    ListGraph g;
    std::vector<ListGraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListGraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    return countConnectedComponents(g);
}

// [[Rcpp::export]]
int CountBiNodeConnectedComponents(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One std::vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: An integer stating the number of bi-node connected components of this graph
    ListGraph g;
    std::vector<ListGraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListGraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    return countBiNodeConnectedComponents(g);
}

// [[Rcpp::export]]
int CountStronglyConnectedComponents(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Requires: Two std::vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One std::vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: An integer stating the number of strongly connected components of this directed graph
    ListDigraph g;
    std::vector<ListDigraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListDigraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    return countStronglyConnectedComponents(g);
}

// [[Rcpp::export]]
std::vector<int> FindStronglyConnectedComponents(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Returns: A std::vector containing the component number of each node
    ListDigraph g;
    std::vector<ListDigraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListDigraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    ListDigraph::NodeMap<int> ComponentMap(g);
    stronglyConnectedComponents(g, ComponentMap);
    std::vector<int> components;
    for(int i = 0; i < numNodes; i++) {
        components.push_back(ComponentMap[nodes[i]]);
    }
    
    return components;
}

// [[Rcpp::export]]
std::vector<std::vector<int>> FindStronglyConnectedCutArcs(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Returns: Two std::vectors containing the source and destination of the cut arcs
    ListDigraph g;
    std::vector<ListDigraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListDigraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    std::vector<ListDigraph::Arc> arcs;
    for(int i = 0; i < NUM_ARCS; ++i) {
        auto a = g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
        arcs.push_back(a);
    }
    ListDigraph::ArcMap<int> ComponentMap(g);
    
    stronglyConnectedCutArcs(g, ComponentMap);
    std::vector<int> arc_sources;
    std::vector<int> arc_destinations;
    for(int i = 0; i < NUM_ARCS; i++) {
        if(ComponentMap[arcs[i]]) {
            arc_sources.push_back(g.id(g.source(arcs[i])));
            arc_destinations.push_back(g.id(g.target(arcs[i])));
        }
    }
    
    std::vector<std::vector<int>> output;
    output.push_back(arc_sources);
    output.push_back(arc_destinations);
    return output;
}


// [[Rcpp::export]]
std::vector<std::vector<int>> FindBiEdgeConnectedCutEdges(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Returns: Two std::vectors containing the source and destination of the cut arcs
    ListGraph g;
    std::vector<ListGraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListGraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    std::vector<ListGraph::Edge> arcs;
    for(int i = 0; i < NUM_ARCS; ++i) {
        auto a = g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
        arcs.push_back(a);
    }
    ListGraph::EdgeMap<int> ComponentMap(g);
    
    biEdgeConnectedCutEdges(g, ComponentMap);
    std::vector<int> arc_sources;
    std::vector<int> arc_destinations;
    for(int i = 0; i < NUM_ARCS; i++) {
        if(ComponentMap[arcs[i]]) {
            arc_sources.push_back(g.id(g.u(arcs[i])));
            arc_destinations.push_back(g.id(g.v(arcs[i])));
        }
    }
    std::vector<std::vector<int>> output;
    output.push_back(arc_sources);
    output.push_back(arc_destinations);
    return output;
}


// [[Rcpp::export]]
std::vector<int> FindBiNodeConnectedComponents(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    ListGraph g;
    std::vector<ListGraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListGraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    std::vector<ListGraph::Edge> arcs;
    for(int i = 0; i < NUM_ARCS; ++i) {
        auto a = g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
        arcs.push_back(a);
    }
    ListGraph::EdgeMap<int> ComponentMap(g);
    biNodeConnectedComponents(g, ComponentMap);
    std::vector<int> component_number;
    for(int i = 0; i < NUM_ARCS; i++) {
        component_number.push_back(ComponentMap[arcs[i]]);
    }
    return component_number;
}


// [[Rcpp::export]]
std::vector<int> FindBiNodeConnectedNodes(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    ListGraph g;
    std::vector<ListGraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListGraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    std::vector<ListGraph::Edge> arcs;
    for(int i = 0; i < NUM_ARCS; ++i) {
        auto a = g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
        arcs.push_back(a);
    }
    ListGraph::NodeMap<int> CutMap(g);
    biNodeConnectedCutNodes(g, CutMap);
    std::vector<int> CutNodes;
    for(int i = 0; i < numNodes; ++i) {
        if(CutMap[nodes[i]]) {
            CutNodes.push_back(g.id(nodes[i]));
        } 
    }
    return CutNodes;
}


// [[Rcpp::export]]
std::vector<int> FindConnectedComponents(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    // Returns: A std::vector containing the component number of each node
    ListGraph g;
    std::vector<ListGraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListGraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    ListGraph::NodeMap<int> ComponentMap(g);
    connectedComponents(g, ComponentMap);
    std::vector<int> components;
    for(int i = 0; i < numNodes; i++) {
        components.push_back(ComponentMap[nodes[i]]);
    }
    
    return components;
}


// [[Rcpp::export]]
std::vector<int> FindBiEdgeConnectedComponents(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
    ListGraph g;
    std::vector<ListGraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        ListGraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    int NUM_ARCS = arcSources.size();
    for(int i = 0; i < NUM_ARCS; ++i) {
        g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
    }
    ListGraph::NodeMap<int> ComponentMap(g);
    biEdgeConnectedComponents(g, ComponentMap);
    std::vector<int> components;
    for(int i = 0; i < numNodes; i++) {
        components.push_back(ComponentMap[nodes[i]]);
    }
    
    return components;
}

