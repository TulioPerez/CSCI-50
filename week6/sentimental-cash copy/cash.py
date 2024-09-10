import cs50

# Prompt user for a float (dollar value) as long as a positive amount is not entered
while True:
    change = cs50.get_float("Change: ")
    if change > 0:
        # Valid aount entered - break the loop
        break

# Delcare and initialize coins counter
coins = 0

# Loop while change is greater than a quarter (same applies to remaining loops and their coin values)
while change >= 0.25:
    # Subtract 0.25 from change
    change = change - 0.25
    # Increment coins counter
    coins = coins + 1

while change >= 0.10:
    change = change - 0.10
    coins = coins + 1

while change >= 0.05:
    change = change - 0.05
    coins = coins + 1

while change >= 0.01:
    # Cast to int to handle floating point imprecision
    change = int(change) - 0.01
    coins = coins + 1

# Print result
print(coins)
