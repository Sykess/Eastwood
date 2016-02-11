#!/bin/bash
# Keeps getting user input until value is between 20 and 30

n=0
printf "%s" "Enter an integer between 20 and 30: "
until [ $n -gt 20 -a $n -lt 30 ]
do
    read n
    case $n in
        *[!0-9]*) 
            printf "%s %s" "$n" "is not a valid integer! Try again: "
            n=0
            ;;
        2[1-9]) ;;
        *)
            printf "%d%s: " "$n" " is not between 20 and 30! Try again"
            ;;
    esac
done
printf "%s%d Thank you!\n" "You have entered the valid integer: " "$n"



printf "Enter the name of a file or directory: "
read n

until [ -e $n ]
do
    printf "%s does not exist! Try again: " "$n"
    read n
done
printf "%s does exist, thank you and goodbye!\n" "$n"


