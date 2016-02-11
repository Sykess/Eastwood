#!/bin/bash

var=strip
allbutfirst=${var#?} # trip
allbutlast=${var%?} # stri

first=${var%"$allbutfirst"} # s
last=${var#"$allbutlast"} # p

printf -v first "%c" "$var" # for some reason not working



while [ -n "$var" ] # Loop through and operate on 1 char at a time
do
    temp=${var#?}       ## everything but first char
    char=${var%"$temp"} ## remove everything but first char
    # do something with $char
    var=$temp           ## assign truncated value to var
done


_revstr() #@ USAGE: revstr STRING (reversed string stored in _REVSTR)
{
    var=$1
    _REVSTR=
    while [ -n "$var" ]
    do
        temp=${var#?}
        _REVSTR=${var%"$temp"}$_REVSTR
        var=$temp
    done
}

_revstr "Cornholioo!"
# echo $_REVSTR

echo abcdefgh | tr ceh CEH # abCdEfgH
echo abcdefgh | tr ceh HEC # abHdEfgC
echo touchdown | tr 'a-z' 'A-Z' # TOUCHDOWN


to_upper()
    case $1 in
        a*) _UPR=A ;; b*) _UPR=B ;; c*) _UPR=C ;; d*) _UPR=D ;;
        e*) _UPR=E ;; f*) _UPR=F ;; g*) _UPR=G ;; h*) _UPR=H ;;
        i*) _UPR=I ;; j*) _UPR=J ;; k*) _UPR=K ;; l*) _UPR=L ;;
        m*) _UPR=M ;; n*) _UPR=N ;; o*) _UPR=O ;; p*) _UPR=P ;;
        q*) _UPR=Q ;; r*) _UPR=R ;; s*) _UPR=S ;; t*) _UPR=T ;;
        u*) _UPR=U ;; v*) _UPR=V ;; w*) _UPR=W ;; x*) _UPR=X ;;
        y*) _UPR=Y ;; z*) _UPR=Z ;;  *) _UPR=${1%${1#?}} ;;
    esac

word=function
to_upper "$word"
printf "%c%s\n" "$_UPR" "${word#?}" # prints word with first letter capitalized

_upword()  #@ USAGE: upword STRING
{
    _UPWORD=
    local word=$1
    while [ -n "$word" ] # loop until nothing is left in $word
    do
        to_upper "$word"
        _UPWORD=$_UPWORD$_UPR
        word=${word#?}  # remove the first character from $word
    done
}
upword()
{
    _upword "$@"
    printf "%s\n" "$_UPWORD"
}
#post bash 4.x you can rewrite _upword like so:
_upword()
{
    _UPWORD=${1^^}
}


# upword "blah blah blah"

echo -n "Enter y/n: "
# read ok
case $ok in
    y|Y) echo "Great!" ;;
    n|N) echo Good-bye
    exit 1
    ;;
    *) echo Invalid entry ;;
esac

# or use bracketed char list:
echo -n "Enter y/n: "
# read ok
case $ok in
    [yY]) echo "Great!" ;;
    [nN]) echo Good-bye
        exit 1
        ;;
    *) echo Invalid entry ;;
esac

echo -n "Enter a month: "
# read monthname
case $monthname in
    [Jj][Aa][Nn]*) month=1 ;;
    [Ff][Ee][Bb]*) month=2 ;;
    # etc..
    [1-9]|[1[0-2]) month=$monthname ;; # accept month number entered
    *) echo "Invalid month: $monthname" >&2 ;;
esac

# better way is convert input to uppercase first:

# _upword "$monthname"
# case $_UPWORD in ## convert $monthname to number
case ${monthname^^} in # or simply convert it here
    JAN*) month=1 ;;
    FEB*) month=2 ;;
    # etc..
    [1-9]|1[0-2]) month=$monthname ;; # accept number
    *) echo "Invalid month: $monthname" >&2 ;;
esac


validname() #@ USAGE: validname varname
    case $1 in
        # doesn't begin with letter or _ or contains something other than letter, number, or _
        [!a-zA-Z_]* | *[!a-zA-Z0-9_]* ) return 1 ;;
    esac

for name in name1 2var first.name first_name last-name _undername __
do
    validname "$name" && echo "valid: $name" || echo "invalid: $name"
done


_insert_string() #@ USAGE: _insert_string STRING INSERTION [POSITION]
{
    local insert_string_dflt=1                  # default insert location
    local string=$1                             # container string
    local i_string=$2                           # string to be inserted
    local i_pos=${3:-${insert_string_dflt:-2}}  # insert location
    local left right                            # before and after strings
    left=${string:0:$(( $i_pos  ))}          # string to left of insert
    right=${string:$(( $i_pos  ))}           # string to right of insert
    _insert_string=$left$i_string$right         # build new string
}

insert_string()
{
    _insert_string "$@" && printf "%s\n" "$_insert_string"
}

insert_string "fooltop" " in " 4 


_overlay() #@ USAGE: _overlay STRING SUBSTRING START, result in $_OVERLAY
{
    local string=$1
    local sub=$2
    local start=$3
    local left right
    left=${string:0:start}
    right=${string:start+${#sub}}
    _OVERLAY=$left$sub$right
}

overlay() #@ USAGE: overlay STRING SUBSTRING START
{
    _overlay "$@" && printf "%s\n" "$_OVERLAY"
}

overlay pony b 0
overlay pony u 1
overlay pony s 2
overlay pony d 3
overlay pony it 1
overlay pony it

# Remove unwanted spaces (or any char you want)
var="       Nate             "
while : # infinite loop
do
    case $var in
        ' '*) var=${var#?} ;; # remove leading space
        *' ') var=${var%?} ;; # remove trailing space
        *) break ;; # no more leading or trailing spaces
    esac
done
echo $var

var="       Nate           "
rightspaces=${var##*[! ]} # remove everything up to the last non-space
var=${var%"$rightspaces"} # remove $rightspaces from $var
leftspaces=${var%%[! ]*} # remove from the first nonspace to the end
var=${var#"$leftspaces"} # remove leftspaces from var, var now contains "Nate"


_trim() #@ Trim spaces (or characters in $2) from $1
{
    local trim_string
    _TRIM=$1
    trim_string=${_TRIM##*[!${2:- }]}
    _TRIM=${_TRIM%"$trim_string"}
    trim_string=${_TRIM%%[!${2:- }]*}
    _TRIM=${_TRIM#"$trim_string"}
}
trim() #@ Trim spaces or chars and print result
{
    _trim "$@" && printf "%s\n" "$_TRIM"
}
trim "       s p a c e d   o u t       "
trim "0000345349.9345000000" 0
trim "232323hidden2323232323" 23


_index() #@ Store position of $2 in $1 in $_INDEX
{
    local idx
    case $1 in
        "") _INDEX=0; return 1 ;;
        *"$2"*) ## extract up to beginning of the matching portion
                idx=${1%%"$2"*}
                ## the starting position is one more than the length
                _INDEX=$(( ${#idx} + 1 )) ;;
        *) _INDEX=0; return 1 ;;
    esac
}
index()
{
    _index "$@"
    printf "%d\n" "$_INDEX"
}

_month2num()
{
    local months=JAN.FEB.MAR.APR.MAY.JUN.JUL.AUG.SEP.OCT.NOV.DEC
    _upword "${1:0:3}" # take first 3 letters of $1 and convert to uppercase
    _index "$months" "$_UPWORD" || return 1
    _MONTH2NUM=$(( $_INDEX / 4 + 1 ))
}
month2num()
{
    _month2num "$@" &&
    printf "%s\n" "$_MONTH2NUM"
}

month2num 9














