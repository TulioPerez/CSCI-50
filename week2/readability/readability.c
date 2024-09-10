#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// method signature declatrations
void getCounts(string s);
void getColemanIndex(string s);

// global variables
string text;
float letterCount = 0;
float wordCount = 0;
float sentenceCount = 0;

int main(void)
{
    // prompt user for text
    text = get_string("Text: ");

    // calculate & print coleman index value based on text input
    getColemanIndex(text);
}

// generate values for total letters, words and sentences using same loop
void getCounts(string s)
{
    for (int i = 0; i <= strlen(s); i++)
    {

        // if it's a letter, increment letter count
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            letterCount++;
        }

        // if it's a space, increment word count
        if (s[i] == ' ')
        {
            wordCount++;
        }

        // if it's a period or a question / exclamation mark, increment sentence count
        if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentenceCount++;
        }
    }

    // account for word at the end of a sentence
    wordCount++;
}

// calculate and print coleman index value
void getColemanIndex(string s)
{
    // count and save total letters, words and sentences in text
    getCounts(s);

    // generate values for letters and sentences per 100 words
    float L = (float) letterCount / wordCount * 100;
    float S = (float) sentenceCount / wordCount * 100;

    // evaluate for Coleman Index value
    float colemanIndex = round(0.0588 * L - 0.296 * S - 15.8);

    // print colemanIndex response
    if (colemanIndex < 1)
    {
        printf("%s\n", "Before Grade 1");
    }
    else if (colemanIndex >= 1 && colemanIndex <= 16)
    {
        printf("%s%i\n", "Grade ", (int) colemanIndex);
    }
    else
    {
        printf("%s\n", "Grade 16+");
    }
}