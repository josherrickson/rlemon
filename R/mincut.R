##' Runs mincut algorithms on graphs.
##'
##' @title MinCut
##' @param arcSources, a vector corresponding to the source nodes of a graph's edges
##' @param arcTargets, a vector corresponding to the destination nodes of a graph's edges
##' @param arcWeights, a vector corresponding to the weights of a graph's arcs
##' @param numNodes, the number of nodes in the graph
##' @param algorithm Which algorithm to run. Choices include
##'   "NagamochiIbaraki", "HaoOrlin", "GomoryHu".
##'    NagamochiIbaraki is the default; see
##'   <http://lemon.cs.elte.hu/pub/doc/1.3.1/a00613.html> for details
##'   on the differences.
##' @return NagamochiIbaraki/HaoOrlin returns a list containing three entries:  1) The value of the minimum cut in the graph, and 2) A list of nodes in the first partition, and 3) A list of nodes in the second partition. GomoryHu calculates a Gomory-Hu Tree and returns a list containing three entries: 1) A list of predecessor nodes of each node in the graph, and 2) A list of weights of the predecessor edge of each node, and 3) A list of distances from the root node to each node.
##' @export
mincut <- function(arcSources, arcTargets, arcWeights, numNodes, algorithm) {

  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcWeights, numNodes)

  switch(algorithm,
         "NagamochiIbaraki" = .Call(`_rlemon_NagamochiIbarakiRunner`, arcSources, arcTargets, arcWeights, numNodes),
         "HaoOrlin" = .Call(`_rlemon_HaoOrlinRunner`, arcSources, arcTargets, arcWeights, numNodes),
         "GomoryHu" = .Call(`_rlemon_GomoryHuTreeRunner`, arcSources, arcTargets, arcWeights, numNodes))
}
