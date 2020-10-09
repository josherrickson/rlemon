#include <std::vector>
#include <iostream>
#include <std::tuple>

using namespace lemon;
using namespace std;

#include <lemon/grosso_locatelli_pullan_mc.h>

auto GrossoLocatelliPullanMcRunner(std::vector<int> arcSources, std::vector<int> arcTargets, int numNodes) {
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  for(int i = 0; i < numNodes; ++i){
      ListGraph::Node n = g.addNode();
      nodes.push_back(n);
  }


  int NUM_ARCS = arcSources.size();

  for(int i = 0; i < NUM_ARCS; ++i) {
      Arc a = g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
  }

  GrossoLocatelliPullanMc runner(g);
  runner.run();

  int cliqueSize = runner.cliqueSize();
  ListGraph::NodeMap<int> clique_members;
  runner.cliqueMap(clique_members);
  std::vector<int> cliqueMembers;
  for(int i = 0; i < numNodes; i++) {
      if(clique_members[nodes[i]]){
          cliqueMembers.push_back(i);
      }
  }

  return std::make_tuple(cliqueSize, cliqueMembers);
}