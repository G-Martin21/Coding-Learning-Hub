#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

int count_letters(string);
int count_words(string);
int count_sentences(string);

int main(void)
{
    /*
        1. Input: prompt the user for a string of text get_string
        2. count the number of letters, words and sentences in text
            a letter is any lowercase character from a to z or any uppercase character from A to Z,
            any sequence of characters separated by spaces should count as a word, and
            that any occurrence of a period, exclamation point, or question mark indicates the end of a sentence.
        3. Output: "Grade X", where X is givev by the Coleman-Liau formula rounded to the nearest integer.
           X should be between 1 to 15, if greater than or equal 16 => 16+, if less than 1 => "Before grade 1"
    */

   // Input

    string text = get_string("Text: ");
    printf("%s", text);
    count_letters(text);
    count_words(text);
    count_sentences(text);

    int count_letters(string text)
    {
        int i = 0;
        int num_letters = 0;
        while (text[i] != '\0')
        {
            if (isalpha(text[i])
            {
                num_letters++;
            }
        }
        printf("%l", letters);
        return num_letters;
    }
    

    int count_words(string text)
    {
        int i = 0;
        int num_words = 0;
        while (text[i] != '\0')
        {
            if (isspace(text[i]))
            {
                num_words++;
            }
        }
        printf("%l", num_words++);
        return num_words++;
    }

    int count_sentences(string text)
    {
        int i = 0;
        int num_sentences = 0;
        while (text[i] != '\0')
        {
            if (text[i] == 33 || text[i] == 46 || text[i] == 63)
            {
                num_sentences++
            }
        }
        printf("%l", num_sentences);
        return num_sentences;
    }
}
