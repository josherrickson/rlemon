##' Runs MMC (Minimum Mean Cycle) algorithms on graphs.
##'
##' @title minimummeancycle
##' @param arcSources, a vector corresponding to the source nodes of a graph's edges
##' @param arcTargets, a vector corresponding to the destination nodes of a graph's edges
##' @param arcDistances, a vector corresponding to the distances of a graph's edges
##' @param numNodes, the number of nodes in the graph
##' @param algorithm Which algorithm to run. Choices include
##'   "Howard", "Karp", "HartmannOrlin"
##'   where "Howard" is the default.
##'   See <http://lemon.cs.elte.hu/pub/doc/1.3.1/a00614.html> 
##'   for details on the differences.
##' @return A list containing two entries: 1) A vector containing the costs of each edge in the MMC cycle, and 2) the nodes in the MMC cycle.   
##' @export
minimummeancycle <- function(arcSources, arcTargets, arcDistances, numNodes, algorithm) {

  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcDistances, numNodes)
  

  switch(algorithm,
         "Howard" = .Call(`_rlemon_HowardMmcRunner`,arcSources, arcTargets, arcDistances, numNodes),
         "Karp" = .Call(`_rlemon_KarpMmcRunner`,arcSources, arcTargets, arcDistances, numNodes),
         "HartmannOrlin" = .Call(`_rlemon_HartmannOrlinMmcRunner`,arcSources, arcTargets, arcDistances, numNodes))
}
