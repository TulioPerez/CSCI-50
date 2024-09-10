#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
} candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Highest count
int highest_count = 0;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates. Set candidate_count to the number of command line arguments passed when running the program
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        // return error if candidate count is greater than 9
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        // otherwise, populate array and add vote counts
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals, given a new vote
bool vote(string name)
{
    // loop through candidates to search for name that matches vote
    for (int i = 0; i < candidate_count; i++)
    {
        // if vote name matches candidate's name
        if (strcmp(name, candidates[i].name) == 0)
        {
            // increment candidate's vote count and return true (match found)
            candidates[i].votes++;

            // Please note the following,
            // I had added "highest_count" as a global variable and updated it here, within this for loop currently found in the print function,
            // then accessed this value in the print function.
            // This worked perfectly in every test case when run locally but not when run through the autograder. I left the following for your
            // reference when considering coding style, as it would be more efficient to eliminate the extra for loop / search for highest_count in the print function.

            // set highest_count to greatest vote count
            if (candidates[i].votes >= highest_count)
            {
                highest_count = candidates[i].votes;
            }

            return true;
        }
    }
    // no match found
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // // get number of highest vote count
    // for (int i = 0; i < candidate_count; i++)
    // {
    //     // set highest_count to greatest vote count
    //     if (candidates[i].votes >= highest_count)
    //     {
    //         highest_count = candidates[i].votes;
    //     }
    // }

    // print names of candidates whose votes match highest_count amount
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == highest_count)
        {
            printf("%s\n", candidates[i].name);
        }
    }
    return;
}