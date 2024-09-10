def factorial(n):
    result == 0

    for i in range (1, n + 1):
        result *= i
    return n * factorial(n - 1)

# only int is accepted, otherwise error:
try:
    number = int(input("Enter a number: "))
    print(factorial(number))
except:
    print("Enter an int")

    # www.w3schools.com for docs
