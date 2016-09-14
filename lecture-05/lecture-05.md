# CME 211: Lecture 5

## Python functions

* Code we have seen so far has been executed in linear fashion from top to
  bottom, sometimes repeating one or more lines in a loop body

* Functions allow us to:

  * Replace duplicated code with one centralized implementation within a single
    program

  * Reuse code across different programs

  * Easily use code developed by others

  * Develop, test, debug code in isolation from other code

* Analogous to mathematical functions

### Defining a function in Python

Let's start with an example:

```python
def print_hello(name):
    print("Hello, {}".format(name))
```

If Python encounters a function name without parens `()`, it tells us that it
is a function:

```python
print_hello
```

Call the function:

```python
print_hello("CME211")
```

### Anatomy of a Python function

```python
def function_name(input_argument):
    # function body
    print("you guys rock")
```

1. start with `def` keyword

2. give the function name

3. followed by comma separated list of input arguments, surrounded by
   parentheses

  * just use `()` for no inputs

4. followed by a colon `:`

5. followed by **indented** function body

### Return a value

Use the `return` keyword to return an object from a function:

```python
def summation(a, b):
    total = 0
    for n in range(a,b+1):
        total += n
    return total
```

```python
c = summation(1, 100)
c
```

### Return multiple values

Separate multiple return values with a comma:

```python
def sum_and_prod(a,b):
   total = 0
   prod = 1
   for n in range(a,b+1):
       total += n
       prod *= n
   return total, prod
```

Call the function:

```python
a = sum_and_prod(1,10)
print("a:", a)
print("type(a):", type(a))
```

The `return` keyword packs multiple outputs into a tuple.  You can use Python's
tuple unpacking to nicely get the return values in calling code.

```python
a, b = sum_and_prod(1,10)
print("a:", a)
print("b:", b)
```

### Variable scope

Let's look at an example to start discussing variable scope:

```python
total = 42
def summation(a, b):
    total = 0
    for n in range(a, b+1):
        total += n
    return total

a = summation(1, 100)
```

```python
print("total:", total)
```

```python
print("n:", n)
```

Function bodies have a local namespace.  In this example the `summation`
function does not see the variable `total` from the top level scope.
`summation` creates its own variable `total` which is different!  The top level
scope also cannot see variables used inside of `summation`.

Reference before assignment to a global scope variable will cause an error:

```python
total = 0
def summation(a, b):
    for n in range(a, b+1):
        total = total + n
        #         ^
        #       reference before assignment
    return total

a = summation(1, 100)
```

### Variable scope examples

It is possible to use a variable from a higher scope.  This is generally
considered bad practice:

```python
a = ['hi', 'bye']
def func():
    print(a)

func()
```

Even worse practice is modifying a mutable object from a higher scope:

```python
a = ['hi', 'bye']
def func():
    a.append('hello')

func()
print(a)
```

Python will not let you redirect an identifier at a global scope.  Here the
function body has its own `a`:

```python
a = ['hi', 'bye']
def func():
    a = 2

func()
print(a)
```

### Accessing a global variable

This is bad practice, do not do this.  We will take off points.  We show you in
case you run into it.

```python
total = 0
def summation(a,b):
    global total
    for n in range(a, b+1):
        total += n

a = summation(1,100)
print("total:",vtotal)
```

### Functions must be defined before they are used

In scripts (and the interpreter), functions must be defined before they are
used!  See the file `lecture-6/order1.py`:

```python
def before():
    print("I am function defined before use.")

before()
after()

def after():
    print("I am function defined after use.")
```

Output:

```
$ python3 order1.py
I am function defined before use.
Traceback (most recent call last):
  File "order.py", line 5, in <module>
    after()
NameError: name 'after' is not defined
$
```

A function may refer to another function defined later in the file.  The rule is
that functions must be defined before they are actually invoked/called.

```python
def sumofsquares(a, b):
    total = 0
    for n in range(a, b+1):
        total += squared(n)
    return total

def squared(n):
    return n*n

print sumofsquares(1,10)
```

Output:

```
$ python3 order2.py
385
$
```


### Passing convention

Python uses pass by object reference.  Python functions can change mutable
objects refereed to by input variables

```python
def DoChores(a):
    a.pop()

b = ['feed dog', 'wash dishes']
DoChores(b)
b
['feed dog']

```

`int`s, `float`s, and `str`ings are immutable objects and cannot be changed by a
function:

```python
def increment(a):
    a = a + 1

b = 2
increment(b)
b
2
```

### Pass by object reference

* Python uses what is sometimes called pass by object reference when calling
functions

* If the reference is to a mutable object (e.g. lists, dictionaries, etc.), that
object might be modified upon return from the function

* For references to immutable objects (e.g. numbers, strings), by definition the
original object being referenced cannot be modified

### Example of a bad function

```
def add(a, b):
    # I wrote this function because Nick
    # is mean and is making us write three functions
    return a + b
```

## Recommended Reading

From **Learning Python, Fifth Edition** by Mark Lutz

* Chapter 6: The Dynamic Typing Interlude (i.e. references and objects)

* Chapter 16: Function Basics

* Chapter 17: Scopes

* Chapter 18: Arguments
