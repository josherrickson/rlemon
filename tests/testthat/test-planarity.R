test_that("Planarity Checking", {
  s <- c(0,0,0,1,1,1,2,2,2)
  t <- c(3,4,5,3,4,5,3,4,5)
  out <- PlanarCheckingRunner(s,t,6)
  expect_is(out, "logical")
  expect_equal(out, FALSE)
})