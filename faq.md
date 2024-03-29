# CME 211 Frequently Asked Questions

- [CME 211 Frequently Asked Questions](#cme-211-frequently-asked-questions)
  - [Why learn to develop within a terminal?](#why-learn-to-develop-within-a-terminal)
    - [Setting up Emacs on Rice](#setting-up-emacs-on-rice)
      - [`.emacs` file](#emacs-file)
        - [Setting up a package installer](#setting-up-a-package-installer)
        - [Installing `elpy` to obtain `python-mode`](#installing-elpy-to-obtain-python-mode)
        - [Using `python-mode`](#using-python-mode)
  - [Setting up VIM for Python development](#setting-up-vim-for-python-development)
  - [Setting up vscode](#setting-up-vscode)
- [Resources](#resources)
- [Questions](#questions)
  - [Course registration](#course-registration)
  - [Course prerequisites](#course-prerequisites)
  - [Recordings](#recordings)
  - [How to ask a question on Ed?](#how-to-ask-a-question-on-ed)
- [Git](#git)

## Why learn to develop within a terminal?

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

### Setting up Emacs on Rice

The cool thing is that on most `unix` environments, `emacs` is already installed; this is true on `Rice`. So, all you have to do is _configure_
the program to your liking / use-cases. We'll be using Python, so let's start there.

#### `.emacs` file

Each editor typically has a standalone file (which can of course be edited using your favorite editor, e.g. `emacs`) containing settings
for your editor. For `emacs` this file is labeled as `~/.emacs` in your root directory. You can open it using the following command from terminal:

```
emacs ~/.emacs
```

##### Setting up a package installer

Now, once your inside, you can add the following code to your configuration file, by copy-pasting:

```
(require 'package)
(add-to-list 'package-archives
             '("melpa-stable" . "https://stable.melpa.org/packages/"))
```

To copy from this markdown document is trivial, but to paste it into your editor you'll need to type `Ctrl-Shift V`, i.e. hold down control and shift buttons at the same time, then simultaneously type the character `V`. This should paste the contents into your `.emacs` configuration. You can then _save_ the file using the keystroke `C-x C-s`, i.e. hold Control then press `x`, and then release both keys; then hold Control and press `s` and release both keys. That's how you save a file in `emacs`!

##### Installing `elpy` to obtain `python-mode`

Now, go ahead and close `emacs` and restart it; the way you close an `emacs` session is by using the keystroke: `C-x C-c`, i.e. hold Control then press `x` and then release both keys; then hold Control and press `c` and release both keys. You may see a prompt at the bottom of the screen that asks if you really with to exit `emacs`: go ahead and type `yes` then hit `Enter` to confirm your decision.

Now, open up `emacs` once more and type `M-x package-install RET elpy RET`, i.e. hold `Alt` followed by pressing `x` and then release both keys. Then type in `package-install` and hit `Enter` (or `RET` for short), then go ahead and type `elpy` and hit `Enter` again. This will install the `elpy` package for you. You'll see in the lower-pane that `emacs` is running through some steps. (If you notice it gets to a step and hangs for several minutes, try and refresh the pane(s) by typing a command that normally switches panes, e.g. `C-x o`.)

After the package is done installing, add the following to your `~/.emacs` file, perhaps by typing: `C-x C-f` (to instruct `emacs` that you wish to open a file), followed by typing `~/.emacs` followed by `RET` (to tell it that you wish to open your config file specifically).

##### Using `python-mode`

Now that you've installed `elpy` and configured your `emacs`, please close them using `C-x C-c`. Go ahead and open up a new file to play around with, call it e.g. `hello_world.py` via the command line: `emacs hello_world.py`. Now, go ahead and type some Python into the editor

```
my_string = "Hello Emacs!"
declaration = "We've made great progress in this tutorial."
print(my_string + declaration)
```

Now, tell `emacs` that you're working with a Python file by typing in `M-x python-mode`.

To run this code, simply type `C-c C-c` i.e. hold Control and then press `c`, then release both keys; then replicate that same action once more. This sends the code from your editor pane into a Python console. Your editor may ask you where you'd like to run Python from, go ahead and simply hit `RET` when it says something like: `Run Python: /usr/binpython -i`. Type `y` when it asks if you'd like a dedicated process.

Now let's view our evaluated expression. Type `C-x 3` to split your window pane vertically (you could use `C-x 2` if you want a horizontal split). Type `C-x o` to switch to the _other_ buffer. Then, type `C-x b` to choose which _buffer_ you'd like to view: hit the down arrow key several times until you see something like: `Switch to buffer: *Python[/home/<SUNET>/hellow_world.py` then hit `RET`. You should see the output of your evaluated expression within the console!

## Setting up VIM for Python development

For instructions on setting up VIM, see the [following link](https://realpython.com/vim-and-python-a-match-made-in-heaven/). In particular, I would start at [this section](https://realpython.com/vim-and-python-a-match-made-in-heaven/#vundle) since VIM and Python are already installed on our compute environment.

## Setting up vscode

Are you sick of coding in nano or not understanding vim / emacs ?

VSCode, or Visual Studio Code, has become an extremely popular Graphical UI EDI these past few years. It is free, lightweight, highly customizable, has good support for most languages, and has a big library of plugins that will make your software engineering learning and professional experience much easier. Using it instead of emacs, vim or nano is your choice. But knowing how to use it and configure it is also a great, valuable experience. And one could argue that it is way easier to code within it than within a terminal.

When it comes to working on rice, setting it up requires just a bit of work. It will look like you're using vscode on your computer, but it will actually perform all the running and saving actions on rice (and that's the beauty of it).

### Method for MacOS & Linux users

The following steps will show how to use vscode installed on your computer to edit and start remote files on rice. THIS GUIDE IS SUITED FOR MACOS / LINUX USERS. If you have Windows, we recommend the method further below.

- A first, recommended thing you should do when you are on MacOS or Linux, is enable SSH multiplexing so that you avoid having vscode disconnecting from time to time, which would force you to redo the 2-factor authentication. You can follow the [tutorial here (Section Two Step Authentication)](https://web.stanford.edu/group/farmshare/cgi-bin/wiki/index.php/Advanced_Connection_Options#Two-step_Authentication). It's what will help not having the connection drop every few minutes and ask you to login again. On Windows, this is not possible.

- Next, install vscode on your computer by downloading it [on its website](https://code.visualstudio.com/).

- Once installed, in the left menu, go to the extensions marketplace and install "Remote Development" and "Remote - SSH".

- Once they are installed, you should have a new icon in the side menu, which will lead you to your remote explorer. Add an SSH target with "ssh your_sunet_id@rice.stanford.edu" and run it. Just like with normal SSH, you will be asked your password and then to login with Duo 2FA.

- Once it's done, you should have a new VS Code window open and be able to explore your remote environment within vscode, run commands in the terminal, and edit the files with your mouse and keyboard directly, with all the cool things from vscode.

### Method for Windows users

Carlos, who took the class in Fall 2022, made a great guide to setup VSCode with Rice on Windows in a stable way.

You can follow [his guide](resources/Set_Up_and_Using_SSH_FS_on_VSCode.pdf).

# Resources

- Staff mailing list: <cme211-staff@lists.stanford.edu>

# Questions

## Course registration

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

## Course prerequisites

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

## Recordings

This course is offered in-person and so won't be recorded. We generally try to stick very close to the notes in the lectures so that anyone missing the lecture do not feel lost.

## How to ask a question on Ed?

As this is a programming class, you're bound to run into errors. Asking for help from your colleagues is one of the best ways to quickly tackle it, and move on.

But we all know that everyone's super busy, and so for efficiency reasons we ask that you adhere to the following style while asking questions to your peers/Teaching Staff.

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

# Git
For a helpful interactive tutorial on Git, please see: https://learngitbranching.js.org/.

## Basic idea of GitHub

GitHub helps you organize your files and keep them in one central location (i.e. GitHub), which is very useful when collaborating with others, as you no longer need to email each other files and manually track everyone's updates. It also helps with keeping track of which update was made when, allows you to go back to old code if needed, is easy for sharing with the general public as well as private groups, and so on. Every tech company uses GitHub!

There are 3 basic 'locations' you'll be working on: your local machine, your local GitHub repository, and the remote GitHub repository. After logging into Rice, Rice is now your 'local' computer (i.e. the one you're working on).

### Pipeline

To get from updating files to getting them on the remote GitHub page, the 'pipeline' is as follows:

#### Add and commit
After changing a file locally (on Rice),  you can add this updated file to your 'local GitHub (repo)' by doing `git add [filename]` (which adds the file to your local GitHub) and `git commit -m "[message]"`, which adds a message to the git add-update you've just done. This allows you to track progess and makes it easier for other collaborators, too, to see a one-line summary of the work that's been added since they've last looked at it. The -m "flag" means you're doing to add a message afterwards.

#### Pushing
Once you've done the add and commit, it's time to push your local changes to a remote "branch": there could be spin-offs on projects, called "branches", and you could push to any. For now, you'll just have the "main" branch. This pushing is done by writing `git push <remote> <branch>` , which amounts to `git push` or `git push origin main` for y'all (both should work). The `<remote>` part refers to which GitHub project/page you want to push to, as you might be working on many projects at once on GitHub. When you start a new project (like everyone just has), origin will refer to that new project, so instead of referring specifically to the location of your CME211 remote repository, you can just write origin! :-). Lastly, each project within the remote repo you referred to in the previous word (i.e. origin for y'all) might have many branches -- to which branch (or "spin-off") do you want to contribute and add your file? In our case, you'll just push to the main branch, hence the main at the end.

#### Tagging
If 100 people work on 1 project, you might get many commits (every day), and if you need to go back to the version of 2 days ago, which one is it??? To keep track of versions, you can 'tag' them -- this is typically done after a big update, or some particular point in time. After ensuring your local GitHub repo contains the same as the remote repo, you can add a tag on your local GitHub repo, and then push it! The command `git tag -am "HW1 Submission" hw1` in the homework is equivalent to doing `git tag -m "HW1 Submission" -a hw1` . Basically, the `-a` means you're going to give this tag a name (you're doing to annotate it), e.g. hw1, while the `-m` means you're going to add a brief message about it (just like with the git commits!) 

#### Pulling
Now, sometimes your local repo is not up to date with the remote repo (e.g. because other people have contributed). If you and person X don't have each other's updates but each try to push your new local files, which file should GitHub go with? For instance, suppose us two (yeah, you and me) had a file containing "A", and I update it to "AB" locally, and you update it to "AC" locally, and we both try to upload these new files to the remote GitHub repo, what should the shared, common new file be? That's not clear, right? So to prevent this, GitHub demands that you first 'pull' in or 'fetch' the updates made to the remote repo before pushing your local files.

In other words, if you get an error like
```
! [rejected]     main -> main (fetch first)
error: failed to push some refs to '[github link]'
hint: Updates were rejected because the remote repo contains work that you do
hint: not have locally. This is ...[more text here]
```
that means there have been made some updates to the remote repository (i.e. the one you see on the website) that you don't have yet. And to prevent said clashes, you need to pull in these updates first. This is done by writing git pull , which rakes the GitHub remote repo (updates), without overwriting your local changes (GitHub is smart -- it'll let you know if git pull is hard without overwriting local changes). After the git pull, your local github should be the same version as the remote one, allowing you to update!

TL;DR: if shown the error in code snippet above when trying to push, do a git pull and then a git push. You need to grab the updates from the remote repo :-).
