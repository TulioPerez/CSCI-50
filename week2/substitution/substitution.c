#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// method signature declarations:
int checkKey(string s);
void cipherPlaintext(string s);

// global variables
string cipherKey = "";
string plaintext = "";

int main(int argc, char *argv[1])
{
    // check that 2 arguments exist (function name and key)
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // arg number is correct - set cipherkey to argv[1]
    cipherKey = argv[1];

    // check cipherkey & print if error:. 1: not 26 chars long, 2: must only use alphabet, 3: must use char only once
    int keyResponse = checkKey(cipherKey);

    // ERROR 1: key != 26 chars
    if (keyResponse == 1)
    {
        printf("Key must be 26 chars long.\n");
        return 1;
    }
    // ERROR 2: non-alpha char detected
    else if (keyResponse == 2)
    {
        printf("Key must only include alphabet characters.\n");
        return 1;
    }
    // ERROR 3: repeated char detected
    else if (keyResponse == 3)
    {
        printf("Characters in key can only be used once.\n");
        return 1;
    }

    // all checks passed (return was 0) - prompt user for inputtext to cipher
    else
    {
        plaintext = get_string("plaintext: ");
        cipherPlaintext(plaintext);
    }
}

// function that checks inputKey and returns an int response code
// code: 0: key checks out, 1: not 26 char long, 2: must only use alphabet, 3: must use char only once,
int checkKey(string s)
{
    // create array to be populated with only qualified chars from string
    char keyArray[strlen(s)];

    // ERROR 1: key != 26 chars
    if (strlen(s) != 26)
    {
        return 1;
    }

    // outer loop for checks 2 & 3
    for (int i = 0; i < strlen(s); i++)
    {
        // set temp char value to currently isolated char
        char temp = s[i];

        // ERROR 2: non-alpha char detected
        if (!isalpha(temp))
        {
            return 2;
        }

        // inner loop to check that temp != any current char in keyArray; skip blanks in keyArray (value not yet set)
        for (int j = 0; j < sizeof(keyArray) && keyArray[j] != '\0'; j++)
        {
            // ERROR 3: repeated char detected
            if (temp == keyArray[j])
            {
                return 3;
            }
        }
        // checks passed so far - add temp char from string to keyArray
        keyArray[i] = temp;
    }

    // all checks passed!
    return 0;
}

// function to cipher plaintext input from user
void cipherPlaintext(string s)
{
    // create array to be used for return value creation
    char ciphertext[strlen(s)];

    for (int i = 0; i <= strlen(s); i++)
    {
        // isolate current char in plaintext
        char tempChar = s[i];

        // map plaintext char to uppercase char
        if (isupper(tempChar))
        {
            ciphertext[i] = toupper(cipherKey[tempChar - 'A']);
        }

        // map plaintext char to lowercase char
        else if (islower(tempChar))
        {
            ciphertext[i] = tolower(cipherKey[tempChar - 'a']);
        }

        // it's not an alphabetical char - just copy it over
        else
        {
            ciphertext[i] = tempChar;
        }
    }

    // convert keyarray to string & print
    char *result = ciphertext;

    printf("ciphertext: %s\n", result);
}