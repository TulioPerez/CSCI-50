#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // create a pointer called s that points to an array in memory
    string s = "Hola";

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