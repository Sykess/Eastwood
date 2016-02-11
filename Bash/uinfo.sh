#!/bin/bash


uinfo() #@ USAGE: uinfo [file]
{
    printf "%12s: %s\n" \
    USER    "${USER:-No value assigned}" \
    PWD     "${PWD:-No value assigned}" \
    COLUMNS "${COLUMNS:-No value assigned}" \
    LINES   "${LINES:-No value assigned}" \
    SHELL   "${SHELL:-No value assigned}" \
    HOME    "${HOME:-No value assigned}" \
    TERM    "${TERM:-No value assigned}"
} > ${1:-/dev/fd/1}


rangecheck() #@ USAGE: rangecheck checkNum lowBound highBound 
{
    if [ "$1" -lt ${2:-10} ]
    then
        return 1
    elif [ "$1" -gt ${3:-20} ]
    then
        return 2
    else
        return 0
    fi
}

_max3() #@ Sort 3 integers and store in $_MAX3, $_MID3 and $_MIN3
{       #@ USAGE:
    [ $# -ne 3  ] && return 5
    [ $1 -gt $2 ] && { set -- $2 $1 $3; }
    [ $2 -gt $3 ] && { set -- $1 $3 $2; }
    [ $1 -gt $2 ] && { set -- $2 $1 $3; }
    _MAX3=$3
    _MID3=$2
    _MIN3=$1
    name=nobody
}


max3() #@ Sort 3 integers and store in an array
{      #@ USAGE: max3 N1 N2 N3 [VARNAME]
    declare -n _max3=${4:-_MAX3}
    (( $# < 3 )) && return 4
    (( $1 > $2 )) && set -- "$2" "$1" "$3"
    (( $2 > $3 )) && set -- "$1" "$3" "$2"
    (( $1 > $2 )) && set -- "$2" "$1" "$3"
    _max3=( "$3" "$2" "$1" )
}

. date-funcs




