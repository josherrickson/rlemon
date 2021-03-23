test_that("Testing connectivity", {
  s <- c(1, 2, 3, 4)
  t <- c(2, 3, 4, 1)
  n <- 4
  out <- IsConnected(s, t, n)
  expect_is(out, "integer")
  expect_equal(out, 1)
})

test_that("Testing acyclicity", {
  s <- c(1, 2, 3, 4)
  t <- c(2, 3, 4, 1)
  n <- 4
  out <- IsAcyclic(s, t, n)
  expect_is(out, "integer")
  expect_equal(out, 0)
})


test_that("Testing tree", {
  s <- c(1, 1, 1)
  t <- c(2, 3, 4)
  n <- 4
  out <- IsTree(s, t, n)
  expect_is(out, "integer")
  expect_equal(out, 1)
})



test_that("Testing biparite", {
  s <- c(1, 1, 1)
  t <- c(2, 3, 4)
  n <- 4
  out <- IsBipartite(s, t, n)
  expect_is(out, "integer")
  expect_equal(out, 1)
})


test_that("Testing DAG", {
  s <- c(1, 1, 1)
  t <- c(2, 3, 4)
  n <- 4
  out <- IsDAG(s, t, n)
  expect_is(out, "integer")
  expect_equal(out, 1)
})



test_that("Testing Bi-Node Connectiveness", {
  s <- c(1, 1, 1)
  t <- c(2, 3, 4)
  n <- 4
  out <- IsBiNodeConnected(s, t, n)
  expect_is(out, "integer")
  expect_equal(out, 0)
})

test_that("Testing Bi-Edge Connectiveness", {
  s <- c(1, 1, 1)
  t <- c(2, 3, 4)
  n <- 4
  out <- IsBiEdgeConnected(s, t, n)
  expect_is(out, "integer")
  expect_equal(out, 0)
})


test_that("Testing Loop Free", {
  s <- c(1, 1, 1)
  t <- c(1, 3, 4)
  n <- 4
  out <- IsLoopFree(s, t, n)
  expect_is(out, "integer")
  expect_equal(out, 0)
})


test_that("Testing parallel-free", {
  s <- c(1, 1, 1)
  t <- c(2, 3, 3)
  n <- 3
  out <- IsParallelFree(s, t, n)
  expect_is(out, "integer")
  expect_equal(out, 0)
})

test_that("simple graph check works", {
  s <- c(1, 2, 3)
  t <- c(2, 3, 1)
  n <- 3
  out <- IsSimpleGraph(s, t, n)
  expect_is(out, "integer")
  expect_equal(out, 1)
})


test_that("eulerian check works", {
  s <- c(1, 2, 3)
  t <- c(2, 3, 1)
  n <- 3
  out <- IsEulerian(s, t, n)
  expect_is(out, "integer")
  expect_equal(out, 1)
})

test_that("strongly connected check works", {
  s <- c(1, 2, 3)
  t <- c(2, 3, 1)
  n <- 3
  out <- IsStronglyConnected(s, t, n)
  expect_is(out, "integer")
  expect_equal(out, 1)
})


test_that("countConnectedComponents works", {
  s <- c(1, 2, 3)
  t <- c(2, 1, 3)
  n <- 3
  out <- CountConnectedComponents(s, t, n)
  expect_is(out, "integer")
  expect_equal(out, 2)
})

test_that("countBiEdgeConnectedComponents works", {
  s <- c(1, 2, 3)
  t <- c(2, 1, 3)
  n <- 3
  out <- CountBiEdgeConnectedComponents(s, t, n)
  expect_is(out, "integer")
  expect_equal(out, 2)
})


test_that("countBiNodeConnectedComponents works", {
  s <- c(1, 2, 3)
  t <- c(2, 1, 3)
  n <- 3
  out <- CountBiNodeConnectedComponents(s, t, n)
  expect_is(out, "integer")
  expect_equal(out, 2)
})

test_that("countStronglyConnectedComponents works", {
  s <- c(1, 2, 3)
  t <- c(2, 3, 2)
  n <- 3
  out <- CountStronglyConnectedComponents(s, t, n)
  expect_is(out, "integer")
  expect_equal(out, 2)
})

test_that("GetBipartitePartitions works", {
  s <- c(1, 1, 1, 2, 2, 2, 3, 3, 3)
  t <- c(4, 5, 6, 4, 5, 6, 4, 5, 6)
  n <- 6
  out <- GetBipartitePartitions(s, t, n)
  expect_equal(out[[1]], TRUE)
  expect_equal(out[[2]], c(0, 0, 0, 1, 1, 1))
})

test_that("topologicalSort works", {
  s <- c(1, 1, 1, 2, 2, 2, 3, 3, 3)
  t <- c(4, 5, 6, 4, 5, 6, 4, 5, 6)
  n <- 6
  out <- GetAndCheckTopologicalSort(s, t, n)
  expect_equal(out[[1]], TRUE)
  expect_equal(out[[2]], c(0, 1, 2, 3, 4, 5))
  out <- GetTopologicalSort(s, t, n)
  expect_equal(out, c(0, 1, 2, 3, 4, 5))
})

test_that("findingComponents works", {
  s <- c(1, 1, 1, 2, 2, 2, 3, 3, 3)
  t <- c(4, 5, 6, 4, 5, 6, 4, 5, 6)
  n <- 6
  out <- FindStronglyConnectedComponents(s, t, n)
  expect_equal(out, c(0, 1, 2, 3, 4, 5))
  out <- FindStronglyConnectedCutArcs(s, t, n)
  expect_equal(out[[1]], c(1, 1, 1, 2, 2, 2, 3, 3, 3))
  expect_equal(out[[2]], c(4, 5, 6, 4, 5, 6, 4, 5, 6))
  out <- FindConnectedComponents(s, t, n)
  expect_equal(out, c(0, 0, 0, 0, 0, 0))
  out <- FindBiEdgeConnectedComponents(s, t, n)
  expect_equal(out, c(0, 0, 0, 0, 0, 0))
  s <- c(1, 2, 3, 4, 5, 6)
  t <- c(2, 3, 4, 5, 6, 1)
  out <- FindBiNodeConnectedComponents(s, t, n)
  expect_equal(out, c(0, 0, 0, 0, 0, 0))
  out <- FindBiNodeConnectedCutNodes(s, t, n)
  expect_is(out, "integer")
  out <- FindBiEdgeConnectedCutEdges(s, t, n)
  expect_is(out, "list")
})
