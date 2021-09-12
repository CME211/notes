# CME 211 Syllabus (Fall 2021)

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

## Topics Covered

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

Please visit the CME211 Canvas page: <https://canvas.stanford.edu/courses/142634>

All other correspondence should be sent to <cme211-staff@lists.stanford.edu>.

*Do not send questions related to course material to the staff mailing list or to individual staff emails (including the instructor).  We will not answer these.
Questions may be posted to the Canvas discussion board or asked during office hours.*

## Teaching staff

Instructor: 
  - [Andreas Santucci](https://asantucci.github.io/) (santucci at stanford)

Teaching assistants:
  - Aasavari Kakne (adkakne at stanford)
  - Frederic Ladouceur (ladouceu at stanford)
  - Trevor Maxfield (maxfit at stanford)
  - Samuel Randall (samuellr at stanford) 

## Time and location

- Days: Tues, Thurs
- Time: 7:15 PM - 8:45 PM
- Location: [STLC 114](http://campus-map.stanford.edu/?srch=STLC114)

## Office hours

All office hours will commence during week 2 of the quarter.

Andreas will hold office hours after each class 
from 8:55 P.M. to 9:45 P.M.

The TA's will announce their weekly Office Hour schedule by the end of the first
week of the quarter.

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
This year, your course grade will be based on assignments (60%), 
one Python exam (12.5%), one C++ exam (12.5%), and a final project (15%).

Course letter grades are at the discretion of the instructor. If at any time you
have questions about your standing in the class, please contact the instructor.
Please don’t wait until after the course is over if you have concerns about your
progress in the class.

It's critical that you read through the [grading guidelines][grading-guidelines] that are posted in the `CME211/guidelines` folder on our Github course webpage.

[grading-guidelines]: https://github.com/CME211/notes/tree/master/guidelines

**Important note regarding minimium thresholds for passing the course** 
Students _must pass_ the homework section of the course in order to pass the
class overall. Additionally,
students _must pass_
the exams (when considered in union) in order to pass the class overall. Lastly,
students
_must pass_ the final project in order to earn a passing grade in the course
overall. We put these guardrails in place to ensure that students are putting
consistent effort into the course.

Should you choose to take the course CR/NC, your final grade must be
satisfactory or better -- i.e. you'll need to earn at least a C- or better to
get a CR.

## Exam
This year, we will administer the exams in person during regularly scheduled
class times. You will have 85 minutes to complete the exam, i.e. we will reserve the entire lecture for the exam on the relevant days. If you foresee or encounter extenuating circumstances that would not allow you to be present for the in-person examinations, please contact the teaching staff as soon as possible.

## Assignments
There will be 7 assignments (although the first is required, 
it is not graded in the same way as subsequent assignments).
In general, assignments will be posted on Friday
afternoons and be due the following Friday at 4:30 pm via online submission, through GitHub.

Students are expected to complete *all* assignments. Across all
assignments, students are permitted a total of 3 late days, which can be used
one day at a time. I.e., each late day used grants up to a 24-hour extension,
and a late day cannot be used partially (e.g. if you hand in an assignment 2
hours after the deadline, you will have used up an entire late day). Usage
of *additional* late days (beyond 3) 
will be penalized at the end of the quarter,
by an amount subject to the discretion of the staff! E.g. with one *additional* late day, we might choose to penalize 25% of allowable marks on the relevant assignment which uses an unsanctioned late day, and with two *additional* late days, we might choose to penalize 50% of allowable marks on the relevant assignments which use unsanctioned late days, etc.

Note that *failure to submit* a single assignment corresponds to 
*at least* a full final letter grade deduction, simply by virtue of the fact that there are six full graded assignments each worth 10% of your final letter grade.

### Re-grade requests
Each student is granted 3 non-valid regrade requests. Unused regrade requests will be translated to a small amount of bonus points at the end of the quarter. A regrade request is only counted as used if the points were not awarded to the student. Regrade requests are made by submitting a GitHub issue in the homework submission repository and tagging or assigning the TA who graded the homework (not to be confused with the TA who pushed the homework feedback); you can find the TA who graded your feedback at the bottom of your homework feedback file.

## Final Project
We allow students to showcase what
they've learned cumulatively throughout the course via a final project, which will use a little bit of Python but will mostly be done in C++; the instructions for the final project will be given to you, i.e. you will not be free to choose your own final project. More details will be provided later in the
quarter.

## Course Privacy Statement
As noted in the University’s [recording and broadcasting courses policy][recording-policy], students may not audio or video record class meetings without permission from the instructor (and guest speakers, when applicable). If the instructor grants permission or if the teaching team posts videos themselves, students may keep recordings only for personal use and may not post recordings on the Internet, or otherwise distribute them. These policies protect the privacy rights of instructors and students, and the intellectual property and other rights of the university. Students who need lectures recorded for the purposes of an academic accommodation should contact the Office of Accessible Education. 

[recording-policy]: https://library.stanford.edu/using/copyright-reminder/common-situations/recording-broadcasting-courses

## Honor Code

All students are expected to abide by the [Stanford Honor Code][honor-code]. The
work you submit to us for grading must be your own.  The [computer science
website][cs-code] has a good explanation of the honor code as it relates to
courses involving significant amounts of computer programming. In particular, for any examinations, the Office of Community standards has provided [guidance][remote-guidance] for (remote) teaching and learning. Some takeaways from the remote-teaching resources:

 - "Permitted informational resources only includes material a reasonable student would have found to be helpful when trying to understand class material or preparing for an assignment or exam. This does not include material that becomes useful once the assignment or exam begins and questions are known."
 - "In all cases, it is not permissible for students to enter exam questions into any software, apps, or websites. Accessing resources that directly explain how to answer questions from the actual assignment or exam is a violation of the Honor Code."
 - "Answers to assignment or exam questions must be written in the student’s own words, or else be cited, otherwise it is plagiarism. Use of all sources, including internet resources, must be cited. Similarly, consulting or collaborating with other people is not permitted and does not fall within the definition of an open-book or informational resource..."

Students are expected to read the three resources on ([honor-code], [cs-code], and [remote-guidance]) in full, as there are serious consequences for not abiding by the honor code! Compromising your academic integrity may lead to serious consequences, including (but not limited to) one or more of the following: failure of the assignment, failure of the course, disciplinary probation, suspension from the university, or dismissal from the university.


Note that at various times we may use special computer software called
[MOSS][moss] to assist us in detecting plagiarism.  If you are having difficulty
completing an *assignment* please contact a TA or the instructor so that we may
help you (for exams, we cannot offer any assistance). We would much rather spend time helping you than dealing with honor
code violations!

[honor-code]: http://studentaffairs.stanford.edu/judicialaffairs/policy/honor-code
[cs-code]: http://csmajor.stanford.edu/HonorCode.shtml
[moss]: http://theory.stanford.edu/\~aiken/moss/
[remote-guidance]: https://communitystandards.stanford.edu/bja-guidance-remote-teaching-and-learning-environment

### Guidelines for *Assignments*

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

## Grading and End of Quarter Policies
 - *Cr/NC Grading policies*: by University policy (https://registrar.stanford.edu/students/definition-grades), `Cr` is earned for `C-` work or better. 
 - *Coursework Deadline*: by University policy (https://registrar.stanford.edu/coursework-deadline-2020-21), “all coursework is due by the last day of the last week of instruction in each quarter.''

## Students with Documented Disabilities

Students who may need an academic accommodation based on the impact of a
disability must initiate the request with the Office of Accessible Education
(OAE). Professional staff will evaluate the request with required documentation,
recommend reasonable accommodations, and prepare an Accommodation Letter for
faculty dated in the current quarter in which the request is made. Students
should contact the OAE as soon as possible since timely notice is needed to
coordinate accommodations. The OAE is located at 563 Salvatierra Walk.

(Phone: 723-1066, URL: <http://studentaffairs.stanford.edu/oae>).

## What do I do if I have an Emergency that requires an Accommodation?
If you have an emergency that requires both medical attention and a course accommodation, please get in touch with the Office of Accessible Education as soon as possible to request a formal accommodation. If there is an emergency within your family that requires your attention and a course accommodation, please get in touch with the Graduate Life Office as soon as possible to establish documentation. While pursuing these steps, please also get in touch with me (Andreas) as soon as possible; I aim to be compassionate and wish to work with you to facilitate a healthy learning experience. Although not all situations can be accommodated, many students have had success using these avenues in the past.

# Saving Code(s) from the Course
Note that at the end of each year, we must purge student repositories from the Github virtual classroom we use and to that end, if you wish to retain a copy of your codes you should make a **private** backup repository (outside of the Github 211 classroom, and within your own personal set of repositories) at the end of the quarter. Note that the repo must be private else it will be a violation of the honor code.
