#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // continously prompts the user for a value between 0 and 23 until valid input is given
    int n;
    do
    {
        n = get_int("Enter a number between 0 and 23: ");
    }
    while (n < 0 || n > 23);

    // uses provided height (n) to print pyramid
    int j;
    for (int i = 0; i < n; i++)
    {
        // the number of spaces in each row is equal to the base (n + 1) minus two more than the current row index (i + 2)
        // (n + 1) - (i + 2) = n - i - 1
        for (j = 0; j < (n - i - 1); j++)
        {
            printf(" ");
        }

        // the number of blocks in each row is always equal to two more than the current row index (i + 2)
        for (j = 0; j < (i + 2); j++)
        {
            printf("#");
        }

        printf("\n");
    }
}