"""print the top n-grams from a specified text file

This python script shows an example of what we'd like to see in your python
assignments.  We use a popular example of computing and printing the top n-grams
from a text file.

A n-gram is a sequence of n words that appear in a text file.  For example,
('a','text') and ('text','file') are 2-grams appearing in the previous sentence.
An example of a 3-gram would be ('words','that','appear').

A fun data set to compute n-grams from is the complete texts of William
Shakespeare.  To download this data set, execute the following from the command
line:

$ wget http://ocw.mit.edu/ans7870/6/6.006/s08/lecturenotes/files/t8.shakespeare.txt

To run this program:

$ python ngrams.py t8.shakespeare.txt 2 10

The command line syntax is:

$ python ngrams.py [input file] [n-gram size] [number of top n-grams to print]

Please note the structure of this python file.  We will lay things out in a
principled and conventional manner:

1. file starts with a doc string describing the file
2. import statements
3. all functions
4. the script body in an `if __name__ == "__main__": body`

"""

import sys

def get_word_list(filename):
    """return list of stripped, lower case words from a file"""
    f = open(filename,'r')
    word_list = list()
    for line in f:
        for word in line.split():
            word_list.append(word.lower().strip())
    return word_list

def count_ngrams(word_list,n):
    """return a dictionary with ngram counts
  
    Input:
      word_list: list of words
      n: size of ngrams

    Output:
      A dictionary with keys being ngram tuples and
      values being the ngram count
    """
    ngram_dict = dict()
    for i in xrange(len(word_list)-n+1):
        ngram = tuple(word_list[i:i+n])
        if ngram in ngram_dict:
            # ngram already exists in dictionary
            # increment the count by 1
            ngram_dict[ngram] += 1
        else:
            # ngram does not exist in dictionary
            # initialize to 1
            ngram_dict[ngram] = 1
    return ngram_dict

def top_ngrams(ngram_dict,ntop):
    """return a list of ntop tuples corresponding to the top ngrams"""
    # get list of all ngrams and counts
    ngrams = ngram_dict.items()
    # sort according to the count
    # we use a python lambda function here to say that we want to sort by the
    # second item in the tuples contained in the list
    ngrams.sort(key=lambda x: x[1], reverse=True)
    # return the top ngrams
    return ngrams[0:ntop]

if __name__ == "__main__":
    # script driver code

    # if no command line input, print a help message and quit
    if len(sys.argv) < 4:
        print("Usage:")
        print("$ python ngrams.py [input file] [n-gram size] [number to print]")
        sys.exit()

    # execute the main program
    word_list = get_word_list(sys.argv[1])
    ngram_dict = count_ngrams(word_list,int(sys.argv[2]))
    top_ngram_list = top_ngrams(ngram_dict,int(sys.argv[3]))

    # print the top results
    for ngram, count in top_ngram_list:
        print("{}: {}".format(ngram,count))
