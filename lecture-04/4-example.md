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

See `code/name1a.py`:

```python
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
names
['PETER', 'LOIS', 'STEWIE', 'BRIAN', 'MEG', 'CHRIS']
len(male)
1219
len(female)
4275

```

### Using lists

See `code/name1b.py`

```python
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

See `code/name2.py`:

```python
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
