The following folder contains an implementation of the network simplex algorithm and cost scaling algorithm to solve the mininum cost flow problem in R through the use of the Rcpp library. The program will read the graph and then choose the optimal algorithm to calculate the minimum cost flow.

package-minCostFlow.rmd contains a simple example on how to compile the C++ program in R to solve the minimum cost flow problem. The minFlow function which is exported to R is found in min_cost_flow.rcpp.cpp. This file is identical to min_cost_flow.cpp, but contains the appropriate header files and configurations to be run with sourceCpp. The function exported through min_cost_flow.rcpp.cpp is minFlow(). The function has 5 vector inputs defining the node supplies, arc source nodes, arc target nodes, arc capacities, and arc costs. The output is a vector of the outflow of each arc. It will also print a message stating the total cost of the graph.

min_cost_flow.cpp is a C++ program using the LEMON library to calcute the minimum cost flow of a graph. This program serves for timing purposes. In order to run the algorithm on any of the tests use the command ./minFlow followed by the size of the test. For example, to run the small  test with 34 nodes, use the command './minFlow smallTest'. In order to time the algorithm use 'time ./minFlow smallTest'.

The Lemon folder contains all necessary files to use the network simplex module of the LEMON library. 

documention.xlsx contains the names of each file used from the LEMON library. 