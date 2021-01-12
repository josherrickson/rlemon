test_that("Planarity Checking", {
  s <- c(0,0,0,1,1,1,2,2,2)
  t <- c(3,4,5,3,4,5,3,4,5)
  out <- PlanarCheckingRunner(s,t,6)
  expect_is(out, "logical")
  expect_equal(out, FALSE)
})

test_that("Planar-Coloring Checking", {
  s <- c(0,0,0,1,1,1,2)
  t <- c(3,4,5,3,4,5,0)
  out <- PlanarColoringRunner(s,t,6)
  expect_is(out[[1]], "logical")
  expect_equal(out[[1]], TRUE)
  expect_equal(out[[2]], c(1,1,0,0,0,0))
  out <- PlanarColoringRunner(s,t,6,FALSE)
  expect_is(out[[1]], "logical")
  expect_equal(out[[1]], TRUE)
  expect_equal(out[[2]], c(1,1,0,0,0,0))
})


test_that("Planar-Embedding Checking", {
  s <- c(0,0,0,1,1,1,2)
  t <- c(3,4,5,3,4,5,0)
  out <- PlanarDrawingRunner(s,t,6)
  expect_is(out[[1]], "logical")
  expect_equal(out[[1]], TRUE)
  expect_equal(out[[2]], c(2,1,1,4,2,0))
  expect_equal(out[[3]], c(2,0,2,1,1,4))
})