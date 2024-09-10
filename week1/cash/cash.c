#include <cs50.h>
#include <stdio.h>

void calculateCoins(int amount);

int main(void)
{
    // declare & initialize the 'change' variable
    int change = 0;

    // prevent invalid user prompts
    do
    {
        change = get_int("Changed owed: ");
    }
    while (change < 0);

    calculateCoins(change);
}

void calculateCoins(int amount)
{
    // convert amount entered into float to get cents
    float cents = (amount / 100.00);

    // counter for total coins
    int coins = 0;

    // loop that runs as long as the cents are greater than 0.
    while (cents >= 0.009)
    {
        // loop that checks for coin values, then subtracts these values from the total 'cents' value.
        // check for quarters
        while ((cents / .25) >= 1)
        {
            cents -= .25;
            coins++;
        }

        // check for dimes
        while ((cents / .10) >= 1)
        {
            cents -= .10;
            coins++;
        }

        // check for nickels
        while ((cents / .05) >= 1)
        {
            cents -= .05;
            coins++;
        }

        // check for pennies
        while ((cents / .009) >= 1)
        {
            cents -= .01;
            coins++;
        }
    }

    // print total number of coins to return
    printf("%i\n", coins);
}