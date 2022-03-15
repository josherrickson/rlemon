# Connectivity
# Runners: IsConnectedRunner, IsAcyclicRunner, IsTreeRunner, IsBipartiteRunner,
#   IsStronglyConnectedRunner, IsDAGRunner, IsBiNodeConnectedRunner,
#   IsBiEdgeConnectedRunner, IsLoopFreeRunner, IsParallelFreeRunner,
#   IsSimpleGraphRunner, IsEulerianRunner, getBipartitePartitionsRunner,
#   getAndCheckTopologicalSortRunner, getTopologicalSortRunner,
#   CountBiEdgeConnectedComponentsRunner, CountConnectedComponentsRunner,
#   CountBiNodeConnectedComponentsRunner,
#   CountStronglyConnectedComponentsRunner,
#   FindStronglyConnectedComponentsRunner, FindStronglyConnectedCutArcsRunner,
#   FindBiEdgeConnectedCutEdgesRunner, FindBiNodeConnectedComponentsRunner,
#   FindBiNodeConnectedCutNodesRunner, FindConnectedComponentsRunner,
#   FindBiEdgeConnectedComponentsRunner
# Exported: GetBipartitePartitions, GetAndCheckTopologicalSort,
#   GetTopologicalSort, IsConnected, IsAcyclic, IsTree, IsBipartite,
#   IsStronglyConnected, IsDAG, IsBiNodeConnected, IsBiEdgeConnected,
#   IsLoopFree, IsParallelFree, IsSimpleGraph, IsEulerian,
#   CountBiEdgeConnectedComponents, CountConnectedComponents,
#   CountBiNodeConnectedComponents, ountStronglyConnectedComponents,
#   FindStronglyConnectedComponents, FindStronglyConnectedCutArcs,
#   FindBiEdgeConnectedCutEdges, FindBiNodeConnectedComponents,
#   FindBiNodeConnectedCutNodes, FindConnectedComponents,
#   FindBiEdgeConnectedComponents
# Valid Algorithms: No algorithms in functions

### Is___ functions

# 1) Ensure runner functions run without error and return the "expected
# objects".
test_that("Testing Is____ runners", {
  s <- c(1, 2, 3, 4)
  t <- c(2, 3, 4, 1)
  n <- 4

  out <- IsConnected(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsAcyclic(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsTree(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsBipartite(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsDAG(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsBiNodeConnected(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsBiEdgeConnected(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsLoopFree(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsParallelFree(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsSimpleGraph(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsEulerian(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsStronglyConnected(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- getBipartitePartitionsRunner(s, t, n)
  expect_is(out, "list")
  expect_length(out, 2)
  expect_true(is.logical(out[[1]]))
  expect_true(is.numeric(out[[2]]))

  out <- getAndCheckTopologicalSortRunner(s, t, n)
  expect_is(out, "list")
  expect_length(out, 2)
  expect_true(is.logical(out[[1]]))
  expect_true(is.numeric(out[[2]]))

  out <- getTopologicalSortRunner(s, t, n)
  expect_is(out, "integer")

  out <- CountBiEdgeConnectedComponentsRunner(s, t, n)
  expect_is(out, "integer")
  expect_length(out, 1)
  expect_true(out >= 0)

  out <- CountConnectedComponentsRunner(s, t, n)
  expect_is(out, "integer")
  expect_length(out, 1)
  expect_true(out >= 0)

  out <- CountBiNodeConnectedComponentsRunner(s, t, n)
  expect_is(out, "integer")
  expect_length(out, 1)
  expect_true(out >= 0)

  out <- CountStronglyConnectedComponentsRunner(s, t, n)
  expect_is(out, "integer")
  expect_length(out, 1)
  expect_true(out >= 0)

  out <- FindStronglyConnectedComponentsRunner(s, t, n)
  expect_is(out, "integer")

  out <- FindStronglyConnectedCutArcsRunner(s, t, n)
  expect_is(out, "list")
  expect_length(out, 2)
  expect_true(is.numeric(out[[1]]))
  expect_true(is.numeric(out[[2]]))

  out <- FindBiEdgeConnectedCutEdgesRunner(s, t, n)
  expect_is(out, "list")
  expect_length(out, 2)
  expect_true(is.numeric(out[[1]]))
  expect_true(is.numeric(out[[2]]))

  out <- FindBiNodeConnectedComponentsRunner(s, t, n)
  expect_is(out, "integer")

  out <- FindBiNodeConnectedCutNodesRunner(s, t, n)
  expect_is(out, "integer")

  out <- FindConnectedComponentsRunner(s, t, n)
  expect_is(out, "integer")

  out <- FindBiEdgeConnectedComponentsRunner(s, t, n)
  expect_is(out, "integer")
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
