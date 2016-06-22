#!/bin/bash

source /home/nathan.caron/Functions.sh && getWorkbookVersion

# Set variables
filename='Harpoon Phase RAN PTR List WIP V'${version_num}'.xlsx'
current_worksheet='/cygdrive/y/WCS/Harpoon Phase RAN/'${filename}
local_copy='/cygdrive/c/Users/nathan.caron/Documents/PTRWorkSheet/Compare/'${filename}
local_unshared='/cygdrive/c/Users/nathan.caron/Documents/PTRWorkSheet/Compare/Harpoon_Unshared.xlsx'
alliance_file='//alliance2.gd-ais.com/DavWWWRoot/sites/3/WCS/WCS Shared Documents IPT WCS Software/TI14 APB15/Workarea/RAN PTR Effort/'${filename}

# Get checksums
current_md5=`md5sum.exe "${current_worksheet}" | awk '{ print $1 }'`
local_md5="1234" # Need valid value in case file doesn't exist
if [ -a "${local_copy}" ]; then
    local_md5=`md5sum.exe "${local_copy}" | awk '{ print $1 }'`
fi


# Make sure checksums are differen't before copying over
if [ $current_md5 != $local_md5 ]; then
    rm -f "$local_copy" "$alliance_file"
    cp "${current_worksheet}" "${local_copy}"
    cygstart.exe /home/nathan.caron/UnshareExcel.vbs
    sleep 10
    cp "${local_unshared}" "${alliance_file}"
    rm -f "${local_unshared}"

    #echo "\"${local_copy}\"" "\"${alliance_file}\"" | xargs -n 1 cp "${current_worksheet}"
fi
