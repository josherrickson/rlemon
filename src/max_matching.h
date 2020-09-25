#include <vector>
#include <iostream>
#include "lemon/matching.h"
#include "lemon/list_graph.h"
#include "lemon/fractional_matching.h"

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


auto MaximumWeightPerfectMatchingRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcWeights, int numNodes) {
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
    auto test = MaxWeightedPerfectMatching<ListGraph, EdgeMap<Cost>>(g, dists);
    std::vector<std::pair<int,int>> matching_arcs;
    test.run();
    for(int i = 0; i < NUM_ARCS; i++) {
        if(test.matching(arcs[i])){
            matching_arcs.push_back(std::pair<int,int>(g.id(g.u(arcs[i])), g.id(g.v(arcs[i]))));
        }    
    }
    std::cout << test.matchingWeight() << std::endl;
    return matching_arcs;
}

auto MaximumWeightFractionalPerfectMatchingRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcWeights, int numNodes) {
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
    auto test = MaxWeightedPerfectFractionalMatching<ListGraph, EdgeMap<Cost>>(g, dists);
    std::vector<std::pair<int,int>> matching_arcs;
    test.run();
    for(int i = 0; i < NUM_ARCS; i++) {
        if(test.matching(arcs[i])){
            matching_arcs.push_back(std::pair<int,int>(g.id(g.u(arcs[i])), g.id(g.v(arcs[i]))));
        }    
    }
    std::cout << test.matchingWeight() << std::endl;
    return matching_arcs;
}




auto MaximumWeightFractionalMatchingRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcWeights,  int numNodes) {
    ListGraph g;
    vector<Node> nodes;
    EdgeMap<Cost> dists(g);
    for(int i = 0; i < numNodes; ++i){
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
    auto test = MaxWeightedFractionalMatching<ListGraph, EdgeMap<Cost>>(g, dists);
    std::vector<std::pair<int,int>> matching_arcs;
    test.run();
    for(int i = 0; i < NUM_ARCS; i++) {
        if(test.matching(arcs[i])){
            matching_arcs.push_back(std::pair<int,int>(g.id(g.u(arcs[i])), g.id(g.v(arcs[i]))));
        }    
    }
    std::cout << test.matchingSize() << std::endl;
    return matching_arcs;
}


auto MaximumWeightMatchingRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcWeights,  int numNodes) {
    ListGraph g;
    vector<Node> nodes;
    EdgeMap<Cost> dists(g);
    for(int i = 0; i < numNodes; ++i){
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
    auto test = MaxWeightedMatching<ListGraph, EdgeMap<Cost>>(g, dists);
    std::vector<std::pair<int,int>> matching_arcs;
    test.run();
    for(int i = 0; i < NUM_ARCS; i++) {
        if(test.matching(arcs[i])){
            matching_arcs.push_back(std::pair<int,int>(g.id(g.u(arcs[i])), g.id(g.v(arcs[i]))));
        }    
    }
    std::cout << test.matchingSize() << std::endl;
    return matching_arcs;
}

auto MaximumCardinalityMatchingRunner(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: One vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
    ListGraph g;
    vector<Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        Node n = g.addNode();
        nodes.push_back(n);
    }
    NodeMap<Cost> dists(g);

    vector<Edge> arcs;

    int NUM_ARCS = arcSources.size();

    for(int i = 0; i < NUM_ARCS; ++i) {
        Edge a = g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
        arcs.push_back(a);
    }
    ListGraph::EdgeMap<int> map(g);
    auto test = MaxMatching<ListGraph>(g);
    test.run();
    std::vector<std::pair<int,int>> matching_arcs;
    for(int i = 0; i < NUM_ARCS; i++) {
        if(test.matching(arcs[i])){
            matching_arcs.push_back(std::pair<int,int>(g.id(g.u(arcs[i])), g.id(g.v(arcs[i]))));
        }    
    }
    return matching_arcs;
}

auto MaximumCardinalityFractionalMatchingRunner(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: One vector, which contains the minimum distances from the start node to each of the nodes, with "-1" used as a placeholder to indicates the target and source and disjoint
    ListGraph g;
    vector<Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        Node n = g.addNode();
        nodes.push_back(n);
    }
    NodeMap<Cost> dists(g);

    vector<Edge> arcs;

    int NUM_ARCS = arcSources.size();

    for(int i = 0; i < NUM_ARCS; ++i) {
        Edge a = g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
        arcs.push_back(a);
    }
    ListGraph::EdgeMap<int> map(g);
    auto test = MaxFractionalMatching<ListGraph>(g);
    test.run();
    std::vector<std::pair<int,int>> matching_arcs;
    for(int i = 0; i < NUM_ARCS; i++) {
        if(test.matching(arcs[i])){
            matching_arcs.push_back(std::pair<int,int>(g.id(g.u(arcs[i])), g.id(g.v(arcs[i]))));
        }    
    }
    return matching_arcs;
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
    auto output = MaximumWeightFractionalPerfectMatchingRunner(arc_src, arc_targ, arc_costs,  8);


    for(int i = 0; i < output.size(); i++) {
        std::cout << output[i].first << " " << output[i].second << std::endl;
    }

}
