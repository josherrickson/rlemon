

test_that("Preflow works", {
  s <- c(0,0,1,1,2,2,3,3,4,4)
  t <- c(1,2,2,3,1,4,2,5,3,5)
  cap <- c(16,13,10,124,14,9,20,7,4)
  out <- PreflowRunner(s,t,cap,0,5,6)
  expect_is(out[[3]],"integer")
  expect_is(out[[2]],"integer")
  expect_is(out[[1]], "integer")
})

test_that("Edmonds-Karp works", {
  s <- c(0,0,1,1,2,2,3,3,4,4)
  t <- c(1,2,2,3,1,4,2,5,3,5)
  cap <- c(16,13,10,124,14,9,20,7,4)
  out <- EdmondsKarpRunner(s,t,cap,0,5,6)
  expect_is(out[[3]],"integer")
  expect_is(out[[2]], "integer")
  expect_is(out[[1]], "integer")
})

test_that("Circulation works", {
  s <- c(0,0,1,1,2,2,3,3,4,4)
  t <- c(1,2,2,3,1,4,2,5,3,5)
  cap <- c(16,13,10,124,14,9,20,7,4)
  out <- CirculationRunner(s,t,cap,0,5,6)
  expect_is(out[[1]], "integer")
  expect_equal(out[[2]], c(1))
})