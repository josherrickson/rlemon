# Internal. Check graph inputs for common issues. Specifically checks if arc
# source, target, capacity, and cost arrays have the same length. Additionally,
# checks if all arc sources and targets are integral.
check_graph <- function(arcSources,
                        arcTargets,
                        arcCapacities,
                        arcCosts,
                        nodeSupplies,
                        numNodes) {

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

  invisible(TRUE) # if it passes all checks. `invisible` instead of `return`
                  # avoids printing anything out
}

# Internal. Check sources and target arrays for common errors. Specifically
# checks that graphs follow 1-indexing conventions, that the number of source
# and target nodes are the same, and that all node indices are integral.
check_graph_vertices <- function(arcSources,
                                 arcTargets,
                                 numNodes) {

  # Check that the arc number is consistent
  if (length(arcSources) != length(arcTargets)) {
    stop("Inconsistent number of arcs across Sources and Targets.")
  }

  # Check that no node is above the maximum
  if (!all(arcSources <= numNodes)) {
    stop(paste(
      "The arcSources vec contains vertices with indices greater",
      "than the number of nodes. rlemon is 1-indexed on the number",
      "of graph vertices, and will assume that the vertices in",
      "between exist"
    ))
  }

  if (!all(arcSources > 0)) {
    stop(paste(
      "The arcSources vec contains vertices with indices less than 1.",
      "rlemon is 1-indexed on the number of graph vertices, and will",
      "assume that the vertices in between exist"
    ))
  }


  if (!all(arcTargets <= numNodes)) {
    stop(paste(
      "The arcTargets vec contains vertices with indices greater than",
      " the number of nodes. rlemon is 1-indexed on the number of",
      "graph vertices, and will assume that the vertices in between",
      "exist"
    ))
  }

  if (!all(arcTargets > 0)) {
    stop(paste(
      "The arcTargets vec contains vertices with indices less than 1.",
      "rlemon is 1-indexed on the number of graph vertices, and will",
      "assume that the vertices in between exist"
    ))
  }

  # Checking that node identifiers are integers
  if (!all(arcSources == floor(arcSources)) |
      !all(arcTargets == floor(arcTargets))) {
    stop("Nodes must be integers")
  }

  invisible(TRUE)
}

# Internal. Check arc maps for common errors. Doesn't check if the underlying
# graph is correct - see `check_graph_vertices` for that purpose. Specifically
# checks if the number of arcs in the graph is the same as the number in the
# map.
check_arc_map <- function(arcSources,
                          arcTargets,
                          mapTest,
                          numNodes) {

  # Check that the arc number is consistent
  if (length(arcSources) != length(mapTest)) {
    stop(paste(
      "Inconsistent number of arcs across Sources and Arc Map",
      "(ArcWeights/ArcCapacities/ArcCosts)"
    ))
  }

  if (length(arcTargets) != length(mapTest)) {
    stop(paste(
      "Inconsistent number of arcs across Targets and Arc Map",
      "(ArcWeights/ArcCapacities/ArcCosts)"
    ))
  }

  invisible(TRUE)
}


# Check node maps for common errors. Doesn't check if the underlying graph is
# correct - see `check_graph_vertices` for that purpose. Specifically checks
# if the number of nodes is inconsistent.
check_node_map <- function(mapTest, numNodes) {

  # Check that the arc number is consistent
  if (length(mapTest) != numNodes) {
    stop("Inconsistent number of nodes in Node Map (NodeSupplies)")
  }

  invisible(TRUE)
}

# Internal. Check node definitions for common errors. Specifically, checks that all
# nodes are integral, and that they are consistent with 1-based indexing.
check_node <- function(testNode,
                       numNodes) {

  # Check that the arc number is consistent
  if (testNode != floor(testNode)) {
    stop("Node index given ( sourceNode/destNode ) not integral.")
  }

  if (testNode > numNodes) {
    stop("Node index given is out of range for graph instance. ")
  }

  if (testNode <= 0) {
    stop("Node index given is out of range for graph instance. ")
  }

  invisible(TRUE)
}


# Internal. Check arcs for common errors. Specifically, check that the number of
# source nodes is the same as the number of target nodes, and that all arc
# sources and targets are integral.
check_graph_arcs <- function(arcSources,
                             arcTargets) {

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

# Internal. Ensures algorithm is a string
check_algorithm <- function(algorithm) {

  # split into four redudant errors for coverage purposes
  if (is.null(algorithm)) {
    stop("`algorithm` must be a string")
  }
  if (!is.character(algorithm)) {
    stop("`algorithm` must be a string")
  }
  if (!is.null(dim(algorithm))) {
   stop("`algorithm` must be a string")
  }
  if (length(algorithm) > 1) {
    stop("`algorithm` must be string")
  }

  invisible(TRUE)
}
