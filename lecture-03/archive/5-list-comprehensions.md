## List comprehensions

It is a common programming task to produce a list whose elements are the
result of a function applied to another list.  For example:

```python
def square(x):
    return x*x

my_list = [1,2,3,4,5,6,7,8]

new_list = []
for x in my_list:
    new_list.append(square(x))

print(new_list)
```

This is so common that Python has special syntax to achieve the same thing:

```python
list_comp = [x*x for x in my_list]
print(list_comp)
```

This is called a [list comprehension][py-list-comp].  It creates a new list by
applying an operation to each item of another list.

[py-list-comp]: https://docs.python.org/3/tutorial/datastructures.html#list-comprehensions

It is also possible to filter out elements of list in a comprehension:

```python
my_list = [1,2,3,4,5,6,7,8,9,10,11]
odds = [x for x in my_list if x % 2 != 0]
odds
```

Python also has [set][so-set-comp] and [dictionary][so-dict-comp]
comprehensions.

[so-set-comp]: http://stackoverflow.com/documentation/python/196/comprehensions/745/set-comprehensions#t=201609141607227980614
[so-dict-comp]: http://stackoverflow.com/documentation/python/196/comprehensions/738/dictionary-comprehensions#t=201609141607227980614

## References

* [List comprehensions in Python Tutorial][py-list-comp]

[py-list-comp]: https://docs.python.org/3/tutorial/datastructures.html#list-comprehensions
