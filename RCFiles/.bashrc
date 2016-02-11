
# My bashrc file.
#
# Maintainer: Nathan Caron
# Last change: 2015 Dec 01
#
# To use it, copy it to:
#     for Unix         : ~/.vimrc

# Source global definitions
if [ -f /etc/bashrc ]; then
	. /etc/bashrc
fi

# GPG-Agent stuff
# GET_TTY=$(tty)
# export $GET_TTY
# $HOME/.gnupg/gpg-agent-start.sh

# User specific aliases and functions
export PATH=$PATH:/usr/local/ccm/bin
export PATH=$PATH:/usr/local/ccm_7.1/bin
export PATH=$PATH:~/Documents/Sublime\ Text\ 2/
alias mkj='make -j8 2> /dev/stdout > /dev/null'
export TERM=xterm-256color
PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\W\[\033[00m\]\$ '
# OLD PS1: [\u@\h \W]\$


# Needed for Google Protocol Buffer programs to run properly
# export LD_LIBRARY_PATH=/home/nathan.caron/Documents/GoogleProtoBuf/protobuf/src/.libs
# (Note: Using COTS protobuf instead of local version now)


# Source for cd --
# source acd_func.sh # been combined into Functions.sh
source Functions.sh



# Aliases created through new-alias function:
alias la='ls -lah'
alias vim="~/vim74/bin/vim"
