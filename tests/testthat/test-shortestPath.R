test_that("Suurballe works", {
  s <- c(0, 0, 1, 1, 1, 2, 3)
  t <- c(1, 3, 2, 3, 4, 4, 4)
  d <- c(6, 1, 5, 2, 2, 5, 1)
  n <- 5
  sn <- 0
  en <- 4
  out <- SuurballeRunner(s,t,d,n,sn,en)
  expect_equal(out[[1]], 2)
  paths <- list()
  paths[[1]] <- c(0,3,4)
  paths[[2]] <- c(0,1,4)
  expect_equal(out[[2]],paths)
})

test_that("Dijkstra works", {
  s <- c(0, 0, 1, 1, 1, 2, 3)
  t <- c(1, 3, 2, 3, 4, 4, 4)
  d <- c(6, 1, 5, 2, 2, 5, 1)
  n <- 5
  sn <- 0
  out <- DijkstraRunner(s,t,d,n,sn)
  expect_equal(out[[1]],c(0,6,11,1,2))
  expect_equal(out[[2]],c(-1,0,1,0,3))
})

test_that("BellmanFord works", {
  s <- c(0, 0, 1, 1, 1, 2, 3)
  t <- c(1, 3, 2, 3, 4, 4, 4)
  d <- c(6, 1, 5, 2, 2, 5, 1)
  n <- 5
  sn <- 0
  out <- BellmanFordRunner(s,t,d,n,sn)
  expect_equal(out[[1]],c(0,6,11,1,2))
  expect_equal(out[[2]],c(-1,0,1,0,3))
})

test_that("ShortestPath works", {
  s <- c(0, 0, 1, 1, 1, 2, 3)
  t <- c(1, 3, 2, 3, 4, 4, 4)
  d <- c(6, 1, 5, 2, 2, 5, 1)
  n <- 5
  sn <- 0
  en <- 4
  out <- ShortestPath(s,t,d,n,sn,en)
  expect_equal(out[[1]], 2)
  paths <- list()
  paths[[1]] <- c(0,3,4)
  paths[[2]] <- c(0,1,4)
  expect_equal(out[[2]],paths)

  expect_error(ShortestPath(s,t,d,n,sn,en,"abc"), "Invalid")
})

test_that("ShortestPathFromSource works", {
  s <- c(0, 0, 1, 1, 1, 2, 3)
  t <- c(1, 3, 2, 3, 4, 4, 4)
  d <- c(6, 1, 5, 2, 2, 5, 1)
  n <- 5
  sn <- 0
  out <- ShortestPathFromSource(s,t,d,n,sn)
  expect_equal(out[[1]],c(0,6,11,1,2))
  expect_equal(out[[2]],c(-1,0,1,0,3))

  expect_error(ShortestPathFromSource(s,t,d,n,sn,"abc"), "Invalid")
})