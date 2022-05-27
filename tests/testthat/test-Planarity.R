# Title            : Planarity
# File             : R/planarityembedding.R
# Exported         : PlanarChecking, PlanarEmbedding, PlanarColoring,
#                    PlanarDrawing
# Valid Algorithms : Only for Planar Coloring, "fiveColoring" (default),
#                    "sixColoring"
# Runners          : PlanarCheckingRunner, PlanarEmbeddingRunner,
#                    PlanarColoringRunner (`useFiveAlg` TRUE or FALSE),
#                    PlanarDrawingRunner

######### Planar Checking

test_that("Planarity Checking", {

  s <- c(1, 1, 1, 2, 2, 2, 3, 3, 3)
  t <- c(4, 5, 6, 4, 5, 6, 4, 5, 6)

  # 1) Ensure runner functions run without error and return the "expected
  # objects".
  out <- PlanarCheckingRunner(s, t, 6)
  expect_is(out, "logical")
  expect_length(out, 1)

  # 2) Ensure exported functions run without error and return the "expected
  # objects".
  out <- PlanarChecking(s, t, 6)
  expect_is(out, "logical")
  expect_length(out, 1)

  # 3) Ensure exported functions with `algorithm=`default runs without error, and
  # returns the same if passed no argument
  # No algorithm

  # 4) Ensure exported functions work with all valid algorithms.
  # No alternate algorithsm

  # 5) Ensure exported functions fail if passed an invalid algorithm.
  # No algorithm
})


######### Planar Embedding

test_embedding <- function(o, isrunner) {
  expect_is(o, "list")
  expect_length(o, 5)
  if (isrunner) {
    expect_true(all(vapply(o, is.numeric, TRUE)))
  } else {
    expect_true(all(vapply(o[2:5], is.numeric, TRUE)))
    expect_true(is.logical(o[[1]]))
    expect_named(o, c("is_planar", "start_nodes_embedding",
                      "end_nodes_embedding", "start_nodes_kuratowski",
                      "end_nodes_kuratowski"))
  }
  expect_equal(length(o[[2]]), length(o[[3]]))
  expect_equal(length(o[[4]]), length(o[[5]]))
}

test_that("Planarity Embedding", {

  # Variation 1
  s <- c(1, 1, 1, 2, 2, 2, 3, 3, 3)
  t <- c(4, 5, 6, 4, 5, 6, 4, 5, 6)

  # 1) Ensure runner functions run without error and return the "expected
  # objects".
  out <- PlanarEmbeddingRunner(s, t, 6)
  test_embedding(out, TRUE)

  # 2) Ensure exported functions run without error and return the "expected
  # objects".
  out <- PlanarEmbedding(s, t, 6)
  test_embedding(out, FALSE)

  # 3) Ensure exported functions with `algorithm=`default runs without error, and
  # returns the same if passed no argument
  # No algorithm

  # 4) Ensure exported functions work with all valid algorithms.
  # No alternate algorithsm

  # 5) Ensure exported functions fail if passed an invalid algorithm.
  # No algorithm

  # Variation 2
  s <- c(1, 1, 1, 2, 2, 2, 3)
  t <- c(4, 5, 6, 4, 5, 6, 4)

  # 1) Ensure runner functions run without error and return the "expected
  # objects".
  out <- PlanarEmbeddingRunner(s, t, 6)
  test_embedding(out, TRUE)

  # 2) Ensure exported functions run without error and return the "expected
  # objects".
  out <- PlanarEmbedding(s, t, 6)
  test_embedding(out, FALSE)

  # 3) Ensure exported functions with `algorithm=`default runs without error, and
  # returns the same if passed no argument
  # No algorithm

  # 4) Ensure exported functions work with all valid algorithms.
  # No alternate algorithsm

  # 5) Ensure exported functions fail if passed an invalid algorithm.
  # No algorithm
})


######### Planar Coloring

test_coloring <- function(o, n, ncolor, named = TRUE) {
  expect_is(o, "list")
  expect_length(o, 2)
  expect_is(o[[1]], "logical")
  expect_length(o[[1]], 1)
  expect_true(is.numeric(o[[2]]))
  expect_length(o[[2]], n)
  expect_true(all(o[[2]] < ncolor))
  if (named) {
    expect_named(o, c("is_planar", "colors"))
  }
}

# 1) Ensure runner functions run without error and return the "expected
# objects".
test_that("Planar Coloring runner", {
  s <- c(1, 1, 1, 2, 2, 2, 3)
  t <- c(4, 5, 6, 4, 5, 6, 1)

  out <- PlanarColoringRunner(s, t, 6, TRUE) # TRUE is 5-coloring
  test_coloring(out, 6, 5, named = FALSE)
  out <- PlanarColoringRunner(s, t, 6, FALSE) # FALSE is 6-coloring
  test_coloring(out, 6, 6, named = FALSE)
})

test_that("Planar Coloring functions", {
  s <- c(1, 1, 1, 2, 2, 2, 3)
  t <- c(4, 5, 6, 4, 5, 6, 1)

  # 2) Ensure exported functions run without error and return the "expected
  # objects".
  out <- PlanarColoring(s, t, 6)
  test_coloring(out, 6, 5)

  # 3) Ensure exported functions with `algorithm=`default runs without error, and
  # returns the same if passed no argument
  out2 <- PlanarColoring(s, t, 6, algorithm = "fiveColoring")
  test_coloring(out, 6, 5)

  # 4) Ensure exported functions work with all valid algorithms.
  out <- PlanarColoring(s, t, 6, algorithm = "sixColoring")
  test_coloring(out, 6, 6)


  # 5) Ensure exported functions fail if passed an invalid algorithm.
  expect_error(PlanarColoring(s, t, 6, algorithm = "abc"),
               "Invalid")
  expect_error(PlanarColoring(s, t, 6, algorithm = 1),
               "must be a string")
  expect_error(PlanarColoring(s, t, 6, algorithm = NULL),
               "must be a string")
})


######### Planar Drawing

test_drawing <- function(o, named = TRUE) {
  expect_is(o, "list")
  expect_length(o, 3)
  expect_is(o[[1]], "logical")
  expect_length(o[[1]], 1)
  expect_true(all(vapply(o[2:3], is.numeric, TRUE)))
  expect_equal(length(o[[2]]), length(o[[3]]))
  if (named) {
    expect_named(o, c("is_planar", "x_coords", "y_coords"))
  }
}

test_that("Planarity Drawing", {

  # Variation 1
  s <- c(1, 1, 1, 2, 2, 2, 3)
  t <- c(4, 5, 6, 4, 5, 6, 1)

  # 1) Ensure runner functions run without error and return the "expected
  # objects".
  out <- PlanarDrawingRunner(s, t, 6)
  test_drawing(out, named = FALSE)

  # 2) Ensure exported functions run without error and return the "expected
  # objects".
  out <- PlanarDrawing(s, t, 6)
  test_drawing(out)

  # 3) Ensure exported functions with `algorithm=`default runs without error, and
  # returns the same if passed no argument
  # No algorithm

  # 4) Ensure exported functions work with all valid algorithms.
  # No alternate algorithsm

  # 5) Ensure exported functions fail if passed an invalid algorithm.
  # No algorithm

})
