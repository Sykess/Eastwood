#!/bin/bash


var=
./sa "${var:-default}" # :default: (if var wasn't empty would display var's contents)
var=
./sa "${var-default}" # var is set, so expands to nothing ::
unset var
./sa "${var-default}" # var is unset, so expands to "default" :default:


var=
./sa "${var:+alternate}" #var is set but empty ::
var=value
./sa "${var:+alternate}" #var is not empty :alternate:
var=
./sa "${var+alternate}" # :alternate:
unset var
./sa "${var+alternate}" # ::
var=value
./sa "${var+alternate}" # :alternate:

var=
for n in a b c d e f g
do
    var="$var $n"
done
./sa "$var" # : a b c d e f g:

var=
for n in a b c d e f g
do
    var="${var:+"$var "}$n"
done
./sa "$var" # :a b c d e f g (this method drops leading space)

#that was shorthand method of doing the following for each value of n:

if [ -n "$var" ]
then
    var="$var $n"
else
    var=$n
fi

# or:

[ -n "$var" ] && var="$var $n" || var=$n


# ${var:=default} expansion behaves same way as ${var:-default} except also assigns default value to variable

unset n
while :
do
    echo :$n:
    [ ${n:=0} -gt 3 ] && break # set $n to 0 if unset or empty
    n=$(( $n + 1))
done


var=Toronto
./sa "${var%%o*}" # :t: The var is expanded, and the longest string that matches pattern from end of expanded val is removed

var=Toronto
./sa "${var#*o}" # :ronto: Var expanded, shortest string matches pattern is removed from beginning of expanded val

scriptname=${0##*/} # gets just scriptname from the full path contained at $0
echo $scriptname

passwd=zxQ1.=+-a
printf "%s\n" "${passwd//?/*}" # replaces all letters with *'s from double slash
printf "%s\n" "${passwd/[[:punct:]]/*}" # only replaces first punctuation found because of single slash

# ${var:OFFSET:LENGTH} return substring of var
var=Toronto
./sa "${var:3:2}" # :on:
./sa "${var:3}" # :onto:
./sa "${var: -3}" # :nto:

x=yes
a=x
./sa "${!a}" # :yes:

eval "./sa \$$a" # :yes:

var=toronto
echo "${var^}" # Toronto (matches first char)
echo "${var^[n-z]}" # matches first char so Toronto
echo "${var^^[n-q]}" # matches all char n-q so tOrONtO
echo "${var^^}" # TORONTO
echo "${var,,}" # converts all to lowercase
echo "${var~}" # flips case of first char, ~~ flips all chars (flip=invert)









