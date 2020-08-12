#include <vector>
#include <iostream>
#include "lemon/planarity.h"

typedef int Value;

using namespace lemon;
using namespace std;

using Cost = int;

using Graph = ListGraph;
using Node = Graph::Node;
using Edge = Graph::Edge;

template<typename ValueType>
using EdgeMap = Graph::EdgeMap<ValueType>;

template<typename ValueType>
using NodeMap = Graph::NodeMap<ValueType>;


// TODO : Add PlanarEmbedding algorithm. It returns strange outputs for its inputs, and needs more understanding of the underlying objects.

bool PlanarCheckingRunner(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    Graph g;
    vector<Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        Node n = g.addNode();
        nodes.push_back(n);
    }
    EdgeMap<Cost> costs(g);
    NodeMap<Cost> dists(g);

    vector<Edge> arcs;

    int NUM_ARCS = arcSources.size();

    for(int i = 0; i < NUM_ARCS; ++i) {
        Edge a = g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
        arcs.push_back(a);
    }

    // NOTE: While the LEMON Documentation does indicate PlanarityChecking is an algorithm, you need to access it through _planarity_bits, for some reason
    lemon::_planarity_bits::PlanarityChecking<Graph> alg(g);
    return alg.run();

}

auto PlanarColoringRunner(vector<int> arcSources, vector<int> arcTargets, int numNodes, bool useFiveAlg = true) {
    // Requires: arcSources and arcTargets, which define the graph's edges via the index of the source and target node, respectively. 
    // The nodes are 0 indexed, where 0 refers to the first node. 
    // numNodes refers to the number of nodes in the possibly unconnected graph. 
    // useFiveAlg refers to the choice of algorithm used to coloring the graph. Setting this to false uses a linear time algorithm which can 
    // give out six colors instead.
    Graph g;
    vector<Node> nodes;
    for(int i = 0; i < numNodes; ++i) {
        Node n = g.addNode();
        nodes.push_back(n);
    }

    vector<Edge> arcs;

    int NUM_ARCS = arcSources.size();

    for(int i = 0; i < NUM_ARCS; ++i) {
        Edge a = g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
        arcs.push_back(a);
    }

    PlanarEmbedding<Graph> preprocess(g);
    bool isPlanar = preprocess.run();
    auto & embedding = preprocess.embeddingMap();

    std::vector<int> colors;
    if(isPlanar) {
        PlanarColoring<Graph> algorithm(g);
        if(useFiveAlg){
        algorithm.runFiveColoring(embedding);
        }
        else{
            algorithm.runSixColoring();
        }

        for(int i = 0; i < numNodes; ++i) {
            colors.push_back(algorithm.colorIndex(nodes[i]));
        }
    }

    auto output = std::make_tuple(isPlanar, colors);
    return output;
}


auto PlanarDrawingRunner(vector<int> arcSources, vector<int> arcTargets, int numNodes) {
    // Requires: Two vectors, arcSources and arcTargets, each of which take integers to index specific nodes and, as pairs, consitute arcs in our graph
    //           One vector, arcDistances, which assigns for each arc an associated distance
    //           Two ints, numNodes and startnode, which give us the number of nodes in the directed graph and the starting node for Bellman Ford
    // Returns: A pair of vectors, which return the integers necessary to embed the graph onto a grid, where each edge is a straight line.
    Graph g;
    vector<Node> nodes;
    for(int i = 0; i < numNodes; ++i){
        Node n = g.addNode();
        nodes.push_back(n);
    }

    vector<Edge> arcs;

    int NUM_ARCS = arcSources.size();

    for(int i = 0; i < NUM_ARCS; ++i) {
        Edge a = g.addEdge(nodes[arcSources[i]], nodes[arcTargets[i]]);
        arcs.push_back(a);
    }


    PlanarEmbedding<Graph> preprocess(g);
    bool isPlanar = preprocess.run();

    auto & embedding = preprocess.embeddingMap();

    std::vector<int> x_coords;
    std::vector<int> y_coords;
    if(isPlanar) {
        PlanarDrawing<Graph> algorithm(g);
        algorithm.run(embedding);


        for(int i = 0; i < numNodes; ++i) {
            x_coords.push_back(algorithm[nodes[i]].x);
            y_coords.push_back(algorithm[nodes[i]].y);
        }
    }

    auto output = std::make_tuple(isPlanar, x_coords, y_coords);
    return output;
}

int main()
{
    // Example Usage - Example taken from EecsforGeeks
    vector<int> arc_src{0,0,0,1,1,2,2,3,4,4,6,7};
    vector<int> arc_targ{1,5,3,2,4,6,3,7,5,6,7,5};

    // Output vectors - used to get the information from minimum mean cycle
    vector<int> distances;
    vector<int> path_elements;

    // Runs the algorithm,
    auto output = PlanarColoringRunner(arc_src, arc_targ, 8);

    if(std::get<0>(output)){
        std::cout << "This graph is planar, with the following embedding:" << std::endl;
        for(int i = 0; i < std::get<1>(output).size(); i++) {
            std::cout << "Node " << i  << " has color " << std::get<1>(output)[i] << std::endl;
        }
    }
    else{
        std::cout << "This graph is not planar" << std::endl;
    }

}
