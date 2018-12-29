#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // continuously prompts the user for a positive amount owed
    float changeOwed;
    do
    {
        changeOwed = get_float("Change owed: ");
    }
    while (changeOwed < 0);

    // quarters, dimes, nickels, and pennies are available
    float coins[] = {0.25, 0.10, 0.05, 0.01};
    int numberCoins = 0;

    for (int i = 0; i < 4; i++)
    {
        // if the change owed minus the current coin's value remains positive, give that coin as change
        // repeat this until the difference would be negative, then move to the next smallest denomination
        while (changeOwed - coins[i] > -0.005)
        {
            numberCoins += 1;
            changeOwed -= coins[i];
        }
    }

    printf("Number of coins: %i\n", numberCoins);
}