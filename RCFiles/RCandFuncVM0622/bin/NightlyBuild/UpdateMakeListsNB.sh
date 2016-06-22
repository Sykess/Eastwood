#!/bin/bash

# export DEPS_DIR=/proj/WCS/deps
# Create list of directories with ready makefiles
echo "Updating List of directories to make..."
echo -n "" > MakeListProj # Clear file
echo -n "" > MakeListDeps
# Add projects to MakeListProj
for f in $(find /WC/proj/WCS -name module.mk | grep -v "deps"); do 
    grep -P "module_ready_for_cm[^=]=.*yes" $f>&/dev/null && \
        echo ${f/module.mk/""} >> MakeListProj
done
# Add deps to MakeListDeps
for f in $(find /WC/proj/WCS/deps -name module.mk); do
    grep -P "module_ready_for_cm[^=]=.*yes" $f>&/dev/null && \
        echo ${f/module.mk/""} >> MakeListDeps
done
echo "Update complete. Data saved to MakeList"
