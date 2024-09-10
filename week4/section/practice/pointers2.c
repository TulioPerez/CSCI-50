#include <stdio.h>

// &: the 'address of x' operator
// *: the dereference operator (take an address and go to it - the map)

void double_value(int *n);

int main(void)
{
    int a = 50;

    // creeate pointer of type int that holds the de-referenced value found at mem address 'a'
    int *p = &a;

    // pass the variable representing the de-referenced address location
    double_value(p);

    // print new value of a
    printf("%i\n", a);
}


void double_value(int *n)
{
    *n = (*n) + (*n);
}