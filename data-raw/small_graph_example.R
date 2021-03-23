small_graph_example <- list(
  startnodes = read.csv("small_graph_startnodes.csv", header = TRUE)$x,
  endnodes   = read.csv("small_graph_endnodes.csv",   header = TRUE)$x,
  arccosts = read.csv("small_graph_arccosts.csv", header = TRUE)$x,
  arccapacity = read.csv("small_graph_arccapacity.csv", header = TRUE)$x,
  nodedemand = read.csv("small_graph_nodedemand.csv", header = TRUE)$x,
  outflow = read.csv("small_graph_outflow.csv", header = TRUE)$x
  )

usethis::use_data(small_graph_example, overwrite=TRUE)
