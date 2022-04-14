##' These "runner" functions provide a slightly lower-level access to LEMON.
##'
##' Internally, all exported rlemon functions call a "runner" function to
##' interface with the C++, for example, \code{MaxFlow(..., algorithm =
##' "PreFlow")} will call \code{PreFlowRunner(...)}.
##'
##' In almost all cases, users will want to stick with the exported functions.
##'
##' The only current scenario in which a user might want to use the runners
##' would be to bypass rlemon's input checks. In this very particular case, a
##' user can access the appropriate runner by the triple-colon notation, e.g. in
##' the MaxFlow example, they would use \code{rlemon:::PreFlowRunner(...)}.
##' @title LEMON runners
##' @param arcSources a vector corresponding to the source nodes of a graph’s
##'   edges
##' @param arcTargets a vector corresponding to the destination nodes of a
##'   graph’s edges
##' @param arcCapacities vector corresponding to the capacities of nodes of a
##'   graph’s edges
##' @param arcLowerBound vector corresponding to the lower-bound capacities of
##'   nodes of a graph’s edges
##' @param arcUpperBound vector corresponding to the upper-bound capacities of
##'   nodes of a graph’s edges
##' @param arcDistances vector corresponding to the distances of a graph’s edges
##' @param arcWeights vector corresponding to the weights of a graph’s arcs
##' @param arcCosts vector corresponding to the costs of nodes of a graph’s
##'   edges
##' @param numNodes the number of nodes in the graph
##' @param nodesList a vector of all the nodes in the graph
##' @param startNode in path-based algorithms, the start node of the path
##' @param endNode in path-based algorithms, the end node of the path
##' @param sourceNode in flow-based algorithms, the source node of the flow
##' @param destinationNode in flow-based algorithms, the destination node of the flow
##' @param nodeSupplies vector corresponding to the supplies of each node of the
##'   graph
##' @param useFiveAlg a boolean that asks if you want to 5-color a graph. If
##'   false, runs a faster 6-coloring algorithm instead.
##' @param defaultEdgeWeight The default edge weight if an edge is not-specified
##'   (default value 999999)
##' @return Algorithm results
##' @rdname lemon_runners
lemon_runners <- function() {
  stop("See `help(lemon_runners)` for details on these lower level functions")
}
