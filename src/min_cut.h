#include <std::vector>
#include <iostream>
#include "lemon/gomory_hu.h"
#include "lemon/list_graph.h"


using namespace lemon;
using namespace std;


auto HaoOrlinRunner(std::vector<int> arcSources, std::vector<int> arcTargets, std::vector<int> arcWeights, int numNodes) {
    ListGraph g;
    std::vector<ListGraph::Node> nodes;
    ListGraph::EdgeMap<int> dists(g);
    for(int i = 0; i < numNodes; ++i) {
        ListGraph::Node n = g.addNode();
        nodes.push_back(n);
    }

    std::vector<ListGraph::Edge> arcs;
    int NUM_ARCS = arcSources.size();

    for(int i = 0; i < NUM_ARCS; ++i) {
        ListGraph::Edge a = g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
        dists[a] = arcWeights[i];
        arcs.push_back(a);
    }
    GomoryHu<ListGraph, ListGraph::EdgeMap<int>> alg(g, dists);
    alg.run();
} 

auto GomoryHuTreeRunner(std::vector<int> arcSources, std::vector<int> arcTargets, std::vector<int> arcWeights, int numNodes) {
    ListGraph g;
    std::vector<ListGraph::Node> nodes;
    ListGraph::EdgeMap<Cost> dists(g);
    for(int i = 0; i < numNodes; ++i) {
        Node n = g.addNode();
        nodes.push_back(n);
    }

    std::vector<ListGraph::Edge> arcs;
    int NUM_ARCS = arcSources.size();

    for(int i = 0; i < NUM_ARCS; ++i) {
        ListGraph::Edge a = g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
        dists[a] = arcWeights[i];
        arcs.push_back(a);
    }
    GomoryHu<ListGraph, ListGraph::EdgeMap<Cost>> alg(g, dists);
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
