##' Checks weather an undirected graph is bipartite and gives back the bipartite partitions
##'
##' @title GetBipartitePartitions
##' @param arcSources Vector corresponding to the source nodes of a graph's edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's edges
##' @param numNodes The number of nodes in the graph
##' @param problem What type of problem you want to run. Choices include
##'   "getBipartitePartitions" 
##'   where "getBipartitePartitions" is the default.
##'   See <http://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#ga58ba1d00c569f0eb0deb42afca9f80bb> 
##'   for details on the differences.
##' @return A list containing two entries:(1) A boolean stating if the graph is bipartite, and (2) a list of length numNodes, containing the partition for each node
##' @export
getBipartitePartitions <- function(arcSources, arcTargets, numNodes, problem="getBipartitePartitions") {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  switch(problem,
         "getBipartitePartitions" = .Call(`_rlemon_getBipartitePartitionsRunner`,arcSources, arcTargets, numNodes),
         stop("Invalid algorithm."))
}

##' Checks weather a directed graph is a DAG and gives back the topological order
##'
##' @title GetAndCheckTopologicalSort
##' @param arcSources Vector corresponding to the source nodes of a graph's edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's edges
##' @param numNodes The number of nodes in the graph
##' @param problem What type of problem you want to run. Choices include
##'   "getAndCheckTopologicalSort" 
##'   where "getAndCheckTopologicalSort" is the default.
##'   See <http://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gaf10c5e1630e5720c20d83cfb77dbf024> 
##'   for details on the differences.
##' @return A list containing two entries:(1) A boolean stating if the graph is a dag, and (2) a vector of length numNodes, containing the index of vertex i in the ordering at location i
##' @export
getAndCheckTopologicalSort <- function(arcSources, arcTargets, numNodes, problem="getAndCheckTopologicalSort") {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  switch(problem,
         "getAndCheckTopologicalSort" = .Call(`_rlemon_getAndCheckTopologicalSortRunner`,arcSources, arcTargets, numNodes),
         stop("Invalid algorithm."))
}

##' Gives back the topological order of a DAG
##'
##' @title GetTopologicalSort
##' @param arcSources Vector corresponding to the source nodes of a graph's edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's edges
##' @param numNodes The number of nodes in the graph
##' @param problem What type of problem you want to run. Choices include
##'   "getTopologicalSort" 
##'   where "getTopologicalSort" is the default.
##'   See <http://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gafc2cb20cf3859f157c0e12da7f310bb3> 
##'   for details on the differences.
##' @return A list containing one entry:(1) A vector of length numNodes, containing the index of vertex i in the ordering at location i.
##' @export
getTopologicalSort <- function(arcSources, arcTargets, numNodes, problem="getTopologicalSort") {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  switch(problem,
         "getTopologicalSort" = .Call(`_rlemon_getTopologicalSortRunner`,arcSources, arcTargets, numNodes),
         stop("Invalid algorithm."))
}

