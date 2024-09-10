#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // get ints
    int x;
    printf("x: ");

    // give scanf a map to x - go to that address and change value
    scanf("%i", &x);
    printf("x: %i\n", x);


    // get strings
    char *s = malloc(4);
    printf("s: ");

    // give scanf a map to x - go to that address and change value
    scanf("%s", s);
    printf("s: %s\n", s);
    free(s);
}