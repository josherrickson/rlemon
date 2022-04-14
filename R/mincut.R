##' Finds the minimum cut on graphs. NagamochiIbaraki calculates the min cut
##' value and edges in undirected graphs,while HaoOrlin calculates the min cut value
##' and edges in directed graphs.
##'
##' For details on LEMON's implementation, including differences between the
##' algorithms, see \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00613.html}.
##' @title Solver for MinCut
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcWeights Vector corresponding to the weights of a graph's arcs
##' @param numNodes The number of nodes in the graph
##' @param algorithm Choices of algorithm include "NagamochiIbaraki" and
##'   "HaoOrlin". "NagamochiIbaraki" is the default.
##' @return A list containing three entries: 1) The value of the minimum cut in
##'   the graph, and 2) A vector of nodes in the first partition, and 3) A
##'   vector of nodes in the second partition. GomoryHu calculates a Gomory-Hu
##'   Tree and returns a list containing three entries: 1) A vector of
##'   predecessor nodes of each node in the graph, and 2) A vector of weights of
##'   the predecessor edge of each node, and 3) A vector of distances from the
##'   root node to each node.
##' @export
MinCut <- function(arcSources,
                   arcTargets,
                   arcWeights,
                   numNodes,
                   algorithm = "NagamochiIbaraki") {

  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcWeights, numNodes)
  check_algorithm(algorithm)

  ## add a undirected/directed boolean?

  switch(algorithm,
         "NagamochiIbaraki" = NagamochiIbarakiRunner(arcSources, arcTargets,
                                                     arcWeights, numNodes),
         "HaoOrlin" = HaoOrlinRunner(arcSources, arcTargets, arcWeights,
                                     numNodes),
         stop("Invalid algorithm.")
         )
}


##' Finds the all-pairs minimum cut tree, using the Gomory-Hu algorithm.
##'
##' For details on LEMON's implementation, including differences between the
##' algorithms, see \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00182.html}.
##' @title Solver for All-Pairs MinCut
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcWeights Vector corresponding to the weights of a graph's arcs
##' @param numNodes The number of nodes in the graph
##' @param algorithm Choices of algorithm include "GomoryHu". "GomoryHu" is the
##'   default.
##' @return A list containing three entries: 1) A vector of predecessor nodes of
##'   each node in the graph, and 2) A vector of weights of the predecessor edge
##'   of each node, and 3) A vector of distances from the root node to each
##'   node.
##' @export
AllPairsMinCut <- function(arcSources,
                           arcTargets,
                           arcWeights,
                           numNodes,
                           algorithm = "GomoryHu") {

  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcWeights, numNodes)
  check_algorithm(algorithm)

  switch(algorithm,
         "GomoryHu" = GomoryHuTreeRunner(arcSources, arcTargets, arcWeights,
                                         numNodes),
         stop("Invalid algorithm.")
         )
}
