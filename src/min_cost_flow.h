#include "lemon/list_graph.h"
#include <Rcpp.h>
#include <lemon/capacity_scaling.h>
#include <lemon/cost_scaling.h>
#include <lemon/cycle_canceling.h>
#include <lemon/network_simplex.h>
#include <tuple>
#include <vector>

using namespace lemon;

//' Minimum Cost Flow Algorithms
//' @name Minimum-Cost-Flow-Algorithms
//' @param arcSources, a vector corresponding to the source nodes of a graph's edges
//' @param arcTargets, a vector corresponding to the destination nodes of a graph's edges
//' @param arcCapacities, a vector corresponding to the capacities of nodes of a graph's edges
//' @param arcCosts, a vector corresponding to the capacities of nodes of a graph's edges
//' @param nodeSupplies, a vector corresponding to the supplies of each node
//' @param numNodes, the number of nodes in the graph
//' @return A list containing three entries: 1) A list corresponding to the flows of arcs in the graph, 2) A list of potentials of the graph's nodes, and 3) the total cost of the flows in the graph, i.e. the mincostflow value
//> NULL

//' @rdname Minimum-Cost-Flow-Algorithms
//' @description `CycleCancellingRunner` runs the Cycle-Cancelling Algorithm to calculate the minimum cost flow.
// [[Rcpp::export]]
Rcpp::List CycleCancellingRunner(std::vector<int> arcSources,
                                 std::vector<int> arcTargets,
                                 std::vector<int> arcCapacities,
                                 std::vector<int> arcCosts,
                                 std::vector<int> nodeSupplies, int numNodes) {
  ListDigraph g;
  std::vector<ListDigraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  std::vector<ListDigraph::Arc> arcs;
  int NUM_ARCS = arcSources.size();

  ListDigraph::ArcMap<int> costs(g);
  ListDigraph::ArcMap<int> capacities(g);
  ListDigraph::NodeMap<int> supplies(g);

  for (int i = 0; i < numNodes; ++i) {
    supplies[nodes[i]] = nodeSupplies[i];
  }

  for (int i = 0; i < NUM_ARCS; ++i) {
    ListDigraph::Arc a =
        g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    costs[a] = arcCosts[i];
    capacities[a] = arcCapacities[i];
    arcs.push_back(a);
  }

  CycleCanceling<ListDigraph, int, int> runner(g);
  runner.upperMap(capacities);
  runner.costMap(costs);
  runner.supplyMap(supplies);
  runner.run();

  std::vector<int> arcFlows;
  std::vector<int> nodePots;

  for (size_t i = 0; i < arcs.size(); ++i) {
    arcFlows.push_back(runner.flow(arcs[i]));
  }

  for (int i = 0; i < numNodes; ++i) {
    nodePots.push_back(runner.potential(nodes[i]));
  }

  return Rcpp::List::create(arcFlows, nodePots, runner.totalCost());
}

//' @rdname Minimum-Cost-Flow-Algorithms
//' @description `CapacityScalingRunner` runs the Capacity-Scaling Algorithm to calculate the minimum cost flow.
// [[Rcpp::export]]
Rcpp::List CapacityScalingRunner(std::vector<int> arcSources,
                                 std::vector<int> arcTargets,
                                 std::vector<int> arcCapacities,
                                 std::vector<int> arcCosts,
                                 std::vector<int> nodeSupplies, int numNodes) {
  ListDigraph g;
  std::vector<ListDigraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  std::vector<ListDigraph::Arc> arcs;
  int NUM_ARCS = arcSources.size();

  ListDigraph::ArcMap<int> costs(g);
  ListDigraph::ArcMap<int> capacities(g);
  ListDigraph::NodeMap<int> supplies(g);

  for (int i = 0; i < numNodes; ++i) {
    supplies[nodes[i]] = nodeSupplies[i];
  }

  for (int i = 0; i < NUM_ARCS; ++i) {
    ListDigraph::Arc a =
        g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    costs[a] = arcCosts[i];
    capacities[a] = arcCapacities[i];
    arcs.push_back(a);
  }

  CapacityScaling<ListDigraph, int, int> runner(g);
  runner.upperMap(capacities);
  runner.costMap(costs);
  runner.supplyMap(supplies);
  runner.run();

  std::vector<int> arcFlows;
  std::vector<int> nodePots;

  for (size_t i = 0; i < arcs.size(); ++i) {
    arcFlows.push_back(runner.flow(arcs[i]));
  }

  for (int i = 0; i < numNodes; ++i) {
    nodePots.push_back(runner.potential(nodes[i]));
  }

  return Rcpp::List::create(arcFlows, nodePots, runner.totalCost());
}

//' @rdname Minimum-Cost-Flow-Algorithms
//' @description `CostScalingRunner` runs the Cost-Scaling Algorithm to calculate the minimum cost flow.
// [[Rcpp::export]]
Rcpp::List CostScalingRunner(std::vector<int> arcSources,
                             std::vector<int> arcTargets,
                             std::vector<int> arcCapacities,
                             std::vector<int> arcCosts,
                             std::vector<int> nodeSupplies, int numNodes) {
  ListDigraph g;
  std::vector<ListDigraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  std::vector<ListDigraph::Arc> arcs;
  int NUM_ARCS = arcSources.size();

  ListDigraph::ArcMap<int> costs(g);
  ListDigraph::ArcMap<int> capacities(g);
  ListDigraph::NodeMap<int> supplies(g);

  for (int i = 0; i < numNodes; ++i) {
    supplies[nodes[i]] = nodeSupplies[i];
  }

  for (int i = 0; i < NUM_ARCS; ++i) {
    ListDigraph::Arc a =
        g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    costs[a] = arcCosts[i];
    capacities[a] = arcCapacities[i];
    arcs.push_back(a);
  }

  CostScaling<ListDigraph, int, int> runner(g);
  runner.upperMap(capacities);
  runner.costMap(costs);
  runner.supplyMap(supplies);
  runner.run();

  std::vector<int> arcFlows;
  std::vector<int> nodePots;

  for (size_t i = 0; i < arcs.size(); ++i) {
    arcFlows.push_back(runner.flow(arcs[i]));
  }

  for (int i = 0; i < numNodes; ++i) {
    nodePots.push_back(runner.potential(nodes[i]));
  }

  return Rcpp::List::create(arcFlows, nodePots, runner.totalCost());
}

//' @rdname Minimum-Cost-Flow-Algorithms
//' @description `NetworkSimplexRunner` runs the Network-Simplex Algorithm to calculate the minimum cost flow.
// [[Rcpp::export]]
Rcpp::List NetworkSimplexRunner(std::vector<int> arcSources,
                                std::vector<int> arcTargets,
                                std::vector<int> arcCapacities,
                                std::vector<int> arcCosts,
                                std::vector<int> nodeSupplies, int numNodes) {
  ListDigraph g;
  std::vector<ListDigraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  std::vector<ListDigraph::Arc> arcs;
  int NUM_ARCS = arcSources.size();

  ListDigraph::ArcMap<int> costs(g);
  ListDigraph::ArcMap<int> capacities(g);
  ListDigraph::NodeMap<int> supplies(g);

  for (int i = 0; i < numNodes; ++i) {
    supplies[nodes[i]] = nodeSupplies[i];
  }

  for (int i = 0; i < NUM_ARCS; ++i) {
    ListDigraph::Arc a =
        g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    costs[a] = arcCosts[i];
    capacities[a] = arcCapacities[i];
    arcs.push_back(a);
  }

  NetworkSimplex<ListDigraph, int, int> runner(g);
  runner.upperMap(capacities);
  runner.costMap(costs);
  runner.supplyMap(supplies);
  runner.run();

  std::vector<int> arcFlows;
  std::vector<int> nodePots;

  for (size_t i = 0; i < arcs.size(); ++i) {
    arcFlows.push_back(runner.flow(arcs[i]));
  }

  for (int i = 0; i < numNodes; ++i) {
    nodePots.push_back(runner.potential(nodes[i]));
  }

  return Rcpp::List::create(arcFlows, nodePots, runner.totalCost());
}
