TODO: clear out this file

### Dictionaries

**Associative container** store data, organized by a unique *key*.  Think of a
dictionary of word definitions.  They unique *key* is a word, the value
associated with the key is the definition.  In Python, this is represented with
the built-in `dict` or Dictionary type.  You will soon learn the greatness of
dictionaries in Python.

```python
emails = dict()
emails['andreas'] = 'andreas@mail.com'
emails['nick'] = 'nwh@stanford.net'
print(emails)
```

Access a single element:

```python
emails['nick']
```

What if a key is not there?

```python
emails['cindy']
```

### Sets

**Set containers** store unique data items.  They are related to dictionaries,
because dictionaries require the keys to be unique.

```python
dinos = set()
dinos.add('triceratops')
dinos.add('t-rex')
dinos.add('raptor')
print(dinos)
dinos.add('pterodactyl')
dinos.add('t-rex')
print(dinos)
```



## File input output

Files are one way to get data into Python for process and out of python for
saving or sending (over a network).  In CME 211, we will mostly work with text
files.  This set of lecture notes is written in a text file `lecture-3.md` in
[Markdown format](https://daringfireball.net/projects/markdown/).  As a
side note, Markdown is a format that makes it easy to write text and convert it
to other formats.  If you are viewing this file via GitHub, you will likely be
looking at an HTML render of the file.  Python scripts are text files and by
convention have a `.py` extension.  On unix systems we can dump a text file to
the terminal with:

```
$ cat hello.py
# run me from the command line with
# $ python hello.py

print("hello sweet world!")
```

For run, try dumping a binary file to the terminal with `$ cat /bin/ls`.  What
happens?

In Python it is very easy to open, read from, and write to a text file.  Let's
see how it works.

See Chapter 9 in **Learning Python** for information on accessing files with
Python.  The relevant information starts on page 282.

### Open a file

We open a file with the built-in `open` function:

```python
f = open("humpty-dumpty.txt","r")
f
```

The syntax is `open(filename,mode)` where `filename` is a string with the
filename to open and `mode` is the mode to open the file.  For now, the mode
should be `'r'` for reading a file and `'w'` for writing a file.  The `open`
function returns a *file object*, which we will use to read and write data.

Note what happens if you try to open a file that does not exist:

```python
bad_file = open("no-file.txt","r")
```

### Reading from files

Use the `readline()` method to read lines from a file:

```python
f = open("humpty-dumpty.txt","r")
print(f.readline())
print(f.readline())
f.close()
```

It is always a good idea to close a file when you are done with it.  *We will
take off points if you neglect to do this.*

You can read an entire file at once with the `read()` method:

```python
f = open("humpty-dumpty.txt","r")
poem = f.read()
print(poem)
f.close()
```

You can very easily iterate over lines in a file with:

```python
f = open("humpty-dumpty.txt","r")
for line in f:
    print(line)
f.close()
```

Note, on your own, try to suppress the extra newline character generated.  You
can do this by specifying the `end` keyword parameter for the `print` function
to be an empty string (`""`): `print(line, end='')` or slicing `line` with
`print(line[:-1])`.  Note that `line` is a variable name.

Let's say we wanted to process all words in a file.  The following example would
get us started:

```python
f = open("humpty-dumpty.txt","r")
for line in f:
    for word in line.split():
        # use strip() method to remove extra newline characters
        print(word.strip())
f.close()
```

### Writing to files

To open a file for writing and write a single line:

```python
f = open("output.txt","w")
f.write("blah blah blah\n")
f.close()
exit()
```

```
$ cat output.txt
blah blah blah
```

Note that the `write` method will not insert a newline character.  To get a new
line, you must add `'\n'` in the string that is passed to `write`.

To write multiple lines to a file at once, use the `writelines` method:

```python
f = open("output.txt","w")
f.writelines(["a mighty fine day\n","ends with a great big party\n","thank you, its friday\n"])
f.close()
```

```
$ cat output.txt
a mighty fine day
ends with a great big party
thank you, its friday
```

Note, the `\n` is still required in the strings that make up the list passed to
`writelines`.  The `"w"` file mode will overwrite the file you open, deleting
all of the old data.  Be careful!  If you would like to append to an existing
file use the `"a"` mode.

### Buffering

Be mindful of file buffering.  We will see a demo in class.
