test_that("NagamochiIbaraki Test", {
  s <- c(1, 1, 2, 2, 3, 3, 4, 4, 5, 5)
  t <- c(2, 4, 3, 4, 4, 6, 2, 5, 3, 6)
  weights <- c(16, 13, 12, 10, 9, 20, 4, 14, 7, 4)
  numNodes <- 6
  out <- MinCut(s, t, weights, numNodes, "NagamochiIbaraki")
  expect_equal(out[[1]], 24)
  expect_equal(out[[2]], c(5))
  expect_equal(out[[3]], c(0, 1, 2, 3, 4))
  expect_error(MinCut(s, t, weights, 6, "abc"), "Invalid")
})

test_that("HaoOrlin Test", {
  s <- c(1, 1, 2, 2, 3, 3, 4, 4, 5, 5)
  t <- c(2, 4, 3, 4, 4, 6, 2, 5, 3, 6)
  weights <- c(16, 13, 12, 10, 9, 20, 4, 14, 7, 4)
  numNodes <- 6
  out <- MinCut(s, t, weights, numNodes, "HaoOrlin")
  expect_equal(out[[1]], 0)
  expect_equal(out[[2]], c(5))
  expect_equal(out[[3]], c(0, 1, 2, 3, 4))
})


test_that("GomoryHu Test", {
  s <- c(1, 1, 2, 2, 3, 3, 4, 4, 5, 5)
  t <- c(2, 4, 3, 4, 4, 6, 2, 5, 3, 6)
  weights <- c(16, 13, 12, 10, 9, 20, 4, 14, 7, 4)
  numNodes <- 6
  out <- AllPairsMinCut(s, t, weights, numNodes, "GomoryHu")
  expect_equal(out[[1]], c(2, 4, 6, 3, 4, -1))
  expect_equal(out[[2]], c(29, 39, 24, 32, 25, -1))
  expect_equal(out[[3]], c(5, 4, 1, 2, 3, 0))
})
