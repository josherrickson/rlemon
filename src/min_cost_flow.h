#include <vector>
#include <tuple>
#include <lemon/network_simplex.h>
#include <lemon/cost_scaling.h>
#include <lemon/capacity_scaling.h>
#include <lemon/cycle_canceling.h>
#include "lemon/list_graph.h"
#include <Rcpp.h>

using namespace lemon;

// [[Rcpp::export]]
Rcpp::List CycleCancellingRunner(std::vector<int> arcSources, std::vector<int> arcTargets, std::vector<int> arcDistances, std::vector<int> nodeSupplies, int numNodes) {
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


    return Rcpp::List::create(arcFlows, nodePots, runner.totalCost());
}

// [[Rcpp::export]]
Rcpp::List CapacityScalingRunner(std::vector<int> arcSources, std::vector<int> arcTargets, std::vector<int> arcDistances, std::vector<int> nodeSupplies, int numNodes) {
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


    return Rcpp::List::create(arcFlows, nodePots, runner.totalCost());
}

// [[Rcpp::export]]
Rcpp::List CostScalingRunner(std::vector<int> arcSources, std::vector<int> arcTargets, std::vector<int> arcDistances, std::vector<int> nodeSupplies, int numNodes) {
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


    return Rcpp::List::create(arcFlows, nodePots, runner.totalCost());
}


// [[Rcpp::export]]
Rcpp::List NetworkSimplexRunner(std::vector<int> arcSources, std::vector<int> arcTargets, std::vector<int> arcDistances, std::vector<int> nodeSupplies, int numNodes) {
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


    return Rcpp::List::create(arcFlows, nodePots, runner.totalCost());
}
