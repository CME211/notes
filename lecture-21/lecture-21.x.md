# CME 211: Lecture 21

Wednesday, November 11, 2015

Topics:

* Multi-dimensional data
* Boost `multi_array`

## Layout in memory for `vector`

![fig](fig/vector-memory.png)

* Memory for `std::vector` has 2 parts:

  * Memory for the vector data

  * Memory for the `std::vector` container.  This part (essentially) includes
  the memory address of the vector data, the size of the vector and capacity.

* The 2 parts may be very far apart in the memory address space.

### Look at the details

!include src/vector_memory.cpp cpp

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/vector_memory.cpp -o src/vector_memory
./src/vector_memory
./src/vector_memory
./src/vector_memory
!end

* The size of the `std::vector` container is 24 bytes, this could be for

  * 8 bytes for the memory address of the vector data

  * 8 bytes for the size of the vector, number of elements stored

  * 8 bytes of the capacity of the vector, number of elements that may be stored
  before reallocation
  
* Memory locations are different in each run of the program.  This is a security
  feature to make it harder to introduce malicious code or data.
  
## Multidimensional data

* How do we handle multidimensional data in C++?

### Container of containers

!include src/multi1.cpp cpp

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/multi1.cpp -o src/multi1
./src/multi1
!end

### Layout in memory

![fig](fig/vector-of-vectors.png)

### Contiguous memory

!include src/multi2.cpp cpp

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/multi2.cpp -o src/multi2
./src/multi2
!end

## Boost Multidimensional Array Library

!include src/array1.cpp cpp

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/array1.cpp -o src/array1
./src/array1
!end

### Accessing the contiguous memory

!include src/array2.cpp cpp

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/array2.cpp -o src/array2
./src/array2
!end

### Performance

!include src/perf1.cpp cpp

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/perf1.cpp -o src/perf1
./src/perf1
./src/perf1
./src/perf1
!end

### Performance

From `src/perf2.cpp`:

```c++
// disable boost range checking
#define BOOST_DISABLE_ASSERTS
#include <boost/multi_array.hpp>
```
!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/perf2.cpp -o src/perf2
./src/perf2
./src/perf2
./src/perf2
!end

### Compiler optimization

Enable compiler optimizations with the `-O3` argument.

With range checking:

!run
clang++ -O3 -std=c++11 -Wall -Wextra -Wconversion src/perf1.cpp -o src/perf1
./src/perf1
./src/perf1
./src/perf1
!end

Range checking disabled:

!run
clang++ -O3 -std=c++11 -Wall -Wextra -Wconversion src/perf2.cpp -o src/perf2
./src/perf2
./src/perf2
./src/perf2
!end

### Range checking

!include src/array3a.cpp cpp

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/array3a.cpp -o src/array3a
./src/array3a
!end

### Range checking

!include src/array3b.cpp cpp

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/array3b.cpp -o src/array3b
./src/array3b
clang++ -std=c++11 -g -fsanitize=address -Wall -Wextra -Wconversion src/array3b.cpp -o src/array3b
./src/array3b
!end

### Range checking

Another method to check for memory leaks is `valgrind`.

!run
clang++ -g -Wall -Wextra -Wconversion src/array3b.cpp -o src/array3b
valgrind ./src/array3b
!end

### Elementwise comparison

!include src/array5.cpp cpp

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/array5.cpp -o src/array5
./src/array5
!end

### Copy or reference?

!include src/array6a.cpp cpp

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/array6a.cpp -o src/array6a
./src/array6a
!end

### Passing an array to a function

!include src/array6b.cpp cpp

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/array6b.cpp -o src/array6b
./src/array6b
!end

### Passing by reference

From `src/array6c.cpp`:

```cpp
void increment(boost::multi_array<double, 2>& b) {
  for (unsigned int i = 0; i < 3; i++) {
    for (unsigned int j = 0; j < 3; j++) {
      b[i][j]++;
    }
  }
}
```

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/array6b.cpp -o src/array6b
./src/array6b
!end

### Array operations?

* Boost `multi_array` does not support array operations like NumPy

* If `a` is a `multi_array` things like `2*a` and `a = 1.0` will not work and
will lead to very long compiler error messages.

* If you want this kind of stuff, have a look at:

  * http://eigen.tuxfamily.org/index.php?title=Main_Page

  * http://arma.sourceforge.net/

### Array views

An **array view** is essentially a reference into a sub-array of a larger array.

!include src/array9.cpp cpp

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/array9.cpp -o src/array9
./src/array9
!end

### Storage order

!include src/array10a.cpp cpp

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/array10a.cpp -o src/array10a
./src/array10a
!end

* Uses C convention that rows are stored contiguously in memory (row major
order)

* Or put another way, the last index in a multidimensional array changes fastest
when traversing through linear memory

### "Fortran" storage order

!include src/array10b.cpp cpp

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/array10b.cpp -o src/array10b
./src/array10b
!end

* In Fortran columns are stored contiguously in memory (column major order)

* Or put another way, the first index in a multidimensional array changes
fastest when traversing through linear memory

### MultiArrays are containers

From `src/accumulate.cpp`:

```cpp
  for (unsigned int i = 0; i < nrows; i++) {
    sum += std::accumulate(a[i].begin(), a[i].end(), 0.);
  }
```

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/accumulate.cpp -o src/accumulate
./src/accumulate
!end

### Boost summary

From <http://www.boost.org>:

Boost provides free peer-reviewed portable C++ source libraries.

We emphasize libraries that work well with the C++ Standard Library. Boost
libraries are intended to be widely useful, and usable across a broad spectrum
of applications. The Boost license encourages both commercial and non-commercial
use.

**Good**:

* Well implemented library with a lot of diverse functionality.

* Approximately 115 sub-libraries, of which MultiArray is just
one of them.

* Cross platform (Windows, Mac, Linux) and friendly license for
commercial applications.

**Bad**:

* Sometimes the documentation can be a bit lacking.

* Not a standard part of C++ (external dependency).

* Some people seem to have a real aversion to it.

* Sometimes the `boost` library authors make an effort to utilize C++ features
  at the expense of code clarity.  I believe this is why some people have strong
  feelings against `boost`.

**Practical advice**:

* Use boost if it helps you get your work done quickly.

* If you find yourself trying too hard to fit into a particular boost library,
then maybe look for something else.

* It is sometimes nice to have single external dependency that contains many useful
  utilities as opposed to many smaller external dependencies.
