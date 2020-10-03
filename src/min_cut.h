#include <std::vector>
#include <iostream>
#include "lemon/gomory_hu.h"
#include "lemon/list_graph.h"

typedef int Value;

using namespace lemon;
using namespace std;

using Cost = int;

using Graph = ListGraph;
using Node = Graph::Node;
using Edge = Graph::Edge;

template<typename ValueType>
using EdgeMap = ListGraph::EdgeMap<ValueType>;

template<typename ValueType>
using NodeMap = ListGraph::NodeMap<ValueType>;

auto HaoOrlinRunner(std::vector<int> arcSources, std::vector<int> arcTargets, std::vector<int> arcWeights, int numNodes) {
    ListGraph g;
    std::vector<Node> nodes;
    EdgeMap<Cost> dists(g);
    for(int i = 0; i < numNodes; ++i) {
        Node n = g.addNode();
        nodes.push_back(n);
    }

    std::vector<Edge> arcs;
    int NUM_ARCS = arcSources.size();

    for(int i = 0; i < NUM_ARCS; ++i) {
        Edge a = g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
        dists[a] = arcWeights[i];
        arcs.push_back(a);
    }
    GomoryHu<ListGraph, EdgeMap<Cost>> alg(g, dists);
    alg.run();
} 

auto GomoryHuTreeRunner(std::vector<int> arcSources, std::vector<int> arcTargets, std::vector<int> arcWeights, int numNodes) {
    ListGraph g;
    std::vector<Node> nodes;
    EdgeMap<Cost> dists(g);
    for(int i = 0; i < numNodes; ++i) {
        Node n = g.addNode();
        nodes.push_back(n);
    }

    std::vector<Edge> arcs;
    int NUM_ARCS = arcSources.size();

    for(int i = 0; i < NUM_ARCS; ++i) {
        Edge a = g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
        dists[a] = arcWeights[i];
        arcs.push_back(a);
    }
    GomoryHu<ListGraph, EdgeMap<Cost>> alg(g, dists);
    alg.run();
    
    std::vector<int> predecessors;
    std::vector<int> predEdgeWeights;
    std::vector<int> rootDistances;
    for(int i = 0; i < numNodes; ++i) {
        int predNodeLoc = g.id(alg.predNode(nodes[i]));
        int predNodeWeight = alg.predValue(nodes[i]);
        int rootDistance = alg.rootDist(nodes[i]);
        predecessors.push_back(predNodeLoc);
        if(predNodeLoc != -1) {
            predEdgeWeights.push_back(predNodeWeight);
        }
        else {
            predEdgeWeights.push_back(-1);
        }
        rootDistances.push_back(rootDistance);
    
    }

    return std::make_tuple(predecessors, predEdgeWeights, rootDistances);
}
