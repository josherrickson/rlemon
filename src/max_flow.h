#include <Rcpp.h>
#include <lemon/circulation.h>
#include <lemon/edmonds_karp.h>
#include <lemon/preflow.h>
#include <tuple>
#include <vector>

using namespace lemon;

//' Maximum Flow Algorithms - Network Circulation
//' @name Maximum-Flow-Algorithms-2
//' @param arcSources Vector corresponding to the source nodes of a graph's edges
//' @param arcTargets Vector corresponding to the destination nodes of a graph's edges
//' @param arcLowerBound Vector corresponding to the lower-bound capacities of nodes of a graph's edges
//' @param arcUpperBound Vector corresponding to the upper-bound capacities of nodes of a graph's edges
//' @param nodeSupplies Vector corresponding to the supplies of each node of the graph.
//' @param numNodes The number of nodes in the graph
//' @return A list containing two entries: 1) A list corresponding to the flows of arcs in the graph, and 2) A list of the graph's barrier nodes.
//> NULL

//' Maximum Flow Algorithms
//' @name Maximum-Flow-Algorithms-1
//' @param arcSources Vector corresponding to the source nodes of a graph's edges
//' @param arcTargets Vector corresponding to the destination nodes of a graph's edges
//' @param arcDistances Vector corresponding to the capacities of nodes of a graph's edges
//' @param sourceNode The source node
//' @param destinationNode The destination node
//' @param numNodes The number of nodes in the graph
//' @return A list containing three entries: 1) A list corresponding to the flows of arcs in the graph, 2) A list of cut-values of the graph's nodes, and 3) the total cost of the flows in the graph, i.e. the maxflow value.
//> NULL

//' @rdname Maximum-Flow-Algorithms-2
//' @description `CirculationRunner` runs the Circulation Algorithm to calculate the maximum flow.
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

//' @rdname Maximum-Flow-Algorithms-1
//' @description `PreflowRunner` runs the Preflow Algorithm to calculate the maximum flow.
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

//' @rdname Maximum-Flow-Algorithms-1
//' @description `EdmondsKarpRunner` runs the EdmondsKarp Algorithm to calculate the maximum flow.
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
