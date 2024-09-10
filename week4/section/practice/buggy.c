#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // malloc returns chunk of contiguous memory
    // treat what comes back from malloc as array
    // create array of ints
    
    int *x = malloc(3 * sizeof (int));
    // was 1, 2, 3 instead of 0, 1, 2
    x[0] = 72;
    x[1] = 73;
    x[2] = 33;

    // was not present
    free(x);
}