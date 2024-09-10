#include <stdio.h>

// &: the 'address of x' operator
// *: the dereference operator (take an address and go to it - the map)

int main(void)
{
    int x = 4;

    int *p1 = &x;
    printf("%i %i\n", x, *p1);

    int *p2 = p1;
    printf("%i %i %i\n", x, *p1, *p2);

    *p2 = 3;
    printf("%i %i %i\n", x, *p1, *p2);
}
