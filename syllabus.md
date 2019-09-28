# CME 211 Syllabus (Fall 2019)

_(cross listed as Earth 211)_

## Software Development for Scientists and Engineers

Basic usage of the Python and C++ programming languages are introduced and
used to solve representative computational problems from various science and
engineering disciplines. Software design principles including time and space
complexity analysis, data structures, object-oriented design, decomposition,
encapsulation, and modularity are emphasized. Usage of campus wide Linux compute
resources: login, file system navigation, editing files, compiling and linking,
file transfer, etc. Versioning and revision control, software build utilities,
and the LaTeX typesetting software are introduced and used to help complete
programming assignments. Prerequisite: introductory programming course
equivalent to [CS 106A][cs106a] or instructor consent.

[cs106a]: https://explorecourses.stanford.edu/search?view=catalog&filter-coursestatus-Active=on&page=0&catalog=&academicYear=&q=cs106&collapse=

## Goals

- To become a productive user of unix-like and remote computing systems.
- To become an effective user of tools for software development such as version
  control (`git`), text editors (vim, emacs), and build systems (`make`).
- To be able to write Python and C++ programs of intermediate complexity for science
  and engineering applications.
- Develop skill in [*computational thinking*][comp-think], that "is the thought
  processes involved in formulating a problem and expressing its solution(s) in
  such a way that a computer, human or machine, can effectively carry out."

[comp-think]: http://socialissues.cs.toronto.edu/index.html%3Fp=279.html

## Topics

### Linux

- Remote login and file transfer using `ssh` and `scp`
- Filesystem navigation (moving through and creating directories, finding files, etc.)
- Creation and editing of code and data files

### Python

- Variables, conditionals, file I/O, data structures (lists, tuples, dictionaries, sets)
- loops, functions, exceptions, and modules
- Objects and references
- Objected Oriented Programming (OOP) using classes
- Numerical Python (NumPy) and Scientific Python (SciPy) extensions for scientific computing
- matplotlib for visualization

### C++

- Creating C++ Programs: preprocessor, compiling, linking
- Containers (vector, map, etc.)
- Object oriented programming (classes and methods, etc.)
- Pointers, addresses, and memory management
- *Note that more advanced features of C++ (operator overloading, templates, etc.) will be covered in CME 212*

### Software Development and Industry Practices
- Creating and using a basic Makefile
- Version control: use of Git and Github for managing software projects
- LaTeX markup (figures, tables, equations, references, managing a
  bibliography, and publishing a PDF document)

## Communication

We will be using Canvas to send announcements and as a discussion board for the
homework projects. Please use this if you have questions regarding course
material.

Please visit the CME211 Canvas page: <https://canvas.stanford.edu/courses/104580>

All other correspondence should be sent to <cme211-staff@lists.stanford.edu>.

*Do not send questions related to course material to the staff mailing list or to individual staff emails (including the instructor).  We will not answer these.
Questions may be posted to the Canvas discussion board or asked in-person during
office hours.*

## Teaching staff

Instructor: 
  - [Andreas Santucci](https://asantucci.github.io/) (santucci at stanford)

Teaching assistants: 
  - Teresa Dayrit (tedayrit at stanford)
  - Fredric Lam (flam at stanford)
  - Frederik Mellby (frederme at stanford)
  - Lewis Warne (lwarne at stanford)
  

## Time and location

- Days: Tues, Thurs
- Time: 4:30 PM - 6:20 PM
- Location: Hewlett 201

## Office hours

All office hours are held in the Huang basement just outside of the ICME. 

Mondays: 12:00 PM - 2:00 PM (Lewis)

Tuesdays: 11:00 PM - 1:00 PM (Fred M) and 2:30 PM - 4:30 PM (Teresa)

Wednesdays: 3:00 PM - 5:00 PM (Lewis) and 6:00 PM - 8:00 PM (Fred M)

Thursdays: 1:00 PM - 3:00 PM (Teresa) and 6:30 PM - 8:30 PM (Fred L)

Fridays: 10:00 AM - 12:00 PM (Fred L)

## Resources

Recommended readings come from the following books, which are available online
to Stanford students through the library.  These are great books to have in your
collection.

- **Learning Python**, 5th Edition by *Mark Lutz* ([link][learning-python])
- **C++ Primer**, 5th Edition by *Lippman, Kajoie, and Moo* ([link][c++-primer])

[learning-python]: http://proquest.safaribooksonline.com/book/programming/python/9781449355722
[c++-primer]: http://proquest.safaribooksonline.com/9780133053043?uicode=stanford

Other resources are listed in the [`CME211/notes`][cme211-notes] repository.

[cme211-notes]: https://github.com/CME211/notes#contents

## Grading

Your course grade will be based on assignments (50%), two exams (12.5%
each, 25% total), and a project (25%).

Course letter grades are at the discretion of the instructor. If at any time you
have questions about your standing in the class, please contact the instructor.
Please don’t wait until after the course is over if you have concerns about your
progress in the class.

## Assignments

There will be 7 graded assignments. Assignments will be posted on Friday
afternoons and be due the following Friday at 4:30 pm via online submission.
Late assignments will **not** be accepted.

Although students are expected to complete all assignments, the one assignment
with the lowest score (by percentage) will automatically be dropped when
computing your overall course grade. The policy of dropping the lowest score is
in lieu of a late policy or providing extensions so please don’t ask for them!

## Final Project

In place of an exam during finals week there will be a final project due on the
scheduled day of the final exam. More details will be provided later in the
quarter.

## Honor Code

All students are expected to abide by the [Stanford Honor Code][honor-code]. The
work you submit to us for grading must be your own.  The [computer science
website][cs-code] has a good explanation of the honor code as it relates to
courses involving significant amounts of computer programming.

Note that at various times we may use special computer software called
[MOSS][moss] to assist us in detecting plagiarism.  If you are having difficulty
completing an assignment please contact a TA or the instructor so that we may
help you. We would much rather spend time helping you than dealing with honor
code violations.

[honor-code]: http://studentaffairs.stanford.edu/judicialaffairs/policy/honor-code
[cs-code]: http://csmajor.stanford.edu/HonorCode.shtml
[moss]: http://theory.stanford.edu/\~aiken/moss/

### Guidelines

- It’s great (and encouraged) to work with other people on high level ideas,
  concepts, and methods.  
  
  But, you must write your code on your own. 

  Please seek help early and often, if and when you encounter problems.
- Keep your code closed and separate if you are helping another student with a
  debugging or technical issue in code.
- Do not copy code from another student (current or previous).
- Do not give your code to another student (current or future).
- It is acceptable to copy small blocks (a few lines) of code from public 
  sources,
  such as [stackoverflow.com](http://stackoverflow.com/).  You must cite your
  source and abide by any copyright and licensing restrictions.  You do 
  not need
  to cite course notes, example programs provided by CME211, reference 
  information
  from [python.org docs](https://docs.python.org/3/), or reference information
  from [cppreference.com](http://en.cppreference.com/w/).
- Do not use or reference work from previous students of CME211 or any solution
  files that may be out there.
- Do not post homework PDFs or your solutions in a publicly available location.
- Please let us know if you come across available solutions.  
  We will kindly ask
  the provider to remove the resource.

## Students with Documented Disabilities

Students who may need an academic accommodation based on the impact of a
disability must initiate the request with the Office of Accessible Education
(OAE). Professional staff will evaluate the request with required documentation,
recommend reasonable accommodations, and prepare an Accommodation Letter for
faculty dated in the current quarter in which the request is made. Students
should contact the OAE as soon as possible since timely notice is needed to
coordinate accommodations. The OAE is located at 563 Salvatierra Walk.

(Phone: 723-1066, URL: <http://studentaffairs.stanford.edu/oae>).
