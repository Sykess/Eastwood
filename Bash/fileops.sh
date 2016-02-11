#!/bin/bash


###################################################################################################
###                                        READING FILES                                        ###
###################################################################################################

# Ways to read files:
while read ## no name supplied so variable REPLY is used
do
    : # do something with $REPLY here
done < "newfile.txt"

while read name phone
do
    printf "Name: %-10s\tPhone: %s\n" "$name" "$phone"
done < "newfile.txt" # or format "$file"

# IFS uses spaces by default, could change to other separators
while IFS=- read name phone
do
    printf "Name: %-10s\tPhone: %s\n" "$name" "$phone"
done < "newfile.txt"

# Placing an assignment in front of a command causes it to be local to that command
# and does not change its value elsewhere in the script.

# while IFS=: read book chapter verse text
# do
#     firstword=${text%% *}
#     printf "%s %s:%s %s\n" "$book" "$chapter" "$verse" "$firstword"
# done < "kingjamesbible.txt"


# cat *.txt | tr aeiou AEIOU > upvowel.txt
# {
#     date
#     cat report.txt
#     printf "Signed: "
#     whoami
# } | mail -s "Here is the report" blah@example.com

# cat thisfile.txt | head -n 25 > thatfile.txt # WRONG
# head -n 25 thisfile.txt > thatfile.txt # CORRECT

# cat "$@" | while read x; do whatever; done
# while read x; do : whatever; done < <( cat "$@" )

# by default, head prints the first 10 lines of each file on the cmd line, or from standard input if no filename
head -n 1 "kingjamesbible.txt" # changes it to 1 with -n
filetop=$( head -n 1 "kingjamesbible.txt") # head is unecessary here since only taking 1 line:
read filetop < "kingjamesbible.txt"
book=${filetop%%:*}
text=${filetop##*:} # having to split the line makes head inefficient, can use:

IFS=: read book chapter verse text < "kingjamesbible.txt"
# ./sa "$book" "$chapter" "$verse" "${text%% *}"

# Even reading multiple lines into vars can be faster using the shell instead of head:
{
    read line1
    read line2
    read line3
    read line4
} < "kingjamesbible.txt"
# or put lines in array:

for n in {1..4}
do
    read lines[${#lines[@]}]
done < "kingjamesbible.txt"

# in bash 4 can use builtin command mapfile to populate array:
mapfile -tn 4 lines < "kingjamesbible.txt" # mapfile explained further ch13


###################################################################################################
###                            CREATING FILES AS WELL AS USING TOOLS                            ###      
###                               SUCH AS CUT, AWK, GREP AND SED                                ###
###################################################################################################



# default action of touch is to update timestamp of file to current time, creating file if doesn't exist.
# an argument to the -d option changes to that timestamp rather than the present.  It is not necessary to use
# touch to create a file, the shell can do it with redirection:
# > filename

# can create multiple files in shell as well:
# for file in {a..z}$RANDOM
# do
#     >"$file"
# done

# for file in $(ls); do # incorrect because of word splitting in files with spaces, eg:
# touch {zzz,xxx,yyy}\ a # create 3 files with a space then a in their names
# for file in $(ls *\ *); do echo "$file"; done # displays xxx, a, yyy, a, zzz, a

# The correct way is:
# for file in **; do echo "$file"; done # *\ * instead of ** will only display files with spaces

# Cut extracts potions of a line specified by char or field.  options are -b, -c, and -f, bytes, chars, fields.

# cut -c 22 "kingjamesbible.txt" | head -n3
# cut -c 22,24,26 "kingjamesbible.txt" | head -n3
# cut -c 22-26 "kingjamesbible.txt" | head -n3

# cut can be used to extract a portion of a string.

boys="Brian,Carl,Dennis,Mike,Al"
# printf "%s\n" "$boys" | cut -d, -f3 # Uses external command
IFS=,  #no external command
boyarray=( $boys )
# printf "%s\n" "${boyarray[2]}"

temp=${boys#*,*,} # even better, more portable
# printf "%s\n" "${temp%%,*}" # all 3 prints printout Dennis


# wc counts lines, words, and bytes.  By default, prints all 3 in that order followed by file name
wc "kingjamesbible.txt" /etc/passwd # multiple files will show both and total results

wc < "kingjamesbible.txt"

wc -l "kingjamesbible.txt" # prints linecount and filename.  Can also use -c and -w options (char and word)


# can get number of lines in var like so:
# IFS=$'\n'
# set -f
# set -- $var
# echo $#

# grep searches files on the command line, or standard input if no files given, and prints lines matching regex
# grep ':0[57]0:001:' "kingjamesbible.txt" | cut -c -78

# the shell can do the same job, but much slower: (waaaay slower!)
# while read line
# do
#     case $line in
#         *0[57]0:001:*) printf "%s\n" "${line:0:78}" ;;
#     esac
# done < "kingjamesbible.txt"

# grep and other external cmds can be used to select lines from file and pipe results to shell script:
grep 'Psalms:023' "kingjamesbible.txt" | 
{
    total=0
    while IFS=: read book chapter verse text
    do
        set -- $text
        total=$(( total + $# )) # set puts verse into positional params, total adds the num of params
    done
    echo $total
}

# sed = stream editor.  used for replacing string or pattern with another string.  also good for pulling
# a particular line or range of lines from file.  To get first 3 lines of book of Leviticus and convert upcase:
sed -n '/Lev.*:001:001/,/Lev.*:001:003/ s/Leviticus/LEVITICUS/p' "kingjamesbible.txt" | cut -c -78
# the -n tells sed not to print anything unless specifically told to do so.  default is to print all lines
# whether modified or not.  The two regexes enclosed in slashes and separated by a comma, define a range
# from the line that matches the first one to the line that matches the second; s is a command to search and replace

# when modifying file, standar Unix practice is to save output to new file and move back to old one if command successful

# sed 's/this/that/g' "$file" > tempfile && mv tempfile "$file"

# some recent vers of sed have -i option that will change the file in situ.  If used, option should be given suffix:
# sed -i.bak 's/this/that/g' "$file"


# awk -F: ' ## -F: sets the field delimiter to a colon
# {
#     ## split the fourth field into an array of words
#     split($4,words," ")
#     ## printf the first three fields and the first word of the fourth
#     printf "%s %s:%s %s\n", $1, $2, $3, words[1]
# }' "kingjamesbible.txt" # prints shortened version of all lines, like the function above

# find the shortest verse in KJV:
# (script checks length of fourth field, if its less than value of shortest field so far, its length, 
# minus length of the name of the book, is measured with the length() function and stored in min, and
# the line is stored in verse.  At the end, verse is printed)

awk -F: 'BEGIN { min = 999 } ## set min larger than any verse length
length($0) - length($1) < min {
    min = length($0) - length($1)
    verse = $0
}
END { print verse }' "kingjamesbible.txt"


# find string Jesus wept, print it and the previous and next lines:
awk '/Jesus wept/ {
    print previousline
    print $0
    n = 1
    next
}
n == 1 {
    print $0
    print "---"
    n = 2
}
{
    previousline = $0
}' "kingjamesbible.txt"

# To total a column of numbers: (adds 12 to 34 all together)
printf "%s\n" {12..34} | awk '{ total += $1 }
END { print total }' # 529


###################################################################################################
###                                 FILE NAME EXPANSION OPTIONS                                 ###
###################################################################################################


shopt -s extglob ## enable the extglob option
shopt -u nocaseglob ## disable the nocaseglob option

# mkdir "$HOME/globfest" && cd "$HOME/globfest" || echo Failed >&2
# touch {a..f}{0..9}{t..z}$RANDOM .{a..f}{0..9}$RANDOM #creates 420 files starting with a letter and 60 with a dot
cd "$HOME/globfest"
sa a1*

# Nullglob: normall if sa *xy doesn't match, will print :*xy:
shopt -s nullglob
sa *xy # now will print ::
shopt -u nullglob # return to normal

# Failglob: If the failglob is set and no files match wildcard, error message is printed
shopt -s failglob
sa *xy # bash: no match: *xy
shopt -u failglob # return to normal

# dotglob: normally wildcard doesn't match "hidden" files that start with .

sa * | wc -l # 420
sa .* | wc -l # 62 (including . and ..)
shopt -s dotglob
printf "%s\n" * | wc -l # 480 (with dotglob enabled * does not include . and ..)
shopt -u dotglob

# touch {john,paul,george,ringo}{john,paul,george,ringo}{1,2}$RANDOM\
#     {john,paul,george,ringo}{1,2}$RANDOM{,,} {1,2}$RANDOM{,,,}


# pr4 ?(john|paul)2* #matches 0 or 1 occurance of given patterns
# pr4 *(john|paul)2* # matches same as ^ as well as those with either pattern more than once in succession
# pr4 @(john|paul)2* # matches files that have a single instance of either pattern followed by 2
# pr4 +(john|paul)2* # matches file begin with one or more instance of pattern followed by 2
# pr4 !([jpr0-9]*) # matches anything except given pattern

# when nocaseglob is set, lowercase letters match uppercase letters, and vice versa

# touch {{a..d},{A..D}}$RANDOM
# pr4 *
# pr4 [ab]* # default behavior only matches same case
# shopt -s nocaseglob
# pr4 [ab]* # now will match both cases
# shopt -u nocaseglob

# bash 4 introduced globstar option allows use of ** to descend recursively into dir and subdirs for matching files
# mkdir -p {ab,ac}$RANDOM/${RANDOM}{q1,q2}/{z,x}$(( $RANDOM % 10 ))
# echo
# shopt -s globstar
# pr4 **
# shopt -u globstar











































