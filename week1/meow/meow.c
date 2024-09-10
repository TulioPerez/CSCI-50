#include <cs50.h>
#include <stdio.h>

void catcall (int n);

int main(void)
{
    int meows = get_int("How many times should I meow?\n");

    catcall(meows);
}

void catcall (int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("meow!\n");
    }
}