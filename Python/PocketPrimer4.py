

###################################################################################################
###                                   File related operations                                   ###
###################################################################################################

import os
# os module caontains following:
# os.listdir(dir): list filenames in a directory
# os.path.join(dir, filename): returns path of a filename
# os.path.abspath(path): returns an absolute path
# os.path.dirname(path): returns the directory of a file
# os.path.basename(path): returns filename
# os.path.exists(path): true if path exists
# os.mkdir(dir_path): creates directory
# os.makedirs(dir_path): creates multiple directories
# shutil.copy(source-path, dest-path): copies a file to a destination

import stat
filename = "PocketPrimer.py"
stat = os.stat(filename)

print stat
readPerm = os.access(filename, os.R_OK)
writePerm = os.access(filename, os.W_OK)
execPerm = os.access(filename, os.X_OK)
print 'read permission:', readPerm
print 'write permission:', writePerm
print 'execute permission:', execPerm

# You can change file permissions via chmod() function
# filename = "DirList3.py"
# mode = 0444
# method 1
# os.chmod(filename, mode)
# method 2
#os.chmod(filename, stat.S_IRUSR|stat.S_IRGRP|stat.S_IROTH)
#                        ^0400        ^040         ^4  
# Performing bitwise OR results in 0444

# can redirect stdout and stderr from command line as follows:
# python MyScript.py 1>stdout 2>stderr
# python MyScript.py 2>&1 1>stdout # redirects stdout and stderr to same file
# python MyScript.py 1>stdout 2>/dev/null # redirect stderr to nowhere

# Equivalent code block for redirecting stdout:
# import os
# f = open(os.devnull, 'w')
# sys.stdout = f


# Create new file with w option:
# f.closed
with open('somefile', 'wt') as f:
    f.write('Hello Python\n')
# The with statement automatically closes the file after code block is completed

# Can check if a file exists and if it does delete it:
import os
myfile = "abc"
if os.path.exists(myfile):
    print "abc exists, deleting it!"
    os.remove(myfile)
else:
    print "abc does not exist"

# Can remove empty directory with: os.rmdir()
# Can delete directory and all its contents with:
# import sutil
# shutil.rmtree()

file = '/home/nathan.caron/Documents/Learning/Python/PocketPrimer.py'
if os.path.exists(file):
    print file, "exists"
else:
    print file, "does not exist"
print 'basename:', os.path.basename(file)
print 'directory:', os.path.dirname(file)
# Join path components together:
print 'join:', os.path.join('tmp', 'myfile', os.path.basename(file))

file = '~/myfile.csv'
print 'expanded:', file
print 'expand user:', os.path.expanduser(file)
# Split file extension
file = '/Users/blah/myfile.csv'
print 'split:', os.path.splitext(file)


# Redirect output of print to file:
import sys
filename = 'outputfile'
# sys.stdout = open(filename, 'w')
print 'test'
# Alternatively, from cmd line, python PocketPrimer4.py > outputfile  will print all output


# Open file in read mode:
f = open('test.txt', 'r')
# f.readline() # reads single line
# f.readlines() # reads all lines (starting where left off since already read one line ^^
# f.read(size) # reads at most size chars from file

# data = f.read()
# print data
# print "that was data"
f.close()

# Another way to open a file and display its content:
with open('failures.txt', 'rt') as f: data = f.read()
print data

# Another way display line numbers:
count = 1
with open('failures.txt', 'rt') as f:
    for line in f:
        print count,":",line,
        count += 1

print
filename = 'failures.txt'
file = open(filename, 'rt')
str = file.read() # read entire contents of file
print 'file contents:', str
print 'char count:', len(str)
file.close()

# Another way to count line numbers:
lineCount = sum(1 for line in open(filename))
print 'linecount:',lineCount

# Yet another way:
file = open(filename, 'rt')
lines = file.read().split("\n")
file.close()
print 'line count:', len(lines) # Also prints end newline


# Print a file backwards:
f = open('failures.txt')
for line in reversed(list(f)):
    print line, 
f.close()
# Note that this method converts iterable to list so could be memory consuming if large


# Writing data to a text file
text1 = 'a string of text'
with open('sample2.txt', 'wt') as f: f.write(text1)

filename = 'sample2.txt'
file = open(filename, 'w') # open in write only mode, to append use 'at'
str = 'put me in the file'
file.write(str)
file.close()

file = open(filename, 'at')
file.write(str) # in python interactive, whill display amt of chars written (15 here)
file.write('\n')
file.write('This is a test\n')

del str
# Non strings must be converted before writing to a file:
value = ('the answer', 42)
s = str(value)
file.write(s)
file.close()

text2 = 'a string of text2'
with open('sample2.txt', 'at') as f: f.write(text2)


with open('binaryfile.bin', 'wb') as f: f.write(b'Hello Python')
with open('binaryfile.bin', 'rb') as f: data = f.read()
print data


import os, tempfile
text = b"hello python"

# Illustrates how to create temporary file in Python (not working though!)
# def temp_opener(name, flag, mode=0o777):
#     return os.open(name, flag | os.O_TEMPORARY, mode)
# with tempfile.NamedTemporaryFile() as f:
#     f.write(text)
#     f.flush()
#     with open(f.name, "rb", opener=temp_opener) as f:
#         assert f.read() == text
# assert not os.path.exists(f.name)



# Finding and setting the file location:
# f.tell() # specifies current position in file(measured in bytes from beginning of file)
# f.seek(offset, from_what) # changes position of a file object
# The from_what argument is where to start: 0 for beginning of file (and is default)
# 1 is from current file position, and 2 uses end of file as the reference point

f = open('workfile', 'rb+')
f.write(b'0123456789abcdef')
f.seek(4) # 4
print f.read(1) # read next byte (4)
f.seek(-3, 2) # go to third byte before end
print f.read(1) # d
f.close()

with open('workfile', 'r') as f:
    read_data = f.read()
print f.closed # True since with auto closes even with exceptions

# Check if it is a regular file:
print os.path.isfile('/etc/passwd')
print os.path.isdir('/etc/passwd')
print os.path.islink('/usr/local/bin/python2') # check if it is a symbolic link
print os.path.realpath('MyLink') # where the symlink points to
print os.path.getsize('/etc/passwd')
print os.path.getmtime('/etc/passwd')
import time
print time.ctime(os.path.getmtime('/etc/passwd'))


# List all files and subdirectories of current directory:
filenames = os.listdir('.')
# print 'Directory list:', filenames

# Display contents of directory, along with additional info
from fnmatch import fnmatch, fnmatchcase
matchCount, otherCount = 0,0
filenames = os.listdir('.')
# for f in filenames:
#     if(fnmatch(f, '*.txt')):
#         print 'file ends in txt:', f
#         matchCount += 1
#     else:
#         otherCount += 1
# 
# print 'match count:', matchCount
# print 'other count:', otherCount


# Use a glob function to find a set of files in a directory, along with additional info about each entry:
import os
import os.path
import glob

pyfiles = glob.glob('*.py')
name_sz_date = [(name, os.path.getsize(name), os.path.getmtime(name)) for name in pyfiles]
# for name, size, mtime in name_sz_date:
#     print name, size, mtime
# Alternative: get file metadata
# file_metadata = [(name, os.stat(name)) for name in pyfiles]
# for name, meta in file_metadata:
#     print(name, meta.st_size, meta.st_mtime

# Function that displays the full path of every file in a directory:
def MyDir(dir):
    filenames = os.listdir(dir)
    for filename in filenames:
        print filename ## foo.txt

        ## dir/foo.txt (relative to current dir)
#         print os.path.join(dir, filename) # both display same for me
        print os.path.abspath(os.path.join(dir, filename))
# MyDir('/home/nathan.caron/Documents')



# Counting the words in a text file:
words = dict()
with open('sample2.txt', 'rt') as f:
    for line in f:
        for w in line.split():
            try:
                if(words[w] == 0):
                    words[w] = 1
                else:
                    words[w] += 1
            except:
                words[w] = 1

# for key in words: print(key, words[key])


str = 'me'
with open('sample2.txt', 'rt') as f:
    print 'Matching Lines:'
    for line in f:
        pos1 = line.find(str)
        if pos1 >= 0:
            print '###', line

# Emulating the grep command

def FindStringInFile(f):
    str = 'me'
    with open(f, 'rt') as f:
        print 'Matching Lines:'
        for line in f:
            pos1 = line.find(str)
            if pos1 >= 0:
                print '$$$', line
filenames = os.listdir('.')
for f in filenames:
     if(f is file): # doesn't work, pound it out but dirs break prog
        print 'Searching file:', f
        FindStringInFile(f)


# Reading from a file with comma separated values (CSV)
import csv
import string
totalCost, unitPrice, itemQuantity, fieldWidth = 0,0,0,20

print 'Purchase Order Total'
with open('test.csv') as f:
    f_csv = csv.reader(f)
    headers = next(f_csv)
    for row in f_csv:
        # process each row
        unitPrice = float(row[1])
        itemQuantity = int(row[2])
        lineItemPrice = unitPrice * itemQuantity
        totalCost += lineItemPrice

        print 'Item:', string.ljust(row[0], fieldWidth),
        print 'Cost:', lineItemPrice
print 'Total cost:', totalCost


# Working with data files with items in a range of columns
import re
#1-5:   Organization name
#10-19: Accounting Cycle
#22-28: Internal Routing
#30-48: Credit Card Number

filename = 'Data.txt'
with open(filename, 'rt') as f:
    for line in f:
        if re.match(r'^$', line):
            pass # print 'skipping empty line'
        elif re.match(r'^[#]', line):
            pass # print 'skipping comment:', line
        else:
            orgName = line[0:5]
            accCycle = line[9:19]
            intRoute = line[21:28]
            CCNumber = line[29:48]
            print 'line:', orgName, accCycle, intRoute, CCNumber

















