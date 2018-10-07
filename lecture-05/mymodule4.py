"""
My Module: a collection of miscellaneous code.

This module defines a summation sub-routine alongside a list of primes.
These utilities may be of interest to someone with interests lying at the
intersection of number theory and computation.
"""

def summation(a,b):
    """
    Returns the sum of integers  between arguments a and b, inclusive.

    We anticipate the input arguments to be each integers. The output
    under this assumption is also an integer. We remark that there
    are simple closed form solutions for this problem, using the fact
    that summation(0,n) = n*(n+1)/2.
    """

    total = 0
    for n in range(a,b+1):
        total += n
    return total

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]

if __name__ == '__main__':
    print('Testing function summation():...', end='')
    total = summation(1,100)
    if (total == 5050):
        print('OK')
    else:
        print('FAILED')
