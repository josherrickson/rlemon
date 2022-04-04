# rlemon: R interface to LEMON solver

Package website: [release](https://errickson.net/rlemon) | [development](https://errickson.net/rlemon/dev)

<!-- badges: start -->
[![CRAN_Status_Badge](https://www.r-pkg.org/badges/version/rlemon)](https://cran.r-project.org/package=rlemon)
[![R-CMD-check](https://github.com/josherrickson/rlemon/workflows/R-CMD-check/badge.svg)](https://github.com/josherrickson/rlemon/actions)
<!-- badges: end -->

rlemon provides convenient access to the
[LEMON](https://lemon.cs.elte.hu/trac/lemon) C++ graph library. Built with the
most recent version of LEMON (1.3.1), it provides an R interface to algorithms
to solve the following problems:

| Problem                     | Algorithm(s)                                                                                        |
|:--------------------------- |:----------------------------------------------------------------------------------------------------|
|Graph Search                 | breadth-first search (BFS), depth-first search (DFS), Maximum Cardinality Search                    |
|Shortest Path                | Bellman-Ford, Dijkstra, Suurballe                                                                   |
|Minimum Spanning Tree        | Kruskal, Minimum Cost Arborescence                                                                  |
|MaxFlow                      | Push-relabel algorithm for the network circulation, Edmonds-Karp, Preflow                           |
|MinCostFlow                  | Primal Network Simplex, Capacity Scaling, Cost Scaling, Cycle Canceling                             |
|Minimum Cut                  | Hao-Orlin, Gomory-Hu, Nagamochi-Ibaraki                                                             |
|minMeanCycle                 | Hartmann-Orlin, Howard's policy iteration, Karp's                                                   |
|Matching                     | Edmond's blossom shrinking algorithms, Push-relabel , Augmenting path                               |
|Connectivity Algorithms      | Topological Sort, Check for Bipartite, loops, simple, or eulerian graphs, check for parallel edges  |
|PlanarEmbedding and Drawing  | Planar Embedding, Schnyder's planar drawing, Planar Coloring                                        |
|Traveling Salesperson        | Christosfides, Greedy, Insertion heuristic, Nearest Neighbor, 2-opt                                 |
|Approximation Algorithms     | Grosso, Locatelli, and Pullan                                                                       |

## 1-indexing vs 0-indexing

The LEMON C++ library uses 0-indexing, as is common in C++, meaning a graph of 5
nodes will be labeled 0 through 4. R almost exclusively uses 1-indexing, meaning
the same graph of 5 nodes will be labeled 1 through 5.

For consistency in R, all function in R expect 1-indexing, and convert to
0-indexing before passing to C++.
