## `for` loops

Very often, one wants to repeat some action. This can be achieved by a `for`
loop:

```python
for i in range(5):
    print(i**2, end=', ')
print() # print a new line at the end
```

Here, `for i in range(n):` will execute the loop body `n` times with `i = 0, 1,
2, ..., n - 1` in succession.

## `while` loops

When we do not know how many iterations are needed, we can use `while`.

```python
i = 2
while i < 100:
    print(i**2,end=", ")
    i = i**2
print() # print a new line at the end
```

## `continue`

`continue` continues with the next iteration of the smallest enclosing loop:

```python
for num in range(2, 10):
    if num % 2 == 0:
        print("Found an even number:", num)
        continue
    print("Found an odd number:", num)
```

Here, `num in range(2,10)` sets up a loop where `num = 2, 3, ..., 9`.

## `break`

The `break` statement allows us to jump out of the smallest enclosing `for` or
`while` loop.

Finding prime numbers:

```python
max_n = 10
for n in range(2, max_n):
    for x in range(2, n):
        if n % x == 0: # n divisible by x
            print(n, 'equals', x, '*', n/x)
            break
    else: # executed if no break in for loop
        # loop fell through without finding a factor
        print(n, 'is a prime number')
```

## `pass`

The `pass` statement does nothing, which can come in handy when you are working
on something and want to implement some part of your code later.

```python
if traffic_light == 'green':
    pass # to implement later
else:
    print('whatever you do, stop the car!')
```
