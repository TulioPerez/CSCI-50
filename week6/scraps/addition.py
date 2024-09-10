#python addition.py 2 8

import sys

if len(sys.argv) != 3:
    sys.exit("Usage: python addition.py x y")

x = int(sys.argv[1])
y = int(sys.argv[2])

print(f"{x} + {y} = {x + y}")
