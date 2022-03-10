##' Checks if an undirected graph is planar.
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00617.html#ga230242aa2ee36f9b1b5a58f2c53016eb'
##' for more information.
##'
##' @title PlanarChecking
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A boolean stating if the graph is planar or not.
##' @export
PlanarChecking <- function(arcSources,
                           arcTargets,
                           numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(`_rlemon_PlanarCheckingRunner`, arcSources, arcTargets, numNodes)
}

##' Checks if an undirected graph is planar and returns a list of outputs
##' related to the planar embedding
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00308.html'
##' for more information.
##'
##' @title PlanarEmbedding
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A list containing 1) A boolean if the graph is planar, 2) the start
##'   nodes of the arcs of the embedding, 3) the end nodes of the arcs of the
##'   planar embedding, 4) the start nodes of the edges of the kuratowski
##'   subdivision, 5) the end nodes of the edges of the kuratowski subdivision.
##' @export
PlanarEmbedding <- function(arcSources,
                            arcTargets,
                            numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(`_rlemon_PlanarEmbeddingRunner`, arcSources, arcTargets, numNodes)
}

##' Checks if a graph is planar and returns the coloring of the graph
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00306.html'
##' for more information.
##'
##' @title PlanarColoring
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @param algorithm, the algorithm to use. "sixColoring" generates a 6-coloring
##'   of the graph, while "fiveColoring" generates a 5-coloring.
##' @return A list containing 1) A boolean if the graph is planar, 2) the color
##'   of each vertex of the graph
##' @export
PlanarColoring <- function(arcSources,
                           arcTargets,
                           numNodes,
                           algorithm = "fiveColoring") {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  switch(algorithm,
    "fiveColoring" = .Call(
      `_rlemon_PlanarColoringRunner`, arcSources,
      arcTargets, numNodes, TRUE
    ),
    "sixColoring" = .Call(
      `_rlemon_PlanarColoringRunner`, arcSources,
      arcTargets, numNodes, FALSE
    ),
    stop("Invalid algorithm.")
  )
}

##' Checks if a graph is planar and returns the coloring of the graph
##' See 'https://lemon.cs.elte.hu/pub/doc/1.3.1/a00307.html'
##' for more information.
##'
##' @title PlanarDrawing
##' @param arcSources Vector corresponding to the source nodes of a graph's
##'   edges
##' @param arcTargets Vector corresponding to the destination nodes of a graph's
##'   edges
##' @param numNodes The number of nodes in the graph
##' @return A list of 1) a boolean of if the graph is planar, 2) the
##'   x-coordinate of the planar embedding, 3) the y-coordinate of the planar
##'   embedding
##' @export
PlanarDrawing <- function(arcSources,
                          arcTargets,
                          numNodes) {
  check_graph_vertices(arcSources, arcTargets, numNodes)
  .Call(`_rlemon_PlanarDrawingRunner`, arcSources, arcTargets, numNodes)
}
