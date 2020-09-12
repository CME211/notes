n = 10

if n >= 0:
    fn2 = 0
    print(fn2,end=',')
if n >= 1:
    fn1 = 1
    print(fn1,end=',')
for i in range(2,n+1):
    fn = fn1 + fn2
    print(fn,end=',')
    fn2 = fn1
    fn1 = fn
print()
