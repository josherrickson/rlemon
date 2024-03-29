% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/shortestpath.R
\name{ShortestPathFromSource}
\alias{ShortestPathFromSource}
\title{Solve for Shortest Path from Source Node to All Other Nodes}
\usage{
ShortestPathFromSource(
  arcSources,
  arcTargets,
  arcDistances,
  numNodes,
  sourceNode,
  algorithm = "Dijkstra"
)
}
\arguments{
\item{arcSources}{Vector corresponding to the source nodes of a graph's
edges}

\item{arcTargets}{Vector corresponding to the destination nodes of a graph's
edges}

\item{arcDistances}{Vector corresponding to the distances of a graph's edges}

\item{numNodes}{The number of nodes in the graph}

\item{sourceNode}{The source node}

\item{algorithm}{Choices of algorithm include "Dijkstra" and "BellmanFord".
"Dijkstra" is the default.}
}
\value{
A named list containing two entries: 1) "distances": the distances
  from each node to the startNode and 2) "predecessors": the predecessor of
  each vertex in its shortest path.
}
\description{
Finds the shortest path from a source node to the rest of the nodes in a
directed graph. These shortest path algorithms consider the distances present
in the graph, as well as the number of edges.
}
\details{
For details on LEMON's implementation, including differences between the
algorithms, see \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00609.html}.
}
