# Title            : Max Cardinality Search
# File             : R/graphsearch.R
# Exported         : MaxCardinalitySearch
# Valid Algorithms : "maxcardinalitysearch" (default)
# Runners          : MaxCardinalitySearchRunner

test_search <- function(o, n, fromRunner) {
  expect_true(is.list(o))
  expect_length(o, 2)
  expect_equal(unique(vapply(o, length, 1)), n)
  expect_true(is.numeric(o[[1]]))
  if (fromRunner) {
    expect_true(is.numeric(o[[2]]))
  } else {
    expect_true(is.logical(o[[2]]))
    expect_named(o, c("cardinalities", "node_reached"))
  }
}

# 1) Ensure runner functions run without error and return the "expected
# objects".
test_that("max cardinality search runners", {
  s <- c(1, 1, 2, 2, 2, 3, 4)
  t <- c(2, 4, 3, 4, 5, 5, 5)
  c <- c(6, 1, 5, 2, 2, 5, 1)
  n <- 5
  sn <- 5

  # Default startNode
  out <- MaxCardinalitySearchRunner(s, t, c, n)
  test_search(out, n, TRUE)

  out <- MaxCardinalitySearchRunner(s, t, c, n, sn)
  test_search(out, n, TRUE)
})

test_that("max cardinality search function", {
  s <- c(1, 1, 2, 2, 2, 3, 4)
  t <- c(2, 4, 3, 4, 5, 5, 5)
  c <- c(6, 1, 5, 2, 2, 5, 1)
  n <- 5
  sn <- 5

  # 2) Ensure exported functions run without error and return the "expected
  # objects".

  # default startNode
  out <- MaxCardinalitySearch(s, t, c, n)
  test_search(out, n, FALSE)

  # default startNode
  out <- MaxCardinalitySearch(s, t, c, n, sn)
  test_search(out, n, FALSE)

  # 3) Ensure exported functions with `algorithm=`default runs without error, and
  # returns the same if passed no argument
  out2 <- MaxCardinalitySearch(s, t, c, n, sn, algorithm = "maxcardinalitysearch")
  expect_identical(out, out2)

  # 4) Ensure exported functions work with all valid algorithms.
  # No alternative algorithms.

  # 5) Ensure exported functions fail if passed an invalid algorithm.
  expect_error(MaxCardinalitySearch(s, t, c, n, sn, algorithm = "abc"),
               "Invalid")
  expect_error(MaxCardinalitySearch(s, t, c, n, sn, algorithm = 1),
               "must be a string")
  expect_error(MaxCardinalitySearch(s, t, c, n, sn, algorithm = NULL),
               "must be a string")

})
