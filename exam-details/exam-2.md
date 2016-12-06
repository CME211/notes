# CME 211 Exam 2 Details

The exam will be conducted through Canvas. The exam will be available from the
morning of Wednesday 12/7 to Friday 12/9 at 2pm. Students will have 2 hours to
complete the exam once it is started. Once you start the exam, you will be given
a link to download a `zip` file. See the directions below to work with the `zip`
file from the command line.

Notes:

* The exam will appear in the "Quizzes" section on Canvas.

* Sample exam solutions from 2014 and 2015 are posted on Canvas in the file
  section.

* There is a "Exam 2 Technical Practice" quiz on Canvas if you would like to
  practice working with a `zip` file before starting the actual exam.

## Exam time

You are granted 120 minutes to work on the exam. We expect you to have the `zip`
file uploaded on Canvas and the exam submitted at the 2 hour mark. We will have
20 buffer minutes on the exam timer. These are to allow you a bit of extra time
to make sure the exam does not time out on you before you've uploaded the file.
We will look at the exam submission time stamps and deduct 1% for each extra
minute used.

**We will not accept exam submissions over email.**

**Make sure to upload your exam file and click the "Submit Quiz" before 120
minutes to avoid any additional time penalty.**

## Details

* Exam will be challenging -- I believe you all to be smart and hardworking
  students no matter how you perform on the exam
* I recommend attacking the problems in the given sequence
* Make sure to use your time wisely
* Remember, this exam is only worth 12.5% of your grade

## Rules

* Open book
* Open note
* Open computer (restricted internet use)
  * your may use computer to access notes at <https://github.com/CME211/notes>
  * your may use computer to access C++ Primer
  * your may use computer to access <http://en.cppreference.com/w/>
  * **You may not use Google or any other search method to try and find
    answers**
  * **Stackoverflow.com and similar QA sites are not allowed**
* Code must be C++11
* You may use any functionality from the C++ Standard Template Library. (i.e.
  anything in the namespace `std`)
* **You may not use any external package (Boost, ...)**

## Communication

* When the exam gets published on Canvas on the morning of Wednesday 12/7, it
  will be known as **The-Exam-Who-Must-Not-Be-Named-Again**. That is, nobody is
  allowed to discuss any aspect of the exam until Friday 12/9 at 2pm.
* The teaching staff will not answer any questions related to the exam until it
  is over. I have tried to remove all ambiguity from the question statements.
  The teaching staff will review the questions. If you feel something is
  ambiguous on the exam, please make a comment above your answer in the source
  code you submit. Indicate what you thought was ambiguous and the decision you
  made to resolve the ambiguity.

## Using the zip file

1. Download the `cme211-exam-2-empty.zip` file from the link on Canvas to your
   local computer. This will require that you authenticate with Stanford Box.

2. Upload the file to `corn.stanford.edu` if you plan to work on the files
   there.

```sh
# copy zip file to corn, replace nwh with your sunet id
$ scp cme211-exam-2-empty.zip nwh@corn.stanford.edu:~/
```

3. Log into `corn` and `unzip` the files.

```sh
# log into corn
$ ssh nwh@corn.stanford.edu
# look at files
$ ls -1
...
cme211-exam-2-empty.zip
...
# unzip the file
$ unzip cme211-exam-2-empty.zip
# inspect
$ ls -1
...
cme211-exam-2
cme211-exam-2-empty.zip
...
# change into exam directory
$ cd cme211-exam-2
```

4. Work on the exam.  Start by reading `0-instructions.md`.

5. `zip` up your work.

```sh
$ zip -r cme211-exam-2.zip cme211-exam-2
```

6. Log out of `corn.stanford.edu` and download files to your local computer.

```sh
# copy file to your local computer, replace nwh with your sunetid
$ scp nwh@corn.stanford.edu:~/cme211-exam-2.zip .
```

7. Upload `cme211-exam-2.zip` to the Canvas quiz interface.
