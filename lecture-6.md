# CME 211: Lecture 6

Friday, October 2, 2015

## Announcements

* CUDA on Campus Day
<http://icme.stanford.edu/events/nvidia-tech-talks-and-hands-labs>

* Homework 1 was due today at 2:30pm

* Homework 2 is out today, due next Friday @ 2:30pm

## Version control with `git`

In CME 211 and CME 212 we will be using Git for version control and homework
submission.  This is an important practice with a good and widely used tool.

### Version control

Today version control systems (like `git`) formally enable the following:

* periodic saving of work (called *committing*)

* returning to old versions when a problem is introduced

* creation of experimental code *branches* with out disturbing the main or
  working code

* *merging* of concurrent work of independent developers

* *remote* backup and storage of work 

* tracking a *log* of project history

* and more

The importance and utility of version control systems really only become clear
when you experience the frustration (or fear) when dealing with large software
projects.  They are useful even when working alone on a project.  It is
important to make periodic commits and then return to one if a breaking change
is introduced into the code.  Version control systems are absolutely essential
when working on a project involving more than one developer.  Merging changes
from two developers into a single codebase by hand is difficult, time consuming,
and error prone.

There are many tools currently in use for version control.  Here are some of the
names:

* **CVS**: Concurrent Versioning System
* **SVN**: Subversion
* **HG**: Mercurial
* **Git**

All of these tools share commonality.  If you learn one, you will be able to
apply that knowledge to other tools.  Today, Git is very popular with open
source projects.

**Note:** version control software is a tool.  Like all powerful tools, it must
  be learned and used properly.  In CME 211 we will learn the very basics of
  Git.

### `git`

Git is one of the most widely used version control systems in both industry,
academia, and elsewhere. It was created in 2005 by Linus Torvalds (the same guy
who started and continues to develop the Linux kernel).  Before 2005, the Linux
kernel developers were using a proprietary version control system called
BitKeeper.  The owner of BitKeeper withheld free access to the software, so the
kernel developers needed to come up with something.  Linus wrote Git to meet the
demanding needs of the Linux kernel project.  The result of this is an excellent
tool for any project dealing with large amounts of text.

**Note:** If you are working on any large project, see if you can work on it in
  a way where the primary thing you create is text.  Then your work can be put
  in a version control system and effectively managed.  Version control is
  reason enough to work in plain text.

In CME 211 we are going to learn the following aspects in Git:

* Creating new *repositories* (or *repo*) locally and on GitHub (see next section)

* Adding files to a repository

* *Committing* file changes to a repository

* Inspecting the history or *log* of a project

* Moving back to a previous *commit*

* *Pushing* to and *pulling* from a *remote* repository 

Git is capable of so much more.  These basic use cases are sufficient for
CME 211.  You  will likely want to learn more for your own work.

### GitHub

GitHub is a webservice that allows the storage, browsing, and updating of Git
repositories online.  There are other web services, like
[BitBucket](https://bitbucket.org/), that do the same thing.  GitHub is quite
popular with many open source projects.  I use it everyday.  Make sure to get
the academic discount so that you have have private repositories.

### Git resources

* Git homepage: <http://git-scm.com/>

* Git documentation: <http://git-scm.com/doc>

* Git Book: <http://git-scm.com/book/en/v2>

Recommended reading: Git Book chapters 1 and 2

### Tutorial introduction

These instructions are going to be rather sparse.  Please follow along in class
or visit office hours for more assistance.

#### Setting up `git`

First, we need to tell `git` who we are.  This information will show up in the
history log.

1. log into `corn.stanford.edu`

2. enter the following commands to introduce yourself to `git`

```
$ git config --global user.name "Your name"
$ git config --global user.email your@email.com
```

Please use the email address associated with your GitHub account.  For example,
I would do this:

```
$ git config --global user.name "Nick Henderson"
$ git config --global user.email nwh@stanford.edu
```

This creates a file `~/.gitconfig` with the following contents:

```
$ cat ~/.gitconfig 
[user]
	name = Nick Henderson
	email = nwh@stanford.edu
```

The `~/.gitconfig` file holds a bunch of configuration settings for `git`.

#### Creating a local repo

Follow along with the following steps:

```
nwh@corn25:~$ cd CME211
nwh@corn25:~/CME211$ ls
hw1  lec5  nwh-submit
nwh@corn25:~/CME211$ mkdir test-repo
nwh@corn25:~/CME211$ cd test-repo/
nwh@corn25:~/CME211/test-repo$ git init .
Initialized empty Git repository in /afs/ir.stanford.edu/users/n/w/nwh/CME211/test-repo/.git/
nwh@corn25:~/CME211/test-repo$
```

#### Adding a file

Let's create a text file and add it to the repo:

```
nwh@corn25:~/CME211/test-repo$ emacs awesome_code.py 
nwh@corn25:~/CME211/test-repo$ cat awesome_code.py 
print("oh my gosh, python is so cool")
nwh@corn25:~/CME211/test-repo$ python awesome_code.py 
oh my gosh, python is so cool
nwh@corn25:~/CME211/test-repo$ git add awesome_code.py 
nwh@corn25:~/CME211/test-repo$ git status 
On branch master

Initial commit

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)

	new file:   awesome_code.py

nwh@corn25:~/CME211/test-repo$ git commit -m "initial commit of awesome code"
[master (root-commit) 57f0c86] initial commit of awesome code
 1 file changed, 1 insertion(+)
 create mode 100644 awesome_code.py
nwh@corn25:~/CME211/test-repo$
```

#### Commiting a change to a file

Here we edit the code and commit the change into the repo.

```
nwh@corn25:~/CME211/test-repo$ emacs awesome_code.py 
nwh@corn25:~/CME211/test-repo$ cat awesome_code.py 
print("oh my gosh, python is so cool")
print("but, now I have to learn git and I just want to go home")
nwh@corn25:~/CME211/test-repo$ git status
On branch master
Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git checkout -- <file>..." to discard changes in working directory)

	modified:   awesome_code.py

no changes added to commit (use "git add" and/or "git commit -a")
nwh@corn25:~/CME211/test-repo$ git add awesome_code.py 
nwh@corn25:~/CME211/test-repo$ git commit -m "update awesome code"
[master 7375d75] update awesome code
 1 file changed, 1 insertion(+)
```

#### Viewing the log

The `$ git log` command allows us to look through the repo history:

```
nwh@corn25:~/CME211/test-repo$ git log
commit 7375d755069b11e1d8799e8d4b3cc5e22aceeee4
Author: Nick Henderson <nwh@stanford.edu>
Date:   Fri Oct 2 12:00:02 2015 -0700

    update awesome code

commit 57f0c86582ec5920f71d1382a0b4b25b08cfa65d
Author: Nick Henderson <nwh@stanford.edu>
Date:   Fri Oct 2 11:57:30 2015 -0700

    initial commit of awesome code
nwh@corn25:~/CME211/test-repo$
```

#### Going back in time

We can go back to a previous commit using the `git checkout` command:

```
nwh@corn25:~/CME211/test-repo$ git checkout 57f0c86582ec5920f71d1382a0b4b25b08cfa65d
Note: checking out '57f0c86582ec5920f71d1382a0b4b25b08cfa65d'.

You are in 'detached HEAD' state. You can look around, make experimental
changes and commit them, and you can discard any commits you make in this
state without impacting any branches by performing another checkout.

If you want to create a new branch to retain commits you create, you may
do so (now or later) by using -b with the checkout command again. Example:

  git checkout -b new_branch_name

HEAD is now at 57f0c86... initial commit of awesome code
nwh@corn25:~/CME211/test-repo$ cat awesome_code.py 
print("oh my gosh, python is so cool")
```

The long string that follows `git commit` comes from the commit identifier in
the log.

When you need to go back to the most recent version use `$ git checkout master`:

```
nwh@corn25:~/CME211/test-repo$ git status
HEAD detached at 57f0c86
nothing to commit, working directory clean
nwh@corn25:~/CME211/test-repo$ git checkout master
Previous HEAD position was 57f0c86... initial commit of awesome code
Switched to branch 'master'
nwh@corn25:~/CME211/test-repo$ git status
On branch master
nothing to commit, working directory clean
nwh@corn25:~/CME211/test-repo$
```

`HEAD detached` sounds scary, but you can ignore it for now.

#### Creating a GitHub repo

Walk through a demo in class:

1. create a new repo in GitHub interface
2. clone to `corn.stanford.edu`

#### Syncing with the remote repo

Push local changes to remote:

1. add file on `corn.stanford.edu`
2. commit locally
3. push to GitHub

Pull down remote changes

1. add a new file on GitHub
2. pull changes to `corn.stanford.edu`

## Python functions

* Code we have seen so far has been executed in linear fashion from top to
  bottom, sometimes repeating one or more lines in a loop body

* Functions allow us to:

    * Replace duplicated code with one centralized implementation within a single
      program

    * Reuse code across different programs

    * Easily use code developed by others

    * Develop, test, debug code in isolation from other code

* Analogous to mathematical functions

## Defining a function in Python

Start of
function
definition


Function
(identifier)
name


Function
arguments


>>> def PrintHello(name):
...
print "Hello, %s" % name Function body

... 
>>> PrintHello

<function PrintHello at 0x14d21b8>
>>> PrintHello("CME 211 students")
Hello, CME 211 students
>>> 

32


## Return a value

>>> def summation(a, b):
...
total = 0
...
for n in range(a,b+1):
...
total += n
...
return total
... 
>>> c = summation(1, 100)
>>> c
5050
>>>

33


## Return multiple values

>>> def SummationAndProduct(a,b):
...
total = 0
...
prod = 1
...
for n in range(a,b+1):
...
total += n
...
prod *= n
...
return total, prod
... 
>>> a = SummationAndProduct(1,10)
>>> a
(55, 3628800)
>>> a, b = SummationAndProduct(1,10)
>>> a
55
>>> b
3628800
>>>
34


## Variable scope

>>> total = 42
>>> def summation(a, b):
...
total = 0
Local namespace
...
for n in range(a, b+1):
within the function

...
total += n
...
return total
... 
>>> a = summation(1, 100)
>>> a
5050
>>> total
42
>>> n
Traceback (most recent call last):
File "<stdin>", line 1, in <module>
NameError: name 'n' is not defined
>>> 
35


## Variable scope

>>> total = 0
>>> def summation(a, b):
...
for n in range(a, b+1):
...
total += n
...
return total
... 
>>> a = summation(1, 100)
Traceback (most recent call last):
File "<stdin>", line 1, in <module>
File "<stdin>", line 3, in summation
UnboundLocalError: local variable 'total' referenced before assignment
>>> 


36


## Variable scope

>>> a = ['hi', 'bye']
>>> def func():
...
print a
... 
>>> func()
['hi', 'bye']
>>> 


>>> a = ['hi', 'bye']
>>> def func():
...
a.append('hello')
... 
>>> func()
>>> a
['hi', 'bye', 'hello']
>>> 

>>> a = ['hi', 'bye']
>>> def func():
...
a = 2
... 
>>> func()
>>> a
['hi', 'bye']
>>> 

* You can't redirect the identifier a at global scope and
have it reference some other object


* You can however modify a mutable object

* Not a good programming practice, but an easy
mistake to make in Python


37


## Variable scope

>>> total = 0
>>> def summation(a,b):
Use the identifier total from
...
global total
the global namespace

...
for n in range(a, b+1):
...
total += n
... 
>>> a = summation(1,100)
>>> total
5050
>>> 

Bad, Bad, Bad, Bad, Bad

38


## Order matters

summation() called before definition

def summation(a, b):
sum = 0
for n in range(a, b+1):
sum = sum + n
return sum

a = summation(1, 100)
print a
order1.py

$ python order1.py 
5050
$


a = summation(1, 100)
print a

def summation(a, b):
sum = 0
for n in range(a, b+1):
sum = sum + n
return sum
order2.py

$ python order2.py 
Traceback (most recent call last):
File "order2.py", line 1, in <module>
a = summation(1, 100)
NameError: name 'summation' is not defined
$


39


## Order matters

def sumofsquares(a, b):
total = 0
for n in range(a, b+1):
total += squared(n)
return total

def squared(n):
return n*n

print sumofsquares(1,10)

When/if this function is called, call the
function squared(). squared()
needs to be defined by the time this
function is actually invoked.


order3.py
plegresl@corn16:~/CME211/Lecture06$ python order3.py 
385
plegresl@corn16:~/CME211/Lecture06$ 
40


## Passing convention

increment() cannot
>>> def increment(a): modify the object
...
a = a + 1
referenced by a
... 
>>> b = 2
>>> increment(b)
>>> b
2

41


## Passing convention

DoChores() has a
>>> def DoChores(a):
reference to a mutable
...
a.pop()
object
... 
>>> b = ['feed dog', 'wash dishes']
>>> DoChores(b)
>>> b
['feed dog']
>>> 

42


## Pass by object reference

* Python uses what is sometimes called pass
by object reference when calling functions


* If the reference is to a mutable object (e.g.

lists, dictionaries, etc.), that object might be
modified upon return from the function


* For references to immutable objects (e.g.

numbers, strings), by definition the original
object being referenced cannot be modified

43


## More realistic example


Function definitions


def LoadNameData(femalenames, malenames):
# Creates a dictionary with the name data from the two input files
namedata = {}

f = open(femalenames)
...

return namedata

def EvaluateName(namedata, name):
# Uses the name data to evaluate a name
if name in namedata:
return namedata[name][0]
else:
return 0.5


# Load reference data into a data structure
namedata = LoadNameData('dist.female.first', 'dist.male.first')

# Setup test data
testdata = ['PETER', 'LOIS', 'STEWIE', 'BRIAN', 'MEG', 'CHRIS']

# Try our algorithm
for name in testdata:
print '%s: %s' % (name, EvaluateName(namedata, name))

Code that calls the functions


From names.py
44


## Bad example

def add(a, b):
# I wrote this function because Nick
# is mean and is making us write functions
return a + b

## Python Object Model (if there's time)

## Recommended Reading

From **Learning Python, Fifth Edition** by Mark Lutz

* Chapter 6: The Dynamic Typing Interlude (i.e. references and objects)

* Chapter 16: Function Basics

* Chapter 17: Scopes

* Chapter 18: Arguments
