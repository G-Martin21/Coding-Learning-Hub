#include <math.h>
#include <stdio.h>

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
        /*printf("Type of Card: %li\n", l);
        //printf("Algorithm %i", LuhnsAlgorithm(l));
        if (!LuhnsAlgorithm(l))
        {
            //printf("Valid card");
        }*/
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
    //printf("%i\n", first_second_digit);

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
            //printf("Total %i\n", total);
            if (total > 9)
            {
                int digits_total = log10(total) + 1;
                for (int jj = 0; jj < digits_total; jj++)
                {
                    total_sum += total % 10;
                    //printf("%i\n", total_sum);
                    total = total / 10;
                }
            }
            else
            {
                total_sum += total;
            }

            //printf("sum: %i and %i\n", digits_number[j], total_sum);
        }
    }
    //printf("Partial sum 1: %i", total_sum);
    for (int k = 0; k < digits; k++)
    {
        if ((k + 1) % 2 != 0)
        {
            total_sum += digits_number[k];
        }
    }
    //printf("Total sum: %i\n", total_sum);
    return total_sum % 10;
}
/* Notes

Pseudocode

prompt user to enter a credit card number
check its structure is a valid card number
 - numeric enter, no hyphens and not leading zeroes
 - check structure
    AMEX 15 digits start with 34 or 37
    MASTERCARD 16-digits, start with 51,52,53,54,55
    VISA 13 to 16 digits, start with 3 or 4
 - outPut correct card name (AMEX, MASTERCARD, VISA or INVALID)
 Apply Luhn algoritm to obtain the checksum
  - the result is 0? (total modulo 10 is congruent to 0) => legit card
   - else reject

Test Cases

 - works with empty (PROMPT, NULL) -> prompt again OK
 - works with negative (INVALID, NEGATIVE NUMBER) ok
 - works with zero (INVALID, ZERO NUMBER) ok
 - works with non numeric (PROMPT, CHAR STRING) -> PROMPT AGAIN OK
 - works with hyphens (PROMPT, 4003-6000-0000-0014) -> prompt again OK
 - works with shorter length (INVALID, 6176292929)  12 DIGITS OR LESS OK
 - works with leading zeroes (INVALID, 0036000000000144) X
 - works with AMEX (AMEX, 378282246310005) OK
 - works with MASTERCARD (MASTERCARD, 5105105105105100) OK
 - works with MASTERCARD (MASTERCARD, 5555555555554444) OK
 - works with VISA (VISA, 4012888888881881) OK
 - works with VISA (VISA, 4222222222222) OK
 */
