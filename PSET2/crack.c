#define _XOPEN_SOURCE
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, string argv[])
{
    // if the incorrect number of arguments is provided, an error is thrown before returning 1
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    // stores the provided argument in the variable 'hash'
    string hash = argv[1];
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // creates a character array to accommodate passwords up to length 5
    char letters[6];
    letters[5] = '\0';

    // determines the salt by taking the first two characters of 'hash'
    char salt[3] = {hash[0], hash[1]};
    salt[2] = '\0';

    // depth controls the length of the possible passwords being checked
    // all possibilities of length one are checked before moving onto those of length two and so on
    int depth = 1;

    // indices for each place in the possible password
    int first, second, third, fourth, fifth;

    // iterates all possible passwords
    for (first = 0; first < 52; first++)
    {
        letters[0] = alphabet[first];

        // if the current depth is greater than one, at least the second place will also be checked
        if (depth > 1)
        {
            for (second = 0; second < 52; second++)
            {
                letters[1] = alphabet[second];

                // if the current depth is greater than two, at least the third place will also be checked
                if (depth > 2)
                {
                    for (third = 0; third < 52; third++)
                    {
                        letters[2] = alphabet[third];

                        // if the current depth is greater than three, at least the fourth place will also be checked
                        if (depth > 3)
                        {
                            for (fourth = 0; fourth < 52; fourth++)
                            {
                                letters[3] = alphabet[fourth];

                                // if the current depth is greater than four, all places will be checked
                                if (depth > 4)
                                {
                                    for (fifth = 0; fifth < 52; fifth++)
                                    {
                                        letters[4] = alphabet[fifth];

                                        // // this can be uncommented to keep track of where in the search process the program is
                                        // if (third == 51 && fourth == 51 && fifth == 51)
                                        // {
                                        //     printf("letters: %s\n", letters);
                                        // }

                                        // if a match is found to 'hash', the decrypted password is shown before returning 0
                                        if (strcmp(hash, crypt(letters, salt)) == 0)
                                        {
                                            printf("Found it: %s\n", letters);
                                            return 0;
                                        }

                                    }

                                }

                                if (depth == 4)
                                {
                                    if (strcmp(hash, crypt(letters, salt)) == 0)
                                    {
                                        printf("Found it: %s\n", letters);
                                        return 0;
                                    }

                                    /* if all four letter combinations have been exhausted, the loops
                                       are restarted and will begin checking all those of length five */
                                    if (letters[0] == 'Z' && letters[1] == 'Z' && letters[2] == 'Z' && letters[3] == 'Z')
                                    {
                                        depth++;
                                        first = -1;
                                    }

                                }

                            }

                        }

                        if (depth == 3)
                        {
                            if (strcmp(hash, crypt(letters, salt)) == 0)
                            {
                                printf("Found it: %s\n", letters);
                                return 0;
                            }

                            /* if all three letter combinations have been exhausted, the loops
                               are restarted and will begin checking all those of length four */
                            if (letters[0] == 'Z' && letters[1] == 'Z' && letters[2] == 'Z')
                            {
                                depth++;
                                first = -1;
                            }

                        }

                    }

                }

                if (depth == 2)
                {
                    if (strcmp(hash, crypt(letters, salt)) == 0)
                    {
                        printf("Found it: %s\n", letters);
                        return 0;
                    }

                    /* if all two letter combinations have been exhausted, the loops
                       are restarted and will begin checking all those of length three */
                    if (letters[0] == 'Z' && letters[1] == 'Z')
                    {
                        depth++;
                        first = -1;
                    }

                }

            }

        }

        if (depth == 1)
        {
            if (strcmp(hash, crypt(letters, salt)) == 0)
            {
                printf("Found it: %s\n", letters);
                return 0;
            }

            /* if each single letter has been exhausted, the loops are
               restarted and will begin checking all combinations of length two */
            if (letters[0] == 'Z')
            {
                depth++;
                first = -1;
            }

        }

    }

    printf("No results\n");
    return 1;
}