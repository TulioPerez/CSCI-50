#include <cs50.h>
#include <stdio.h>

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

    // outer loop runs while i is less than the user's input value (step height)
    for (int i = 0; i < n; i++)
    {
        // loop for creating spaces before steps
        // '-1' is required tpo prevent an extra space from being added to all rows
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

        // after a row is created, skip to the next line and continue outside loop
        printf("\n");
    }
}