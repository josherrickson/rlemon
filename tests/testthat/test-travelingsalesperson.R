# Title            : Traveling Salesperson
# File             : R/travellingsalespersonproblem.R
# Exported         : TravelingSalesperson/TravellingSalesperson
# Valid Algorithms : "Christofides" (default), "Greedy", "Insertion",
#                    "NearestNeighbor", "Opt2"
# Runners          : ChristofidesRunner, GreedyTSPRunner, InsertionTSPRunner,
#                    NearestNeighborTSPRunner, Opt2TSPRunner

test_tsp <- function(o, addEdges, weight, named = TRUE) {
  expect_true(is.list(o))
  expect_length(o, 2)
  expect_true(all(o[[1]] %in% seq_along(o[[1]])))
  # If edges weren't added, total length should be less than weight (assuming
  # weight is very large)
  if (addEdges == FALSE) {
    expect_true(o[[2]] < weight)
  }
  # if edges were added, we traveled along at least one so total length is
  # higher than weights
  if (addEdges == TRUE) {
    expect_true(o[[2]] > weight)
  }

  if (named) {
    expect_named(o, c("node_order", "cost"))
  }
}

# 1) Ensure runner functions run without error and return the "expected
# objects".
test_that("traveling salesperson runners", {

  # No new edges needed
  s <- c(1, 1, 1, 2, 2, 3)
  t <- c(2, 3, 4, 3, 4, 4)
  d <- c(1, 2, 3, 4, 5, 6)

  # default defaultEdgeWeight
  out <- ChristofidesRunner(s, t, d, 4)
  test_tsp(out, FALSE, 999999, named = FALSE)

  out <- GreedyTSPRunner(s, t, d, 4)
  test_tsp(out, FALSE, 999999, named = FALSE)

  out <- InsertionTSPRunner(s, t, d, 4)
  test_tsp(out, FALSE, 999999, named = FALSE)

  out <- NearestNeighborTSPRunner(s, t, d, 4)
  test_tsp(out, FALSE, 999999, named = FALSE)

  out <- Opt2TSPRunner(s, t, d, 4)
  test_tsp(out, FALSE, 999999, named = FALSE)

  # Set defaultEdgeWeight
  out <- ChristofidesRunner(s, t, d, 4, 123456)
  test_tsp(out, FALSE, 123456, named = FALSE)

  out <- GreedyTSPRunner(s, t, d, 4, 123456)
  test_tsp(out, FALSE, 123456, named = FALSE)

  out <- InsertionTSPRunner(s, t, d, 4, 123456)
  test_tsp(out, FALSE, 123456, named = FALSE)

  out <- NearestNeighborTSPRunner(s, t, d, 4, 123456)
  test_tsp(out, FALSE, 123456, named = FALSE)

  out <- Opt2TSPRunner(s, t, d, 4, 123456)
  test_tsp(out, FALSE, 123456, named = FALSE)

  # New edges needed
  s <- c(1, 1, 2)
  t <- c(2, 3, 3)
  d <- c(1, 2, 4)
  # assume still 4 nodes, no edge to node 4

  # default defaultEdgeWeight
  out <- ChristofidesRunner(s, t, d, 4)
  test_tsp(out, TRUE, 999999, named = FALSE)

  out <- GreedyTSPRunner(s, t, d, 4)
  test_tsp(out, TRUE, 999999, named = FALSE)

  out <- InsertionTSPRunner(s, t, d, 4)
  test_tsp(out, TRUE, 999999, named = FALSE)

  out <- NearestNeighborTSPRunner(s, t, d, 4)
  test_tsp(out, TRUE, 999999, named = FALSE)

  out <- Opt2TSPRunner(s, t, d, 4)
  test_tsp(out, TRUE, 999999, named = FALSE)

  # Set defaultEdgeWeight
  out <- ChristofidesRunner(s, t, d, 4, 123456)
  test_tsp(out, TRUE, 123456, named = FALSE)

  out <- GreedyTSPRunner(s, t, d, 4, 123456)
  test_tsp(out, TRUE, 123456, named = FALSE)

  out <- InsertionTSPRunner(s, t, d, 4, 123456)
  test_tsp(out, TRUE, 123456, named = FALSE)

  out <- NearestNeighborTSPRunner(s, t, d, 4, 123456)
  test_tsp(out, TRUE, 123456, named = FALSE)

  out <- Opt2TSPRunner(s, t, d, 4, 123456)
  test_tsp(out, TRUE, 123456, named = FALSE)

})

test_that("Spelling of function", {
  expect_identical(TravelingSalesperson, TravellingSalesperson)
})


test_that("traveling salesperson function, no new edges", {

  s <- c(1, 1, 1, 2, 2, 3)
  t <- c(2, 3, 4, 3, 4, 4)
  d <- c(1, 2, 3, 4, 5, 6)

  # 2) Ensure exported functions run without error and return the "expected
  # objects".
  # no defaultEdgeWeight
  out_a <- TravellingSalesperson(s, t, d, 4)
  test_tsp(out_a, FALSE, 999999)
  # set defaultEdgeWeight
  out_b <- TravellingSalesperson(s, t, d, 4, 123456)
  test_tsp(out_b, FALSE, 123456)

  # 3) Ensure exported functions with `algorithm=`default runs without error, and
  # returns the same if passed no argument
  out_a2 <- TravellingSalesperson(s, t, d, 4, algorithm = "Christofides")
  expect_identical(out_a, out_a2)
  out_b2 <- TravellingSalesperson(s, t, d, 4, 123456, algorithm = "Christofides")
  expect_identical(out_b, out_a2)

  # 4) Ensure exported functions work with all valid algorithms.
  # no defaultEdgeWeight
  out <- TravellingSalesperson(s, t, d, 4, algorithm = "Greedy")
  test_tsp(out, FALSE, 999999)
  out <- TravellingSalesperson(s, t, d, 4, algorithm = "Insertion")
  test_tsp(out, FALSE, 999999)
  out <- TravellingSalesperson(s, t, d, 4, algorithm = "NearestNeighbor")
  test_tsp(out, FALSE, 999999)
  out <- TravellingSalesperson(s, t, d, 4, algorithm = "Opt2")
  test_tsp(out, FALSE, 999999)
  # set defaultEdgeWeight
  out <- TravellingSalesperson(s, t, d, 4, 123456, algorithm = "Greedy")
  test_tsp(out, FALSE, 123456)
  out <- TravellingSalesperson(s, t, d, 4, 123456, algorithm = "Insertion")
  test_tsp(out, FALSE, 123456)
  out <- TravellingSalesperson(s, t, d, 4, 123456, algorithm = "NearestNeighbor")
  test_tsp(out, FALSE, 123456)
  out <- TravellingSalesperson(s, t, d, 4, 123456, algorithm = "Opt2")
  test_tsp(out, FALSE, 123456)

})

test_that("traveling salesperson function, with new edges", {

  s <- c(1, 1, 2)
  t <- c(2, 3, 3)
  d <- c(1, 2, 4)

  # 2) Ensure exported functions run without error and return the "expected
  # objects".
  # no defaultEdgeWeight
  out_a <- TravellingSalesperson(s, t, d, 4)
  test_tsp(out_a, TRUE, 999999)
  # set defaultEdgeWeight
  out_b <- TravellingSalesperson(s, t, d, 4, 123456)
  test_tsp(out_b, TRUE, 123456)

  # 3) Ensure exported functions with `algorithm=`default runs without error, and
  # returns the same if passed no argument
  out_a2 <- TravellingSalesperson(s, t, d, 4, algorithm = "Christofides")
  expect_identical(out_a, out_a2)
  out_b2 <- TravellingSalesperson(s, t, d, 4, 123456, algorithm = "Christofides")
  expect_identical(out_b, out_a2)

  # 4) Ensure exported functions work with all valid algorithms.
  # no defaultEdgeWeight
  out <- TravellingSalesperson(s, t, d, 4, algorithm = "Greedy")
  test_tsp(out, TRUE, 999999)
  out <- TravellingSalesperson(s, t, d, 4, algorithm = "Insertion")
  test_tsp(out, TRUE, 999999)
  out <- TravellingSalesperson(s, t, d, 4, algorithm = "NearestNeighbor")
  test_tsp(out, TRUE, 999999)
  out <- TravellingSalesperson(s, t, d, 4, algorithm = "Opt2")
  test_tsp(out, TRUE, 999999)
  # set defaultEdgeWeight
  out <- TravellingSalesperson(s, t, d, 4, 123456, algorithm = "Greedy")
  test_tsp(out, TRUE, 123456)
  out <- TravellingSalesperson(s, t, d, 4, 123456, algorithm = "Insertion")
  test_tsp(out, TRUE, 123456)
  out <- TravellingSalesperson(s, t, d, 4, 123456, algorithm = "NearestNeighbor")
  test_tsp(out, TRUE, 123456)
  out <- TravellingSalesperson(s, t, d, 4, 123456, algorithm = "Opt2")
  test_tsp(out, TRUE, 123456)

})

# 5) Ensure exported functions fail if passed an invalid algorithm.
test_that("travellingsalesperson, invalid algorithm", {
  s <- c(1, 1, 2)
  t <- c(2, 3, 3)
  d <- c(1, 2, 4)

  expect_error(TravellingSalesperson(s, t, d, 4, algorithm = "abc"),
               "Invalid")
  expect_error(TravellingSalesperson(s, t, d, 4, algorithm = 1),
               "must be a string")
  expect_error(TravellingSalesperson(s, t, d, 4, algorithm = NULL),
               "must be a string")
})
