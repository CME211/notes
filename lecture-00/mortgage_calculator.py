# mortgage amount in dollars
L = 100000
# yearly interest rate of 4%
r = .04
c = r / 12
# duration of mortgage in months
n = 360
P = L * (c*(1+c)**n) / ((1+c)**n-1)
print("P = " + str(P))
