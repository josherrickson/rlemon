#include <vector>
#include <iostream>
#include "lemon/list_graph.h"
#include "lemon/connectivity.h"
#include "lemon/euler.h"
using namespace lemon;
using namespace std;

// TODO: Add TopologicalSort, CheckedTopologicalSort, Bipartite Partitions, loopfree, parallelfree,  simpleGraph, and eulerian

auto IsConnected(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if we have a connected graph or not
    ListGraph g;
    vector<ListGraph::Node> nodes;
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

auto IsAcyclic(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if we have a connected graph or not
    ListGraph g;
    vector<ListGraph::Node> nodes;
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


auto IsTree(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if we have a tree 
    ListGraph g;
    vector<ListGraph::Node> nodes;
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

auto IsBipartite(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if we have a bipartite graph or not
    ListGraph g;
    vector<ListGraph::Node> nodes;
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


auto IsStronglyConnected(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if we have a strongly connected digraph or not.
    ListDigraph g;
    vector<ListDigraph::Node> nodes;
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

auto IsDAG(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if we have a DAG, or a Directed Acyclic Graph, or not.
    ListDigraph g;
    vector<ListDigraph::Node> nodes;
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


auto IsBiNodeConnected(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if we have a bi-node connected graph or not
    ListGraph g;
    vector<ListGraph::Node> nodes;
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


auto IsBiEdgeConnected(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if we have a bi-node connected graph or not
    ListGraph g;
    vector<ListGraph::Node> nodes;
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

auto CountBiEdgeConnected(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A boolean stating if we have a bi-node connected graph or not
    ListGraph g;
    vector<ListGraph::Node> nodes;
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

auto CountConnectedComponents(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: An integer stating the number of connected components of this graph
    ListGraph g;
    vector<ListGraph::Node> nodes;
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


auto CountBiNodeConnectedComponents(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: An integer stating the number of bi-node connected components of this graph
    ListGraph g;
    vector<ListGraph::Node> nodes;
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


auto CountStronglyConnectedComponents(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: An integer stating the number of strongly connected components of this directed graph
    ListDigraph g;
    vector<ListDigraph::Node> nodes;
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

auto FindStronglyConnectedComponents(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    // Returns: A vector containing the component number of each node
    ListDigraph g;
    vector<ListDigraph::Node> nodes;
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

auto FindStronglyConnectedCutArcs(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    // Returns: Two vectors containing the source and destination of the cut arcs
    ListDigraph g;
    vector<ListDigraph::Node> nodes;
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
    vector<int> arc_sources;
    vector<int> arc_destinations;
    for(int i = 0; i < NUM_ARCS; i++) {
        if(ComponentMap[arcs[i]]) {
            arc_sources.push_back(g.id(g.source(arcs[i])));
            arc_destinations.push_back(g.id(g.target(arcs[i])));
        }
    }
    
    return std::make_tuple(arc_sources, arc_destinations);
}

auto FindBiEdgeConnectedCutEdges(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    // Returns: Two vectors containing the source and destination of the cut arcs
    ListGraph g;
    vector<ListGraph::Node> nodes;
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
    vector<int> arc_sources;
    vector<int> arc_destinations;
    for(int i = 0; i < NUM_ARCS; i++) {
        if(ComponentMap[arcs[i]]) {
            arc_sources.push_back(g.id(g.u(arcs[i])));
            arc_destinations.push_back(g.id(g.v(arcs[i])));
        }
    }
    
    return std::make_tuple(arc_sources, arc_destinations);
}


auto FindBiNodeConnectedComponents(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    ListGraph g;
    vector<ListGraph::Node> nodes;
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
    vector<int> component_number;
    for(int i = 0; i < NUM_ARCS; i++) {
        component_number.push_back(ComponentMap[arcs[i]]);
    }
    return component_number;
}

auto FindBiNodeConnectedNodes(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    ListGraph g;
    vector<ListGraph::Node> nodes;
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

auto FindConnectedComponents(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    // Returns: A vector containing the component number of each node
    ListGraph g;
    vector<ListGraph::Node> nodes;
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

auto FindBiEdgeConnectedComponents(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    ListGraph g;
    vector<ListGraph::Node> nodes;
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

int main()
{
    // Example Usage - Example taken from EecsforGeeks
    vector<int> arc_src{ 0, 0, 0, 1, 1, 2, 2, 3, 4, 4, 6, 7};
    vector<int> arc_targ{1, 3, 5, 2, 4, 6, 3, 7, 5, 6, 7, 5};
    vector<int> arc_costs{10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    // Output vectors - used to get the information from minimum mean cycle
    vector<int> distances;
    vector<int> path_elements;

    // Runs the algorithm,
    std::cout << IsConnected(arc_src, arc_targ, 8) << std::endl;

 }
