#!/bin/bash

# Input stream, output stream, error stream, called FDs (file descriptors) 
# They are 0, 1, and 2.  Also contracted to stdin, stdout, stderr
# Can create file with printf "" > FILENAME, or just: > FILENAME.  > truncates file if exists
# >> appends to file.  
# can use FD specifier to send stderr to file such as 2> ERRORFILE
# Instead of sending output to file, can be redirected to another IO using >&N, N is FD
# &> FILE redirects both stdout and stderr to same place
# &>> appends both stdout and stderr to FILE
# tr, H wY < bin/hw : command that reads from stdin can have input redirected from file
# can use exec to redirect IO stream for rest of script, or until changed:
#   exec 1>tempfile, exec 0<datafile, exec 2>errorfile

# read is builtin command that reads from standard input, by default until newline receieved. read var
# -r option makes shell interpret escape sequences literally
# read var < FILENAME gets input from first line from FILENAME

# > newfile.txt # creates new file named newfile.txt, or erases the existing one
# echo exit 0 >> newfile.txt # appends exit 0 to end of newfile.txt.  Will create if doesn't exist
# printf '%s\n%v\n' OK? Oops! > FILE 2> ERRORFILE # prints OK? to file, error msg to ERRORFILE
# cat ERRORFILE # displays errorfile

# printf '%s\n%v\n' OK? Oops! 2>/dev/null # sends error message to bit bucket, discards it
# printf '%s\n%v\n' OK? Oops! > FILE 2>&1 # sends output and error to FILE
# printf '%s\n%v\n' OK? Oops! 2>&1 > FILE # order sends error to where output originally went, then output to file

# read a b c d # will read 1 word into each var, with remaining words to last var
# echo $a
# echo $b
# echo $c
# echo $d

# $RANDOM returns random int between 0 and 32767
# printf "%s\n" "$RANDOM" "$RANDOM" "$RANDOM" "$RANDOM" | tee FILENAME # tee passes to file as well as stdout

# Output of command can be stored in variable using command substitution using 1 of 2 methods:
# date=`date` # backticks, not recommended
# date=$( date ) # newer, recommended way
# Command substitution should be reserved for external commands.  When used with builtin, it is slow. 
#  That is why -v option was added to printf








