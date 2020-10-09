<<<<<<< HEAD
#include <vector>
#include <tuple>
#include <lemon/network_simplex.h>
=======
#include <std::vector>

>>>>>>> 9a5bc8998c3930efb165de38253b0ce55fe73942
#include <lemon/cost_scaling.h>
#include <lemon/capacity_scaling.h>
#include <lemon/cycle_canceling.h>
#include "lemon/list_graph.h"

using namespace std;

using namespace lemon;

auto CycleCancellingRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcDistances, vector<int> nodeSupplies, int numNodes) {
    ListDigraph g;
    vector<ListDigraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i) {
        ListDigraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    
    vector<ListDigraph::Arc> arcs;
    int NUM_ARCS = arcSources.size();

    ListDigraph::ArcMap<int> dists(g);
    ListDigraph::NodeMap<int> supplies(g);

    for(int i = 0; i < numNodes; ++i) {
        supplies[nodes[i]] = nodeSupplies[i];
    }

    for(int i = 0; i < NUM_ARCS; ++i) {
        ListDigraph::Arc a = g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
        dists[a] = arcDistances[i];

        arcs.push_back(a);
    }


    CycleCanceling<ListDigraph, int, int> runner(g);
    runner.costMap(dists);
    runner.supplyMap(supplies);
    runner.run();

    std::vector<int> arcFlows;
    std::vector<int> nodePots;

    for(int i = 0; i < arcs.size(); ++i) {
        arcFlows.push_back(runner.flow(arcs[i]));
    }

    for(int i = 0; i < numNodes; ++i) {
        nodePots.push_back(runner.potential(nodes[i]));
    }


    return std::make_tuple(arcFlows, nodePots, runner.totalCost());
}


auto CapacityScalingRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcDistances, vector<int> nodeSupplies, int numNodes) {
    ListDigraph g;
    vector<ListDigraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i) {
        ListDigraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    
    vector<ListDigraph::Arc> arcs;
    int NUM_ARCS = arcSources.size();

    ListDigraph::ArcMap<int> dists(g);
    ListDigraph::NodeMap<int> supplies(g);

    for(int i = 0; i < numNodes; ++i) {
        supplies[nodes[i]] = nodeSupplies[i];
    }

    for(int i = 0; i < NUM_ARCS; ++i) {
        ListDigraph::Arc a = g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
        dists[a] = arcDistances[i];

        arcs.push_back(a);
    }


    CapacityScaling<ListDigraph, int, int> runner(g);
    runner.costMap(dists);
    runner.supplyMap(supplies);
    runner.run();

    std::vector<int> arcFlows;
    std::vector<int> nodePots;

    for(int i = 0; i < arcs.size(); ++i) {
        arcFlows.push_back(runner.flow(arcs[i]));
    }

    for(int i = 0; i < numNodes; ++i) {
        nodePots.push_back(runner.potential(nodes[i]));
    }


    return std::make_tuple(arcFlows, nodePots, runner.totalCost());
}

<<<<<<< HEAD
auto CostScalingRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcDistances, vector<int> nodeSupplies, int numNodes) {
=======
auto CapacityScalingRunner(std::vector<int> arcSources, std::vector<int> arcTargets, std::vector<int> arcDistances, std::vector<int> arcSupplies, int numNodes) {
>>>>>>> 9a5bc8998c3930efb165de38253b0ce55fe73942
    ListDigraph g;
    std::vector<ListDigraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i) {
        ListDigraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    
    std::vector<ListDigraph::Arc> arcs;
    int NUM_ARCS = arcSources.size();

    ListDigraph::ArcMap<int> dists(g);
    ListDigraph::NodeMap<int> supplies(g);

    for(int i = 0; i < numNodes; ++i) {
        supplies[nodes[i]] = nodeSupplies[i];
    }

    for(int i = 0; i < NUM_ARCS; ++i) {
        ListDigraph::Arc a = g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
        dists[a] = arcDistances[i];

        arcs.push_back(a);
    }


    CostScaling<ListDigraph, int, int> runner(g);
    runner.costMap(dists);
    runner.supplyMap(supplies);
    runner.run();

    std::vector<int> arcFlows;
    std::vector<int> nodePots;

    for(int i = 0; i < arcs.size(); ++i) {
        arcFlows.push_back(runner.flow(arcs[i]));
    }

    for(int i = 0; i < numNodes; ++i) {
        nodePots.push_back(runner.potential(nodes[i]));
    }


    return std::make_tuple(arcFlows, nodePots, runner.totalCost());
}

auto NetworkSimplexRunner(vector<int> arcSources, vector<int> arcTargets, vector<int> arcDistances, vector<int> nodeSupplies, int numNodes) {
    ListDigraph g;
    vector<ListDigraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i) {
        ListDigraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    
    vector<ListDigraph::Arc> arcs;
    int NUM_ARCS = arcSources.size();

    ListDigraph::ArcMap<int> dists(g);
    ListDigraph::NodeMap<int> supplies(g);

    for(int i = 0; i < numNodes; ++i) {
        supplies[nodes[i]] = nodeSupplies[i];
    }

    for(int i = 0; i < NUM_ARCS; ++i) {
        ListDigraph::Arc a = g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
        dists[a] = arcDistances[i];

        arcs.push_back(a);
    }


    NetworkSimplex<ListDigraph, int, int> runner(g);
    runner.costMap(dists);
    runner.supplyMap(supplies);
    runner.run();

    std::vector<int> arcFlows;
    std::vector<int> nodePots;

    for(int i = 0; i < arcs.size(); ++i) {
        arcFlows.push_back(runner.flow(arcs[i]));
    }

    for(int i = 0; i < numNodes; ++i) {
        nodePots.push_back(runner.potential(nodes[i]));
    }


    return std::make_tuple(arcFlows, nodePots, runner.totalCost());
}