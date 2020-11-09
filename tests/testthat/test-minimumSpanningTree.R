test_that("Kruskal works", {
  s <- c(0,0,1,2,3,3)
  t <- c(1,2,2,3,0,1)
  d <- c(1,10,3,2,0,8)
  out <- KruskalRunner(s,t,d,4)
  expect_equal(out[[1]],c(3,0,2))
  expect_equal(out[[2]],c(0,1,3))
  expect_equal(out[[3]],3)
})

test_that("mincostarborescence works", {
  s <- c(0,1,2,3,4,5)
  t <- c(1,2,3,4,5,0)
  d <- c(1,10,3,2,0,8)
  out <- MinCostArborescenceRunner(s,t,d,0,6)
  expect_equal(out[[1]],c(0,1,2,3,4))
  expect_equal(out[[2]],c(1,2,3,4,5))
  expect_equal(out[[3]],16)
})
