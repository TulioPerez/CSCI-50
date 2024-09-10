import cs50

# Prompt user for a float (dollar value) as long as a positive amount is not entered
while True:
    change = cs50.get_float("Change: ")
    if change > 0:
        # Valid float entered - break the loop
        break

# Declare coin values in list
coin_values = [0.25, 0.10, 0.05, 0.01]

# Declare and initialize coins counter
coins = 0

# Loop through each coin_values element
for coin in coin_values:
    # Check that change is greater than or equal to 'coin_values' element
    while change >= coin:
        # Subtract coin value and round to handle floating point imprecision
        change = round(change - coin, 2)

        # Increment coins counter
        coins += 1

# Print result
print(coins)
