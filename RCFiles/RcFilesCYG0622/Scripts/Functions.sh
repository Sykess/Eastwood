#!/bin/bash


getWorkbookVersion()
{
    version_num="7"
    while [[ `ls /cygdrive/y/WCS/Harpoon\ Phase\ RAN/ | grep V$((version_num+1)).xlsx` ]]
    do
        ((version_num++))
    done


}

CopyWorksheet()
{
    #local v="${1}"
    #if [ -z ${1} ]; then
    #    v="7"
    #fi
    [ ! -z $1 ] && (($1>1)) && version_num=$1 || getWorkbookVersion

    #getWorkbookVersion

    local to="/cygdrive/c/Users/nathan.caron/Documents/PTRWorkSheet/"
    local loc="/cygdrive/y/WCS/Harpoon Phase RAN/"
    local prev="Previous Spreadsheets/"
    local version="Version_${version_num}/"
    local file="Harpoon Phase RAN PTR List WIP V${version_num}.xlsx"
    local new_file="Harpoon_Phase_RAN_PTR_List_WIP_V${version_num}_$(date +%b%d).xlsx"
    local time_file="Harpoon_Phase_RAN_PTR_List_WIP_V${version_num}_$(date +%b%d_%H%M).xlsx"

    if [ ! -e "${loc}${file}" ]; then
        if [ ! -e "${loc}${prev}${file}" ]; then
            echo "${loc}${prev}${file} doesn't exist! exiting"
            return 1
        fi
        loc="${loc}${prev}"
        mkdir -p "${to}${version}"
    fi


    if [ -e $to$version$new_file ]; then
        cp "${loc}${file}" "${to}${version}${time_file}"
    else
        cp "${loc}${file}" "${to}${version}${new_file}"
    fi
}
export -f CopyWorksheet
