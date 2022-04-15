##' Runs a common graph search algorithm to find the minimum cardinality
##' shortest path. Finds the shortest path from/to all vertices if a start/end
##' node are not given.
##'
##' For details on LEMON's implementation, including differences between the
##' algorithms, see \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00608.html}.
##' @title Solver for Graph Search
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @param startNode Optional start node of the path
##' @param endNode Optional end node of the path
##' @param algorithm Choices of algorithm include "Bfs" (Breadth First Search)
##'   and "Dfs" (Depth First Search). Bfs is the default.
##' @return A list containing three entries: 1) the predecessor of each vertex
##'   in its shortest path, 2) the distances from each node to the startNode, 3)
##'   a vector of logicals indicating whether a node was reached.
##' @export
GraphSearch <- function(arcSources,
                        arcTargets,
                        numNodes,
                        startNode = -1,
                        endNode = -1,
                        algorithm = "Bfs") {

  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_algorithm(algorithm)

  if (startNode != -1) {
    check_node(startNode, numNodes)
  }
  if (endNode != -1) {
    check_node(endNode, numNodes)
  }

  out <- switch(algorithm,
                "Bfs" = BfsRunner(arcSources, arcTargets, numNodes,
                                  startNode, endNode),
                "Dfs" = DfsRunner(arcSources, arcTargets, numNodes,
                                  startNode, endNode),
                stop("Invalid algorithm."))

  out[[3]] <- as.logical(out[[3]])
  out
}

##' Runs the maximum cardinality search algorithm on a directed graph. The
##' maximum cardinality search first chooses any node of the digraph. Then every
##' time it chooses one unprocessed node with maximum cardinality, i.e the sum
##' of capacities on out arcs to the nodes which were previously processed. If
##' there is a cut in the digraph the algorithm should choose again any
##' unprocessed node of the digraph.
##'
##' For details on LEMON's implementation, including differences between the
##' algorithms, see \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00255.html}.
##' @title Solver for Max Cardinality Search
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcCapacities Vector corresponding to the distances of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @param startNode Optional start node of the path
##' @param algorithm Choices of algorithm include "maxcardinalitysearch".
##'   maxcardinalitysearch is the default.
##' @return A list containing two entries: 1) the cardinality of each node , 2)
##'   a logical vector indicating whether a node was reached or not
##' @export
MaxCardinalitySearch <- function(arcSources,
                                 arcTargets,
                                 arcCapacities,
                                 numNodes,
                                 startNode = -1,
                                 algorithm = "maxcardinalitysearch") {

  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_algorithm(algorithm)

  if (startNode != -1) {
    check_node(startNode, numNodes)
  }

  check_arc_map(arcSources, arcTargets, arcCapacities, numNodes)

  out <- switch(algorithm,
                "maxcardinalitysearch" =
                  MaxCardinalitySearchRunner(arcSources,
                                             arcTargets,
                                             arcCapacities,
                                             numNodes,
                                             startNode),
                stop("Invalid algorithm."))

  out[[2]] <- as.logical(out[[2]])
  out
}
