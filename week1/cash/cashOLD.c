#include <cs50.h>
#include <stdio.h>

void calculateCoins(int amount);

int main(void)
{
    // initialize the 'change' variable
    int change = 0;

    // prevent invalid user prompts
    do
    {
        change = get_int("Changed owed: ");
    }
    while (change < 0);

    calculateCoins(change);
    // printf("%f", change);
}

void calculateCoins(int amount)
{
    // printf("Amount = %i\n", amount);
    // convert amount entered into float to get cents
    float cents = (amount / 100.00);
    // printf("Cents = %.2f\n", cents);

    // counter for total coins
    int coins = 0;

    // run a loop to that runs as long as the cents are greater than 0.
    while (cents >= 0.009)
    {
        // run loops that check for coin values, then subtracts these values from the total amount.
        while ((cents / .25) >= 1)
        {
            cents -= .25;
            coins++;
            // printf("quarter added. ");
            // printf("Cents = %.2f\n", cents);
        }

        while ((cents / .10) >= 1)
        {
            cents -= .10;
            coins++;
            // printf("dime added. ");
            // printf("Cents = %.2f\n", cents);
        }

        while ((cents / .05) >= 1)
        {
            cents -= .05;
            coins++;
            // printf("nickel added. ");
            // printf("Cents = %.2f\n", cents);
        }

        while ((cents / .009) >= 1)
        {
            cents -= .01;
            coins++;
            // printf("penny added. ");
            // printf("Cents = %.2f\n", cents);
        }
    }
    // printf("\ncoins = %i\n", coins);
    printf("%i\n", coins);
}