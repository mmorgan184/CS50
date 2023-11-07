#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

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
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    // Convert argv[1] from a `string` to an `int`
    int k = atoi(argv[1]);
    if (k < 0)
    {
        printf("Key must be a non-negative integer.\n");
        return 1;
    }
    // Prompt user for plaintext
    string plaintext = get_string("Plaintext: ");
    // For each character in the plaintext:

        // Rotate the character if it's a letter
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            plaintext[i] = ((plaintext[i] - 'A' + k) % 26) + 'A';
        }
        else if (islower(plaintext[i]))
        {
            plaintext[i] = ((plaintext[i] - 'a' + k) % 26) + 'a';
        }
    }
    printf("ciphertext: %s\n", plaintext);
}
