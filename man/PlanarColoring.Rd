% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/planarityembedding.R
\name{PlanarColoring}
\alias{PlanarColoring}
\title{Solver for Planar Coloring}
\usage{
PlanarColoring(arcSources, arcTargets, numNodes, algorithm = "fiveColoring")
}
\arguments{
\item{arcSources}{Vector corresponding to the source nodes of a graph's
edges}

\item{arcTargets}{Vector corresponding to the destination nodes of a graph's
edges}

\item{numNodes}{The number of nodes in the graph}

\item{algorithm, }{the algorithm to use. "sixColoring" generates a 6-coloring
of the graph, while "fiveColoring" generates a 5-coloring. Default is
"fiveColoring".}
}
\value{
A named list containing 1) "is_planar": a \code{logical} if the
  graph is planar, 2) "colors": the color of each vertex of the graph
}
\description{
Checks if a graph is planar and returns the coloring of the graph
}
\details{
See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00306.html}
for more information.
}
