#include <Rcpp.h>
#include <iostream>
#include <lemon/grosso_locatelli_pullan_mc.h>
#include <lemon/list_graph.h>
#include <vector>

using namespace lemon;
using namespace std;

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List GrossoLocatelliPullanMcRunner(std::vector<int> arcSources,
                                         std::vector<int> arcTargets,
                                         int numNodes) {
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }

  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
  }

  GrossoLocatelliPullanMc<ListGraph> runner(g);
  runner.run();

  int cliqueSize = runner.cliqueSize();
  ListGraph::NodeMap<int> clique_members(g);
  runner.cliqueMap(clique_members);
  std::vector<int> cliqueMembers;
  for (int i = 0; i < numNodes; i++) {
    if (clique_members[nodes[i]]) {
      cliqueMembers.push_back(i + 1);
    }
  }

  return Rcpp::List::create(cliqueSize, cliqueMembers);
}
