##' Checks if an undirected graph is bipartite and finds the bipartite
##' partitions.
##'
##' See
##' \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga58ba1d00c569f0eb0deb42afca9f80bb}
##' for more information.
##' @title Obtains (if possible) Bipartite Split
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A list containing 1) A \code{logical} stating if the graph is
##'   bipartite, and 2) A vector of length \code{numNodes}, containing the
##'   partition for each node
##' @export
GetBipartitePartitions <- function(arcSources,
                                   arcTargets,
                                   numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  getBipartitePartitionsRunner(arcSources, arcTargets, numNodes)
}

##' Checks if a directed graph is a DAG and returns the topological order.
##'
##' See
##' \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gaf10c5e1630e5720c20d83cfb77dbf024}
##' for more information.
##' @title Check if Graph is DAG, then Sorts Nodes into Topological Order
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A list containing 1) A \code{logical} stating if the graph is a dag,
##'   and 2) A vector of length \code{numNodes}, containing the index of vertex
##'   i in the ordering at location i
##' @export
GetAndCheckTopologicalSort <- function(arcSources,
                                       arcTargets,
                                       numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  getAndCheckTopologicalSortRunner(arcSources, arcTargets, numNodes)
}

##' Gives back the topological order of a DAG.
##'
##' See
##' \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gafc2cb20cf3859f157c0e12da7f310bb3}
##' for more information.
##' @title Sorts Nodes into Topological Order
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A vector of length \code{numNodes}, containing the index of vertex i
##'   in the ordering at location i.
##' @export
GetTopologicalSort <- function(arcSources,
                               arcTargets,
                               numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  getTopologicalSortRunner(arcSources, arcTargets, numNodes)
}

##' A connected graph has a path between any two nodes in the graph.
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gad5c8d1b650f6b614a852f8430d90e184}
##' for more information.
##' @title Check if Graph is Connected
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A \code{logical} stating if the graph is connected
##' @export
IsConnected <- function(arcSources,
                        arcTargets,
                        numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  as.logical(IsConnectedRunner(arcSources, arcTargets, numNodes))
}

##' A cycle is a path starting and ending in the same node and containing at
##' least one other node. A acyclic graph contains no cycles.
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga14c191b2133a1dd23e1527f074c821c0}
##' for more information.
##' @title Check if Graph is Acyclic.
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A \code{logical} stating if the graph is acyclic
##' @export
IsAcyclic <- function(arcSources,
                      arcTargets,
                      numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  as.logical(IsAcyclicRunner(arcSources, arcTargets, numNodes))
}

##' A tree is an undirected graph in which any two nodes are connected by
##' exactly one path, or equivalently is both connected and acyclic.
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gad1e4de234e926958647905478415bd54}
##' for more information.
##' @title Check if Graph is a Tree
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A \code{logical} stating if the graph is a tree
##' @export
IsTree <- function(arcSources,
                   arcTargets,
                   numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  as.logical(IsTreeRunner(arcSources, arcTargets, numNodes))
}

##' A bipartite graph is one whose nodes can be divided into two disjoint and
##' independent sets such that edges only connecte between those two sets and
##' not within a set.
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga577db110d33bd487aaad5bfffb31c6f5}
##' for more information.
##' @title Checks if Graph is Bipartite
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A \code{logical} stating if the graph is bipartite
##' @export
IsBipartite <- function(arcSources,
                        arcTargets,
                        numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  as.logical(IsBipartiteRunner(arcSources, arcTargets, numNodes))
}

##' A directed graph is strongly connected if any two nodes are connected via
##' paths in both directions.
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gacd21b34d7b42b9835a204a57fcf15964}
##' for more information.
##' @title Check if Graph is Strongly Connected
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A \code{logical} stating if the graph is strongly connected
##' @export
IsStronglyConnected <- function(arcSources,
                                arcTargets,
                                numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  as.logical(IsStronglyConnectedRunner(arcSources, arcTargets, numNodes))
}

##' A graph is a DAG if it is Directed and Acyclic.
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gaef2b43c8cd1d74e15fa5c7607bc5e396}
##' for more information.
##' @title Check if Graph is a DAG.
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A \code{logical} stating if the graph is DAG
##' @export
IsDAG <- function(arcSources,
                  arcTargets,
                  numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  as.logical(IsDAGRunner(arcSources, arcTargets, numNodes))
}

##' Checks if an undirected graph is bi-node-connected, that is if there is are no
##' nodes which, if removed, would split the graph into two unconnected graphs.
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gac9257323ead7cbe64b7b4a628c4876b3}
##' for more information.
##' @title Checks if Graph is Bi-Node-Connected
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A \code{logical} stating if the graph is bi-node connected
##' @export
IsBiNodeConnected <- function(arcSources,
                              arcTargets,
                              numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  as.logical(IsBiNodeConnectedRunner(arcSources, arcTargets, numNodes))
}

##' Checks if an undirected graph is bi-edge-connected, that is if there are no
##' edges that, if removed, would split the graph into two unconnected graphs.
##'
##' See
##' \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga37d22a2ddd5a064a9203720f2b93518e}
##' for more information.
##' @title Chcek if Graph is Bi-Edge-Connected
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A \code{logical} stating if the graph is bi-edge connected
##' @export
IsBiEdgeConnected <- function(arcSources,
                              arcTargets,
                              numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  as.logical(IsBiEdgeConnectedRunner(arcSources, arcTargets, numNodes))
}

##' A loop is an edge that starts and ends at the same node and passes through
##' no other nodes.
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga127f3963003cd532c79c226885fe1c8c}
##' for more information.
##' @title Checks if Graph is Loop Free
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return TRUE if the graph is loop free, FALSE otherwise
##' @export
IsLoopFree <- function(arcSources,
                       arcTargets,
                       numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  as.logical(IsLoopFreeRunner(arcSources, arcTargets, numNodes))
}

##' Parallel edges occur when there are two edges between a single pair of nodes.
##'
##' See
##' \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gaa05e0683f90b69f31eb29fe7d09afde4}
##' for more information.
##' @title Check if Graph is Parallel Free
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return TRUE if the graph is parallel free, FALSE otherwise
##' @export
IsParallelFree <- function(arcSources,
                           arcTargets,
                           numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  as.logical(IsParallelFreeRunner(arcSources, arcTargets, numNodes))
}

##' A graph is simple if it is both loop free, and parallel free. See also
##' \code{IsLoopFree} and \code{IsParallelFree}.
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gae4c7ae734e2509ab78dc747d602c9236}
##' for more information.
##' @title Check if Graph is Simple
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return TRUE if graph is simple, FALSE otherwise.
##' @export
IsSimpleGraph <- function(arcSources,
                          arcTargets,
                          numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  as.logical(IsSimpleGraphRunner(arcSources, arcTargets, numNodes))
}

##' A directed graph is Eulerian if and only if it is connected and the number
##' of incoming and outgoing edges are the same for each node. An undirected
##' graph is Eulerian if and only if it is connected and the number of incident
##' edges is even for each node.
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gafb5a4961cac4d877006869fc4cb6ea1d}
##' for more information.
##' @title Check if Graph is Eulerian
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return TRUE if graph is Eulerian, FALSE otherwise
##' @export
IsEulerian <- function(arcSources,
                       arcTargets,
                       numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  as.logical(IsEulerianRunner(arcSources, arcTargets, numNodes))
}

##' Counts the number of bi-edge-connected components in an undirected graph.
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga4d5db78dc21099d075c3967484990954}
##' for more information.
##' @title Count Number of Bi-Edge-Connected Components
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return An integer defining the number of bi-edge-connected components
##' @export
CountBiEdgeConnectedComponents <- function(arcSources,
                                           arcTargets,
                                           numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  CountBiEdgeConnectedComponentsRunner(arcSources, arcTargets, numNodes )
}

##' Counts the number of bi-node-connected components in an undirected graph.
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gaf7c5744b2175210b8ea67897aaa27885}
##' for more information.
##' @title Count Number of Bi-Node-Connected Components
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return An integer defining the number of bi-node-connected components
##' @export
CountBiNodeConnectedComponents <- function(arcSources,
                                           arcTargets,
                                           numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  CountBiNodeConnectedComponentsRunner(arcSources, arcTargets, numNodes)
}

##' The connected components are the classes of an equivalence relation on the
##' nodes of an undirected graph. Two nodes are in the same class if they are
##' connected with a path.
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga33a9d9d4803cb15e83568b2526e978a5}
##' for more information.
##' @title Count the Number of Connected Components
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

  CountConnectedComponentsRunner(arcSources, arcTargets, numNodes)
}


##' The strongly connected components are the classes of an equivalence relation
##' on the nodes of a directed graph. Two nodes are in the same class if they
##' are connected with directed paths in both direction.
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gad30bc47dfffb78234eeee903cb3766f4}
##' for more information.
##' @title Count the Number of Strongly Connected Components
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

  CountStronglyConnectedComponentsRunner(arcSources, arcTargets, numNodes)
}

##' The strongly connected components are the classes of an equivalence relation
##' on the nodes of a directed graph. Two nodes are in the same class if they
##' are connected with directed paths in both direction.
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga46f8c22f3e2989c4689faa4c46ec9436}
##' for more information.
##' @title Find Strongly Connected Components
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A vector containing the node id of each strongly connected component.
##' @export
FindStronglyConnectedComponents <- function(arcSources,
                                            arcTargets,
                                            numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  FindStronglyConnectedComponentsRunner(arcSources, arcTargets, numNodes)
}

##' The strongly connected components are the classes of an equivalence relation
##' on the nodes of a directed graph. Two nodes are in the same class if they
##' are connected with directed paths in both direction. The strongly connected
##' components are separated by the cut arcs.
##'
##' See
##' \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gad7af5c3a97453e37f251f0e86dbb83db}
##' for more information.
##' @title Find Strongly Connected Cut Arcs
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A list containing 1) A vector of cut arc sources, and 2) A vector of
##'   cut arc destinations.
##' @export
FindStronglyConnectedCutArcs <- function(arcSources,
                                         arcTargets,
                                         numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  FindStronglyConnectedCutArcsRunner(arcSources, arcTargets, numNodes)
}

##' The bi-edge-connected components are the classes of an equivalence relation
##' on the nodes of an undirected graph. Two nodes are in the same class if they
##' are connected with at least two edge-disjoint paths. The bi-edge-connected
##' components are separted by the cut edges of the components.
##'
##' See
##' \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga58d444eba448c5f1a53539bd1b69636e}
##' for more information.
##' @title Find Bi-Edge-Connected Cut Edges
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A list containing 1) A vector of cut edge sources, and 2) A vector
##'   of cut edge destinations.
##' @export
FindBiEdgeConnectedCutEdges <- function(arcSources,
                                        arcTargets,
                                        numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  FindBiEdgeConnectedCutEdgesRunner(arcSources, arcTargets, numNodes)
}

##' The bi-node-connected components are the classes of an equivalence relation
##' on the edges of a undirected graph. Two edges are in the same class if they
##' are on same circle.
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga9d70526ab54e10b4b6fe3762af8675dd}
##' for more information.
##' @title Find Bi-Node-Connected Components
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A vector containing the arc id of each bi-node-connected component
##' @export
FindBiNodeConnectedComponents <- function(arcSources,
                                          arcTargets,
                                          numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  FindBiNodeConnectedComponentsRunner(arcSources, arcTargets, numNodes)
}

##' The bi-node-connected components are the classes of an equivalence relation
##' on the edges of a undirected graph. Two edges are in the same class if they
##' are on same circle.
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga31461f33a748327ea3ef2a3199ffb6c7}
##' for more information.
##' @title Find Bi-Node-Connected Cut Nodes
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A vector containing the cut nodes.
##' @export
FindBiNodeConnectedCutNodes <- function(arcSources,
                                        arcTargets,
                                        numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  FindBiNodeConnectedCutNodesRunner(arcSources, arcTargets, numNodes)
}

##' The connected components are the classes of an equivalence relation on the
##' nodes of an undirected graph. Two nodes are in the same class if they are
##' connected with a path.
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gaa467a3e0a8c2e9e762650fd01fadff89}
##' for more information.
##' @title Find Connected Components
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A vector containing the node id of each connected component.
##' @export
FindConnectedComponents <- function(arcSources,
                                    arcTargets,
                                    numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  FindConnectedComponentsRunner(arcSources, arcTargets, numNodes)
}

##' The bi-edge-connected components are the classes of an equivalence relation
##' on the nodes of an undirected graph. Two nodes are in the same class if they
##' are connected with at least two edge-disjoint paths.
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga76c1fdd1881d21677507100b7e96c983}
##' for more information.
##' @title Find Bi-Edge-Connected Components
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A vector containing the node id of each bi-edge-connected component.
##' @export
FindBiEdgeConnectedComponents <- function(arcSources,
                                          arcTargets,
                                          numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  FindBiEdgeConnectedComponentsRunner(arcSources, arcTargets, numNodes)
}
