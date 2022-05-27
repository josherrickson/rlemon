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
##' @return A named list containing three entries: 1) "mincut": the value of the
##'   minimum cut in the graph, 2) "first_partition": a vector of nodes in the
##'   first partition, and 3) "second_partition": a vector of nodes in the
##'   second partition. GomoryHu calculates a Gomory-Hu Tree and returns a list
##'   containing three entries: 1) A vector of predecessor nodes of each node in
##'   the graph, and 2) A vector of weights of the predecessor edge of each
##'   node, and 3) A vector of distances from the root node to each node.
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

  algfn <- switch(algorithm,
                  "NagamochiIbaraki" = NagamochiIbarakiRunner,
                  "HaoOrlin" = HaoOrlinRunner,
                  stop("Invalid algorithm.")
                  )
  result <- algfn(arcSources, arcTargets, arcWeights, numNodes)
  names(result) <- c("mincut", "first_partition", "second_partition")
  return(result)
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
##' @return A namedlist containing three entries: 1) "predecessors": a vector of
##'   predecessor nodes of each node in the graph, and 2) "weights": a vector of
##'   weights of the predecessor edge of each node, and 3) "distances": vector
##'   of distances from the root node to each node.
##' @export
AllPairsMinCut <- function(arcSources,
                           arcTargets,
                           arcWeights,
                           numNodes,
                           algorithm = "GomoryHu") {

  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcWeights, numNodes)
  check_algorithm(algorithm)

  algfn <- switch(algorithm,
                  "GomoryHu" = GomoryHuTreeRunner,
                  stop("Invalid algorithm.")
                  )
  result <- algfn(arcSources, arcTargets, arcWeights, numNodes)
  names(result) <- c("predecessors", "weights", "distances")
  return(result)
}
