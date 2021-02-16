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
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

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

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int m = 0; m < voter_count; m++)
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

// Update vote totals given a new vote
int x = 0;
bool vote(string name)
{
    // TODO
    for (int k = 0; k < candidate_count; k++)
    {
        if (strcmp(name, candidates[k].name) == 0)
        {
            candidates[k].votes++;
            return true;
        }
    }
    return false;
}
string winner;
int winnervotes;
// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    winner = candidates[0].name;
    winnervotes = candidates[0].votes;
    if (candidate_count > 1)
    {
        for (int n = 1; n < candidate_count; n++)
        {
            if (candidates[n].votes >= winnervotes)
            {
                winnervotes = candidates[n].votes;
            }
        }
        for (int p = 0; p < candidate_count; p++)
        {
            if (candidates[p].votes == winnervotes)
            {
                printf("%s\n", candidates[p].name);
            }
        }
    }
}

