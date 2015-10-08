def sumofsquares(a, b):
    total = 0
    for n in range(a, b+1):
        total += squared(n)
    return total

def squared(n):
    return n*n

print sumofsquares(1,10)
