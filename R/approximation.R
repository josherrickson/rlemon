##' Runs approximation algorthims for the maximal clique problem to find the largest complete subgraph (clique) in an undirected graph.
##'
##' @title approx
##' @param arcSources, a vector corresponding to the source nodes of a graph's edges
##' @param arcTargets, a vector corresponding to the destination nodes of a graph's edges
##' @param numNodes, the number of nodes in the graph
##' @param algorithm Which algorithm to run. Choices include
##'   "GrossoLocatelliPullanMc".
##'    GrossoLocatelliPullanMc is the default; see
##'   <http://lemon.cs.elte.hu/pub/doc/1.3.1/a00619.html> for details
##'   on the differences.
##' @return a list containing two entries with 1) the clique size, and 2) the members of the clique.
##' @export
approx <- function(arcSources, arcTargets, numNodes, algorithm) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  switch(algorithm, "GrossoLocatelliPullanMc" = .Call(`_rlemon_GrossoLocatelliPullanMcRunner`, arcSources, arcTargets, numNodes))
}
