##' Checks if an undirected graph is bipartite and finds the bipartite
##' partitions.
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga58ba1d00c569f0eb0deb42afca9f80bb'
##' for more information.
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

##' Checks if a directed graph is a DAG and returns the topological order.
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gafc2cb20cf3859f157c0e12da7f310bb3'
##' for more information.
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

##' Gives back the topological order of a DAG.
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gafc2cb20cf3859f157c0e12da7f310bb3'
##' for more information.
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

##' Checks if an undirected graph is connected.
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gad5c8d1b650f6b614a852f8430d90e184'
##' for more information.
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

##' Checks if an undirected graph is acyclic.
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga14c191b2133a1dd23e1527f074c821c0'
##' for more information.
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

##' Checks if an undirected graph is a tree.
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gad1e4de234e926958647905478415bd54'
##' for more information.
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

##' Checks if an undirected graph is bipartite.
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga577db110d33bd487aaad5bfffb31c6f5'
##' for more information.
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

##' Checks if a directed graph is strongly connected.
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gacd21b34d7b42b9835a204a57fcf15964'
##' for more information.
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

##' Checks if a directed graph is a DAG.
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gaef2b43c8cd1d74e15fa5c7607bc5e396'
##' for more information.
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

##' Checks if an undirected graph is bi-node connected.
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga37d22a2ddd5a064a9203720f2b93518e'
##' for more information.
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

##' Checks if an undirected graph is bi-edge connected.
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga37d22a2ddd5a064a9203720f2b93518e'
##' for more information.
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
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga127f3963003cd532c79c226885fe1c8c'
##' for more information.
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
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gaa05e0683f90b69f31eb29fe7d09afde4'
##' for more information.
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
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gae4c7ae734e2509ab78dc747d602c9236'
##' for more information.
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
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gafb5a4961cac4d877006869fc4cb6ea1d'
##' for more information.
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
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gaf7c5744b2175210b8ea67897aaa27885'
##' for more information.
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
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga33a9d9d4803cb15e83568b2526e978a5'
##' for more information.
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
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gaf7c5744b2175210b8ea67897aaa27885'
##' for more information.
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
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gad30bc47dfffb78234eeee903cb3766f4'
##' for more information.
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
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga46f8c22f3e2989c4689faa4c46ec9436'
##' for more information.
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
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gad7af5c3a97453e37f251f0e86dbb83db'
##' for more information.
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
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga58d444eba448c5f1a53539bd1b69636e'
##' for more information.
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
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga9d70526ab54e10b4b6fe3762af8675dd'
##' for more information.
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
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga31461f33a748327ea3ef2a3199ffb6c7'
##' for more information.
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
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gaa467a3e0a8c2e9e762650fd01fadff89'
##' for more information.
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
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga76c1fdd1881d21677507100b7e96c983'
##' for more information.
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
