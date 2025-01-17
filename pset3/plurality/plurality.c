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
    /*for (int i = 0; i < candidate_count; i++)
    {
        printf("%i\n", candidates[i].votes);
    }
    for (int i = 0; i < candidate_count; i++)
    {
        printf("%s\n", candidates[i].name);
    }*/
}

// Update vote totals given a new vote
bool vote(string name)
{
    // Count the votes cast for each candidate
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            ++candidates[i].votes;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    int i, j, temp1;
    string temp2;
    for (i = 0; i < candidate_count - 1; i++)
    {
        for (j = 0; j < candidate_count - i - 1; j++)
        {
            if (candidates[j].votes > candidates[j + 1].votes)
            {
                temp1 = candidates[j].votes;
                candidates[j].votes = candidates[j + 1].votes;
                candidates[j + 1].votes = temp1;
                temp2 = candidates[j].name;
                candidates[j].name = candidates[j + 1].name;
                candidates[j + 1].name = temp2;
            }
        }
    }
    if (candidates[candidate_count - 1].votes > candidates[candidate_count - 2].votes)
    {
        printf("%s\n", candidates[candidate_count - 1].name);
    }
    else if (candidates[candidate_count - 1].votes == candidates[candidate_count - 3].votes)
    {
        printf("%s\n%s\n%s\n", candidates[candidate_count - 1].name, candidates[candidate_count - 2].name,
               candidates[candidate_count - 3].name);
    }
    else if (candidates[candidate_count - 1].votes == candidates[candidate_count - 2].votes)
    {
        printf("%s\n%s\n", candidates[candidate_count - 1].name, candidates[candidate_count - 2].name);
    }
    else
    {
        return;
    }
}