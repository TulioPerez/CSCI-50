#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x = get_int("Enter x ");
    int y = get_int("Enter y ");

    if (x < y)
    {
        printf("%i is less than %i.\n", x, y);
    }
    else if (x > y)
    {
        printf("%i is greater than %i.\n", x, y);
    }
    else
    {
        printf("%i is equal to %i.\n", x, y);
    }
}