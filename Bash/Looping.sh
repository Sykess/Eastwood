#!/bin/bash

# States of a file can be tested.  Existance: -e (or nonstandard -a). File type: -f for regular file
#   -d for directory, -h or -L for symbolic link.
# Integers can be compared using -eq, -ne, -gt, -lt, -ge, and -le options.
#   (equal, not equal, greater than, less than, greater/equal, less/equal)
# Strings are concatenations of zero or more characters and can include any char except NUL (ascii 0)
#   Can use = for equality, != for inequality.  Can use == for equality, but not necessary.

# ${var-default} - if var is not set, will use default

test -f /etc/fstab # true if a regular file
# echo $? # 0 for true, non 0 for false
test -h /etc/rc.local # true if symbolic link
[ -x "$HOME/bin/hw" ] # true if you can execute the file
# echo $?
[[ -s $HOME/bin/hw ]] # true if file exists and is not empty
# echo $?

test 1 -eq 1 # true
[ 2 -eq 1 ] # false
[ 2 -ne 1 ] # true

test "$a" = "$b"
[ "$q" != "$b" ]

# the -z and -n operators return successfully if their arguments are empty or nonempty.
[ -z "" ] # true
test -n "" # false

str1=abc
str2=def
test "$str1" \< "$str2" # true.  Note the < must be escaped.
test "$str1" \> "$str2" # false

# Can combine tests in single call to test with -a (&&) and -o (||)
# test -f /path/to/file -a $test -eq 1
# test -x bin/file -o $test -gt 1 # gt = greater than, x = executable

# The feature of [[ ... ]] that is not duplicated elsewhere is the ability to match exended regex using =~ operator
string=whatever
[[ $string =~ h[aeiou] ]] # true
[[ $string =~ h[sdfghjkl] ]] # false

test $(( a - 2 )) -ne 0 # (( arithmetic expr)) returns false if expr evaluates to 0 and true otherwise
if (( total > max )); then : ...; fi
((verbose)) && command # execute command if verbose != 0

# Non-numeric values are equivalent to 0
y=yes
# ((y)) && echo $y || echo n
# nLists

# A list is a sequence of one or more commands separated by ;, #, control operators, or newlines
# A list may be used as the condition in a while or until loop, an if statement, or as body of any loop.
# The exit code of a list is the exit code of the last command in the list.

# if <condition list>
# then
#       <list>
# fi
# Usually, the <condition list> is a single command, very often a test.

# read name
# if [[ -z $name ]] # -z operand to test checks whether a name was entered
# then
#     echo "No name entered" >&2
#     exit 1 # Set failed return code
# fi

# printf "Enter a number not greater than 10: "
# read number
# if (( number > 10 ))
# then
#     printf "%d is too big\n" "$number" >&2
#     exit 1
# else
#     printf "You entered %d\n" "$number"
# fi

# printf "Enter a number between 10 and 20 inclusive: "
# read number
# if (( number < 10 ))
# then
#     printf "%d is too low\n" "$number" >&2
#     exit 1
# elif (( number > 20 ))
# then
#     printf "%d is too high\n" "$number" >&2
#     exit 1
# else
#     printf "You entered %d\n" "$number"
# fi

# test -d "$directory" && cd "$directory" # check for a dir and cd into it if it exists
# cd "$HOME/bin" || exit 1 # change to dir or exit if it fails

# mkdir "$HOME/bin" && cd "$HOME/bin" || exit 1 # Tries to create and change to dir, if fails, exit with error

# if [ -d "$dir" ] && cd "$dir"
# then
#     echo "$PWD"
# fi # echo is executed if both tests are successful

# case WORD in
#     PATTERN) COMMANDS ;;
#     PATTERN) COMMANDS ;; # optional
# esac

case $1 in
    *"$2"*) true ;;
    *) false ;;
esac # determine if one string is contained in another

case $1 in
    *[!0-9]*) false;;
    *) true;;
esac # tests if the string is a valid number

# case $# in
#     3) ;; # we need 3 args, so do nothing
#     *) printf "%s\n" "Please provide three names" >&2
#     exit 1
#     ;;
# esac # Check whether there are a correct number of arguments

# 3 types of loops: while, until, and for

# while <list>
# do
#     <list>
# done

n=1
# while [ $n -le 10 ]
# do
#     echo "$n"
#     n=$(( $n + 1 ))
# done

# while true # : can be used in place of true
# do
#     read x
# done # infinite loop

# while IFS= read -r line
# do
#     : do something with "$line"
# done < FILENAME? # read line by line from file

# until loops as long as the condition fails.  Opposite of while
n=1
until [ $n -gt 10 ]
do
#     echo "$n"
    n=$(( $n + 1 ))
done

# for var in Canada USA Mexico
# do
#     printf "%s\n" "$var"
# done 

# Also has a nonstandard form similar to C
# for (( n=1; n<=10; ++n ))
# do
#     echo "$n"
# done

# while :
# do
#     read x
#     [ -z "$x" ] && break
# done # Will break once empty read is entered

for n in a b c d e
do
    while true
    do
        if [ $RANDOM -gt 20000 ]
        then
#             printf .
            break 2 # break out of both while and for loops
        elif [ $RANDOM -lt 10000 ]
        then
#             printf '"'
            break # break out of the while loop
        fi
    done
done

for n in {1..9} # range 1-9
do
    x=$RANDOM
    [ $x -le 20000 ] && continue
#     echo "n=$n x=$x"
done




















