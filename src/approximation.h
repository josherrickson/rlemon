#include <vector>
#include <iostream>

using namespace lemon;
using namespace std;
#include <Rcpp.h>
#include <lemon/grosso_locatelli_pullan_mc.h>

//' @export
// [[Rcpp::export]]
Rcpp::List GrossoLocatelliPullanMcRunner(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for(int i = 0; i < numNodes; ++i){
      ListGraph::Node n = g.addNode();
      nodes.push_back(n);
  }


  int NUM_ARCS = arcSources.size();

  for(int i = 0; i < NUM_ARCS; ++i) {
      ListGraph::Edge a = g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
  }

  GrossoLocatelliPullanMc<ListGraph> runner(g);
  runner.run();

  int cliqueSize = runner.cliqueSize();
  ListGraph::NodeMap<int> clique_members(g);
  runner.cliqueMap(clique_members);
  std::vector<int> cliqueMembers;
  for(int i = 0; i < numNodes; i++) {
      if(clique_members[nodes[i]]){
          cliqueMembers.push_back(i);
      }
  }

  return Rcpp::List::create(cliqueSize, cliqueMembers);
}
