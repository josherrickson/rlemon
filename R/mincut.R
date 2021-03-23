##' Runs mincut algorithms on graphs. NagamochiIbaraki calculates the min cut
##' value in undirected graphs. HaoOrlin calculates the min cut value in
##' directed graphs.
##'
##' @title MinCut
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcWeights Vector corresponding to the weights of a graph's arcs
##' @param numNodes The number of nodes in the graph
##' @param algorithm Which algorithm to run. Choices include "NagamochiIbaraki",
##'   "HaoOrlin" where NagamochiIbaraki is the default; see
##'   <http://lemon.cs.elte.hu/pub/doc/1.3.1/a00613.html> for details on the
##'   differences.
##' @return A list containing three entries: 1) The value of the minimum cut in
##'   the graph, and 2) A list of nodes in the first partition, and 3) A list of
##'   nodes in the second partition. GomoryHu calculates a Gomory-Hu Tree and
##'   returns a list containing three entries: 1) A list of predecessor nodes of
##'   each node in the graph, and 2) A list of weights of the predecessor edge
##'   of each node, and 3) A list of distances from the root node to each node.
##' @export
MinCut <- function(arcSources,
                   arcTargets,
                   arcWeights,
                   numNodes,
                   algorithm) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcWeights, numNodes)

  ## add a undirected/directed boolean?

  switch(algorithm,
    "NagamochiIbaraki" =
      .Call(
        `_rlemon_NagamochiIbarakiRunner`, arcSources, arcTargets,
        arcWeights, numNodes
      ),
    "HaoOrlin" =
      .Call(
        `_rlemon_HaoOrlinRunner`, arcSources, arcTargets, arcWeights,
        numNodes
      ),
    stop("Invalid algorithm.")
  )
}


##' Runs the Gomory-Hu Algorithm to calculate a rooted Gomory Hu Tree.
##'
##' @title MinCut
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcWeights Vector corresponding to the weights of a graph's arcs
##' @param numNodes The number of nodes in the graph
##' @return A list containing three entries: 1) A list of predecessor nodes of
##'   each node in the graph, and 2) A list of weights of the predecessor edge
##'   of each node, and 3) A list of distances from the root node to each node.
##' @export
GomoryHuTree <- function(arcSources, arcTargets, arcWeights, numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcWeights, numNodes)

  .Call(`_rlemon_GomoryHuTreeRunner`, arcSources, arcTargets, arcWeights,
        numNodes)
}
