# Lists

A list in Python is a data container that holds multiple objects in a specific
order.

## Creating lists

In Python, lists are created by putting things inside of square brackets (`[]`).

```python
some_primes = [1,2,3,5,7,11]
print(some_primes)
```

Lists can hold objects of any type:

```python
many_types = [1, 55.5, "Am I in a list?", True]
print(many_types)
```

We can get the length of the list with the `len()` functions:

```python
len(many_types)
```

## Accessing Elements

Elements of a list are accessed using square brackets after a variable.

```python
myList = [5, 2.3, 'hello']
```

The first element of a list is at index `0`:

```python
myList[0]
```

```python
myList[2]
```

Attempting to access an element out of bounds will produce an error:

```python
myList[3]
```

We can index to `-1` to get the object at the end of the list:

```python
myList[-1]
```

Likewise, we can index backwards using negative numbers:

```python
myList[-3]
```

## Slicing

A sub-list may be accessed using slice syntax.  Let's start with the list:

```python
many_types = [1, 55.5, "Am I in a list?", True, "the end"]
```

Let's look at a sub-list:

```python
many_types[2:4]
```

The `[2:4]` is called a slice and returns a list with elements at indices 2 and
3 from the original list.

It is easy to slice from an index to the end:

```python
many_types[2:]
```

It is also easy to slice from the beginning to a specified index:

```python
many_types[:3]
```

## Adding and multiplying

The `+` operator concatenates (or combines) lists:

```python
myList = [5, 2.3, 'hello']
mySecondList = ['a', '3']
concatList = myList + mySecondList
print(concatList)
```

The `*` operator can be used to repeat lists:

```python
myList = ['hello', 'world']
print(myList * 2)
print(2 * myList)
```

## Lists are mutable

Lists are mutable, this means that individual elements can be changed.

```python
# start with a list
my_list = ['a', 43, 1.234]
# assign a new value to index 0
my_list[0] = -3
# inspect the list
print(my_list)
```

We can also assign to a slice

```python
x = 2
my_list[1:3] = [x, 2.3]
print(my_list)
```

## Copying a list

Let's attempt to copy a list referenced by variable `a` to another variable `b`:

```python
a = ['a', 'b', 'c']
b = a # attempt to copy a to b
b[1] = 1 # now we want to change an element in b
print(b)
print(a)
```

That's interesting!  Modifying `b` caused `a` to change.

Let's look at this example in [Python Tutor][pytut-list].

[pytut-list]: http://pythontutor.com/iframe-embed.html#code=a+%3D+%5B'a',+'b',+'c'%5D%0Ab+%3D+a+%23+attempt+to+copy+a+to+b%0Ab%5B1%5D+%3D+1+%23+now+we+want+to+change+an+element+in+b%0Aprint(b%29%0Aprint(a%29%0A&origin=opt-frontend.js&cumulative=false&heapPrimitives=false&textReferences=false&py=3&rawInputLstJSON=%5B%5D&curInstr=0&codeDivWidth=350&codeDivHeight=400

Ok, let's try a different technique.

```python
a = ['a', 'b', 'c']
b = a       # first attempt to copy a to b
c = list(a) # use the list constructor
b[1] = 1    # now we want to change an element in b
print("a: ", a)
print("b: ", b)
print("c: ", c)
print("id(a): ", id(a))
print("id(b): ", id(b))
print("id(c): ", id(c))
```

Again, let's try this example in [Python Tutor][pytut-copy].

[pytut-copy]: http://pythontutor.com/iframe-embed.html#code=a+%3D+%5B'a',+'b',+'c'%5D%0Ab+%3D+a+++++++%23+first+attempt+to+copy+a+to+b%0Ac+%3D+list(a%29+%23+use+the+list+constructor%0Ab%5B1%5D+%3D+1++++%23+now+we+want+to+change+an+element+in+b&origin=opt-frontend.js&cumulative=false&heapPrimitives=false&textReferences=false&py=3&rawInputLstJSON=%5B%5D&curInstr=0&codeDivWidth=350&codeDivHeight=400

A list can be copied with `b = list(a)` or `b = a[:]`.  The second option is a
slice including all elements.

## List operations

In the following summary, `s` is a list and `x` is an element.

* `x in s`: `True` if an item of `s` is equal to `x`, else `False`
* `x not in s`: `False` if an item of `s` is equal to `x`, else `True`
* `s + t`: the concatenation of `s` and `t`
* `s * n` or `n * s`: equivalent to adding `s` to itself `n` times
* `s[i]`: `i`th item of `s`, origin `0`
* `s[i:j]`: slice of `s` from `i` to `j`
* `s[i:j:k]`: slice of s from `i` to `j` with step `k`
* `len(s)`: length of `s`
* `min(s)`: smallest item of `s`
* `max(s)`: largest item of `s`
* `s.index(x)`: index of the first occurrence of `x` in `s`
* `s.count(x)`: total number of occurrences of `x` in `s`
* `s[i] = x`: item `i` of `s` is replaced by `x`
* `s[i:j] = t`: slice of `s` from `i` to `j` is replaced by the contents of the `t`
* `del s[i:j]`: same as `s[i:j] = []`
* `s[i:j:k] = t`: the elements of `s[i:j:k]` are replaced by those of `t`
* `del s[i:j:k]`: removes the elements of `s[i:j:k]` from the list
* `s.append(x)`: appends `x` to the end of the sequence (same as `s[len(s):len(s)] = [x]`)
* `s.clear()`: removes all items from `s` (same as `del s[:]`)
* `s.copy()`: creates a shallow copy of `s` (same as `s[:]`)
* `s.extend(t) or s += t`: extends `s` with the contents of `t` (for the most part the same as `s[len(s):len(s)] = t`)
* `s *= n`: updates `s` with its contents repeated `n` times
* `s.insert(i, x)`: inserts `x` into `s` at the index given by `i` (same as `s[i:i] = [x]`)
* `s.pop([i])`: retrieves the item at `i` and also removes it from `s`
* `s.remove(x)`: remove the first item from `s` where `s[i] == x`
* `s.reverse()`: reverses the items of `s` in place

Also have a look at:

```python
help(list)
```

## Looping over elements

It is very easy to loop over elements of a list using `for`, we have seen this
before using `range`.

```python
someIntegers = [1, 3, 10]
for integer in someIntegers:
    print(integer)
```

Using `enumerate`, we can loop over both elements and indices at the same time.

```python
myList = [1, 2, 4]
for index, elem in enumerate(myList):
    print("{0}) {1}".format(index, elem))
```

## `map`

We can apply a function to all elements of a list using `map` and return the
result in a new object.

```python
list_1 = [1, 2, 3, 4, 5, 6]
list_2 = map(lambda x: x*x*x, list_1)
print("list_2: ", list_2)
print("list_2: ", list(list_2))
```

## `filter`

We can also filter elements of a list using `filter`.

```python
list_1 = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
list_2 = filter(lambda x: x % 2 == 0, list_1)
print("list_2: ", list_2)
print("list_2: ", (list_2))
```

## List comprehensions

A very powerful and concise way to create lists is using *list comprehensions*.

```python
list_1 = [0, 1, 2, 3, 4]
list_2 = [x**2 for x in list_1]
print("list_2: ", list_2)
```

This is often more readable than using `map` or `filter`.

## Resources

* Python tutorial section on [`list`][pydoc-lists]
* Python reference section on [sequences][pydoc-sequences]

[pydoc-lists]: https://docs.python.org/3/tutorial/introduction.html#lists
[pydoc-sequences]: https://docs.python.org/3/library/stdtypes.html#sequence-types-list-tuple-range
