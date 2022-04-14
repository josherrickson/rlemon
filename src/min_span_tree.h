#include <Rcpp.h>
#include <lemon/kruskal.h>
#include <lemon/list_graph.h>
#include <lemon/min_cost_arborescence.h>
#include <vector>

using namespace lemon;

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List KruskalRunner(std::vector<int> arcSources,
                         std::vector<int> arcTargets,
                         std::vector<int> arcDistances, int numNodes) {
  ListDigraph g;

  std::vector<ListDigraph::Node> nodes;

  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  ListDigraph::ArcMap<int> dists(g);
  std::vector<ListDigraph::Arc> tree;
  std::vector<ListDigraph::Arc> arcs;

  for (int i = 0; i < NUM_ARCS; ++i) {
    ListDigraph::Arc a =
        g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    arcs.push_back(a);
    dists[a] = arcDistances[i];
  }
  int treeVal = kruskal(g, dists, std::back_inserter(tree));
  std::vector<int> treeSources;
  std::vector<int> treeTargets;
  for (size_t i = 0; i < tree.size(); i++) {
    treeSources.push_back(g.id(g.source(tree[i])) + 1);
    treeTargets.push_back(g.id(g.target(tree[i])) + 1);
  }
  return Rcpp::List::create(treeSources, treeTargets, treeVal);
}

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List MinCostArborescenceRunner(std::vector<int> arcSources,
                                     std::vector<int> arcTargets,
                                     std::vector<int> arcDistances,
                                     int sourceNode, int numNodes) {
  ListDigraph g;

  std::vector<ListDigraph::Node> nodes;

  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }
  int NUM_ARCS = arcSources.size();
  ListDigraph::ArcMap<int> dists(g);
  std::vector<ListDigraph::Arc> tree;
  std::vector<ListDigraph::Arc> arcs;

  for (int i = 0; i < NUM_ARCS; ++i) {
    ListDigraph::Arc a =
        g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    arcs.push_back(a);
    dists[a] = arcDistances[i];
  }
  ListDigraph::ArcMap<int> arbs(g);
  int arbVal = minCostArborescence(g, dists, nodes[sourceNode - 1], arbs);
  std::vector<int> treeSources;
  std::vector<int> treeTargets;
  for (int i = 0; i < NUM_ARCS; i++) {
    if (arbs[arcs[i]]) {
      treeSources.push_back(g.id(g.source(arcs[i])) + 1);
      treeTargets.push_back(g.id(g.target(arcs[i])) + 1);
    }
  }
  return Rcpp::List::create(treeSources, treeTargets, arbVal);
}
