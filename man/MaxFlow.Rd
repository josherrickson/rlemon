% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/maxflow.R
\name{MaxFlow}
\alias{MaxFlow}
\title{Solver for MaxFlow}
\usage{
MaxFlow(
  arcSources,
  arcTargets,
  arcCapacities,
  sourceNode,
  destNode,
  numNodes,
  algorithm = "Preflow"
)
}
\arguments{
\item{arcSources}{Vector corresponding to the source nodes of a graph's
edges}

\item{arcTargets}{Vector corresponding to the destination nodes of a graph's
edges}

\item{arcCapacities}{Vector corresponding to the capacities of nodes of a
graph's edges}

\item{sourceNode}{The source node}

\item{destNode}{The destination node}

\item{numNodes}{The number of nodes in the graph}

\item{algorithm}{Choices of algorithm include "Preflow" and "EdmondsKarp".
"Preflow" is the default.}
}
\value{
A named list containing three entries: 1) "flows": a vector
  corresponding to the flows of arcs in the graph, 2) "cut_values": 0/1 vector
  in which 1s identify nodes belonging to a minimum-capacity cut separating the
  source from the destination node, and 3) "cost": the total flow from source to
  destination, i.e. the maxflow value.
}
\description{
Finds the maximum flow of a directed graph, given a source and destination
node.
}
\details{
For details on LEMON's implementation, including differences between the
algorithms, see \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00611.html}.
}
