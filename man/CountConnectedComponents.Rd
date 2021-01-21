% Generated by roxygen2: do not edit by hand
% Please edit documentation in R/connectivity.R
\name{CountConnectedComponents}
\alias{CountConnectedComponents}
\title{CountConnectedComponents}
\usage{
CountConnectedComponents(arcSources, arcTargets, numNodes)
}
\arguments{
\item{arcSources}{Vector corresponding to the source nodes of a graph's edges}

\item{arcTargets}{Vector corresponding to the destination nodes of a graph's edges}

\item{numNodes}{The number of nodes in the graph}
}
\value{
An integer defining the number of connected components
}
\description{
Counts the number of connected components in an undirected graph.
}