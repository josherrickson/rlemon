##' Runs MST (Minimum Spanning Tree) algorithms on graphs.
##'
##' @title minimumspanningtree
##' @param arcSources, a vector corresponding to the source nodes of a graph's edges
##' @param arcTargets, a vector corresponding to the destination nodes of a graph's edges
##' @param arcDistances, a vector corresponding to the distances of nodes of a graph's edges
##' @param sourceNode, the source node (only used for MinCostArborescence)
##' @param numNodes, the number of nodes in the graph
##' @param algorithm Which algorithm to run. Choices include
##'   "Kruskal", "MinCostArborescence"
##'   where "Kruskal" is the default.
##'   See <http://lemon.cs.elte.hu/pub/doc/1.3.1/a00610.html> 
##'   for details on the differences.
##' @return A list containing three entries: 1) Two vectors corresponding the source and target nodes of the edges in the tree, and 2) the total minimum spanning tree value.
##' @export
minimummspanningtree <- function(arcSources, arcTargets, arcDistances, numNodes, algorithm="Kruskal",sourceNode=NULL) {

  #Ensure optional args are satisfied
  if(algorithm=="MinCostArborescence" && is.null(sourceNode)) {
    stop("Need to specify sourceNode to run MinCostArborescence")
  }

  # Check graph invariants
  if(!is.null(sourceNode)) {
    check_node(sourceNode, numNodes)
  }
  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcDistances, numNodes)
  

  switch(algorithm,
         "Kruskal" = .Call(`_rlemon_KruskalRunner`,arcSources, arcTargets, arcDistances, numNodes),
         "MinCostArborescence" = .Call(`_rlemon_MinCostArborescenceRunner`,arcSources, arcTargets, arcDistances, numNodes))}
