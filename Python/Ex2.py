
# Triangular output:

for i in range(0, 8):
    for j in range(0, 8):
        if(j > i):
#             print "#",
            pass
        else:
#             print "*",
            pass
#     print


def primeSieve(limit):
    limitn = limit + 1
    not_prime = [False] * limitn
    primes = []

    for i in range(2, limitn):
        if not_prime[i]:
            continue
        for f in xrange(i*2, limitn, i):
            not_prime[f] = True
        primes.append(i)
    return primes


primes = primeSieve(100)

# Find pair of primes that adds to every even number 4-100
for i in range(2, 100, 2):
    for j in primes:
        for k in primes:
            if(j + k == i):
#                 print i,"is the sum of", j,"and",k
                break


print "a and then go to".title()

# Print numbers divisible by 2 or 3 but not by any other prime
for i in range(2, 101):
    primes = primeSieve(100)
    primes.remove(2)
    primes.remove(3)
    for j in primes:
        if(i % j == 0):
            break 
        if(i % 2 == 0 or i % 3 == 0 ):
#             print i, ' ',
            break









