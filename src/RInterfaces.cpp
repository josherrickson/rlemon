#include "connectivity.h"
#include "max_matching.h"
#include "min_cost_flow.h"
#include "planarityEmbedding.h"
#include "travelling_salesman.h"
#include "minimum_mean_cycle.h"
#include "approximation.h"
#include "max_flow.h"
#include "minSpanTree.h"
#include <Rcpp.h>
#include <tuple>
using namespace Rcpp;


// NOTE: This file should not contain any actual
// C++ code. This is only a temp file if the auto
// conversion does not work, and if we need 
// to write non-automatic converters. 


//' Graph Input Specifications
//' @name Input-Information
//' Due to how LEMON operates, and to make the interfaces similar to the actual program, 
//' graphs in rLEMON use the following 2 vectors:
//' arcSources, and arcTargets
//' to acquire information about how the graph is structured
//' each edge in a graph will consist of a (node id, node id) pair, which is represented
//' by the ith entry in both arcSources and arcTargets. 
//' The nodes are 0-indexed, and must be sequential. 
//' numNodes must be equal to the number of nodes in the graph, as otherwise there
//' are potentials to error out. 
//' As an example, the cycle graph on three vertices would have the following input:
//' arcSources <- c(0,1,2)
//' arcTargets <- c(1,2,0)
//' numNodes <- 3
//' Here, the edges are (0,1), (1,2), (2,0)
//> NULL