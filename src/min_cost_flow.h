#include "lemon/list_graph.h"
#include <Rcpp.h>
#include <lemon/capacity_scaling.h>
#include <lemon/cost_scaling.h>
#include <lemon/cycle_canceling.h>
#include <lemon/network_simplex.h>
#include <tuple>
#include <vector>

using namespace lemon;

//' @rdname lemon_runners
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
  CycleCanceling<ListDigraph, int, int>::ProblemType feasibility = runner.run();
  std::string feasibility_type = "";
  if (feasibility ==
      CycleCanceling<ListDigraph, int, int>::ProblemType::INFEASIBLE) {
    feasibility_type = "INFEASIBLE";
  } else if (feasibility ==
             CycleCanceling<ListDigraph, int, int>::ProblemType::OPTIMAL) {
    feasibility_type = "OPTIMAL";
  } else {
    feasibility_type = "UNBOUNDED";
  }
  std::vector<int> arcFlows;
  std::vector<int> nodePots;

  for (size_t i = 0; i < arcs.size(); ++i) {
    arcFlows.push_back(runner.flow(arcs[i]));
  }

  for (int i = 0; i < numNodes; ++i) {
    nodePots.push_back(runner.potential(nodes[i]));
  }

  return Rcpp::List::create(arcFlows, nodePots, runner.totalCost(),
                            feasibility_type);
}

//' @rdname lemon_runners
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
  CapacityScaling<ListDigraph, int, int>::ProblemType feasibility =
      runner.run();
  std::string feasibility_type = "";
  if (feasibility ==
      CapacityScaling<ListDigraph, int, int>::ProblemType::INFEASIBLE) {
    feasibility_type = "INFEASIBLE";
  } else if (feasibility ==
             CapacityScaling<ListDigraph, int, int>::ProblemType::OPTIMAL) {
    feasibility_type = "OPTIMAL";
  } else {
    feasibility_type = "UNBOUNDED";
  }

  std::vector<int> arcFlows;
  std::vector<int> nodePots;

  for (size_t i = 0; i < arcs.size(); ++i) {
    arcFlows.push_back(runner.flow(arcs[i]));
  }

  for (int i = 0; i < numNodes; ++i) {
    nodePots.push_back(runner.potential(nodes[i]));
  }

  return Rcpp::List::create(arcFlows, nodePots, runner.totalCost(),
                            feasibility_type);
}

//' @rdname lemon_runners
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
  CostScaling<ListDigraph, int, int>::ProblemType feasibility = runner.run();
  std::string feasibility_type = "";
  if (feasibility ==
      CostScaling<ListDigraph, int, int>::ProblemType::INFEASIBLE) {
    feasibility_type = "INFEASIBLE";
  } else if (feasibility ==
             CostScaling<ListDigraph, int, int>::ProblemType::OPTIMAL) {
    feasibility_type = "OPTIMAL";
  } else {
    feasibility_type = "UNBOUNDED";
  }

  std::vector<int> arcFlows;
  std::vector<int> nodePots;

  for (size_t i = 0; i < arcs.size(); ++i) {
    arcFlows.push_back(runner.flow(arcs[i]));
  }

  for (int i = 0; i < numNodes; ++i) {
    nodePots.push_back(runner.potential(nodes[i]));
  }

  return Rcpp::List::create(arcFlows, nodePots, runner.totalCost(),
                            feasibility_type);
}

//' @rdname lemon_runners
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
  NetworkSimplex<ListDigraph, int, int>::ProblemType feasibility = runner.run();
  std::string feasibility_type = "";
  if (feasibility ==
      NetworkSimplex<ListDigraph, int, int>::ProblemType::INFEASIBLE) {
    feasibility_type = "INFEASIBLE";
  } else if (feasibility ==
             NetworkSimplex<ListDigraph, int, int>::ProblemType::OPTIMAL) {
    feasibility_type = "OPTIMAL";
  } else {
    feasibility_type = "UNBOUNDED";
  }

  std::vector<int> arcFlows;
  std::vector<int> nodePots;

  for (size_t i = 0; i < arcs.size(); ++i) {
    arcFlows.push_back(runner.flow(arcs[i]));
  }

  for (int i = 0; i < numNodes; ++i) {
    nodePots.push_back(runner.potential(nodes[i]));
  }

  return Rcpp::List::create(arcFlows, nodePots, runner.totalCost(),
                            feasibility_type);
}
