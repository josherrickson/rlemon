test_that("Max Perfect Checking", {
  s <- c(0,0,0,1,1,1,2,2,2)
  t <- c(3,4,5,3,4,5,3,4,5)
  d <- c(1,2,3,4,5,6,7,8,9)
  out <- MaximumWeightPerfectMatchingRunner(s,t,d,6)
  expect_equal(out[[1]],15)
  expect_equal(out[[2]],list(c(0,3),c(1,4),c(2,5)))
})

test_that("Max Fractional Perfect Checking", {
  s <- c(0,0,0,1,1,1,2,2,2)
  t <- c(3,4,5,3,4,5,3,4,5)
  d <- c(1,2,3,4,5,6,7,8,9)
  out <- MaximumWeightFractionalPerfectMatchingRunner(s,t,d,6)
  expect_equal(out[[1]],30)
  expect_equal(out[[2]],list(c(0,3),c(1,4),c(2,5)))
})

test_that("Max Weight Fractional Checking", {
  s <- c(0,0,0,1,1,1,2,2,2)
  t <- c(3,4,5,3,4,5,3,4,5)
  d <- c(1,2,3,4,5,6,7,8,9)
  out <- MaximumWeightFractionalMatchingRunner(s,t,d,6)
  expect_equal(out[[1]],30)
  expect_equal(out[[2]],list(c(0,3),c(1,4),c(2,5)))
})

test_that("Max Weight Checking", {
  s <- c(0,0,0,1,1,1,2,2,2)
  t <- c(3,4,5,3,4,5,3,4,5)
  d <- c(1,2,3,4,5,6,7,8,9)
  out <- MaximumWeightMatchingRunner(s,t,d,6)
  expect_equal(out[[1]],15)
  expect_equal(out[[2]],list(c(0,3),c(1,4),c(2,5)))
})

test_that("Max Cardinality Checking", {
  s <- c(0,0,0,1,1,1,2,2,2)
  t <- c(3,4,5,3,4,5,3,4,5)
  d <- c(1,2,3,4,5,6,7,8,9)
  out <- MaximumCardinalityMatchingRunner(s,t,6)
  expect_equal(out[[2]],list(c(0,3),c(1,4),c(2,5)))
})

test_that("Max Cardinality Fractional Checking", {
  s <- c(0,0,0,1,1,1,2,2,2)
  t <- c(3,4,5,3,4,5,3,4,5)
  d <- c(1,2,3,4,5,6,7,8,9)
  out <- MaximumCardinalityFractionalMatchingRunner(s,t,6)
  expect_equal(out[[2]],list(c(0,5),c(1,4),c(2,3)))
})