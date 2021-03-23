context("Basic test")

test_that("Calling a function works", {
  s <- c(1, 2, 3)
  t <- c(4, 4, 5)
  n <- 6
  out <- IsConnected(s, t, n)
  expect_is(out, "integer")
  expect_equal(out, 0)
})
