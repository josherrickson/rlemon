test_that("Testing connectivity", {
   s <- c(0,1,2,3)
   t <- c(1,2,3,0)
   n <- 4
   out <- IsConnected(s, t, n)
   expect_is(out, "integer")
   expect_equal(out, 1)
})

test_that("Testing acyclicity", {
   s <- c(0,1,2,3)
   t <- c(1,2,3,0)
   n <- 4
   out <- IsAcyclic(s, t, n)
   expect_is(out, "integer")
   expect_equal(out, 0)
})


test_that("Testing tree", {
   s <- c(0,0,0)
   t <- c(1,2,3)
   n <- 4
   out <- IsTree(s, t, n)
   expect_is(out, "integer")
   expect_equal(out, 1)
})



test_that("Testing biparite", {
   s <- c(0,0,0)
   t <- c(1,2,3)
   n <- 4
   out <- IsBipartite(s, t, n)
   expect_is(out, "integer")
   expect_equal(out, 1)
})


test_that("Testing DAG", {
   s <- c(0,0,0)
   t <- c(1,2,3)
   n <- 4
   out <- IsDAG(s, t, n)
   expect_is(out, "integer")
   expect_equal(out, 1)
})



test_that("Testing Bi-Node Connectiveness", {
   s <- c(0,0,0)
   t <- c(1,2,3)
   n <- 4
   out <- IsBiNodeConnected(s, t, n)
   expect_is(out, "integer")
   expect_equal(out, 0)
})

test_that("Testing Bi-Edge Connectiveness", {
   s <- c(0,0,0)
   t <- c(1,2,3)
   n <- 4
   out <- IsBiEdgeConnected(s, t, n)
   expect_is(out, "integer")
   expect_equal(out, 0)
})


test_that("Testing Loop Free", {
   s <- c(0,0,0)
   t <- c(0,2,3)
   n <- 4
   out <- IsLoopFree(s, t, n)
   expect_is(out, "integer")
   expect_equal(out, 0)
})


test_that("Testing parallel-free", {
   s <- c(0,0,0)
   t <- c(1,2,2)
   n <- 3
   out <- IsParallelFree(s,t,n)
   expect_is(out, "integer")
   expect_equal(out, 0)
})

test_that("simple graph check works", {
   s <- c(0,1,2)
   t <- c(1,2,0)
   n <- 3
   out <- IsSimpleGraph(s,t,n)
   expect_is(out, "integer")
   expect_equal(out, 1)
})


test_that("eulerian check works", {
   s <- c(0,1,2)
   t <- c(1,2,0)
   n <- 3
   out <- IsEulerian(s,t,n)
   expect_is(out, "integer")
   expect_equal(out, 1)
})

test_that("strongly connected check works", {
   s <- c(0,1,2)
   t <- c(1,2,0)
   n <- 3
   out <- IsStronglyConnected(s,t,n)
   expect_is(out, "integer")
   expect_equal(out, 1)
})


test_that("countConnectedComponents works", {
   s <- c(0,1,2)
   t <- c(1,0,2)
   n <- 3
   out <- CountConnectedComponents(s,t,n)
   expect_is(out, "integer")
   expect_equal(out, 2)
})

test_that("countBiEdgeConnectedComponents works", {
   s <- c(0,1,2)
   t <- c(1,0,2)
   n <- 3
   out <- CountBiEdgeConnectedComponents(s,t,n)
   expect_is(out, "integer")
   expect_equal(out, 2)
})


test_that("countBiNodeConnectedComponents works", {
   s <- c(0,1,2)
   t <- c(1,0,2)
   n <- 3
   out <- CountBiNodeConnectedComponents(s,t,n)
   expect_is(out, "integer")
   expect_equal(out, 2)
})

test_that("countStronglyConnectedComponents works", {
   s <- c(0,1,2)
   t <- c(1,2,1)
   n <- 3
   out <- CountStronglyConnectedComponents(s,t,n)
   expect_is(out, "integer")
   expect_equal(out, 2)
})

test_that("getBipartitePartitions works", {
   s <- c(0,0,0,1,1,1,2,2,2)
   t <- c(3,4,5,3,4,5,3,4,5)
   n <- 6
   out <- getBipartitePartitions(s,t,n)
   expect_equal(out[[1]], TRUE)
   expect_equal(out[[2]],c(0,0,0,1,1,1))
})

test_that("topologicalSort works", {
   s <- c(0,0,0,1,1,1,2,2,2)
   t <- c(3,4,5,3,4,5,3,4,5)
   n <- 6
   out <- getAndCheckTopologicalSort(s,t,n)
   expect_equal(out[[1]],TRUE)
   expect_equal(out[[2]],c(0,1,2,3,4,5))
   out <- getTopologicalSort(s,t,n)
   expect_equal(out, c(0,1,2,3,4,5))
})

test_that("findingComponents works", {
   s <- c(0,0,0,1,1,1,2,2,2)
   t <- c(3,4,5,3,4,5,3,4,5)
   n <- 6
   out <- FindStronglyConnectedComponents(s,t,n)
   expect_equal(out,c(0,1,2,3,4,5))
   out <- FindStronglyConnectedCutArcs(s,t,n)
   expect_equal(out[[1]], c(0,0,0,1,1,1,2,2,2))
   expect_equal(out[[2]], c(3,4,5,3,4,5,3,4,5))
   out <- FindConnectedComponents(s,t,n)
   expect_equal(out, c(0,0,0,0,0,0))
   out <- FindBiEdgeConnectedComponents(s,t,n)
   expect_equal(out, c(0,0,0,0,0,0))
   s <- c(0,1,2,3,4,5)
   t <- c(1,2,3,4,5,0)
   out <- FindBiNodeConnectedComponents(s,t,n)
   expect_equal(out, c(0,0,0,0,0,0))
   out <- FindBiNodeConnectedCutNodes(s,t,n)
   expect_is(out, "integer")
   out <- FindBiEdgeConnectedCutEdges(s,t,n)
   expect_is(out, "list")
})