#include <Rcpp.h>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace lemon;
using namespace std;

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List GraphCompatabilityConverter(std::vector<int> nodesList,
                                       std::vector<int> arcSources,
                                       std::vector<int> arcTargets) {

  std::vector<int> allNodes;
  allNodes.insert(allNodes.end(), nodesList.begin(), nodesList.end());
  allNodes.insert(allNodes.end(), arcSources.begin(), arcSources.end());
  allNodes.insert(allNodes.end(), arcTargets.begin(), arcTargets.end());

  std::sort(allNodes.begin(), allNodes.end());
  vector<int>::iterator it;
  it = std::unique(allNodes.begin(), allNodes.end());
  allNodes.resize(distance(allNodes.begin(), it));

  std::unordered_map<int, int> nodeMap;
  std::vector<int> ret_nodesList;
  std::vector<std::string> ret_nodeMapping;
  for (size_t i = 0; i < allNodes.size(); ++i) {
    nodeMap[allNodes[i]] = i;
    ret_nodesList.push_back(i);
    ret_nodeMapping.push_back(std::to_string(allNodes[i]) + " -> " +
                              std::to_string(i));
  }

  std::vector<int> ret_arcSources;
  std::vector<int> ret_arcTargets;
  for (size_t i = 0; i < arcSources.size(); ++i) {
    ret_arcSources.push_back(nodeMap[arcSources[i]]);
    ret_arcTargets.push_back(nodeMap[arcTargets[i]]);
  }

  return Rcpp::List::create(ret_nodesList, ret_arcSources, ret_arcTargets,
                            ret_nodeMapping);
}
