# rlemon: R interface to LEMON solver

[![R-CMD-check](https://github.com/atewari7/rlemon/workflows/R-CMD-check/badge.svg)](https://github.com/atewari7/rlemon/actions)
[![Codecov test coverage](https://codecov.io/gh/atewari7/rlemon/branch/master/graph/badge.svg)](https://codecov.io/gh/atewari7/rlemon?branch=master)

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
