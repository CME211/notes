## Tuples

* Tuples are essentially immutable lists

* Tuples are denoted with parentheses: `tup = (1,2,3)`

* Tuples store data in order

* Items in tuples are accessed via indexing and slicing

* Tuple items may not be changed.  (However, if a tuple contains a modifiable
  object such as a list, the contained object may be modified)

### Tuple examples

Basic usage:

```python
days = ('Su', 'M', 'Tu', 'W', 'Th', 'F', 'Sa')
days[5]
'F'
days[3:6]
('W', 'Th', 'F')
days[1] = 'C'
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: 'tuple' object does not support item assignment

```

Modifiable objects contained in a tuple are still modifiable:

```python
my_tup = (2, 'a string', [1,3,8])
my_tup[2]
[1, 3, 8]
my_tup[2] = 'something else'
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
TypeError: 'tuple' object does not support item assignment
my_tup[2][0] = 'new data'
my_tup
(2, 'a string', ['new data', 3, 8])

```

### Tuple modifiability diagram

![tuple diagram](fig/tuple-modifiability.png)

### Tuple-list conversion

```python
days_list = list(days)
days_list
['Su', 'M', 'Tu', 'W', 'Th', 'F', 'Sa']
days_tup = tuple(days_list)
days_tup
('Su', 'M', 'Tu', 'W', 'Th', 'F', 'Sa')

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

```python
ages
{'bruce': 60, 'angelina': 40, 'leo': 40, 'brad': 51}
ages['mike'] = ages['bruce']
del ages['bruce']
ages
{'mike': 60, 'angelina': 40, 'leo': 40, 'brad': 51}

```
