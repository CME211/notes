## Advanced list operations

TODO: place this material somewhere ... probably after functions

### `map`

We can apply a function to all elements of a list using `map` and return the
result in a new object.

```python
list_1 = [1, 2, 3, 4, 5, 6]
list_2 = map(lambda x: x*x*x, list_1)
print("list_2: ", list_2)
print("list_2: ", list(list_2))
```

### `filter`

We can also filter elements of a list using `filter`.

```python
list_1 = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
list_2 = filter(lambda x: x % 2 == 0, list_1)
print("list_2: ", list_2)
print("list_2: ", (list_2))
```

### List comprehensions

A very powerful and concise way to create lists is using *list comprehensions*.

```python
list_1 = [0, 1, 2, 3, 4]
list_2 = [x**2 for x in list_1]
print("list_2: ", list_2)
```

This is often more readable than using `map` or `filter`.
