#include <vector>
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

auto HaoOrlinRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcWeights, int numNodes) {
    ListGraph g;
    vector<Node> nodes;
    EdgeMap<Cost> dists(g);
    for(int i = 0; i < numNodes; ++i) {
        Node n = g.addNode();
        nodes.push_back(n);
    }

    vector<Edge> arcs;
    int NUM_ARCS = arcSources.size();

    for(int i = 0; i < NUM_ARCS; ++i) {
        Edge a = g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
        dists[a] = arcWeights[i];
        arcs.push_back(a);
    }
    GomoryHu<ListGraph, EdgeMap<Cost>> alg(g, dists);
    alg.run();
} 

auto GomoryHuTreeRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcWeights, int numNodes) {
    ListGraph g;
    vector<Node> nodes;
    EdgeMap<Cost> dists(g);
    for(int i = 0; i < numNodes; ++i) {
        Node n = g.addNode();
        nodes.push_back(n);
    }

    vector<Edge> arcs;
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
int main()
{
    vector<int> arc_src{ 0, 0, 0, 1, 1, 2, 2, 3, 4, 4, 6, 7};
    vector<int> arc_targ{1, 3, 5, 2, 4, 6, 3, 7, 5, 6, 7, 5};
    vector<int> arc_costs{10, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

    // Output vectors - used to get the information from minimum mean cycle
    vector<int> distances;
    vector<int> path_elements;

    // Runs the algorithm,
    auto output = GomoryHuTreeRunner(arc_src, arc_targ, arc_costs,  8);

}
