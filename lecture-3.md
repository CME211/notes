# CME 211 Lecture 3: Lists, file input and output

Friday, September 25, 2015

## Announcements

* Homework 1 is out today.  It will require material covered in this weeks
  class.  You will not need version control (`git`) for this assignment.  We
  will start using `git` in homework 2 or 3, so start getting comfortable with
  it.  This assignment will be submited via a script on `corn.stanford.edu`.
  See the homework PDF for details.  Please alert us on Piazza if there are any
  issues.

* Today we will discuss: Python lists, control flow, and file input output.
  These topics will be needed for homework 1.

* Relevant chapters in *Learning Python* are:

    * Chapter 5: Numeric Types
    * Chapter 7: String Fundamentals
    * Chapter 8: Lists and Dictionaries (you can ignore Dictionaries for now)
    * Chapter 9: Tuples, Files, and Everything Else
    * Chapter 11: Assignments, Expressions, and Prints
    * Chapter 12: if Tests and Syntax Rules
    * Chapter 13: while and for Loops

* Chapter 4 (Introducing Python Object Types) has a summary of the object types

* By Monday (Sept 28) I will post a schedule for the rest of the quarter.
  In summary:

    * 1 assignment per week, unless there is a quiz
    * 6 assignments
    * 2 quizes (1 Python, 1 C++)
    * 2-part final project in C++

## Last time

In the last lecture we discussed basic use of the Python as an interpreter and
saw some of the fundamental data types (integers, floats, strings).

## Today

We have a lot to cover:

* Lists
* Control flow
* File input output

## Big picture

To complete a task in any programming language, the software developer must
consider the following:

* Data and it's representation
* Operations: modifying or computing things from data
* Flow of control: selecting which operations to run

With the combination of these things, we can write programs that tell a computer
what to do.  A computer program is a form of imperative or procedural knowledge.
Most programming today is done in this style.  This is different from
declarative knowledge.  An example of this difference from mathematics is a
system of equations vs. an algorithm to find a solution to the system of
equations.  The algorithm tells a specific procedure so that we can find the
quantity we are interested in.

### Data

Python has many built-in types.  The ones that we have seen so far are:

* Integers
* Floating point numbers
* Strings

Other important (more fundamental) are:

* Complex numbers
* Unicode strings (which can represent text from ALL languages)

To perform useful tasks more efficiently, we need to combine the above types in
various ways.  For this, Python allows us to store data in various *contrainers*

## Lists


