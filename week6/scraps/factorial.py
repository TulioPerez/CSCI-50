def factorial(n):
    result = 1

    for i in range (1, n + 1):
        result *= i
    return result

# only int is accepted, otherwise error:
try:
    number = int(input("Enter a number: "))
    print(factorial(number))
except:
    print("Enter an int")

    # www.w3schools.com for docs
