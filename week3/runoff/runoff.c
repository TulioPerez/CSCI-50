#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
} candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // Compare user entry to candidate name to validate candidate choice
        if (strcmp(name, candidates[i].name) == 0)
        {
            // Add candidate to voter's preferences array
            preferences[voter][rank] = i;

            // Valid candidate choice
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // loop through voters
    for (int i = 0; i < voter_count; i++)
    {
        // loop through candidates
        for (int j = 0; j < candidate_count; j++)
        {
            // set candidates_index to preference value
            int current_candidate = preferences[i][j];

            // if candidate is not yet eliminated, increment their votes
            if (!candidates[current_candidate].eliminated)
            {
                candidates[current_candidate].votes++;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    int vote_count = 0;

    // Count total votes
    for (int i = 0; i < candidate_count; i++)
    {
        vote_count += candidates[i].votes;
    }

    // loop through candidates and search for candidate with >= half the votes
    for (int i = 0; i < candidate_count; i++)
    {
        // print most popular candidate if votes are >= half of total_votes
        if (candidates[i].votes > (voter_count / 2))
        {
            printf("winner %s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // initialize return value as number of voters
    int minimum_count = voter_count;

    for (int i = 0; i < candidate_count; i++)
    {
        // if candidate is not eliminated and votes are less than min count
        if (!candidates[i].eliminated && candidates[i].votes < minimum_count)
        {
            // set minimum_count to new min vote count
            minimum_count = candidates[i].votes;
        }
    }
    return minimum_count;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    for (int i = 0; i < candidate_count; i++)
    {
        // Check if candidate has not been eliminated && that votes are greater than min
        if (candidates[i].votes > min && !candidates[i].eliminated)
        {
            // Election is not tied
            return false;
        }
    }
    // Election is tried
    return true;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // loop through candidates
    for (int i = 0; i < candidate_count; i++)
    {
        // check if candidates was not eliminated && that votes are == minvotes
        if (!candidates[i].eliminated && candidates[i].votes == min)
        {
            // set candidate's status to eliminated
            candidates[i].eliminated = true;
        }
    }
    return;
}