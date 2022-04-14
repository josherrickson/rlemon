# Title            : Minimum Mean Cycle
# File             : R/minmeancycle.R
# Exported         : MinMeanCycle
# Valid Algorithms : "Howard" (default), "Karp", "HartmannOrlin
# Runners          : HowardMmcRunner, KarpMmcRunner, HartmannOrlinMmcRunner

test_minmeancycle <- function(o) {
  expect_true(is.list(o))
  expect_length(o, 2)
  expect_true(all(vapply(o, is.numeric, TRUE)))
}

# 1) Ensure runner functions run without error and return the "expected
# objects".
test_that("min mean cycle runners", {

  s <- c(1, 1, 2, 3, 4, 4)
  t <- c(2, 3, 3, 4, 1, 2)
  d <- c(1, 10, 3, 2, 0, 8)

  out <- HowardMmcRunner(s, t, d, 4)
  test_minmeancycle(out)

  out <- KarpMmcRunner(s, t, d, 4)
  test_minmeancycle(out)

  out <- HartmannOrlinMmcRunner(s, t, d, 4)
  test_minmeancycle(out)

})

test_that("min mean cycle function", {

  s <- c(1, 1, 2, 3, 4, 4)
  t <- c(2, 3, 3, 4, 1, 2)
  d <- c(1, 10, 3, 2, 0, 8)

  # 2) Ensure exported functions run without error and return the "expected
  # objects".
  out <- MinMeanCycle(s, t, d, 4)
  test_minmeancycle(out)

  # 3) Ensure exported functions with `algorithm=`default runs without error, and
  # returns the same if passed no argument
  out2 <- MinMeanCycle(s, t, d, 4, algorithm = "Howard")
  expect_identical(out, out2)

  # 4) Ensure exported functions work with all valid algorithms.
  out <- MinMeanCycle(s, t, d, 4, algorithm = "Karp")
  test_minmeancycle(out)

  out <- MinMeanCycle(s, t, d, 4, algorithm = "HartmannOrlin")
  test_minmeancycle(out)


  # 5) Ensure exported functions fail if passed an invalid algorithm.
  expect_error(MinMeanCycle(s, t, d, 4, algorithm = "abc"),
               "Invalid")
  expect_error(MinMeanCycle(s, t, d, 4, algorithm = 1),
               "must be a string")
  expect_error(MinMeanCycle(s, t, d, 4, algorithm = NULL),
               "must be a string")
})
