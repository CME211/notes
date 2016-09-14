

### Exceptions

* Errors generate exceptions

* Exceptions can potentially be caught

* Uncaught exceptions propagate up to the interpreter, which halts execution and
  displays the information in a traceback

### Exceptions

* Python uses a try/except model for error handling

```py
>>> f = open('thisfiledoesntexist.txt')
Traceback (most recent call last):
File "<stdin>", line 1, in <module>
IOError: [Errno 2] No such file or directory: 'thisfiledoesntexist.txt'
>>> try:
...     f = open('thisfiledoesntexist.txt')
... except IOError:
...     print 'That filename doesn't exist.'
...
That filename doesn't exist.
>>>
```

### Catching multiple exceptions

```py
>>> try:
...     5/0
... except IOError, e:
...     print('I/O error')
... except ZeroDivisionError, e:
...     print('Zero division error')
... except Exception, e:
...     print(e)
...
Zero division error
>>>
```

### Raising exceptions

From `code/mymodule5.py`:

```py
import types

def summation(a,b):
    """
    Returns the sum of numbers between, and including, a and b.
    """

    if (type(a) != types.IntType or type(b) != types.IntType):
        raise ValueError, 'Expected integers'

    total = 0
    for n in range(a,b+1):
        total += n
    return total
```

Using:

```py
>>> import mymodule4
>>> mymodule4.summation(1,'hello')
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
  File "mymodule4.py", line 11, in summation
    for n in range(a,b+1):
TypeError: cannot concatenate 'str' and 'int' objects
>>> import mymodule5
>>> mymodule5.summation(1,'hello')
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
  File "mymodule5.py", line 13, in summation
    raise ValueError, 'Expected integers'
ValueError: Expected integers
>>>
```

### Recommended Reading

* Chapter 33: Exception Basics

* Chapter 34: Exception Coding Details
