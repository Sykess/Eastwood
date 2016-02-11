#!/bin/bash



_palindrome() #@ USAGE palindrome QUERY
{
    pal=$1
    startpos=0
    endpos=$(( ${#pal} - 1 ))

    pal=${pal^^}

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
#             echo "$1 is NOT a palindrome!"
            return 1
        else
            startpos=$(( $startpos + 1 ))
            endpos=$(( $endpos - 1 ))
        fi

    done

#     echo "$1 IS a palindrome!"
    return 0

}
palindrome()
{
#     _palindrome "$@"
    if _palindrome "$@"
    then
        echo "$1 is a Palindrome!"
    else
        echo "$1 is NOT a Palindrome!"
    fi
}

# palindrome "Able was I ere, I saw elba"
# palindrome "Nope, I'm definitely not a palindrome"
# palindrome "1244421"

