

###################################################################################################
###                                     Working with lists                                      ###
###################################################################################################


list = [1,2,3,4,5]
# print list # [1,2,3,4,5]
# print list[2] # 3
list2 = list + [1,2,3,4,5]
# print list2 # [1,2,3,4,5,1,2,3,4,5]
list2.append(6)
# print len(list) # 5
x = ['a','b','c']
y = [1,2,3]
z = [x,y]
# print z[0] # ['a','b','c']
# print len(x) # 3

point = [7,8]
x,y = point
# print x # 7
# print y # 8

line = ['a', 10, 20, (2014,01,31)]
x1,x2,x3,date1 = line
x1,x2,x3,(year,month,day) = line

a = [4,1,2,3]
a.reverse()
# print a
a.sort()
# print a
a.reverse()
# print a
L = [0,10,20,40]
# print L[::-1] # another way to reverse

# reverse(array) is iterable and not a list, can convert reversed array to list:

list1 = ['a', 'list', 'of', 'words']
list2 = [s.upper() for s in list1]
list3 = [s for s in list1 if len(s) <= 2]
list4 = [s for s in list1 if 'w' in s]
# print list1
# print list2
# print list3
# print list4

x = [3,1,2,4]
maxList = x.sort()
minList = x.sort(x.reverse()) # doesn't work properly

min1 = min(x)
max1 = max(x)
# print min1, max1

# print minList
minList = x.sort(reverse=True) # doesn't work properly

# print sorted(x, reverse = True)

mylist = [1,-2,3,-5,6,-7,8]
pos = [n for n in mylist if n > 0]
neg = [n for n in mylist if n < 0]
# print pos, neg

negative = [n if n < 0 else 0 for n in mylist]
positive = [n if n > 0 else 0 for n in mylist]

# print negative, positive

list1 = [1,2,3,4,5]
list2 = [2,1,3,4,5]
sort1 = sorted(list1)
sort2 = sorted(list2)
if(list1 == sort1):
    print list1,'is sorted'
else:
    print list1,'is not sorted'

list1 = ['a', 'A', 'b', 'B', 'Z']
# print sorted(list1) # Uppercase come first due to ASCII values
# print sorted(list1, reverse=True)

list1 = ['a', 'AA', 'bbb', 'BBBBB', 'ZZZZZZ']
print sorted(list1, key=len)
print sorted(list1, key=len, reverse=True)
print sorted(list1, key=str.lower)

nums = [1,2,3,4]
cubes = [n*n*n for n in nums]
print nums, cubes

parts = ['Is', 'SF', 'In', 'California?']
print ' '.join(parts)

# The most inefficient way to concatenate strings:
print "This" + " is" + " a" + " sentence."
# Either of the following is preferred:
print "%s %s %s %s" % ("This", "is", "a", "sentence.")
print " ".join(["This", "is", "a", "sentence."])



###################################################################################################
###                               Sorting, ranges, and iterating                                ###
###################################################################################################


list1 = [1,5,3,4]
# Bubble sort:
for i in range(0, len(list1)-1):
    for j in range(i+1, len(list1)):
        if(list1[i] > list1[j]):
            temp = list1[i]
            list1[i] = list1[j]
            list1[j] = temp
print "Sorted list:",list1


# Ranges
for i in range(0,5):
    continue

x = ['a','b','c','d']
for w in x:
    continue
for w in x:
    print len(w), w

# Count character types:
str1 = "abc4234AFde"
digitCount, alphaCount, upperCount, lowerCount = 0,0,0,0
for i in range(0, len(str1)):
    char = str1[i]
    if(char.isdigit()):
        digitCount += 1
    elif(char.isalpha()):
        alphaCount += 1
        if(char.upper() == char):
            upperCount += 1
        else:
            lowerCount += 1
print str1, 'Digits:',digitCount,'Alpha:',alphaCount,'Upper:',upperCount,'Lower:',lowerCount


# Arrays and append function
a = [10, 'hello', [5, '77']]
a[2].append('abc')
print a

myList = ['a', 'b', 91.1, (2014, 01, 31)]
x1,x2,x3,x4 = myList

# Split is more useful

x = "this is a string"
list = x.split()
print list
for w in x.split():
    continue # or print w to print each word per line
for w in x.split():
    if(w == 'this'):
        print 'x contains this'

# from collections import Counter # Need python 2.7 or higher for
mywords = ['a','b','a','b','c','a','d','e','f','b']
# wordcount = counter(mywords)
# topthree = wordcount.most_common(3)
# print topthree


list1 = [1,2,3]
print [3*x for x in list1] # [3,6,9]
print [[x, 3*x] for x in list1]

list2 = [5,6,7]
# Product of every pair of numbers from the two lists:
print [a*b for a in list1 for b in list2] # [5,6,7,10,12,14,15,18,21]
print [a+b for a in list1 for b in list2] # [6,7,8,7,8,9,8,9,10]

print [list1[i]*list2[i] for i in range(len(list1))] # [5, 12, 21]

a = [1,2,3,2,4,2,5]
print a.count(1), a.count(2) # Occurrences of each 1 and 2

a.insert(3, -8) # insert -8 in position 3
a.remove(3) # remove occurrences of 3
a.append(19) # add 19 to end of list
print a
a.index(19) # index of 19 in the list
a.reverse() # reverse the list
a.sort() # sort the list
b = [100,200,300]
a.extend(b) # extend list a with b
a.pop(2) # remove first occurence of 2
a.pop() # remove last item from the list

# You can use a list as a stack and a queue
# A stack is LIFO where push and pop are used to add and remove elements
s = [1,2,3,4]
s.append(5)
s.pop() # removes 5
# A queue is FIFO where insert and pop are used to insert and remove elements
q = [1,2,3,4]
q.insert(0,5) # inserts 5 at beginning of queue
q.pop(0) # removes first element from queue

from collections import deque
q = deque('', maxlen=10)
for i in range(10,20):
    q.append(i)
print q

# Tuples are comma separated values without brackets.  [] are list, () are arrays, {} are dicts.
t = 1,'a',2,'hello',3
print t

v = 10,11,t # (10,11, (1,'a',2,'hello',3))
# Tuples are immutable, so t[0] = 1000 will give an error

del list # delete it so i can use it as a call again:
lst = [1,2,3,4,5,5,2]
lst = list(set(lst))
print lst


l = ['a','b','a','c']
s = set(l)
print s

print 'a' in s
print 'd' in s


n = set('abacad')
print n

print s - n
print n - s


print s | n # Union of s and n
print s & n # Intersection of s and n
print s ^ n # Exclusive or of s and n

# dict1 = {key1:value1, key2:value2}
dict1 = {} # empty dict
dict1 = {'x':1, 'y':2}

print dict1
print dict1['x']
# print dict['z'] # will fail and crash
dict1.get('x') # 1
dict1.get('z') # returns None instead of error

# print {x: x**3 for x in (1,2,3)} # doesn't work, maybe higher python version

print 'x' in dict1
print 'z' in dict1


mydict = {'x':5, 'y':7, 'z':13}
for key, value in mydict.iteritems():
    print key, value

# Modulus operator substitutes values from dictionary into string by name
hash = {}
hash['beverage'] = 'coffee'
hash['count'] = 3
# %d for int, %s for string
s = 'Today I drank %(count)d cups of %(beverage)s' % hash

print s

# from collections import OrderedDict #doesn't work
# d = OrderedDict([('first', 1), ('second', 2), ('third', 3)])
# print d.items()

from collections import defaultdict

d = {'a':[1,2,3], 'b': [4,5]}
print d
d = defaultdict(list)
d['a'].append(1)
d['a'].append(2)
d['b'].append(4)
print d
d = defaultdict(set)
d['a'].add(1)
d['a'].add(2)
d['b'].add(4)
print d

# Python supports seven sequence types: str, unicode, list, tuple, bytearray, buffer, and xrange
# You can iterate through a sequence and retrieve index and value at same time with enumerate()

for i,v in enumerate(['x', 'y', 'z']):
    print i, v



###################################################################################################
###                                     Regular Expressions                                     ###
###################################################################################################


import re
text1 = "meta characters ? and / and + and . and *"
text2 = re.sub("[/\.*?=+]+","",text1)
print text2
print text1

# ^[0-9] matches a regex that starts with a digit
# ^[^0-9] matches a regex that doesn't start with digit
# The ^ before [] means start of text, inside means negate
#     what is directly to the ^'s right.

# \.H.* matches .Hello    H.* matches Hello    H.*\. matches Hello.
# .ell. matches Hello    .* matches Hello    \..* matches .Hello

# \d: single digit    \w: single char(digit or letter)    \s: single whitespace(return, tab)
# \b: matches boundary between word and nonword(meta-chars)   \n;\r;\t: newline, return, tab
# \: escapes any char except \n \r and \t
# \d is same as [0-9]    \D is same as [^0-9]    \s same as \t;\n;\r;\f;\v, and matches all
#     non whitespace chars, whereas \S is the opposite (matches [^ \t\n\r\f\v])
# \w same as [a-zA-Z0-9_], matches any alphanumeric char.  \W is opposite
# \d{2} same as [0-9][0-9]    \d{3} same as [0-9][3]
# \d{2,4} same as [0-9]{2,4}   \d{5,} same as [0-9]{5,}   \d+$ same as ^[0-9]+$
# NOTE: The curly braces are called quantifiers, they specify the number or range of chrs 
#    in the expressions that precede them.

# From the re module: match() - determine if the RE matches beginning of the string
# search() scan through string looking for any location where the RE matches
# findall() find all substrings where the RE matches and return them as a list
# finditer() find all substrings where the RE matches and return them as an iterator
# Note: the match() function matches the pattern only to the start of string

# re.match() method attempts to match an RE pattern in a text string(with optional flags):
# re.match(pattern, string, flag=0)
# You can specify multiple flags with | symbol
# re.match returns object on success and None on failure. 
# group(num=0) return an entire match(or specific subgroup num)
# groups() return all matching subgroups in a tuple (or impty if there aren't any)

#import re # already imported
p = re.compile('(a(b)c)de')
m = p.match('abcde')
m.group(0) # 'abcde'
m.group(1) # 'abc'
m.group(2) # 'b'

line1 = 'abcd123'
line2 = 'abcdefg'
mixed = re.compile(r"^[a-z0-9]{5,7}$") # specifies sequence lowercase letters followed by digits
                                       # with length between 5 and 7 'abcd123' satisfies condition
                                       # You can specify lower or upper limit without the other
line3 = mixed.match(line1)
line4 = mixed.match(line2)
print line1
print line2
print line3
print line4
print line4.group(0)

line6 = 'a1b2c3d4e5f6g7'
mixed2 = re.compile(r"^([a-z]+[0-9]+){5,7}$")
line7 = mixed2.match(line6)
print line6
print line7.group(0)
print line7.group(1)

line9 = 'abc123fgh4567'
mixed3 = re.compile(r"^([a-z]*[0-9]*){5,7}$")
line10 = mixed3.match(line9)
print line9
print line10.group(0)



alphas = re.compile(r"^[abcde]{5,}")
line1 = alphas.match("abcde").group(0)
line2 = alphas.match("edcba").group(0)
line3 = alphas.match("acbedf").group(0)
line4 = alphas.match("abcdefghi").group(0)
line5 = alphas.match("abcdefghi abcdef")

print 'line1:',line1
print 'line2:',line2
print 'line3:',line3
print 'line4:',line4
print 'line5:',line5


line = "Giraffes are taller than elephants";

matchObj = re.match( r'(.*) are(\.*)', line, re.M|re.I)

if matchObj:
    print "matchObj.group() :  ", matchObj.group()
    print "matchObj.group(1) : ", matchObj.group(1)
    print "matchObj.group(2) : ", matchObj.group(2)
else:
    print "matchObj does not match line:", line

# contains pair of delimiters separated by pipe symbol.  First delimiter, re.M, for "multi-line"
# in order to match more than a single line.  Second delimiter, re.I, for ignore case.
# Delimiter Options: re.I: case insensitive matches    re.L: interpret words according to current locale
# re.M: make $ match the end of a line and makes ^ match start of any line
# re.S: make a period "." match any char including newline    re.U: interpret according to unicode

# For further info check out either word with snippets from chapter, or chapter 4 itself.


p = re.compile( '(one|two|three)')
print p.sub( 'some', 'one book two books three books')
print p.sub('some', 'one book two books three books', count=1)
line = 'abcde'
line2 = re.sub('', '\n', line)
print line2

line2 = "abc1,Abc2:def3;Def4"
result2 = re.split(r'[,:;]', line2)

for w in result2:
    if w.startswith('Abc'):
        print 'Word starts with Abc:', w
    elif w.endswith('4'):
        print 'Word ends with 4:', w
    else:
        print 'Word:', w



line1 = "abcdef"
line2 = "123,abc1,abc2,abc3"
line3 = "abc1,abc2,123,456f"

if re.match("^[A-Za-z]*$", line1):
    print 'line1 contains only letters:',line1

# better than the preceding snippet:
line1[:-1].isalpha()
print 'line1 contains only letters:',line1

if re.match("^[\w]*$", line1):
    print 'line1 contains only letters:',line1

if re.match(r"^[^\W\d_]+$", line1, re.LOCALE):
    print 'line1 contains only letters:',line1
print

if re.match("^[0-9][0-9][0-9]", line2):
    print 'line2 starts with 3 digits:',line2

if re.match("^\d\d\d", line2):
    print 'line2 starts with 3 digits:',line2
print

if re.match(".*[0-9][0-9][0-9][a-z]$", line3):
    print 'line3 ends with 3 digits and 1 char:',line3

if re.match(".*[a-z]$", line3):
    print 'line3 ends with 1 char:',line3

line1 = "This is a line"
line2 = "That is a line"

if re.match("^[Tt]his", line1):
    print 'starts with this or This:', line1
else:
    print 'no match'

if re.match("^This|That", line2):
    print 'line2 starts with This or That:', line2
else:
    print 'no match'



charcount, digitcount, othercount = 0,0,0
line1 = "A line with numbers: 12 345"

for ch in line1:
    if re.match(r'\d', ch):
        digitcount += 1
    elif re.match(r'\w', ch):
        charcount += 1
    else:
        othercount += 1
print "char:", charcount
print "digit:", digitcount
print "other:", othercount


# Zero or more occurances of three consecutive letters or digits:  ^([a-zA-Z0-9]{3,3})?
# Telephone number such as 413-743-7090:  ^\d{3,3}[-]\d{3,3}[-]\d{4,4} 
# Match zipcode 01220 or 01220-1004:  ^\d{5,5}([-]\d{4,4})?
# Partially match email address:
str = 'john.doe@google.com'
match = re.search(r'\w+@\w+', str)
if match:
    print match.group() ## 'doe@google.com'



















