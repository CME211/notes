# CME 211: Lecture 13

Monday, October 19, 2015

Topics: Introduction to LaTeX

## LaTeX

* LaTeX is a document markup language

* HTML is also a document markup language targeting web browsers

* LaTeX targets high quality print documents

* LaTeX commands are also now used to typeset equations on the web

![fig](fig/markup.png)

## How to obtain

* Windows: <http://miktex.org/about>

* Mac OSX: <https://tug.org/mactex/>

* Ubuntu: `$ sudo apt-get install texlive`

* Fedora: `$ sudo yum install texlive-scheme-medium`

Note: on Linux distributions, you may have to install other `texlive` packages
to get the full TeXLive distribution.  Ubuntu has the package `texlive-full`.
Fedora has the package collection `texlive-scheme-full`.  These are large
downloads.  Be prepared to wait.  Don't install TeX at the last moment!

TeXLive is installed on `corn.stanford.edu`.  The primary access point for CME
211 will be the command line program `pdflatex`.

### Equations in LaTeX

![fig](fig/equation.png)

### Hello world

See: `tex/hello.tex`:

```
\documentclass{article}
\begin{document}
Hello
\end{document}
```

Typesetting instructions (from this directory):

```
$ cd tex
$ pdflatex hello.tex
```

This creates `hello.pdf`.

### Document class

Quite a few options:

* `article` - general purpose class for publications, reports, etc.

* `proc` - proceedings

* `report` - longer reports, short books, etc.

* `book` - books

* `slides` - presentation slides

* `letter` - writing letters

* etc.

Various organizations will also distribute customized document classes for
various purposes.  For example:

* SIAM LaTeX: <https://www.siam.org/journals/auth-info.php>

* Stanford PhD thesis template:
  <https://library.stanford.edu/research/bibliography-management/latex-and-bibtex>

### White space

White space is normalized so `1` to `n` spaces are treated the same

![fig](fig/spaces.png)

### Paragraphs

![fig](fig/paragraphs.png)

### Special characters

There are several reserved characters in LaTeX:

```
# $ % ^ & _ { } ~ \
```

### Comments

![fig](fig/comments.png)

### Groups

Pairs of curly brackets denote a group and are typically used to limit the scope
of switches:

![fig](fig/groups.png)

### Commands

General form of a LaTeX command is

```
\commandname[option1,option2,...]{argument1}{argument2}...
```

### Command example

![fig](fig/commands.png)

### Environments

```
\begin{environmentname}
Text to be influenced by this environment
\end{environmentname}
```

### Equation environment

![fig](fig/equation.png)

### Bulleted list

![fig](fig/bullets.png)

### Latex packages

Many LaTeX environments are defined in packages.  To include a package use the
`\usepackage` command in the document preamble.  The `tex/demo.tex` document
uses a few:

```
\usepackage{graphicx}
\usepackage{algorithm2e}
```

This comes before the `\begin{document}` command.

* `graphicx` provides the `\includegraphics` command for figures

* `algorithm2e` provides an environment for displaying algorithms

### Figures

![fig](fig/figure.png)

### Table

![fig](fig/table.png)

### Algorithm

![fig](fig/algorithm.png)

### Referencing labels

Use `\label` and `\ref`:

![fig](fig/referencing.png)

The first pass of LaTeX will produce an unresolved reference:

![fig](fig/unresolved-reference.png)

The second pass of LaTeX will resolved the reference:

![fig](fig/resolved-reference.png)

### Controlling placement

* By default figures, tables, etc. will "float" around to where they best fit

* You can also specify preferences about placement

* Floating environments take a parameter in square brackets:
  `\begin{figure}[?]`.  The options are:

  * `h` for "float here"
  
  * `t` for "top of page"
  
  * `b` for "bottom of page"
  
  * `H` for "put here, don't float"

* Good figure placement often requires some experimentation.

* Advice: write the document first.  Make it look nice second.  Things will
  change as you add more text and figures.

![fig](fig/placement.png)

### BibTex

* Companion program for managing citations of papers, books, websites, etc.

* Start by creating a `.bib` file

### .bib file

See `tex/references.bib`:

![fig](fig/bibtex-example.png)

### Typesetting with BibTeX reference

This is really annoying!

```
$ pdflatex demo
$ bibtex demo
$ pdflatex demo
$ pdflatex demo
```

Many TeX editors do this for you with one button click.  See

* TeXShop

* TeXWorks

* TeXMaker

I use a GNU makefile to drive TeX.

### Bibliography management

* Any text editor can be used to create, edit, and manage a `.bib` file

* Some editors will recognize the file extension and enable a BibTex specific
mode

  * There are also applications specifically for doing this:
  
  * BibDesk (Mac OS X only): <http://bibdesk.sourceforge.net>
  
  * JabRef (Windows / Mac OS X / Linux): <http://jabref.sourceforge.net>
  
  * Mendeley: <http://www.mendeley.com>

### Citations

Citation in LaTeX:

![fig](fig/citations.png)

Resulting PDF:

![fig](fig/demo-pdf.png)

### A note on LaTeX errors

LaTeX will dump error messages and start a prompt on errors:

```
$ pwd
/Users/nwh/Dropbox/courses/2015-Q4-cme211/lecture-prep/lecture-13-work/tex
nwh-mbpro:tex nwh$ pdflatex demo
This is pdfTeX, Version 3.14159265-2.6-1.40.16 (TeX Live 2015) (preloaded format=pdflatex)
.....
) (./demo.aux) (/usr/local/texlive/2015/texmf-dist/tex/latex/base/omscmr.fd)
! Undefined control sequence.
l.35 \includegraphics
                     [width=0.85\linewidth]{../fig/maze.pdf}
? 
```

LaTeX is wanting you to guide the typesetting at this point.  I have no idea
what to do here.  I input a capital `X` to get back to the shell.  I then fix
the error in the `.tex` file.  In this case, I forgot `\usepackage{graphicx}` in
the preamble.

### LaTeX references

* Google

* Guide to LaTeX by Kopka and Daly:  
  <http://proquest.safaribooksonline.com/book/graphic-design/9780321617736>

* **Detexify**: a web tool to go from symbol drawing to TeX command:  
  <http://detexify.kirelabs.org/classify.html>

* LaTeX Wikibook:
  <https://en.wikibooks.org/wiki/LaTeX>
