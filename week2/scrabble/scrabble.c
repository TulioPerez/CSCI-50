#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// declare return values to be printed out by function
const string RESULTS[] = {"Player 1 wins!\n", "Player 2 wins!\n", "Tie!\n"};

// declare point value system for chars in strings
const int POINTSCORE[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

// method signature declarations
int getScore(string s);
string checkWinner(string s1, string s2);

int main(void)
{
    // get input from players and save to variables
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // print the result of the function that checks for the winner
    printf("%s", checkWinner(word1, word2));
}

// calculate score for a word
int getScore(string s)
{
    int tempScore = 0;
    for (int i = 0; i < strlen(s); i++)
    {
        // if char is lowercase, assign uppercase version of character
        if (islower(s[i]))
        {
            s[i] = toupper(s[i]);
        }

        // Add the point score for each letter to tempScore. The index number of POINTSCORE that corresponds to a particular char
        // is equal to the char's ascii value subtracted by the value of 'A'.
        tempScore += POINTSCORE[s[i] - 'A'];
    }

    return tempScore;
}

// calculate and return the string message announcing the winner
string checkWinner(string s1, string s2)
{
    int score1 = getScore(s1);
    int score2 = getScore(s2);

    if (score1 > score2)
    {
        return RESULTS[0];
    }
    else if (score2 > score1)
    {
        return RESULTS[1];
    }
    return RESULTS[2];
}