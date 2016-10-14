# CME 211 Guidelines

Good style practices in software development are important for collaboration
and code readability.  This document provides a set of guidelines that we expect
you to follow for homework assignments in CME 211.  Some of the items below are
formal, measurable rules while others are informal guidelines that we may assess
manually.

## Style

* Use 4 spaces to indent code in Python.  Use 2 or 4 spaces to indent code in
  C++.  [Don't use tabs](https://www.youtube.com/watch?v=SsoOG6ZeyUI).

* The maximum line length for all code is 80 characters.

* There should be no trailing whitespace at the end of a line.

* The last character of a file should be a new line (`"\n"`).

* `import` or `#include` (C++) statements go at the top of a source code file
  (possibly after documentation comments) and must appear in lexicographic
  (alphabetical) order.

* The maximum nesting or indentation level of code is 5, which allows for a triple
  nested loop inside of a method for a Python class.  But really, 5 is too much
  unless the nested code is very simple.  It is likely a good idea to reconsider
  the flow of your code if you find your self indenting over 3 times in the body
  of a function or 4 times in the body of a class method. Sometimes moving a
  nested loop into a function call can help.

* Keep your conditional (`if`-`else`) structures as simple as possible.  They
  can be hard for humans to read.

## Files

* File and directory names may not contain spaces.

* Do not use Windows line endings (CRLF).

* All text files must be [UTF-8](https://en.wikipedia.org/wiki/UTF-8).

## Decomposition

Humans are only able to store 7-9 current cognitive entities in their head at
any given time.  The number of things that a person has in their head at any
given moment is sometimes called cognitive load.  We use decomposition to
decrease cognitive load while reading or reasoning about code.  Moving parts of
code (in a logical manner) in to a function can collapse several cognitive
entities into one, enabling the programmer to be more awesome. Decomposition
involves breaking a procedure down into human understandable parts.  In
programming we do this with functions and classes.

Guideline:

* You should be able to fit the inner workings of a function or method into your
  head all at the same time.  If a function or method is too long and difficult
  to reason about, it would likely benefit from further decomposition.

* The same goes for blocks of code in the body of conditional structures.

## Runtime

Unless stated otherwise, the expected runtime of homework code is on the order
of seconds. If your code is taking many minutes to run on the largest test case,
it would be good to think about the scalability of the algorithms and data
structures that you use.  We may deduct points if your code takes a long time to
run.  We may also set an upper limit on runtime (maybe 20-100x of the runtime of
our reference code).

## References

You can learn more about good programming style from these guides:

* [PEP8 - Python Style Guide][pep8]
* [Google Python Style Guide][google-py]
* [Google C++ Style Guide][google-c++]
* [LLVM Coding Standards][llvm-c++]

[pep8]: https://www.python.org/dev/peps/pep-0008/
[google-py]: https://google.github.io/styleguide/pyguide.html
[google-c++]: https://google.github.io/styleguide/cppguide.html
[llvm-c++]: http://llvm.org/docs/CodingStandards.html
