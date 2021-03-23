test_that("grosso locatelli works", {
  s <- c(1, 2, 3, 4, 5)
  t <- c(2, 3, 1, 5, 4)
  n <- 5
  out <- GrossoLocatelliPullanMcRunner(s, t, n)
  expect_equal(out[[1]], 3)
  expect_equal(out[[2]], c(1, 2, 3))
})

test_that("maxclique works", {
  s <- c(1, 2, 3, 4, 5)
  t <- c(2, 3, 1, 5, 4)
  n <- 5
  out <- MaxClique(s, t, n, "GrossoLocatelliPullanMc")
  expect_equal(out[[1]], 3)
  expect_equal(out[[2]], c(1, 2, 3))
  expect_error(MaxClique(s, t, n, "abc"), "Invalid")
})
