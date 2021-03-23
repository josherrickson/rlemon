##' Check graph for common issues.
##'
##' @param arcSources Arc sources
##' @param arcTargets Arc targets
##' @param arcCapacities Arc capacities
##' @param arcCosts Arc costs
##' @param nodeSupplies Node supplies
##' @param numNodes Number of nodes
##' @return TRUE if no errors are found.
##' @export
check_graph <- function(arcSources, arcTargets, arcCapacities, arcCosts, nodeSupplies, numNodes) {
  # Checking that arc number is consistent
  if (length(arcSources) != length(arcTargets) |
      length(arcSources) != length(arcCapacities) |
      length(arcSources) != length(arcCosts) |
        length(arcSources) != length(arcCapacities)) {
    stop("Inconsistent number of arcs across Sources/Targets/Capacities/Costs")
  }

  # Checking that node identifiers are integers
  if (!all(arcSources == floor(arcSources)) |
      !all(arcTargets == floor(arcTargets))) {
    stop("Nodes must be integers")
  }

  invisible(TRUE) # if it passes all checks. `invisible` instead of `return` avoids printing anything out
}

##' Check sources and target arrays for common errors.
##'
##' @param arcSources Arc sources 
##' @param arcTargets Arc Targets
##' @param numNodes Number of nodes
##' @return TRUE if no errors are found
##' export
check_graph_vertices <- function(arcSources, arcTargets, numNodes) {
  # Check that the arc number is consistent
  if (length(arcSources) != length(arcTargets)) {
    stop("Inconsistent number of arcs across Sources and Targets.")
  }
  # Check that no node is above the maximum
  if (!all(arcSources <= numNodes)) {
    stop("The arcSources vec contains vertices with indices greater than the number of nodes. rLEMON is 1-indexed on the number of graph vertices, and will assume that the vertices in between exist")
  }

  if (!all(arcTargets > 0)) {
  stop("The arcTargets vec contains vertices with indices less than 1. rLEMON is 1-indexed on the number of graph vertices, and will assume that the vertices in between exist")
  }


  # Checking that node identifiers are integers
  if (!all(arcSources == floor(arcSources)) |
      !all(arcTargets == floor(arcTargets))) {
    stop("Nodes must be integers")
  }

  invisible(TRUE)

}

##' Check arc maps for common errors. 
##' Doesn't check if the underlying graph is correct - see `check_graph_vertices`
##'
##' @param arcSources Arc sources 
##' @param arcTargets Arc Targets
##' @param mapTest Arc Map to Test
##' @param numNodes Number of nodes
##' @return TRUE if no errors are found
##' export
check_arc_map <- function(arcSources, arcTargets, mapTest, numNodes) {
  # Check that the arc number is consistent
  if (length(arcSources) != length(mapTest)) {
    print(length(arcSources))
    print(length(mapTest))
    stop("Inconsistent number of arcs across Sources and Arc Map (ArcWeights/ArcCapacities/ArcCosts)")
  }
  if (length(arcTargets) != length(mapTest)) {
    stop("Inconsistent number of arcs across Targets and Arc Map (ArcWeights/ArcCapacities/ArcCosts)")
  }
  invisible(TRUE)

}


##' Check node maps for common errors. 
##' Doesn't check if the underlying graph is correct - see `check_graph_vertices`
##'
##' @param mapTest Node Map to Test
##' @param numNodes Number of nodes
##' @return TRUE if no errors are found
##' export
check_node_map <- function(mapTest, numNodes) {
  # Check that the arc number is consistent
  if (length(mapTest) != numNodes) {
    stop("Inconsistent number of nodes in Node Map (NodeSupplies)")
  }
  invisible(TRUE)

}

##' Check node definitions for common errors
##'
##' @param testNode Node to test
##' @param numNodes Number of nodes
##' @return TRUE if no errors are found
##' export
check_node <- function(testNode, numNodes) {
  # Check that the arc number is consistent
  if (testNode != floor(testNode)){
    stop("Node index given ( sourceNode/destNode ) not integral.")
  }
  if (testNode >= numNodes){
    stop("Node index given is out of range for graph instance. ")
  }
  invisible(TRUE)

}


##' Check arcs for common errors.
##'
##' @param arcSources Arc sources 
##' @param arcTargets Arc Targets
##' @return TRUE if no errors are found
##' export
check_graph_arcs <- function(arcSources, arcTargets) {
  # Check that the arc number is consistent
  if (length(arcSources) != length(arcTargets)) {
    stop("Inconsistent number of arcs across Sources and Targets.")
  }

  # Checking that node identifiers are integers
  if (!all(arcSources == floor(arcSources)) |
      !all(arcTargets == floor(arcTargets))) {
    stop("Nodes must be integers")
  }

  invisible(TRUE)

}