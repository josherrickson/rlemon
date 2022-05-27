##' Finds the minimum cost flow of a directed graph.
##'
##' For details on LEMON's implementation, including differences between the
##' algorithms, see \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00612.html}.
##' @title Solver for MinCostFlow
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param arcCapacities Vector corresponding to the capacities of nodes of a
##'   graph's edges
##' @param arcCosts Vector corresponding to the capacities of nodes of a graph's
##'   edges
##' @param nodeSupplies Vector corresponding to the supplies of each node
##' @param numNodes The number of nodes in the graph
##' @param algorithm Choices of algorithm include "NetworkSimplex",
##'   "CostScaling", "CapacityScaling", and "CycleCancelling". NetworkSimplex is
##'   the default.
##' @return A named list containing four entries: 1) "flows": A vector
##'   corresponding to the flows of arcs in the graph, 2) "potentials": A vector
##'   of potentials of the graph's nodes, 3) "cost": the total cost of the flows
##'   in the graph, i.e. the mincostflow value, and 4) "feasibility": LEMON's
##'   feasibility type, demonstrating how feasible the graph problem is, one of
##'   "INFEASIBLE", "OPTIMAL", and "UNBOUNDED"
##' @export
MinCostFlow <- function(arcSources,
                        arcTargets,
                        arcCapacities,
                        arcCosts,
                        nodeSupplies,
                        numNodes,
                        algorithm = "NetworkSimplex") {

  check_graph(
    arcSources, arcTargets, arcCapacities, arcCosts, nodeSupplies,
    numNodes
  )
  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_arc_map(arcSources, arcTargets, arcCapacities, numNodes)
  check_arc_map(arcSources, arcTargets, arcCosts, numNodes)
  check_arc_map(arcSources, arcTargets, arcCosts, numNodes)
  check_node_map(nodeSupplies, numNodes)
  check_algorithm(algorithm)

  algfn <- switch(algorithm,
                  "NetworkSimplex" = NetworkSimplexRunner,
                  "CostScaling" = CostScalingRunner,
                  "CapacityScaling" = CapacityScalingRunner,
                  "CycleCancelling" = CycleCancellingRunner,
                  stop("Invalid algorithm.")
                  )
  result <- algfn(arcSources, arcTargets, arcCapacities,
                  arcCosts, nodeSupplies, numNodes)
  names(result) <- c("flows", "potentials", "cost", "feasibility")
  return(result)
}
