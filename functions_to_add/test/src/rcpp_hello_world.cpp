#include "connectivity.h"
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
int rcpp_hello_world(NumericVector sources, NumericVector destinations, int num) {

    
    // Example Usage - Example taken from EecsforGeeks
    vector<int> arc_src{ 0, 0, 0, 1, 1, 2, 2, 3, 4, 4, 6, 7};
    vector<int> arc_targ{1, 3, 5, 2, 4, 6, 3, 7, 5, 6, 7, 5};
    arc_src = as<std::vector<int> >(sources);
    arc_targ = as<std::vector<int> >(destinations);
    return IsConnected(arc_src, arc_targ, num);
}
