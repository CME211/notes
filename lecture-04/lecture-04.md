# CME 211 Lecture 4: Python containers

Monday, September 28, 2015

## Announcements

- Screencasts posted to Piazza
- Course schedule posted
- 11 spots in the class now open (waiting for registrar to update)
- Will update on open spots Wednesday, Friday as well

## Container review

- *Containers* are objects that contain one or more other objects

- *Containers* are sometimes called "collections" or "data structures"

- In lecture 3, we spent sometime looking at the Python `list` container

- Today we will see Dictionaries and Tuples

## List review

- Python lists store objects in a specified sequence

```py
>>> cme211_tas = ["josh", "evan", "oliver", "swaroop"]
```

- Accessing a single item is done via square brackets

```py
>>> cme211_tas[2]
'oliver'
```

- You can get a sub-list with a slice:

```py
>>> cme211_tas[1:3]
['evan', 'oliver']
```

- Note that slicing creates a new list:

```py
>>> two_tas = cme211_tas[1:3]
>>> two_tas
['evan', 'oliver']
>>> two_tas[0] = 'bob'
>>> two_tas
['bob', 'oliver']
>>> cme211_tas
['josh', 'evan', 'oliver', 'swaroop']
>>>
```

## List methods

See `>>> help(list)` to get a list of the list methods.  This should open a
"pager" in your python interpreter.  The "pager" allows you to view the help text
one page at a time.  On my computer the pager is the `less` program.  Hitting
the key `g` goes back to the top of the help text.  Hitting the space bar moves
one page forward in the help documentation.  For reference here are the built-in
methods for Python `list` objects:

```
append(...)
    L.append(object) -- append object to end

count(...)
    L.count(value) -> integer -- return number of occurrences of value

extend(...)
    L.extend(iterable) -- extend list by appending elements from the iterable

index(...)
    L.index(value, [start, [stop]]) -> integer -- return first index of value.
    Raises ValueError if the value is not present.

insert(...)
    L.insert(index, object) -- insert object before index

pop(...)
    L.pop([index]) -> item -- remove and return item at index (default last).
    Raises IndexError if list is empty or index is out of range.

remove(...)
    L.remove(value) -- remove first occurrence of value.
    Raises ValueError if the value is not present.

reverse(...)
    L.reverse() -- reverse *IN PLACE*

sort(...)
    L.sort(cmp=None, key=None, reverse=False) -- stable sort *IN PLACE*;
    cmp(x, y) -> -1, 0, 1
```

The methods in the help documentation that start and end with underscores (for
example, `__add__`) refer to methods that are called through python operators.
The `__add__` method is called when the `+` operator is called on lists:

```py
>>> cme211_tas + ['loek']
['josh', 'evan', 'oliver', 'swaroop', 'loek']
>>> cme211_tas.__add__(['loek'])
['josh', 'evan', 'oliver', 'swaroop', 'loek']
>>> 
```

## Dictionaries

- Dictionaries are an *associative container*.  They contain *keys* with
  associated *values*

- Dictionaries in Python are denoted by curly braces

    - Create an empty dictionary: `empty_dict = {}`

    - Create a dictionary with some data: `ages = {"brad": 51, "angelina": 40}`

- Values can be any python object: numbers, strings, lists, other dictionaries

- Keys can be any immutable object: numbers, strings, tuples (containing
  immutable data)

- No sense of order in a python dictionary.  When used in a loop, the key-value
  pairs may come out in any order.

- Access values associated with a key with square brackets:
  `value = dictionary[key]`

### Create a dictionary

```py
>>> ages = {} # or ages = dict()
>>> ages['brad'] = 51
>>> ages['angelina'] = 40
>>> ages['leo'] = 40
>>> ages['bruce'] = 60
>>> ages
{'bruce': 60, 'angelina': 40, 'leo': 40, 'brad': 51}
```

### Access items

```py
>>> ages['leo']
40
```

When the key does not exist:

```py
>>> ages['helen']
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
KeyError: 'helen'
>>>
```

Or you can use the `get()` method:

```py
>>> temp = ages.get('brad')
>>> print(temp)
51
>>> temp = ages.get('helen')
>>> print(temp)
None
```

### Iteration

Iterate through the keys with:

```py
>>> for key in ages:
...     print("{} = {}".format(key,ages[key]))
... 
bruce = 60
angelina = 40
leo = 40
brad = 51
>>> 
```

Iterate through key-values pairs with:

```py
>>> for k, v in ages.items():
...     print('{} = {}'.format(k,v))
... 
bruce = 60
angelina = 40
leo = 40
brad = 51
```

The above syntax is more efficient in Python 3.  To achieve equivalent
performance in Python 2, it is best to ask for an *iterator* over the key-value
pairs:

```py
>>> for k, v in ages.iteritems():
...     print('{} = {}'.format(k,v))
... 
bruce = 60
angelina = 40
leo = 40
brad = 51
```

We will discuss *iterators* in more detail later.  In Python 2 the dictionary
`items()` method returns a newly-created list of *tuples*:

```py
>>> ages.items()
[('bruce', 60), ('angelina', 40), ('leo', 40), ('brad', 51)]
```

This requires memory allocation and data copying.  The `iteritems()` method (or
`items()` method in Python 3) returns an *iterator*:

```py
>>> ages.iteritems()
<dictionary-itemiterator object at 0x7f509e06d260>
```

This is a Python object that provides access to the data in a container in a
sequential fashion **without** requiring the creation of a new data structure
and copying of data.

### Dictionary methods

See `help(dict)` to get a summary of all dictionary methods:

```
clear(...)
    D.clear() -> None.  Remove all items from D.

copy(...)
    D.copy() -> a shallow copy of D

fromkeys(...)
    dict.fromkeys(S[,v]) -> New dict with keys from S and values equal to v.
    v defaults to None.

get(...)
    D.get(k[,d]) -> D[k] if k in D, else d.  d defaults to None.

has_key(...)
    D.has_key(k) -> True if D has a key k, else False

items(...)
    D.items() -> list of D's (key, value) pairs, as 2-tuples

iteritems(...)
    D.iteritems() -> an iterator over the (key, value) items of D

iterkeys(...)
    D.iterkeys() -> an iterator over the keys of D

itervalues(...)
    D.itervalues() -> an iterator over the values of D

keys(...)
    D.keys() -> list of D's keys

pop(...)
    D.pop(k[,d]) -> v, remove specified key and return the corresponding value.
    If key is not found, d is returned if given, otherwise KeyError is raised

popitem(...)
    D.popitem() -> (k, v), remove and return some (key, value) pair as a
    2-tuple; but raise KeyError if D is empty.

setdefault(...)
    D.setdefault(k[,d]) -> D.get(k,d), also set D[k]=d if k not in D

update(...)
    D.update([E, ]**F) -> None.  Update D from dict/iterable E and F.
    If E present and has a .keys() method, does:     for k in E: D[k] = E[k]
    If E present and lacks .keys() method, does:     for (k, v) in E: D[k] = v
    In either case, this is followed by: for k in F: D[k] = F[k]

values(...)
    D.values() -> list of D's values

viewitems(...)
    D.viewitems() -> a set-like object providing a view on D's items

viewkeys(...)
    D.viewkeys() -> a set-like object providing a view on D's keys

viewvalues(...)
    D.viewvalues() -> an object providing a view on D's values
```

## Tuples

- Tuples are essentially immutable lists

- Tuples are denoted with parentheses: `tup = (1,2,3)`

- Tuples store data in order

- Items in tuples are accessed via indexing and slicing

- Tuple items may not be changed.  (However, if a tuple contains a modifiable
object such as a list, the contained object may be modified)

### Tuple examples

Basic usage:

```py
>>> days = ('Su', 'M', 'Tu', 'W', 'Th', 'F', 'Sa')
>>> days[5]
'F'
>>> days[3:6]
('W', 'Th', 'F')
>>> days[1] = 'C'
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: 'tuple' object does not support item assignment
>>>
```

Modifiable objects contained in a tuple are still modifiable:

```py
>>> my_tup = (2, 'a string', [1,3,8])
>>> my_tup[2]
[1, 3, 8]
>>> my_tup[2] = 'something else'
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: 'tuple' object does not support item assignment
>>> my_tup[2][0] = 'new data'
>>> my_tup
(2, 'a string', ['new data', 3, 8])
>>> 
```

### Tuple modifiability diagram

![tuple diagram](fig/tuple-modifiability.png)

### Tuple-list conversion

```py
>>> days_list = list(days)
>>> days_list
['Su', 'M', 'Tu', 'W', 'Th', 'F', 'Sa']
>>> days_tup = tuple(days_list)
>>> days_tup
('Su', 'M', 'Tu', 'W', 'Th', 'F', 'Sa')
>>>
```

### A note on (im)mutability

It is natural to wonder why have immutable objects at all.  One answer to this
is practical: in Python, only immutable objects are allowed as keys in a
dictionary or items in a set.

The more detailed answer requires knowledge of the underlying data structure
behind Python dictionary and set objects.  In the context of a Python
dictionary, the memory location for a key-value pair is computed from a *hash*
of the key.  If the key were modified, the *hash* would change, likely requiring
a move of the data in memory.  Thus, Python requires immutable keys to prevent
unnecessary movement of data.

It is possible to associate a value with a new key with the following code:

```py
>>> ages
{'bruce': 60, 'angelina': 40, 'leo': 40, 'brad': 51}
>>> ages['mike'] = ages['bruce']
>>> del ages['bruce']
>>> ages
{'mike': 60, 'angelina': 40, 'leo': 40, 'brad': 51}
>>> 
```

## Python sets

- A `set` is an unordered, mutable collection of unique items
- Items in Python set must be immutable (for the same reason keys in a
  dictionary must be immutable)
- Create a set with: `>>> my_set = set([1, 2, 3])`
- We can test for existence in a set and perform set operations

### Set examples

```
>>> myclasses = set()
>>> myclasses.add("math")
>>> myclasses.add("chemistry")
>>> myclasses.add("literature")
>>> 
>>> yourclasses = set()
>>> yourclasses.add("physics")
>>> yourclasses.add("gym")
>>> yourclasses.add("math")
>>>
>>> "gym" in myclasses
False
>>> "gym" in yourclasses
True
>>> 
>>> myclasses & yourclasses # intersection
set(['math'])
>>> myclasses | yourclasses # union
set(['literature', 'gym', 'chemistry', 'physics', 'math'])
>>>
```

### Set methods

See `help(set)`:

```
add(...)
    Add an element to a set.
    
    This has no effect if the element is already present.

clear(...)
    Remove all elements from this set.

copy(...)
    Return a shallow copy of a set.

difference(...)
    Return the difference of two or more sets as a new set.
    
    (i.e. all elements that are in this set but not the others.)

difference_update(...)
    Remove all elements of another set from this set.

discard(...)
    Remove an element from a set if it is a member.
    
    If the element is not a member, do nothing.

intersection(...)
    Return the intersection of two or more sets as a new set.
    
    (i.e. elements that are common to all of the sets.)

intersection_update(...)
    Update a set with the intersection of itself and another.

isdisjoint(...)
    Return True if two sets have a null intersection.

issubset(...)
    Report whether another set contains this set.

issuperset(...)
    Report whether this set contains another set.

pop(...)
    Remove and return an arbitrary set element.
    Raises KeyError if the set is empty.

remove(...)
    Remove an element from a set; it must be a member.
    
    If the element is not a member, raise a KeyError.

symmetric_difference(...)
    Return the symmetric difference of two sets as a new set.
    
    (i.e. all elements that are in exactly one of the sets.)

symmetric_difference_update(...)
    Update a set with the symmetric difference of itself and another.

union(...)
    Return the union of sets as a new set.
    
    (i.e. all elements that are in either set.)

update(...)
    Update a set with the union of itself and others.
```

http://www.stanford.edu/~plegresl/CME211/Lecture04.tar

## Example looking at 1990 first name data from US Census

Thanks to Patrick LeGresley for this example.

Goal: write program to predict *male* or *female* given name

Algorithm:

1. If input name is in list of males, return `"M"`
2. Else if input name is in list of females, return `"F"`
3. Otherwise, return `"NA"`

### Look at the files

```
[nwh@icme-nwh cme211-notes] $ pwd
/home/nwh/git/cme211-notes
[nwh@icme-nwh cme211-notes] $ cd lecture-4/
[nwh@icme-nwh lecture-4] $ ls -1
dist.female.first
dist.male.first
name1a.py
name1b.py
name2.py
[nwh@icme-nwh lecture-4] $ head dist.female.first 
MARY           2.629  2.629      1
PATRICIA       1.073  3.702      2
LINDA          1.035  4.736      3
BARBARA        0.980  5.716      4
ELIZABETH      0.937  6.653      5
JENNIFER       0.932  7.586      6
MARIA          0.828  8.414      7
SUSAN          0.794  9.209      8
MARGARET       0.768  9.976      9
DOROTHY        0.727 10.703     10
```

Notes:

- the unix `head` command prints out the first 10 lines of a text file
- first column of the data file contains the name in uppercase
- following columns contain frequency data and rank, which we won't use today.

### Using sets

See `lecture-4/name1a.py`:

```py
# Create sets for female and male names
female = set()
f = open("dist.female.first")
for line in f:
    female.add(line.split()[0])
f.close()

male = set()
f = open("dist.male.first")
for line in f:
    male.add(line.split()[0])
f.close()

# Summarize information about the reference data
print("There are {} female names and {} male names.".format(len(female),len(male)))
print("There are {} names that appear in both sets.".format(len(female & male)))

# Test data
names = ["PETER", "LOIS", "STEWIE", "BRIAN", "MEG", "CHRIS"]

# Try our algorithm
for name in names:
    if name in male:
        ret = "M"
    elif name in female:
        ret = "F"
    else:
        ret = "NA"
    print("{}: {}".format(name, ret))
```

Run the code:

```
[nwh@icme-nwh lecture-4] $ python name1a.py 
There are 4275 female names and 1219 male names.
There are 331 names that appear in both sets.
PETER: M
LOIS: F
STEWIE: NA
BRIAN: M
MEG: F
CHRIS: M
```

Run the code and get interpreter after completion:

```
[nwh@icme-nwh lecture-4] $ python -i name1a.py 
There are 4275 female names and 1219 male names.
There are 331 names that appear in both sets.
PETER: M
LOIS: F
STEWIE: NA
BRIAN: M
MEG: F
CHRIS: M
>>> names
['PETER', 'LOIS', 'STEWIE', 'BRIAN', 'MEG', 'CHRIS']
>>> len(male)
1219
>>> len(female)
4275
>>> 
```

### Using lists

See `lecture-4/name1b.py`

```py
# Create sets for female and male names
female = list()
f = open("dist.female.first")
for line in f:
    female.append(line.split()[0])
f.close()

male = list()
f = open("dist.male.first")
for line in f:
    male.append(line.split()[0])
f.close()

# Summarize information about the reference data
print("There are {} female names and {} male names.".format(len(female),len(male)))

# need to implement intersection
nboth = 0
for name in female:
    if name in male:
        nboth = nboth + 1

print("There are {} names that appear in both sets.".format(nboth))
```

### Second algorithm

Some names appear in both **male** and **female** lists.  Some names might not
appear in either list.  Let's write a new algorithm to handle this uncertainty:

Given an input name:
- return `0.0` if male
- return `1.0` if female
- return `0.5` if uncertain or name does not appear in dataset

### Solution

Use a Python dictionary with keys as first names and values as specified above.

See `lecture-4/name2.py`:

```py
# Create dictionary with name data
names = {}
f = open("dist.female.first")
for line in f:
    names[line.split()[0]] = 1.
f.close()

f = open("dist.male.first")
for line in f:
    name = line.split()[0]
    if name in names:
        # Just assume a 50/50 distribution for names on both lists
        names[name] = 0.5 
    else:
        names[name] = 0.
f.close()

# Summary information about our reference data
print("There are {} names in our reference data.".format(len(names)))

# Test data
testdata = ["PETER", "LOIS", "STEWIE", "BRIAN", "MEG", "CHRIS", "NICK"]

# Try our algorithm
for name in testdata:
    if name in names:
        ret = names[name]
    else:
        ret = 0.5
    print("{}: {}".format(name, ret))
```

## Coming up this week:

- Wednesday: complexity analysis
- Friday: python data model, functions
- Assignment due Friday @ 2:30pm
- Next assignment out on Friday also
