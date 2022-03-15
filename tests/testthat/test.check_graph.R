context("Check for issues with graph")

test_that("check_graph", {
  s <- c(1, 2)
  t <- c(3, 4)
  ca <- c(1, 1)
  co <- c(1, 1)
  s <- c(1, 1)
  n <- 4

  expect_true(check_graph(s, t, ca, co, s, n))
  expect_silent(check_graph(s, t, ca, co, s, n))

  expect_error(check_graph(s, 1, ca, co, s, n))

  expect_error(check_graph(s, c(1.1, 2.1), ca, co, s, n))
})

test_that("check_graph_vertices", {
  s <- c(1, 2)
  t <- c(3, 4, 5)
  n <- 5
  expect_error(check_graph_vertices(s, t, n))
  s <- c(1, 2, 5)
  t <- c(3, 4, 3)
  n <- 4
  expect_error(check_graph_vertices(s, t, n))
  s <- c(1, 2, 5)
  t <- c(3, 4, 3)
  n <- 4
  expect_error(check_graph_vertices(s, t, n))
  s <- c(0, 2, 4)
  t <- c(3, 4, 3)
  n <- 4
  expect_error(check_graph_vertices(s, t, n))
  s <- c(1, 2, 4)
  t <- c(3, 4, 5)
  n <- 4
  expect_error(check_graph_vertices(s, t, n))
  s <- c(1, 2, 4)
  t <- c(0, 4, 3)
  n <- 4
  expect_error(check_graph_vertices(s, t, n))

  s <- c(1.5, 2.5, 3.5)
  t <- 1:3
  expect_error(check_graph_vertices(s, t, n))


})

test_that("check_arc_map", {
  s <- c(1, 2, 3)
  t <- c(4, 5, 6, 3)
  m <- c(2, 3, 4, 5)
  n <- 6
  expect_error(check_arc_map(s, t, m, n))
  s <- c(1, 2, 3, 4)
  t <- c(4, 5, 6)
  m <- c(2, 3, 4, 5)
  n <- 6
  expect_error(check_arc_map(s, t, m, n))
})

test_that("check_node_map", {
  m <- c(1, 2)
  n <- 3
  expect_error(check_node_map(m, n))
})

test_that("check_node", {
  t <- 2.5
  n <- 3
  expect_error(check_node(t, n))
  t <- 3
  n <- 2
  expect_error(check_node(t, n))
  t <- 0
  n <- 2
  expect_error(check_node(t, n))
})

test_that("check_graph_arcs", {
  s <- c(1, 2)
  t <- c(1, 2, 3)
  expect_error(check_graph_arcs(s, t))
  s <- c(1.5, 2, 3)
  t <- c(1, 2, 3)
  expect_error(check_graph_arcs(s, t))
  s <- c(1, 2, 3)
  t <- c(1.5, 2, 3)
  expect_error(check_graph_arcs(s, t))
  s <- c(1, 2, 3)
  t <- c(1, 2, 3)
  expect_true(check_graph_arcs(s, t))
})

test_that("check_algorithm", {
  expect_error(check_algorithm(1))
  expect_error(check_algorithm(NULL))
  expect_error(check_algorithm(data.frame("a")))
  expect_error(check_algorithm(matrix("a")))
  expect_error(check_algorithm(c("a", "b")))

  expect_true(check_algorithm("abc"))
})
