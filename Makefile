# load.R fixes a bug with devtool's `help` to enable `help` on
# functions in this package, as well as loading the package
LOAD=R_PROFILE=load.R
RCMD=R -q -e

.PHONY:interactive
interactive:
	@$(LOAD) R -q --no-save

.PHONY:interactive-emacs
interactive-emacs:
	@$(LOAD) emacs -nw -f R

.PHONY:.devtools
.devtools:
	@$(RCMD) "devtools:::$(FUNC)($(DEVTOOLSARG))"

DEVTOOLSARG=
.PHONY:dependencies
dependencies: FUNC=install_deps
dependencies: DEVTOOLSARG=dependencies=TRUE

.PHONY:test
test: FUNC=test

.PHONY:check
check: FUNC=check

.PHONY:document
document: FUNC=document

.PHONY:coverage
coverage:
	@$(RCMD) "covr::report(file = 'coverage.html', browse = TRUE)"

.PHONY:goodpractice
goodpractice:
	@$(RCMD) "goodpractice::gp('.')"

.PHONY:build
build: FUNC=build

dependencies test check document build: .devtools

.PHONY: clean
clean:
	git clean -Xfd

.PHONY: dos2unix
dos2unix:
	find . -type f -print0 | xargs -0 dos2unix
