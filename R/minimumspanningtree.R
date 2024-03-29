##' The minimum spanning tree is the minimal connected acyclic subgraph of a
##' graph, assuming the graph is undirected.
##'
##' For details on LEMON's implementation, including differences between the
##' algorithms, see
##' \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00610.html#ga233792b2c44a3581b85a775703e045af}
##' @title Solver for Minimum Spanning Tree
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcDistances Vector corresponding to the distances of nodes of a
##'   graph's edges
##' @param numNodes The number of nodes in the graph
##' @param algorithm Choices of algorithm include "Kruskal". "Kruskal" is the
##'   default.
##' @return A named list containing three entries: 1) "sources": a vector
##'   corresponding the source nodes of the edges in the tree, 2) "targets": a
##'   vector corresponding the target nodes of the edges in the tree, and 3)
##'   "value": the total minimum spanning tree value.
##' @export
MinSpanningTree <- function(arcSources,
                            arcTargets,
                            arcDistances,
                            numNodes,
                            algorithm = "Kruskal") {

  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcDistances, numNodes)
  check_algorithm(algorithm)

  algfn <- switch(algorithm,
                  "Kruskal" = KruskalRunner,
                  stop("Invalid algorithm.")
                  )
  result <- algfn(arcSources, arcTargets, arcDistances, numNodes)
  names(result) <- c("sources", "targets", "value")
  return(result)
}


##' Finds the minimum cost arborescence of a graph, returning both the cost and
##' the pairs of nodes for the edges in the arborescence.
##'
##' For details on LEMON's implementation, including differences between the
##' algorithms, see \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00264.html}.
##' @title Solver for Minimum Cost Arborescence
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcDistances Vector corresponding to the distances of nodes of a
##'   graph's edges
##' @param sourceNode The source node
##' @param numNodes The number of nodes in the graph
##' @param algorithm Choices of algorithm include "MinCostArborescence".
##'   "MinCostArborescence" is the default.
##' @return A named list containing three entries: 1) "sources": a vector
##'   corresponding the source nodes of the edges in the tree, 2) "targets": a
##'   vector corresponding the target nodes of the edges in the tree, and 3)
##'   "cost": the total cost of the arborescence.
##' @export
MinCostArborescence <- function(arcSources,
                                arcTargets,
                                arcDistances,
                                sourceNode,
                                numNodes,
                                algorithm = "MinCostArborescence") {

  # Check graph invariants
  check_node(sourceNode, numNodes)
  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcDistances, numNodes)
  check_algorithm(algorithm)

  algfn <- switch(algorithm,
                  "MinCostArborescence" = MinCostArborescenceRunner,
                  stop("Invalid algorithm.")
                  )
  result <- algfn(arcSources, arcTargets, arcDistances, sourceNode, numNodes)
  names(result) <- c("sources", "targets", "cost")
  return(result)
}
