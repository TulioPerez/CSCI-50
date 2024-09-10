import cs50

# create w while loop that repeats as long as the name entered by user is blank
while True:
    # prompt user for a string (their name)
    name = cs50.get_string("What is your name? ")
    if name != "":
        # name is not blank - break out of loop
        break

# print the customized greeting with the user's name
print(f"hello, {name}")
