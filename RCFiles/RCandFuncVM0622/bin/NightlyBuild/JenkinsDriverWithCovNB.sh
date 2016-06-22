#!/bin/bash
# Drive Jenkins to update and build projects, copy results to
# WorkArea folder, and then copy to Sync folder in DOS format.

# Set variables for directories to work with
workArea=/WorkArea/NathanCaron/
syncArea=/home/nathan.caron/Documents/Learning/Sync/Compilations/

# Update projects from Synergy via script
bash UpdateProjectsNB.sh
# Create list of directories to run make on
bash UpdateMakeListsNB.sh
{
    # Compile all pojects and save output via Python
    python BuildWithCoverityNB.py
} 2>&1 | tee CompileOutputCoverity # Adds display to both console and file

# Save compile output and failures to WorkGroup
cp CompileOutputCoverity ${workArea}CompileErrors$( date +%m%d)
cp FailOutputCoverity ${workArea}FailedProjects$( date +%m%d)

if [ $? ]
then
    echo "Saving successful!"
fi

# Move logs from 3 days ago to Older logs file
moveDate=$( date -d "3 days ago 13:00" '+%m%d')
moveTo="Logs$( date -d "3 days ago 13:00" '+%B')"

# Create LogsMonth directory if doesn't yet exist
if [ ! -d ${workArea}${moveTo} ]
then
    mkdir ${workArea}${moveTo}
fi

# Move 3 day old Compile log to appropriate month folder
if [ -f ${workArea}CompileErrors${moveDate} ]
then
    mv ${workArea}CompileErrors${moveDate} ${workArea}${moveTo}
fi

# Move 3 day old Fail log to appropriate month folder
if [ -f ${workArea}FailedProjects${moveDate} ]
then
    mv ${workArea}FailedProjects${moveDate} ${workArea}${moveTo}
fi

# Use awk to copy files to Sync folder in DOS format
awk 'sub("$", "\r")' ${workArea}CompileErrors$(date +%m%d) \
    > ${syncArea}CompileErrors$(date +%m%d).txt
awk 'sub("$", "\r")' ${workArea}FailedProjects$(date +%m%d) \
    > ${syncArea}FailedProjects$(date +%m%d).txt





