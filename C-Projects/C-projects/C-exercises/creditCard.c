#include <cs50.h>
#include <math.h>
#include <stdio.h>

int count_digits(long int);
int check_card_vendor(long int);


int main()
{
    long l = get_long("Enter a credit card number: ");

    /* https://brilliant.org/wiki/finding-digits-of-a-number/
    / We use base 10 logarithm to get the length of a decimal number, taking only the integer part.
    */
    int count_digits = log10(l)+1;
    
    if (l <= 0)
    {
        printf("Invalid entry\n");
    } else if (count_digits <= 12)
    {
        printf("Invalid entry\n");
    } else
    {
        check_card_vendor(l);
        printf("Output: %li\n", l);
    }
}
/*
int count_digits(long int number)
{
    int count = 0;
    do
    {
     number /= 10;
     ++count;
    } while (number != 0);

    return count;
}
*/
int check_card_vendor(long int number)
{
    /* To get the first digit or the first and second digit of the number, just use division
      by a power of 10 to move the decimal point.
    */
    int digits = log10(number)+1;
    int first_digit = number/pow(10, digits-1);
    int first_second_digit = number/pow(10, digits-2);
    printf("%i\n", first_second_digit);

    if (digits == 15 && (first_second_digit == 34 || first_second_digit == 37))
    {
        printf("AMEX");
    } else if (digits == 16 && (first_second_digit >= 51 && first_second_digit <= 55))
    {
        printf("MASTERCARD");
    } else if ((digits >= 13 && digits <= 16) && (first_digit == 3 || first_digit == 4))
    {
        printf("VISA");
    } else
    {
        printf("Invalid card\n");
    }
    return first_digit;
}

int LuhnsAlgorithm(long int number)
{
    /*
     Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products’ digits together.
    Add the sum to the sum of the digits that weren’t multiplied by 2.
    If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    */
    // number of digits: log10(number)+1
    // n-th digit: int(number%pow(10, n)/pow(10, n-1)); n >= 1 and being n=1 the digit in the rightmost position.
    // remember than a digital number is a sum of powers of 10

    int digits = log10(number)+1;
    int digit;
    int total_sum = 0;

    for (int i = 1; i <= digits; i++)
    {
        digit = floor(number % (int) pow(10, i) / pow(10, i - 1));
        //printf("digit %i\n", digit);
        if (i % 2 == 0)
        {
            total_sum += 2 * digit;
        }
    }
            printf("Partial sum 1: %i", total_sum);
    for (int j = 1; j <= digits; j++)
    {
        digit = floor(number % (int) pow(10, j) / pow(10, j - 1));
        if (j % 2 != 0)
        {
            total_sum += digit;
        }
    }
    printf("Total sum: %i\n", total_sum);
    return 0;
}
/*
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

TDD

 - works with empty (PROMPT, NULL) -> prompt again OK
 - works with negative (INVALID, NEGATIVE NUMBER) ok
 - works with zero (INVALID, ZERO NUMBER) ok
 - works with non numeric (PROMPT, CHAR STRING) -> PROMPT AGAIN OK
 - works with hyphens (PROMPT, 4003-6000-0000-0014) -> prompt again OK
 - works with shorter length (INVALID, 6176292929)  12 DIGITS OR LESS OK
 - works with leading zeroes (INVALID, 0036000000000144) X
 - works with AMEX (AMEX, 378282246310005)
 - works with MASTERCARD (MASTERCARD, 5105105105105100)
 - works with MASTERCARD (MASTERCARD, 5555555555554444)
 - works with VISA (VISA, 4012888888881881)
 - works with VISA (VISA, 4222222222222)
 */