"""
My module of misc code.
"""

import types

def summation(a,b):
    """
    Returns the sum of numbers between, and including, a and b.
    """

    if (type(a) != types.IntType or type(b) != types.IntType):
        raise ValueError, 'Expected integers'

    total = 0
    for n in range(a,b+1):
        total += n
    return total

primes = [2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47]

if __name__ == '__main__':
    print('Testing function summation():...'),
    total = summation(1,100)
    if (total == 5050):
        print('OK')
    else:
        print('FAILED')
