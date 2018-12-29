#import <cs50.h>
#import <stdio.h>

int main(void)
{
    // continously prompts the user for a value between 0 and 23 until valid input is given
    int n;
    do
    {
        n = get_int("Enter a number between 0 and 23: ");
    }
    while (n < 0 || n > 23);

    // uses provided height (n) to print pyramids
    int j;
    for (int i = 0; i < n; i++)
    {
        // prints spaces for the left half
        for (j = 0; j < (n - i - 1); j++)
        {
            printf(" ");
        }

        // prints blocks for the left half
        for (j = 0; j < (i + 1); j++)
        {
            printf("#");
        }

        // prints the space between the two sides
        printf("  ");

        // prints the blocks for the right half
        for (j = 0; j < (i + 1); j++)
        {
            printf("#");
        }

        printf("\n");

    }
}