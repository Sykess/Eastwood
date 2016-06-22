
def sieve (n):
    lim = n+1
    primes = dict()
    for i in range(2, lim): primes[i] = True
    for i in primes:
        factors = range(i, lim, i)
        for f in factors[1:]:
            primes[f] = False
    return [i for i in primes if primes[i] == True]

primes = sieve(100)
for i in primes:
    if 150 % i == 0:
        print i

