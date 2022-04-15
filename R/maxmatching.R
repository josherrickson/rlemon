##' Finds the maximum weighted matching in graphs and bipartite graphs. Each
##' algorithm in this set returns different outputs depending on different
##' situations, like PerfectMatching or PerfectFractionalMathing.
##'
##' For details on LEMON's implementation, including differences between the
##' algorithms, see \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00615.html}.
##' @title Solver for Maximum Weighted Matching
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcWeights Vector corresponding to the weights of a graph's edges.
##'   Default is \code{NULL} for unweight matching.
##' @param numNodes The number of nodes in the graph
##' @param algorithm Choices of algorithm include "MaxWeightedMatching",
##'   "MaxWeightedPerfectMatching", "MaxWeightedFractionalMatching", and
##'   "MaxWeightedPerfectFractionalMatching". "MaxWeightedMatching" is the
##'   default.
##' @return A list containing two entries: 1) The matching value, 2) The edges
##'   of the final graph, in a list of (node, node) pairs
##' @export
MaxMatching <- function(arcSources,
                        arcTargets,
                        arcWeights = NULL,
                        numNodes,
                        algorithm = "MaxWeightedMatching") {

  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_algorithm(algorithm)
  if (is.null(arcWeights)) {
    arcWeights <- rep(1, length(arcSources))
  }
  check_arc_map(arcSources, arcTargets, arcWeights, numNodes)

  switch(algorithm,
         "MaxWeightedMatching" =
           MaximumWeightMatchingRunner(arcSources,
                                       arcTargets,
                                       arcWeights,
                                       numNodes),
         "MaxWeightedPerfectMatching" =
           MaximumWeightPerfectMatchingRunner(arcSources,
                                              arcTargets,
                                              arcWeights,
                                              numNodes),
         "MaxWeightedFractionalMatching" =
           MaximumWeightFractionalMatchingRunner(arcSources,
                                                 arcTargets,
                                                 arcWeights,
                                                 numNodes),
         "MaxWeightedPerfectFractionalMatching" =
           MaximumWeightFractionalPerfectMatchingRunner(arcSources,
                                                        arcTargets,
                                                        arcWeights,
                                                        numNodes),
         stop("Invalid algorithm."))
}

##' Finds the maximum cardinality matching in graphs and bipartite graphs.
##'
##' For details on LEMON's implementation, including differences between the
##' algorithms, see \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00615.html}.
##' @title Solve for Maximum Cardinality Matching
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @param algorithm Choices of algorithm include "MaxMatching" and
##'   "MaxFractionalMatching". "MaxMatching" is the default.
##' @return A list containing two entries: 1) The matching value, 2) The edges
##'   of the final graph, in a List of (node, node) pairs
##' @export
MaxCardinalityMatching <- function(arcSources,
                                   arcTargets,
                                   numNodes,
                                   algorithm = "MaxMatching") {

  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_algorithm(algorithm)

  switch(algorithm,
         "MaxMatching" =
           MaximumCardinalityMatchingRunner(arcSources,
                                            arcTargets,
                                            numNodes),
         "MaxFractionalMatching" =
           MaximumCardinalityFractionalMatchingRunner(arcSources,
                                                      arcTargets,
                                                      numNodes),
         stop("Invalid algorithm."))
}
