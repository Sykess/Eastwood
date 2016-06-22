#!/bin/bash


bookmark_file="/cygdrive/c/Users/nathan.caron/AppData/Local/Google/Chrome/User Data/Default/Bookmarks"
save_to="/cygdrive/c/Users/nathan.caron/Documents/Backups/"

cp "${bookmark_file}" "${save_to}Bookmarks$(date +%m%d)"


