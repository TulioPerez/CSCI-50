import sys

if len(sys.argv) != 2:
    sys.exit("Usage: python fizzbuzz.py [integer value]")

fizz_val = 3
buzz_val = 5

num = int(sys.argv[1])


def main():
    fizzbuzz(num)


def fizzbuzz(num):
    for n in range(1, num + 1):

        if n % fizz_val == 0 and n % buzz_val == 0:
            print(n, ": fizzbuzz", sep = "")

        elif n % fizz_val == 0:
            print(n, ": fizz", sep = "")

        elif n % buzz_val == 0:
            print(n, ": buzz", sep = "")

        else:
            print(n, ": none", sep = "")

main()
