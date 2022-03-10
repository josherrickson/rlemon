##' Finds the Minimum Mean Cycle in directed graphs.
##'
##' @title MinimumMeanCycle
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcDistances Vector corresponding to the distances of a graph's edges
##' @param numNodes The number of nodes in the graph
##' @param algorithm Which algorithm to run. Choices include "Howard", "Karp",
##'   "HartmannOrlin" where "Howard" is the default. See
##'   <https://lemon.cs.elte.hu/pub/doc/1.3.1/a00614.html> for details on the
##'   differences.
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


  switch(algorithm,
    "Howard" =
      .Call(
        `_rlemon_HowardMmcRunner`, arcSources, arcTargets,
        arcDistances, numNodes
      ),
    "Karp" =
      .Call(
        `_rlemon_KarpMmcRunner`, arcSources, arcTargets, arcDistances,
        numNodes
      ),
    "HartmannOrlin" =
      .Call(
        `_rlemon_HartmannOrlinMmcRunner`, arcSources, arcTargets,
        arcDistances, numNodes
      ),
    stop("Invalid algorithm.")
  )
}
