# CME 211 Lecture 5: Complexity Analysis

Wednesday, September 30, 2015

## Announcements

* If you are on the wait list: submit homework by deadline.  We will grade
  if/when you make it into the class.

* We will be using [GitHub][GitHub] for version control and managing assignment
  submissions in this course. If you haven't already done so, please create a
  personal Github account at <https://github.com/>. Feel free to link the
  account to whatever email that you prefer (i.e. it does not need to be your
  `stanford.edu` email). Afterward, please fill out the [Google form][gh-form].

* Note: *SUNetID* refers to the first part of your stanford email address.  My
  SUNetID is `nwh`.  Please do not put your student ID number in the above form.

* Goal: we need to associate your GitHub username with your stanford username
  (SUNetID)

* In class I've shown IPython (Jupyter) notebooks and recommended the install of
  Anaconda Python.  We recommend that you use the web and each other for tech
  support related to these packages.  Computers and software are complicated
  things.  In this class, we must standardize and can only support your code
  running on the Farmshare systems.  Feel free to ask us for help, but we may
  decline based on time or requests from other students.  We will help you with
  farmshare issues.

[GitHub]: https://github.com/
[gh-form]: https://docs.google.com/forms/d/1JyNmmn2Ur6WTwUrI4jvCSpDNv6jph48mFUXu6lF-G2Q/viewform

## Farmshare review

Your first assignment must run on and be submitted through the farmshare
servers.  Let's walk through the process of creating a Python script and data
file locally then move it over to farmshare.  We will use the same conventions
as homework 1.

Please note that these instructions will work best on Mac OS X.  If you are on
Windows, you will need to follow the spirit of the instructions.

### Create a local directory structure for the class

1. Open your terminal program (`Terminal.app` on OSX).

2. Follow the sequence of commands:

```
nwh-mbpro:~ nwh$ cd
nwh-mbpro:~ nwh$ pwd
/Users/nwh
nwh-mbpro:~ nwh$ mkdir CME211
nwh-mbpro:~ nwh$ cd CME211/
nwh-mbpro:CME211 nwh$ mkdir lec5
nwh-mbpro:CME211 nwh$ cd lec5/
nwh-mbpro:lec5 nwh$ pwd
/Users/nwh/CME211/lec5
```

Notes:

* `cd` by itself moves to your home directory
* `~` is an alias for your home directory
* Homework 1 requires that your files be placed in `~/CME211/hw1` on farmshare

### Exercise

Let's write a short python script to count unique words in a data file.  The
data file will have one word per line.

### Create a data file

Open your favorite text editor and create the file `~/CME211/lec5/words.txt`.
Enter the following contents:

```
this
is
a
short
file
this
is
also
a
rainy
day
```
### Create a python script to count words

```py
# file name uses relative path
data_file = "words.txt"

f = open(data_file,"r")

# dictionary to store unique words as keys and counts as values
word_dict = dict()

# count the words
for line in f:
    # remove the new line character
    word = line.strip()
    if word in word_dict:
        # word is in dictionary, increment count
        word_dict[word] += 1
    else:
        # word is not yet in dictionary, set count to 1
        word_dict[word] = 1

# print the word counts
for word, count in word_dict.items():
    print("'{}' appeared {} time(s)".format(word,count))
```

### Test the script locally:

```
nwh-mbpro:lec5 nwh$ python count_words.py
'a' appeared 2 time(s)
'rainy' appeared 1 time(s)
'short' appeared 1 time(s)
'this' appeared 2 time(s)
'is' appeared 2 time(s)
'also' appeared 1 time(s)
'file' appeared 1 time(s)
'day' appeared 1 time(s)
```

### Move onto Farmshare with WebAFS

Log into <https://afs.stanford.edu/>.  You will see your farmshare files.  With
this interface you can create directories and upload files.

![web afs interface](lecture-5/web-afs.png)

Create a new folder:

![web afs new folder](lecture-5/web-afs-new-folder.png)

Upload files:

![web afs upload](lecture-5/web-afs-upload.png)

Final result:

![files uploaded](lecture-5/web-afs-files-uploaded.png)

### Test the program on Farmshare

```
nwh-mbpro:lec5 nwh$ ssh nwh@corn.stanford.edu
nwh@corn26:~$ cd CME211/lec5/
nwh@corn26:~/CME211/lec5$ ls
count_words.py	words.txt
nwh@corn26:~/CME211/lec5$ python count_words.py
'a' appeared 2 time(s)
'rainy' appeared 1 time(s)
'short' appeared 1 time(s)
'this' appeared 2 time(s)
'is' appeared 2 time(s)
'also' appeared 1 time(s)
'file' appeared 1 time(s)
'day' appeared 1 time(s)
# edit the data file
nwh@corn26:~/CME211/lec5$ emacs words.txt
nwh@corn26:~/CME211/lec5$ python count_words.py
'a' appeared 2 time(s)
'rainy' appeared 4 time(s)
'short' appeared 1 time(s)
'this' appeared 2 time(s)
'is' appeared 2 time(s)
'also' appeared 1 time(s)
'file' appeared 1 time(s)
'day' appeared 1 time(s)
nwh@corn26:~/CME211/lec5$
```

### Other method to copy files: `scp`

```
nwh-mbpro:lec5 nwh$ scp test.txt nwh@corn.stanford.edu:~/CME211/lec5/
Warning: Permanently added the RSA host key for IP address '171.67.215.107' to the listAuthenticated with partial success.
Duo two-factor login for nwh

Enter a passcode or select one of the following options:

 1. Duo Push to XXX-XXX-2441
 2. Phone call to XXX-XXX-2441
 3. SMS passcodes to XXX-XXX-2441

Passcode or option (1-3): 1
test.txt                                              100%   50     0.1KB/s   00:00
nwh-mbpro:lec5 nwh$
```

See `$ man scp`

### Other method to copy files: `sftp`

```
nwh-mbpro:lec5 nwh$ sftp nwh@corn.stanford.edu
nwh@corn.stanford.edu's password:
Authenticated with partial success.
Duo two-factor login for nwh

Enter a passcode or select one of the following options:

 1. Duo Push to XXX-XXX-2441
 2. Phone call to XXX-XXX-2441
 3. SMS passcodes to XXX-XXX-2441

Passcode or option (1-3): 1
Connected to corn.stanford.edu.
sftp> help
Available commands:
bye                                Quit sftp
cd path                            Change remote directory to 'path'
chgrp grp path                     Change group of file 'path' to 'grp'
chmod mode path                    Change permissions of file 'path' to 'mode'
chown own path                     Change owner of file 'path' to 'own'
df [-hi] [path]                    Display statistics for current directory or
                                   filesystem containing 'path'
exit                               Quit sftp
get [-Ppr] remote [local]          Download file
help                               Display this help text
lcd path                           Change local directory to 'path'
lls [ls-options [path]]            Display local directory listing
lmkdir path                        Create local directory
ln [-s] oldpath newpath            Link remote file (-s for symlink)
lpwd                               Print local working directory
ls [-1afhlnrSt] [path]             Display remote directory listing
lumask umask                       Set local umask to 'umask'
mkdir path                         Create remote directory
progress                           Toggle display of progress meter
put [-Ppr] local [remote]          Upload file
pwd                                Display remote working directory
quit                               Quit sftp
rename oldpath newpath             Rename remote file
rm path                            Delete remote file
rmdir path                         Remove remote directory
symlink oldpath newpath            Symlink remote file
version                            Show SFTP version
!command                           Execute 'command' in local shell
!                                  Escape to local shell
?                                  Synonym for help
sftp>
```

### Other software

See <https://itservices.stanford.edu/service/ess/> for Mac and Windows SFTP and
AFS clients.

Text editors:

* emacs
* vim
* [TextWrangler](http://www.barebones.com/products/textwrangler/)
* [Sublime Text](http://www.sublimetext.com/)
* [Atom](https://atom.io/)

Key: learn a tool, learn it well

Note: very helpful to become comfortable with a text editor you can use from the
terminal.

### Learn more about unix systems and interacting with the shell

William E. Shotts, Jr. has a very nice online book called **The Linux Command
Line**.  See the book online:

* <http://linuxcommand.org/lc3_learning_the_shell.php>

Only need to focus on "Learning the Shell".  In CME 211, we are not concerned
with writing shell scripts.

## A note on Python variables

It is bad practice to define a variable inside of a conditional or loop body and
then reference it outside:

```py
>>> name = "Nick"
>>> if name == "Nick":
...     age = 45
...
>>> print("Nick's age is {}".format(age))
Nick's age is 45
>>>
```

If `name` holds a different name, the following will happen:

```py
>>> name = "Bob"
>>> if name == "Nick":
...     age = 45
...
>>> print("Nick's age is {}".format(age))
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
NameError: name 'age' is not defined
>>>
```

Good practice to define/initialize variables at the same level they will be
used:

```py
>>> name = "Bob"
>>> age = None
>>> if name == "Nick":
...     age = 45
...
>>> print("Nick's age is {}".format(age))
Nick's age is None
>>>
```

Note in the above example, it may be more appropriate to initialize the `age`
variable to a more meaningful value.

We will learn about *scope* when we talk about functions on Friday.

## Analysis of algorithms

Key questions when considering the performance of algorithms:

* **Time complexity**: How does the number of operations in an algorithm scale with
the size of the input?

* **Space complexity**: How do the storage requirements of the algorithm scale?

## Empirical approach

Let's measure the running time of Pythons `sort` method on a random list of
integers.  See `lecture-5/listsort.py`:

```py
import random
import sys
import time

if len(sys.argv) < 2:
print 'Usage:'
print ' %s nvalues' % sys.argv[0]

n = int(sys.argv[1])

# Setup a list of random values and record the time required to sort it
v = random.sample(xrange(n), n)
t0 = time.time()
v.sort()
t1 = time.time()

print "Sorting %d values took %.3f seconds." % (n, t1-t0)
```

## Empirical approach

Let's run the script with increasing list length:

```
[nwh@icme-nwh lecture-5] $ python listsort.py
Usage:
 listsort.py nvalues
[nwh@icme-nwh lecture-5] $ python listsort.py 1000000
Sorting %d values took %.3f seconds.
[nwh@icme-nwh lecture-5] $ python listsort.py 2000000
Sorting 2000000 values took 1.12 seconds.
[nwh@icme-nwh lecture-5] $ python listsort.py 4000000
Sorting 4000000 values took 2.49 seconds.
[nwh@icme-nwh lecture-5] $ python listsort.py 8000000
Sorting 8000000 values took 5.41 seconds.
[nwh@icme-nwh lecture-5] $ python listsort.py 16000000
Sorting 16000000 values took 11.9 seconds.
[nwh@icme-nwh lecture-5] $
```

## Problems with empirical

Empirical performance testing is an important endeavor.  It is an apect of
"profiling" your code to see what parts take longer.  Empirical performance
testing has some drawbacks, namely:

* Results are computer dependent

* You need to have the code before you can do the analysis

## Time complexity

* Estimate of the number of operations as a function of the input size (usually
  denoted as `n`)

* Input size examples:

    * length of list

    * for an `m` by `m` matrix, we say the input size is `m` even though the
      matrix as `m^2` entries
    
    * number of non-zero entries in a sparse matrix

    * number of nodes in a graph or network structure

* Typically characterized in terms of Big O notation, e.g. an algorithm is
  `O(n log n)` or `O(n^2)`.

```
| order notation | in English          |
|----------------+---------------------|
| O(1)           | Constant time       |
| O(log n)       | Logarithmic time    |
| O(n)           | Linear time         |
| O(n log n)     | Linearithmitic time |
| O(n^2)         | Quadratic time      |
```

## Visualization

![order chart](lecture-5/order-chart.png)

## Big O notation

* Big O notation represents growth rate of a function in the limit of argument
  going to infinity

* Excludes coefficients and lower order terms

```
2n^22 + 64n -> O(n^2)
```

* Often some simplifying assumptions will need to be made about the nature of
  the input data in order to carry out analysis

## Linear algebra examples

* Adding two vectors? `O(n)`

```py
# c = a + b
# assume all the same length
n = len(a)
for i in xrange(n):
    c[i] = a[i] + b[i]
```

* Multiplying two matrices? Assuming the matrices are both `n x n`, it's
  `O(n^3)`

```py
# assume all matrices are n x n
# indexing notation below comes from numpy
# this will not work with standard python
# C = A*B
for i in xrange(n):
    for j in xrange(n):
        C[i,j] = 0
        for k in xrange(n):
            C[i,j] += A[i,k]*B[k,j]
```


![matmul](lecture-5/matrix.png)

Computing one value in the output matrix requires `O(n)`
operations, and there are `n^2` values in the output matrix.

## Linear search

*Linear search* is searching through a sequential data container for a specified
item.  An example of this is finding the start index of a given sub-string in a
longer string.

Exercise: Find the number `x` in your data:

```
|---+----+-----+----+-----+----+-----+-----|
| 4 | 17 | 100 | 73 | 120 | 42 | 999 | -17 |
|---+----+-----+----+-----+----+-----+-----|
```

Is it `O(1)`, or `O(n)`, or something else?

## Linear search: best and worst case

```
|---+----+-----+----+-----+----+-----+-----|
| 4 | 17 | 100 | 73 | 120 | 42 | 999 | -17 |
|---+----+-----+----+-----+----+-----+-----|

  ^                                     ^
  |                                     |
 O(1)                                  O(n)
```

* Best case: `x = 4` and we find the index with only one comparison

* Worst case: `x = -17` and we scan the entire list to find the last element

## Linear search: average case

```
|---+----+-----+----+-----+----+-----+-----|
| 4 | 17 | 100 | 73 | 120 | 42 | 999 | -17 |
|---+----+-----+----+-----+----+-----+-----|
             
                    ^
                    |
                  O(n/2)
```

Given random data and a random input (in the range of the data) we can **on
average** expect to search through half of the list.  This would be `O(n/2)`.
Remember that Big O notation is not concerned with constant terms, so this
becomes `O(n)`.

## Binary search algorithm

I we know that the list is sorted, we can apply binary search.  Let's look at an example

**Goal**: Find the index of `17` in the following list:

```
|-----+---+----+----+----+-----+-----+-----|
| -17 | 4 | 17 | 42 | 73 | 100 | 120 | 999 |
|-----+---+----+----+----+-----+-----+-----|
```

Start by looking half way through the list:

```
|-----+---+----+----+----+-----+-----+-----|
| -17 | 4 | 17 | 42 | 73 | 100 | 120 | 999 |
|-----+---+----+----+----+-----+-----+-----|
                  ^
                  U
```

`42` is not `17`, but `42` is greater than `17` so continue searching the left
(lower) part of the list.  The index associated with `42` becomes an upper bound
on the search.

```
|-----+---+----+----+----+-----+-----+-----|
| -17 | 4 | 17 | 42 | 73 | 100 | 120 | 999 |
|-----+---+----+----+----+-----+-----+-----|
        ^         ^
        L         U
```

`4` is not `17`, but `4` is less than `17` so continue searching to the right
part of the list up to the upper bound.  Turns out in this example that we only
have one entry to inspect:

```
|-----+---+----+----+----+-----+-----+-----|
| -17 | 4 | 17 | 42 | 73 | 100 | 120 | 999 |
|-----+---+----+----+----+-----+-----+-----|
        ^   ^     ^
        L   *     U
```

We have found `17`.  It is time to celebrate and return the index of `2`.
(Remember Python uses 0-based indexing.)

## Summary: Binary search

* Requires that the data first be sorted, but then:

    * Best case: `O(1)`

    * Average case: `O(log n)`

    * Worst case: `O(log n)`

## Sorting algorithms

There are many sorting algorithms and this is a worthy area of study.  Here are
few examples of names of sorting algorithms:

* Quicksort

* Merge sort

* Heapsort

* Timsort

* Bubble sort

* Radix sorts

* Etc.

The internet is full of examples of how sorting algorithms work

* <http://www.youtube.com/watch?v=lyZQPjUT5B4>

* <http://www.youtube.com/user/AlgoRythmics>


## Sorting algorithms

![sorting algo table](lecture-5/sorting-algo-table.png)

See: <https://en.wikipedia.org/wiki/Sorting_algorithm#Comparison_of_algorithms>

## Finding the maximum

What's the order of the algorithm to find the maximum value in an *unordered*
list?

```
|----+------+----+-----+----+----+-----+-----+---|
| 17 | 1325 | -3 | 346 | 73 | 19 | 999 | 120 | 0 |
|----+------+----+-----+----+----+-----+-----+---|
```

### Idea: let's sort

* Sort the list ascending / descending and take the last / first value

* Cost of the algorithm will be the cost of the sorting plus one more operation
to take the last / first value

* Sorting algorithms are typically `O(n log n)` or `O(n^2)`

* Overall order of algorithm will clearly be the order of the sorting algorithm

### Idea: linear search

Algorithm:

* scan through the list sequentially
* keep track of max element seen so far
* compare each element and update if needed

Step 1:

```
|----+------+----+-----+----+----+-----+-----+---|
| 17 | 1325 | -3 | 346 | 73 | 19 | 999 | 120 | 0 |
|----+------+----+-----+----+----+-----+-----+---|
  ^
  |
 17
```

Step 2: move to next element, compare and update

```
|----+------+----+-----+----+----+-----+-----+---|
| 17 | 1325 | -3 | 346 | 73 | 19 | 999 | 120 | 0 |
|----+------+----+-----+----+----+-----+-----+---|
         ^
         |
       1325
```

Repeat:

```
|----+------+----+-----+----+----+-----+-----+---|
| 17 | 1325 | -3 | 346 | 73 | 19 | 999 | 120 | 0 |
|----+------+----+-----+----+----+-----+-----+---|
              ^
              |
            1325
```

And so on:

```
|----+------+----+-----+----+----+-----+-----+---|
| 17 | 1325 | -3 | 346 | 73 | 19 | 999 | 120 | 0 |
|----+------+----+-----+----+----+-----+-----+---|
                                               ^
                                               |
                                             1325
```

Question: what is the order of this algorithm?

## Two largest values

* What's the complexity to find the two largest values in an *unordered* list of `n`
values?

## Two largest values

Now we need to keep track of two values during the traverse of the list.  We
will also need to sort the pair of numbers that we keep along the way.

Start by looking at the first two elements:

```
|----+----+-----+-----+----+------+-----+---|
| 17 | 73 | 417 | 346 | 73 | 1325 | 120 | 0 |
|----+----+-----+-----+----+------+-----+---|
 ^    ^
 |    |
(17,  73)
(73,  17) <- sorted
```

Move down by one:

```
|----+----+-----+-----+----+------+-----+---|
| 17 | 73 | 417 | 346 | 73 | 1325 | 120 | 0 |
|----+----+-----+-----+----+------+-----+---|
      ^    ^
      |    |
     (73,  417)
     (417,  73) <- sorted
```

Repeat:

```
|----+----+-----+-----+----+------+-----+---|
| 17 | 73 | 417 | 346 | 73 | 1325 | 120 | 0 |
|----+----+-----+-----+----+------+-----+---|
           ^     ^
           |     |
          (417,  346)
          (417,  346) <- sorted
```

Repeat (in this case no update is needed):

```
|----+----+-----+-----+----+------+-----+---|
| 17 | 73 | 417 | 346 | 73 | 1325 | 120 | 0 |
|----+----+-----+-----+----+------+-----+---|
                 ^     ^
                 |     |
                (417,  346)
                (417,  346) <- sorted
```

Notes:

* For each of n input elements you will do a comparison, potentially a
replacement, and a sort

* Time complexity is `O(n)`

Question:

* Does that mean that finding the two largest values will take the same amount
of time as finding the single largest value?

## `m` largest values

What if I want to find the `m` largest values in an unordered list of `n`
elements?

This is an example of a more complicated algorithm.  We have two components to
consider:

* the length of the list `n`

* number number of largest values that we want `m`

Thus, it may not be appropriate to characterize an algorithm in terms of one
parameter `n`:

* Time complexity for finding the `m` largest values in an unordered list of `n`
elements could be characterized as `O(n m log m)` for a sorting algorithm that
is `O(m log m)`

Question:

* For what m is it better just to sort the list?

## Finding sub-strings

Important procedure.  We are using it in homework 1.

Example:

```
TGTAGAATCACTTGAAAGGCGCGCAGTCTGGGGCGCTAGTCGTGGT
          CTTGAAAGG
          ^       ^
          |       |
```


* String has length `m`, and sub-string has length `n`

* Different algorithms:

    * `O(mn)` for a naive implementation

    * `O(m)` for typical algorithms

    * `O(n)` for a search that uses the Burrows-Wheeler transform

## List operations in Python

```
>>> a = []
>>> a.append(42)
>>> a
[42]
>>> a.insert(0, 7)
>>> a
[7, 42]
>>> a.insert(1, 19)
>>> a
[7, 19, 42]
>>>
```

Python lists use contiguous storage.  As we are inserting into the list, the
memory layout will look something like:

```
>>> a.append(42)

|----+---+---+---|
| 42 | ? | ? | ? |
|----+---+---+---|

>>> a.insert(0, 7)

|---+----+---+---|
| 7 | 42 | ? | ? |
|---+----+---+---|

>>> a.insert(1, 19)

|---+----+----+---|
| 7 | 19 | 42 | ? |
|---+----+----+---|

```

## List vs Set in python

Let's compare Python's list and set objects for a few operations:

Create a file `loadnames.py`

```
names_list = []
names_set = set([])
f = open('dist.female.first')
for line in f:
    name = line.split()[0]
    names_list.append(name)
    names_set.add(name)
f.close()
```

Run the script and enter into the interpreter:

```
$ python -i loadnames.py
>>> 'JANE' in names_list
True
>>> 'LELAND' in names_list
False
>>> 'JANE' in names_set
True
>>> 'LELAND' in names_set
False
>>>
```

Which container is better for insertion and existence testing?

## Documentation

![time complexity](lecture-5/time-complexity.png)

<https://wiki.python.org/moin/TimeComplexity>

### List operations

![list](lecture-5/list.png)

### Set operations

![set](lecture-5/set.png)

## Dictionary operations

![dict](lecture-5/dict.png)

## Space complexity

* What additional storage will I need during execution of the algorithm?

* Doesn't include the input or output data

* Really just refers to temporary data structures which have the life of the
algorithm

* Process for determining the space complexity is analogous to determining time
complexity

## Complexity analysis

* Good framework for comparing *algorithms*

* Understanding individual algorithms will help you understand performance of an
application made up of multiple algorithms

* Also important for understanding data structures

* Caveats:

    * There is no standard definition of what constitutes an operation

    * It's an asymptotic limit for large n

    * Says nothing about the constants

    * May make assumptions about dataset (random distribution, etc.)
