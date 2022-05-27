# Title            : Shortest Path
# File             : R/shortestpath.R
# Exported         : ShortestPath
# Valid Algorithms : "Suurballe" (default),
# Runners          : SuurballeRunner

test_shortestpath <- function(o, named = TRUE) {
  expect_true(is.list(o))
  expect_length(o, 2)
  expect_length(o[[1]], 1)
  expect_true(is.list(o[[2]]))
  expect_true(all(vapply(o[[2]], is.numeric, TRUE)))
  expect_length(o[[2]], o[[1]])
  if (named) {
    expect_named(o, c("num_paths", "list_paths"))
  }
}

# 1) Ensure runner functions run without error and return the "expected
# objects".
test_that("shortest path runners", {

  s <- c(1, 1, 2, 2, 2, 3, 4)
  t <- c(2, 4, 3, 4, 5, 5, 5)
  d <- c(6, 1, 5, 2, 2, 5, 1)
  n <- 5
  sn <- 1
  en <- 5

  out <- SuurballeRunner(s, t, d, n, sn, en)
  test_shortestpath(out, named = FALSE)

})


test_that("shortest path function", {

  s <- c(1, 1, 2, 2, 2, 3, 4)
  t <- c(2, 4, 3, 4, 5, 5, 5)
  d <- c(6, 1, 5, 2, 2, 5, 1)
  n <- 5
  sn <- 1
  en <- 5

  # 2) Ensure exported functions run without error and return the "expected
  # objects".
  out <- ShortestPath(s, t, d, n, sn, en)
  test_shortestpath(out)

  # 3) Ensure exported functions with `algorithm=`default runs without error, and
  # returns the same if passed no argument
  out2 <- ShortestPath(s, t, d, n, sn, en, algorithm = "Suurballe")
  expect_identical(out, out2)

  # 4) Ensure exported functions work with all valid algorithms.
  # No alternative algorithms.

  # 5) Ensure exported functions fail if passed an invalid algorithm.
  expect_error(ShortestPath(s, t, d, n, sn, en, algorithm = "abc"),
               "Invalid")
  expect_error(ShortestPath(s, t, d, n, sn, en, algorithm = 1),
               "must be a string")
  expect_error(ShortestPath(s, t, d, n, sn, en, algorithm = NULL),
               "must be a string")
})
