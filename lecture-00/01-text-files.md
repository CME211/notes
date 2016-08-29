# CME211 Lecture 0 - Text Files

A **text file** is simply a sequence of characters that can be opened by any
**text editor**.  In scientific computing and data science applications, text
files can be used for a variety of tasks:

* Publication and presentation with [LaTeX][tex] (`.tex` file extension)
* Dataset storage in comma-separated value files (`.csv`)
* Object serialization with [JSON][json] (`*.json`)
* Websites (`.html`)
* Graphics with tools like [SVG][svg] or [TikZ][tikz]
* Source code in any language, CME211 will use Python (`.py`) and C++ (`.cpp`)
* Tools for [3d models][3d]
* [Commonmark][commonmark]/[Markdown][markdown] for many things (`.md`)
* Software build systems with [GNU Make][gnu-make] or [CMake][cmake]
* [Music notation](http://lilypond.org/text-input.html) (note: the author of these
  notes knows very little about music composition)

[svg]: https://developer.mozilla.org/en-US/docs/Web/SVG
[tex]: https://www.latex-project.org/
[tikz]: http://www.texample.net/tikz/
[3d]: http://www.implicitcad.org/
[commonmark]: http://commonmark.org/
[markdown]: http://daringfireball.net/projects/markdown/
[json]: http://www.json.org/
[gnu-make]: https://www.gnu.org/software/make/
[cmake]: https://cmake.org/

One benefit of working with text files is that they can be checked into
version control systems and easily compared to previous versions.  It is also
possible to check binary files into a version control system, but it is not as
easy to find the differences from previous versions.

A few examples of binary files: `.zip`, `.jpg`, `.xls`, `.docx`.

## Text Editors

Text editors that work in a terminal:

* Emacs: <https://www.gnu.org/software/emacs/>
* Vim: <http://www.vim.org/>
* GNU Nano: <https://www.nano-editor.org/>

GUI Based text editors:

* Atom: <https://atom.io/>
* Visual Studio Code: <https://code.visualstudio.com/>
* Sublime Text: <https://www.sublimetext.com/>
* TextWrangler: <http://www.barebones.com/products/textwrangler/> (macOS)
