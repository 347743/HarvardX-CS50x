#include <cs50.h>
#include <ctype.h>

#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string w);

int main(void)
{
    // Prompt the user for two words
    string w1 = get_string("Player 1: ");
    string w2 = get_string("Player 2: ");

    // Compute the score of each word
    int s1 = compute_score(w1);
    int s2 = compute_score(w2);

    // Print the winner
    if (s1 > s2)
    {
        printf("Player 1 wins!\n");
    }
    else if (s1 < s2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

int compute_score(string w)
{
    // Keep track of score
    int score = 0;

    // Compute score for each character
    for (int i = 0, len = strlen(w); i < len; i++)
    {
        if (isupper(w[i]))
        {
            score += POINTS[w[i] - 'A'];
        }
        else if (islower(w[i]))
        {
            score += POINTS[w[i] - 'a'];
        }
    }

    return score;
}
