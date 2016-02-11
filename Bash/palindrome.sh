#!/bin/bash

echo -n "Enter a string to see if its a palindrome: "
read pal

while [ ${#pal} == 0 ] # while no input
do
    echo -n "You must enter a string: "
    read pal
done

startpos=0
endpos=$(( ${#pal} - 1 ))

pal=${pal^^}
echo $pal

# echo $endpos
# echo ${pal:$startpos:$startpos+1}
while [ $startpos -lt $endpos ]  
do
    if [[ ${pal:$startpos:1} =~ [A-Z0-9] ]]
    then
        :
    else
        startpos=$(( $startpos + 1 ))
        continue
    fi
    if [[ ${pal:$endpos:1} =~ [A-Z0-9] ]]
    then
        :
    else
        endpos=$(( $endpos - 1 ))
        continue
    fi

    if [[ ${pal:$startpos:1} != ${pal:$endpos:1} ]]
    then
        echo "$pal is NOT a palindrome!"
        exit 1
    else
        startpos=$(( $startpos + 1 ))
        endpos=$(( $endpos - 1 ))
    fi

done

echo "$pal IS a palindrome!"


