n = 10

if n >= 0:
    fn2 = 0             # Initialize f(n-2).
    print(fn2,end=',')
if n >= 1:
    fn1 = 1             # Initialize f(n-1).
    print(fn1,end=',')
for i in range(2,n+1):  # Here is where we iterate from 2:n.
    fn = fn1 + fn2      # Recurrence relation is f(n) = f(n-1) + f(n-2).
    print(fn,end=',')
    fn2 = fn1           # Update our values...
    fn1 = fn            # ...for both f(n-2) and f(n-1).
print()
