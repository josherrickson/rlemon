# Title            : Network Circulation
# File             : R/maxflow.R
# Exported         : NetworkCirculation
# Valid Algorithms : "Circulation" (default)
# Runners          : CirculationRunner

# 1) Ensure runner functions run without error and return the "expected
# objects".
test_that("circulation runners", {
  s <- c(1, 1, 2, 2, 3, 3, 4, 4, 5, 5)
  t <- c(2, 3, 3, 4, 2, 5, 3, 6, 4, 6)
  cap <- c(16, 13, 10, 124, 14, 9, 20, 7, 4, 0)
  lower <- c(0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
  upper <- c(16, 13, 10, 124, 14, 9, 20, 7, 4, 0)
  supplies <- c(1, 2, 3, 4, 5, 6)

  out <- CirculationRunner(s, t, lower, upper, supplies, 6)
  expect_true(is.list(out))
  expect_length(out, 2)
  expect_true(all(vapply(out, is.numeric, TRUE)))
})


test_that("circulation function", {

  s <- c(1, 1, 2, 2, 3, 3, 4, 4, 5, 5)
  t <- c(2, 3, 3, 4, 2, 5, 3, 6, 4, 6)
  cap <- c(16, 13, 10, 124, 14, 9, 20, 7, 4, 0)
  lower <- c(0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
  upper <- c(16, 13, 10, 124, 14, 9, 20, 7, 4, 0)
  supplies <- c(1, 2, 3, 4, 5, 6)

  # 2) Ensure exported functions run without error and return the "expected
  # objects".
  out <- NetworkCirculation(s, t, lower, upper, supplies, 6)
  expect_true(is.list(out))
  expect_length(out, 2)
  expect_true(all(vapply(out, is.numeric, TRUE)))

  # 3) Ensure exported functions with `algorithm=`default runs without error, and
  # returns the same if passed no argument
  out2 <- NetworkCirculation(s, t, lower, upper, supplies, 6,
                             algorithm = "Circulation")
  expect_identical(out, out2)

  # 4) Ensure exported functions work with all valid algorithms.
  # No alternative algorithms

  # 5) Ensure exported functions fail if passed an invalid algorithm.
  expect_error(NetworkCirculation(s, t, lower, upper, supplies, 6,
                                  algorithm = "abc"),
               "Invalid")
  expect_error(NetworkCirculation(s, t, lower, upper, supplies, 6,
                                  algorithm = 1),
               "must be a string")
  expect_error(NetworkCirculation(s, t, lower, upper, supplies, 6,
                                  algorithm = NULL),
               "must be a string")
})
