#include <Rcpp.h>
#include <lemon/circulation.h>
#include <lemon/edmonds_karp.h>
#include <lemon/preflow.h>
#include <tuple>
#include <vector>

using namespace lemon;

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List CirculationRunner(std::vector<int> arcSources,
                             std::vector<int> arcTargets,
                             std::vector<int> arcLowerBound,
                             std::vector<int> arcUpperBound,
                             std::vector<int> nodeSupplies, int numNodes) {
  ListDigraph g;

  std::vector<ListDigraph::Node> nodes;

  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }

  ListDigraph::NodeMap<int> supply(g);
  for (int i = 0; i < numNodes; ++i) {
    supply[nodes[i]] = nodeSupplies[i];
  }

  std::vector<ListDigraph::Arc> arcs;
  int NUM_ARCS = arcSources.size();

  ListDigraph::ArcMap<int> upper(g);
  ListDigraph::ArcMap<int> lower(g);

  for (int i = 0; i < NUM_ARCS; ++i) {
    ListDigraph::Arc a =
        g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    upper[a] = arcUpperBound[i];
    lower[a] = arcLowerBound[i];
    arcs.push_back(a);
  }

  Circulation<ListDigraph> runner(g, lower, upper, supply);
  runner.run();

  std::vector<int> arcFlows;
  std::vector<int> barrierNodes;
  for (int i = 0; i < NUM_ARCS; ++i) {
    arcFlows.push_back(runner.flow(arcs[i]));
  }

  for (int i = 0; i < numNodes; ++i) {
    if (runner.barrier(nodes[i])) {
      barrierNodes.push_back(i + 1);
    }
  }
  return Rcpp::List::create(arcFlows, barrierNodes);
}

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List PreflowRunner(std::vector<int> arcSources,
                         std::vector<int> arcTargets,
                         std::vector<int> arcDistances, int sourceNode,
                         int destinationNode, int numNodes) {
  ListDigraph g;

  std::vector<ListDigraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }

  std::vector<ListDigraph::Arc> arcs;
  int NUM_ARCS = arcSources.size();

  ListDigraph::ArcMap<int> dists(g);

  for (int i = 0; i < NUM_ARCS; ++i) {
    ListDigraph::Arc a =
        g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    dists[a] = arcDistances[i];

    arcs.push_back(a);
  }

  Preflow<ListDigraph> runner(g, dists, nodes[sourceNode - 1],
                              nodes[destinationNode - 1]);
  runner.run();

  int outVal = runner.flowValue();
  std::vector<int> arcFlows;
  std::vector<int> nodeCuts;
  for (int i = 0; i < NUM_ARCS; ++i) {
    arcFlows.push_back(runner.flow(arcs[i]));
  }

  for (int i = 0; i < numNodes; ++i) {
    nodeCuts.push_back(runner.minCut(nodes[i]));
  }
  return Rcpp::List::create(arcFlows, nodeCuts, outVal);
}

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List EdmondsKarpRunner(std::vector<int> arcSources,
                             std::vector<int> arcTargets,
                             std::vector<int> arcDistances, int sourceNode,
                             int destinationNode, int numNodes) {
  ListDigraph g;

  std::vector<ListDigraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }

  std::vector<ListDigraph::Arc> arcs;
  int NUM_ARCS = arcSources.size();

  ListDigraph::ArcMap<int> dists(g);

  for (int i = 0; i < NUM_ARCS; ++i) {
    ListDigraph::Arc a =
        g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    dists[a] = arcDistances[i];

    arcs.push_back(a);
  }

  EdmondsKarp<ListDigraph> runner(g, dists, nodes[sourceNode - 1],
                                  nodes[destinationNode - 1]);
  runner.run();

  int outVal = runner.flowValue();
  std::vector<int> arcFlows;
  std::vector<int> nodeCuts;
  for (int i = 0; i < NUM_ARCS; ++i) {
    arcFlows.push_back(runner.flow(arcs[i]));
  }

  for (int i = 0; i < numNodes; ++i) {
    nodeCuts.push_back(runner.minCut(nodes[i]));
  }
  return Rcpp::List::create(arcFlows, nodeCuts, outVal);
}
