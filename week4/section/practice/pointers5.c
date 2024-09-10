#include <stdio.h>
#include <string.h>

// this is the same as pointers4 but without the <cs50.h> helper library
// removed #include <cs50.h>
// changed string s to char *s
// references to s* stay the same, as in "%s\n", if used
// the double quotes encasing "Hola" act as a &

int main(void)
{
    // create a pointer called s that points to an array in memory
    char *s = "Hola";

    // print the pointer memory address
    printf("String address = %p\n", s);

    for (int i = 0; i < strlen(s) + 1; i++)
    {
        // print the i'th  char in the array
        printf("%c\n", s[i]);

        // print the address of each char array value (including the terminating char: \0)
        printf("%p\n", &s[i]);
    }
}

// the address of s and the address of the first char are excatly the same:
// a string is == the mem location of the 1st value of char array