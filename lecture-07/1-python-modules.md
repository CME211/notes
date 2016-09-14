## Python modules

### Organization

* Your code should be organized in some way

* Code should often be split across multiple files for ease of maintenance and
  reuse

* For large projects you will probably have multiple directories each with
  multiple files

### Modules

* Code in Python can be organized and accessed as modules

* We've already used some modules that are part of Python (math, time, etc.)

* These modules were accessed using the import statement

### Import

Here is an example if importing and using a function from the `time` module:

```py
>>> import time
>>> time.time()
1381091212.070504
>>> time()
Traceback (most recent call last):
File "<stdin>", line 1, in <module>
TypeError: 'module' object is not callable
>>> type(time)
<type 'module'>
>>> type(time.time)
<type 'builtin_function_or_method'>
>>>
```

* Keep in mind that the module name/object is different then the function that
  exists inside of the module

### Reference to a function

Functions are also objects and may be assigned to a variable:

```py
>>> t = time.time
>>> type(t)
<type 'builtin_function_or_method'>
>>> t is time.time
True
>>> t()
1381091266.353158
>>>
```

### Import a single function

We can import a single function from a module:

```py
>>> from time import time
>>> type(time)
<type 'builtin_function_or_method'>
>>> time()
1381091470.26926
>>> import time
>>> type(time)
<type 'module'>
>>> time.time()
1381091483.548532
>>>
```

Another example is `from math import sqrt`.

### Import and rename

We can rename a function in the import statement:

```py
>>> from time import time as timer
>>> type(timer)
<type 'builtin_function_or_method'>
>>> timer()
1381091498.986958
>>>
```

### Wild card import

We can import everything from a module into the global namespace with:

```py
>>> from time import *
>>> type(time)
<type 'builtin_function_or_method'>
>>> time()
1381091614.217997
>>>
```

This is normally not a good idea, because you may unknowingly overwrite some
symbols that have been defined elsewhere.

### Modules and namespaces

* Not only do modules allow you to separate code into multiple files, but they
  also provide distinct namespaces

* Namespaces are particularly important in larger projects where reuse of common
  terms could be confusing at best

* Attribute renaming and/or wild card imports can make code less readable and
  more difficult to debug

### Example

Here we know where `time()` is coming from:

```py
import time
import mymodule
...
t = time.time()
```

Does `time()` come from `time` or `mymodule`?

```py
from time import *
from mymodule import *
...
t = time()
```

**Recommendation:** be explicit when using module functions!

### Writing your first module

See file `code/mymodule1.py`:

```py
def summation(a,b):
    total = 0
    for n in range(a,b+1):
        total += n
    return total

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]
```

### Using your first module

```py
>>> import mymodule1
>>> mymodule1.summation(1,100)
5050
>>> mymodule1.primes
[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
41, 43, 47]
>>>
```

### Improving your module

Add test code in file `code/mymodule2.py`:

```py
def summation(a,b):
    total = 0
    for n in range(a,b+1):
        total += n
    return total

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]

print('Testing function summation():...'),
total = summation(1,100)
if (total == 5050):
    print('OK')
else:
    print('FAILED')
```

### Testing your new module

```py
>>> import mymodule2
Testing function summation():... OK
>>> mymodule2.summation(1,100)
5050
>>> mymodule2.primes
[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
41, 43, 47]
>>>
```

### Import process

When you do `import mymodule2` several things happen

1. Python interpreter looks for a `.py` file with the same name as the module,
starting with your current directory followed by looking in system wide
locations

2. Code is byte compiled from the `.py` file to a `.pyc` file

3. File is processed from top to bottom

### Locating modules

* Searches for a module are based on directories in
the `sys.path` list

* First item in the `sys.path` list is an empty string, `''``, which is used to
  denote the current directory

```py
$ pwd
/home/nwh/git/cme211-notes/lecture-07
$ ls *.py
mymodule1.py  mymodule2.py
$ python
Python 2.7.5+ (default, Feb 27 2014, 19:37:08)
[GCC 4.8.1] on linux2
Type "help", "copyright", "credits" or "license" for more information.
>>> import sys
>>> sys.path.remove('')
>>> import mymodule1
Traceback (most recent call last):
File "<stdin>", line 1, in <module>
ImportError: No module named mymodule1
>>> sys.path.insert(0,'')
>>> import mymodule1
>>>
```

### .pyc files

```
$ ls *.py*
mymodule1.py  mymodule1.pyc  mymodule2.py  mymodule2.pyc
```

* When you import a file Python byte compiles the file


* `.pyc` files are faster to load, but the runtime performance once you have
* them loaded is exactly the same

### `__name__` and `__main__`

* Special variable `__name__` is equal to `__main__` if the file is being
  executed as the main program

* `__name__` will not be equal to `__main__` if the file is being imported

### "Hiding" code during import

See `code/mymodule3.py`

```py
def summation(a,b):
    total = 0
    for n in range(a,b+1):
        total += n
    return total

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]

if __name__ == '__main__':
    print('Testing function summation():...'),
    total = summation(1,100)
    if (total == 5050):
        print('OK')
    else:
        print('FAILED')
```

### Another try at importing

```py
>>> import mymodule3
>>> mymodule3.summation(1,100)
5050
>>> mymodule3.primes
[2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37,
41, 43, 47]
>>>
```

### Running the test code

```
$ python3 mymodule3.py
Testing function summation()... OK
$
```

### Documenting the module

See `code/mymodule4.py`:

```py
"""
My module of misc code.
"""

def summation(a,b):
    """
    Returns the sum of numbers between, and including, a and b.
    """

    total = 0
    for n in range(a,b+1):
        total += n
    return total

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]

if __name__ == '__main__':
    print('Testing function summation():...'),
    total = summation(1,100)
    if (total == 5050):
        print('OK')
    else:
        print('FAILED')
```

### Accessing your documentation

```py
>>> import mymodule4
>>> help(mymodule4)
```

```
Help on module mymodule4:

NAME
mymodule4 - My module of misc code.

FILE
/afs/.ir.stanford.edu/users/p/l/plegresl/CME211/Lecture07/mymodule4.py

FUNCTIONS
summation(a, b)
Returns the sum of numbers between, and including, a and b.

DATA
primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]

(END)
```
## Python Error Handling

### Errors in Python

```py
>>> a = [3, 7]
>>> a[2]
Traceback (most recent call last):
File "<stdin>", line 1, in <module>
IndexError: list index out of range
>>> b = {'cupcakes' : 7, 'brownies' : 2}
>>> b['cookies']
Traceback (most recent call last):
File "<stdin>", line 1, in <module>
KeyError: 'cookies'
>>>
```

### Recommended Reading

* Chapter 22: Modules: The Big Picture

* Chapter 23: Module Coding Basics
