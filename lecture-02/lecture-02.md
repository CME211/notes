# CME 211 Lecture 2: Introduction to Python

## Python

* Python is a high level language that runs in an *interpreter*
* An *interpreter* is a program (see `$ python`) that executes statements from a
  high level language
* Examples of high level interpreted languages: Python, R, Matlab, Perl,
  JavaScript
* The most widely used Python interpreter is called **CPython**.  It is written
  in C.  There are others, for example **Jython** and **IronPython**.  It is
  fairly easy (with experience) to access code written in C from **CPython**.
* Python now has a long history.  Version 1.0 was released in 1994.
* This class will use Python 3.  However, we will discuss important differences
  from Python 2 as we go along.

## Getting started

To get started, let's log into `corn.stanford.edu`, start the Python 3
interpreter, and execute some Python commands.  Please review the Lecture 0
notes if any of the following is unfamiliar.

1. Use SSH to login with `$ ssh [username]@corn.stanford.edu`
2. Locate the Python 3 interpreter with `$ which python3`
3. Run the Python 3 interpreter with `$ python3`
4. Execute the python statement `print("Hello World!")`

### Some notes

* An *interpreter* is a program that reads and executes commands
* It is also sometimes called a REPL or read-evaluate-print-loop
* One way to interact with Python is to use the interpreter
* This is useful for interactive work, learning, and simple testing
* When you see a `$` in code blocks, it typically indicates a shell command.  For
  example:
```
$ ls
Downloads  bin	    config  gurobi.log	projects  tmp
WWW	   cme213b  cs107   jobs	test.txt  work
$
```
* When you see a `>>>` in code blocks, it typically indicates a command for the
  Python interpreter
* The basic Python interpreter is good for very simple computations or tests.
  [IPython][ipython] provides a lot more functionality (like tab completion and
  syntax highlighting), try `$ ipython3` at the command line

[ipython]: https://ipython.org/

### Python as a calculator

The Python interpreter uses `>>>` as a command prompt (by default).  It is often
useful to use the Python interpreter as a simple calculator:

```
4+7
11
55*2
110
9-1.4
7.6
2/4
0
2//4
0
2.0/4
0.5
2.0//4
0.0
>>>
```

## Integers and floating point

In CME 212, we will discuss in detail the computer representation of integers
and floating point numbers.  For now:

- It is best to think of integers as being represented exactly over a fixed
  range.  (This is not really true in current versions of Python, but will be
  true in C++)

- Floating point numbers are *approximations* of real numbers over a limited
  range.

- Floating point number range is not continuous.  There are gaps between
  floating point numbers that depend on the scale.  The gap between `1.0` and
  the next representable floating point number is smaller than the gap between
  `1.0e50` and the next representable floating point number.

- These things matter and bad numerical computing has resulted in a number of
  disasters: https://www.ima.umn.edu/~arnold/disasters/

### Some more examples

```
1.0
1.0
3/5
0.6
3//5
0
3.//5
0.0
3%5
3
```

* Division between two integers with `/` returns a floating point number
* `//` performs integer division (rounds towards `0`)
* The `%` operator is called the *modulus* operator and returns the remainder
  for integer division

## Python scripts

* A more convenient way to interact with Python is to write a script
* A Python script is a text file containing Python code
* Python script file names typically end in `.py`

### Let's create our first script

* Log into `corn.stanford.edu`

* Create a text file named `firstscript.py` with your favorite text editor
  (`$ nano firstscript.py` is a good choice)

* Insert the following Python code into `firstscript.py`:

```pythonthon
print("Hello from Python.")
print("I am your first script!")
```

* Execute the command `$ python3 fisrtscript.py`

Note the use of the `$ python3` command.  On many systems the command `$ python`
will start the Python 2 interpreter.  For this simple example, the behavior will
be the same.  In general, this is not the case Python versions 2 and 3 have
[many differences][py3-diff].

[py3-diff]: https://docs.python.org/3/whatsnew/3.0.html

### Why scripts?

Let's write a simple Python script to compute the first `n` numbers in the
Fibonacci series.  As a reminder, each number in the Fibonacci series is the sum
of the two previous numbers.  Let `F(i)` be the `i`th number in the series.  We
define `F(0) = 0` and `F(1) = 1`, then `F(i) = F(i-1) + F(i-2)` for `i >= 2`.
Numbers `F(0)` to `F(n)` can be computed with the following Python code:

```pythonthon
n = 10

if n >= 0:
    fn2 = 0
    print(fn2,end=',')
if n >= 1:
    fn1 = 1
    print(fn1,end=',')
for i in range(2,n+1):
    fn = fn1 + fn2
    print(fn,end=',')
    fn2 = fn1
    fn1 = fn
print()
```

Note, the above code is a preview of Python syntax that we will review in this
course.  Now, paste this code into a file named `fib.py`.  Execute the file with
the command `$ python fib.py`.  The result should like:

```
$ python fib.py
0,1,1,2,3,5,8,13,21,34,55,
```

To see the utility of scripts, we need to add a bit more code.  Change the first
line of `fib.py` to be:

```
import sys
n = int(sys.argv[1])
```

This will instruct the script to obtain the value of `n` from the command line:

```
$ python fib.py 0
0,

$ python fib.py 5
0,1,1,2,3,5,

$ python fib.py 21
0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765,10946,
```

We have increased the utility of our program by making it simple to run from the
command line with different input arguments.


## Interacting with Python and Jupyter Notebook

Jupyter Notebooks are great for teaching and interactive work.  From the
[jupyter.org][jupyter] website:

> The Jupyter Notebook is a web application that allows you to create and share
> documents that contain live code, equations, visualizations and explanatory
> text. Uses include: data cleaning and transformation, numerical simulation,
> statistical modeling, machine learning and much more.

[jupyter]: http://jupyter.org/

In Jupyter Notebook, code is typed into code blocks:

```pythonthon
print("hello from a code block!")
```

Code blocks can be re-executed with ease!

You can test Jupyter Notebook in your browser via <https://try.jupyter.org/>.
Note that any work you do here will not be saved.

If you want to install Jupyter Notebook on your computer, I recommend [Anaconda
Python][anaconda].  Make sure to install the Python 3.5 version.

[anaconda]: https://www.continuum.io/downloads

CME211 Notes:
* We do not formally support Jupyter notebook.  I show to the class, because
  it is a very useful tool.  You are responsible for figuring out how to install
  and run Jupyter Notebook.  There are plenty of good tutorials online.
* The teaching staff is not responsible for helping you set up Jupyter Notebook
  on your computer.  Python 3 on `corn.stanford.edu` is the supported computing
  environment.
* All Python work for CME211 must be submitted as Python scripts `.py` files
  that can be executed via the command line.  We will not accept or grade any
  work submitted as a notebook (`.ipynb` format).
* The notes for CME211 are written in [Markdown format][markdown] and [converted
  to Jupyter notebooks][notedown] for lectures and screencasts.

[markdown]: http://commonmark.org/
[notedown]: https://github.com/aaren/notedown

## More math

If you are familiar with Matlab, you may come to Python and be confused by:

```pythonthon
sqrt(3)
```

The Python languange does not have a built in `sqrt` function.  `sqrt` exists in
the Python `math` module:

```python
import math
math.sqrt(9)
```

## Modules

* A module is a collection of Python resources (functions, variables, objects,
  classes) that can be easily loaded into Python via `import` statements

* Modules allow for easy code reuse and organization

* Modules allow the programmer to keep various functionality in different
  namespaces.

* There are a large number of modules in the Python Standard Library:
  <https://docs.python.org/3/library/index.html>

* It is often useful to explore the Python documentation in the interpreter:

```python
import math
help(math)
```

```python
help(math.sqrt)
```

## Variables

Variables may be assigned to data and may also come from modules:

```python
print("pi: ", math.pi)
radius = 4.82
circ = 2*math.pi*radius
print("circ: ", circ)
30.2849531806
```

In Python 3, `print` is a function.  It must be called with parentheses `()`. In
Python 2, `print` is a statement.  If you work with a Python 2 code base, you
will likely see code like:

```
print circ
```

**Question:** what happens when you attempt to reference a variable that has not
been defined?

## Variable naming

* The name associated with a variable is referred to as an *identifier*
* Variables names must start with a letter or an underscore, such as
    * `_underscore`
    * `underscore_`
* The remainder of your variable name may consist of letters, numbers and underscores
    * `password1`
    * `n00b`
    * `un_der_scores`
* Names are case sensitive
    * `case_sensitive`, `CASE_SENSITIVE`, and `Case_Sensitive` are each a
      different variable.

## Variable naming style

* too short: `a`, `b`, `c`
* too long: `number_of_particles_in_target_region`
* better: `num_target_particles`
* CamelCase: `numTargetParticles`

This is quite important for code readability.  People think about this a lot.
See: <https://www.python.org/dev/peps/pep-0008/#naming-conventions>

## Important: don't override built-in names

```python
abs(-7)
```

```python
abs = 'must do sit-ups'
abs(-4)
```

## Printing

Jupyter Notebook will echo the output of the last (non-assignment) statement in
a code block:

```python
1 + 1
5 + 5
```

```python
myvar = 101
# no output
```

You can use the `print()` function:

```python
a = 99
print(a)
```

We will also learn about string formatting:

```python
print("the area of a circle of radius 1 is {}.".format(2*math.pi))
```

## Strings

Strings are a very important data type in all languages.  In Python, strings may
be quoted several ways:

```python
inputfile = "data.txt"
outputfule = 'output.txt'
triplequotes = """woah!
split lines"""
print(triplequotes)
```

## Strings versus numbers

```python
a = 5
b = '5'
a + b
```

```python
print("type(a): ", type(a))
print("type(b): ", type(b))
```

It is simple to convert!

```python
# convert int to a string
a = str(55)
print(a)
print(type(a))
```

```python
# convert string to a float
a = float("99.45")
print(a)
print(type(a))
```

## String slicing

```python
quote = """That's all folks!"""
print(quote[2])
print(quote[7:10])
print(quote[:4])
print(quote[7:])
print(quote[:-7])
```

## Strings are immutable

```python
a = 'hello'
a[0]
```

```python
a[0] = 'k'
```

Concatenate strings with `+``

```python
b = 'j' + a[1:]
b
```

## String functions / methods 	

```python
name = 'Leland'
```

```python
len(name)
```

```python
name.lower()
```

```python
name.upper()
```

```python
name.find('lan')
```

```python
name.find('lan', 1, 4)
```

There are many [string methods][py-str-methods].

[py-str-methods]: https://docs.python.org/3/library/stdtypes.html#string-methods

## Looping

```python
for i in range(5):
    # loop body
    print(i)
```

## Note on Python syntax

Python uses syntatic indenting.  This means that indenting code has a meaning in
the programming language.  In languages like C, C++, and Java, loop bodies are
enclosed in braces, but good coding style suggests that statements in a loop or
conditional body are indented:

```
for (int i = 0; i < 10; i++) {
    printf("i = %d\n",i);
}
```

Python takes this a step further and requires the indenting of loop and
conditional bodies.  We recommend that you use 4 spaces to indent python code
([so does the python community](https://www.python.org/dev/peps/pep-0008/#tabs-or-spaces)).
Please tell your text editors to insert spaces instead of tab characters when
you hit the tab key on the keyboard.

## `for` loop 	

* The function `range(n)` returns a `range` object allowing us to iterate over
  integers `0` to `n-1`

```python
range(6)
```

* The `for i in <sequence>:` can be interpreted as doing the following:
    * assign the loop counter, `i`, the first value in `<sequence>`
    * execute the body of the loop
    * assign the loop counter variable the next value in the sequence and repeat

## `range()`

The `range()` function can be used in a few different ways.  We can convert
a range object to a python list with the `list()` function:

```python
print(list(range(7)))
print(list(range(4,11)))
print(list(range(4,16,3)))
```

## Summing numbers

```python
summation = 0
for n in range(1,101):
    summation += n

print(summation)
```

## Conditional statements

We might want to test the summation example:

```python
if summation != 100*(100+1)/2:
    print("Sorry, wrong answer!")
```

```python
if summation != 100*(100+1)/2:
    print("Sorry, wrong answer!")
else:
    print "Congratulations!"
```

## Boolean logic 	

```python
2 == 2
```

```python
2 == 3
```

```python
2 != 3
```

```python
a = 2
```

```python
b = 3
```

```python
a == 2 and b == 3
```

```python
a == 2 or b == 4
```

## Boolean logic and numbers 	

```python
a = 2
if a:
    print("True")
```

```python
b = 0
if b:
    print("True")
```

## Boolean logic and strings 	

```python
msg = "Hello!"
if msg:
    print("Evaluated True")
```

```python
msg = ""
if msg:
    print("Evaluated True")
```

## else if: `elif`

If you need to handle more than an `if` and `else` case use one or more `elif`:

```python
if summation < 5050:
    print("Too low")
elif summation > 5050:
    print("Too high")
else:
    print("Just right")
```

## `while` loop 	

* The `for` loop is associated with executing a loop body a known number of
  times

* What if we’re unsure how many times we’ll need to execute the loop?

```python
n = 0
while n < 7:
    print(n)
    n = n + 1
```

## Infinite loops

```
while True:
    pass
```

* In Jupyter Notebook, select "Interrupt" from the Kernel menu
* Use `ctrl-c` to interrupt the interpreter

## Nesting loops 	

```python
for i in range(5):
    for j in range(i):
        print(j,end=" ")
    print()
```

## Nesting loops and logic

```python
for i in range(8):
    for j in range(i):
        print(j),
    print()
```

## `continue`

The `continue` statement allows you to skip the remainder of a loop body and
continue with the next iteration:

```python
for n in range(10):
    if not 3 < n < 7:
        continue
    print(n)
```

## `break`

The `break` statement allows one to immediately exit from a `for` or `while`
loop

```python
for n in range(10):!
    if n > 3:
        break
    print(n)
```

## Innermost loop

`continue` and `break` only apply to the innermost loop being executed:

```python
for i in range(2):
    print("i = {}".format(i))
    for j in range(2):
        break
        print("j = {}".format(j))
        for k in range(2):
            print("k = {}".format(k))
```

## Loop `else`

* An `else` can be used with a `for` or `while` loop

* The `else` is only executed if the loop runs to completion, not when a `break`
statement is executed

```python
for i in range(4):
    print(i)
else:
    print("all done")
```

```python
for i in range(7):
    print(i)
    if i > 3:
        break
else:
    print("all done")
```

## Exiting the interpreter

* use `ctrl-d`

* use `exit()`

```
$ python3
Python 3.5.2 (default, Jun 29 2016, 13:43:58)
[GCC 4.2.1 Compatible Apple LLVM 7.3.0 (clang-703.0.31)] on darwin
Type "help", "copyright", "credits" or "license" for more information.
>>> exit
Use exit() or Ctrl-D (i.e. EOF) to exit
>>> exit()
```
