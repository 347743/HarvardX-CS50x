#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int n;
    // Prompt user for the height of the pyramid
    do
    {
        printf("Height: ");
        int r = scanf("%d", &n);

        // Clear input buffer if the user enters a non-integer value
        if (r != 1)
        {
            while (getchar() != '\n')
                ;
            n = 0; // Force another prompt
        }
    }
    while (n < 1 || n > 8);

    // Print the pyramid
    for (int i = 1; i <= n; i++)
    {
        // Print spaces
        for (int j = 0; j < n - i; j++)
        {
            printf(" ");
        }
        // Print left hashes
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }
        // Print the gap between the pyramids
        printf("  ");

        // Print left hashes
        for (int j = 0; j < i; j++)
        {
            printf("#");
        }

        // Move to the next line
        printf("\n");
    }

    return 0;
}
