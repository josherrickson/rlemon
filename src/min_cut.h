#include "lemon/gomory_hu.h"
#include "lemon/hao_orlin.h"
#include "lemon/list_graph.h"
#include "lemon/nagamochi_ibaraki.h"
#include <Rcpp.h>
#include <vector>

using namespace lemon;
using namespace std;

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List NagamochiIbarakiRunner(std::vector<int> arcSources,
                                  std::vector<int> arcTargets,
                                  std::vector<int> arcWeights, int numNodes) {
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  ListGraph::EdgeMap<int> dists(g);
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }

  std::vector<ListGraph::Edge> arcs;
  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    ListGraph::Edge a =
        g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    dists[a] = arcWeights[i];
    arcs.push_back(a);
  }
  NagamochiIbaraki<ListGraph, ListGraph::EdgeMap<int> > alg(g, dists);
  alg.run();

  ListGraph::NodeMap<int> mincutmap(g);
  alg.minCutMap(mincutmap);

  int mincutvalue = alg.minCutValue();
  vector<int> partition1;
  vector<int> partition2;
  for (int i = 0; i < numNodes; ++i) {
    if (mincutmap[nodes[i]]) {
      partition1.push_back(i);
    } else {
      partition2.push_back(i);
    }
  }

  return Rcpp::List::create(mincutvalue, partition1, partition2);
}

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List HaoOrlinRunner(std::vector<int> arcSources,
                          std::vector<int> arcTargets,
                          std::vector<int> arcWeights, int numNodes) {
  ListDigraph g;
  std::vector<ListDigraph::Node> nodes;
  ListDigraph::ArcMap<int> dists(g);
  for (int i = 0; i < numNodes; ++i) {
    ListDigraph::Node n = g.addNode();
    nodes.push_back(n);
  }

  std::vector<ListDigraph::Arc> arcs;
  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    ListDigraph::Arc a =
        g.addArc(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    dists[a] = arcWeights[i];
    arcs.push_back(a);
  }
  HaoOrlin<ListDigraph, ListDigraph::ArcMap<int> > alg(g, dists);
  alg.run();

  ListDigraph::NodeMap<int> mincutmap(g);
  alg.minCutMap(mincutmap);

  int mincutvalue = alg.minCutValue();
  vector<int> partition1;
  vector<int> partition2;
  for (int i = 0; i < numNodes; ++i) {
    if (mincutmap[nodes[i]]) {
      partition1.push_back(i);
    } else {
      partition2.push_back(i);
    }
  }

  return Rcpp::List::create(mincutvalue, partition1, partition2);
}

//' @rdname lemon_runners
// [[Rcpp::export]]
Rcpp::List GomoryHuTreeRunner(std::vector<int> arcSources,
                              std::vector<int> arcTargets,
                              std::vector<int> arcWeights, int numNodes) {
  ListGraph g;
  std::vector<ListGraph::Node> nodes;
  ListGraph::EdgeMap<Cost> dists(g);
  for (int i = 0; i < numNodes; ++i) {
    ListGraph::Node n = g.addNode();
    nodes.push_back(n);
  }

  std::vector<ListGraph::Edge> arcs;
  int NUM_ARCS = arcSources.size();

  for (int i = 0; i < NUM_ARCS; ++i) {
    ListGraph::Edge a =
        g.addEdge(nodes[arcSources[i] - 1], nodes[arcTargets[i] - 1]);
    dists[a] = arcWeights[i];
    arcs.push_back(a);
  }
  GomoryHu<ListGraph, ListGraph::EdgeMap<Cost> > alg(g, dists);
  alg.run();

  std::vector<int> predecessors;
  std::vector<int> predEdgeWeights;
  std::vector<int> rootDistances;
  for (int i = 0; i < numNodes; ++i) {
    int predNodeLoc = g.id(alg.predNode(nodes[i]));
    int predNodeWeight = alg.predValue(nodes[i]);
    int rootDistance = alg.rootDist(nodes[i]);

    if (predNodeLoc != -1) {
      predEdgeWeights.push_back(predNodeWeight);
      predecessors.push_back(predNodeLoc + 1);
    } else {
      predEdgeWeights.push_back(-1);
      predecessors.push_back(predNodeLoc);
    }
    rootDistances.push_back(rootDistance);
  }

  return Rcpp::List::create(predecessors, predEdgeWeights, rootDistances);
}
