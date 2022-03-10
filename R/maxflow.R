##' Finds the maximum flow of a directed graph, given a source and destination node.
##'
##' @title MaxFlow
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcCapacities Vector corresponding to the capacities of nodes of a
##'   graph's edges
##' @param sourceNode The source node
##' @param destNode The destination node
##' @param numNodes The number of nodes in the graph
##' @param algorithm Which algorithm to run. Choices include "Preflow",
##'   "EdmondsKarp", where "Preflow" is the default. See
##'   <https://lemon.cs.elte.hu/pub/doc/1.3.1/a00611.html> for details on the
##'   differences.
##' @return A list containing three entries: 1) A list corresponding to the
##'   flows of arcs in the graph, 2) A list of cut-values of the graph's nodes,
##'   and 3) the total cost of the flows in the graph, i.e. the maxflow value.
##' @export
MaxFlow <- function(arcSources,
                    arcTargets,
                    arcCapacities,
                    sourceNode,
                    destNode,
                    numNodes,
                    algorithm) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcCapacities, numNodes)
  check_node(sourceNode, numNodes)
  check_node(destNode, numNodes)

  switch(algorithm,
    "Preflow" = .Call(
      `_rlemon_PreflowRunner`, arcSources, arcTargets,
      arcCapacities, sourceNode, destNode, numNodes
    ),
    "EdmondsKarp" = .Call(
      `_rlemon_EdmondsKarpRunner`, arcSources, arcTargets,
      arcCapacities, sourceNode, destNode, numNodes
    ),
    stop("Invalid algorithm.")
  )
}

##' Finds the solution to the network circulation problem via the push-relabel circulation algorithm.
##'
##' @title NetworkCirculation
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcLowerBound Vector corresponding to the lower-bound capacities of
##'   nodes of a graph's edges
##' @param arcUpperBound Vector corresponding to the upper-bound capacities of
##'   nodes of a graph's edges
##' @param nodeSupplies Vector corresponding to the supplies of each node of the
##'   graph.
##' @param numNodes The number of nodes in the graph
##' @param algorithm Which algorithm to run. Choices include "Circulation" where
##'   "Circulation" is the default. See
##'   <https://lemon.cs.elte.hu/pub/doc/1.3.1/a00078.html> for details on the
##'   differences.
##' @return A list containing two entries: 1) A list corresponding to the flows
##'   of arcs in the graph, and 2) A list of the graph's barrier nodes.
##' @export
NetworkCirculation <- function(arcSources,
                               arcTargets,
                               arcLowerBound,
                               arcUpperBound,
                               nodeSupplies,
                               numNodes,
                               algorithm) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcLowerBound, numNodes)
  check_arc_map(arcSources, arcTargets, arcUpperBound, numNodes)
  check_node_map(nodeSupplies, numNodes)

  switch(algorithm,
    "Circulation" = .Call(
      `_rlemon_CirculationRunner`, arcSources, arcTargets,
      arcLowerBound, arcUpperBound, nodeSupplies,
      numNodes
    ),
    stop("Invalid algorithm.")
  )
}
