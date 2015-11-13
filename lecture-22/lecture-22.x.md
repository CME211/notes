# CME 211: Lecture 22

Friday, November 13, 2015

Topics:

* Compilation process
* Make for building software

## Compilation

* Although you can go from source code to an executable in one command, the
process is actually made up of 4 steps

  * Preprocessing
  
  * Compilation
  
  * Assembly
  
  * Linking

* `g++` and `clang++` (and `gcc` or `clang` for C code) are driver programs that
invoke the appropriate tools to perform these steps

* This is a high level overview.  The compilation process also includes
  optimization phases during compilation and linking.

### Behind the scenes

We can inspect the compilation process in more detail with the `-v` compiler
argument.  `-v` typically stands for "verbose".

!run
g++ -v -Wall -Wextra -Wconversion src/hello1.cpp -o src/hello1
!end

### Splitting up the steps manually

GNU compiler flags:

* `-E`: preprocess
* `-S`: compile
* `-c`: assemble

!run
cat src/hello1.cpp
g++ -E -o src/hello1.i src/hello1.cpp 
g++ -S -o src/hello1.s src/hello1.i
g++ -c -o src/hello1.o src/hello1.s
g++ -o src/hello1 src/hello1.o
./src/hello1
!end

### Preprocessing

* The preprocessor handles the lines that start with `#`

  * `#include`
  * `#define`
  * `#if`
  * etc.

* You can invoke the preprocessor with the `cpp` command

### Preprocessed file

From `src/hello1.i`:

```
# 1 "hello1.cpp"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 30 "/usr/include/stdc-predef.h" 3 4
# 1 "/usr/include/x86_64-linux-gnu/bits/predefs.h" 1 3 4
# 31 "/usr/include/stdc-predef.h" 2 3 4
# 1 "<command-line>" 2
# 1 "hello1.cpp"
# 1 "/usr/include/c++/4.8/iostream" 1 3
# 36 "/usr/include/c++/4.8/iostream" 3

...

int main()
{
std::cout << "Hello" << std::endl;
return 0;
}
```

Approximately 17,500 lines omitted!

### Compilation

* Compilation is the process of translating source code to assembly commands

* The assembly commands are still human readable text (if the human knows
assembly)

From `src/hello.s`:

```
main:
.LFB1020:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	movl	$.LC0, %esi
	movl	$_ZSt4cout, %edi
	call	_ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
	movl	$_ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_, %esi
	movq	%rax, %rdi
	call	_ZNSolsEPFRSoS_E
	movl	$0, %eax
	popq	%rbp
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
```

### Assembly

* This step translates the text representation of the assembly instructions into
the binary machine code in a `.o` file

* `.o` files are called object files

* Linux uses the Executable and Linkable Format (ELF) for these files

* If you try to look at these files with a normal text editor you will just see
garbage, intermixed with a few strings

* Sometimes it is helpful to inspect object files with the `nm` command to see
  what symbols are defined:

!run
nm ./src/hello1.o
!end

### Linking

* Linking is the process of building the final executable by combining (linking)
the `.o` file(s), and possibly library files as well

* The linker makes sure all of the required functions are present

* If for example `foo.o` contains a call to a function called `bar()`, there has
to be another `.o` file or library file that provides the implementation of the
`bar()` function

### Linking example

!include src/foobar.hpp c++

!include src/foo.cpp c++

!include src/bar.cpp c++

!include src/main.cpp c++

### Linking example

Inspect the files:

!run
ls src
!end

Compile and assemble source files, but don't link:

!run
g++ -c src/foo.cpp -o src/foo.o
g++ -c src/bar.cpp -o src/bar.o
g++ -c src/main.cpp -o src/main.o
!end

Let's inspect the output:

!run
ls src/*.o
!end

What symbols are present in the object files?

!run
nm src/foo.o
nm src/bar.o
nm src/main.o
!end

What happens if we try to link `main.o` into an executable with out pointing to
the other object files?

!run
g++ src/main.o -o src/main
!end

Ahhh, linker errors!  Let's do it right:

!run
g++ src/main.o src/foo.o src/bar.o -o src/main
./src/main
!end

### Libraries

* Libraries are really just a file that contain one or more `.o` files

* On Linux these files typically have a `.a` (static library) or `.so` (dynamic
library) extension

* `.so` files are analogous to `.dll` files on Windows

* `.dylib` files on Mac OS X and iOS are also very similar to `.so` files

* Static libraries are factored into the executable at link time in the
compilation process.

* Shared (dynamic) libraries are loaded up at run time.

### JPEG Example

From `src/hw6.cpp`:

```c++
...

#include <jpeglib.h>

#include "hw6.hpp"


void ReadGrayscaleJPEG(std::string filename, boost::multi_array<unsigned char,2> &img)
{
  /* Open the file, read the header, and allocate memory */

  FILE *f = fopen(filename.c_str(), "rb");
  if (not f)
  {
    std::stringstream s;
    s << __func__ << ": Failed to open file " << filename;
    throw std::runtime_error(s.str());
  }
  ...
} 

...

#ifdef DEBUG
int main()
{
  boost::multi_array<unsigned char,2> img;
  ReadGrayscaleJPEG("stanford.jpg", img);
  WriteGrayscaleJPEG("test.jpg", img);

  return 0;
}
#endif /* DEBUG */
```

Let's try to compile:

!run
g++ -std=c++11 -Wall -Wextra -Wconversion src/hw6.cpp -o src/hw6
!end

That did not work.  The linker looks for the `main` symbol when trying to build
and executable.  This linker also cannot find all of the symbols from the JPEG
library.

Let's find the `jpeglib.h` header file:

!run
ls -l /usr/include/jpeglib.h 
!end

Let's find `libjpeg`:

!run
ls -l /usr/lib/libjpeg.*
ls -l /usr/lib64/libjpeg.*
!end

Note that the library files may be in a different location on your system.

Now let's compile:

!run
g++ -std=c++11 -Wall -Wextra -Wconversion src/hw6.cpp -o src/hw6 -DDEBUG -I/usr/include -L/usr/lib64 -ljpeg
./src/hw6
!end

* `-I/usr/include`: look in this directory for include files (optional in this case)
* `-L/usr/lib64`: look in this directory for library files (optional in this case)
* `-ljpeg`: link to the `libjpeg.{a,so}` file (not optional here)

## Make

* Utility that compiles programs based on rules read in from a file called
Makefile

* Widely used on Linux/Unix platforms

* Setup and maintenance of Makefile(s) can become rather complicated for major
projects

* We will look at a few simple examples

### Example source files

!include src/ex1/sum.cpp c++

!include src/ex1/sum.hpp c++

!include src/ex1/main.cpp c++

### Example `makefile`

!include src/ex1/makefile makefile

Anatomy of a `make` rule:

```
target: dependencies
    build_command
```

* `target`: is the thing you want the rule to create.  The target should be a
  file that will be created in the file system.  For example, the final
  executable or intermediate object file.

* `dependencies`: space separated list files that the target depends on
  (typically source or header files)

* `build_command`: a **tab-indented** shell command (or sequence) to build the
  target from dependencies.

### Let's run the example

Let's run make!

```
[nwh@icme-nwh ex1] $ ls
main.cpp  makefile  sum.cpp  sum.hpp
[nwh@icme-nwh ex1] $ make
g++ -Wall -Wextra -Wconversion -o main main.cpp sum.cpp
[nwh@icme-nwh ex1] $ ls
main  main.cpp	makefile  sum.cpp  sum.hpp
[nwh@icme-nwh ex1] $ make
make: 'main' is up to date.
[nwh@icme-nwh ex1] $
```

### File changes

* Make looks at time stamps on files to know when changes have been made and
will recompile accordingly

```
[nwh@icme-nwh ex1] $ make
make: 'main' is up to date.
[nwh@icme-nwh ex1] $ touch main.cpp
[nwh@icme-nwh ex1] $ make
g++ -Wall -Wextra -Wconversion -o main main.cpp sum.cpp
[nwh@icme-nwh ex1] $ touch sum.hpp
[nwh@icme-nwh ex1] $ make
g++ -Wall -Wextra -Wconversion -o main main.cpp sum.cpp
[nwh@icme-nwh ex1] $ make
make: 'main' is up to date.
[nwh@icme-nwh ex1] $
```

### Make variables, multiple targets, and comments

!include src/ex2/makefile makefile

Output:

```
[nwh@icme-nwh ex2] $ ls
main.cpp  makefile  sum.cpp  sum.hpp
[nwh@icme-nwh ex2] $ make
g++ -Wall -Wextra -Wconversion -fsanitize=address -o main main.cpp sum.cpp
[nwh@icme-nwh ex2] $ ls
main  main.cpp	makefile  sum.cpp  sum.hpp
[nwh@icme-nwh ex2] $ make clean
rm -f main
[nwh@icme-nwh ex2] $ ls
main.cpp  makefile  sum.cpp  sum.hpp
[nwh@icme-nwh ex2] $ 
```

### Individual compilation of object files

!include src/ex3/makefile makefile

Output:

```
[nwh@icme-nwh ex3] $ ls
bar.cpp  foobar.hpp  foo.cpp  main.cpp	makefile  sum.cpp  sum.hpp
[nwh@icme-nwh ex3] $ make
g++ -c -o main.o main.cpp -O3 -Wall -Wextra -Wconversion -std=c++11
g++ -c -o sum.o sum.cpp -O3 -Wall -Wextra -Wconversion -std=c++11
g++ -c -o foo.o foo.cpp -O3 -Wall -Wextra -Wconversion -std=c++11
g++ -c -o bar.o bar.cpp -O3 -Wall -Wextra -Wconversion -std=c++11
g++ -o main main.o sum.o foo.o bar.o
[nwh@icme-nwh ex3] $ ls
bar.cpp  bar.o	foobar.hpp  foo.cpp  foo.o  main  main.cpp  main.o  makefile  sum.cpp  sum.hpp	sum.o
[nwh@icme-nwh ex3] $ make clean
rm -f main.o sum.o foo.o bar.o main
[nwh@icme-nwh ex3] $ ls
bar.cpp  foobar.hpp  foo.cpp  main.cpp	makefile  sum.cpp  sum.hpp
[nwh@icme-nwh ex3] $
```

### Linking to a library & `run` targets

!include src/ex4/makefile makefile

Output:

```
[nwh@icme-nwh ex4] $ ls
hw6.cpp  hw6.hpp  makefile  stanford.jpg
[nwh@icme-nwh ex4] $ make
g++ -c -o hw6.o hw6.cpp -DDEBUG -O3 -std=c++11 -Wall -Wextra -Wconversion
g++ -o hw6 hw6.o -ljpeg
[nwh@icme-nwh ex4] $ ./hw6 
[nwh@icme-nwh ex4] $ make clean
rm -f hw6.o hw6 *~
[nwh@icme-nwh ex4] $ make run
g++ -c -o hw6.o hw6.cpp -DDEBUG -O3 -std=c++11 -Wall -Wextra -Wconversion
g++ -o hw6 hw6.o -ljpeg
./hw6
[nwh@icme-nwh ex4] $ ls
hw6  hw6.cpp  hw6.hpp  hw6.o  makefile	stanford.jpg  test.jpg
```

### Make

* Automation tool for expressing how your C/C++/Fortran code should be compiled

* Good for small projects

* But be careful with dependencies.  It is **very** important to understand this
  process for larger projects.

* Some people would not recommend hand writing Makefile(s) for larger projects
(use CMake or similar)

* With discipline, I believe that Make is a good tool for large projects.  This
  is what I use.  Sometimes CMake and other tools make it harder to build
  projects.
