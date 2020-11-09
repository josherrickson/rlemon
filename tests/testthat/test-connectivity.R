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
   out <- IsBiEdgeConnected(s, t, n)
   expect_is(out, "integer")
   expect_equal(out, 0)
})



