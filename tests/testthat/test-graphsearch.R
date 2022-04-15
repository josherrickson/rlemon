# Title            : Graph Search
# FIle             : R/graphsearch.R
# Exported         : GraphSearch
# Valid Algorithms : "Bfs" (default), "Dfs"
# Runners          : BfsRunner, DfsRunner

# 1) Ensure runner functions run without error and return the "expected
# objects".
test_that("graph search runners", {
  s <- c(1, 1, 2, 2, 2, 3, 4)
  t <- c(2, 4, 3, 4, 5, 5, 5)
  n <- 5
  sn <- 1
  en <- 5

  # default startNode and endNode
  out <- BfsRunner(s, t, n)
  expect_true(is.list(out))
  expect_length(out, 3)
  expect_length(unique(vapply(out, length, 1)), 1)

  out <- BfsRunner(s, t, n, sn, en)
  expect_true(is.list(out))
  expect_length(out, 3)
  expect_length(unique(vapply(out, length, 1)), 1)

  # default startNode and endNode
  out <- DfsRunner(s, t, n)
  expect_true(is.list(out))
  expect_length(out, 3)
  expect_length(unique(vapply(out, length, 1)), 1)

  out <- DfsRunner(s, t, n, sn, en)
  expect_true(is.list(out))
  expect_length(out, 3)
  expect_length(unique(vapply(out, length, 1)), 1)

})

test_that("graph search function", {
  s <- c(1, 1, 2, 2, 2, 3, 4)
  t <- c(2, 4, 3, 4, 5, 5, 5)
  n <- 5
  sn <- 1
  en <- 5

  # 2) Ensure exported functions run without error and return the "expected
  # objects".

  # default startNode and endNode
  out <- GraphSearch(s, t, n, sn, en)
  expect_true(is.list(out))
  expect_length(out, 3)
  expect_length(unique(vapply(out, length, 1)), 1)
  expect_true(is.numeric(out[[1]]))
  expect_true(is.numeric(out[[2]]))
  expect_true(is.logical(out[[3]]))

  out <- GraphSearch(s, t, n, sn, en)
  expect_true(is.list(out))
  expect_length(out, 3)
  expect_length(unique(vapply(out, length, 1)), 1)
  expect_true(is.numeric(out[[1]]))
  expect_true(is.numeric(out[[2]]))
  expect_true(is.logical(out[[3]]))

  # 3) Ensure exported functions with `algorithm=`default runs without error, and
  # returns the same if passed no argument
  out2 <- GraphSearch(s, t, n, sn, en, algorithm = "Bfs")
  expect_identical(out, out2)

  # 4) Ensure exported functions work with all valid algorithms.
  out <- GraphSearch(s, t, n, sn, en, algorithm = "Dfs")
  expect_true(is.list(out))
  expect_length(out, 3)
  expect_length(unique(vapply(out, length, 1)), 1)
  expect_true(is.numeric(out[[1]]))
  expect_true(is.numeric(out[[2]]))
  expect_true(is.logical(out[[3]]))

  # 5) Ensure exported functions fail if passed an invalid algorithm.
  expect_error(GraphSearch(s, t, n, sn, en, algorithm = "abc"),
               "Invalid")
  expect_error(GraphSearch(s, t, n, sn, en, algorithm = 1),
               "must be a string")
  expect_error(GraphSearch(s, t, n, sn, en, algorithm = NULL),
               "must be a string")

})
