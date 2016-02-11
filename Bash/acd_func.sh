#!/bin/bash
# Create a listing of previous directories with cd --
# You can access them by number with cd -#


cd_func()
{
    # Create local vars to be used
    local x2 newDir adir index donkey
    # -i options means treat as integer
    local -i cnt

    if [[ $1 == "--" ]]; then
        dirs -v
        return 0
    fi

    newDir=$1
    # If call to cd with no params, set to home
    [[ -z $1 ]] && newDir=$HOME

    if [[ ${newDir:0:1} == '-' ]]; then
        # Extract dir # from dirs
        index=${newDir:1}
        # If no # after - use 1
        [[ -z $index ]] && index=1
        adir=$(dirs +$index)
        # If no dirs -# return 1(error)
        [[ -z $adir ]] && return 1
        newDir=$adir
    fi

    # '~' needs to be substituted by ${HOME}
    [[ ${newDir:0:1} == '~' ]] && newDir="${HOME}${newDir:1}"

    # Change to the new dir and add it to top of stack
    pushd "${newDir}" > /dev/null
    newDir=$(pwd)

    # Trim down entries after 11
    popd -n +11 2>/dev/null 1>/dev/null

    # Remove any other occurrance of this dir (except top of stack)
    for ((cnt=1; cnt <= 10; cnt++)); do
        x2=$(dirs +${cnt} 2>/dev/null)
        [[ $? -ne 0 ]] && return 0
        [[ ${x2:0:1} == '~' ]] && x2="${HOME}${x2:1}"
        if [[ "${x2}" == "${newDir}" ]]; then
            popd -n +$cnt 2>/dev/null 1>/dev/null
            cnt=cnt-1
        fi
    done

    return 0
}

alias cd=cd_func




