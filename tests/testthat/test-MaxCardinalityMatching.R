# Title            : Max Cardinality matching
# File             : R/maxmatching.R
# Exported         : MaxCardinalityMatching
# Valid Algorithms : "MaxMatching" (default),
#                    "MaxFractionalMatching"
# Runners          : MaximumCardinalityMatchingRunner,
#                    MaximumCardinalityFractionalMatchingRunner
#                    MaximumWeightPerfectMatchingRunner,
#                    MaximumWeightFractionalMatchingRunner,
#                    MaximumWeightFractionalPerfectMatchingRunner

test_matching <- function(o) {
  expect_true(is.list(o))
  expect_true(is.numeric(o[[1]]))
  expect_length(o[[1]], 1)
  expect_true(is.list(o[[2]]))
  expect_true(all(vapply(o[[2]], length, 1) == 2))
}

# 1) Ensure runner functions run without error and return the "expected
# objects".
test_that("Matching runners",  {
  s <- c(1, 1, 1, 2, 2, 2, 3, 3, 3)
  t <- c(4, 5, 6, 4, 5, 6, 4, 5, 6)

  out <- MaximumCardinalityMatchingRunner(s, t, 6)
  test_matching(out)
  out <- MaximumCardinalityFractionalMatchingRunner(s, t, 6)
  test_matching(out)

})

test_that("MaxCardinalityMatching function", {
  s <- c(1, 1, 1, 2, 2, 2, 3, 3, 3)
  t <- c(4, 5, 6, 4, 5, 6, 4, 5, 6)

  # 2) Ensure exported functions run without error and return the "expected
  # objects".
  out <- MaxCardinalityMatching(s, t, 6)
  test_matching(out)

  # 3) Ensure exported functions with `algorithm=`default runs without error, and
  # returns the same if passed no argument
  out2 <- MaxCardinalityMatching(s, t, 6, algorithm = "MaxMatching")
  expect_identical(out, out2)

  # 4) Ensure exported functions work with all valid algorithms.
  out <- MaxCardinalityMatching(s, t, 6, algorithm = "MaxFractionalMatching")
  test_matching(out)


  # 5) Ensure exported functions fail if passed an invalid algorithm.
  expect_error(MaxCardinalityMatching(s, t, 6, algorithm = "abc"),
               "Invalid")
  expect_error(MaxCardinalityMatching(s, t, 6, algorithm = 1),
               "must be a string")
  expect_error(MaxCardinalityMatching(s, t, 6, algorithm = NULL),
               "must be a string")
})
