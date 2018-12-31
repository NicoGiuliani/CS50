#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // if the incorrect number of arguments is provided, an error will be thrown before returning 1
    if (argc != 2)
    {
        printf("Error: incorrect number of arguments provided");
        return 1;
    }

    // stores the command line argument as the shift value
    int shift = atoi(argv[1]);
    string plaintext = get_string("plaintext: ");
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowercaseAlphabet = "abcdefghijklmnopqrstuvwxyz";

    // iterates over the plaintext message in order to encoded one character at a time
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        // iterates over the alphabet to determine the index of the current character
        for (int j = 0; j < 26; j++)
        {
            // if a match is found, that character in the plaintext will be replaced by its encoded equivalent
            if (plaintext[i] == alphabet[j] || plaintext[i] == lowercaseAlphabet[j])
            {
                plaintext[i] = (plaintext[i] == alphabet[j]) ? alphabet[(j + shift) % 26] : lowercaseAlphabet[(j + shift) % 26];
                break;
            }
        }
    }

    printf("ciphertext: %s\n", plaintext);
    return 0;
}