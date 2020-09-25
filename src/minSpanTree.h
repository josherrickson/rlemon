#include <vector>
#include "kruskal.h"
#include "list_graph.h"

using namespace lemon;
using namespace std;

using Cost = int;

using Graph = ListDigraph;
using Node = Graph::Node;
using Arc = Graph::Arc;

template<typename ValueType>
using ArcMap = ListDigraph::ArcMap<ValueType>;


int main()
{
    Graph g;

    vector<Node> nodes;
    for(int i = 0; i < 9; ++i)
    {
        Node n = g.addNode();
        nodes.push_back(n);
    }

    ArcMap<bool> output(g);
    ArcMap<Cost> costs(g);
    vector<Arc> arcs;

    vector<int> arc_src{1, 1, 2, 2, 2, 3, 3, 4, 4,5,5,5,6,6,7};
    vector<int> arc_targ{2, 3, 3, 4, 5, 4, 7, 5, 7,7,8,6,8,9,8};
    vector<int> arc_costs{5, 2, 2, 3, 7, 3, 9, 2, 6,5,7,8,3,4,2};
    int NUM_ARCS = arc_src.size();

    for(int i = 0; i < NUM_ARCS; ++i)
    {
        Arc a = g.addArc(nodes[arc_src[i] - 1], nodes[arc_targ[i] - 1]);
        arcs.push_back(a);
        costs[arcs[i]] = arc_costs[i];
        output[arcs[i]] = false;
    }

    std::vector<Arc> tree;
    cout << "Total Cost: " << kruskal(g,costs,output) << endl;

    for(int i = 0; i < NUM_ARCS; ++i)
    {
        if(output[arcs[i]])
        {
            cout << arc_src[i] << "->" << arc_targ[i] << ": " << arc_costs[i] << endl;
        }
    }

    return 1;
}