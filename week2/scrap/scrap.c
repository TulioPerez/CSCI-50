#include <cs50.h>
#include <stdio.h>

void printLoop();

int main(void)
{
    printLoop();
}

void printLoop()
{
    string s = "hello";

    for (int i = 0; i < strlen(s); i++)
    {
        printf("%c\n, s[i]);
    }
}

// int main(int argc, char *argv[])
// {
//     printf("Number of arguments: %d\n", argc);
//     return 0;
// }