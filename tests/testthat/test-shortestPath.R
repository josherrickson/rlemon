test_that("Suurballe works", {
  s <- c(1, 1, 2, 2, 2, 3, 4)
  t <- c(2, 4, 3, 4, 5, 5, 5)
  d <- c(6, 1, 5, 2, 2, 5, 1)
  n <- 5
  sn <- 1
  en <- 5
  out <- SuurballeRunner(s, t, d, n, sn, en)
  expect_equal(out[[1]], 2)
  paths <- list()
  paths[[1]] <- c(1, 4, 5)
  paths[[2]] <- c(1, 2, 5)
  expect_equal(out[[2]], paths)
})

test_that("Dijkstra works", {
  s <- c(1, 1, 2, 2, 2, 3, 4)
  t <- c(2, 4, 3, 4, 5, 5, 5)
  d <- c(6, 1, 5, 2, 2, 5, 1)
  n <- 5
  sn <- 1
  out <- DijkstraRunner(s, t, d, n, sn)
  expect_equal(out[[1]], c(0, 6, 11, 1, 2))
  expect_equal(out[[2]], c(0, 1, 2, 1, 4))
})

test_that("BellmanFord works", {
  s <- c(1, 1, 2, 2, 2, 3, 4)
  t <- c(2, 4, 3, 4, 5, 5, 5)
  d <- c(6, 1, 5, 2, 2, 5, 1)
  n <- 5
  sn <- 1
  out <- BellmanFordRunner(s, t, d, n, sn)
  expect_equal(out[[1]], c(0, 6, 11, 1, 2))
  expect_equal(out[[2]], c(0, 1, 2, 1, 4))
})

test_that("ShortestPath works", {
  s <- c(1, 1, 2, 2, 2, 3, 4)
  t <- c(2, 4, 3, 4, 5, 5, 5)
  d <- c(6, 1, 5, 2, 2, 5, 1)
  n <- 5
  sn <- 1
  en <- 5
  out <- ShortestPath(s, t, d, n, sn, en)
  expect_equal(out[[1]], 2)
  paths <- list()
  paths[[1]] <- c(1, 4, 5)
  paths[[2]] <- c(1, 2, 5)
  expect_equal(out[[2]], paths)

  expect_error(ShortestPath(s, t, d, n, sn, en, "abc"), "Invalid")
})

test_that("ShortestPathFromSource works", {
  s <- c(1, 1, 2, 2, 2, 3, 4)
  t <- c(2, 4, 3, 4, 5, 5, 5)
  d <- c(6, 1, 5, 2, 2, 5, 1)
  n <- 5
  sn <- 1
  out <- ShortestPathFromSource(s, t, d, n, sn)
  expect_equal(out[[1]], c(0, 6, 11, 1, 2))
  expect_equal(out[[2]], c(0, 1, 2, 1, 4))

  out <- ShortestPathFromSource(s, t, d, n, sn, "BellmanFord")
  expect_equal(out[[1]], c(0, 6, 11, 1, 2))
  expect_equal(out[[2]], c(0, 1, 2, 1, 4))

  expect_error(ShortestPathFromSource(s, t, d, n, sn, "abc"), "Invalid")
})
