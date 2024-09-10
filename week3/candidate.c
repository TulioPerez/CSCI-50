#include <cs50.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    string name;
    float prob_of_win;
    string party;
}
candidate;

candidate get_candidate(void);

int main(void)
{
    candidate candidates[3];

    // Get 3 candidates
    for (int i = 0; i < 3; i++)
    {
        candidates[i] = get_candidate();
    }

    for (int i = 0; i < 3; i++)
    {
        // Print candidate info
        printf("%s has a %f probability of winning and is a member of the %s party\n",
        candidates[i].name, candidates[i]. prob_of_win, candidates[i].party);
    }
}

candidate get_candidate(void)
{
    // declare a new candidate
    candidate newcandidate;

    // get candidate info
    newcandidate.name = get_string("Candidate name: \n");
    newcandidate.prob_of_win = get_int("Probability of winning: \n");
    newcandidate.party = get_string("Political party: \n");

    return newcandidate;
}