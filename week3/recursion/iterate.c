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
    for (int i = 0; i < n; i++) // iterate over every row
    {
        for (int j = 0; j < i + 1; j++) // "j < i + 1" means use the index to determine how many hashes to print
        {
            printf("M");
        }
        printf("\n"); // move down one line
    }
}