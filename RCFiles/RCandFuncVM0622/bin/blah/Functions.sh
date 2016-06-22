################################################################################
# Name:         sa                                                             #
# Description:  Separates arguments for help learning bash                     #
# Usage:        sa "anything you" want to "say here"                           #
# Created:      8-25-2015                                                      #
################################################################################
sa()
{
    pre=: post=:
    printf "$pre%s$post\n" "$@"
}
export -f sa

################################################################################
# Name:         addtotar                                                       #
# Description:  Allows you to add files to a compressed archive file           #
# Usage:        addtotar archive.tar.gz file1 file2 file3...                   #
# Created:      11-21-2015                                                     #
################################################################################
addtotar() 
{
    zippedArchiveName=$1
    archiveName=`echo $zippedArchiveName | rev | cut -c 4- | rev`
    gunzip $zippedArchiveName
    shift
    tar -uf $archiveName $@
    gzip $archiveName
}
export -f addtotar

################################################################################
# Name:          pr4                                                           #
# Description:   Calculates column width, used for bash learning               #
# Usage:         pr4 file                                                      #
# Created:       8-25-2015                                                     #
################################################################################
pr4()
{
    ## calculate column width
    local width=$(( (${COLUMNS:-80} - 2) / 4 ))

    ## Note that braces are necessary on the second $width to separate it from 's'
    local s=%-$width.${width}s
    printf "$s $s $s $s\n" "$@"
}
export -f pr4

################################################################################
# Name:         followLink                                                     #
# Description:  Allows you to find absolute path of a symbolic link            #
# Usage:        followLink symlink                                             #
# Created:      9-30-2015                                                      #
################################################################################
followLink()
{
    # -z is true if length of string is zero.
    if [ -z "$1" ]
    then
        echo "Must specify first link"
        return 1
    fi

    # Adds / to end of link if not alredy there
    if [ "${1:(-1)}" == '/' ]
    then
        FILE=$1
    else
        FILE=$1/
    fi

    # Checks all chars except last, since readlink returns
    # path with /, but returns nothing if you include the /
    while [[ -L "${FILE%?}" || -L "$FILE" ]]
    do
        TEMP=`readlink "${FILE%?}"`

        if [ -z "$TEMP" ]
        then
            TEMP=`readlink "$FILE"`
        fi

        FILE=$TEMP
        echo "$FILE"
    done
}
export -f followLink

################################################################################
# Name:         new-alias                                                      #
# Description:  Function to create new aliases on the fly                      #
# Usage:        new-alias [alias-name [alias-definition]]                      #
# Created:      9-10-1015                                                      #
################################################################################
new-alias () 
{
    if [ -z "$1" ]; then
        echo "Alias name:"
        read NAME
    else
        NAME=$1
    fi

    if [ -z "$2" ]; then
        echo "Alias definition:"
        read DEFINTION
    else
        if [ "$2" = "-cd" ]; then
            DEFINTION='cd '
        else
            DEFINTION=$2
        fi
    fi
    echo "alias $NAME='$DEFINTION'" >> ~/.bashrc
    . ~/.bashrc
}
export -f new-alias


################################################################################
# Name:         vim-process-swap                                               #
# Description:  Lets you view current file against its swap and compare        #
# Usage:        vim-process-swap file [swapfile [recoverfile]]                 #
# Created:      11-30-2015                                                     #
################################################################################
function vim-process-swap
{
    local swapfile_first=0
    while true; do
        case "$1" in
            ""|-h|--help)
                echo "usage: vim-process-swap file [swapfile [recoverfile]]" >&2
                return 1;;
            -s)
                shift
                swapfile_first=1;;
            *)
                break;;
        esac
    done
    local realfile=`readlink -f "$1"`
    local path=`dirname "$realfile"`
    local realname=`basename "$realfile"`
    if [ $swapfile_first -eq 1 ]; then
        local swapfile=$realfile
        realname=${realname:1:-4}
        realfile="${path}/${realname}"
    else
        local swapfile=${2:-"${path}/.${realname}.swp"}
    fi
    local recoverfile=${3:-"${path}/${realname}-recovered"}
    local lastresort=0
    for f in "$realfile" "$swapfile"; do
        if [ ! -f "$f" ]; then
            echo "File $f does not exist." >&2
            return 1
        #elif fuser "$f"; then
        #    echo "File $f in use by process." >&2
        #    return 1
        fi
    done
    if [ -f "$recoverfile" ]; then
        echo "Recover file $recoverfile already exists. Delete existing recover file first." >&2
        return 1
    fi
    vim -u /dev/null --noplugin -r "$swapfile" -c ":wq $recoverfile"
    if cmp -s "$realfile" "$recoverfile"; then
        rm "$swapfile" "$recoverfile"
    elif [ "$realfile" -nt "$swapfile" ] && [ `stat -c%s "$realfile"` -gt `stat -c%s "$recoverfile"` ]; then
        echo "Swapfile is older than realfile, and recovered file is smaller than realfile"
        if _prompt_yn "Delete recovered file and swapfile without doing diff?"; then
            rm "$swapfile" "$recoverfile"
        else
            lastresort=1
        fi
    else
        lastresort=1
    fi

    if [[ "$lastresort" -ne 0 ]]; then
        rm "$swapfile"
        vimdiff "$recoverfile" "$realfile"
        if _prompt_yn "Delete recovered file?"; then
            rm "$recoverfile"
        fi
    fi
}

################################################################################
# Name:         _prompt_yn                                                     #
# Description:  Helper function for vim-process-swap, prompts user for y|n     #
# Usage:        _prompt_yn   (returns boolean)                                 #
# Created:      11-30-2015                                                     #
################################################################################
function _prompt_yn
{
    while true; do
        read -p "$1 [y|n] " yn
        case $yn in
            [Yy]* ) return 0;;
            [Nn]* ) return 1;;
            * ) echo "Please answer yes or no.";;
        esac
    done
}
export -f vim-process-swap
export -f _prompt_yn

###############################################################################
# Name:           cd_func                                                     #
# Description:    Function that makes cd -- work                              #
# Usage:          cd -- to see list, cd -# to go to # dir                     #
# Created:        10-nov-2004                                                 #
###############################################################################
cd_func ()
{
  local x2 the_new_dir adir index
  local -i cnt

  if [[ $1 ==  "--" ]]; then
    dirs -v
    return 0
  fi

  the_new_dir=$1
  [[ -z $1 ]] && the_new_dir=$HOME

  if [[ ${the_new_dir:0:1} == '-' ]]; then
    #
    # Extract dir N from dirs
    index=${the_new_dir:1}
    [[ -z $index ]] && index=1
    adir=$(dirs +$index)
    [[ -z $adir ]] && return 1
    the_new_dir=$adir
  fi

  #
  # '~' has to be substituted by ${HOME}
  [[ ${the_new_dir:0:1} == '~' ]] && the_new_dir="${HOME}${the_new_dir:1}"

  #
  # Now change to the new dir and add to the top of the stack
  pushd "${the_new_dir}" > /dev/null
  [[ $? -ne 0 ]] && return 1
  the_new_dir=$(pwd)

  #
  # Trim down everything beyond 11th entry
  popd -n +11 2>/dev/null 1>/dev/null

  #
  # Remove any other occurence of this dir, skipping the top of the stack
  for ((cnt=1; cnt <= 10; cnt++)); do
    x2=$(dirs +${cnt} 2>/dev/null)
    [[ $? -ne 0 ]] && return 0
    [[ ${x2:0:1} == '~' ]] && x2="${HOME}${x2:1}"
    if [[ "${x2}" == "${the_new_dir}" ]]; then
      popd -n +$cnt 2>/dev/null 1>/dev/null
      cnt=cnt-1
    fi
  done

  return 0
}

alias cd=cd_func

if [[ $BASH_VERSION > "2.05a" ]]; then
  # ctrl+w shows the menu
  bind -x "\"\C-w\":cd_func -- ;"
fi

###############################################################################


