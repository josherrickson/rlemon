##' These "runner" functions provide a slightly lower-level access to LEMON. See
##' "Details".
##'
##' Internally, all exported rlemon functions call a "runner" function to
##' interface with the C++, for example, \code{MaxFlow(..., algorithm =
##' "PreFlow")} will call \code{PreFlowRunner(...)}.
##'
##' In almost all cases, users will want to stick with the exported functions.
##'
##' Runners differ from exported functions in a few ways:
##' \enumerate{
##'  \item Exported functions provide input checking.
##'  \item Exported functions provide slightly cleaner output, such as
##'        converting 0/1 boolean into \code{logical}.
##'  \item Any \code{list} which is returned from an exported function will be
##'        named.
##'  \item The \code{arcWeights} argument is optional to \code{MaxMatching()},
##'        automatically generating a constant weight if it is excluded.
##'        \code{arcWeights} is not optional in \code{MaxMatchingRunner()}.
##' }
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
##' @param destinationNode in flow-based algorithms, the destination node of the
##'   flow
##' @param nodeSupplies vector corresponding to the supplies of each node of the
##'   graph
##' @param useFiveAlg if \code{TRUE} (default), run a 5-color algorithm. If
##'   \code{FALSE}, runs a faster 6-coloring algorithm instead.
##' @param defaultEdgeWeight The default edge weight if an edge is not-specified
##'   (default value 999999)
##' @return Algorithm results
##' @rdname lemon_runners
lemon_runners <- function() {
  stop("See `help(lemon_runners)` for details on these lower level functions")
}
