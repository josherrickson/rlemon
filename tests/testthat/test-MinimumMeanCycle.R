test_that("multiplication works", {
  expect_equal(2 * 2, 4)
})

test_that("howard mmc works", {
  s <- c(0,0,1,2,3,3)
  t <- c(1,2,2,3,0,1)
  d <- c(1,10,3,2,0,8)
  out <- HowardMmcRunner(s,t,d,4)
  expect_equal(out[[1]],c(0,1,3,2))
  expect_equal(out[[2]],c(3,0,1,2))
})

test_that("karp mmc works", {
  s <- c(0,0,1,2,3,3)
  t <- c(1,2,2,3,0,1)
  d <- c(1,10,3,2,0,8)
  out <- KarpMmcRunner(s,t,d,4)
  expect_equal(out[[1]],c(0,1,3,2))
  expect_equal(out[[2]],c(3,0,1,2))
})

test_that("hartmannorlin mmc works", {
  s <- c(0,0,1,2,3,3)
  t <- c(1,2,2,3,0,1)
  d <- c(1,10,3,2,0,8)
  out <- HartmannOrlinMmcRunner(s,t,d,4)
  expect_equal(out[[1]],c(0,1,3,2))
  expect_equal(out[[2]],c(3,0,1,2))
})