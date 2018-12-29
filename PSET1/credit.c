#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // prompts the user for a credit card number
    long long cardNumber = get_long_long("Enter credit card number: ");
    bool timesTwo = false;
    int currentDigit;
    int length = 0;
    int checksum = 0;
    int lead = 0;

    // by repeatedly dividing the card number by ten, the digit in each place can be handled individually
    while (cardNumber > 0)
    {
        currentDigit = cardNumber % 10;
        length += 1;
        cardNumber /= 10;

        // this saves the first two digits of the card (left-to-right)
        if (cardNumber / 100 > 10)
        {
            lead = cardNumber / 100;
        }

        // starting with the number's second-to-last digit, every other digit is multiplied by two
        if (timesTwo)
        {
            int temp = currentDigit * 2;

            // if after being multiplied by two, temp is a single digit, it is added directly to checksum
            if (temp < 10)
            {
                checksum += temp;
            }
            // otherwise its digits will be separated by repeatedly dividing by ten, adding each to checksum
            else
            {
                while (temp > 0)
                {
                    checksum += (temp % 10);
                    temp /= 10;
                }
            }
            timesTwo = false;
        }
        // all digits not multiplied by two are added directly to the checksum
        else
        {
            checksum += currentDigit;
            timesTwo = true;
        }

    }

    // if the checksum is not evenly divisible by ten, it is marked invalid
    if ((checksum % 10) != 0)
    {
        printf("INVALID\n");
    }
    // American Express cards begin with either 34 or 37 and contain 15 digits
    else if ((lead == 34 || lead == 37) && length == 15)
    {
        printf("AMEX\n");
    }
    // MasterCard numbers begin with 51, 52, 53, 54, or 55 and contain 16 digits
    else if ((lead == 51 || lead == 52 || lead == 53 || lead == 54 || lead == 55) && length == 16)
    {
        printf("MASTERCARD\n");
    }
    // Visa cards start with 4 and contain either 13 or 16 digit
    else if ((lead / 10) == 4 && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }
    // all other possibilities are considered invalid
    else
    {
        printf("INVALID\n");
    }

}