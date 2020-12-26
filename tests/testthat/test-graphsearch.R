test_that("BFS works", {
  s <- c(0, 0, 1, 1, 1, 2, 3)
  t <- c(1, 3, 2, 3, 4, 4, 4)
  n <- 5
  sn <- 0
  en <- 4
  out <- BfsRunner(s,t,n,sn,en)
  expect_equal(out[[1]], c(-1,0,-1,0,3))
  expect_equal(out[[2]], c(0,1,0,1,2))
  expect_equal(out[[3]], c(1,1,0,1,1))
  out1 <- BfsRunner(s,t,n,sn,-1)
  expect_equal(out1[[1]], c(-1,0,1,0,3))
  expect_equal(out1[[2]], c(0,1,2,1,2))
  expect_equal(out1[[3]], c(1,1,1,1,1))
})

test_that("DFS works", {
  s <- c(0, 0, 1, 1, 1, 2, 3)
  t <- c(1, 3, 2, 3, 4, 4, 4)
  n <- 5
  sn <- 0
  en <- 4
  out <- DfsRunner(s,t,n,sn,en)
  expect_equal(out[[1]], c(-1,-1,-1,0,3))
  expect_equal(out[[2]], c(0,0,0,1,2))
  expect_equal(out[[3]], c(1,0,0,1,1))
  out1 <- DfsRunner(s,t,n,sn,-1)
  expect_equal(out1[[1]], c(-1,0,1,0,3))
  expect_equal(out1[[2]], c(0,1,2,1,2))
  expect_equal(out1[[3]], c(1,1,1,1,1))
})

test_that("MaxCardinality works", {
  s <- c(0, 0, 1, 1, 1, 2, 3)
  t <- c(1, 3, 2, 3, 4, 4, 4)
  c <- c(6, 1, 5, 2, 2, 5, 1)
  n <- 5
  sn <- 4
  out <- MaxCardinalitySearchRunner(s,t,c,n,sn)
  expect_equal(out[[1]],c(6,7,5,1,0))
  expect_equal(out[[2]],c(1,1,1,1,1))
})