TODO: make sure this content is covered somewhere

## Looping

```python
for i in range(5):
    # loop body
    print(i)
```

## Note on Python syntax

Python uses syntatic indenting.  This means that indenting code has a meaning in
the programming language.  In languages like C, C++, and Java, loop bodies are
enclosed in braces, but good coding style suggests that statements in a loop or
conditional body are indented:

```
for (int i = 0; i < 10; i++) {
    printf("i = %d\n",i);
}
```

Python takes this a step further and requires the indenting of loop and
conditional bodies.  We recommend that you use 4 spaces to indent python code
([so does the python community](https://www.python.org/dev/peps/pep-0008/#tabs-or-spaces)).
Please tell your text editors to insert spaces instead of tab characters when
you hit the tab key on the keyboard.

## `for` loop 	

* The function `range(n)` returns a `range` object allowing us to iterate over
  integers `0` to `n-1`

```python
range(6)
```

* The `for i in <sequence>:` can be interpreted as doing the following:
    * assign the loop counter, `i`, the first value in `<sequence>`
    * execute the body of the loop
    * assign the loop counter variable the next value in the sequence and repeat

## `range()`

The `range()` function can be used in a few different ways.  We can convert
a range object to a python list with the `list()` function:

```python
print(list(range(7)))
print(list(range(4,11)))
print(list(range(4,16,3)))
```

## Summing numbers

```python
summation = 0
for n in range(1,101):
    summation += n

print(summation)
```
## `while` loop 	

* The `for` loop is associated with executing a loop body a known number of
  times

* What if we’re unsure how many times we’ll need to execute the loop?

```python
n = 0
while n < 7:
    print(n)
    n = n + 1
```

## Infinite loops

```
while True:
    pass
```

* In Jupyter Notebook, select "Interrupt" from the Kernel menu
* Use `ctrl-c` to interrupt the interpreter

## Nesting loops 	

```python
for i in range(5):
    for j in range(i):
        print(j,end=" ")
    print()
```

## Nesting loops and logic

```python
for i in range(8):
    for j in range(i):
        print(j, end=' ')
    print()
```

## `continue`

The `continue` statement allows you to skip the remainder of a loop body and
continue with the next iteration:

```python
for n in range(10):
    if not 3 < n < 7:
        continue
    print(n)
```

## `break`

The `break` statement allows one to immediately exit from a `for` or `while`
loop

```python
for n in range(10):
    if n > 3:
        break
    print(n)
```

## Innermost loop

`continue` and `break` only apply to the innermost loop being executed:

```python
for i in range(2):
    print("i = {}".format(i))
    for j in range(2):
        break
        print("j = {}".format(j))
        for k in range(2):
            print("k = {}".format(k))
```

## Loop `else`

* An `else` can be used with a `for` or `while` loop

* The `else` is only executed if the loop runs to completion, not when a `break`
statement is executed

```python
for i in range(4):
    print(i)
else:
    print("all done")
```

```python
for i in range(7):
    print(i)
    if i > 3:
        break
else:
    print("all done")
```
