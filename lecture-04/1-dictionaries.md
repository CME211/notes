## Dictionaries

* Dictionaries are an *associative container*.  They contain *keys* with
  associated *values*

* Dictionaries in Python are denoted by curly braces

  * Create an empty dictionary: `empty_dict = {}` or `empty_dict = dict()`

  * Create a dictionary with some data: `ages = {"brad": 51, "angelina": 40}`

* Values can be any python object: numbers, strings, lists, other dictionaries

* Keys can be any immutable object: numbers, strings, tuples (containing
  immutable data)

* No sense of order in a python dictionary.  When used in a loop, the key-value
  pairs may come out in any order.

* Access values associated with a key with square brackets:
  `value = dictionary[key]`

### Create a dictionary

```python
ages = {} # or ages = dict()
ages['brad'] = 51
ages['angelina'] = 40
ages['leo'] = 40
ages['bruce'] = 60
ages
```

### Access items

```python
ages['leo']
```

When the key does not exist:

```python
ages['helen']
```

Or you can use the `get()` method:

```python
temp = ages.get('brad')
print(temp)
temp = ages.get('helen')
print(temp)
```

### Iteration

Iterate through the keys with:

```python
for key in ages:
    print("{} = {}".format(key,ages[key]))
```

Iterate through key-values pairs with:

```python
for k, v in ages.items():
    print('{} = {}'.format(k,v))
```

**Note**: The above syntax is more efficient in Python 3.  To achieve equivalent
performance in Python 2, it is best to ask for an *iterator* over the
key-value pairs.

```
for k, v in ages.iteritems():
    print('{} = {}'.format(k,v))
```

What does `ages.items()` return?

```python
ages.items()
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
