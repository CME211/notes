# CME 211: Lecture 8

Wednesday, October 7, 2015

Topic: Introduction to Object Oriented Programming (OOP) in Python

## Announcements

* Deadline: by 5pm today you must have a GitHub account.  If you have not
  created a GitHub account and sent us your account information, your homework 2
  **will not** be graded.  You can do this today and email the following to
  <cme211-staff@lists.stanford.edu>:

  * GitHub user name

  * Stanford email address

  * Email address you used to register on GitHub

* Example to show good formatting of a Python program:
  <https://github.com/nwh/cme211-notes/blob/master/examples/ngrams/ngrams.py>

## Command line arguments

In Python it is easy to pass command line arguments into a program.  For
review, a shell command looks like this:

```
$ command arg1 arg2 arg3
```

For example:

```
$ ls -l code/
total 48
-rw-rw-r--. 1 nwh nwh  65 Oct  7 13:23 filewrite.py
-rw-rw-r--. 1 nwh nwh  14 Oct  7 13:23 hello.txt
-rw-rw-r--. 1 nwh nwh 184 Oct  7 13:23 self.py
-rw-rw-r--. 1 nwh nwh 230 Oct  7 13:23 student10.py
-rw-rw-r--. 1 nwh nwh   0 Oct  7 13:23 student11.py
-rw-rw-r--. 1 nwh nwh  89 Oct  7 13:23 student1.py
-rw-rw-r--. 1 nwh nwh   0 Oct  7 13:23 student2.py
-rw-rw-r--. 1 nwh nwh 176 Oct  7 13:23 student3.py
-rw-rw-r--. 1 nwh nwh 279 Oct  7 13:23 student4.py
-rw-rw-r--. 1 nwh nwh 469 Oct  7 13:23 student5.py
-rw-rw-r--. 1 nwh nwh 568 Oct  7 13:23 student6.py
-rw-rw-r--. 1 nwh nwh 618 Oct  7 13:23 student7.py
-rw-rw-r--. 1 nwh nwh 182 Oct  7 13:23 student8.py
-rw-rw-r--. 1 nwh nwh 243 Oct  7 13:23 student9.py
```

* The command is: `ls`
* The first argument is `-l` which tells `ls` to output detailed information for
  each file
* The second argument is the directory I want to list

In a python scripts we can get access to the command line arguments with the
`sys.argv` variable.  `sys.argv` is a list containing the command line arguments
as items.  Command line arguments are separated by spaces.  See the example in
`code/command.py`:

```py
import sys

print("There are {} command line argument(s).".format(len(sys.argv)))

for i, arg in enumerate(sys.argv):
    print("arg {}: {}".format(i,arg))
```

Output:

```
$ python command.py a b c
There are 4 command line argument(s).
arg 0: command.py
arg 1: a
arg 2: b
arg 3: c
$ python command.py a b c "quote things with spaces"
There are 5 command line argument(s).
arg 0: command.py
arg 1: a
arg 2: b
arg 3: c
arg 4: quote things with spaces
$
```

Notes:

* `sys.argv[0]` is the name of the python script
* arguments are separated by spaces
* need to quote a string containing spaces
* in python, the data type is `str`, need to convert to an `int` or `float` if
  you want a number

## Introduction to OOP

### Procedural programming

* In procedural programming you implement your computation in terms of variables
(integers, doubles, etc.), data structures (arrays, lists, dictionaries, etc.),
and procedures (functions, subroutines, etc.)


* Python, C++, Fortran, Java, MATLAB, and many other languages have procedural
aspects to them but also support Object Oriented Programming (OOP)

### Why OOP?

* Concept of OOP has been around since 1960s

* Gained popularity in the 1980s and 1990s with the development and
standardization of C++, and faster computers that mitigated the overhead of the
abstractions

* Abstraction, modularity, and reusability are some of the most commonly cited
reasons for using OOP

* Almost all new software development uses some degree of OOP

### Abstraction

* Represent data and computations in a familiar form

    * Car object, with an engine object, and tire objects

* Make programmers more productive

    * Salaries are expensive compared to computers

* Too much abstraction can be a bad thing if it has a significant impact on
performance

    * Desktop computers really are cheap

    * Supercomputers are not cheap

### Objects

* In OOP you express your computations in terms of objects, which are instances
  of classes

* Classes are blueprints for objects

![fig/class-object.png](fig/class-object.png)

* Classes specify data and the methods to use or interact with that data

### Class / object example 1: list

```py
>>> a = list()
>>> a.append(5)
>>> a.append(19)
>>> a.append(3)
>>> a
[5, 19, 3]
>>> a.sort()
>>> a
[3, 5, 19]
>>>
```

* `list()` returns an object which is an instance of the *list* class
* `append()` and `sort()` are *methods*
* 3, 5, 19 are the *data* maintained by the object

### Class / object examples 2: file objects

See the file `code/filewrite.py`:

```py
f = open("hello.txt", "w")
f.write("hello cme211!\n")
f.close()
```

* The `open()` function returns an *object* which is an instance of the *file
  class*

* `write()` and `close()` are methods of the *file class*

If we run the code in *interactive* mode, we can inspect these things in
Python's online help:

```
$ python -i filewrite.py
>>> help(open)
```

Output:

```
Help on built-in function open in module __builtin__:

open(...)
    open(name[, mode[, buffering]]) -> file object

    Open a file using the file() type, returns a file object.  This is the
    preferred way to open a file.  See file.__doc__ for further information.
```

Now let's look at the file object with `>>> help(f)`:

```
Help on file object:

class file(object)
 |  file(name[, mode[, buffering]]) -> file object
 |  
 |  Open a file.  The mode can be 'r', 'w' or 'a' for reading (default),
 |  writing or appending.  The file will be created if it doesn't exist
 |  when opened for writing or appending; it will be truncated when
 |  opened for writing.  Add a 'b' to the mode for binary files.
 |  Add a '+' to the mode to allow simultaneous reading and writing.
 |  If the buffering argument is given, 0 means unbuffered, 1 means line
 |  buffered, and larger numbers specify the buffer size.  The preferred way
 |  to open a file is with the builtin open() function.
 |  Add a 'U' to mode to open the file for input with universal newline
 |  support.  Any line ending in the input file will be seen as a '\n'
 |  in Python.  Also, a file so opened gains the attribute 'newlines';
 |  the value for this attribute is one of None (no newline read yet),
 |  '\r', '\n', '\r\n' or a tuple containing all the newline types seen.
 |  
 |  'U' cannot be combined with 'w' or '+' mode.
 |  
 |  Methods defined here:
 |  
 |  __delattr__(...)
 |      x.__delattr__('name') <==> del x.name
 |  
 |  __enter__(...)
 |      __enter__() -> self.
 |  
```

The help documentation continues.  The public interface methods are at the
bottom.  I wish they would swap the order.

### Modularity and reusability

* High level languages like Python, Java, C++, etc.  include classes for working
with files, holding data (lists and dictionaries), etc.


* So you do not have to design and create your own classes if someone else has
already done the work for you


* But you might want to create classes that are specialized to the needs of your
applications, so they can be used (and reused) by yourself and others

### OOP in Python

* New kinds of objects can be created in Python by defining your own classes

* Classes are the blueprint for creating objects which are known as instances of
the class

* Classes have *attributes*

    * Variables (data) are called class *variables*

    * Functions for interacting with the class are called *methods*

    * Attributes are accessed using *dot notation*

### Creating instances

* Instances of a class are created by calling the class object as a function

* Any arguments of the function call are passed to the special `__init__()`
  method

### Python class definition

```py
class Student:
    def __init__(self, id):
        self.id = id
```

* Classes are defined with the `class` keyword
* Followed by the class name and a colon (`:`)
* Followed by the indented class body, containing class *attributes*

### Object initialization

```py
    def __init__(self, id):
        self.id = id
```

* `__init__` is the special name for the initialization method
* `self` is a reference to the specific instance (object) that is calling this
  method
* `id` is the input argument from the call to create a new instance
* `self.id = id` stores the input `id` in the object

### Class definition in action

See the file `code/student1.py`

```py
class Student:
    def __init__(self, id):
        self.id = id

s = Student(7)
print(s)
```

Output:

```
$ python student1.py
<__main__.Student instance at 0x1069f6c20>
$
```

### Let's talk about `self`

See `code/self.py`:

```py
class Student:
    def __init__(self, id):
        print("inside __init__()")
        print("self = {}".format(self))
        self.id = id

s = Student(7)
print("s    = {}".format(s))
```

Output:

```
$ python self.py
inside __init__()
self = <__main__.Student instance at 0x10967cc20>
s    = <__main__.Student instance at 0x10967cc20>
$
```

### Object setup

* The optional initialization method is typically used to do setup of class
variables that will be used throughout the life of the instance

* What kind of class variables might we want to setup for a student class?

### Class variable setup

See `code/student2.py`.  Let's add an empty dictionary for the classes that
the student is enrolled in:

```py
class Student:
    def __init__(self, id):
        self.id = id
        self.classes = {}

s = Student(7)
```

### Architecting our object

* Our object has data about `id` and `classes`

* But how do we do anything with it?

* We need to create additional methods for interacting or *interfacing* with the
object

### Encapsulation

* The *interface* of an object encapsulates the internal data and code

* *encapsulation* means hiding the details of data structures and algorithms
(internal code)

![fig/encapsulation.png](fig/encapsulation.png)

### Interfaces

* Interfaces protect the user of the class from internal implementation details

* Found a better way to implement the internal representation of the data? No
problem

* New algorithm for the internal processing of that data? No problem

* Screwed up your interface and now need to make changes to the interface?
Problem

### Defining a regular method

Inside of the `Student` class, we put:

```py
    def getId(self):
        return self.id
```

* just like defining a Python function

* `self` is a reference to the specific instance that is calling this method

### Access to id

See `code/student3.py`:

```py
class Student:
    def __init__(self, id):
        self.id = id
        self.classes = {}
    def getId(self):
        return self.id

s = Student(7)
print(s)
print(s.getId())
```

Output:

```
$ python student3.py
<__main__.Student instance at 0x1038becb0>
7
$
```

### Check up

* How are we doing with interface design?

* Is there a way somebody could accidentally change the id given the interface
we've implemented?

* Let's test it!  See `code/student4.py`:

```py
class Student:
    def __init__(self, id):
        self.id = id
        self.classes = {}
    def getId(self):
        return self.id

s = Student(7)
print(s)
id = s.getId()
print("id = {}".format(id))
id = 9
print("id = {}".format(id))
print("s.getId() = {}".format(s.getId()))
```

Output:

```
$ python student4.py
<__main__.Student instance at 0x10bef2cb0>
id = 7
id = 9
s.getId() = 7
$
```

* The reference returned by `getId()` cannot be used to change the assignment of
  the reference within the object.


### Adding classes / grades

See: `code/student5.py`:

```py
class Student:
    def __init__(self, id):
        self.id = id
        self.classes = {}
    def getId(self):
        return self.id
    def addClass(self, name, gradepoint):
        self.classes[name] = gradepoint
        sumgradepoints = float(sum(self.classes.values()))
        self.gpa = sumgradepoints/len(self.classes)
    def getGPA(self):
        return self.gpa

s = Student(7)
s.addClass("gym", 4)
s.addClass("math", 3)
print("GPA = {}".format(s.getGPA()))
```

Output:

```
$ python student5.py
GPA = 3.5
$
```

### Getting classes

See `code/student6.py`:

```py
class Student:
    def __init__(self, id):
        self.id = id
        self.classes = {}
    def getId(self):
        return self.id
    def addClass(self, name, gradepoint):
        self.classes[name] = gradepoint
        sumgradepoints = float(sum(self.classes.values()))
        self.gpa = sumgradepoints/len(self.classes)
    def getGPA(self):
        return self.gpa
    def getClasses(self):
        return self.classes

s = Student(7)
s.addClass("gym", 4)
s.addClass("math", 3)
print("GPA = {}".format(s.getGPA()))
print("classes = {}".format(s.getClasses()))
```

Output:

```
$ python student6.py
GPA = 3.5
classes = {'gym': 4, 'math': 3}
$
```

### Getting classes

If a method returns a reference to a mutable object, then changing that object
"outside" of the class will change the data "inside" of the class.  See `code/student7.py`

```py
class Student:
    def __init__(self, id):
        self.id = id
        self.classes = {}
    def getId(self):
        return self.id
    def addClass(self, name, gradepoint):
        self.classes[name] = gradepoint
        sumgradepoints = float(sum(self.classes.values()))
        self.gpa = sumgradepoints/len(self.classes)
    def getGPA(self):
        return self.gpa
    def getClasses(self):
        return self.classes

s = Student(7)
s.addClass("gym", 4)
s.addClass("math", 3)

classes = s.getClasses()
classes["englist"] = 4

print("GPA = {}".format(s.getGPA()))
print("classes = {}".format(s.getClasses()))
```

Output:

```
$ python student7.py
GPA = 3.5
classes = {'gym': 4, 'englist': 4, 'math': 3}
$
```

### Interfaces and references

* It is easy to accidentally let a method provide a reference to a mutable data
structure within your object

* Once you have handed out that reference someone can manipulate your internal
data and perhaps get the object into an unexpected state

* You really need to think about what you pass out of your object if you want to
have strong encapsulation

### Public attributes

* Default behavior is that all attributes are public, i.e. accessible using dot
notation

`code/student8.py`:

```py
class Student:
    def __init__(self, id):
        self.id = id
        self.classes = {}
    def getId(self):
        return self.id

s = Student(7)
print("s.id = {}".format(s.id))
```


Output:

```
$ python student8.py
s.id = 7
$
```

### Public attributes

`code/student9.py`:

```py
class Student:
    def __init__(self, id):
        self.id = id
        self.classes = {}
    def getId(self):
        return self.id

s = Student(7)
print("s.getId() = {}".format(s.getId()))
s.id = 9
print("s.getId() = {}".format(s.getId()))
```

Output:

```
$ python student9.py
s.getId() = 7
s.getId() = 9
$
```

### Private attributes

* Attributes can be made private by using a double underscore prefix for the
name

* See `code/student10.py`:

```py
class Student:
    def __init__(self, id):
        self.__id = id
        self.classes = {}
    def getId(self):
        return self.__id

s = Student(7)
print("s.getId() = {}".format(s.getId()))
print("s.id = {}".format(s.__id))
```

* Output

```
$ python student10.py
s.getId() = 7
Traceback (most recent call last):
  File "student10.py", line 10, in <module>
    print("s.id = {}".format(s.__id))
AttributeError: Student instance has no attribute '__id'
$
```

### "Privacy" through obscurity

Run `student10.py` in interactive mode:

```
$ python -i student10.py
s.getId() = 7
Traceback (most recent call last):
File "student10.py", line 10, in <module>
print "s.id = %s" % s.__id
AttributeError: Student instance has no attribute '__id'
>>> s._Student__id
7
>>> s._Student__id = 9
>>> s.getId()
9
>>>
```

The "private" attribute is still accessible by prefixing it with `_<class name>`.

### What not to do

Python is dynamic, which is great.  But you should not do this:

```
$ python
Python 2.7.4 (default, Sep 26 2013, 03:20:26)
[GCC 4.7.3] on linux2
Type "help", "copyright", "credits" or "license" for more information.
>>> class MyClass:
...
pass
...
>>> a = MyClass()
>>> a.nitems = 3
>>> a.todo = []
>>> a.todo.append("get groceries")
>>> a.todo
['get groceries']
>>>
```

### OOP Summary

* Object Oriented Programming is about implementing abstractions such that data,
and the associated operations on it, are represented in a way that is more
familiar to humans

* Mechanics of OOP are about the same as procedural programming, but developing
good abstractions can take a lot of thought

### Recommended Reading

*Learning Python, Fifth Edition* by Mark Lutz

* Chapter 26: OOP: The Big Picture

* Chapter 27: Class Coding Basics
