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
##' @return A named list containing two entries: 1) "value": the matching value,
##'   2) "edges": the edges of the final graph, in a list of (node, node) pairs
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

  algfn <- switch(algorithm,
                  "MaxWeightedMatching" =
                    MaximumWeightMatchingRunner,
                  "MaxWeightedPerfectMatching" =
                    MaximumWeightPerfectMatchingRunner,
                  "MaxWeightedFractionalMatching" =
                    MaximumWeightFractionalMatchingRunner,
                  "MaxWeightedPerfectFractionalMatching" =
                    MaximumWeightFractionalPerfectMatchingRunner,
                  stop("Invalid algorithm.")
                  )
  result <- algfn(arcSources, arcTargets, arcWeights, numNodes)
  names(result) <- c("value", "edges")
  return(result)
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
##' @return A named list containing two entries: 1) "value": the matching value,
##'   2) "edges": the edges of the final graph, in a List of (node, node) pairs
##' @export
MaxCardinalityMatching <- function(arcSources,
                                   arcTargets,
                                   numNodes,
                                   algorithm = "MaxMatching") {

  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_algorithm(algorithm)

  algfn <- switch(algorithm,
                  "MaxMatching" = MaximumCardinalityMatchingRunner,
                  "MaxFractionalMatching" =
                    MaximumCardinalityFractionalMatchingRunner,
                  stop("Invalid algorithm.")
                  )

  result <- algfn(arcSources, arcTargets, numNodes)
  names(result) <- c("value", "edges")
  return(result)
}
