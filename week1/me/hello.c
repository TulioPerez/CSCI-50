#include <cs50.h>
#include <stdio.h>

// This program takes the name of the user and returns a greeting
int main(void)
{
    // 'answer' is the user's input and could be substituted for a string return value from a method
    string answer = get_string("What's your name?");
    printf("Hello, %s\n", answer);
}