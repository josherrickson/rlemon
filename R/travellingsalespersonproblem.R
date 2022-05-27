##' Finds approximations for the travelling salesperson problem using
##' approximation algorithms on graphs. NOTE: LEMON's TSP uses a
##' complete graph in its backend, so expect less performance on sparse graphs.
##'
##' For details on LEMON's implementation, including differences between the
##' algorithms, see \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00618.html}.
##' @title Solver for Traveling Salesperson Problem
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcDistances Vector corresponding to the distances of a graph's edges
##' @param numNodes The number of nodes in the graph
##' @param defaultEdgeWeight The default edge weight if an edge is not-specified
##'   (default value 999999)
##' @param algorithm Choices of algorithm include "Christofides", "Greedy",
##'   "Insertion", "NearestNeighbor", and "Opt2". "Christofides" is the default.
##' @return A named list with 1) "node_order": the vector of visited nodes in
##'   order, and 2) "cost": the total tour cost.
##' @rdname TravelingSalesperson
##' @export
TravelingSalesperson <- function(arcSources,
                                 arcTargets,
                                 arcDistances,
                                 numNodes,
                                 defaultEdgeWeight = 999999,
                                 algorithm = "Christofides") {

  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcDistances, numNodes)
  check_algorithm(algorithm)

  algfn <- switch(algorithm,
                  "Christofides" = ChristofidesRunner,
                  "Greedy" = GreedyTSPRunner,
                  "Insertion" = InsertionTSPRunner,
                  "NearestNeighbor" = NearestNeighborTSPRunner,
                  "Opt2" = Opt2TSPRunner,
                  stop("Invalid algorithm.")
                  )
  result <- algfn(arcSources, arcTargets, arcDistances,
                  numNodes, defaultEdgeWeight = 999999)
  names(result) <- c("node_order", "cost")
  return(result)
}

##' @rdname TravelingSalesperson
##' @export
TravellingSalesperson <- TravelingSalesperson
