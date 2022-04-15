##' Finds the Minimum Mean Cycle in directed graphs.
##'
##' For details on LEMON's implementation, including differences between the
##' algorithms, see \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00614.html}.
##' @title Solver for Minimum Mean Cycle
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcDistances Vector corresponding to the distances of a graph's edges
##' @param numNodes The number of nodes in the graph
##' @param algorithm Choices of algorithm include "Howard", "Karp", and
##'   "HartmannOrlin". "Howard" is the default.
##' @return A list containing two entries: 1) A vector containing the costs of
##'   each edge in the MMC, and 2) the nodes in the MMC.
##' @export
MinMeanCycle <- function(arcSources,
                         arcTargets,
                         arcDistances,
                         numNodes,
                         algorithm = "Howard") {

  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcDistances, numNodes)
  check_algorithm(algorithm)

  switch(algorithm,
         "Howard" = HowardMmcRunner(arcSources, arcTargets,
                                    arcDistances, numNodes),
         "Karp" = KarpMmcRunner(arcSources, arcTargets,
                                arcDistances, numNodes),
         "HartmannOrlin" = HartmannOrlinMmcRunner(arcSources, arcTargets,
                                                  arcDistances, numNodes),
         stop("Invalid algorithm.")
         )
}
