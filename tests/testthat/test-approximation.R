# Approximation
# Runners: GrossoLocatelliPullanMcRunner
# Exported: MaxCliuque
# Valid Algorithms: "GrossoLocatelliPullanMc"

# 1) Ensure runner functions run without error and return the "expected
# objects".
test_that("Approxmiation runner", {
  s <- c(1, 2, 3, 4, 5)
  t <- c(2, 3, 1, 5, 4)
  n <- 5
  out <- GrossoLocatelliPullanMcRunner(s, t, n)
  expect_true(is.list(out))
  expect_length(out, 2)
  expect_length(out[[1]], 1)
  expect_true(all(out[[2]] %in% s))
})

test_that("Approximation functions", {
  s <- c(1, 2, 3, 4, 5)
  t <- c(2, 3, 1, 5, 4)
  n <- 5
  out <- MaxClique(s, t, n)
  # 2) Ensure exported functions run without error and return the "expected
  # objects".
  expect_true(is.list(out))
  expect_length(out, 2)
  expect_length(out[[1]], 1)
  expect_true(all(out[[2]] %in% s))

  # 3) Ensure exported functions with algorithm= run without error on default,
  # and return the same if passed the default argument.
  out2 <- MaxClique(s, t, n, algorithm = "GrossoLocatelliPullanMc")
  expect_identical(out, out2)

  # 4) Ensure exported functions work with all valid algorithms.

  # 5) Ensure exported functions fail if passed an invalid algorithm.
  expect_error(MaxClique(s, t, n, algorithm = "abc"),
               "Invalid")
  expect_error(MaxClique(s, t, n, algorithm = 1),
               "must be string")
  expect_error(MaxClique(s, t, n, algorithm = NULL),
               "must be string")
})
