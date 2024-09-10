#include <cs50.h>
#include<stdio.h>

int add(int x, int y);

int main(void)
{
    int first = get_int("What is the first number you would like to add?\n");
    int second = get_int("What is the second number you would like to add?\n");

    printf("The result is %i\n", add(first, second));
}

int add(int x, int y)
{
    return x + y;
}