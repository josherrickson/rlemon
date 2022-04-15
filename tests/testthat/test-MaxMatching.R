# Title            : Max Matching
# File             : R/maxmatching.R
# Exported         : MaxMatching
# Valid Algorithms : "MaxWeightedMatching" (default),
#                    "MaxWeightedPerfectMatching",
#                    "MaxWeightedFractionalMatching",
#                    "MaxWeightedPerfectFractionalMatching"
# Runners          : MaximumWeightMatchingRunner,
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
  d <- c(1, 2, 3, 4, 5, 6, 7, 8, 9)

  out <- MaximumWeightMatchingRunner(s, t, d, 6)
  test_matching(out)

  out <- MaximumWeightPerfectMatchingRunner(s, t, d, 6)
  test_matching(out)

  out <- MaximumWeightFractionalMatchingRunner(s, t, d, 6)
  test_matching(out)

  out <- MaximumWeightFractionalPerfectMatchingRunner(s, t, d, 6)
  test_matching(out)

})

test_that("MaxMatching function", {
  s <- c(1, 1, 1, 2, 2, 2, 3, 3, 3)
  t <- c(4, 5, 6, 4, 5, 6, 4, 5, 6)
  d <- c(1, 2, 3, 4, 5, 6, 7, 8, 9)

  # 2) Ensure exported functions run without error and return the "expected
  # objects".

  # This currently errors, see #35
  out <- MaxMatching(s, t, numNodes = 6)
  test_matching(out)

  out <- MaxMatching(s, t, d, 6)
  test_matching(out)

  # 3) Ensure exported functions with `algorithm=`default runs without error, and
  # returns the same if passed no argument
  out2 <- MaxMatching(s, t, d, 6, algorithm = "MaxWeightedMatching")
  expect_identical(out, out2)

  # 4) Ensure exported functions work with all valid algorithms.

  # Tests below erroring, see #35
  out <- MaxMatching(s, t, numNodes = 6,
                     algorithm = "MaxWeightedPerfectMatching")
  test_matching(out)
  out <- MaxMatching(s, t, d, 6,
                     algorithm = "MaxWeightedPerfectMatching")
  test_matching(out)
  out <- MaxMatching(s, t, numNodes = 6,
                     algorithm = "MaxWeightedFractionalMatching")
  test_matching(out)
  out <- MaxMatching(s, t, d, 6,
                     algorithm = "MaxWeightedFractionalMatching")
  test_matching(out)
  out <- MaxMatching(s, t, numNodes = 6,
                     algorithm = "MaxWeightedPerfectFractionalMatching")
  test_matching(out)
  out <- MaxMatching(s, t, d, 6,
                     algorithm = "MaxWeightedPerfectFractionalMatching")
  test_matching(out)


  # 5) Ensure exported functions fail if passed an invalid algorithm.
  expect_error(MaxMatching(s, t, d, 6, algorithm = "abc"),
               "Invalid")
  expect_error(MaxMatching(s, t, d, 6, algorithm = 1),
               "must be a string")
  expect_error(MaxMatching(s, t, d, 6, algorithm = NULL),
               "must be a string")
})
