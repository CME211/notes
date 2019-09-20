import numpy
import time

t0 = time.time()
total = sum(numpy.ones(1000000,dtype=numpy.int32))
t1 = time.time()
print(total)
print("time = {}".format(t1-t0))
