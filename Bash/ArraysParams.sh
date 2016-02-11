#!/bin/bash

# shift will move all parameters one to the left, ie $2 becomes $1 etc.  shift 3 moves 3 over
# shift "$#" removes all parameters
# shift "$(( $# - 2 ))" removes all but last 2
# To access parameters greater than 9, {} required ie ${10}

# 2 ways to cycle parameters:
# for param in "$@" # or just for param
# do
#     : do something with $param
# done
# or:
# while (( $# ))
# do
#     : do something with $1
#     shift
# done

printf "%s\n" "${BASH_VERSINFO[0]}" #4
printf "%s\n" "${BASH_VERSINFO[1]}" #1 so 4.1


printf "%s\n" "${BASH_VERSINFO[*]}" # same line
printf "%s\n" "${BASH_VERSINFO[@]}" # separate lines

# for 2nd and 3rd elements from array, use [@]:1:2
printf "%s\n" "${#BASH_VERSINFO[*]}" # the # length expansion returns # of elements in array when * or @
                                     # if a number subscript is given, the length of the element at the index
printf "%s\n" "${#BASH_VERSINFO[2]}" "${#BASH_VERSINFO[5]}" 

name[0]=Aaron
name[42]=Adams # sparse array, there are no 1-41 elements
unset a
a[${#a[@]}]="1 $RANDOM" ## ${#a[@]} is 0
a[${#a[@]}]="2 $RANDOM" ## ${#a[@]} is 1
a[${#a[@]}]="3 $RANDOM" ## ${#a[@]} is 2
a[${#a[@]}]="4 $RANDOM" ## ${#a[@]} is 3
# printf "%s\n" "${a[@]}"

province=( Quebec Ontario Manitoba ) # Array populated with 1 command
# printf "%s\n" "${province[@]}" # access whole array
province+=( Saskatchewan ) # append an element to the array
province+=( Alberta "British Columbia" "Nova Scotia" ) # append 3 more elements
printf "%-25s %-25s %s\n" "${province[@]}"

# Associative arrays use strings as subscripts and must be declared before using

declare -A array
for subscript in a b c d e
do
    array[$subscript]="$subscript $RANDOM"
done
printf ":%s:\n" "${array["c"]}" ## print one element
printf ":%s:\n" "${array[@]}" ## print the entire array















