## Test environments
* local OS X install, R 4.1.2
* win-builder (old, devel and release)
* rhub

## R CMD check results
There were no ERRORs or WARNINGs.

There was 2 NOTEs:

* checking CRAN incoming feasibility ... NOTE
Maintainer: ‘Josh Errickson <jerrick@umich.edu>’

New submission

This is in fact a new submission

* checking installed package size ... NOTE
  installed size is 29.3Mb
  sub-directories of 1Mb or more:
    lemon   2.9Mb
    libs   26.2Mb

The rlemon package implements an R interface to the C++ LEMON graph library
which we include in the package to remove the need for external dependenices.
The library is comprehensive and thus slightly large.
