#!/bin/bash

# Check if there is newer version:
version_num="7" && until [[ `ls /cygdrive/y/WCS/Harpoon\ Phase\ RAN/ | grep V$((version_num)).xlsx` ]]; do ((version_num++)); ((version_num>20)) && exit 1; done



# Set variables
filename='Harpoon Phase RAN PTR List WIP V'${version_num}'.xlsx'
current_worksheet='/cygdrive/y/WCS/Harpoon Phase RAN/'${filename}
local_copy='/cygdrive/c/Users/nathan.caron/Documents/PTRWorkSheet/Compare/'${filename}
local_unshared='/cygdrive/c/Users/nathan.caron/Documents/PTRWorkSheet/Compare/Harpoon_Unshared.xlsx'
alliance_file='//alliance2.gd-ais.com/DavWWWRoot/sites/3/WCS/WCS Shared Documents IPT WCS Software/TI14 APB15/Workarea/RAN PTR Effort/'${filename}

# If the worksheet doesn't exist, game over
[ -e "${current_worksheet}" ] || exit 1

# Get checksums (with local check if file exists first)
current_md5=`md5sum.exe "${current_worksheet}" | awk '{ print $1 }'`
[ -e "${local_copy}" ] && local_md5=`md5sum.exe "${local_copy}" | awk '{ print $1 }'`


# Make sure checksums are differen't before copying over
if [ "$current_md5" != "$local_md5" ]; then
    rm -f "$local_copy" "$alliance_file"
    cp "${current_worksheet}" "${local_copy}"
    # Run from windows command line so that wait works
    cmd /c start /wait "C:\Users\nathan.caron\Documents\UnshareExcel.vbs"
    [ -e "${local_unshared}" ] && cp "${local_unshared}" "${alliance_file}"
    rm -f "${local_unshared}"
fi


    # Obsolete code earlier used:
    #cygstart.exe /home/nathan.caron/UnshareExcel.vbs
    # for some reason bash doesn't wait for cygstart.exe, so sleep 10
    #sleep 10
    #echo "\"${local_copy}\"" "\"${alliance_file}\"" | xargs -n 1 cp "${current_worksheet}"
