#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// method signature declarations:
int checkKey (string s);
string cipherTheText(string s);

// global variables
string key = "";
string plaintext = "";

int main(int argc, char *argv[1])
{
    // check that 2 arguments exist (function name and key)
    if (argc != 2){
        printf("Usage: ./substitution key\n");
        return -1;
    }

    // arg number is correct - set key to argv[1]
    key = argv[1];

    // check key values and print if error:. 1: not 26 chars long, 2: must only use alphabet, 3: must use char only once
    int keyResponse = checkKey(key);
    if (keyResponse == 1)
    {
        printf("Key must be 26 chars long.\n");
        return -1;
    }
    else if (keyResponse == 2)
    {
        printf("Key must only include alphabet characters.\n");
        return -1;
    }
    else if (keyResponse == 3)
    {
        printf("Characters in key can only be used once.\n");
        return -1;
    }

    // all checks passed (return was 0) - prompt user for text to cipher
    else
    {
        plaintext = get_string("plaintext:  ");
        cipherTheText(plaintext);
    }
}


// check string return case: 0: key checks out, 1: not 26 char long, 2: must only use alphabet, 3: must use char only once,
int checkKey (string s)
{
    // create array to be populated with qualified chars from string
    char keyArray[strlen(s)];
    // printf("CHECKING STRING: %s...\n", s);

    // ERROR 1: key != 26 chars
    if (strlen(s) != 26)
    {
        return 1;
    }

    // outer loop
    for (int i = 0; i < strlen(s); i++)
    {
        // set temp char value to currently isolated char
        char temp = s[i];

        // printf("Checking char: %c...  \n", temp);

        // ERROR 2: non-alpha char detected
        if (!isalpha(temp))
        {
            return 2;
        }

        // inner loop to check that temp != any current char in keyArray; skip blanks in keyArray (value not yet set)
        for (int j = 0; j < sizeof(keyArray) && keyArray[j] != '\0'; j++)
        {
            // printf("Comparing %c to Array value: %c\n", temp, keyArray[j]);

            // ERROR 3: repeated char detected
            if (temp == keyArray[j])
            {
                // printf("Repeated char detected: %c\n", temp);
                // printf("ARRAY: %s\n", keyArray);
                return 3;
            }

        }
        // printf("Char %c passed\n", temp);

        // all checks passed so far - add temp char from string to keyArray
        keyArray[i] = temp;
    }

    // all checks passed!
    printf("checks passed! KEY:%s\n", (key));
    return 0;
}

//function to cipher plaintext input from user
string cipherTheText(string s)
{
    // create array to be used for return value creation
    char ciphertext[strlen(s)];

    for (int i = 0; i < strlen(s); i++)
    {
        // isolate current char in plaintext
        char tempChar = s[i];

        // map plaintext char to uppercase char
        if (isupper(tempChar))
        {
            ciphertext[i] = toupper(key[tempChar - 'A']);
            printf("UPPER %c is == %c\n", tempChar, key[tempChar - 'A']);
        }

        // map plaintext char to lowercase char
        else
        {
            ciphertext[i] = tolower(key[tempChar - 'a']);
            printf("LOWER %c is == %c\n", tempChar, key[tempChar - 'a']);
        }
    }

    string result = ciphertext;
    printf("ciphertext:  %s\n", result);
    return result;
}