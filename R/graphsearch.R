##' Runs a common graph search algorithm to find the minimum cardinality shortest path.
##' Finds the shortest path from/to all vertices if a start/end node are
##' not given.
##'
##' @title GraphSearch
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @param startNode Optional start node of the path
##' @param endNode Optional end node of the path
##' @param algorithm Which algorithm to run. Choices include "Bfs", "Dfs". Bfs
##'   (Breadth First Search) is the default; see
##'   <https://lemon.cs.elte.hu/pub/doc/1.3.1/a00608.html> for details on the
##'   differences.
##' @return A list containing three entries: 1) the predecessor of each vertex
##'   in its shortest path, 2) the distances from each node to the startNode ,
##'   3) a list containing if a node was reached or not
##' @export
GraphSearch <- function(arcSources,
                        arcTargets,
                        numNodes,
                        startNode = -1,
                        endNode = -1,
                        algorithm = "Bfs") {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  if (startNode != -1) {
    check_node(startNode, numNodes)
  }
  if (endNode != -1) {
    check_node(endNode, numNodes)
  }

  switch(algorithm,
    "Bfs" = .Call(
      `_rlemon_BfsRunner`, arcSources, arcTargets, numNodes,
      startNode, endNode
    ),
    "Dfs" = .Call(
      `_rlemon_DfsRunner`, arcSources, arcTargets, numNodes,
      startNode, endNode
    ),
    stop("Invalid algorithm.")
  )
}

##' Runs the maximum cardinality search algorithm on a directed graph. The
##' maximum cardinality search first chooses any node of the digraph. Then every
##' time it chooses one unprocessed node with maximum cardinality, i.e the sum
##' of capacities on out arcs to the nodes which were previously processed. If
##' there is a cut in the digraph the algorithm should choose again any
##' unprocessed node of the digraph.
##'
##' @title MaxCardinalitySearch
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcCapacities Vector corresponding to the distances of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @param startNode Optional start node of the path
##' @param algorithm Which algorithm to run. Choices include
##'   "maxcardinalitysearch". maxcardinalitysearch is the default; see
##'   <https://lemon.cs.elte.hu/pub/doc/1.3.1/a00255.html> for more information.
##' @return A list containing two entries: 1) the cardinality of each node , 2)
##'   a list containing if a node was reached or not
##' @export
MaxCardinalitySearch <- function(arcSources,
                                 arcTargets,
                                 arcCapacities,
                                 numNodes,
                                 startNode = -1,
                                 algorithm = "maxcardinalitysearch") {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  if (startNode != -1) {
    check_node(startNode, numNodes)
  }
  check_arc_map(arcSources, arcTargets, arcCapacities, numNodes)

  switch(algorithm,
    "maxcardinalitysearch" = .Call(
      `_rlemon_MaxCardinalitySearchRunner`,
      arcSources, arcTargets, arcCapacities,
      numNodes, startNode
    ),
    stop("Invalid algorithm.")
  )
}
