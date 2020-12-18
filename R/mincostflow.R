##' Runs mincostflow algorithms on graphs.
##'
##' @title MinCostFlow
##' @param arcSources, a vector corresponding to the source nodes of a graph's edges
##' @param arcTargets, a vector corresponding to the destination nodes of a graph's edges
##' @param arcCapacities, a vector corresponding to the capacities of nodes of a graph's edges
##' @param arcCosts, a vector corresponding to the capacities of nodes of a graph's edges
##' @param nodeSupplies, a vector corresponding to the supplies of each node
##' @param numNodes, the number of nodes in the graph
##' @param algorithm Which algorithm to run. Choices include
##'   "NetworkSimplex", "CostScaling", "CapacityScaling",
##'   "CycleCancelling". NetworkSimplex is the default; see
##'   <http://lemon.cs.elte.hu/pub/doc/1.3.1/a00612.html> for details
##'   on the differences.
##' @return A list containing three entries: 1) A list corresponding to the flows of arcs in the graph, 2) A list of potentials of the graph's nodes, and 3) the total cost of the flows in the graph, i.e. the mincostflow value
##' @export
mincostflow <- function(arcSources, arcTargets, arcCapacities, arcCosts, nodeSupplies, numNodes, algorithm) {

  check_graph(arcSources, arcTargets, arcCapacities, arcCosts, nodeSupplies, numNodes)

  switch(algorithm,
         "NetworkSimplex" = .Call(`_rlemon_NetworkSimplexRunner`, arcSources, arcTargets, arcCapacities, arcCosts, nodeSupplies, numNodes),
         "CostScaling" = .Call(`_rlemon_CostScalingRunner`, arcSources, arcTargets, arcCapacities, arcCosts, nodeSupplies, numNodes),
         "CapacityScaling" = .Call(`_rlemon_CapacityScalingRunner`, arcSources, arcTargets, arcCapacities, arcCosts, nodeSupplies, numNodes),
         "CycleCancelling" = .Call(`_rlemon_CycleCancellingRunner`, arcSources, arcTargets, arcCapacities, arcCosts, nodeSupplies, numNodes))
}
