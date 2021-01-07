test_that("grosso locatelli works", {
  s <- c(0,1,2,3,4)
  t <- c(1,2,0,4,3)
  n <- 5
  out <- GrossoLocatelliPullanMcRunner(s,t,n)
  expect_equal(out[[1]],3)
  expect_equal(out[[2]],c(0,1,2))
})

test_that("maxclique works", {
  s <- c(0,1,2,3,4)
  t <- c(1,2,0,4,3)
  n <- 5
  out <- maxclique(s,t,n,"GrossoLocatelliPullanMc")
  expect_equal(out[[1]],3)
  expect_equal(out[[2]],c(0,1,2))
  expect_error(maxclique(s,t,n,"abc"), "Invalid")
})