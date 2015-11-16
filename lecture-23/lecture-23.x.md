# CME 211: Lecture 23

Monday, November 16, 2015

Topic: C++ Object Oriented Programming

## A simple class

!include src/class1.cpp c++

!run
clang++ -Wall -Wextra -Wconversion src/class1.cpp -o src/class1
./src/class1
!end

### Member access

!include src/class2.cpp c++

!run
clang++ -Wall -Wextra -Wconversion src/class2.cpp -o src/class2
!end

### Member access

!include src/struct1.cpp c++

!run
clang++ -Wall -Wextra -Wconversion src/struct1.cpp -o src/struct1
./src/struct1 
!end

### Member access

* C++ is strict about member access

* Need to know about default behavior

* And how to override defaults via access specifiers

### Access specifiers

* `private`: data or method member only accessible from within member(s) of the
same class

* `public`: data or method member accessible by anyone using dot notation

* Default access specifier for `class` is `private`

* Default access specifier for `struct` is `public`

### Overriding default access

!include src/class3.cpp c++

!run
clang++ -Wall -Wextra -Wconversion src/class3.cpp -o src/class3
./src/class3
!end

### Overriding default access

!include src/struct2.cpp c++

!run
clang++ -Wall -Wextra -Wconversion src/struct2.cpp -o src/struct2
!end

### Mix and match

!include src/class4.cpp c++

!run
clang++ -Wall -Wextra -Wconversion src/class4.cpp -o src/class4
!end

### "Adding" a member

!include src/struct3.cpp c++

!run
clang++ -Wall -Wextra -Wconversion src/struct3.cpp -o src/struct3
!end

### Our first method

!include src/class5.cpp c++

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/class5.cpp -o src/class5
!end

### Our first method

!include src/class6.cpp c++

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/class6.cpp -o src/class6
./src/class6
!end

### Naming

!include src/class7.cpp c++

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/class7.cpp -o src/class7
./src/class7
!end

### One solution

!include src/class8.cpp c++

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/class8.cpp -o src/class8
./src/class8
!end

### `this`

!include src/class9.cpp c++

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/class9.cpp -o src/class9
./src/class9
!end

## Constructor

* Special method called when a new object of the class is created

* C++ provides a default constructor that takes no arguments

* You can replace the default constructor with a custom constructor by defining
a method name with the same name as the class

* Like other methods, the constructor can take arguments

* Does not return anything, not even void

### Constructor example

!include src/class10.cpp c++

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/class10.cpp -o src/class10
./src/class10
!end

### Constructor example
!include src/class11.cpp c++

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/class11.cpp -o src/class11
!end

## Circle example

!include src/circle1.cpp c++

!run
clang++ -Wall -Wextra -Wconversion src/circle1.cpp -o src/circle1
./src/circle1 
!end

## Multiple files

!include src/circle2.hpp c++

!include src/circle2.cpp c++

!include src/main2.cpp c++

!run
clang++ -Wall -Wextra -Wconversion src/circle2.cpp src/main2.cpp -o src/main2 -I./src
./src/main2
!end

### Multiple files, example 2

!include src/circle3.hpp c++

!include src/circle3a.cpp c++

!include src/circle3b.cpp c++

!include src/main3.cpp c++

!run
clang++ -Wall -Wextra -Wconversion src/circle3a.cpp src/circle3b.cpp src/main3.cpp -o src/main3 -I./src
./src/main3
!end

## Objects and containers

!include src/container.cpp c++

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/circle3a.cpp src/circle3b.cpp src/container.cpp -o src/container -I./src
./src/container 
!end

## Reading

**C++ Primer, Fifth Edition** by Lippman et al.

* Section 1.5: Introducing Classes
