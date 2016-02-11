

###################################################################################################
###                                   Reserved words and loops                                  ###
###################################################################################################


# Reserved words: and, exec, not, assert, finally, or, break, for, pass, class, from, print
#                 continue, global, raise, def, if, return, del, try, elif, in, while, else, is,
#                 with, except, lambda, and yield.

x = ['a', 'b', 'c']
for w in x: # loops x, putting each value in w
    print w, # adding comment adds space instead of newline 
print # newline
for w in reversed(x): # iterates backwards
    print w,
print


line = '1 2 3 4 10e abc'
sum = 0
invalidStr = ""

print 'String:', line
for i in line.split(" "):
    try:
        sum = sum + int(i)
    except:
        invalidStr = invalidStr + i + ' '
print 'sum:', sum
print 'Invalid strings:', invalidStr

def pwr(num, exp):
    prod = 1
    for n in range(1, exp + 1):
        prod = prod * num
    return prod
# for num in range(1, 5):
#     print num, "to the power of 5 is", pwr(num, 5)

# Nested loops:
max = 8
# for x in range(1, max+1): # prints a "stairs-like" shape with numbers
#     for y in range(1, x+1):
#         print y,
#     print

# Split and join are opposites of eachother

x = 'This is a string that contains abc and Abc'
y = 'abc'
identical = 0
casematch = 0
for w in x.split():
    if(w == y):
        identical += 1
    elif (w.lower() == y.lower()):
        casematch += 1
if(identical):
    print 'found identical matches:', identical
if(casematch):
    print 'found case matches:', casematch
if(not casematch and not identical):
    print 'no matches found'

# Using loops with justification

str1 = 'this is a string with a set of words in it'
wordCount = 0

print 'left-justified strings:'
print '-----------------------'
for w in str1.split():
#     print '%-10s' %w,
    wordCount += 1
    if(wordCount % 2 == 0):
        print '',
# print '\n'
# print 'right-justified strings:'
print '------------------------'
wordCount = 0

for w in str1.split():
#     print '%10s' %w,
    wordCount += 1
    if(wordCount % 2 == 0):
        print '',
print '\n'


# Print "newspaper-style" column

left, right, columnWidth = 0,0,8

str1 = 'this is a string with a set of words in it and it will be split into a fixed column width'
strLen = len(str1)

# print 'Left-justified column:'
# print '----------------------'
rowCount = strLen/columnWidth
# print 'row:', rowCount

for i in range(0, rowCount):
    left = i * columnWidth
    right = (i + 1) * columnWidth - 1
    word = str1[left:right]
#     print "%-10s" %word
# check for a 'partial row'
if(rowCount * columnWidth < strLen):
    left = rowCount * columnWidth - 1
    right, word = strLen, str1[left:right]
#     print "%-10s" %word

# Comparing strings
text1 = 'a b c d'
text2 = 'a b c e d'
if(text2.find(text1) >= 0):
    print 'text1 is a substring of text 2'
else:
    print 'text1 is not a substring of text2'

subStr = True
for w in text1.split():
    if(text2.find(w) == -1):
        subStr = False
        break

if( subStr == True):
    print 'Every word in text1 is a word in text2'
else:
    print 'Not every word in text1 is a word in text2'

text = 'abcdef'
# for ch in text:
#     print('char:', ch, 'ord value:', ord(ch))
print


text1 = '    there are     extra     spaces     '
print 'text1:', text1

text2 = ' '.join(text1.split())
print 'text2:', text2

text2 = 'XYZ'.join(text1.split())
# print 'text2:', text2

# Can use while loops:
x = 0
while x < 5:
    print x,
    x += 1
print

lst = [1,2,3,4]
while lst: # proceeds until list is empty
    print 'list:', lst,'item:', lst.pop()


###################################################################################################
###                                      Conditional logic                                      ###
###################################################################################################


x = 25
if x < 0:
    print 'negative'
elif x < 25:
    print 'under 25'
elif x == 25:
    print 'exactly 25'
else:
    print 'over 25'

# Break allows early exit from a loop, continue returns to top of loop with next value loop var
# Pass statement is essentially "do nothing"

print 'first loop'
for x in range(1, 4):
    if(x == 2):
        break
    print x
print 'second loop'
for x in range(1, 4):
    if(x == 2):
        continue
    print x
print 'third loop'
for x in range(1, 4):
    if(x == 2):
        pass
    print x

# in and not in used with sequences to check whether value occurs or not in a sequence
# is and is not determine whether or not 2 objects are the same object
# comparisons can be chained as in a < b == c
string1, string2, string3 = '', 'b', 'cd'
str4 = string1 or string2 or string3 # becomes 'b'



###################################################################################################
###                               Scope and functions and lambdas                               ###
###################################################################################################


# can specify nonlocal variables: nonlocal z
# can specify explicitly global with: global z
global z
z = 3
def changeVar(z):
    z = 4
    print 'z in function:', z
print 'first global z:', z
changeVar(z)
print 'second global z:', z

# a global variable:
total = 0
def sum(x1, x2):
    #this total is local
    total = x1+x2
    print "Local total:", total
    return total
sum(2,3)
print "Global total:", total

g = globals()
# print g # view all global variables and their values (can also use locals()
# print g.pop('z')

# ALL arguments in Python are pssed by REFERENCE

def changeme(myList):
    "This changes a passed list into this function"
    myList.append([1,2,3,4])
#     print "Values inside the function:", mylist
    return

myList = [10,20,30]
changeme(myList)
# print "Values outside of function:", myList # will be same as inside function

def foo(x, y):
    return x - y
data = 4,5 # tuple
# foo(data) # error only one argument
# foo(*data) # passes however many args are in tuple, this is successfully -1

def divisors(num):
    div = 2
    while(num > 1):
        if(num % div == 0):
#             print "divisor:", div
            num /= div
        else:
            div += 1
#     print "**finished**"
divisors(56)

def divisors(num): # convert divisors to a string
    divList = ""
    div = 2

    while(num > 1):
        if(num % div == 0):
            divList += str(div) + ' '
            num /= div
        else:
            div += 1
    return divList
result = divisors(12)
print "Divisors of 12 are:", result

def divisors(num):
    count, div = 1, 2
    while( div < num):
        if(num % div == 0):
            count += 1
        div += 1
    return count
result = divisors(12)
if(result == 1):
    print '12 is prime'
else:
    print '12 is not prime'

def numberFunc(a, b=10):
    print (a,b)
def stringFunc(a, b='xyz'):
    print (a,b)
def collectionsFunc(a, b=None):
    if(b is None):
        print 'no value assigned to b'
numberFunc(3)
stringFunc('one','two')
collectionsFunc([1,2,3])

# Functions can return multiple values:
def multipleValues():
    return 'a', 'b', 'c'
x,y,z = multipleValues()
# x=a, y=b, z=c

# You can set variable number of arguments:
def sum(*values):
    sum = 0
    for x in values:
        sum += x
    return sum
# print sum(1,3,5,7)
values = (1,2,3,4)
s1 = sum(*values) # s1 = 10


# Lambda Expressions

add = lambda x, y: x + y
x1 = add(5, 7) # 12
x2 = add('Hello', 'Python') # HelloPython


# Recursion:

def factorial(num):
    if(num > 1):
        return num * factorial(num - 1)
    else:
        return 1
result = factorial(5)
# print result # 120

# The factorial can also be done with iteration:
def factorial2(num):
    prod = 1
    for x in range(1, num+1):
        prod *= x
    return prod

result = factorial2(5)
# print result # also 120

def fib(num):
    if(num == 0):
        return 1
    elif(num == 1):
        return 1
    else:
        return fib(num-1) + fib(num-2)
result = fib(10)
# print result # 89

# Greatest common denominator:
def gcd(num1, num2):
    if(num1 % num2 == 0):
        return num2
    elif(num1 < num2):
#         print "Switching", num1, num2
        return gcd(num2, num1) # switches nums so num1 is greater
    else:
#         print "Reducing", num1, num2
        return gcd(num1-num2, num2)
result = gcd(24, 10)
print result

# Least common multiple is defined: lcm(x,y) = x/gcd(x,y) * y/gcd(x,y)
def lcm(num1, num2):
    gcd1 = gcd(num1, num2)
    lcm1 = num1/gcd1 * num2/gcd1
    return lcm1
result = lcm(24, 10)
print result







