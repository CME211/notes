# CME 211 Grading Guidelines

We want to see functioning, clear, elegant code that is readable, cleanly
designed, well-decomposed, and commented appropriately.

## Broad categories
 
* [65%] Functionality
* [25%] Code quality
* [10%] Documentation / Write-up

In each category, overall feedback will be summarized with:

* `++`: truly exceptional work, rarely granted,
* `+`: work meets all expectations, without flaw(s),
* `ok`: major functionality present, small details missed or an anticipated error was made,
* `-`: functionality impeded by a fundamental correctness error, which requires multiple modifications to rectified,
* `--`: multiple key components impeded by fundamental correctness errors, *each of which* requires *multiple* modifications to be rectified.

Students who do not submit their assignment at all will earn an entirely separate 
category of points, called "0", which in fact maps to zero. At the end of the quarter, we will map remaining categories to scalar values, e.g.

`{"++" : 1.05, "+" : 0.95", "ok" : 0.85, "-" : 0.75, "--" : 0.6}`.

E.g. your feedback from an assignment might be something like, `"Functionality" : "+", "code-quality" : "ok", "documentation" : "-"}` then if you were really eager to squash this multidimensional, rich feedback into a single scalar value you could compute `0.65 * 0.95 + 0.25 * 0.85 + 0.10 * 0.75 = 0.905`.

### Why do we use a coarser grading schema?
By using a more coarsely grained schema, we encourage students to focus on
salient learning goals rather than spending time justifying each point earned.
Our top-priority is to channel feedback from the experienced teaching staff
through to students in a way that can maximize the learning experience;
we've found through experience that this facilitates a more pedagogical
experience.

Disputes about homework grading must be submitted to the course staff within 1 week of receiving your grade. For more information about the assignment grading process, please see our page on how assignments are graded.

## Functionality

### High priority

* Correct functionality on test cases
* Performance is in reasonable bounds on all test cases

### Medium priority

* Output conforms to spec
* Clean compile
  * C++: program compiles, no warnings under strict compiler flags 
  * Python: no syntax errors
* Clean run
  * C++: no segfaults under any cases
  * C++: valgrind is clean under all cases
  * Python: no fails on exception tracebacks in any cases unless allowed by hw spec

### Low priority

* Correct files present
* Clean repo (according to hw specs)

## Code quality

* Cleanliness/readability
* Language conventions
* Design (decomposition into logical units/functions/classes)
* Use if proper and efficient Data structures

## Write up

* Formatting of text or PDF file is clean and easy to read
* Language is mostly correct and easy to follow
* correct answers to questions asked in assignment specification

## Code quality notes

Cleanliness/readability

* code is free of clutter: remove all dead code and unused vars/fns
* use of whitespace/indentation is tidy and consistent
  * split long lines if necessary (screenwidth ~80 chars)
  * 2-4 spaces per indent level (use spaces to indent instead of tabs to avoid editor inconsistency)
  * whitespace used to visually support logical separation
* variable/function names are consistent and descriptive
  * good naming conventions help avoid need for additional commentary
  * use consistent scheme for capitalization/underscores
* use constants/#define'd/sizeof/variables instead of hardcoded numbers
* comments are present where warranted, prose is correct and helpful
  * overview comments (per-function, per-module) with summary highlights
  * inline comments used sparingly where needed to decipher dense/complex lines
  * no excess verbiage that reiterates what code itself already says

Language conventions

* choose the most clean, direct, conventional syntax available to you
* avoid unnecessary use of obscure constructs
* use standard language features appropriately, e.g.
  * `bool` instead of `int` for true-false scenarios

Program design

* program flow decomposed into manageable, logical pieces
* function interfaces are clean and well-encapsulated
* appropriate algorithms used, coded cleanly
* common code is unified, not duplicated
  * when you need same lines more the once, don't copy and paste -- unify!
* use standard library functions rather than re-implement that functionality, e.g.
  * string manipulation, formatted I/O, sort/search, type conversion, etc.

Data structures

* data structures are well-chosen and appropriate
* no redundant storage/copying of data
* no global variables
