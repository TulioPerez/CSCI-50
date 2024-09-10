#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// method signature declarations
bool checkKey(string s);
string cipherText(string s);

// global variables
int caesarKey;
string plaintext;

int main(int argc, char *argv[1])
{
    // check if arg was entered and if the chars in the arg are digits
    if (argc == 2 && checkKey(argv[1]))
    {
        // valid arg entered - convert to int
        caesarKey = atoi(argv[1]);

        plaintext = get_string("plaintext:  ");
        cipherText(plaintext);
    }
    else
    {
        // no arg entered - print usage instructions
        printf("%s\n", "Usage: ./ caesar key");
        return 1;
    }
}

// function that returns true if all chars in caesarKey are digits
bool checkKey(string s)
{
    for (int i = 0; i < strlen(s); i++)
    {
        if (!(isdigit(s[i])))
        {
            return false;
        }
    }
    return true;
}

// function that ciphers the given text
string cipherText(string s)
{
    // create array that will hold ciphered chars from string
    char charArray[strlen(s)];
    for (int i = 0; i < strlen(s); i++)
    {
        char current = s[i];

        // if current char is a letter, cipher it
        if (isalpha(current))
        {
            // get overflow factor by mapping letters to distance from 'a' and adding the cipherKey
            int factor = (current - 'a' + caesarKey);

            // if factor is > 26, get remainder of factor / 26
            if (factor >= 26)
            {
                factor %= 26;
            }

            // add factor to current character to get the new (ciphered) character
            charArray[i] = (factor + 'a');
        }

        // char is not a letter - just add the current character as is
        else
        {
            charArray[i] = current;
        }
    }

    // convert char array to string
    string result = charArray;

    printf("ciphertext: %s\n", result);

    return result;
}