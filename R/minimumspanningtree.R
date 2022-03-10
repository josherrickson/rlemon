##' Finds the minimum spanning tree of a graph.
##' The minimum spanning tree is the minimal connected acyclic subgraph of a graph,
##' assuming the graph is undirected.
##'
##'
##' @title MinSpanningTree
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcDistances Vector corresponding to the distances of nodes of a
##'   graph's edges
##' @param numNodes The number of nodes in the graph
##' @param algorithm Which algorithm to run. Choices include "Kruskal" where
##'   "Kruskal" is the default. See
##'   <https://lemon.cs.elte.hu/pub/doc/1.3.1/a00610.html#ga233792b2c44a3581b85a775703e045af>
##'   for more information.
##' @return A list containing three entries: 1) Two vectors corresponding the
##'   source and target nodes of the edges in the tree, and 2) the total minimum
##'   spanning tree value.
##' @export
MinSpanningTree <- function(arcSources,
                            arcTargets,
                            arcDistances,
                            numNodes,
                            algorithm = "Kruskal") {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcDistances, numNodes)


  switch(algorithm,
    "Kruskal" =
      .Call(
        `_rlemon_KruskalRunner`, arcSources, arcTargets, arcDistances,
        numNodes
      ),
    stop("Invalid algorithm.")
  )
}


##' Finds the minimum cost arborescence of a graph, returning both the cost and
##' the pairs of nodes for the edges in the arborescence.
##'
##' @title MinCostArborescence
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcDistances Vector corresponding to the distances of nodes of a
##'   graph's edges
##' @param sourceNode The source node
##' @param numNodes The number of nodes in the graph
##' @param algorithm Which algorithm to run. Choices include
##'   "MinCostArborescence" where "MinCostArborescence" is the default. See
##'   <https://lemon.cs.elte.hu/pub/doc/1.3.1/a00264.html> for more information.
##' @return A list containing three entries: 1) Two vectors corresponding the
##'   source and target nodes of the edges in the tree, and 2) the total cost of
##'   the arborescence.
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


  switch(algorithm,
    "MinCostArborescence" =
      .Call(
        `_rlemon_MinCostArborescenceRunner`, arcSources, arcTargets,
        arcDistances, sourceNode, numNodes
      ),
    stop("Invalid algorithm.")
  )
}
