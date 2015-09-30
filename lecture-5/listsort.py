import random
import sys
import time

if len(sys.argv) < 2:
    print('Usage:')
    print(' {} nvalues'.format(sys.argv[0]))
    sys.exit()
    
n = int(sys.argv[1])

# Setup a list of random values and record the time required to sort it
v = random.sample(xrange(n), n)
t0 = time.time()
v.sort()
t1 = time.time()

print("Sorting {} values took {:.3} seconds.".format(n, t1-t0))
