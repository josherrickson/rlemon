##' Runs maxflow algorithms on graphs.
##'
##' @title ConnectivityCheck
##' @param arcSources Vector corresponding to the source nodes of a graph's edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's edges
##' @param arcWeights Vector corresponding to the weights of a graph's edges
##' @param numNodes The number of nodes in the graph
##' @param problem What type of problem you want to run. Choices include
##'   "MaxMatching", "MaxWeightedMatching", "MaxWeightedPerfectMatching", 
##'   "MaxFractionalMatching", "MaxWeightedFractionalMatching", "MaxWeightedPerfectFractionalMatching"
##'   where "MaxWeightedMatching" is the default.
##'   See <http://lemon.cs.elte.hu/pub/doc/1.3.1/a00615.html> 
##'   for details on the differences.
##' @return A list containing two entries: 1) The matching value, 2) The edges of the final graph, in a List of List of (node, node) pairs
##' @export
maxmatching <- function(arcSources, arcTargets, numNodes, problem="MaxWeightedMatching", arcWeights=NULL) {

  check_graph_vertices(arcSources, arcTargets, numNodes)
  if(!is.null(arcWeights)) {
    check_arc_map(arcSources, arcTargets, arcWeights, numNodes)
  }
  switch(problem,
         "MaxWeightedMatching" = .Call(`_rlemon_MaximumWeightMatchingRunner`,arcSources, arcTargets, arcWeights, numNodes),
         "MaxWeightedPerfectMatching" = .Call(`_rlemon_MaximumWeightPerfectMatchingRunner`,arcSources, arcTargets, arcWeights, numNodes),
         "MaxWeightedFractionalMatching" = .Call(`_rlemon_MaximumWeightFractionalMatchingRunner`,arcSources, arcTargets, arcWeights, numNodes),
         "MaxWeightedPerfectFractionalMatching" = .Call(`_rlemon_MaximumWeightFractionalPerfectMatchingRunner`,arcSources, arcTargets, arcWeights, numNodes),
         "MaxMatching" = .Call(`_rlemon_MaximumCardinalityMatchingRunner`,arcSources, arcTargets, numNodes),
         "MaxFractionalMatching" = .Call(`_rlemon_MaximumCardinalityFractionalMatchingRunner`, arcSources, arcTargets, numNodes),
         stop("Invalid algorithm."))
}
