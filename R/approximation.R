##' Finds the largest complete subgraph (clique) in an undirected graph
##' via approximation algorithms for the maximal clique problem.
##'
##' @title MaxClique
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @param algorithm Which algorithm to run. Choices include
##'   "GrossoLocatelliPullanMc". GrossoLocatelliPullanMc is the default; see
##'   <https://lemon.cs.elte.hu/pub/doc/1.3.1/a00194.html> for more information.
##' @return A list containing two entries: 1) the clique size, and 2) the
##'   members of the clique.
##' @export
MaxClique <- function(arcSources,
                      arcTargets,
                      numNodes,
                      algorithm = "GrossoLocatelliPullanMc") {
  check_graph_vertices(arcSources, arcTargets, numNodes)

  switch(algorithm,
    "GrossoLocatelliPullanMc" =
      .Call(
        `_rlemon_GrossoLocatelliPullanMcRunner`,
        arcSources, arcTargets,
        numNodes
      ),
    stop("Invalid algorithm.")
  )
}
