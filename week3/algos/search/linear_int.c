#include <cs50.h>
#include <stdio.h>
#include <string.h>

// O(n) search option
int main (void)
{
    // array of bills in random order
    int numbers[] = {20, 500, 10, 5, 100, 1, 50};

    int n = get_int("Number: ");
    for (int i = 0; i < 7; i++)
    {
        if (numbers[i] == n)
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}