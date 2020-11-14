context("Check for issues with graph")

test_that("check_graph", {

  s <- c(1,2)
  t <- c(3,4)
  ca <- c(1,1)
  co <- c(1,1)
  s <- c(1,1)
  n <- 4

  expect_true(check_graph(s, t, ca, co, s, n))
  expect_silent(check_graph(s, t, ca, co, s, n))

  expect_error(check_graph(s, 1, ca, co, s, n))

  expect_error(check_graph(s, c(1.1, 2.1), ca, co, s, n))

})
