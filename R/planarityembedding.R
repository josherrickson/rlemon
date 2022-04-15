##' Checks if an undirected graph is planar.
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00617.html#ga230242aa2ee36f9b1b5a58f2c53016eb}
##' for more information.
##'
##' @title Check if Graph is Planar
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A \code{logical} stating if the graph is planar or not.
##' @export
PlanarChecking <- function(arcSources,
                           arcTargets,
                           numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  PlanarCheckingRunner(arcSources, arcTargets, numNodes)
}

##' Checks if an undirected graph is planar and returns a list of outputs
##' related to the planar embedding
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00308.html}
##' for more information.
##'
##' @title Solver for Planar Embedding
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A list containing 1) A logical indicating if the graph is planar, 2)
##'   the start nodes of the arcs of the embedding, 3) the end nodes of the arcs
##'   of the planar embedding, 4) the start nodes of the edges of the kuratowski
##'   subdivision, 5) the end nodes of the edges of the kuratowski subdivision.
##' @export
PlanarEmbedding <- function(arcSources,
                            arcTargets,
                            numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  out <- PlanarEmbeddingRunner(arcSources, arcTargets, numNodes)
  out[[1]] <- as.logical(out[[1]])
  out
}

##' Checks if a graph is planar and returns the coloring of the graph
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00306.html}
##' for more information.
##'
##' @title Solver for Planar Coloring
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @param algorithm, the algorithm to use. "sixColoring" generates a 6-coloring
##'   of the graph, while "fiveColoring" generates a 5-coloring.
##' @return A list containing 1) A \code{logical} if the graph is planar, 2) the
##'   color of each vertex of the graph
##' @export
PlanarColoring <- function(arcSources,
                           arcTargets,
                           numNodes,
                           algorithm = "fiveColoring") {

  check_graph_vertices(arcSources, arcTargets, numNodes)
  check_algorithm(algorithm)

  switch(algorithm,
         "fiveColoring" = PlanarColoringRunner(arcSources, arcTargets, numNodes,
                                               useFiveAlg = TRUE),
         "sixColoring" = PlanarColoringRunner(arcSources, arcTargets, numNodes,
                                              useFiveAlg = FALSE),
         stop("Invalid algorithm.")
         )
}

##' The planar drawing algorithm calculates positions for the nodes in the
##' plane. These coordinates satisfy that if the edges are represented with
##' straight lines, then they will not intersect each other.
##'
##' See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00307.html}
##' for more information.
##'
##' @title Solver for Planar Drawing
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A list of 1) a \code{logical} of if the graph is planar, 2) the
##'   x-coordinate of the planar embedding, 3) the y-coordinate of the planar
##'   embedding
##' @export
PlanarDrawing <- function(arcSources,
                          arcTargets,
                          numNodes) {

  check_graph_vertices(arcSources, arcTargets, numNodes)

  PlanarDrawingRunner(arcSources, arcTargets, numNodes)
}
