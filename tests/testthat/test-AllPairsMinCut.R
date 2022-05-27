# Title            : All Pairs Min Cut
# File             : R/mincut.R
# Exported         : AllPairsMinCut
# Valid Algorithms : "GomoryHu" (default)
# Runners          : GomoryHuTreeRunner

test_allpairsmincut <- function(o, named = TRUE) {
  expect_true(is.list(o))
  expect_length(o, 3)
  expect_true(all(vapply(o[1:3], is.numeric, TRUE)))
  if (named) {
    c("predecessors", "weights", "distances")
  }
}

# 1) Ensure runner functions run without error and return the "expected
# objects".
test_that("min cut runners", {

  s <- c(1, 1, 2, 2, 3, 3, 4, 4, 5, 5)
  t <- c(2, 4, 3, 4, 4, 6, 2, 5, 3, 6)
  weights <- c(16, 13, 12, 10, 9, 20, 4, 14, 7, 4)
  numNodes <- 6

  out <- GomoryHuTreeRunner(s, t, weights, numNodes)
  test_allpairsmincut(out, named = FALSE)

})

test_that("min cut function", {

  s <- c(1, 1, 2, 2, 3, 3, 4, 4, 5, 5)
  t <- c(2, 4, 3, 4, 4, 6, 2, 5, 3, 6)
  weights <- c(16, 13, 12, 10, 9, 20, 4, 14, 7, 4)
  numNodes <- 6

  # 2) Ensure exported functions run without error and return the "expected
  # objects".
  out <- AllPairsMinCut(s, t, weights, numNodes)
  test_allpairsmincut(out)

  # 3) Ensure exported functions with `algorithm=`default runs without error, and
  # returns the same if passed no argument
  out2 <- AllPairsMinCut(s, t, weights, numNodes, algorithm = "GomoryHu")
  expect_identical(out, out2)

  # 4) Ensure exported functions work with all valid algorithms.
  # No alternative algorithms

  # 5) Ensure exported functions fail if passed an invalid algorithm.
  expect_error(AllPairsMinCut(s, t, weights, numNodes, algorithm = "abc"),
               "Invalid")
  expect_error(AllPairsMinCut(s, t, weights, numNodes, algorithm = 1),
               "must be a string")
  expect_error(AllPairsMinCut(s, t, weights, numNodes, algorithm = NULL),
               "must be a string")
})
