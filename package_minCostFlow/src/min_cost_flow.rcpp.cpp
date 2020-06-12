#include <Rcpp.h>
#include <vector>

#include "lemon_minFlowAlgs/min_cost_flow_NS.rcpp.h"
#include "lemon_minFlowAlgs/min_cost_flow_CS.rcpp.h"

using namespace Rcpp;

// [[Rcpp::export]]
std::vector<int> minFlow(std::vector<int> node_supplies, std::vector<int> arc_src, std::vector<int> arc_targ, std::vector<int> arc_costs, std::vector<int> arc_capacities)
{
    std::vector<Flow> outflow;
    
    if(node_supplies.size() >= 50000) outflow = costScaling(node_supplies, arc_src, arc_targ, arc_costs, arc_capacities);
    else outflow = networkSimplex(node_supplies, arc_src, arc_targ, arc_costs, arc_capacities);

    return outflow;
}
