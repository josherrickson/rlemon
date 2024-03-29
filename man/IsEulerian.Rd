% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/connectivity.R
\name{IsEulerian}
\alias{IsEulerian}
\title{Check if Graph is Eulerian}
\usage{
IsEulerian(arcSources, arcTargets, numNodes)
}
\arguments{
\item{arcSources}{Vector corresponding to the source nodes of a graph's
edges}

\item{arcTargets}{Vector corresponding to the destination nodes of a graph's
edges}

\item{numNodes}{The number of nodes in the graph}
}
\value{
TRUE if graph is Eulerian, FALSE otherwise
}
\description{
A directed graph is Eulerian if and only if it is connected and the number
of incoming and outgoing edges are the same for each node. An undirected
graph is Eulerian if and only if it is connected and the number of incident
edges is even for each node.
}
\details{
See \url{https://lemon.cs.elte.hu/pub/doc/1.3.1/a00616.html#gafb5a4961cac4d877006869fc4cb6ea1d}
for more information.
}
