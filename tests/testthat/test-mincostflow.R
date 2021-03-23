test_that("Capcity Scaling Test", {
  s <- small_graph_example$startnodes
  t <- small_graph_example$endnodes
  cap <- small_graph_example$arccapacity
  costs <- small_graph_example$arccosts
  n <- small_graph_example$nodedemand
  numNodes <- 34
  out <- CapacityScalingRunner(s, t, cap, costs, n, numNodes)
  expect_is(out, "list")
  expect_is(out[[3]], "integer")
  expect_equal(out[[3]], 9833)
  expect_equal(out[[1]], small_graph_example$outflow)
})

test_that("Cost Scaling Test", {
  s <- small_graph_example$startnodes
  t <- small_graph_example$endnodes
  cap <- small_graph_example$arccapacity
  costs <- small_graph_example$arccosts
  n <- small_graph_example$nodedemand
  numNodes <- 34
  out <- CostScalingRunner(s, t, cap, costs, n, numNodes)
  expect_is(out, "list")
  expect_is(out[[3]], "integer")
  expect_equal(out[[3]], 9833)
  expect_equal(out[[1]], small_graph_example$outflow)
})


test_that("Network Simplex Test", {
  s <- small_graph_example$startnodes
  t <- small_graph_example$endnodes
  cap <- small_graph_example$arccapacity
  costs <- small_graph_example$arccosts
  n <- small_graph_example$nodedemand
  numNodes <- 34
  out <- NetworkSimplexRunner(s, t, cap, costs, n, numNodes)
  expect_is(out, "list")
  expect_is(out[[3]], "integer")
  expect_equal(out[[3]], 9833)
  expect_equal(out[[1]], small_graph_example$outflow)
})

test_that("Cycle Cancelling Test", {
  s <- small_graph_example$startnodes
  t <- small_graph_example$endnodes
  cap <- small_graph_example$arccapacity
  costs <- small_graph_example$arccosts
  n <- small_graph_example$nodedemand
  numNodes <- 34
  out <- CycleCancellingRunner(s, t, cap, costs, n, numNodes)
  expect_is(out, "list")
  expect_is(out[[3]], "integer")
  expect_equal(out[[3]], 9833)
  expect_equal(out[[1]], small_graph_example$outflow)
})
test_that("MinCostFlow Test", {
  s <- small_graph_example$startnodes
  t <- small_graph_example$endnodes
  cap <- small_graph_example$arccapacity
  costs <- small_graph_example$arccosts
  n <- small_graph_example$nodedemand
  numNodes <- 34
  out <- MinCostFlow(s, t, cap, costs, n, numNodes, "NetworkSimplex")
  expect_is(out, "list")
  expect_is(out[[3]], "integer")
  expect_equal(out[[3]], 9833)
  expect_equal(out[[1]], small_graph_example$outflow)
  out <- MinCostFlow(s, t, cap, costs, n, numNodes, "CostScaling")
  expect_is(out, "list")
  expect_is(out[[3]], "integer")
  expect_equal(out[[3]], 9833)
  out <- MinCostFlow(s, t, cap, costs, n, numNodes, "CapacityScaling")
  expect_is(out, "list")
  expect_is(out[[3]], "integer")
  expect_equal(out[[3]], 9833)
  out <- MinCostFlow(s, t, cap, costs, n, numNodes, "CycleCancelling")
  expect_is(out, "list")
  expect_is(out[[3]], "integer")
  expect_equal(out[[3]], 9833)

  expect_error(MinCostFlow(s, t, cap, costs, n, numNodes, "abc"), "Invalid")
})
