# CME 211 Lecture 5: Complexity Analysis

Wednesday, September 30, 2015

# Warning: these notes are not complete

## Announcements

## Analysis of algorithms

* Time complexity: How does the

number of operations in an algorithm scale
with the size of the input?


* Space complexity: How do the storage
requirements of the algorithm scale?


3


## Empirical approach

import random!
import sys!
import time!
!
if len(sys.argv) < 2:!
print 'Usage:'!
print ' %s nvalues' % sys.argv[0]!
!
n = int(sys.argv[1])!
!
# Setup a list of random values and record the time required to sort it!
v = random.sample(xrange(n), n)!
t0 = time.time()!
v.sort()!
t1 = time.time()!
!
print "Sorting %d values took %.3f seconds." % (n, t1-t0)!

listsort.py!

4


## Empirical approach

plegresl@corn16:~/CME211/Lecture05$ python listsort.py
Sorting 1000000 values took 0.794 seconds.!
plegresl@corn16:~/CME211/Lecture05$ python listsort.py
Sorting 2000000 values took 1.854 seconds.!
plegresl@corn16:~/CME211/Lecture05$ python listsort.py
Sorting 4000000 values took 4.334 seconds.!
plegresl@corn16:~/CME211/Lecture05$ python listsort.py
Sorting 8000000 values took 9.695 seconds.!
plegresl@corn16:~/CME211/Lecture05$ python listsort.py
Sorting 16000000 values took 22.484 seconds.!
plegresl@corn16:~/CME211/Lecture05$ !

5


1000000!
2000000!
4000000!
8000000!
16000000!

## Problems with empirical

* Results are computer dependent

* You need to have the code before you can
do the analysis


6


## Time complexity

* Estimate of the number of operations as a

function of the input size (usually denoted as n)


* Typically characterized in terms of Big O

notation, e.g. an algorithm is O(n log n) or O(n2)

O(1)

O(log n)

O(n)

O(n log n)

O(n2)


Constant time

Logarithmic time

Linear time

Linearithmitic time

Quadratic time

7


## Visualization


8


## Big O notation

* Big O notation represents growth rate of a

function in the limit of argument going to infinity


* Excludes coefficients and lower order terms

2n2 + 64n

e

O(n2)




* Often some simplifying assumptions will need to
be made about the nature of the input data


9


## Linear algebra examples

* Adding two vectors? O(n)

* Multiplying two matrices? Assuming the
matrices are both n x n, it's O(n3)


[][] []
=


n x n


n x n


n x n


Computing one value in the output matrix requires O(n)
operations, and there are n2 values in the output matrix.

10


## Linear search

Find the number x in your data:


4


17


100


73


120


42


999


-17


Is it O(1), or O(n), or something else?


11


## Linear search: best and worst case


4


17


100


73


120


Best case: O(1)


42


999


-17


Worst case: O(n)


12


## Linear search: average case


4


17


100


73


120


Average case: O(n/2)

13


42


e

999


O(n)


-17


## Binary search algorithm

Find 17:

-17


4


17


42


73


100


120


999


-17


4


17


42


73


100


120


999


-17


4


17


42


73


100


120


999


14


## Binary search

* Requires that the data first be sorted, but
then:


* Best case: O(1)

* Average case: O(log n)

* Worst case: O(log n)

15


## Sorting algorithms

* Quicksort

* Merge sort

* Heapsort

* Timsort

* Bubble sort

* Radix sorts

* Etc.

16


## Bubble sort

http://www.youtube.com/watch?v=lyZQPjUT5B4


For more examples:

http://www.youtube.com/user/AlgoRythmics


17


## Sorting algorithms

Name


Best


Average


Worst


Memory


Stable


Quicksort


n log n


n log n


n2


Average log n,
worst n


Usually not




Merge sort


n log n


n log n


n log n


Worst n


Yes


Heapsort


n log n


n log n


n log n


1


No


Bubble sort


n


n2


n2


1


Yes


http://en.wikipedia.org/wiki/Sorting_algorithms#Comparison_of_algorithms

18


## Finding the maximum

What's the order of the algorithm to find
the maximum value in an unordered list?


17


1325


-3


346


73


19


999


120


0


## Maximum via sorting

* Sort the list ascending / descending and take
the last / first value


* Cost of the algorithm will be the cost of the

sorting plus one more operation to take the
last / first value


* Sorting algorithms are typically O(n log n) or
O(n2)


* Overall order of algorithm will clearly be the
order of the sorting algorithm

20


## Maximum via linear search

17


1325


-3


346


73


999


120


0


Is this the maximum value I've seen so far?

17


1325


-3


346


73


999


120


0


Is this the maximum value I've seen so far?

17


1325


-3


346


73


999


120


0


Is this the maximum value I've seen so far?

21


## Two largest values

* What's the complexity to find the two largest
values in an unordered list of n values?


22


## Two largest values

17


73


417

 346


73

 1325

 120


0


17


73


Sort


> ?

17


73


417

 346


73

 1325

 120


0


73


17


73


417


Sort

417


73


...

1325

 417

23


## Two largest values

* For each of n input elements you will do a

comparison, potentially a replacement, and a sort


* Time complexity is O(n)


* Does that mean that finding the two largest
values will take the same amount of time as
finding the single largest value?


24


## m largest values

* What if I want to find the m largest values
in an unordered list of n elements?


25


## More complicated algorithms


* May not be appropriate to characterize an
algorithm in terms of one parameter n


* Time complexity for finding the m largest

values in an unordered list of n elements
could be characterized as O(n m log m) for
a sorting algorithm that is O(m log m)


* For what m is it better just to sort the list?

26


## Finding substrings

TGTAGAATCACTTGAAAGGCGCGCAGTCTGGGGCGCTAGTCGTGGT

CTTGAAAGG


* String has length m, and substring has length n

* Algorithms could vary

* O(mn) for a naive implementation

* O(m) for typical algorithms

* O(n) for a search that uses the BurrowsWheeler transform


27


## List operations

>>> a = []!
>>> a.append(42)!
>>> a!
[42]!
>>> a.insert(0, 7)!
>>> a!
[7, 42]!
>>> a.insert(1, 19)!
>>> a!
[7, 19, 42]!
>>> !
28


## Python lists use contiguous storage

42!

?!

?!

?!

7!

42!

?!

?!

7!

19!

42!

?!

29


## List access

* What is the time complexity to access the
ith element of a list with n elements?


30


## List access


Start


Location of ith element


Computing the location of the ith
element is independent of n, so O(1)


31


## Which is better? And why?

names_list = []!
names_set = set([])!
f = open('dist.female.first')!
for line in f:!
name = line.split()[0]!
names_list.append(name)!
names_set.add(name)!
f.close()!
loadnames.py!
plegresl@corn16:~/CME211/Lecture05$ python -i loadnames.py !
>>> 'JANE' in names_list!
True!
>>> 'LELAND' in names_list!
False!
>>> 'JANE' in names_set !
True!
>>> 'LELAND' in names_set!
False!
>>> !
32

!

## Documentation


https://wiki.python.org/moin/TimeComplexity

33


## List operations


34


## Set operations


35


## Dictionary operations


36


## Space complexity

* What additional storage will I need during
execution of the algorithm?


* Doesn't include the input or output data

* Really just refers to temporary data structures
which have the life of the algorithm


* Process for determining the space complexity
is analogous to determining time complexity


37


## Complexity analysis


* Good framework for comparing algorithms

* Understanding individual algorithms will help you

understand performance of an application made up of
multiple algorithms


* Also important for understanding data structures

* Caveats:

*
*
*
*

There is no standard definition of what constitutes an operation

It's an asymptotic limit for large n

Says nothing about the constants

May make assumptions about dataset (random distribution, etc.)

38


## 
