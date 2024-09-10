#python copy.py infil outfile

import sys

if len(sys.argv) != 3:
    sys.exit("Usage: python copy.py infile outfile")

infile = open(sys.argv[1])
outfile = open(sys.argv[2], "w")

contents = infile.read()
outfile.write(contents.upper())

# did not use with open, so must close file:
infile.close()
outfile.close()
