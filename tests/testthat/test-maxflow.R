# Title            : Maximum Flow
# File             : R/maxflow.R
# Exported         : MaxFlow
# Valid Algorithms : "Preflow" (default), "EdmondsKarp"
# Runners          : PreflowRunner, EdmondsKarp

test_maxflow <- function(o, named = TRUE) {
  expect_true(is.list(o))
  expect_length(o, 3)
  expect_true(all(vapply(o, is.numeric, TRUE)))
  expect_length(o[[3]], 1)
  if (named) {
    expect_named(o, c("flows", "cut_values", "cost"))
  }
}

# 1) Ensure runner functions run without error and return the "expected
# objects".
test_that("max flow runners", {

  s <- c(1, 1, 2, 2, 3, 3, 4, 4, 5, 5)
  t <- c(2, 3, 3, 4, 2, 5, 3, 6, 4, 6)
  cap <- c(16, 13, 10, 124, 14, 9, 20, 7, 4, 0)

  out <- PreflowRunner(s, t, cap, 1, 6, 6)
  test_maxflow(out, named = FALSE)

  out <- EdmondsKarpRunner(s, t, cap, 1, 6, 6)
  test_maxflow(out, named = FALSE)

})


test_that("max flow function", {

  s <- c(1, 1, 2, 2, 3, 3, 4, 4, 5, 5)
  t <- c(2, 3, 3, 4, 2, 5, 3, 6, 4, 6)
  cap <- c(16, 13, 10, 124, 14, 9, 20, 7, 4, 0)

  # 2) Ensure exported functions run without error and return the "expected
  # objects".
  out <- MaxFlow(s, t, cap, 1, 6, 6)
  test_maxflow(out)

  # 3) Ensure exported functions with `algorithm=`default runs without error, and
  # returns the same if passed no argument
  out2 <- MaxFlow(s, t, cap, 1, 6, 6, algorithm = "Preflow")
  expect_identical(out, out2)

  # 4) Ensure exported functions work with all valid algorithms.
  out <- MaxFlow(s, t, cap, 1, 6, 6, algorithm = "EdmondsKarp")
  test_maxflow(out)

  # 5) Ensure exported functions fail if passed an invalid algorithm.
  expect_error(MaxFlow(s, t, cap, 1, 6, 6, algorithm = "abc"),
               "Invalid")
  expect_error(MaxFlow(s, t, cap, 1, 6, 6, algorithm = 1),
               "must be a string")
  expect_error(MaxFlow(s, t, cap, 1, 6, 6, algorithm = NULL),
               "must be a string")
})
