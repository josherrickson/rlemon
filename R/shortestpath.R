##' Finds the shortest path from a source node to the rest of the nodes in a
##' directed graph. These shortest path algorithms consider the distances present
##' in the graph, as well as the number of edges.
##'
##' For details on LEMON's implementation, including differences between the
##' algorithms, see \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00609.html}.
##' @title Solve for Shortest Path from Source Node to All Other Nodes
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcDistances Vector corresponding to the distances of a graph's edges
##' @param numNodes The number of nodes in the graph
##' @param sourceNode The source node
##' @param algorithm Choices of algorithm include "Dijkstra" and "BellmanFord".
##'   "Dijkstra" is the default.
##' @return A named list containing two entries: 1) "distances": the distances
##'   from each node to the startNode and 2) "predecessors": the predecessor of
##'   each vertex in its shortest path.
##' @export
ShortestPathFromSource <- function(arcSources,
                                   arcTargets,
                                   arcDistances,
                                   numNodes,
                                   sourceNode,
                                   algorithm = "Dijkstra") {

  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcDistances, numNodes)
  check_node(sourceNode, numNodes)
  check_algorithm(algorithm)

  algfn <- switch(algorithm,
                  "Dijkstra" = DijkstraRunner,
                  "BellmanFord" = BellmanFordRunner,
                  stop("Invalid algorithm.")
                  )
  result <- algfn(arcSources, arcTargets, arcDistances, numNodes, sourceNode)
  names(result) <- c("distances", "predecessors")
  return(result)
}

##' FINDS the shortest arc disjoint paths between two nodes in a directed graph.
##' This implementation runs a variation of the successive shortest path algorithm.
##'
##' For details on LEMON's implementation, including differences between the
##' algorithms, see \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00609.html}.
##' @title Solver for Shortest Path Between Two Nodes
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcDistances Vector corresponding to the distances of a graph's edges
##' @param numNodes The number of nodes in the graph
##' @param sourceNode The start node of the path
##' @param destNode The end node of the path
##' @param algorithm Choices of algorithm include "Suurballe". "Suurballe" is
##'   the default.
##' @return A named list containing two entries: 1) "num_paths": the number of
##'   paths from the start node to the end node and 2) "list_paths": a list of
##'   paths found. If there are multiple paths, then the second entry will have
##'   multiple paths.
##' @export
ShortestPath <- function(arcSources,
                         arcTargets,
                         arcDistances,
                         numNodes,
                         sourceNode,
                         destNode,
                         algorithm = "Suurballe") {

  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcDistances, numNodes)
  check_node(sourceNode, numNodes)
  check_node(destNode, numNodes)
  check_algorithm(algorithm)

  algfn <- switch(algorithm,
                  "Suurballe" = SuurballeRunner,
                  stop("Invalid algorithm.")
                  )
  result <- algfn(arcSources, arcTargets, arcDistances,
                                       numNodes, sourceNode, destNode)
  names(result) <- c("num_paths", "list_paths")
  return(result)
}
