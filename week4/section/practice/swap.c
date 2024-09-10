#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;

    printf("x is %i, y is %i\n", x, y);
    // swap function expects pointers - pass in the ADDRESS of x and that of y
    swap(&x, &y);

    printf("x is %i, y is %i\n", x, y);
}

// swap function expects pointers
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}