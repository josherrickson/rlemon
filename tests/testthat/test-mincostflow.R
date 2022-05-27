# Title            : Min Cost Flow
# File             : R/mincostflow.R
# Exported         : MinCostFlow
# Valid Algorithms : "NetworkSimplex" (default), "CostScaling",
#                    "CapacityScaling", "CycleCancelling"
# Runners          : NetworkSimplexRunner, CostScalingRunner,
#                    CapacityScalingRunner, CycleCancellingRunner

test_mincostflow <- function(o, s, n, names = TRUE) {
  expect_true(is.list(o))
  expect_length(o, 4)
  expect_true(all(vapply(o[1:3], is.numeric, TRUE)))
  expect_equal(length(o[[1]]), length(s))
  expect_length(o[[2]], n)
  expect_length(o[[3]], 1)
  expect_true(o[[3]] > 0)
  expect_true(o[[4]] %in% c("INFEASIBLE", "OPTIMAL", "UNBOUNDED"))
  if (names) {
    expect_named(o, c("flows", "potentials", "cost", "feasibility"))
  }
}

# 1) Ensure runner functions run without error and return the "expected
# objects".
test_that("min cost flow runners", {

  s <- small_graph_example$startnodes
  t <- small_graph_example$endnodes
  cap <- small_graph_example$arccapacity
  costs <- small_graph_example$arccosts
  n <- small_graph_example$nodedemand
  numNodes <- 34

  out <- NetworkSimplexRunner(s, t, cap, costs, n, numNodes)
  test_mincostflow(out, s, numNodes, names = FALSE)

  out <- CostScalingRunner(s, t, cap, costs, n, numNodes)
  test_mincostflow(out, s, numNodes, names = FALSE)

  out <- CapacityScalingRunner(s, t, cap, costs, n, numNodes)
  test_mincostflow(out, s, numNodes, names = FALSE)

  out <- CycleCancellingRunner(s, t, cap, costs, n, numNodes)
  test_mincostflow(out, s, numNodes, names = FALSE)

})

test_that("min cost flow function", {

  s <- small_graph_example$startnodes
  t <- small_graph_example$endnodes
  cap <- small_graph_example$arccapacity
  costs <- small_graph_example$arccosts
  n <- small_graph_example$nodedemand
  numNodes <- 34

  # 2) Ensure exported functions run without error and return the "expected
  # objects".
  out <- MinCostFlow(s, t, cap, costs, n, numNodes)
  test_mincostflow(out, s, numNodes)

  # 3) Ensure exported functions with `algorithm=`default runs without error, and
  # returns the same if passed no argument
  out2 <- MinCostFlow(s, t, cap, costs, n, numNodes, algorithm = "NetworkSimplex")
  expect_identical(out, out2)

  # 4) Ensure exported functions work with all valid algorithms.
  out <- MinCostFlow(s, t, cap, costs, n, numNodes, algorithm = "CostScaling")
  test_mincostflow(out, s, numNodes)

  out <- MinCostFlow(s, t, cap, costs, n, numNodes, algorithm = "CapacityScaling")
  test_mincostflow(out, s, numNodes)

  out <- MinCostFlow(s, t, cap, costs, n, numNodes, algorithm = "CycleCancelling")
  test_mincostflow(out, s, numNodes)

  # 5) Ensure exported functions fail if passed an invalid algorithm.
  expect_error(MinCostFlow(s, t, cap, costs, n, numNodes,
                           algorithm = "abc"),
               "Invalid")
  expect_error(MinCostFlow(s, t, cap, costs, n, numNodes, algorithm = 1),
               "must be a string")
  expect_error(MinCostFlow(s, t, cap, costs, n, numNodes, algorithm = NULL),
               "must be a string")
})
