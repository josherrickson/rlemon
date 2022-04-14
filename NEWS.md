# rlemon 0.2.0.9000

## Major changes

- `MinCostFlow()` now returns feasibility status (#25)
- `algorithm=` argument has received fixes and cleanups
  - Ensure all `algorithm=` arguments have a default (#29)
  - Intelligent error if `algorithm=` argument isn't string (#32)
  - `MaxFlow()` and `NetworkCirulation()` properly error on invalid `algorithm`
    argument.

## Minor changes

- Various fixed, orgaization, and cleanups of documentation (#34, #30, #27, #28,
  #31, and other cleanups)
  - Specifically, more precise use of the term "list", and remove usage of
    "boolean"

# rlemon 0.1.0

First release!
