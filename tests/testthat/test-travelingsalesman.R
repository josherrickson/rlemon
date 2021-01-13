test_that("multiplication works", {
  expect_equal(2 * 2, 4)
})

test_that("christofides works",{
  s <- c(0,0,0,1,1,2)
  t <- c(1,2,3,2,3,3)
  d <- c(1,2,3,4,5,6)
  out <- ChristofidesRunner(s,t,d,4)
  expect_equal(out[[1]],c(2,0,1,3))
  expect_equal(out[[2]],14)
})

test_that("greedy works",{
  s <- c(0,0,0,1,1,2)
  t <- c(1,2,3,2,3,3)
  d <- c(1,2,3,4,5,6)
  out <- GreedyTSPRunner(s,t,d,4)
  expect_equal(out[[1]],c(0,1,3,2))
  expect_equal(out[[2]],14)
})

test_that("insertion works",{
  s <- c(0,0,0,1,1,2)
  t <- c(1,2,3,2,3,3)
  d <- c(1,2,3,4,5,6)
  out <- InsertionTSPRunner(s,t,d,4)
  expect_equal(out[[1]],c(0,1,2,3))
  expect_equal(out[[2]],14)
})

test_that("Nearest Neighbor works",{
  s <- c(0,0,0,1,1,2)
  t <- c(1,2,3,2,3,3)
  d <- c(1,2,3,4,5,6)
  out <- NearestNeighborTSPRunner(s,t,d,4)
  expect_equal(out[[1]],c(2,0,1,3))
  expect_equal(out[[2]],14)
})

test_that("Nearest Neighbor works",{
  s <- c(0,0,0,1,1,2)
  t <- c(1,2,3,2,3,3)
  d <- c(1,2,3,4,5,6)
  out <- Opt2TSPRunner(s,t,d,4)
  expect_equal(out[[1]],c(0,1,2,3))
  expect_equal(out[[2]],14)
})