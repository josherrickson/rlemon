#include <Rcpp.h>

#include "lemon_minFlowAlgs/min_cost_flow_NS.rcpp.h"
#include "lemon_minFlowAlgs/min_cost_flow_CS.rcpp.h"

using namespace Rcpp;
using namespace std;

// [[Rcpp::export]]
vector<Flow> minFlow(vector<int> node_supplies, vector<int> arc_src, vector<int> arc_targ, vector<int> arc_costs, vector<int> arc_capacities)
{
    vector<Flow> outflow;
    
    if(node_supplies.size() >= 50000) outflow = costScaling(node_supplies, arc_src, arc_targ, arc_costs, arc_capacities);
    else outflow = networkSimplex(node_supplies, arc_src, arc_targ, arc_costs, arc_capacities);

    return outflow;
}