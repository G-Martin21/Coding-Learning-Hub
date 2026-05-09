#include <cs50.h>
#include <math.h>
#include <stdio.h>

/*
    Prompt user to enter a credit card number.
    Check its structure is a valid card number: has the correct lenght, has the correct first numbers
    depending of maker and using Luhn's Algorithm check it is a valid card.
*/

int check_card(long int);
int LuhnsAlgorithm(long int);


int main()
{
    long l = get_long("Enter a credit card number: ");

    /* https://brilliant.org/wiki/finding-digits-of-a-number/
    / We use base 10 logarithm to get the length of a decimal number, taking only the integer part.
    */
    int count_digits = log10(l) + 1;

    if (l <= 0)
    {
        printf("INVALID\n");
    }
    else if (count_digits <= 12)
    {
        printf("INVALID\n");
    }
    else
    {
        check_card(l);
    }
}


int check_card(long int number)
{
    /* To get the first digit or the first and second digit of the number, just use division
      by a power of 10 to move the decimal point and keep only the integer part.
    */
    int digits = log10(number) + 1;
    int first_digit = number / pow(10, digits - 1);
    int first_second_digit = number / pow(10, digits - 2);

    if (digits == 15 && (first_second_digit == 34 || first_second_digit == 37))
    {
        if (!LuhnsAlgorithm(number))
        {
            printf("AMEX\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if (digits == 16 && (first_second_digit >= 51 && first_second_digit <= 55))
    {
        if (!LuhnsAlgorithm(number))
        {
            printf("MASTERCARD\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else if ((digits >= 13 && digits <= 16) && (first_digit == 4))
    {
        if (LuhnsAlgorithm(number) == 0)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
    return first_digit;
}

int LuhnsAlgorithm(long int number)
{
    /*
     Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those
     products’ digits together.
     Add the sum to the sum of the digits that weren’t multiplied by 2.
     If the total’s last digit is 0 (the total modulo 10 is congruent to 0),
     the number is valid!
    */
    // number of digits: log10(number)+1


    int digits = log10(number) + 1;

    long int digit;
    int total_sum = 0;
    int digits_number[digits];

    long int working_number = number;
    for (int i = 0; i < digits; i++)
    {
        digits_number[i] = working_number % 10;
        working_number = working_number / 10;
    }
    int total = 0;
    for (int j = 1; j < digits; j++)
    {
        if ((j + 1) % 2 == 0)
        {
            total = 2 * digits_number[j];
            if (total > 9)
            {
                int digits_total = log10(total) + 1;
                for (int jj = 0; jj < digits_total; jj++)
                {
                    total_sum += total % 10;
                    total = total / 10;
                }
            }
            else
            {
                total_sum += total;
            }
        }
    }
    for (int k = 0; k < digits; k++)
    {
        if ((k + 1) % 2 != 0)
        {
            total_sum += digits_number[k];
        }
    }
    return total_sum % 10;
}
