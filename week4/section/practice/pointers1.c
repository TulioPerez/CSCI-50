#include <stdio.h>

// &: the 'address of x' operator
// *: the dereference operator (take an address and go to it - the map)

void double_value(int n);

int main(void)
{
    int a = 50;
    double_value(a);
    printf("%i\n", a);
}

void double_value(int n)
{
    n = n + n;
}