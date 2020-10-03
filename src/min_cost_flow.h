#include <std::vector>

#include <lemon/cost_scaling.h>
using namespace std;

using namespace lemon;


/*
std::vector<int> minFlow(std::vector<int> node_supplies, std::vector<int> arc_src, std::vector<int> arc_targ, std::vector<int> arc_costs, std::vector<int> arc_capacities)
{
    std::vector<Flow> outflow;
    
    if(node_supplies.size() >= 50000) outflow = costScaling(node_supplies, arc_src, arc_targ, arc_costs, arc_capacities);
    else outflow = networkSimplex(node_supplies, arc_src, arc_targ, arc_costs, arc_capacities);

    return outflow;
}
*/

auto CapacityScalingRunner(std::vector<int> arcSources, std::vector<int> arcTargets, std::vector<int> arcDistances, std::vector<int> arcSupplies, int numNodes) {
    ListDigraph g;
    std::vector<ListDigraph::Node> nodes;
    for(int i = 0; i < numNodes; ++i) {
        ListDigraph::Node n = g.addNode();
        nodes.push_back(n);
    }
    
    std::vector<ListDigraph::Arc> arcs;
    int NUM_ARCS = arcSources.size();

    ListDigraph::ArcMap<int> dists(g);
    ListDigraph::ArcMap<int> supplies(g);
    for(int i = 0; i < NUM_ARCS; ++i) {
        ListDigraph::Arc a = g.addArc(nodes[arcSources[i]], nodes[arcTargets[i]]);
        dists[a] = arcDistances[i];
        supplies[a] = arcSupplies[i];
        arcs.push_back(a);
    }


    CostScaling<ListDigraph, int, int> runner(g);
    runner.costMap(dists);
    runner.supplyMap(dists);
    runner.run();
    return runner.totalCost();
}