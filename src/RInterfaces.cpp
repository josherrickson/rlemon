#include "approximation.h"
#include "connectivity.h"
#include "convert.h"
#include "graph_search.h"
#include "max_flow.h"
#include "max_matching.h"
#include "min_cost_flow.h"
#include "min_cut.h"
#include "min_mean_cycle.h"
#include "min_span_tree.h"
#include "planarity_embedding.h"
#include "shortest_path.h"
#include "travelling_salesperson.h"
#include <Rcpp.h>
#include <tuple>
using namespace Rcpp;

// NOTE: This file should not contain any actual
// C++ code. This is only a temp file if the auto
// conversion does not work, and if we need
// to write non-automatic converters.
