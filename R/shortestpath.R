##' Runs maxflow algorithms on graphs.
##'
##' @title ShortestPath
##' @param arcSources, a vector corresponding to the source nodes of a graph's edges
##' @param arcTargets, a vector corresponding to the destination nodes of a graph's edges
##' @param arcDistances, a vector corresponding to the distances of a graph's edges
##' @param numNodes, the number of nodes in the graph
##' @param sourceNode, the start node of the path
##' @param destNode, the end node of the path
##' @param algorithm Which algorithm to run. Choices include
##'   "Suurballe", "Dijkstra", "BellmanFord"
##'   where "Dijkstra" is the default.
##'   See <http://lemon.cs.elte.hu/pub/doc/1.3.1/a00608.html>
##'   for details on the differences.
##' @return  "BellmanFord" and "Dijktra" return a list containing two entries: 1) the distances from each node to the startNode and 2) the predecessor of each vertex in its shortest path. "Suurballe" returns A list containing two entries: 1) the number of paths from the start node to the end node and 2) a list of paths found.
##' @export
shortestpath <- function(arcSources, arcTargets, arcDistances, sourceNode, numNodes, algorithm="Dijkstra", destNode=-1) {

  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcDistances, numNodes)
  check_node(sourceNode,numNodes)
  if(destNode != -1){
    check_node(destNode, numNodes)
  }
  if(destNode == -1 & algorithm=="Suurballe") {
    stop("Need to specify destNode to run Suurballe")
  }
  switch(algorithm,
         "Dijkstra" = .Call(`_rlemon_DijkstraRunner`,arcSources, arcTargets, arcDistances, numNodes, sourceNode),
         "Suurballe" = .Call(`_rlemon_SuurballeRunner`,arcSources, arcTargets, arcDistances, numNodes, sourceNode, destNode),
         "BellmanFord" = .Call(`_rlemon_BellmanFordRunner`, arcSources, arcTargets, arcDistances, numNodes, sourceNode))


}
