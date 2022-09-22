# CME 211 Frequently Asked Questions

- [CME 211 Frequently Asked Questions](#cme-211-frequently-asked-questions)
    - [Why learn to develop within a terminal?](#why-learn-to-develop-within-a-terminal)
      - [Setting up Emacs on Rice](#setting-up-emacs-on-rice)
        - [`.emacs` file](#emacs-file)
          - [Setting up a package installer](#setting-up-a-package-installer)
          - [Installing `elpy` to obtain `python-mode`](#installing-elpy-to-obtain-python-mode)
          - [Using `python-mode`](#using-python-mode)
    - [Setting up VIM for Python development](#setting-up-vim-for-python-development)
  - [Resources](#resources)
  - [Questions](#questions)
    - [Course registration](#course-registration)
    - [Course prerequisites](#course-prerequisites)
    - [Recordings](#recordings)
    - [How to ask a question on Ed?](#how-to-ask-a-question-on-ed)

### Why learn to develop within a terminal?

When you go into industry, or even if you stay in academia, chances are that you will be computing on data sets that are so large
they cannot fit within or be processed on your local machine. In such cases, you'll need to `SSH` into a remote machine with
sufficient compute resources. E.g. at Google, I don't have access to a majority of the tooling available to Engineers unless
I utilize the command line; if I embrace an editor like `emacs`, I get a lot of freebies buil-in that enable a more efficient workflow.

Some of these benefits include

- Being able to send code from an editor to a console within the same `emacs` session.
- Being able to interface with other tools such as [`git` within the editor](https://alexott.net/en/writings/emacs-vcs/EmacsGit.html),
  or even [`gdb` within emacs](https://kb.iu.edu/d/aqsy).
- [Keyboard shortcuts](https://www.gnu.org/software/emacs/refcards/pdf/refcard.pdf) which enable programmer productivity, e.g. have you
  ever wanted to be able to capitalize an entire word at a time? This is trivial in `emacs`!

#### Setting up Emacs on Rice

The cool thing is that on most `unix` environments, `emacs` is already installed; this is true on `Rice`. So, all you have to do is _configure_
the program to your liking / use-cases. We'll be using Python, so let's start there.

##### `.emacs` file

Each editor typically has a standalone file (which can of course be edited using your favorite editor, e.g. `emacs`) containing settings
for your editor. For `emacs` this file is labeled as `~/.emacs` in your root directory. You can open it using the following command from terminal:

```
emacs ~/.emacs
```

###### Setting up a package installer

Now, once your inside, you can add the following code to your configuration file, by copy-pasting:

```
(require 'package)
(add-to-list 'package-archives
             '("melpa-stable" . "https://stable.melpa.org/packages/"))
```

To copy from this markdown document is trivial, but to paste it into your editor you'll need to type `Ctrl-Shift V`, i.e. hold down control and shift buttons at the same time, then simultaneously type the character `V`. This should paste the contents into your `.emacs` configuration. You can then _save_ the file using the keystroke `C-x C-s`, i.e. hold Control then press `x`, and then release both keys; then hold Control and press `s` and release both keys. That's how you save a file in `emacs`!

###### Installing `elpy` to obtain `python-mode`

Now, go ahead and close `emacs` and restart it; the way you close an `emacs` session is by using the keystroke: `C-x C-c`, i.e. hold Control then press `x` and then release both keys; then hold Control and press `c` and release both keys. You may see a prompt at the bottom of the screen that asks if you really with to exit `emacs`: go ahead and type `yes` then hit `Enter` to confirm your decision.

Now, open up `emacs` once more and type `M-x package-install RET elpy RET`, i.e. hold `Alt` followed by pressing `x` and then release both keys. Then type in `package-install` and hit `Enter` (or `RET` for short), then go ahead and type `elpy` and hit `Enter` again. This will install the `elpy` package for you. You'll see in the lower-pane that `emacs` is running through some steps. (If you notice it gets to a step and hangs for several minutes, try and refresh the pane(s) by typing a command that normally switches panes, e.g. `C-x o`.)

After the package is done installing, add the following to your `~/.emacs` file, perhaps by typing: `C-x C-f` (to instruct `emacs` that you wish to open a file), followed by typing `~/.emacs` followed by `RET` (to tell it that you wish to open your config file specifically).

###### Using `python-mode`

Now that you've installed `elpy` and configured your `emacs`, please close them using `C-x C-c`. Go ahead and open up a new file to play around with, call it e.g. `hello_world.py` via the command line: `emacs hello_world.py`. Now, go ahead and type some Python into the editor

```
my_string = "Hello Emacs!"
declaration = "We've made great progress in this tutorial."
print(my_string + declaration)
```

Now, tell `emacs` that you're working with a Python file by typing in `M-x python-mode`.

To run this code, simply type `C-c C-c` i.e. hold Control and then press `c`, then release both keys; then replicate that same action once more. This sends the code from your editor pane into a Python console. Your editor may ask you where you'd like to run Python from, go ahead and simply hit `RET` when it says something like: `Run Python: /usr/binpython -i`. Type `y` when it asks if you'd like a dedicated process.

Now let's view our evaluated expression. Type `C-x 3` to split your window pane vertically (you could use `C-x 2` if you want a horizontal split). Type `C-x o` to switch to the _other_ buffer. Then, type `C-x b` to choose which _buffer_ you'd like to view: hit the down arrow key several times until you see something like: `Switch to buffer: *Python[/home/<SUNET>/hellow_world.py` then hit `RET`. You should see the output of your evaluated expression within the console!

### Setting up VIM for Python development

For instructions on setting up VIM, see the [following link](https://realpython.com/vim-and-python-a-match-made-in-heaven/). In particular, I would start at [this section](https://realpython.com/vim-and-python-a-match-made-in-heaven/#vundle) since VIM and Python are already installed on our compute environment.

## Resources

- Staff mailing list: <cme211-staff@lists.stanford.edu>

## Questions

### Course registration

We usually reach capacity each year for course enrollment. Students who know
they do not wish to take the course should drop as soon as possible to make room
for those who do wish to enroll. There are several notable points in which
enrollment changes (i.e. spots open up and allow students to get off the
waitlist), and these occur when the first substantial programming assignment is
due and also at the end of the third week of the quarter when there is an
add/drop deadline.

- If you are on the registrar wait list, you must have room in your schedule to
  be added to CME211.
- If you experience any technical issues while registering, you must submit a
  HelpSU request. Feel free to ask questions on Canvas. Keep in mind that the
  teaching staff has no control over registration.

### Course prerequisites

The prerequisite for CME 211 in the bulletin is stated as "introductory
programming course equivalent to CS 106A or instructor consent". CME 211
is a fast paced course for computing skill useful in scientific and
engineering applications. **It is not a good first course in computing or
programming.** We assume that students have learned and practiced with
basic programming concepts and structures such as variables, functions,
loops, data structures, file input/output, encapsulation, and modularity
(in some programming language). We review these concepts for both Python
and C++. However, we have found that students without at least one
formal undergraduate computing course quickly become overwhelmed with
the pace of CME 211.

A background of using MATLAB and/or Python as a
part of (non-programming focused) science and engineering coursework is
typically not sufficient for success in CME 211.

### Recordings

This course is offered in-person and so won't be recorded. We generally try to stick very close to the notes in the lectures so that anyone missing the lecture do not feel lost.

### How to ask a question on Ed?

As this is a programming class, you're bound to run into errors. Asking for help from your colleagues is one of the best ways to quickly tackle it, and move on.

But we all know that everyone's super busy :( and so it'll be better if we don't 'waste' their time.

So, we would recommend you to adhere to the following style while asking questions to your peers/Teaching Staff.

- **Search for similar question:**

  Often your question has already been asked by a different person. Please make sure to do an exhaustive search for similar question. If the question has indeed been asked, but doesn't address your issue, then add a follow-up question to the thread.

- **Title:**

  Keep your title very specific and to the point.

  **Bad:**

  - Help!! Code is not working
  - Getting Runtime error :(

  **Good:**

  - why does $\frac{2}{3}$ giving $0$ istead of $0.66$ in python?
  - I'm getting a segmentation fault while accessing the time list for function Time()

- **Body:**

  Briefly summarize your problem in words by giving the readers some context. Add code snippets/template if needed. Please avoid including your entire code. This could lead to Honor Code Violations and also, inadvertant addition of irrelevant details.

- **What have you tried?:**

  It's always good to let the readers know what workarounds you have already tried. Include the links of the sites where you found those workarounds (Maybe you implemented it wrong?)

- **Intermediate results:**
  Say you coded everything beautifully, but you initialized the variables incorrectly! This could lead to hours of debugging. It's better to put intermediate results in your post so that one can know how much of your code is working as expected.

- **Proofread:**

  This is often ignored in haste, but always proofread whatever you post.

- **Feedback:**

  If you've got an error, others will get it too! Always make sure to reply to posts to let others know whether the solution worked for you or not.

- **Reference:**

  Here's a great reference on how to ask question from [stackoverflow](https://stackoverflow.com/help/how-to-ask)
