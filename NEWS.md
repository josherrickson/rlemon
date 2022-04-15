# rlemon 0.2.0

## Major changes

- `MinCostFlow()` now returns feasibility status (#25)
- Functions which returned 0/1 booleans now return logical instead. (#36)
- `algorithm=` argument to various functions has received fixes and cleanups
  - Ensure all `algorithm=` arguments have a default (#29)
  - Informative error if `algorithm=` argument isn't string (#32)
  - `MaxFlow()` and `NetworkCirculation()` properly error on invalid `algorithm`
    argument.
- `MaxMatching()` crashed if given `NULL` weights; fix such that `NULL` weights
  now yields unweighted Max Matching. (#35)
- Exported functions now interface with the LEMON library through runners. These
  runners aren't exported, but may be useful for users who want access to LEMON
  with no pre- or post-processing. See `help(lemon_runners)` for details. (#30)

## Minor changes

- Various corrections and cleanups of documentation (#34, #27, #28, etc)
  - More precise use of the term "list", and remove usage of "boolean"
  - Fixed some links to LEMON documentation.
- Testing has been standardized to hopefully get ahead of problems in the
  future. (#31)

# rlemon 0.1.0

First release!
