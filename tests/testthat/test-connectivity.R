# Title            : Connectivity Functions
# File             : R/connectivity.R
# Exported         : GetBipartitePartitions, GetAndCheckTopologicalSort,
#   GetTopologicalSort, IsConnected, IsAcyclic, IsTree, IsBipartite,
#   IsStronglyConnected, IsDAG, IsBiNodeConnected, IsBiEdgeConnected,
#   IsLoopFree, IsParallelFree, IsSimpleGraph, IsEulerian,
#   CountBiEdgeConnectedComponents, CountConnectedComponents,
#   CountBiNodeConnectedComponents, CountStronglyConnectedComponents,
#   FindStronglyConnectedComponents, FindStronglyConnectedCutArcs,
#   FindBiEdgeConnectedCutEdges, FindBiNodeConnectedComponents,
#   FindBiNodeConnectedCutNodes, FindConnectedComponents,
#   FindBiEdgeConnectedComponents
# Valid Algorithms : No algorithms in functions
# Runners          : IsConnectedRunner, IsAcyclicRunner, IsTreeRunner,
#   IsBipartiteRunner, IsStronglyConnectedRunner, IsDAGRunner,
#   IsBiNodeConnectedRunner, IsBiEdgeConnectedRunner, IsLoopFreeRunner,
#   IsParallelFreeRunner, IsSimpleGraphRunner, IsEulerianRunner,
#   getBipartitePartitionsRunner, getAndCheckTopologicalSortRunner,
#   getTopologicalSortRunner, CountBiEdgeConnectedComponentsRunner,
#   CountConnectedComponentsRunner, CountBiNodeConnectedComponentsRunner,
#   CountStronglyConnectedComponentsRunner,
#   FindStronglyConnectedComponentsRunner, FindStronglyConnectedCutArcsRunner,
#   FindBiEdgeConnectedCutEdgesRunner, FindBiNodeConnectedComponentsRunner,
#   FindBiNodeConnectedCutNodesRunner, FindConnectedComponentsRunner,
#   FindBiEdgeConnectedComponentsRunner

# 1) Ensure runner functions run without error and return the "expected
# objects".
test_that("Testing Is____ runners", {
  s <- c(1, 2, 3, 4)
  t <- c(2, 3, 4, 1)
  n <- 4

  out <- IsConnectedRunner(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsAcyclicRunner(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsTreeRunner(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsBipartiteRunner(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsStronglyConnectedRunner(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsDAGRunner(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsBiNodeConnectedRunner(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsBiEdgeConnectedRunner(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsLoopFreeRunner(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsParallelFreeRunner(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsSimpleGraphRunner(s, t, n)
  expect_is(out, "integer")
  expect_true(out %in% 0:1)

  out <- IsEulerianRunner(s, t, n)
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

# 2) Ensure exported functions run without error and return the "expected
# objects".
test_that("GetBipartitePartitions function", {
  s <- c(1, 1, 1, 2, 2, 2, 3, 3, 3)
  t <- c(4, 5, 6, 4, 5, 6, 4, 5, 6)
  n <- 6

  out <- GetBipartitePartitions(s, t, n)
  expect_true(is.list(out))
  expect_length(out, 2)
  expect_length(out[[1]], 1)
  expect_true(is.logical(out[[1]]))
  expect_true(all(out[[2]] %in% 0:1))
  expect_named(out, c("is_bipartite", "partitions"))

})

test_that("topologicalSort functions", {
  s <- c(1, 1, 1, 2, 2, 2, 3, 3, 3)
  t <- c(4, 5, 6, 4, 5, 6, 4, 5, 6)
  n <- 6
  out <- GetAndCheckTopologicalSort(s, t, n)
  expect_true(is.list(out))
  expect_length(out, 2)
  expect_length(out[[1]], 1)
  expect_true(is.logical(out[[1]]))
  expect_length(out[[2]] , n)
  expect_true(is.numeric(out[[2]]))
  expect_named(out, c("is_DAG", "indices"))

  out <- GetTopologicalSort(s, t, n)
  expect_length(out, n)
  expect_true(is.numeric(out))
})


test_that("is___ functions", {

  s <- c(1, 2, 3, 4)
  t <- c(2, 3, 4, 1)
  n <- 4

  out <- IsConnected(s, t, n)
  expect_is(out, "logical")

  out <- IsAcyclic(s, t, n)
  expect_is(out, "logical")

  out <- IsTree(s, t, n)
  expect_is(out, "logical")

  out <- IsBipartite(s, t, n)
  expect_is(out, "logical")

  out <- IsStronglyConnected(s, t, n)
  expect_is(out, "logical")

  out <- IsDAG(s, t, n)
  expect_is(out, "logical")

  out <- IsBiNodeConnected(s, t, n)
  expect_is(out, "logical")

  out <- IsBiEdgeConnected(s, t, n)
  expect_is(out, "logical")

  out <- IsLoopFree(s, t, n)
  expect_is(out, "logical")

  out <- IsParallelFree(s, t, n)
  expect_is(out, "logical")

  out <- IsSimpleGraph(s, t, n)
  expect_is(out, "logical")

  out <- IsEulerian(s, t, n)
  expect_is(out, "logical")

})

test_that("count functions", {
  s <- c(1, 2, 3)
  t <- c(2, 1, 3)
  n <- 3

  out <- CountBiEdgeConnectedComponents(s, t, n)
  expect_length(out, 1)
  expect_is(out, "integer")

  out <- CountConnectedComponents(s, t, n)
  expect_length(out, 1)
  expect_is(out, "integer")

  out <- CountBiNodeConnectedComponents(s, t, n)
  expect_length(out, 1)
  expect_is(out, "integer")

  out <- CountStronglyConnectedComponents(s, t, n)
  expect_length(out, 1)
  expect_is(out, "integer")
})


test_that("find functions", {
  s <- c(1, 1, 1, 2, 2, 2, 3, 3, 3)
  t <- c(4, 5, 6, 4, 5, 6, 4, 5, 6)
  n <- 6

  out <- FindStronglyConnectedComponents(s, t, n)
  expect_true(is.numeric(out))

  out <- FindStronglyConnectedCutArcs(s, t, n)
  expect_is(out, "list")
  expect_length(out, 2)
  expect_true(is.numeric(out[[1]]))
  expect_true(is.numeric(out[[2]]))
  expect_named(out, c("sources", "destinations"))

  out <- FindConnectedComponents(s, t, n)
  expect_true(is.numeric(out))

  out <- FindBiEdgeConnectedComponents(s, t, n)
  expect_true(is.numeric(out))

  s <- c(1, 2, 3, 4, 5, 6)
  t <- c(2, 3, 2, 5, 6, 1)

  out <- FindBiEdgeConnectedCutEdges(s, t, n)
  expect_is(out, "list")
  expect_length(out, 2)
  expect_true(is.numeric(out[[1]]))
  expect_true(is.numeric(out[[2]]))
  expect_named(out, c("sources", "destinations"))

  out <- FindBiNodeConnectedComponents(s, t, n)
  expect_true(is.numeric(out))

  out <- FindBiNodeConnectedCutNodes(s, t, n)
  expect_true(is.numeric(out))


})

# 3) Ensure exported functions with `algorithm=`default runs without error, and
# returns the same if passed no argument
# No algorithms here

# 4) Ensure exported functions work with all valid algorithms.
# No algorithms here

# 5) Ensure exported functions fail if passed an invalid algorithm.
# No algorithms here
