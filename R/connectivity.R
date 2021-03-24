##' Checks if an undirected graph is bipartite and returns the bipartite
##' partitions
##'
##' @title GetBipartitePartitions
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A list containing 1) A boolean stating if the graph is bipartite,
##'   and 2) A list of length numNodes, containing the partition for each node
##' @export
GetBipartitePartitions <- function(arcSources,
                                   arcTargets,
                                   numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(
    `_rlemon_getBipartitePartitionsRunner`, arcSources, arcTargets,
    numNodes
  )
}

##' Checks if a directed graph is a DAG and returns the topological order
##'
##' @title GetAndCheckTopologicalSort
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A list containing 1) A boolean stating if the graph is a dag, and 2)
##'   A vector of length numNodes, containing the index of vertex i in the
##'   ordering at location i
##' @export
GetAndCheckTopologicalSort <- function(arcSources,
                                       arcTargets,
                                       numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(
    `_rlemon_getAndCheckTopologicalSortRunner`, arcSources, arcTargets,
    numNodes
  )
}

##' Gives back the topological order of a DAG
##'
##' @title GetTopologicalSort
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A list of length numNodes, containing the index of vertex i in the
##'   ordering at location i.
##' @export
GetTopologicalSort <- function(arcSources,
                               arcTargets,
                               numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(`_rlemon_getTopologicalSortRunner`, arcSources, arcTargets, numNodes)
}

##' Checks if an undirected graph is connected
##'
##' @title IsConnected
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A boolean stating if the graph is connected
##' @export
IsConnected <- function(arcSources,
                        arcTargets,
                        numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(`_rlemon_IsConnectedRunner`, arcSources, arcTargets, numNodes)
}

##' Checks if an undirected graph is acyclic
##'
##' @title IsAcylic
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A boolean stating if the graph is acyclic
##' @export
IsAcyclic <- function(arcSources,
                      arcTargets,
                      numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(`_rlemon_IsAcyclicRunner`, arcSources, arcTargets, numNodes)
}

##' Checks if an undirected graph is a tree
##'
##' @title IsTree
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A boolean stating if the graph is a tree
##' @export
IsTree <- function(arcSources,
                   arcTargets,
                   numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(`_rlemon_IsTreeRunner`, arcSources, arcTargets, numNodes)
}

##' Checks if an undirected graph is bipartite
##'
##' @title IsBipartite
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A boolean stating if the graph is bipartite
##' @export
IsBipartite <- function(arcSources,
                        arcTargets,
                        numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(`_rlemon_IsBipartiteRunner`, arcSources, arcTargets, numNodes)
}

##' Checks if a directed graph is strongly connected
##'
##' @title IsStronglyConnected
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A boolean stating if the graph is strongly connected
##' @export
IsStronglyConnected <- function(arcSources,
                                arcTargets,
                                numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(`_rlemon_IsStronglyConnectedRunner`, arcSources, arcTargets, numNodes)
}

##' Checks if a directed graph is a DAG
##'
##' @title IsDAG
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A boolean stating if the graph is DAG
##' @export
IsDAG <- function(arcSources,
                  arcTargets,
                  numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(`_rlemon_IsDAGRunner`, arcSources, arcTargets, numNodes)
}

##' Checks if an undirected graph is bi-node connected
##'
##' @title IsBiNodeConnected
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A boolean stating if the graph is bi-node connected
##' @export
IsBiNodeConnected <- function(arcSources,
                              arcTargets,
                              numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(`_rlemon_IsBiNodeConnectedRunner`, arcSources, arcTargets, numNodes)
}

##' Checks if an undirected graph is bi-edge connected
##'
##' @title IsBiEdgeConnected
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A boolean stating if the graph is bi-edge connected
##' @export
IsBiEdgeConnected <- function(arcSources,
                              arcTargets,
                              numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(`_rlemon_IsBiEdgeConnectedRunner`, arcSources, arcTargets, numNodes)
}

##' Checks if a graph is loop free. Works for both undirected and directed
##' graphs.
##'
##' @title IsLoopFree
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A boolean stating if the graph is loop free
##' @export
IsLoopFree <- function(arcSources,
                       arcTargets,
                       numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(`_rlemon_IsLoopFreeRunner`, arcSources, arcTargets, numNodes)
}

##' Checks if a graph has no parallel arcs/edges. Works for both undirected and
##' directed graphs.
##'
##' @title IsParallelFree
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A boolean stating if the graph is loop free
##' @export
IsParallelFree <- function(arcSources,
                           arcTargets,
                           numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(`_rlemon_IsParallelFreeRunner`, arcSources, arcTargets, numNodes)
}

##' Checks if a graph is simple, i.e. it contains no loop arcs/edges and no
##' parallel arcs/edges. Works for both undirected and directed graphs.
##'
##' @title IsSimpleGraph
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A boolean stating if the graph is simple
##' @export
IsSimpleGraph <- function(arcSources,
                          arcTargets,
                          numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(`_rlemon_IsSimpleGraphRunner`, arcSources, arcTargets, numNodes)
}

##' Checks if a graph is Eulerian. Works for both undirected and directed
##' graphs.
##'
##' @title IsEulerian
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A boolean stating if the graph is Eulerian
##' @export
IsEulerian <- function(arcSources,
                       arcTargets,
                       numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(`_rlemon_IsEulerianRunner`, arcSources, arcTargets, numNodes)
}

##' Counts the number of bi-edge connected components in an undirected graph.
##'
##' @title CountBiEdgeConnectedComponents
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return An integer defining the number of bi-node connected components
##' @export
CountBiEdgeConnectedComponents <- function(arcSources,
                                           arcTargets,
                                           numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(
    `_rlemon_CountBiEdgeConnectedComponentsRunner`, arcSources, arcTargets,
    numNodes
  )
}

##' Counts the number of connected components in an undirected graph.
##'
##' @title CountConnectedComponents
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return An integer defining the number of connected components
##' @export
CountConnectedComponents <- function(arcSources,
                                     arcTargets,
                                     numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(
    `_rlemon_CountConnectedComponentsRunner`, arcSources, arcTargets,
    numNodes
  )
}

##' Counts the number of bi-node connected components in an undirected graph.
##'
##' @title CountBiNodeConnectedComponents
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return An integer defining the number of bi-node connected components
##' @export
CountBiNodeConnectedComponents <- function(arcSources,
                                           arcTargets,
                                           numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(
    `_rlemon_CountBiNodeConnectedComponentsRunner`, arcSources, arcTargets,
    numNodes
  )
}

##' Counts the number of strongly connected components in a directed graph.
##'
##' @title CountStronglyConnectedComponents
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return An integer defining the number of strongly connected components
##' @export
CountStronglyConnectedComponents <- function(arcSources,
                                             arcTargets,
                                             numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(
    `_rlemon_CountStronglyConnectedComponentsRunner`, arcSources,
    arcTargets, numNodes
  )
}

##' Finds the strongly connected components in a directed graph.
##'
##' @title FindStronglyConnectedComponents
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A list containing the node id of each strongly connected component.
##' @export
FindStronglyConnectedComponents <- function(arcSources,
                                            arcTargets,
                                            numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(
    `_rlemon_FindStronglyConnectedComponentsRunner`, arcSources, arcTargets,
    numNodes
  )
}

##' Finds the cut arcs of strongly connected components in a directed graph.
##'
##' @title FindStronglyConnectedCutArcs
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A list containing 1) A list of cut arc sources, and 2) A list of cut
##'   arc destinations.
##' @export
FindStronglyConnectedCutArcs <- function(arcSources,
                                         arcTargets,
                                         numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(
    `_rlemon_FindStronglyConnectedCutArcsRunner`, arcSources, arcTargets,
    numNodes
  )
}

##' Finds the bi-edge-connected cut edges in an undirected graph.
##'
##' @title FindBiEdgeConnectedCutEdges
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A list containing 1) A list of cut arc sources, and 2) A list of cut
##'   arc destinations.
##' @export
FindBiEdgeConnectedCutEdges <- function(arcSources,
                                        arcTargets,
                                        numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(
    `_rlemon_FindBiEdgeConnectedCutEdgesRunner`, arcSources, arcTargets,
    numNodes
  )
}

##' Finds the bi-node-connected components of an undirected graph.
##'
##' @title FindBiNodeConnectedComponents
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A list containing the arc id of each cut arc.
##' @export
FindBiNodeConnectedComponents <- function(arcSources,
                                          arcTargets,
                                          numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(
    `_rlemon_FindBiNodeConnectedComponentsRunner`, arcSources, arcTargets,
    numNodes
  )
}

##' Finds the bi-node-connected cut nodes in an undirected graph.
##'
##' @title FindBiNodeConnectedCutNodes
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A list containing the cut nodes.
##' @export
FindBiNodeConnectedCutNodes <- function(arcSources,
                                        arcTargets,
                                        numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(
    `_rlemon_FindBiNodeConnectedCutNodesRunner`, arcSources, arcTargets,
    numNodes
  )
}

##' Finds the connected components in an undirected graph.
##'
##' @title FindConnectedComponents
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A list containing the node id of each connected component.
##' @export
FindConnectedComponents <- function(arcSources,
                                    arcTargets,
                                    numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(
    `_rlemon_FindConnectedComponentsRunner`, arcSources, arcTargets,
    numNodes
  )
}

##' Finds the bi-edge-connected components of an undirected graph.
##'
##' @title FindBiEdgeConnectedComponents
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A list containing the node id of each bi-edge-connected component.
##' @export
FindBiEdgeConnectedComponents <- function(arcSources,
                                          arcTargets,
                                          numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(
    `_rlemon_FindBiEdgeConnectedComponentsRunner`, arcSources, arcTargets,
    numNodes
  )
}
