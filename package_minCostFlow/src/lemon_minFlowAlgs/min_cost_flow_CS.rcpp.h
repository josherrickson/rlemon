#include <Rcpp.h>
#include <iostream>
#include <fstream>
#include <string>

#include "list_graph.h"
#include "cost_scaling.h"

using namespace Rcpp;
using namespace lemon;
using namespace std;

using Flow = int;
using Supply = int;
using Cost = int;
using Capacity = int;

using Graph = ListDigraph;

using Node = Graph::Node;
using Arc = Graph::Arc;

template<typename ValueType>
using ArcMap = ListDigraph::ArcMap<ValueType>;


template<typename ValueType>
using NodeMap = ListDigraph::NodeMap<ValueType>;

using CS = CostScaling<ListDigraph, Capacity, Cost>;

vector<Flow> costScaling(vector<int> node_supplies, vector<int> arc_src, vector<int> arc_targ, vector<int> arc_costs, vector<int> arc_capacities)
{
    int NUM_NODES = node_supplies.size();
    int NUM_ARCS = arc_src.size();

    Graph g;
    g.reserveNode(NUM_NODES);

    NodeMap<Supply> supplies(g);
    vector<Node> nodes;
    nodes.resize(NUM_NODES);
    for(int i = 0; i < NUM_NODES; ++i)
    {
        Node n = g.addNode();
        nodes[i] = n;
        supplies[nodes[i]] = node_supplies[i];
    }

    ArcMap<Cost> costs(g);
    ArcMap<Capacity> capacities(g);
    ArcMap<Capacity> lower_capacities(g);
    vector<Arc> arcs;
    arcs.resize(NUM_ARCS);
    for(int i = 0; i < NUM_ARCS; ++i)
    {
        Arc a = g.addArc(nodes[arc_src[i] - 1], nodes[arc_targ[i] - 1]);
        arcs[i] = a;
        costs[arcs[i]] = arc_costs[i];
        capacities[arcs[i]] = arc_capacities[i];
        lower_capacities[arcs[i]] = 0;
    }

    CS cs(g);
    cs.costMap(costs).upperMap(capacities).lowerMap(lower_capacities).supplyMap(supplies);

    vector<Flow> output_flow(NUM_ARCS, 0);
    ArcMap<Capacity> flows(g);
    CS::ProblemType status = cs.run();
    
    switch (status) {
    case CS::INFEASIBLE:
        Rcout << "insufficient flow" << endl;
        break;
    case CS::OPTIMAL:
        cs.flowMap(flows);
        for(int i = 0; i < NUM_ARCS; ++i)
        {
            output_flow[i] = flows[arcs[i]];
        }
        Rcout << "Total Cost: " << cs.totalCost() << endl;
        break;
    case CS::UNBOUNDED:
        Rcout << "infinite flow" << endl;
        break;
    default:
        break;
    }
   

    return output_flow;
}

