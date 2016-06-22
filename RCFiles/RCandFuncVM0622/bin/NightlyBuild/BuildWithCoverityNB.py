#!/usr/bin/env python


import os, time, sys

# List to be used to hold failing projects
failures = []
# String used for debugging
failString = ""
# Starting time for timer
start = time.time()
# Files used for projects, deps, and output
#projFile = '/home/nathan.caron/Documents/Learning/Project/MakeListProj'
#depsFile = '/home/nathan.caron/Documents/Learning/Project/MakeListDeps'
projFile = '/home/nathan.caron/bin/NightlyBuild/MakeListProj'
depsFile = '/home/nathan.caron/bin/NightlyBuild/MakeListDeps'
outputFile = '/home/nathan.caron/bin/NightlyBuild/FailOutputCoverity'
# Directories to be removed from output to clean things up a bit
rootDir = '/WC/proj/'
projPath = 'proj=nathan.caron1/'
depsPath = 'deps=nathan.caron1/'
verbose = False

for arg in sys.argv:
    if arg == '-v' or arg == '--v':
        verbose = True

# Environment variable needed for compilation
os.environ["DEPS_DIR"] = "/proj/WCS/deps"

# Read projects from file
with open(projFile, 'r') as f:
    projDirs = f.read().splitlines()
# Read dependant projects from file
with open(depsFile, 'r') as f:
    depsDirs = f.read().splitlines()

# Cycle through each project, clean it, build it with coverity, analyze it, and then commit the defects
for d in projDirs:
    # Stream name for committing defects
    streamName = "TI14A15_" + d.split("/")[-2]
    # Commands to be run with os.system
    cleanCommand = "make -C " + d + " clean 2>/dev/stdout > /dev/null"
    clearIntermediate = "rm -rf /WC/coverity-idirs/TempBuild 2>/dev/stdout > /dev/null"
    moveOutput = "rm -rf /WC/coverity-idirs/TempBuild/output 2>/dev/stdout > /dev/null; mv /WC/coverity-idirs/TempBuild/outputc /WC/coverity-idirs/TempBuild/output 2>/dev/stdout > /dev/null"
    runCommand = "/mnt/gluster_WorkArea/software/coverity/analysis-7.5.0/bin/cov-build --config /mnt/gluster_WorkArea/software/coverity/analysis-7.5.0/config/coverity_config.xml --dir /WC/coverity-idirs/TempBuild --delete-stale-tus  make DEPS_DIR=/proj/WCS/deps -C " + d + " dist 2>/dev/stdout > /dev/null"
    analyzeCommand = "/mnt/gluster_WorkArea/software/coverity/analysis-7.5.0/bin/cov-analyze --allow-unmerged-emits --dir /WC/coverity-idirs/TempBuild --output-tag c -j auto --all --concurrency --security --rule --strip-path " + d + " 2>/dev/stdout > /dev/null"
    commitCommand = "/mnt/gluster_WorkArea/software/coverity/analysis-7.5.0/bin/cov-commit-defects --dir /WC/coverity-idirs/TempBuild --host coverity.wcs.gd-ais.com --port 8080 --user nathan.caron --password `Decrypt '@H!^HzkjKP0&*2M<><4$<>T$!$G%#G<<$4>>!$T<2<50E54923xdx7xnevaE\"#$%!%#!$\"'` --stream " + streamName + " 2>/dev/stdout > /dev/null"


    # Print name of project being worked on if in Verbose mode:
    if verbose:
        print "Now building: ", streamName, "..."

    # Clear the intermediate directory so that there will be no overlap
    if os.system(clearIntermediate):
        print "Failed to clear Intermediate Directory during ", d
        failString += "Failed to clear Intermediate Directory during " + d + '\n'
    # Make clean must be run for coverity to work.
    if os.system(cleanCommand):
        print "Failed to run make clean on ", d
        failString += "Failed to run make clean on " + d + '\n'
    # Build project using coverity
    if os.system(runCommand):
        failures.append(d)
        failString += "Failed to build " + d + '\n'
    # Analyze the build
    if os.system(analyzeCommand):
        print "Failed to analyze ", d
        failString += "Failed to analyze " + d + '\n'
    else:
        # If it gets here, analyze was success, so fix output folder (analyze creates outputc, commit uses output)
        if os.system(moveOutput):
            print "Failed to fix output folder during ", d
            failString += "Failed to fix output folder during ", d + '\n'
        # Commit defects
        if os.system(commitCommand):
            print "Failed to commit defects for ", d
            failString += "Failed to commit defects for " + d + '\n'

# Compile dependants without coverity, since their defects will be added to any project using them
for d in depsDirs:
    os.chdir(os.path.join(d))
    if os.system("make -j4 2>/dev/stdout > /dev/null"):
        failures.append(d)
        failString += "Failed to build " + d + "\n"


# Print out the failures to screen and to file
print "Failures:"
with open(outputFile, 'w') as f:
    for i in failures:
        i = i.replace(rootDir, '').replace(depsPath, '').replace(projPath, '')
        print i
        f.write("%s\n" % i)

print "FailString:\n", failString
seconds = (int)(time.time()-start)
# Print total time taken to Build/Analyze/Commit everything
print "Total time elapsed: ", seconds/60, " minutes and ", seconds%60, " seconds"
