# Python File Input-Output (IO)

Python makes it very easy to read and write files to disk.

Keep in mind that it is almost always better to use a Python module for specific
formats.  For example, use the [`json`][pyref-json] module for JSON files or the
[`csv`][pyref-csv] module for `.csv` files.  Better yet, use [Pandas][pandas]
for table-like data.

[pyref-json]: https://docs.python.org/3/library/json.html
[pyref-csv]: https://docs.python.org/3/library/csv.html
[pandas]: http://pandas.pydata.org/

## What is a file?

A *file* is a segment of data, typically associated with a filename, that exists
in a computer's persistent storage.  This means that the data remains when the
computer is turned off.

There are two main kinds of files: *text* and *binary*.

Text files are easy for humans to read and write.

Binary files (images, music files, etc.) are more efficient in terms of storage.

## The file object

* Interaction with the file system is pretty straightforward in Python.
* Done using *file objects*
* We can instantiate a file object using `open` or `file`

## Opening a file

```
f = open(filename, option)
```

* `filename`: path to file on disk
* `option`: mode to open file (passed as a string)
  * `'r'`: read file
  * `'w'`: write to file (overwrites existing file)
  * `'a'`: append to file
* We need to close a file after we are done: `f.close()`

## `with open() as f:`

It is good practice to use the `with` keyword when dealing with file objects.
This has the advantage that the file is properly closed after its suite
finishes, even if an exception is raised on the way.

```python
with open('07-data/text_file.txt', 'r') as f:
    print(f.read())
```

```python
f.closed
```

## Reading a file

File object methods:

* `read()`: Read entire file (or first `n` characters, if supplied)
* `readline()`: Reads a single line per call
* `readlines()`: Returns a list with lines (splits at newline)

Another fast option to read a file:

```python
with open('07-data/text_file.txt', 'r') as f:
    for i, line in enumerate(f):
        print("line", i, ":", line, end="")
```

Note that the line string in the loop includes the newline character (`"\n"`) at
the end.

## Writing to file

Use the `write()` method to write to a file.

```python
name = "Python learner"
with open('07-data/hello.txt', 'w') as f:
    f.write("Hello, {}!\n".format(name))
```

## More writing examples

Write elements of list to file:

```python
xs = ["i", "am", 'a', 'fancy', 'list', 42]
with open('07-data/from_list.txt', 'w') as f:
    for x in xs:
        f.write('{}\n'.format(x))
```

Write elements of dictionary to file:

```python
d = {"name": "Peter Pan", "job": "lost boy", "location": "Neverland"}
with open('07-data/from_dict.txt', 'w') as f:
    for k, v in d.items():
        f.write('{}: {}\n'.format(k, v))
```

## JSON

The JSON format is commonly used by modern applications to allow for data
exchange. Many programmers are already familiar with it, which makes it a good
choice for interoperability.

```python
json.dumps([1, 'simple', 'list'])
```

```python
d = {"name": "Peter Pan", "job": "lost boy", "location": "Neverland"}
json.dumps({})
```

See:

* [JSON in Python Tutorial](https://docs.python.org/3/tutorial/inputoutput.html#saving-structured-data-with-json)
* <http://www.json.org/>
