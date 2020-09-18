#include "connectivity.h"
#include <Rcpp.h>
using namespace Rcpp;

// [[Rcpp::export]]
int rcpp_hello_world(NumericVector sources, NumericVector destinations, int num) {
    arc_src = as<std::vector<int> >(sources);
    arc_targ = as<std::vector<int> >(destinations);
    return IsConnected(arc_src, arc_targ, num);
}
