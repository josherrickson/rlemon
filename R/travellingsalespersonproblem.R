##' Finds approximations for the travelling salesperson problem using
##' approximation algorithms on graphs. NOTE: LEMON's TSP uses a
##' complete graph in its backend, so expect less performance on sparse graphs.
##' @title TravelingSalespersonProblem
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcDistances Vector corresponding to the distances of a graph's edges
##' @param numNodes The number of nodes in the graph
##' @param defaultEdgeWeight The default edge weight if an edge is not-specified
##'   (default value 999999)
##' @param algorithm Which algorithm to run. Choices include
##'   "Christofides","Greedy","Insertion","NearestNeighbor","Opt2". Christofides
##'   is the default; see <https://lemon.cs.elte.hu/pub/doc/1.3.1/a00618.html>
##'   for details on the differences.
##' @return a List with 1) the list of tour vertices, and 2) the total tour cost
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

  switch(algorithm,
    "Christofides" = .Call(`_rlemon_ChristofidesRunner`, arcSources, arcTargets,
      arcDistances, numNodes,
      defaultEdgeWeight = 999999
    ),
    "Greedy" = .Call(`_rlemon_GreedyTSPRunner`, arcSources, arcTargets,
      arcDistances, numNodes,
      defaultEdgeWeight = 999999
    ),
    "Insertion" = .Call(`_rlemon_InsertionTSPRunner`, arcSources,
      arcTargets, arcDistances, numNodes,
      defaultEdgeWeight = 999999
    ),
    "NearestNeighbor" = .Call(`_rlemon_NearestNeighborTSPRunner`,
      arcSources, arcTargets, arcDistances,
      numNodes,
      defaultEdgeWeight = 999999
    ),
    "Opt2" = .Call(`_rlemon_Opt2TSPRunner`, arcSources, arcTargets,
      arcDistances, numNodes,
      defaultEdgeWeight = 999999
    ),
    stop("Invalid algorithm.")
  )
}

##' @rdname TravelingSalesperson
##' @export
TravellingSalesperson <- TravelingSalesperson
