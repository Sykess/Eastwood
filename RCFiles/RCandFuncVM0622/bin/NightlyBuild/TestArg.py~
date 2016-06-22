#!/usr/bin/env python

import sys

verbose = False;

if len(sys.argv) > 1:
    print "*******************\n", sys.argv[1], "\n*******************"

for arg in sys.argv:
    if arg == '-v' or arg == '--v':
        verbose = True;

if verbose:
    print "This is verbose!"

blah = "hey"

if blah == ("hi" or "hello" or "hey"):
    print "Blah is: ", blah
else:
    print "Blah is not: ", blah
