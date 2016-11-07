# CME 211: Lecture 20

Monday, November 9, 2015

Topics:

* C++ containers
* `map`
* `set`
* and more

## Container iteration

### Container iteration example 1

`src/iter1.cpp`:

!include src/iter1.cpp cpp

Output:

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/iter1.cpp -o src/iter1
./src/iter1 
!end

### Container iteration example 2

`src/iter2.cpp`:

!include src/iter2.cpp cpp

Output:

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/iter2.cpp -o src/iter2
./src/iter2
!end

## Map

* A C++ map is analogous to a dictionary in Python

* Need to specify data type for both the key and the value when instance is
declared

### Our first map

`src/map1.cpp`:

!include src/map1.cpp cpp

Output:

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/map1.cpp -o src/map1
./src/map1
!end

### Map iteration

`src/map2.cpp`:

!include src/map2.cpp cpp

Output:

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/map2.cpp -o src/map2
./src/map2
!end

### Older style iteration

`src/map3.cpp`:

!include src/map3.cpp cpp

Output:

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/map3.cpp -o src/map3
./src/map3
!end

### Nonexistent keys

`src/map4.cpp`:

!include src/map4.cpp cpp

Output:

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/map4.cpp -o src/map4
./src/map4
!end

### Nonexistent keys

`src/map5.cpp`:

!include src/map5.cpp cpp

Output:

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/map5.cpp -o src/map5
./src/map5
!end

### Testing for a key

`src/map6.cpp`:

!include src/map6.cpp cpp

Output:

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/map6.cpp -o src/map6
./src/map6
!end

### Testing for a key

`src/map7.cpp`:

!include src/map7.cpp cpp

Output:

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/map7.cpp -o src/map7
./src/map7
!end

### Key order

`src/map8.cpp`:

!include src/map8.cpp cpp

Output:

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/map8.cpp -o src/map8
./src/map8
!end

### Map and tuples

`src/map9.cpp`:

!include src/map9.cpp cpp

Output:

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/map9.cpp -o src/map9
./src/map9
!end

### Using functions

`src/readnames.hpp`:

!include src/readnames.hpp cpp

`src/readnames.cpp`:

!include src/readnames.cpp cpp

`#pragma once`: only include this file once (not standard)

`src/testname.hpp`:

!include src/testname.hpp cpp

`src/testname.cpp`:

!include src/testname.cpp cpp

### Using functions

`src/main.cpp`:

!include src/main.cpp cpp

Output:

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/main.cpp src/readnames.cpp src/testname.cpp -o src/main
./src/main
!end

### Sets

`src/set.cpp`:

!include src/set.cpp cpp

Output:

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/set.cpp -o src/set
./src/set 
!end

### Additional data structures

* `std::array` (C++ 2011)

* `std::list`

* `std::forward_list` (C++ 2011)

* `std::unordered_map` (C++ 2011)

* `std::unordered_set` (C++ 2011)

### Array example

`src/array.cpp`:

!include src/array.cpp cpp

Output:

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/array.cpp -o src/array
./src/array 
!end

## Linked lists

* Ordered data sequence similar to a C++ vector or Python list, but data is not
stored contiguously

* Sense of order is maintained via links

* There is additional storage overhead for the links

* But this allows for insertion and removal operations in constant time

![fig](fig/linked-list.png)

### List example

`src/list.cpp`:

!include src/list.cpp cpp

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/list.cpp -o src/list
./src/list 
!end

### Maps and sets

* Python dictionaries and sets are internally implemented by using hashing

* For hashing implementation, time complexity for data access is (amortized)
constant time

* Instances of C++ `std::map` and `std::set` are internally implemented using a tree
data structure

* For a tree, time complexity for data access is `O(log n)`

* Reference: <http://www.cplusplus.com/reference/map/map/operator[]/>

### Unordered maps and sets

* In the C++ 2011 standard the `std::unordered_map` and `set::unordered_set`
were added

* Like Python, internal implementation is based on hashing

* Faster access, but entries are no longer ordered (but that usually doesn't
  matter)

### Unordered map example

`src/unordered_map.cpp`:

!include src/unordered_map.cpp cpp

Output:

!run
clang++ -std=c++11 -Wall -Wextra -Wconversion src/unordered_map.cpp -o src/unordered_map
./src/unordered_map 
!end

## Reading

* **C++ Primer, Fifth Edition** by Lippman et al.

* Chapter 11: Associative Containers: Sections 11.1 - 11.3
