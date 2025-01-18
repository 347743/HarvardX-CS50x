#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // Ensure the program is run with exactly one command-line argument
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }

    // Ensure the key has 26 characters
    string k = argv[1];
    int len = strlen(k);
    if (len != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    // Ensure the key contains only alphabetic characters
    for (int i = 0; i < len; i++)
    {
        if (!isalpha(k[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }

        // Ensure the key has no duplicate characters
        for (int j = i + 1; j < len; j++)
        {
            if (tolower(k[i]) == tolower(k[j]))
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }

    // Prompt user for plaintext
    string s = get_string("plaintext: ");

    // Print the ciphertext
    printf("ciphertext: ");
    for (int i = 0; i < strlen(s); i++)
    {
        char c = s[i];

        if (isupper(c))
        {
            // Map uppercase letters using the key
            printf("%c", toupper(k[c - 'A']));
        }
        else if (islower(c))
        {
            // Map lowercase letters using the key
            printf("%c", tolower(k[c - 'a']));
        }
        else
        {
            // Non-alphabetic characters remain unchanged
            printf("%c", c);
        }
    }
    printf("\n");
    return 0;
}
