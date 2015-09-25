# CME 211 Lecture 3: Lists, file input and output

Friday, September 25, 2015

## Announcements

* Homework 1 is out today.  It will require material covered in this weeks
  class.  You will not need version control (`git`) for this assignment.  We
  will start using `git` in homework 2 or 3, so start getting comfortable with
  it.  This assignment will be submitted via a script on `corn.stanford.edu`.
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
    * 2 quizzes (1 Python, 1 C++)
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

Other important types are:

* Files!
* Complex numbers
* Unicode strings (which can represent text from ALL languages)

To perform useful tasks more efficiently, we need to combine the above types in
various ways.  For this, Python allows us to store data in various
*containers*.  In simple terms, *containers* contain data and there are various
sorts.

**Sequential containers** store data items in a specified order.  Think elements
of a vector, names in a list of people that you want to invite to your
birthday party.  The most fundamental Python data type for this is called a
`list`.  Later in the course we will learn about containers that are more
appropriate (and faster) for numerical data that come from NumPy.

Example Python code:

```py
cme211_tas = ["josh", "evan", "oliver", "swaroop"]
cme211_tas.append("loek")
print(cme211_tas)
for ta in cme211_tas:
    print("{} is an awesome ta".format(ta))
print("cme211 has {} tas".format(len(cme211_tas)))
```

Output:

```
['josh', 'evan', 'oliver', 'swaroop', 'loek']
josh is an awesome ta
evan is an awesome ta
oliver is an awesome ta
swaroop is an awesome ta
loek is an awesome ta
cme211 has 5 tas
```

**Associative container** store data, organized by a unique *key*.  Think of a
dictionary of word definitions.  They unique *key* is a word, the value
associated with the key is the definition.  In Python, this is represented with
the built-in `dict` or Dictionary type.  You will soon learn the greatness of
dictionaries in Python.

```py
emails = dict()
emails['loek'] = 'loek@mail.com'
emails['nick'] = 'nwh@stanford.net'
print(emails)
```

```
{'nick': 'nwh@stanford.net', 'loek': 'loek@mail.com'}
```

**Set containers** store unique data items.  They are related to dictionaries,
because dictionaries require the keys to be unique.

```py
dinos = set()
dinos.add('triceratops')
dinos.add('t-rex')
dinos.add('raptor')
print(dinos)
dinos.add('pterodactyl')
dinos.add('t-rex')
print(dinos)
```

```
set(['triceratops', 'raptor', 't-rex'])
set(['pterodactyl', 'triceratops', 'raptor', 't-rex'])
```

## Lists

Python lists are a very useful data container.  They may contain any python
object.  Here is a list containing some numbers and strings:

```py
>>> my_list = [4, 9.4, 'some text', 55]
```

Python lists (and other sequential data types) use 0-base indexing.  Data in a
list may be accessed via a slice:

```py
>>> my_list[0]
4
>>> my_list[1:2]
[9.4]
>>> my_list[1:3]
[9.4, 'some text']
>>> my_list[1:4]
[9.4, 'some text', 55]
>>> my_list[1:]
[9.4, 'some text', 55]
```

Lists are mutable.  You may change the elements in a list:

```py
>>> my_list[2] = 'some different text'
>>> my_list
[4, 9.4, 'some different text', 55]
```

You can get the length of a list with:

```py
>>> len(my_list)
4
```

See `help(list)` from the Python interpreter for summary of methods that can
operate on a list.

## Python's data model

Variables in Python are actually a reference to an object in memory.  Here is a
simple example to demonstrate this property:

```py
>>> a = [1,2,3,4]
>>> b = a
>>> b[1] = 55
>>> print(b)
[1, 55, 3, 4]
>>> print(a)
[1, 55, 3, 4]
```

In this example, we assigned `a` to `b` via `b = a`.  This did not copy the
data, it only copied the reference to the list object in memory.  Thus
modifying the list through `b` also changes the data that you will see when
accessing from `a`.  You can inspect object ids in Python with:

```py
>>> id(a)
140672544197304
>>> id(b)
140672544197304
```

Those numbers refer to memory addresses.

## Copying data

If you need to make a new copy of a list you may use the `copy` function in the
`copy` module:

```py
>>> import copy
>>> a = [5,2,7,0,'abc']
>>> b = copy.copy(a)
>>> b[4] = 'xyz'
>>> print(b)
[5, 2, 7, 0, 'xyz']
>>> print(a)
[5, 2, 7, 0, 'abc']
```

Note that elements in a list are also references to memory location.  For
example if your list contains a list, this will happen when using `copy.copy()`:

```py
>>> a = [2, 'string', [1,2,3]]
>>> b = copy.copy(a)
>>> b[2][0] = 55
>>> print(b)
[2, 'string', [55, 2, 3]]
>>> print(a)
[2, 'string', [55, 2, 3]]
```

Here, the element for the sub-list `[55, 2, 3]` is actually a memory reference.
So, when we copy the outer list, only references for the contained objects are
copied.  Thus in this case modifying the copy (`b`) modifies the original
(`a`).  Thus, we may need the function `copy.deepcopy()`:

```py
>>> a = [2, 'string', [1,2,3]]
>>> b = copy.deepcopy(a)
>>> b[2][0] = 99
>>> print(b)
[2, 'string', [99, 2, 3]]
>>> print(a)
[2, 'string', [1, 2, 3]]
```

## Control flow

Control flow in imperative programming languages boils down to 3 main
constructs:

* Repeated execution or iteration: `for` and `while` loops

* Conditional execution: `if` statements

* Functions to encapsulate code, defined in python with the keyword `def`.
  Python is an object-oriented language and objects often have associated
  *methods*.  *Methods* are just functions that operate on a specific object.

Note that `while` loops are a combination repeated and conditional execution.

See Chapter 13 in learning Python.  I expect you to understand the full looping
syntax, including loop `else` blocks.  Be sure to read pages 387-402.

### Python `if` statements

`if` statements control the flow of code execution based on a conditional
statement.  Here are some examples:

```py
>>> a = 1
>>> if a == 1:
...     print("a is equal to one")
... 
a is equal to one
```

```py
>>> b = 4
>>> if b == 1:
...     print("b is equal to one")
... 
```

```py
>>> c = 55
>>> if c == 20:
...     print('c is equal to twenty')
... else:
...     print('c is not equal to twenty')
... 
c is not equal to twenty
```

```py
>>> d = 99
>>> if d == 1:
...     print("d is 1")
... elif d == 99:
...     print("d is 99")
... else:
...     print("I have no idea what d is")
... 
d is 99
```

Read Chapter 12 of **Learning Python** for a complete picture of Python's `if`
statement.  Specifically, look at page 381, which specifies all of the rules on
how Python statements evaluate to `True` and `False`.

```py
>>> if "":
...     print('an empty string evaluates to False')
... 
>>> if "hi nick":
...     print('a non-empty string evaluates to True')
... 
a non-empty string evaluates to True
```

### Python `for` loops

Let's start with an example:

```py
>>> for i in range(5):
...     print("i = {}".format(i))
... 
i = 0
i = 1
i = 2
i = 3
i = 4
```

The anatomy of a `for` loop is:

```py
for loop_var in sequence:
    loop_body()
```

Components:

1. a loop starts with the `for` keyword
2. followed by the loop variable, `loop_var` in this case
3. followed by the `in` keyword
4. followed by some form of sequence
5. followed by a `:`
6. followed by an **indented** loop body.  (Please use 4 spaces here)

In Python 2, the `range` function returns a list:

```py
>>> range(5)
[0, 1, 2, 3, 4]
>>> range(4,8)
[4, 5, 6, 7]
>>> range(4,20,3)
[4, 7, 10, 13, 16, 19]
```

Likewise, we can use a list as the sequence to iterate (loop) over:

```py
>>> languages = ['python', 'c', 'c++', 'r', 'java', 'matlab', 'julia']
>>> for lang in languages:
...     print('{} is a pretty good language'.format(lang))
... 
python is a pretty good language
c is a pretty good language
c++ is a pretty good language
r is a pretty good language
java is a pretty good language
matlab is a pretty good language
julia is a pretty good language
```

### Python `while` loops

Let's start with an example:

```py
>>> i = 0
>>> while i <= 10:
...     i += 1
... 
>>> print("i = {}".format(i))
i = 11
```

The anatomy of a Python `while` loop is:

```py
while conditional:
    loop_body()
```

Components:

1. starts with the `while` keyword

2. followed by a conditional statement

    * a conditional statement is something that Python knows to be true or false

3. followed by a colon `:`

4. followed by an indented loop body

### `continue` and `break` statements

The `continue` and `break` control execution of a loop from within the loop
body.  Here is an example with `break`:

```py
>>> i = 0
>>> while i < 10:
...     print("in loop, i = {}".format(i))
...     i += 1
...     if i == 4:
...             break
... 
in loop, i = 0
in loop, i = 1
in loop, i = 2
in loop, i = 3
>>> print(i)
4
```

If a loop body encounters a `break` statement, the loop is terminated.

If a loop body encounters a `continue` statement, control moves to the next
iteration.  For example:

```py
>>> for i in range(100):
...     if i < 92:
...             continue
...     print("i = {}".format(i))
... 
i = 92
i = 93
i = 94
i = 95
i = 96
i = 97
i = 98
i = 99
```

## File input output

Files are one way to get data into Python for process and out of python for
saving or sending (over a network).  In CME 211, we will mostly work with text
files.  This set of lecture notes is written in a text file `lecture-3.md` in
[Markdown format](https://daringfireball.net/projects/markdown/).  As a
side note, Markdown is a format that makes it easy to write text and convert it
to other formats.  If you are viewing this file via GitHub, you will likely be
looking at an HTML render of the file.  Python scripts are text files and by
convention have a `.py` extension.  On unix systems we can dump a text file to
the terminal with:

```
$ cat hello.py 
# run me from the command line with
# $ python hello.py

print("hello sweet world!")
```

For run, try dumping a binary file to the terminal with `$ cat /bin/ls`.  What
happens?

In Python it is very easy to open, read from, and write to a text file.  Let's
see how it works.

See Chapter 9 in **Learning Python** for information on accessing files with
Python.  The relevant information starts on page 282.

### Open a file

We open a file with the built-in `open` function:

```py
>>> f = open("humpty-dumpty.txt","r")
>>> f
<open file 'humpty-dumpty.txt', mode 'r' at 0x7f475ec18390>
```

The syntax is `open(filename,mode)` where `filename` is a string with the
filename to open and `mode` is the mode to open the file.  For now, the mode
should be `'r'` for reading a file and `'w'` for writing a file.  The `open`
function returns a *file object*, which we will use to read and write data.

Note what happens if you try to open a file that does not exist:

```py
>>> bad_file = open("no-file.txt","r")
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
IOError: [Errno 2] No such file or directory: 'no-file.txt'
>>> 
```

### Reading from files

Use the `readline()` method to read lines from a file:

```py
>>> f = open("humpty-dumpty.txt","r")
>>> f.readline()
'Humpty Dumpty sat on a wall,\n'
>>> f.readline()
'Humpty Dumpty had a great fall.\n'
>>> f.close()
```

It is always a good idea to close a file when you are done with it.  We will
take off points if you neglect to do this.

You can read an entire file at once with the `read()` method:

```py
>>> f = open("humpty-dumpty.txt","r")
>>> poem = f.read()
>>> print(poem)
Humpty Dumpty sat on a wall,
Humpty Dumpty had a great fall.
All the king's horses and all the king's men
Couldn't put Humpty together again.

>>> f.close()
```

You can very easily iterate over lines in a file with:

```py
>>> f = open("humpty-dumpty.txt","r")
>>> for line in f:
...     print(line)
... 
Humpty Dumpty sat on a wall,

Humpty Dumpty had a great fall.

All the king's horses and all the king's men

Couldn't put Humpty together again.

>>> f.close()
```

Note, on your own, try to suppress the extra newline character generated.  You
can do with with adding a comment after print: `print(line),` or slicing `line`
with `print(line[:-1])`.  Note that `line` is a variable name.  The following
works in the same manner:

```py
>>> f = open("humpty-dumpty.txt","r")
>>> for my_line in f:
...     print(my_line)
... 
Humpty Dumpty sat on a wall,

Humpty Dumpty had a great fall.

All the king's horses and all the king's men

Couldn't put Humpty together again.

>>> f.close()
```

Let's say we wanted to process all words in a file.  The following example would
get us started:

```py
f = open("humpty-dumpty.txt","r")
for line in f:
    for word in line.split():
        # use strip() method to remove extra newline characters
        print(word.strip())
f.close()
```

### Writing to files

To open a file for writing and write a single line:

```py
>>> f = open("output.txt","w")
>>> f.write("blah blah blah\n")
>>> f.close()
>>> exit()
$ cat output.txt 
blah blah blah
```

Note that the `write` method will not insert a newline character.  To get a new
line, you must add `'\n'` in the string that is passed to `write`.

To write multiple lines to a file at once, use the `writelines` method:

```py
>>> f = open("output.txt","w")
>>> f.writelines(["a mighty fine day\n","ends with a great big party\n","thank you, it's friday\n"])
>>> f.close()
>>> exit()
$ cat output.txt 
a mighty fine day
ends with a great big party
thank you, it's friday
```

Note, the `\n` is still required in the strings that make up the list passed to
`writelines`.  The `"w"` file mode will overwrite the file you open, deleting
all of the old data.  Be careful!  If you would like to append to an existing
file use the `"a"` mode.

### Buffering

Be mindful of file buffering.  We will see a demo in class.
