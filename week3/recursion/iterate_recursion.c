#include <cs50.h>
#include <stdio.h>
#include <string.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw(height);
}

void draw(int n)
{
    // Exit if nothing left to draw (when n is no longer positive)
    if (n <= 0)
    {
        return;
    }

    // Print pyramid of height n - 1
    draw(n - 1);

    // Print on more row
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}