# C++ Challenge: what does `=` do?

Think back to our Python days.  Things were nice back then.  The weather was
warmer, the days were longer, and the assignment operator `=` associated a
variable with a reference to an object in memory.  If we wanted to copy a data
structure from one variable to another we had to explicitly call `copy.copy` or
`copy.deepcopy`.  The purpose of this challenge is to gain a better
understanding of what is going on in C++ when we do assignment.

This directory contains `u.data` and `u.data.short` from the MovieLens data
set.  We used this in a previous homework.

The challenge is to:

1. Load the data into an appropriate C++ nested `map` structure.  The hierarchy
   should be `MovieId -> UserId -> Rating`.

2. Write simple print routines for the `map`.

3. Test to determine the behavior of `=` on your structure.  Does it behave
like:
  * Python's `=`
  * Python's `copy.copy()`
  * Python's `copy.deepcopy()`

Have a look at the code in `../../lecture-24/similarity/` to get started.
