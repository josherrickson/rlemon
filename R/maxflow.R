##' Runs maxflow algorithms on graphs.
##'
##' @title MinCostFlow
##' @param arcSources, a vector corresponding to the source nodes of a graph's edges
##' @param arcTargets, a vector corresponding to the destination nodes of a graph's edges
##' @param arcCapacities, a vector corresponding to the capacities of nodes of a graph's edges
##' @param sourceNode, the source node 
##' @param destNode, the destination node
##' @param numNodes, the number of nodes in the graph
##' @param algorithm Which algorithm to run. Choices include
##'   "Preflow", "EdmondsKarp",
##'   where "Preflow" is the default.
##'   See <http://lemon.cs.elte.hu/pub/doc/1.3.1/a00611.html> 
##'   for details on the differences.
##' @return A list containing three entries: 1) A list corresponding to the flows of arcs in the graph, and 2) A list of cut-values of the graph's nodes.
##' @export
maxflow <- function(arcSources, arcTargets, arcCapacities, sourceNode, destNode, numNodes, algorithm) {

  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcCapacities, numNodes)
  check_node(sourceNode,numNodes)
  check_node(destNode, numNodes)

  switch(algorithm,
         "Preflow" = .Call(`_rlemon_PreflowRunner`,arcSources, arcTargets, arcCapacities, sourceNode, destNode, numNodes),
         "EdmondsKarp" = .Call(`_rlemon_EdmondsKarpRunner`, arcSources, arcTargets, arcCapacities, sourceNode, destNode, numNodes))
}
