##' Runs MST (Minimum Spanning Tree) algorithms on graphs.
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
##'   <http://lemon.cs.elte.hu/pub/doc/1.3.1/a00610.html> for details on the
##'   differences.
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
           .Call(`_rlemon_KruskalRunner`, arcSources, arcTargets, arcDistances,
                 numNodes),
         stop("Invalid algorithm.")
         )
}


##' Runs Minimum Cost Arborescence algorithms on graphs.
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
##'   <http://lemon.cs.elte.hu/pub/doc/1.3.1/a00610.html> for details on the
##'   differences.
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
           .Call(`_rlemon_MinCostArborescenceRunner`, arcSources, arcTargets,
                 arcDistances, sourceNode, numNodes),
         stop("Invalid algorithm.")
         )
}
