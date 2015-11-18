# CME 211: Lecture 24

Wednesday, November 18, 2015

Topic: C++ Object Oriented Programming, Part Duex

## Example 1: name algorithm

!include ../lecture-09/code/names.py py

!include ../lecture-09/code/main.py py

Output:

```
$ python main.py 
PETER: 1.0
LOIS: 1.0
STEWIE: 0.5
BRIAN: 1.0
MEG: 1.0
CHRIS: 1.0
$
```

### Top level

!include name/main.cpp c++

### Interface

!include name/names.hpp c++

### Implementaion

!include name/names.cpp c++

### Putting it together

!run
make -C name clean
make -C name main
./name/main name/dist.female.first name/dist.male.first
!end

## Example 2: user similarity

* Homework 2

* Uses MovieLens dataset

* Computes user similarities based on Pearson Correlation Coefficient (PCC)

### Python performance

On my workstation.

```
$ python similarity.py u.data sim_cpy.txt
Input MovieLens file: u.data 
Output file for similarity data: sim_cpy.txt
Minimum number of common users: 5
Read 100000 lines with total of 1682 movies and 943 users
Computed similarities in 39.075 seconds
```

### C++ implementation

* Uses same algorithm and data structures

* Only difference is high level versus low level language

* Let's review the implementation...

### C++ performance

```
$ g++ -std=c++11 -O3 -Wall -Wextra -Wconversion similarity.cpp -o similarity
./similarity u.data sim_cpp.txt
Input MovieLens file: u.data
Output file for similarity data: sim_cpp.txt
Minimum number of common users: 5
Read 100000 lines with total of 1682 movies and 943 users
Computed similarities in 4.83 seconds
```

### Easier options?

There are alternatives to pure Python or pure C++:

* PyPy: Implementation of Python that uses Just-in-Time compilation to improve
performance (see: <http://pypy.org/>).

* Numba: Uses annotations in Python code to speed up your application using
compilation (see: <http://numba.pydata.org/>).  This seems to work best on
operations with NumPy arrays.

* Cython: Extends Python with C like constructs to create compiled extensions
  (see: <http://cython.org/>).

We will look at PyPy.

**Warnings**:

* Not all of these options support code that uses NumPy

* Also, they tend to be more experimental so you will need to retest if your
code works properly

### PyPy performance

```
$ pypy similarity.py u.data sim_pypy.txt
Input MovieLens file: u.data 
Output file for similarity data: sim_pypy.txt
Minimum number of common users: 5
Read 100000 lines with total of 1682 movies and 943 users
Computed similarities in 19.097 seconds
```

### Performance summary

* CPython: 39.1 seconds

* PyPy: 19.1 seconds

* C++: 4.83 seconds (with `-O3`)

(On Nick's workstation)
