
# print 2 ** 1000

lastName = "Smith"
count = 0
for letter in lastName:
#     print(letter," ",count)
    count += 1

# print("--------")
count=0
while (count<5):
#     print(lastName[count]," ",count)
    count+=1

# print range(5) # also print range(0,5) and print list(range(5))

components = 'propython.com'.split('.') # components- ['propython', 'com']
domain, tld = 'propython.com'.split('.') # domain-propython, tld-com
# domain, tld = 'www.propython.com'.split('.') # error! number of vars must match
# domain, *path = 'propython.com/example/url'.split('/') # domain-propython.com, path-['example','url'](py3)

output = []
for value in range(10):
    if value > 5:
        output.append(str(value))
# print output

output = [str(value) for value in range(10) if value > 5]
# print output

# print min([value for value in range(10) if value > 5])

gen = (value for value in range(10) if value > 5) #()'s create generator
# print gen
# print min(gen)# if call min again after this, error
# print (min(value for value in range(10) if value > 5))

# print {str(value) for value in range(10) if value > 5} # prints a set. Sets are unordered, (py3)
# print set(str(value) for value in range(10) if value > 5) # (py2 way of ^^)

# print {value: str(value) for value in range(10) if value > 5} #(py3)
# print dict((value, str(value)) for value in range(10) if value > 5) # (py2 way of ^^)

import itertools
# print list(itertools.chain(range(3), range(4), range(5))) # chain iterables

# print list(zip(range(3), reversed(range(5)))) # Zip will use length of smallest iterator, in this case 3
keys = map(chr, range(97, 102))
values = range(1,6)
# print dict(zip(keys, values))

def unique_letters(word):
    return set(word.lower())
# print unique_letters('eggs')

example = set([1,2,3,4,5])
# example = {1,2,3,4,5} # (py3)
# print 4 in example
# print 6 in example
example.add(6)
example.update([6,7,8,9])
example.remove(9) #if call remove on 9 again will crash
example.discard(8) # if call discard multiple times, will not crash
# print example.pop() # will pop off random number, since sets are unordered
example.clear() # empties whole set

# print set([1,2,3]) | set([4,5,6])
# print set([1,2,3]).union(set([4,5,6])) # same as ^^

# print set([1,2,3,4,5]) & set([4,5,6,7,8]) # can also use intersection() just like union above

# print set([1,2,3,4,5]) - set([2,4,6]) # can also use difference()

# print set([1,2,3,4,5]) ^ set([4,5,6]) # can also use symmetric_difference() (all items in either set, but not both)

# print set([1,2,3]).issubset(set([1,2,3,4,5])) # true, can also use issuperset, or subtract from eachother to see if empty

from collections import namedtuple
Point = namedtuple('Point', 'x y')
point = Point(13, 25)
# print point
# print point.x, point.y
# print point[0], point[1]

# from collections import OrderedDict # (py3)
# d = OrderedDict((value, str(value)) for value in range(10) if value > 5)
# print d
from collections import defaultdict
def count_words(text): # creates dict with text as key and int of how many times that word occured
    count = defaultdict(int)
    for word in text.split(' '):
        count[word] += 1
    return count
# print count_words("hello hello hello where are you you you")

try:
    from hashlib import md5 # new library added after 2.5
except ImportError:
    from md5 import new as md5 # old library before 2.5


def add_prefix(string, prefix='pro_'):
    """Adds a 'pro_' prefix before the string provided."""
    return prefix + string
# mystring = input("Enter a string to put pro_ in front of it!: ")
# print(add_prefix(mystring))
# print add_prefix("fill", "land")

class ShoppingCart:
    def add_to_cart(*items):
        self.items.extend(items)
cart = ShoppingCart








