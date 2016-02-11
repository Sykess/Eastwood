#!/bin/bash

# basically just drops current directory when you pass a full path to it

case $1 in
     */*) printf "%s\n" "${1%/*}" ;;
     *) [ -e "$1" ] && printf "%s\n" "$PWD" || echo '.' ;;
esac

echo "2.3 + 3.6" | bc
