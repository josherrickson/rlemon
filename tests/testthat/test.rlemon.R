context("Basic test")

test_that("Calling a function works", {
   s <- c(1,2,3)
   t <- c(4,4,5)
   n <- 5
   out <- getBipartitePartitions(s, t, n)
   expect_is(out, "list")
   expect_length(out, 2)
})
