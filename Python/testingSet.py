
test = set()
from fractions import Fraction

max = 1000000

for n in range(1, max+1):
    for d in range(1, n):
        test.add(Fraction(n,d))

print len(test)









