import cs50

# Prompt user for int as long as an int is not entered and it is not beweeen 1 and 8
while True:
    height = cs50.get_int("Height: ")
    if height > 0 and height < 9:
        # Valid int entered - break the loop
        break

# Loop to print the steps
for step in range(height):
    # print a (space that is equal to the iterator(-1 to prevent extra space on first line)) and print a step equal to iterator (+1 to not consider the 0 index)
    print((" " * (height - step - 1)) + ("#" * (step + 1)))
