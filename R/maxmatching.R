##' Finds the maximum weighted matching in graphs and
##' bipartite graphs. Each algorithm in this set returns different outputs
##' depending on different situations, like PerfectMatching or PerfectFractionalMathing.
##'
##' @title MaxMatching
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcWeights Vector corresponding to the weights of a graph's edges
##' @param numNodes The number of nodes in the graph
##' @param algorithm What algorithm you want to run. Choices include
##'   "MaxWeightedMatching", "MaxWeightedPerfectMatching",
##'   "MaxWeightedFractionalMatching", "MaxWeightedPerfectFractionalMatching"
##'   where "MaxWeightedMatching" is the default. See
##'   <https://lemon.cs.elte.hu/pub/doc/1.3.1/a00615.html> for details on the
##'   differences.
##' @return A list containing two entries: 1) The matching value, 2) The edges
##'   of the final graph, in a List of List of (node, node) pairs
##' @export
MaxMatching <- function(arcSources,
                        arcTargets,
                        arcWeights = NULL,
                        numNodes,
                        algorithm = "MaxWeightedMatching") {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  if (!is.null(arcWeights)) {
    check_arc_map(arcSources, arcTargets, arcWeights, numNodes)
  }
  switch(algorithm,
    "MaxWeightedMatching" =
      .Call(
        `_rlemon_MaximumWeightMatchingRunner`, arcSources, arcTargets,
        arcWeights, numNodes
      ),
    "MaxWeightedPerfectMatching" =
      .Call(
        `_rlemon_MaximumWeightPerfectMatchingRunner`, arcSources,
        arcTargets, arcWeights, numNodes
      ),
    "MaxWeightedFractionalMatching" =
      .Call(
        `_rlemon_MaximumWeightFractionalMatchingRunner`, arcSources,
        arcTargets, arcWeights, numNodes
      ),
    "MaxWeightedPerfectFractionalMatching" =
      .Call(
        `_rlemon_MaximumWeightFractionalPerfectMatchingRunner`,
        arcSources, arcTargets, arcWeights, numNodes
      ),
    stop("Invalid algorithm.")
  )
}

##' Finds the maximum cardinality matching in graphs and
##' bipartite graphs.
##'
##' @title MaxCardinalityMatching
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @param algorithm What algorithm you want to run. Choices include
##'   "MaxMatching", "MaxFractionalMatching" where "MaxMatching" is the default.
##'   See <https://lemon.cs.elte.hu/pub/doc/1.3.1/a00615.html> for details on the
##'   differences.
##' @return A list containing two entries: 1) The matching value, 2) The edges
##'   of the final graph, in a List of List of (node, node) pairs
##' @export
MaxCardinalityMatching <- function(arcSources,
                                   arcTargets,
                                   numNodes,
                                   algorithm = "MaxMatching") {
  check_graph_vertices(arcSources, arcTargets, numNodes)

  switch(algorithm,
    "MaxMatching" = .Call(
      `_rlemon_MaximumCardinalityMatchingRunner`,
      arcSources, arcTargets, numNodes
    ),
    "MaxFractionalMatching" =
      .Call(
        `_rlemon_MaximumCardinalityFractionalMatchingRunner`,
        arcSources, arcTargets, numNodes
      ),
    stop("Invalid algorithm.")
  )
}
