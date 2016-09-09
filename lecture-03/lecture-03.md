# CME 211 Lecture 3: Lists, file input and output

## Reading

Relevant chapters in *Learning Python* are:

* Chapter 5: Numeric Types
* Chapter 7: String Fundamentals
* Chapter 8: Lists and Dictionaries (you can ignore Dictionaries for now)
* Chapter 9: Tuples, Files, and Everything Else
* Chapter 11: Assignments, Expressions, and Prints
* Chapter 12: if Tests and Syntax Rules
* Chapter 13: while and for Loops

Chapter 4 (Introducing Python Object Types) has a summary of the object types

## Outline

We have a lot to cover in this lecture:

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

## Data

Python has many built-in types.  The ones that we have seen so far are:

* Integers
* Floating point numbers
* Strings
* Boolean (`True` or `False`)

Other important types are:

* Files
* Complex numbers

To perform useful tasks more efficiently, we need to combine the above types in
various ways.  For this, Python allows us to store data in various
*containers*.  In simple terms, *containers* contain data and there are various
sorts.

### Lists

**Sequential containers** store data items in a specified order.  Think elements
of a vector, names in a list of people that you want to invite to your
birthday party.  The most fundamental Python data type for this is called a
`list`.  Later in the course we will learn about containers that are more
appropriate (and faster) for numerical data that come from NumPy.

Example Python code:

```python
cme211_tas = ["andreas", "amy", "cindy", "yu-sheng"]
cme211_tas.append("andreas")
print(cme211_tas)
for ta in cme211_tas:
    print("{} is an awesome ta".format(ta))
print("cme211 has {} tas".format(len(cme211_tas)))
```

Python lists are a very useful data container.  They may contain any python
object.  Here is a list containing some numbers and strings:

```python
my_list = [4, 9.4, 'some text', 55]
```

Python lists (and other sequential data types) use 0-base indexing.  Data in a
list may be accessed via a slice:

```python
my_list[0]
```

```python
my_list[1:2]
```

```python
my_list[1:3]
```

```python
my_list[1:4]
```

```python
my_list[1:]
```

Lists are mutable.  You may change the elements in a list:

```python
my_list[2] = 'some different text'
my_list
```

You can get the length of a list with:

```python
len(my_list)
```

See `help(list)` from the Python interpreter for summary of methods that can
operate on a list.

### Dictionaries

**Associative container** store data, organized by a unique *key*.  Think of a
dictionary of word definitions.  They unique *key* is a word, the value
associated with the key is the definition.  In Python, this is represented with
the built-in `dict` or Dictionary type.  You will soon learn the greatness of
dictionaries in Python.

```python
emails = dict()
emails['andreas'] = 'andreas@mail.com'
emails['nick'] = 'nwh@stanford.net'
print(emails)
```

Access a single element:

```python
emails['nick']
```

What if a key is not there?

```python
emails['cindy']
```

### Sets

**Set containers** store unique data items.  They are related to dictionaries,
because dictionaries require the keys to be unique.

```python
dinos = set()
dinos.add('triceratops')
dinos.add('t-rex')
dinos.add('raptor')
print(dinos)
dinos.add('pterodactyl')
dinos.add('t-rex')
print(dinos)
```

## Python's data model

Variables in Python are actually a reference to an object in memory.  Here is a
simple example to demonstrate this property:

```python
a = [1,2,3,4]
b = a
b[1] = 55
print(b)
print(a)
```

In this example, we assigned `a` to `b` via `b = a`.  This did not copy the
data, it only copied the reference to the list object in memory.  Thus
modifying the list through `b` also changes the data that you will see when
accessing from `a`.  You can inspect object ids in Python with:

```python
print("id(a): ", id(a))
print("id(b): ", id(b))
```

Those numbers refer to memory addresses.

### Copying data

If you need to make a new copy of a list you may use the `copy` function in the
`copy` module:

```python
import copy
a = [5,2,7,0,'abc']
b = copy.copy(a)
b[4] = 'xyz'
print(b)
print(a)
```

Note that elements in a list are also references to memory location.  For
example if your list contains a list, this will happen when using `copy.copy()`:

```python
a = [2, 'string', [1,2,3]]
b = copy.copy(a)
b[2][0] = 55
print(b)
print(a)
```

Here, the element for the sub-list `[55, 2, 3]` is actually a memory reference.
So, when we copy the outer list, only references for the contained objects are
copied.  Thus in this case modifying the copy (`b`) modifies the original
(`a`).  Thus, we may need the function `copy.deepcopy()`:

```python
a = [2, 'string', [1,2,3]]
b = copy.deepcopy(a)
b[2][0] = 99
print(b)
print(a)
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

```python
a = 1
if a == 1:
    print("a is equal to one")
```

```python
b = 4
if b == 1:
    print("b is equal to one")
```

```python
c = 55
if c == 20:
    print('c is equal to twenty')
else:
    print('c is not equal to twenty')
```

```python
d = 99
if d == 1:
    print("d is 1")
elif d == 99:
    print("d is 99")
else:
    print("I have no idea what d is")
```

Read Chapter 12 of **Learning Python** for a complete picture of Python's `if`
statement.  Specifically, look at page 381, which specifies all of the rules on
how Python statements evaluate to `True` and `False`.

```python
if "":
    print('an empty string evaluates to False')

if "hi nick":
    print('a non-empty string evaluates to True')
```

### Python `for` loops

Let's start with an example:

```python
for i in range(5):
    print("i = {}".format(i))
```

The anatomy of a `for` loop is:

```
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

Note: in Python 2, the `range` function returns a list.  In Python 3 `range`
returns a **range** object, which allows for iteration over integers with out
creating a new list in memory.

We can use a list as the sequence to iterate (loop) over:

```python
languages = ['python', 'c', 'c++', 'r', 'java', 'matlab', 'julia']
for lang in languages:
    print('{} is a pretty good language'.format(lang))
```

### Python `while` loops

Let's start with an example:

```python
i = 0
while i <= 10:
    i += 1

print("i = {}".format(i))
```

The anatomy of a Python `while` loop is:

```
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

```python
i = 0
while i < 10:
    print("in loop, i = {}".format(i))
    i += 1
    if i == 4:
            break
print(i)
```

If a loop body encounters a `break` statement, the loop is terminated.

If a loop body encounters a `continue` statement, control moves to the next
iteration.  For example:

```python
for i in range(100):
    if i < 92:
            continue
    print("i = {}".format(i))
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

```python
f = open("humpty-dumpty.txt","r")
f
```

The syntax is `open(filename,mode)` where `filename` is a string with the
filename to open and `mode` is the mode to open the file.  For now, the mode
should be `'r'` for reading a file and `'w'` for writing a file.  The `open`
function returns a *file object*, which we will use to read and write data.

Note what happens if you try to open a file that does not exist:

```python
bad_file = open("no-file.txt","r")
```

### Reading from files

Use the `readline()` method to read lines from a file:

```python
f = open("humpty-dumpty.txt","r")
print(f.readline())
print(f.readline())
f.close()
```

It is always a good idea to close a file when you are done with it.  *We will
take off points if you neglect to do this.*

You can read an entire file at once with the `read()` method:

```python
f = open("humpty-dumpty.txt","r")
poem = f.read()
print(poem)
f.close()
```

You can very easily iterate over lines in a file with:

```python
f = open("humpty-dumpty.txt","r")
for line in f:
    print(line)
f.close()
```

Note, on your own, try to suppress the extra newline character generated.  You
can do this by specifying the `end` keyword parameter for the `print` function
to be an empty string (`""`): `print(line, end='')` or slicing `line` with
`print(line[:-1])`.  Note that `line` is a variable name.

Let's say we wanted to process all words in a file.  The following example would
get us started:

```python
f = open("humpty-dumpty.txt","r")
for line in f:
    for word in line.split():
        # use strip() method to remove extra newline characters
        print(word.strip())
f.close()
```

### Writing to files

To open a file for writing and write a single line:

```python
f = open("output.txt","w")
f.write("blah blah blah\n")
f.close()
exit()
```

```
$ cat output.txt
blah blah blah
```

Note that the `write` method will not insert a newline character.  To get a new
line, you must add `'\n'` in the string that is passed to `write`.

To write multiple lines to a file at once, use the `writelines` method:

```python
f = open("output.txt","w")
f.writelines(["a mighty fine day\n","ends with a great big party\n","thank you, its friday\n"])
f.close()
```

```
$ cat output.txt
a mighty fine day
ends with a great big party
thank you, its friday
```

Note, the `\n` is still required in the strings that make up the list passed to
`writelines`.  The `"w"` file mode will overwrite the file you open, deleting
all of the old data.  Be careful!  If you would like to append to an existing
file use the `"a"` mode.

### Buffering

Be mindful of file buffering.  We will see a demo in class.
