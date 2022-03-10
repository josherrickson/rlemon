##' Finds the shortest path from a source node to the rest of the nodes in a
##' directed graph. These shortest path algorithms consider the distances present
##' in the graph, as well as the number of edges.
##'
##' @title ShortestPathFromSource
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcDistances Vector corresponding to the distances of a graph's edges
##' @param numNodes The number of nodes in the graph
##' @param sourceNode The start node of the path
##' @param algorithm Which algorithm to run. Choices include "Dijkstra",
##'   "BellmanFord" where "Dijkstra" is the default. See
##'   <https://lemon.cs.elte.hu/pub/doc/1.3.1/a00609.html> for details on the
##'   differences.
##' @return A list containing two entries: 1) the distances from each node to
##'   the startNode and 2) the predecessor of each vertex in its shortest path.
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

  switch(algorithm,
    "Dijkstra" = .Call(
      `_rlemon_DijkstraRunner`, arcSources, arcTargets,
      arcDistances, numNodes, sourceNode
    ),
    "BellmanFord" = .Call(
      `_rlemon_BellmanFordRunner`, arcSources, arcTargets,
      arcDistances, numNodes, sourceNode
    ),
    stop("Invalid algorithm.")
  )
}

##' Finds the shortest arc disjoint paths between two nodes in a directed graph.
##' This implementation runs a variation of the successive shortest path algorithm.
##'
##' @title ShortestPath
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcDistances Vector corresponding to the distances of a graph's edges
##' @param numNodes The number of nodes in the graph
##' @param sourceNode The start node of the path
##' @param destNode The end node of the path
##' @param algorithm Which algorithm to run. Choices include "Suurballe" where
##'   "Suurballe" is the default. See
##'   <https://lemon.cs.elte.hu/pub/doc/1.3.1/a00420.html> for more information.
##' @return A list containing two entries: 1) the number of paths from the start
##'   node to the end node and 2) a list of paths found.
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

  switch(algorithm,
    "Suurballe" = .Call(
      `_rlemon_SuurballeRunner`, arcSources, arcTargets,
      arcDistances, numNodes, sourceNode, destNode
    ),
    stop("Invalid algorithm.")
  )
}
