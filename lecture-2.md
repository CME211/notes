# CME 211 Lecture 2: Introduction to Python

## Python

* Python is a high level language that runs in an *interpreter*
* An *interpreter* is a program (see `$ python`) that executes statements from a
  high level language
* Examples of high level interpreted languages: Python, R, Matlab, Perl,
  JavaScript
* The most widely used Python interpreter is called **CPython**.  It is written
  in C.  There are others, for example **Jython** and **IronPython**.  It is
  fairly easy (with experience) to access code written in C from **CPython**.
* Python now has a long history.  Version 1.0 was released in 1994.
* This class will use Python 2.  However, we will use the syntax most compatible
  with Python 3 and discuss differences along the way.

## Let's get started

### We need to log into `corn.stanford.edu`

Open `Terminal.app` on Max OS X.  Execute the following:

```
[nwh@icme-nwh cme211-notes] $ ssh nwh@corn.stanford.edu
Warning: Permanently added the RSA host key for IP address '171.67.216.95' to the list of known hosts.
nwh@corn.stanford.edu's password: 
Authenticated with partial success.
Duo two-factor login for nwh

Enter a passcode or select one of the following options:

 1. Duo Push to XXX-XXX-2441
 2. Phone call to XXX-XXX-2441
 3. SMS passcodes to XXX-XXX-2441

Passcode or option (1-3): 1
Success. Logging you in...
Welcome to Ubuntu 14.04.2 LTS (GNU/Linux 3.13.0-45-generic x86_64)

 * Documentation:  https://help.ubuntu.com/
corn30.stanford.edu - Ubuntu 14.04.2 LTS, amd64
8-core Opteron 2384 (SB X6240); 31.42GB RAM, 10GB swap
Puppet environment: rec_test3; kernel 3.13.0-45-generic (x86_64)
 --*-*- Stanford University Research Computing -*-*--

  _____                    ____  _
 |  ___|_ _ _ __ _ __ ___ / ___|| |__   __ _ _ __ ___
 | |_ / _` | '__| '_ ` _ \\___ \| '_ \ / _` | '__/ _ \
 |  _| (_| | |  | | | | | |___) | | | | (_| | | |  __/
 |_|  \__,_|_|  |_| |_| |_|____/|_| |_|\__,_|_|  \___|


    http://farmshare.stanford.edu

 ###########################################################################
 #						                           #
 # Welcome to Farmshare! We recommend Mac and Linux users add the          #
 # following lines to their local laptop/desktop .ssh/config file to avoid #
 # having to use Duo two-factor every time you connect to a corn machine.  #
 #									   #
 # Host corn corn?? corn.stanford.edu corn??.stanford.edu		   #
 #  ControlMaster auto							   #
 #  ControlPath ~/.ssh/%r@%h:%p						   #
 #  ControlPersist yes							   #
 #									   #
 # This will open an ssh tunnel that will be shared on subsequent          #
 # connections to the same node and allow you to avoid having to manually  # 
 # authenticate again.							   #
 #									   #
 ###########################################################################

	Don't Forget to sign up for the Farmshare mailing list to stay 
	informed about upgrades, maintenace, FAQ, and downtime. 
	https://mailman.stanford.edu/mailman/listinfo/farmshare-discuss


nwh@corn30:~$ 
```

### Hello world!

1. see where `python` executable (program) is located with the `which` command
2. launch the `python` interpreter

```
nwh@corn30:~$ which python
/usr/bin/python
nwh@corn30:~$ python
Python 2.7.6 (default, Mar 22 2014, 22:59:56) 
[GCC 4.8.2] on linux2
Type "help", "copyright", "credits" or "license" for more information.
>>> print("Hello CME 211, how are you today?")
Hello CME 211, how are you today?
>>> 
```

### Some notes

When you see a `$` in quoted code, it typically indicates a shell command.  For
example:

```
nwh@corn30:~$ ls
Downloads  bin	    config  gurobi.log	projects  tmp
WWW	   cme213b  cs107   jobs	test.txt  work
nwh@corn30:~$ 
```

The `nwh@corn30:~$ ls` means that I've executed the `ls` command in the shell
program (Bash).  Sometimes, I will simplify the output to:

```
$ ls
Downloads  bin	    config  gurobi.log	projects  tmp
WWW	   cme213b  cs107   jobs	test.txt  work
$ 
```

This just removes the username, server name, and directory path from the command
line prompt.  Note that the `ls` command lists the files and directories
contained in the "working directory".  The "working directory" is where your
shell is currently focued.  To see what your "working directory" is:

```
$ pwd
/afs/ir/users/n/w/nwh
```

### Python as a calculator

The Python interpreter uses `>>>` as a command prompt (by default).  It is often
useful to use the Python interpreter as a simple calculator:

```
>>> 4+7
11
>>> 55*2
110
>>> 9-1.4
7.6
>>> 2/4
0
>>> 2//4
0
>>> 2.0/4
0.5
>>> 2.0//4
0.0
>>> 
```

## Integers and floating point

In CME 212, we will discuss in detail the computer representation of integers
and floating point numbers.  For now:

- It is best to think of integers as being represented exactly over a fixed
  range.  (This is not really true in current versions of Python, but will be
  true in C++)

- Floating point numbers are *approximations* of real numbers over a limited
  range.

- Floating point number range is not continuous.  There are gaps between
  floating point numbers that depend on the scale.  The gap between `1.0` and
  the next representable floating point number is smaller than the gap between
  `1.0e50` and the next representable floating point number.

- These things matter and bad numerical computing has resulted in a number of
  disasters: https://www.ima.umn.edu/~arnold/disasters/

### Some more examples

```
>>> 1.0
1.0
>>> 3/5
0
>>> 3./5
0.6
>>> 3/5.
0.6
>>> 3%5
3
>>> 
```

The `%` operator is called the *modulus* operator and returns the remainder for
integer division.

## More math

If you are familiar with Matlab, you may come to Python and be confused by:

```
>>> sqrt(3)
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
NameError: name 'sqrt' is not defined
>>> 
```

The Python languange does not have a built in `sqrt` function.  `sqrt` exists in
the Python `math` module:

```python
>>> import math
>>> math.sqrt(9)
3.0
```

## Modules

* A module is a collection of Python resources (functions, variables, objects,
  classes) that can be easily loaded into Python via `import` statements

* Modules allow for easy code reuse and organization

* Modules allow the programmer to keep various functionality in different
  namespaces.

* There are a large number of modules in the Python Standard Library:
  https://docs.python.org/2/library/index.html

* It is often useful to explore the Python documentation in the interpreter:

```py
>>> import math
>>> help(math)
# pager opened
>>> help(math.sqrt)
# pager opened
```
