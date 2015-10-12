import time

t0 = time.time()
total = 0
for n in range(1000000):
    total += 1
t1 = time.time()
print(total)
print("time = {}".format(t1-t0))
