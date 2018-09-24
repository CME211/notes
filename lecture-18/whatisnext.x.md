# CME 211: Lecture 18

Topic:

* Programming in C
* What's next?

## The C Programming Language

### Why learn C?

* Mainly a subset of C++

* C is a low level language that has few abstractions over the hardware, so you
get a better feel for how the hardware actually works

* Even within C++ programs, the most computationally intense parts should be
very C like for efficiency

* In use for many applications: Linux kernel, CPython interpreter, low
power or embedded systems, etc.

### Where to learn?

**21st Century C, Second Edition** by Ben Klemens is a good place to start.

See: <http://proquest.safaribooksonline.com/book/programming/c/9781491904428>

### C/C++ differences

C does not have:

* Support for Object Oriented Programming

* The C++ standard library

* Pass by reference or reference variables

* bool data type

* `new` / `delete` keywords replaced with `malloc` / `free` library functions

* `and` / `or` / `not` replaced with `&&` / `||` / `!` 

### Hello world

!include src/hello.c c

!run
gcc src/hello.c -o src/hello
./src/hello
!end

### `printf()`

!include src/printf1.c c

!run
gcc -Wall -Wextra -Wconversion src/printf1.c -o src/printf1
./src/printf1
!end

### Common mistake

!include src/printf2.c c

!run
gcc -Wall -Wextra -Wconversion src/printf2.c -o src/printf2
./src/printf2
!end

### `for` loop, example 1

!include src/forloop1.c c

!run
gcc -Wall -Wextra -Wconversion src/forloop1.c -o src/forloop1
./src/forloop1
!end

### `for` loop, example 2

!include src/forloop2.c c

!run
gcc -std=c89 -Wall -Wextra -Wconversion src/forloop2.c -o src/forloop2
gcc -std=c99 -Wall -Wextra -Wconversion src/forloop2.c -o src/forloop2
./src/forloop2
!end

Note: By default, on recent versions of Max OS X `gcc` is a wrapper around
`clang`.  `clang` seems more lenient with this issue when compiling with
`-std=c89`.  I installed `gcc-5` on my Mac and now get the expected behavior.

### `gcc` standards support

* See `$ man gcc`

* See <http://gcc.gnu.org/c99status.html>

### C89 vs C99

* In C89 you must declare all of your variables at the beginning of a scope
block

* In C99 you can declare your variables anywhere (just like C++)

* In 2014, the Microsoft C compiler only supports C89

### Writing to a file

!include src/filewrite.c c

!run
gcc -std=c99 -Wall -Wextra -Wconversion src/filewrite.c -o src/filewrite
./src/filewrite
cat hello.txt
!end

### C math library

!include src/math.c c

!run
gcc -std=c99 -Wall -Wextra -Wconversion src/math.c -o src/math
./src/math
!end

### Functions

!include src/sum1.c c

!run
gcc -std=c99 -Wall -Wextra -Wconversion src/sum1.c -o src/sum1
./src/sum1
!end

### Functions

!include src/sum2.c c

!run
gcc -std=c99 -Wall -Wextra -Wconversion src/sum2.c -o src/sum2
./src/sum2
g++ -std=c99 -Wall -Wextra -Wconversion src/sum2.c -o src/sum2
!end

### Functions

!include src/sum3.c c

!run
gcc -std=c99 -Wall -Wextra -Wconversion src/sum3.c -o src/sum3
!end

### Type assumptions

C assumes unspecified types are integers

```c
sum(a, b) {
  return a+b;
}
```

Here `a`, `b`, and the return type are all `int`.

## Memory management

* `malloc()` allocates heap memory and returns
a `void` pointer to the start of the allocation

* No guarantees about the state of initialization
(i.e. the memory will have "random" data in it)

* `calloc()` works similar to `malloc()`
except it initializes the memory to zero

* `free()` frees the memory allocated by
`malloc()` or `calloc()`

### Memory management

!include src/malloc.c c

!run
gcc -std=c99 -Wall -Wextra -Wconversion src/malloc.c -o src/malloc
./src/malloc
!end

### Command line arguments

!include src/argv.c c

!run
gcc -std=c99 -Wall -Wextra -Wconversion src/argv.c -o src/argv
./src/argv file.txt 4 3.7
!end

## Strings

* Strings in C are arrays of characters

* A null character, `\0`, denotes the end of the string (but not necessarily the
end of the array)

```c
char name[] = "Leland";
```

![fig](fig/char-array.png)

### `char` array

!include src/strings1.c c

!run
gcc -std=c99 -Wall -Wextra -Wconversion src/strings1.c -o src/strings1
./src/strings1
!end

### Copying strings

!include src/strings2.c c

!run
gcc -std=c99 -Wall -Wextra -Wconversion src/strings2.c -o src/strings2
!end

### Copying strings

!include src/strings3.c c

!run
gcc -std=c99 -Wall -Wextra -Wconversion src/strings3.c -o src/strings3
!end

Things to keep in mind:

* string copying in C can lead to several problems

* the function `strcpy` will keep copying until it hits the null character
  (`\0`).  If there is no null character in the array, then the function may run
  on with out end, reading from and writing to parts of memory that it is not
  supposed to.

* C11 (the 2011 standard) introduces `strcpy_s`, which takes in a max size.

### `fscanf()`

* For reading from files use the `fscanf()` function which is analogous to
`fprintf()`

* `fscanf()` takes format specifiers for converting to the proper data type

```
float a;
...
fscanf(f, "%f\n", &a);
```

### Reading numbers

!include src/strings3.c c

!run
gcc -std=c99 -Wall -Wextra -Wconversion src/strings3.c -o src/strings3
!end

### Reading numbers

!include src/fileread.c c

!run
gcc -std=c99 -Wall -Wextra -Wconversion src/fileread.c -o src/fileread
cat src/numbers.txt
./src/fileread
!end

## Pointers

If you use a Mac:

* Try Homebrew <http://brew.sh/> to install software that does not come built
  in.

* Some people like MacPorts <https://www.macports.org/>, which does essentially
the same thing.  Seems like more people are using Homebrew these days.

If you use Windows:

* <https://cygwin.com/>: GNU and other tools to provide linux like
functionality.

* <http://www.mingw.org/>: minimal gnu compiler toolchain for windows

For any operating system:

* Virtual machines (VirtualBox, VMware, Parallels) allow you to run another
operating system concurrently.

* Vagrant <https://www.vagrantup.com/> is a tool to create and configure
  lightweight, reproducible, and portable development environments.  Uses
  VirtualBox under the hood.

Advice: Build software that works on Linux.  If you are stuck on Windows or Mac,
use the above tools to develop for Linux.  As a result, you can run your code
anywhere (personal computer, amazon cloud, your buddy's computer) without
hardware or software licensing restrictions.

## Where do you go from here?

* CME 212 - Advanced Programming for Scientists and Engineers

* CME 213 - Introduction to Parallel Computing using MPI, OpenMP, and CUDA

* CME 214 - Software Design in Modern Fortran for Scientists and Engineers

* CME 342 - Parallel Methods in Numerical Analysis

### Course evaluations

* Please fill out the course evaluation in Axess

* I really do read them and make changes based on the feedback

* Evaluations due by December 15 at 8 am

* Can see your course grade as soon as they are
entered, versus waiting until December 19
