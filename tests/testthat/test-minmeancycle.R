test_that("howard mmc works", {
  s <- c(1, 1, 2, 3, 4, 4)
  t <- c(2, 3, 3, 4, 1, 2)
  d <- c(1, 10, 3, 2, 0, 8)
  out <- MinMeanCycle(s, t, d, 4, "Howard")
  expect_equal(out[[1]], c(0, 1, 3, 2))
  expect_equal(out[[2]], c(4, 1, 2, 3))
  expect_error(MinMeanCycle(s, t, d, 4, "abc"), "Invalid")
})

test_that("karp mmc works", {
  s <- c(1, 1, 2, 3, 4, 4)
  t <- c(2, 3, 3, 4, 1, 2)
  d <- c(1, 10, 3, 2, 0, 8)
  out <- MinMeanCycle(s, t, d, 4, "Karp")
  expect_equal(out[[1]], c(0, 1, 3, 2))
  expect_equal(out[[2]], c(4, 1, 2, 3))
})

test_that("hartmannorlin mmc works", {
  s <- c(1, 1, 2, 3, 4, 4)
  t <- c(2, 3, 3, 4, 1, 2)
  d <- c(1, 10, 3, 2, 0, 8)
  out <- MinMeanCycle(s, t, d, 4, "HartmannOrlin")
  expect_equal(out[[1]], c(0, 1, 3, 2))
  expect_equal(out[[2]], c(4, 1, 2, 3))
})
