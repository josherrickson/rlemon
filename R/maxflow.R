##' Finds the maximum flow of a directed graph, given a source and destination
##' node.
##'
##' For details on LEMON's implementation, including differences between the
##' algorithms, see \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00611.html}.
##' @title Solver for MaxFlow
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcCapacities Vector corresponding to the capacities of nodes of a
##'   graph's edges
##' @param sourceNode The source node
##' @param destNode The destination node
##' @param numNodes The number of nodes in the graph
##' @param algorithm Choices of algorithm include "Preflow" and "EdmondsKarp".
##'   "Preflow" is the default.
##' @return A named list containing three entries: 1) "flows": a vector
##'   corresponding to the flows of arcs in the graph, 2) "cut_values": a vector
##'   of cut-values of the graph's nodes, and 3) "cost": the total cost of the
##'   flows in the graph, i.e. the maxflow value.
##' @export
MaxFlow <- function(arcSources,
                    arcTargets,
                    arcCapacities,
                    sourceNode,
                    destNode,
                    numNodes,
                    algorithm = "Preflow") {

  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcCapacities, numNodes)
  check_node(sourceNode, numNodes)
  check_node(destNode, numNodes)
  check_algorithm(algorithm)

  algfn <- switch(algorithm,
                  "Preflow" = PreflowRunner,
                  "EdmondsKarp" = EdmondsKarpRunner,
                  stop("Invalid algorithm.")
                  )
  result <- algfn(arcSources, arcTargets, arcCapacities,
                  sourceNode, destNode, numNodes)
  names(result) <- c("flows", "cut_values", "cost")
  return(result)
}

##' Finds the solution to the network circulation problem via the push-relabel
##' circulation algorithm.
##'

##' For details on LEMON's implementation, including differences between the
##' algorithms, see \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00078.html}.
##' @title Solver for Network Circulation
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
##' @param algorithm Choices of algorithminclude "Circulation". "Circulation" is
##'   the default.
##' @return A named list containing two entries: 1) "flows": a vector
##'   corresponding to the flows of arcs in the graph, and 2) "barriers": a
##'   vector of the graph's barrier nodes.
##' @export
NetworkCirculation <- function(arcSources,
                               arcTargets,
                               arcLowerBound,
                               arcUpperBound,
                               nodeSupplies,
                               numNodes,
                               algorithm = "Circulation") {

  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcLowerBound, numNodes)
  check_arc_map(arcSources, arcTargets, arcUpperBound, numNodes)
  check_node_map(nodeSupplies, numNodes)
  check_algorithm(algorithm)

  algfn <- switch(algorithm,
                  "Circulation" = CirculationRunner,
                  stop("Invalid algorithm.")
                  )
  result <- algfn(arcSources, arcTargets, arcLowerBound,
                  arcUpperBound, nodeSupplies, numNodes)
  names(result) <- c("flows", "barriers")
  return(result)
}
