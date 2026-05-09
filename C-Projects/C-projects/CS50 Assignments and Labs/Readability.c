#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <math.h>

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
        3. Output: "Grade X", where X is given by the Coleman-Liau formula rounded to the nearest integer.
           X should be between 1 to 15, if greater than or equal 16 => 16+, if less than 1 => "Before grade 1"
    */

    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    float avg_letters = ((float) letters / (float) words) * 100;
    float avg_sentences = ((float) sentences / (float) words) * 100;
    float index = (0.0588 * avg_letters) - (0.296 * avg_sentences) - 15.8;
    int grade = round(index);

    if (grade >= 1 && grade < 16)
    {
        printf("Grade %d\n", grade);
    }
    else if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    int i = 0;
    int num_letters = 0;
    while (text[i] != '\0')
    {
        if (isalpha(text[i]))
        {
            num_letters++;
        }
        i++;
    }
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
        i++;
    }
    num_words++;
    return num_words;
}

int count_sentences(string text)
{
    int i = 0;
    int num_sentences = 0;
    while (text[i] != '\0')
    {
        if (text[i] == 33 || text[i] == 46 || text[i] == 63)
        {
            num_sentences++;
        }
        i++;
    }
    return num_sentences;
}