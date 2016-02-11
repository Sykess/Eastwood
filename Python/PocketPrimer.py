#!/bin/python



###################################################################################################
###                               Beginning math and format info                                ###
###################################################################################################

# You can see what functions work on string-related methods:
# print dir(str)
# print dir(__builtins__)
# You can also do import string then dir(string) to see available functions
# And you can keep going within functions FOREVER

# You can get help on how to use methods and whatnot:
# help(str.lower)


# To set a variable to empty:
var = None
# To destroy it:
del var

var = 17
print bin(var)
print hex(var)
print format(var, 'b')
print format(var, 'x')

x = chr(65)
print x # A


result = ""
for x in range(65,91):
#     print x, chr(x)
    result = result + chr(x) + ' '
print "result: ", result

# could also use range 97,123
for x in range(ord('a'), ord('z')+ 1 ): # +1 to include z
    result = result + chr(x) + ' '

print "result: ", result

print round(1.23, 1) # second number is precision (number of digits)
print round(-3.42, 1)

x = 1.23456
print format(x, '0.2f') # 1.23
print format(x, '0.3f') # 1.235
# 'value is {:0.3f}'.format(x) # this one doesn't work >.>

from decimal import Decimal
a = Decimal('4.2')
b = Decimal('2.1')
print a + b
print (a + b) == Decimal('6.3')

x = 1234.56789
print format(x, '>10.1f') # right justified in 10 chars, 1 digit accuracy
print format(x, '<10.1f') # left justified
print format(x, '^10.1f') # centered
# print format(x, ',') # include 1000's separator (these dont work either o_O)
# print format(x, '0,.1f') # separator and 1 digit accuracy

from fractions import Fraction
a = Fraction(5, 4)
b = Fraction(7, 16)
print a + b
print a * b

c = a * b
print c.numerator
print c.denominator
print float(c)
print c.limit_denominator(8) # not sure how this works
print c

x = 3.75
y = Fraction(*x.as_integer_ratio())
print y

chinese1 = u'\u5c07\u63a2\u8a0e HTML5 \u53ca\u5176\u4ed6'
hiragana = u'D3 \u306F \u304B\u3063\u3053\u3043\u3043 \u3067\u3059!'

print chinese1
print hiragana


###################################################################################################
###                                    Working with strings                                     ###
###################################################################################################


print 'a' + 'b' # prints 'ab'
print 'a' * 3 # prints 'aaa'
x = 'abc'
y = 'def'
print x + y # prints 'abcdef'

# You can "unpack" letters of a string to variables
str1 = "World"
x1,x2,x3,x4,x5 = str1 # x1=W, x2=o, x3=r, x4=l, x5=d

x = 'abcdef'
# x[0] = 'a'    x[-1] = 'f'    x[1:3] = 'bc'    x[0:2] + x[5:] = 'abf'

print 'Python'.lower() # 'python'
print 'Python'.upper() # 'PYTHON'

x = 'Abc'
y = 'abc'
if(x == y):
    print 'x and y: identical'
elif(x.lower() == y.lower()):
    print 'x and y: case insensitive match'
else:
    print 'x and y are different'

import string
str1 = 'this is a string'
print string.ljust(str1, 10) # book said lstring, but dir says ljust
print string.rjust(str1, 40)
print string.center(str1, 40) # these position text left, right, and center

print 'First 7 chars:', str1[0:7]
print 'Chars 2-4:', str1[2:4]
print 'Right-most char:', str1[-1]
print 'Right-most 2 chars:', str1[-3:-1] # can do str1[-3:] to display last 3 chars

# You can also use format to justfiy:

text = "test string"
print format(text, '>20') # right justify
print format(text, '<20') # left justify
print format(text, '^20') # center

str1 = "4"
str2 = "4234"
str3 = "b"
str4 = "abc"
str5 = "a1b2cde3"
if(str1.isdigit()):
    print "this is a digit:", str1
if(str2.isdigit()):
    print "this is a digit", str2
if(str3.isalpha()):
    print "this is alphabetic:", str3
if(str4.isalpha()):
    print "this is alphabetic:", str4
if(not str5.isalpha()):
    print "this is not pure alphabetic:", str5

print "capitalized first letter:", str5.title()

item1 = 'abc'
item2 = 'Abc'
text = 'This is a text string with abc'

pos1 = text.find(item1)
pos2 = text.find(item2)
print 'pos1=', pos1
print 'pos2=', pos2 # Returns -1 it no match

lst = [1,2,3]
print 1 in lst # True

print 'text:', text
text = text.replace('is a', 'was a')
print 'text:', text

text = '     leading and trailing whitespace     '
print 'text1:', 'x', text, 'y'
text = text.lstrip()
print 'text2:', 'x', text, 'y'
text = text.rstrip()
print 'text3:', 'x', text, 'y'

import re
text = 'a    b'
a = text.replace(' ', '') #eliminate all spaces
b = re.sub('\s+', ' ', text) #drop multi spaces to single space

print a, b


x = str(9) + str(0xff) + str(-3.1) # adds while suppressing whitespace
print 'x:', x

import sys
print str(sys)

write = sys.stdout.write # can make your own write to suppress whitespace
write('123')
write('456\n')


import time
import datetime

print "Time in seconds since epoch: %s" %time.time()
print "Current date and time:", datetime.datetime.now()
print "Another format:", datetime.datetime.now().strftime("%y-%m-%d-%H-%M")
print "Current year:", datetime.date.today().strftime("%Y")
# using ^^ can print month: %B, Week # of year: %W, Weekday of the week: %w
#                           Day of year: %j, Day of month: %d, Day of week: %A

# Can also perform arithmetic calculations with date values:
from datetime import timedelta
a = timedelta(days=2, hours=6)
b = timedelta(hours=4.5)
c = a + b
print c.days
print c.seconds
print c.seconds/3600
# print c.total_seconds() / 3600 # My python has no total_seconds()

# Can convert a string to a date:
from datetime import datetime
text = '2014-08-13'
y = datetime.strptime(text, '%Y-%m-%d')
z = datetime.now()
diff = z - y
print 'Date difference:', diff


###################################################################################################
###                              Exception handling and user input                              ###
###################################################################################################


try:
    x = 4
    y = 'abc'
    z = x + y
except:
    print 'cannot add incompatible types:', x, y

try:
    print 'a' - 'b'
except TypeError:
    print 'TypeError while trying to subtract two strings'
except:
    print 'Exception while trying to subtract two strings'


import sys
try:
    f = open('myfile.txt')
    s = f.readline()
    i = int(s.strip())
except IOError as err:
    print("I/O error: {0}".format(err))
except ValueError:
    print("could not convert data to an integer.")
except:
    print("Unexpected error:", sys.exc_info()[0])
    raise # "raises" an exception

# can also specify multiple exceptions in a single statement:
# except (NameError, RuntimeError, TypeError):
#     print 'One of three error types occurred'


# userInput = raw_input("Enter your name: ")
# print "Hello, %s, my name is Python" % userInput # they added ; at end, although not needed

# userInput = raw_input("Enter something: ")
userInput = 23 # just made it up for testing
try:
    x = 0 + eval(userInput) # eval should be avoided so code does not evaluate destructive cmds
    print 'you entered the number:', userInput
except:
    print userInput, 'is a string'

sum = 0
msg = 'Enter a number:'
# val1 = raw_input(msg)
val1 = 15

try:
    sum = sum + eval(val1)
except:
    print val1, 'is a string'

msg = 'Enter a number:'
# val2 = raw_input(msg)
val2 = 15

try:
    sum = sum + eval(val2)
except:
    print val2, 'is a string'

print 'The sum of', val1, 'and', val2, 'is', sum

# Command line arguments:
# import sys (commented because already imported)
print 'Number of arguments:', len(sys.argv), 'arguments'
print 'Argument List:', str(sys.argv)

# If you had a custom class that contains methods add and subtract could use cmd line args:
# python MyClass add 3 5
# python MyClass subtract 3 5


# import sys

def main():
    if len(sys.argv) >= 2:
        name = sys.argv[1]
    else:
        name = 'World'
    print 'Hello', name

if __name__ == '__main__': # standard boilerplate to invoke main() function
    main()







