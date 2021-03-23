test_that("BFS works", {
  s <- c(1, 1, 2, 2, 2, 3, 4)
  t <- c(2, 4, 3, 4, 5, 5, 5)
  n <- 5
  sn <- 1
  en <- 5
  out <- BfsRunner(s, t, n, sn, en)
  expect_equal(out[[1]], c(0, 1, 0, 1, 4))
  expect_equal(out[[2]], c(0, 1, 0, 1, 2))
  expect_equal(out[[3]], c(1, 1, 0, 1, 1))
  out1 <- BfsRunner(s, t, n, sn, -1)
  expect_equal(out1[[1]], c(0, 1, 2, 1, 4))
  expect_equal(out1[[2]], c(0, 1, 2, 1, 2))
  expect_equal(out1[[3]], c(1, 1, 1, 1, 1))
  out <- GraphSearch(s, t, n, sn, en, "Bfs")
  expect_equal(out[[1]], c(0, 1, 0, 1, 4))
  expect_equal(out[[2]], c(0, 1, 0, 1, 2))
  expect_equal(out[[3]], c(1, 1, 0, 1, 1))
  out1 <- GraphSearch(s, t, n, sn, -1, "Bfs")
  expect_equal(out1[[1]], c(0, 1, 2, 1, 4))
  expect_equal(out1[[2]], c(0, 1, 2, 1, 2))
  expect_equal(out1[[3]], c(1, 1, 1, 1, 1))
  expect_error(GraphSearch(s, t, n, sn, en, "abc"), "Invalid")
})

test_that("DFS works", {
  s <- c(1, 1, 2, 2, 2, 3, 4)
  t <- c(2, 4, 3, 4, 5, 5, 5)
  n <- 5
  sn <- 1
  en <- 5
  out <- DfsRunner(s, t, n, sn, en)
  expect_equal(out[[1]], c(0, 0, 0, 1, 4))
  expect_equal(out[[2]], c(0, 0, 0, 1, 2))
  expect_equal(out[[3]], c(1, 0, 0, 1, 1))
  out1 <- DfsRunner(s, t, n, sn, -1)
  expect_equal(out1[[1]], c(0, 1, 2, 1, 4))
  expect_equal(out1[[2]], c(0, 1, 2, 1, 2))
  expect_equal(out1[[3]], c(1, 1, 1, 1, 1))
  out <- GraphSearch(s, t, n, sn, en, "Dfs")
  expect_equal(out[[1]], c(0, 0, 0, 1, 4))
  expect_equal(out[[2]], c(0, 0, 0, 1, 2))
  expect_equal(out[[3]], c(1, 0, 0, 1, 1))
  out1 <- GraphSearch(s, t, n, sn, -1, "Dfs")
  expect_equal(out1[[1]], c(0, 1, 2, 1, 4))
  expect_equal(out1[[2]], c(0, 1, 2, 1, 2))
  expect_equal(out1[[3]], c(1, 1, 1, 1, 1))
  expect_error(GraphSearch(s, t, n, sn, en, "abc"), "Invalid")
})

test_that("MaxCardinality works", {
  s <- c(1, 1, 2, 2, 2, 3, 4)
  t <- c(2, 4, 3, 4, 5, 5, 5)
  c <- c(6, 1, 5, 2, 2, 5, 1)
  n <- 5
  sn <- 5
  out <- MaxCardinalitySearchRunner(s, t, c, n, sn)
  expect_equal(out[[1]], c(6, 7, 5, 1, 0))
  expect_equal(out[[2]], c(1, 1, 1, 1, 1))
  out <- MaxCardinalitySearch(s, t, c, n, sn)
  expect_equal(out[[1]], c(6, 7, 5, 1, 0))
  expect_equal(out[[2]], c(1, 1, 1, 1, 1))
  expect_error(MaxCardinalitySearch(s, t, c, n, sn, "abc"), "Invalid")
})
