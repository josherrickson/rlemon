

test_that("Preflow works", {
  s <- c(0,0,1,1,2,2,3,3,4,4)
  t <- c(1,2,2,3,1,4,2,5,3,5)
  cap <- c(16,13,10,124,14,9,20,7,4)
  out <- PreflowRunner(s,t,cap,0,5,6)
  expect_equal(out[[3]],7)
  expect_equal(out[[2]], c(1,1,1,1,1,0))
  expect_equal(out[[1]], c(7,0,0,21,14,4,18,7,4,0))
})

test_that("Edmonds-Karp works", {
  s <- c(0,0,1,1,2,2,3,3,4,4)
  t <- c(1,2,2,3,1,4,2,5,3,5)
  cap <- c(16,13,10,124,14,9,20,7,4)
  out <- EdmondsKarpRunner(s,t,cap,0,5,6)
  expect_equal(out[[3]],7)
  expect_equal(out[[2]], c(1,1,1,1,1,0), tolerance=0.1)
  expect_equal(out[[1]], c(7,0,0,7,0,0,0,7,0,0), tolerance=1)
})

test_that("Circulation works", {
  s <- c(0,0,1,1,2,2,3,3,4,4)
  t <- c(1,2,2,3,1,4,2,5,3,5)
  cap <- c(16,13,10,124,14,9,20,7,4)
  out <- CirculationRunner(s,t,cap,0,5,6)
  expect_equal(out[[1]], c( 16,21918,-450495744,21918,14,9,7969, 0,-396368256, 0), tolerance=1)
  expect_equal(out[[2]], c(1))
})