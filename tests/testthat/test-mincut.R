test_that("NagamochiIbaraki Test", {
   s <- c(0, 0, 1, 1, 2, 2, 3, 3, 4, 4)
   t <- c(1, 3, 2, 3, 3, 5, 1, 4, 2, 5)
   weights <- c(16, 13, 12, 10, 9, 20, 4, 14, 7, 4)
   numNodes <- 6
   out <- MinCut(s,t,weights,numNodes, "NagamochiIbaraki")
   expect_equal(out[[1]],24)
   expect_equal(out[[2]],c(5))
   expect_equal(out[[3]],c(0, 1, 2, 3, 4))
   expect_error(MinCut(s,t,weights,6,"abc"), "Invalid")
})

test_that("HaoOrlin Test", {
   s <- c(0, 0, 1, 1, 2, 2, 3, 3, 4, 4)
   t <- c(1, 3, 2, 3, 3, 5, 1, 4, 2, 5)
   weights <- c(16, 13, 12, 10, 9, 20, 4, 14, 7, 4)
   numNodes <- 6
   out <- MinCut(s,t,weights,numNodes, "HaoOrlin")
   expect_equal(out[[1]],24)
   expect_equal(out[[2]],c(5))
   expect_equal(out[[3]],c(0, 1, 2, 3, 4))
})


test_that("GomoryHu Test", {
   s <- c(0, 0, 1, 1, 2, 2, 3, 3, 4, 4)
   t <- c(1, 3, 2, 3, 3, 5, 1, 4, 2, 5)
   weights <- c(16, 13, 12, 10, 9, 20, 4, 14, 7, 4)
   numNodes <- 6
   out <- GomoryHuTree(s,t,weights,numNodes)
   expect_equal(out[[1]],c(1, 3, 5, 2, 3, -1))
   expect_equal(out[[2]],c(29, 39, 24, 32, 25, -1))
   expect_equal(out[[3]],c(5, 4, 1, 2, 3, 0))   
})

