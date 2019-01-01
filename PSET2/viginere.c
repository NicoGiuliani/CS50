#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(int argc, string argv[])
{
    // if the incorrect number of arguments is provided, an error will be thrown before returning 1
    if (argc != 2)
    {
        printf("Error: incorrect number of arguments.\n");
        return 1;
    }

    // if the provided keyword contains non-alphabetical characters, an error will be thrown before returning 1
    for (int i = 0, n = strlen(argv[1]); i < n; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Error: keyword must be composed entirely of alphabetical characters.\n");
            return 1;
        }
    }

    // stores the provided keyword, then creates an array with a length equal to that of the keyword
    string keyword = argv[1];
    int keylength = strlen(keyword);
    int shifts[keylength];

    // prompts the user for plaintext input to be encoded
    string plaintext = get_string("plaintext: ");
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string lowercaseAlphabet = "abcdefghijklmnopqrstuvwxyz";

    // populates shifts[] with the numerical shift values associated with each letter in the keyword
    for (int i = 0; i < keylength; i++)
    {
        for (int j = 0, n = strlen(alphabet); j < n; j++)
        {
            if (keyword[i] == alphabet[j] || keyword[i] == lowercaseAlphabet[j])
            {
                shifts[i] = j;
                break;
            }
        }
    }

    // iterates over the plaintext and replaces each letter with its encoded equivalent
    for (int i = 0, q = 0, n = strlen(plaintext); i < n; i++)
    {
        for (int j = 0, s = strlen(alphabet); j < s; j++)
        {
            if (plaintext[i] == alphabet[j] || plaintext[i] == lowercaseAlphabet[j])
            {
                plaintext[i] = (plaintext[i] == alphabet[j]) ? alphabet[(j + shifts[q]) % s] : lowercaseAlphabet[(j + shifts[q]) % s];
                q = (q + 1) % keylength;
                break;
            }
        }
    }

    printf("ciphertext: %s\n", plaintext);
    return 0;
}