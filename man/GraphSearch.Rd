% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/graphsearch.R
\name{GraphSearch}
\alias{GraphSearch}
\title{Solver for Graph Search}
\usage{
GraphSearch(
  arcSources,
  arcTargets,
  numNodes,
  startNode = -1,
  endNode = -1,
  algorithm = "Bfs"
)
}
\arguments{
\item{arcSources}{Vector corresponding to the source nodes of a graph's
edges}

\item{arcTargets}{Vector corresponding to the destination nodes of a graph's
edges}

\item{numNodes}{The number of nodes in the graph}

\item{startNode}{Optional start node of the path}

\item{endNode}{Optional end node of the path}

\item{algorithm}{Choices of algorithm include "Bfs" (Breadth First Search)
and "Dfs" (Depth First Search). Bfs is the default.}
}
\value{
A named list containing three entries: 1) "predecessors": the
  predecessor of each vertex in its shortest path, 2) "distances": the
  distances from each node to the startNode, 3) "node_reached": a vector of
  logicals indicating whether a node was reached.
}
\description{
Runs a common graph search algorithm to find the minimum cardinality
shortest path. Finds the shortest path from/to all vertices if a start/end
node are not given.
}
\details{
For details on LEMON's implementation, including differences between the
algorithms, see \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00608.html}.
}
