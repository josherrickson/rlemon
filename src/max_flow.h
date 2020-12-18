#include <vector>
#include <tuple>
#include <lemon/preflow.h>
#include <lemon/edmonds_karp.h>
#include <lemon/circulation.h>
#include <Rcpp.h>

using namespace lemon;

//' Maximum  Flow Algorithms - Network Circulation
//' @name Maximum Flow Algorithms 2
//' @param arcSources, a vector corresponding to the source nodes of a graph's edges
//' @param arcTargets, a vector corresponding to the destination nodes of a graph's edges
//' @param arcLowerBound, a vector corresponding to the lower-bound capacities of nodes of a graph's edges
//' @param arcUpperBound, a vector corresponding to the upper-bound capacities of nodes of a graph's edges
//' @param nodeSupplies, a vector corresponding to the supplies of each node of the graph.
//' @param numNodes, the number of nodes in the graph
//' @return A list containing three entries: 1) A list corresponding to the flows of arcs in the graph, 2) A list of the graph's barrier nodes, and 3) the total cost of the flows in the graph, i.e. the maxflow value
//> NULL


//' Maximum  Flow Algorithms
//' @name Maximum Flow Algorithms
//' @param arcSources, a vector corresponding to the source nodes of a graph's edges
//' @param arcTargets, a vector corresponding to the destination nodes of a graph's edges
//' @param arcDistances, a vector corresponding to the capacities of nodes of a graph's edges
//' @param sourceNode, the source node 
//' @param destinationNode, the destination node
//' @param numNodes, the number of nodes in the graph
//' @return A list containing three entries: 1) A list corresponding to the flows of arcs in the graph, and 2) A list of cut-values of the graph's nodes.
//> NULL


//' @rdname Maximum-Flow-Algorithms-2
//' @description `PreflowRunner` runs the Preflow Algorithm to calculate the maximum flow.
//' @export
// [[Rcpp::export]]
Rcpp::List CirculationRunner(std::vector<int> arcSources, std::vector<int> arcTargets, std::vector<int> arcLowerBound, std::vector<int> arcUpperBound, std::vector<int> nodeSupplies, int numNodes) {
    ListDigraph g;

    std::vector<ListDigraph::Node> nodes;


    for(int i = 0; i < numNodes; ++i) {
        ListDigraph::Node n = g.addNode();
        nodes.push_back(n);
    }

    ListDigraph::NodeMap<int> supply(g);
    for(int i = 0; i < numNodes; ++i) {
        supply[nodes[i]] = nodeSupplies[i];
    }

    std::vector<ListDigraph::Arc> arcs;
    int NUM_ARCS = arcSources.size();

    ListDigraph::ArcMap<int> upper(g);
    ListDigraph::ArcMap<int> lower(g);

    for(int i = 0; i < NUM_ARCS; ++i) {
        ListDigraph::Arc a = g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
        upper[a] = arcUpperBound[i];
        lower[a] = arcLowerBound[i];
        arcs.push_back(a);
    }


    Circulation<ListDigraph> runner(g,lower,upper,supply);
    runner.run();

    std::vector<int> arcFlows;
    std::vector<int> barrierNodes;
    for(int i = 0; i < NUM_ARCS; ++i) {
        arcFlows.push_back(runner.flow(arcs[i]));
    }

    for(int i = 0; i < numNodes; ++i) {
        if(runner.barrier(nodes[i])){
            barrierNodes.push_back(i);
        }
    }
    return Rcpp::List::create(arcFlows, barrierNodes);
}



//' @rdname Maximum-Flow-Algorithms
//' @description `PreflowRunner` runs the Preflow Algorithm to calculate the maximum flow.
// [[Rcpp::export]]
Rcpp::List PreflowRunner(std::vector<int> arcSources, std::vector<int> arcTargets, std::vector<int> arcDistances, int sourceNode, int destinationNode, int numNodes) {
    ListDigraph g;

    std::vector<ListDigraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i) {
        ListDigraph::Node n = g.addNode();
        nodes.push_back(n);
    }

    std::vector<ListDigraph::Arc> arcs;
    int NUM_ARCS = arcSources.size();

    ListDigraph::ArcMap<int> dists(g);

    for(int i = 0; i < NUM_ARCS; ++i) {
        ListDigraph::Arc a = g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
        dists[a] = arcDistances[i];

        arcs.push_back(a);
    }


    Preflow<ListDigraph> runner(g,dists,nodes[sourceNode],nodes[destinationNode]);
    runner.run();

    int outVal = runner.flowValue();
    std::vector<int> arcFlows;
    std::vector<int> nodeCuts;
    for(int i = 0; i < NUM_ARCS; ++i) {
        arcFlows.push_back(runner.flow(arcs[i]));
    }

    for(int i = 0; i < numNodes; ++i) {
        nodeCuts.push_back(runner.minCut(nodes[i]));
    }
    return Rcpp::List::create(arcFlows, nodeCuts, outVal);
}



//' @rdname Maximum-Flow-Algorithms
//' @description `EdmondsKarpRunner` runs the EdmondsKarp Algorithm to calculate the maximum flow.
// [[Rcpp::export]]
Rcpp::List EdmondsKarpRunner(std::vector<int> arcSources, std::vector<int> arcTargets, std::vector<int> arcDistances, int sourceNode, int destinationNode, int numNodes) {
    ListDigraph g;

    std::vector<ListDigraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i) {
        ListDigraph::Node n = g.addNode();
        nodes.push_back(n);
    }

    std::vector<ListDigraph::Arc> arcs;
    int NUM_ARCS = arcSources.size();

    ListDigraph::ArcMap<int> dists(g);

    for(int i = 0; i < NUM_ARCS; ++i) {
        ListDigraph::Arc a = g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
        dists[a] = arcDistances[i];

        arcs.push_back(a);
    }


    EdmondsKarp<ListDigraph> runner(g,dists,nodes[sourceNode],nodes[destinationNode]);
    runner.run();

    int outVal = runner.flowValue();
    std::vector<int> arcFlows;
    std::vector<int> nodeCuts;
    for(int i = 0; i < NUM_ARCS; ++i) {
        arcFlows.push_back(runner.flow(arcs[i]));
    }

    for(int i = 0; i < numNodes; ++i) {
        nodeCuts.push_back(runner.minCut(nodes[i]));
    }
    return Rcpp::List::create(arcFlows, nodeCuts, outVal);
}