#!/bin/bash

#cygstart.exe /home/nathan.caron/UnshareExcel.vbs --wait
#date
#/c/Users/nathan.caron/Documents/UnshareExcel.vbs
date
$(cygpath -u "${COMSPEC}") /c start /wait "C:\Users\nathan.caron\Documents\UnshareExcel.vbs"
date
echo "done"

