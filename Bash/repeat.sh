#!/bin/bash

_repeat()
{
    #@ USAGE: _repeat string number
    _REPEAT=$1
    while (( ${#_REPEAT} < $2 )) ## Loop until string exceeds desired length
    do
        _REPEAT=$_REPEAT$_REPEAT$_REPEAT ## 3 seems to be the optimum number
    done
    _REPEAT=${_REPEAT:0:$2} ## Trim to desired length
}

repeat()
{
    _repeat "$@"
    printf "%s\n" "$_REPEAT"
}

alert() #@ USAGE: altert message border
{
    _repeat "${2:-#}" $(( ${#1} + 8 ))
    printf '\a%s\n' "$_REPEAT" ## \a = BEL (not sure what it does, if I remove it nothing changes)
    printf '%2.2s  %s  %2.2s\n' "$_REPEAT" "$1" "$_REPEAT"
    printf '%s\n' "$_REPEAT"
}

alert "Do you really want to delete all your files?"

alert "I am Eastwood!" $
