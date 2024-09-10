#include <cs50.h>
#include <stdio.h>

int factorial(int n);

int main(void)
{
    int n = get_int("Number: \n");
    printf("%i factorial is %i\n", n, factorial(n));
}

int factorial(int n)
{
    // break loop once 0 is reached
    if (n == 0)
    {
        return 1;
    }

    // for instance 3! (3 * 2 * 1) is 3 times 2! (2 * 1)
    return n * factorial(n - 1);
}