#!/bin/bash

# functions work like: name() <compound command>
# bash also allows: function name() <compound command>
# Load functions into terminal by using . ShellFunctions.sh (may have to set permissions)


isvalidip() #@ USAGE: isvalidip DOTTED-QUAD
{
    case $1 in
        ## reject the following:
        ##   empty string
        ##   anything other than digits and dots
        ##   anything not ending in a digit
        "" | *[!0-9.]* | *[!0-9]) return 1 ;;
    esac

    ## Change IFS to a dot, but only in this function
    local IFS=.

    ## Place the IP address into the positional parameters;
    ## after word splitting each element becomes a parameter
    set -- $1

    [ $# -eq 4 ] && ## must be four parameters
                    ## each must be less than 256
    ## A default of 666 (which is invalid) is used if a parameter is empty
    ## All four parameters must pass the test
    [ ${1:-666} -le 255 ] && [ ${2:-666} -le 255 ] &&
    [ ${3:-666} -le 255 ] && [ ${4:-666} -le 255 ]
}

valint() #@ USAGE: valint INTEGER
{
    case ${1#-} in              ## Leading hyphen removed to accept negative numbers
        *[!0-9]*) false;;       ## the string contains a non-digit character
        *) true ;;              ## the whole number, and nothing but the number
    esac
}

funky() ( name=nobody; echo "name = $name" ) # ()'s so vars are only local to function
name=Rumpelstiltskin
funky
echo "name = $name"












