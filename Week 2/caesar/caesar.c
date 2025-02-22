#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Make sure every character in argv[1] is a digit
    for (int i = 0; i < strlen(argv[1]); i++)
    {
        if (!(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }else if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }

    // Convert argv[1] from a `string` to an `int`
    int k = atoi(argv[1]);

    // Prompt user for plaintext
    string s = get_string("plaintext: ");

    // For each character in the plaintext:
    printf("ciphertext: ");
    for (int i = 0; i < strlen(s); i++)
    {
        char c = s[i];

        // Rotate the character if it's a letter
        if (isalpha(c))
        {
            char A = isupper(c) ? 'A' : 'a';
            printf("%c", (c - A + k) % 26 + A);
        }
        else
        {
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}
