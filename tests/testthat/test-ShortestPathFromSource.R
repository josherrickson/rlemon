# Title            : Shortest Path From Source
# File             : R/shortestpath.R
# Exported         : ShortestPathFromSource
# Valid Algorithms : "Dijkstra" (default), "BellmanFord"
# Runners          : DijkstraRunner, BellmanFordRunner

test_shortestpath <- function(o) {
  expect_true(is.list(o))
  expect_length(o, 2)
  expect_true(all(vapply(o, is.numeric, TRUE)))
}

# 1) Ensure runner functions run without error and return the "expected
# objects".
test_that("shortest path from source runners", {

  s <- c(1, 1, 2, 2, 2, 3, 4)
  t <- c(2, 4, 3, 4, 5, 5, 5)
  d <- c(6, 1, 5, 2, 2, 5, 1)
  n <- 5
  sn <- 1

  out <- DijkstraRunner(s, t, d, n, sn)
  test_shortestpath(out)

  out <- BellmanFordRunner(s, t, d, n, sn)
  test_shortestpath(out)

})


test_that("shortest path from source function", {

  s <- c(1, 1, 2, 2, 2, 3, 4)
  t <- c(2, 4, 3, 4, 5, 5, 5)
  d <- c(6, 1, 5, 2, 2, 5, 1)
  n <- 5
  sn <- 1

  # 2) Ensure exported functions run without error and return the "expected
  # objects".
  out <- ShortestPathFromSource(s, t, d, n, sn)
  test_shortestpath(out)

  # 3) Ensure exported functions with `algorithm=`default runs without error, and
  # returns the same if passed no argument
  out2 <- ShortestPathFromSource(s, t, d, n, sn, algorithm = "Dijkstra")
  expect_identical(out, out2)

  # 4) Ensure exported functions work with all valid algorithms.
  out <- ShortestPathFromSource(s, t, d, n, sn, algorithm = "BellmanFord")
  test_shortestpath(out)

  # 5) Ensure exported functions fail if passed an invalid algorithm.
  expect_error(ShortestPathFromSource(s, t, d, n, sn, algorithm = "abc"),
               "Invalid")
  expect_error(ShortestPathFromSource(s, t, d, n, sn, algorithm = 1),
               "must be a string")
  expect_error(ShortestPathFromSource(s, t, d, n, sn, algorithm = NULL),
               "must be a string")
})
