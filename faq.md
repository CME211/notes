# CME 211 Frequently Asked Questions

## Development Environments
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
<<<<<<< HEAD

### Recordings

This course is offered in-person and so won't be recorded. We generally try to stick very close to the notes in the lectures so that anyone missing the lecture do not feel lost.
=======
>>>>>>> bb2547f25eff0e8feb575c7a047ec0a30eb3bde8
