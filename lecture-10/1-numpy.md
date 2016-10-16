## Performance comparison

`code/summation.cpp`:

```c++
#include <iostream>
#include <ctime>

int main() {
  std::clock_t start = std::clock();
  int sum = 0;
  for(int n = 0; n < 1000000; n++) {
    sum++;
  }
  double duration = (std::clock()-start) / (double) CLOCKS_PER_SEC;

  std::cout << sum << std::endl;
  std::cout << "time = " << duration << std::endl;

  return 0;
}
```

`code/summation1.py`:

```
import time

t0 = time.time()
total = 0
for n in range(1000000):
    total += 1
t1 = time.time()
print(total)
print("time = {}".format(t1-t0))
```

Output:

```
$ python3 summation1.py
1000000
time = 0.17532491684
$

$ ./summation
1000000
time = 9.53674e-07
$
```

Compile the C++ code with: `$ g++ summation.cpp -o summation`

### Python is kind of slow

One of the main disadvantages of a higher level language is that, while
comparatively easy to program, it is typically slow compared to C/C++, Fortran,
or other lower level languages

![fig](fig/python-v-compiled.png)

### Object overhead

![fig](fig/object-overhead.png)

### Options

* Python is great for quick projects, prototyping new ideas, etc.

* What if you need better performance?

* One option is to completely rewrite your program in something like C/C++

### Python C API

* Python has a C API which allows the use of compiled modules

![fig](fig/python-c-interface.png)

* The actual implementation of `string.find()` can be viewed at:

http://svn.python.org/view/python/trunk/Objects/stringlib/fastsearch.h

### Python compiled modules

* Python code in a `.py` file is actually executed in a hybrid approach by a mix
of the interpreter and compiled modules that come with Python

![fig](fig/python-compiled-modules.png)

### Extension modules

* The same Python C API used by the developers of Python itself also allows
other programmers to develop and build their own compiled extension modules

* These modules extend the functionality of Python with high performance
implementations of common operations

* Other languages, such as C++ and Fortran, are also supported by using the C
API

### NumPy, SciPy, matplotlib

* NumPy - multidimensional arrays and fundamental operations on them

* SciPy - Various math functionality (linear solvers, FFT, optimization, etc.)
utilizing NumPy arrays

* matplotlib - plotting and data visualization

* None of these packages seek to clone MATLAB, if you want that try something
like GNU Octave

### Python software stack

![fig](fig/python-stack.png)

### NumPy

```py
>>> import numpy
>>> a = numpy.array([7, 42, -3])
>>> a
array([ 7, 42, -3])
>>> a[1]
42
>>> a[1] = 19
>>> a
array([ 7, 19, -3])
>>>
```

### Arrays are not lists

```py
>>> a[0] = "hello"
Traceback (most recent call last):
File "<stdin>", line 1, in <module>
ValueError: invalid literal for long() with base 10: 'hello'
>>> a.append(8)
Traceback (most recent call last):
File "<stdin>", line 1, in <module>
AttributeError: 'numpy.ndarray' object has no attribute 'append'
>>>
```

### NumPy arrays

* NumPy arrays contain **homogeneous** data

* Size is fixed, i.e. you can't append or remove

### Data types

* Integers

    * 8, 16, 32, and 64 bit signed and unsigned (numpy.int8, numpy.uint8, etc.)

* Floating point

    * 32, 64, 128 bit (numpy.float32, numpy.float64, etc.)

* Complex, strings, and Python object references also supported

### Data type examples

```py
>>> a = numpy.array([ 7, 19, -3], dtype=numpy.float32)
>>> a
array([ 7., 19., -3.], dtype=float32)
>>> a[0] = a[0]/0.
__main__:1: RuntimeWarning: divide by zero encountered
>>> a
array([ inf, 19., -3.], dtype=float32)
>>> b = numpy.array([4, 7, 19], dtype=numpy.int8)
>>> b
array([ 4, 7, 19], dtype=int8)
>>> b[0] = 437
>>> b
array([-75,
7, 19], dtype=int8)
>>>
```

### Multidimensional arrays

* Arrays can have multiple dimensions called *axes*

* The number of *axes* is called the *rank*

### Multidimensional arrays

```py
>>> a = numpy.array([(7, 19, -3), (4, 8, 17)], dtype=numpy.float64)
>>> a
array([[ 7., 19., -3.],
[ 4.,
8., 17.]])
>>> a.ndim
2
>>> a.dtype
dtype('float64')
>>> a.shape
(2, 3)
>>> a.size
6
>>>
```

### Internal representation

![fig](fig/numpy-representation.png)

### Creating arrays

```py
>>> a = numpy.empty((3,3))
>>> a
array([[  2.12261410e-314,   0.00000000e+000,   2.14827413e-314],
       [  2.14834326e-314,   2.14832351e-314,   2.14834284e-314],
       [  0.00000000e+000,   0.00000000e+000,   2.12336647e-314]])
>>> a = numpy.zeros((3,3))
>>> a
array([[ 0.,  0.,  0.],
       [ 0.,  0.,  0.],
       [ 0.,  0.,  0.]])
>>> a = numpy.ones((3,3))
>>> a
array([[ 1.,  1.,  1.],
       [ 1.,  1.,  1.],
       [ 1.,  1.,  1.]])
>>> a = numpy.eye(3)
>>> a
array([[ 1.,  0.,  0.],
       [ 0.,  1.,  0.],
       [ 0.,  0.,  1.]])
>>>
```

### Creating more arrays

```py
>>> a = numpy.arange(9, dtype=numpy.float64)
>>> a
array([ 0., 1., 2., 3., 4., 5., 6., 7., 8.])
>>> a = numpy.arange(9, dtype=numpy.float64).reshape(3,3)
>>> a
array([[ 0., 1., 2.],
[ 3., 4., 5.],
[ 6., 7., 8.]])
>>>
```

### Creating more arrays

```
$ cat numbers.txt
7. 19. -3.
4. 8. 17.
$ python
Python 2.7.5+ (default, Feb 27 2014, 19:37:08)
[GCC 4.8.1] on linux2
Type "help", "copyright", "credits" or "license" for more information.
>>> import numpy
>>> a = numpy.loadtxt('numbers.txt', dtype=numpy.float64)
>>> a
array([[ 7., 19., -3.],
[ 4.,
8., 17.]])
>>> numpy.savetxt('numbers2.txt', a)
>>>
```

### Remove single dimension entry

```py
>>> a = numpy.arange(3)
>>> a
array([0, 1, 2])
>>> a.shape
(3,)
>>> b = numpy.arange(3).reshape(3,1)
>>> b
array([[0],
[1],
[2]])
>>> b.shape
(3, 1)
>>> b = numpy.squeeze(b)
>>> b
array([0, 1, 2])
>>> b.shape
(3,)
>>>
```

### Array operations

```py
>>> a = numpy.arange(9, dtype=numpy.float64)
>>> a
array([ 0.,  1.,  2.,  3.,  4.,  5.,  6.,  7.,  8.])
>>> a[3:7]
array([ 3.,  4.,  5.,  6.])
>>> a[3:7] = 0
>>> a
array([ 0.,  1.,  2.,  0.,  0.,  0.,  0.,  7.,  8.])
>>> 2*a
array([  0.,   2.,   4.,   0.,   0.,   0.,   0.,  14.,  16.])
>>> a*a
array([  0.,   1.,   4.,   0.,   0.,   0.,   0.,  49.,  64.])
>>> sum(a)
18.0
>>> min(a)
0.0
>>> max(a)
8.0
>>>
```

### Array operations

```py
>>> import math
>>> a = numpy.arange(9, dtype=numpy.float64)
>>> a
array([ 0., 1., 2., 3., 4., 5., 6., 7., 8.])
>>> # bad idea
>>> total = 0.
>>> for n in range(len(a)):
...   total += a[n]*a[n]
...
>>> math.sqrt(total)
14.2828568570857
>>> # better idea
>>> math.sqrt(numpy.dot(a,a))
14.2828568570857
>>> # best idea
>>> numpy.linalg.norm(a)
14.282856857085701
>>>
```

### Speed of array operations

`code/summation2.py`:

```py
import numpy
import time

t0 = time.time()
total = sum(numpy.ones(1000000,dtype=numpy.int32))
t1 = time.time()
print(total)
print("time = {}".format(t1-t0))
```

Output:

```
$ python3 summation2.py
1000000
time = 0.428977012634
$
```

### Speed of array operations

`code/summation3.py`:

```py
import numpy
import time

t0 = time.time()
total = numpy.sum(numpy.ones(1000000,dtype=numpy.int32))
t1 = time.time()
print(total)
print("time = {}".format(t1-t0))
```

Output:

```
$ python3 summation3.py
1000000
time = 0.00641703605652
$
```

### Loops vs. array operations

* Loops you write in Python will be executed by the interpreter

* Some of the overloaded operators (e.g. `min`, `max`, `sum`, etc.) work albeit
  slowly


* Calling NumPy function or methods of the array object will invoke high
performance implementations of these operations

### Matrix operations

```py
>>> a = numpy.arange(9, dtype=numpy.float64).reshape(3,3)
>>> a
array([[ 0.,  1.,  2.],
       [ 3.,  4.,  5.],
       [ 6.,  7.,  8.]])
>>> a.transpose()
array([[ 0.,  3.,  6.],
       [ 1.,  4.,  7.],
       [ 2.,  5.,  8.]])
>>> numpy.trace(a)
12.0
>>> a*a # element wise multiplication
array([[  0.,   1.,   4.],
       [  9.,  16.,  25.],
       [ 36.,  49.,  64.]])
>>> numpy.dot(a,a) # matrix-matrix multiplication
array([[  15.,   18.,   21.],
       [  42.,   54.,   66.],
       [  69.,   90.,  111.]])
>>>
```

### array vs matrix

* NumPy has a dedicated matrix class

* However, the matrix class is not as widely used and there are subtle
differences between a 2D array and a matrix

* It is highly recommended that you use 2D arrays for maximum compatibility with
other NumPy functions, SciPy, matplotlib, etc.

* See here for more details:

<http://www.scipy.org/NumPy_for_Matlab_Users>

(`array' or `matrix'? Which should I use?)

### References to an array

```py
>>> a = numpy.arange(9, dtype=numpy.float64).reshape(3,3)
>>> a
array([[ 0.,  1.,  2.],
       [ 3.,  4.,  5.],
       [ 6.,  7.,  8.]])
>>> b = a
>>> b[0,0] = 42
>>> b
array([[ 42.,   1.,   2.],
       [  3.,   4.,   5.],
       [  6.,   7.,   8.]])
>>> a
array([[ 42.,   1.,   2.],
       [  3.,   4.,   5.],
       [  6.,   7.,   8.]])
>>>
```

### Array slices and references

```py
>>> a = numpy.arange(9, dtype=numpy.float64)
>>> a
array([ 0.,  1.,  2.,  3.,  4.,  5.,  6.,  7.,  8.])
>>> b = a[2:7]
>>> b
array([ 2.,  3.,  4.,  5.,  6.])
>>> b[2] = -1
>>> b
array([ 2.,  3., -1.,  5.,  6.])
>>> a
array([ 0.,  1.,  2.,  3., -1.,  5.,  6.,  7.,  8.])
>>>
```

### Array copies

```py
>>> a = numpy.arange(9, dtype=numpy.float64)
>>> a
array([ 0.,  1.,  2.,  3.,  4.,  5.,  6.,  7.,  8.])
>>> b = a.copy()
>>> b
array([ 0.,  1.,  2.,  3.,  4.,  5.,  6.,  7.,  8.])
>>> b[4] = -1
>>> b
array([ 0.,  1.,  2.,  3., -1.,  5.,  6.,  7.,  8.])
>>> a
array([ 0.,  1.,  2.,  3.,  4.,  5.,  6.,  7.,  8.])
>>>
```

### Universal functions (ufuncs)

```py
>>> import numpy
>>> a = numpy.arange(9, dtype=numpy.float64)
>>> a
array([ 0.,  1.,  2.,  3.,  4.,  5.,  6.,  7.,  8.])
>>> import math
>>> math.sqrt(a)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: only length-1 arrays can be converted to Python scalars
>>> numpy.sqrt(a)
array([ 0.        ,  1.        ,  1.41421356,  1.73205081,  2.        ,
        2.23606798,  2.44948974,  2.64575131,  2.82842712])
>>>
```

### Beyond just arrays


* NumPy has some support for some useful operations beyond the usual vector and
matrix operations:

    * Searching, sorting, and counting within arrays

    * FFT (Fast Fourier Transform)

    * Linear Algebra

    * Statistics

    * Polynomials

    * Random number generation

* SciPy has largely replaced much of this functionality,
plus added much more

### Warning

* Once you start making use of extension modules such as NumPy, SciPy, etc. the
chances of code "breaking" when you run it on different machines goes up
significantly

* If you do some of your development on machines other than corn (which isn't
the model we advise) you may run into issues

### Further Reading

* MATLAB users: <http://www.scipy.org/NumPy_for_Matlab_Users>
* NumPy tutorial at: <http://www.scipy.org/Tentative_NumPy_Tutorial>
* Official docs at: <http://docs.scipy.org/>
