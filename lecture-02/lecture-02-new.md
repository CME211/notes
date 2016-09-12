# CME 211 Lecture 2: Introduction to Python

* Python is a high level language that runs in an *interpreter*
* An *interpreter* is a program (see `$ python`) that executes statements from a
  high level language
* Examples of high level interpreted languages: Python, R, Matlab, Perl,
  JavaScript
* The most widely used Python interpreter is called **CPython**.  It is written
  in C.  There are others, for example **Jython** and **IronPython**.  It is
  fairly easy (with experience) to access code written in C from **CPython**.
* Python now has a long history.  Version 1.0 was released in 1994.
* This class will use Python 3.  However, we will discuss important differences
  from Python 2 as we go along.

## Getting started

To get started, let's log into `corn.stanford.edu`, start the Python 3
interpreter, and execute some Python commands.  Please review the Lecture 0
notes if any of the following is unfamiliar.

1. Use SSH to login with `$ ssh [username]@corn.stanford.edu`
2. Locate the Python 3 interpreter with `$ which python3`
3. Run the Python 3 interpreter with `$ python3`
4. Execute the python statement `print("Hello World!")`

### Interpreter

* An *interpreter* is a program that reads and executes commands
* It is also sometimes called a REPL or read-evaluate-print-loop
* One way to interact with Python is to use the interpreter
* This is useful for interactive work, learning, and simple testing
* When you see a `$` in code blocks, it typically indicates a shell command.  For
  example:
```
$ ls
Downloads  bin	    config  gurobi.log	projects  tmp
WWW	   cme213b  cs107   jobs	test.txt  work
$
```
* When you see a `>>>` in code blocks, it typically indicates a command for the
  Python interpreter
* The basic Python interpreter is good for very simple computations or tests.
  [IPython][ipython] provides a lot more functionality (like tab completion and
  syntax highlighting), try `$ ipython3` at the command line

[ipython]: https://ipython.org/

### Python as a calculator

In the Python 3 interpreter:

```
>>> 4+7
11
>>> 55*2
110
>>> 9-1.4
7.6
>>> 5/3
1.6666666666666667
>>> 5//3
1
>>> -5//3
-2
>>> 5.0/3
1.6666666666666667
>>> 5.0//3
1.0
```

### Jupyter notebook

Jupyter Notebooks are great for teaching and interactive work.  From the
[jupyter.org][jupyter] website:

> The Jupyter Notebook is a web application that allows you to create and share
> documents that contain live code, equations, visualizations and explanatory
> text. Uses include: data cleaning and transformation, numerical simulation,
> statistical modeling, machine learning and much more.

[jupyter]: http://jupyter.org/

In Jupyter Notebook, code is typed into code blocks:

```python
print("hello from a code block!")
```

Code blocks can be re-executed with ease!

You can test Jupyter Notebook in your browser via <https://try.jupyter.org/>.
Note that any work you do here will not be saved.

If you want to install Jupyter Notebook on your computer, I recommend [Anaconda
Python][anaconda].  Make sure to install the Python 3.5 version.

[anaconda]: https://www.continuum.io/downloads

CME211 Notes:
* We do not formally support Jupyter Notebook.  I show it to the class, because
  it is a very useful tool.  You are responsible for figuring out how to install
  and run Jupyter Notebook.  There are plenty of good tutorials online.
* The teaching staff is not responsible for helping you set up Jupyter Notebook
  on your computer.  Python 3 on `corn.stanford.edu` is the supported computing
  environment.
* All Python work for CME211 must be submitted as Python scripts (`.py` files)
  that can be executed via the command line.  We will not accept or grade any
  work submitted as a notebook (`.ipynb` format).
* The notes for CME211 are written in [Markdown format][markdown] and [converted
  to Jupyter notebooks][notedown] for lectures and screencasts.
  [`nbconvert`][nbconvert] is used to create PDFs.

[markdown]: http://commonmark.org/
[notedown]: https://github.com/aaren/notedown
[nbconvert]: http://nbconvert.readthedocs.io/en/latest/

### Looking ahead with Jupyter Notebooks

Jupyter notebook is a very useful tool for scientific computing.  If you have a
background with Matlab, the following may help you get started working with
Python and NumPy.

Start by importing modules:

```python
# for 2d plotting
import matplotlib.pyplot as plt
# for numerical computing
import numpy as np
```

Configure plotting for notebook:

```python
# tell matplotlib to use the notebook for figures
%matplotlib notebook
# tell matplotlib to use svg (they look better than png)
%config InlineBackend.figure_format = 'svg'
```

Note: in Jupyter notebook, statements that start with `%` are known as [magic
commands][ipy-magic].

[ipy-magic]: http://ipython.readthedocs.io/en/stable/interactive/magics.html

A simple plot of 100 random sampled data points:

```
plt.plot(np.random.rand(100))
```

Have a look at the ["NumPy for MATLAB Users"][numpy-matlab] reference.  Note
that you will have to prefix NumPy function calls from the reference with `np.`
based on the import statements above.

[numpy-matlab]: http://mathesaurus.sourceforge.net/matlab-numpy.html

It may also be a good idea to skim the following:
* [NumPy reference](http://docs.scipy.org/doc/numpy/reference/)
* [SciPy reference](http://docs.scipy.org/doc/scipy/reference/)

### Python scripts

### Python modules

## Values, variables, and types

## More on Python 3 strings

## Introduction to looping
