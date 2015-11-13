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

Output:

```
$ g++ -v -Wall -Wextra -Wconversion src/hello1.cpp -o src/hello1
Using built-in specs.
COLLECT_GCC=/usr/bin/g++
COLLECT_LTO_WRAPPER=/usr/libexec/gcc/x86_64-redhat-linux/4.9.2/lto-wrapper
Target: x86_64-redhat-linux
Configured with: ../configure --prefix=/usr --mandir=/usr/share/man --infodir=/usr/share/info --with-bugurl=http://bugzilla.redhat.com/bugzilla --enable-bootstrap --enable-shared --enable-threads=posix --enable-checking=release --enable-multilib --with-system-zlib --enable-__cxa_atexit --disable-libunwind-exceptions --enable-gnu-unique-object --enable-linker-build-id --with-linker-hash-style=gnu --enable-languages=c,c++,objc,obj-c++,fortran,ada,go,lto --enable-plugin --enable-initfini-array --disable-libgcj --with-isl=/builddir/build/BUILD/gcc-4.9.2-20150212/obj-x86_64-redhat-linux/isl-install --with-cloog=/builddir/build/BUILD/gcc-4.9.2-20150212/obj-x86_64-redhat-linux/cloog-install --enable-gnu-indirect-function --with-tune=generic --with-arch_32=i686 --build=x86_64-redhat-linux
Thread model: posix
gcc version 4.9.2 20150212 (Red Hat 4.9.2-6) (GCC) 
COLLECT_GCC_OPTIONS='-v' '-Wall' '-Wextra' '-Wconversion' '-o' 'src/hello1' '-shared-libgcc' '-mtune=generic' '-march=x86-64'
 /usr/libexec/gcc/x86_64-redhat-linux/4.9.2/cc1plus -quiet -v -D_GNU_SOURCE src/hello1.cpp -quiet -dumpbase hello1.cpp -mtune=generic -march=x86-64 -auxbase hello1 -Wall -Wextra -Wconversion -version -o /tmp/ccgejI6U.s
GNU C++ (GCC) version 4.9.2 20150212 (Red Hat 4.9.2-6) (x86_64-redhat-linux)
	compiled by GNU C version 4.9.2 20150212 (Red Hat 4.9.2-6), GMP version 6.0.0, MPFR version 3.1.2, MPC version 1.0.2
GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
ignoring nonexistent directory "/usr/lib/gcc/x86_64-redhat-linux/4.9.2/include-fixed"
ignoring nonexistent directory "/usr/lib/gcc/x86_64-redhat-linux/4.9.2/../../../../x86_64-redhat-linux/include"
#include "..." search starts here:
#include <...> search starts here:
 /usr/lib/gcc/x86_64-redhat-linux/4.9.2/../../../../include/c++/4.9.2
 /usr/lib/gcc/x86_64-redhat-linux/4.9.2/../../../../include/c++/4.9.2/x86_64-redhat-linux
 /usr/lib/gcc/x86_64-redhat-linux/4.9.2/../../../../include/c++/4.9.2/backward
 /usr/lib/gcc/x86_64-redhat-linux/4.9.2/include
 /usr/local/include
 /usr/include
End of search list.
GNU C++ (GCC) version 4.9.2 20150212 (Red Hat 4.9.2-6) (x86_64-redhat-linux)
	compiled by GNU C version 4.9.2 20150212 (Red Hat 4.9.2-6), GMP version 6.0.0, MPFR version 3.1.2, MPC version 1.0.2
GGC heuristics: --param ggc-min-expand=100 --param ggc-min-heapsize=131072
Compiler executable checksum: 954ba53e83b294b646fa1b6b73a69682
COLLECT_GCC_OPTIONS='-v' '-Wall' '-Wextra' '-Wconversion' '-o' 'src/hello1' '-shared-libgcc' '-mtune=generic' '-march=x86-64'
 as -v --64 -o /tmp/ccHWfZ3W.o /tmp/ccgejI6U.s
GNU assembler version 2.24 (x86_64-redhat-linux) using BFD version version 2.24
COMPILER_PATH=/usr/libexec/gcc/x86_64-redhat-linux/4.9.2/:/usr/libexec/gcc/x86_64-redhat-linux/4.9.2/:/usr/libexec/gcc/x86_64-redhat-linux/:/usr/lib/gcc/x86_64-redhat-linux/4.9.2/:/usr/lib/gcc/x86_64-redhat-linux/
LIBRARY_PATH=/usr/lib/gcc/x86_64-redhat-linux/4.9.2/:/usr/lib/gcc/x86_64-redhat-linux/4.9.2/../../../../lib64/:/lib/../lib64/:/usr/lib/../lib64/:/usr/lib/gcc/x86_64-redhat-linux/4.9.2/../../../:/lib/:/usr/lib/
COLLECT_GCC_OPTIONS='-v' '-Wall' '-Wextra' '-Wconversion' '-o' 'src/hello1' '-shared-libgcc' '-mtune=generic' '-march=x86-64'
 /usr/libexec/gcc/x86_64-redhat-linux/4.9.2/collect2 -plugin /usr/libexec/gcc/x86_64-redhat-linux/4.9.2/liblto_plugin.so -plugin-opt=/usr/libexec/gcc/x86_64-redhat-linux/4.9.2/lto-wrapper -plugin-opt=-fresolution=/tmp/ccK49X1Y.res -plugin-opt=-pass-through=-lgcc_s -plugin-opt=-pass-through=-lgcc -plugin-opt=-pass-through=-lc -plugin-opt=-pass-through=-lgcc_s -plugin-opt=-pass-through=-lgcc --build-id --no-add-needed --eh-frame-hdr --hash-style=gnu -m elf_x86_64 -dynamic-linker /lib64/ld-linux-x86-64.so.2 -o src/hello1 /usr/lib/gcc/x86_64-redhat-linux/4.9.2/../../../../lib64/crt1.o /usr/lib/gcc/x86_64-redhat-linux/4.9.2/../../../../lib64/crti.o /usr/lib/gcc/x86_64-redhat-linux/4.9.2/crtbegin.o -L/usr/lib/gcc/x86_64-redhat-linux/4.9.2 -L/usr/lib/gcc/x86_64-redhat-linux/4.9.2/../../../../lib64 -L/lib/../lib64 -L/usr/lib/../lib64 -L/usr/lib/gcc/x86_64-redhat-linux/4.9.2/../../.. /tmp/ccHWfZ3W.o -lstdc++ -lm -lgcc_s -lgcc -lc -lgcc_s -lgcc /usr/lib/gcc/x86_64-redhat-linux/4.9.2/crtend.o /usr/lib/gcc/x86_64-redhat-linux/4.9.2/../../../../lib64/crtn.o
```

### Splitting up the steps manually

GNU compiler flags:

* `-E`: preprocess
* `-S`: compile
* `-c`: assemble

Output:

```
$ cat src/hello1.cpp
#include <iostream>

int main() {
  std::cout << "Hello, CME 211!" << std::endl;
  return 0;
}
$ g++ -E -o src/hello1.i src/hello1.cpp 
$ g++ -S -o src/hello1.s src/hello1.i
$ g++ -c -o src/hello1.o src/hello1.s
$ g++ -o src/hello1 src/hello1.o
$ ./src/hello1
Hello, CME 211!
```

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

Output:

```
$ nm ./src/hello1.o
                 U __cxa_atexit
                 U __dso_handle
0000000000000064 t _GLOBAL__sub_I_main
0000000000000000 T main
0000000000000027 t _Z41__static_initialization_and_destruction_0ii
                 U _ZNSolsEPFRSoS_E
                 U _ZNSt8ios_base4InitC1Ev
                 U _ZNSt8ios_base4InitD1Ev
                 U _ZSt4cout
                 U _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
0000000000000000 b _ZStL8__ioinit
                 U _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
```

### Linking

* Linking is the process of building the final executable by combining (linking)
the `.o` file(s), and possibly library files as well

* The linker makes sure all of the required functions are present

* If for example `foo.o` contains a call to a function called `bar()`, there has
to be another `.o` file or library file that provides the implementation of the
`bar()` function

### Linking example

`src/foobar.hpp`:

```c++
#pragma once

void bar(void);
void foo(void);
```

`src/foo.cpp`:

```c++
#include <iostream>

void foo(void) {
  std::cout << "Hello from foo" << std::endl;
}
```

`src/bar.cpp`:

```c++
#include <iostream>

void bar(void) {
  std::cout << "Hello from bar" << std::endl;
}
```

`src/main.cpp`:

```c++
#include "foobar.hpp"

int main() {
  foo();
  bar();
  return 0;
}
```

### Linking example

Inspect the files:

Output:

```
$ ls src
bar.cpp
bar.o
ex1
ex2
ex3
ex4
foobar.hpp
foo.cpp
foo.o
hello1
hello1.cpp
hello1.i
hello1.o
hello1.s
hw6
hw6.cpp
hw6.hpp
main
main.cpp
main.o
stanford.jpg
test.jpg
```

Compile and assemble source files, but don't link:

Output:

```
$ g++ -c src/foo.cpp -o src/foo.o
$ g++ -c src/bar.cpp -o src/bar.o
$ g++ -c src/main.cpp -o src/main.o
```

Let's inspect the output:

Output:

```
$ ls src/*.o
ls: cannot access src/*.o: No such file or directory
```

What symbols are present in the object files?

Output:

```
$ nm src/foo.o
                 U __cxa_atexit
                 U __dso_handle
000000000000005f t _GLOBAL__sub_I__Z3foov
0000000000000000 T _Z3foov
0000000000000022 t _Z41__static_initialization_and_destruction_0ii
                 U _ZNSolsEPFRSoS_E
                 U _ZNSt8ios_base4InitC1Ev
                 U _ZNSt8ios_base4InitD1Ev
                 U _ZSt4cout
                 U _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
0000000000000000 b _ZStL8__ioinit
                 U _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
$ nm src/bar.o
                 U __cxa_atexit
                 U __dso_handle
000000000000005f t _GLOBAL__sub_I__Z3barv
0000000000000000 T _Z3barv
0000000000000022 t _Z41__static_initialization_and_destruction_0ii
                 U _ZNSolsEPFRSoS_E
                 U _ZNSt8ios_base4InitC1Ev
                 U _ZNSt8ios_base4InitD1Ev
                 U _ZSt4cout
                 U _ZSt4endlIcSt11char_traitsIcEERSt13basic_ostreamIT_T0_ES6_
0000000000000000 b _ZStL8__ioinit
                 U _ZStlsISt11char_traitsIcEERSt13basic_ostreamIcT_ES5_PKc
$ nm src/main.o
0000000000000000 T main
                 U _Z3barv
                 U _Z3foov
```

What happens if we try to link `main.o` into an executable with out pointing to
the other object files?

Output:

```
$ g++ src/main.o -o src/main
src/main.o: In function `main':
main.cpp:(.text+0x5): undefined reference to `foo()'
main.cpp:(.text+0xa): undefined reference to `bar()'
collect2: error: ld returned 1 exit status
```

Ahhh, linker errors!  Let's do it right:

Output:

```
$ g++ src/main.o src/foo.o src/bar.o -o src/main
$ ./src/main
Hello from foo
Hello from bar
```

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

Output:

```
$ g++ -std=c++11 -Wall -Wextra -Wconversion src/hw6.cpp -o src/hw6
/usr/lib/gcc/x86_64-redhat-linux/4.9.2/../../../../lib64/crt1.o: In function `_start':
(.text+0x20): undefined reference to `main'
/tmp/ccoFK0Eq.o: In function `ReadGrayscaleJPEG(std::string, boost::multi_array<unsigned char, 2ul, std::allocator<unsigned char> >&)':
hw6.cpp:(.text+0xfe): undefined reference to `jpeg_std_error'
hw6.cpp:(.text+0x11e): undefined reference to `jpeg_CreateDecompress'
hw6.cpp:(.text+0x134): undefined reference to `jpeg_stdio_src'
hw6.cpp:(.text+0x148): undefined reference to `jpeg_read_header'
hw6.cpp:(.text+0x281): undefined reference to `jpeg_start_decompress'
hw6.cpp:(.text+0x2c9): undefined reference to `jpeg_read_scanlines'
hw6.cpp:(.text+0x32e): undefined reference to `jpeg_finish_decompress'
hw6.cpp:(.text+0x33d): undefined reference to `jpeg_destroy_decompress'
/tmp/ccoFK0Eq.o: In function `WriteGrayscaleJPEG(std::string, boost::multi_array<unsigned char, 2ul, std::allocator<unsigned char> >&)':
hw6.cpp:(.text+0x4e4): undefined reference to `jpeg_std_error'
hw6.cpp:(.text+0x504): undefined reference to `jpeg_CreateCompress'
hw6.cpp:(.text+0x51a): undefined reference to `jpeg_stdio_dest'
hw6.cpp:(.text+0x56e): undefined reference to `jpeg_set_defaults'
hw6.cpp:(.text+0x587): undefined reference to `jpeg_set_quality'
hw6.cpp:(.text+0x59b): undefined reference to `jpeg_start_compress'
hw6.cpp:(.text+0x5e7): undefined reference to `jpeg_write_scanlines'
hw6.cpp:(.text+0x606): undefined reference to `jpeg_finish_compress'
collect2: error: ld returned 1 exit status
```

That did not work.  The linker looks for the `main` symbol when trying to build
and executable.  This linker also cannot find all of the symbols from the JPEG
library.

Let's find the `jpeglib.h` header file:

Output:

```
$ ls -l /usr/include/jpeglib.h 
-rw-r--r--. 1 root root 50298 Feb 24  2015 /usr/include/jpeglib.h
```

Let's find `libjpeg`:

Output:

```
$ ls -l /usr/lib/libjpeg.*
ls: cannot access /usr/lib/libjpeg.*: No such file or directory
$ ls -l /usr/lib64/libjpeg.*
ls: cannot access /usr/lib64/libjpeg.*: No such file or directory
```

Note that the library files may be in a different location on your system.

Now let's compile:

Output:

```
$ g++ -std=c++11 -Wall -Wextra -Wconversion src/hw6.cpp -o src/hw6 -DDEBUG -I/usr/include -L/usr/lib64 -ljpeg
$ ./src/hw6
```

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

`src/ex1/sum.cpp`:

```c++
#include "sum.hpp"

double sum(double a, double b) {
  double c = a + b;
  return c;
}
```

`src/ex1/sum.hpp`:

```c++
#pragma once

double sum(double a, double b);
```

`src/ex1/main.cpp`:

```c++
#include <iostream>

#include "sum.hpp"

int main() {
  double a = 2., b = 3., c;

  c = sum(a,b);
  std::cout << "c = " << c << std::endl;

  return 0;
}
```

### Example `makefile`

`src/ex1/makefile`:

```makefile
main: main.cpp sum.cpp sum.hpp
	g++ -Wall -Wextra -Wconversion -o main main.cpp sum.cpp
```

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

`src/ex2/makefile`:

```makefile
# this is a makefile variable, note := for direct assignment
CXX := g++

# this is a makefile comment
#CXXFLAGS := -Wall -Wextra -Wconversion
#CXXFLAGS := -Wall -Wextra -Wconversion -g Commented out
CXXFLAGS := -Wall -Wextra -Wconversion -fsanitize=address

main: main.cpp sum.cpp sum.hpp
	$(CXX) $(CXXFLAGS) -o main main.cpp sum.cpp

# here is a target to clean up the output of the build process
.PHONY: clean
clean:
	$(RM) main
```

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

`src/ex3/makefile`:

```makefile
CXX := g++
CXXFLAGS := -O3 -Wall -Wextra -Wconversion -std=c++11

TARGET := main
OBJS := main.o sum.o foo.o bar.o
INCS := sum.hpp foobar.hpp

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS)

# this is a make pattern rule
%.o: %.cpp $(INCS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY: clean
clean:
	$(RM) $(OBJS) $(TARGET)
```

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

`src/ex4/makefile`:

```makefile
# conventional variable for c++ compiler
CXX := g++

# conventional variable for C preprocessor
CPPFLAGS := -DDEBUG

# conventional variable for C++ compiler flags
CXXFLAGS := -O3 -std=c++11 -Wall -Wextra -Wconversion

# conventional variable for linker flags
LDFLAGS := -ljpeg

TARGET := hw6
OBJS := hw6.o
INCS := hw6.hpp

$(TARGET): $(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LDFLAGS)

%.o: %.cpp $(INCS)
	$(CXX) -c -o $@ $< $(CPPFLAGS) $(CXXFLAGS)

# use .PHONY for targets that do not produce a file
.PHONY: clean
clean:
	rm -f $(OBJS) $(TARGET) *~

.PHONY: run
run: $(TARGET)
	./$(TARGET)
```

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
