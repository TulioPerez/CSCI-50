#include <cs50.h>
#include <stdio.h>
#include <string.h>

// O(n) search option
int main (void)
{
    // array of bills in random order
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "tophat"};

    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(strings[i], s) == 0) // returning 0 means there is NO difference in the strings ( they are equal / same )
        {
            printf("Found\n");
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}