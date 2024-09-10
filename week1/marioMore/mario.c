#include <cs50.h>
#include <stdio.h>

// method signature declaration
void buildSteps(int n);

int main(void)
{
    // continue prompting user for height as long as an int that is greater than 0 is not entered
    int height = 0;
    do
    {
        height = get_int("Height: \n");
    }
    while (height < 1);

    buildSteps(height);
}

void buildSteps(int n)
{
    // 'spaces' is a counter that is used to create the gaps at the beginning of every row
    int spaces = n;

    for (int i = 0; i < n; i++)
    {
        // inner loop for creating spaces before the steps
        // '-1' is required to prevent an extra space from being added to all rows
        int k = (n - i) - 1;
        while (k > 0)
        {
            printf(" ");
            k--;
        }

        // loop for row creation
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }

        // create gaps between staircases
        printf("  ");

        // loop and create the other staircase
        for (int m = 0; m < i + 1; m++)
        {
            printf("#");
        }

        // after a row is created, skip to the next line and continue outside loop
        printf("\n");
    }
}