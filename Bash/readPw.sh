#!/bin/bash

read passwd
if [ ${#passwd} -lt 8 ]
then
    printf "Password is too short: %d characters\n" "$#" >&2
    exit 1
fi

var=Toronto
var=${var%o*}
printf "%s\n" "$var" # Toront
printf "%s\n" "${var%o*}" # Tor



