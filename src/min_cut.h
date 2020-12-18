#include <vector>
#include <iostream>
#include "lemon/gomory_hu.h"
#include "lemon/nagamochi_ibaraki.h"
#include "lemon/hao_orlin.h"
#include "lemon/list_graph.h"
#include <Rcpp.h>

using namespace lemon;
using namespace std;

//' Minimum Cut Algorithms - Gomory Hu Tree
//' @name Minimum Cut Algorithms 2 
//' @param arcSources, a vector corresponding to the source nodes of a graph's edges
//' @param arcTargets, a vector corresponding to the destination nodes of a graph's edges
//' @param arcWeights, a vector corresponding to the weights of a graph's edges
//' @param numNodes, the number of nodes in the graph
//' @return Calculates a Gomory-Hu Tree and returns a list containing three entries: 1) A list of predecessor nodes of each node in the graph, and 2) A list of weights of the predecessor edge of each node, and 3) A list of distances from the root node to each node.
//> NULL


//' Minimum Cut Algorithms
//' @name Minimum Cut Algorithms
//' @param arcSources, a vector corresponding to the source nodes of a graph's edges
//' @param arcTargets, a vector corresponding to the destination nodes of a graph's edges
//' @param arcWeights, a vector corresponding to the weights of a graph's edges
//' @param numNodes, the number of nodes in the graph
//' @return A list containing three entries: 1) The value of the minimum cut in the graph, and 2) A list of nodes in the first partition, and 3) A list of nodes in the second partition.
//> NULL


//' @rdname Minimum-Cut-Algorithms
//' @description `NagamochiIbarakiRunner` runs the Nagamochi-Ibaraki Algorithm to calculate the minimum cut.
//' @export
// [[Rcpp::export]]
Rcpp::List NagamochiIbarakiRunner(std::vector<int> arcSources, std::vector<int> arcTargets, std::vector<int> arcWeights, int numNodes)
{
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
    NagamochiIbaraki<ListGraph, ListGraph::EdgeMap<int>> alg(g, dists);
    alg.run();   
    
    ListGraph::NodeMap<int> mincutmap(g);
    alg.minCutMap(mincutmap);

    int mincutvalue = alg.minCutValue();
    cout << mincutvalue << endl;
    vector<int> partition1;
    vector<int> partition2;
    for(int i = 0; i < numNodes; ++i)
    {
        if(mincutmap[nodes[i]])
        {
            partition1.push_back(i);
        }
        else
        {
            partition2.push_back(i);
        }
    }

    return Rcpp::List::create(mincutvalue, partition1, partition2);
}

//' @rdname Minimum-Cut-Algorithms
//' @description `HaoOrlinRunner` runs the Hao-Orlin Algorithm to calculate the minimum cut.
//' @export
// [[Rcpp::export]]
Rcpp::List HaoOrlinRunner(std::vector<int> arcSources, std::vector<int> arcTargets, std::vector<int> arcWeights, int numNodes)
{
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
    HaoOrlin<ListGraph, ListGraph::EdgeMap<int>> alg(g, dists);
    alg.run();   
    
    ListGraph::NodeMap<int> mincutmap(g);
    alg.minCutMap(mincutmap);

    int mincutvalue = alg.minCutValue();
    cout << mincutvalue << endl;
    vector<int> partition1;
    vector<int> partition2;
    for(int i = 0; i < numNodes; ++i)
    {
        if(mincutmap[nodes[i]])
        {
            partition1.push_back(i);
        }
        else
        {
            partition2.push_back(i);
        }
    }

    return Rcpp::List::create(mincutvalue, partition1, partition2);
}

//' @rdname Minimum-Cut-Algorithms-2
//' @description `GomoryHuTreeRunner` runs the Gomory-Hu Algorithm to calculate a rooted Gomory Hu Tree.
//' @export
// [[Rcpp::export]]
Rcpp::List GomoryHuTreeRunner(std::vector<int> arcSources, std::vector<int> arcTargets, std::vector<int> arcWeights, int numNodes) {
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

    return Rcpp::List::create(predecessors, predEdgeWeights, rootDistances);
}
