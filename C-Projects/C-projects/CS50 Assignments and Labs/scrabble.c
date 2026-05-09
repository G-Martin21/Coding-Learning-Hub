#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
int is_alpha(int character);
void print_winner(int score1, int score2);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    print_winner(score1, score2);
}

int compute_score(string word)
{
    /*
        Check a string and compute each letter value in a scrabble game.
        1. In C each char is store as an int ASCII value.
        2. Every string has a null character, '\0', to indicate when the string ends.
    */

    int i = 0;
    int points = 0;
    int index;
    while (word[i] != '\0')
    {
        index = is_alpha(word[i]);
        if (index != -1)
        {
            points += POINTS[index];
        }
        i++;
    }
    return points;
}

int is_alpha(int character)
{
    /*
       Check if the argument provide is a letter A to Z (ASCII 65 to 97) or a to z (97 to 122).
       Return -1 if it is not a letter or if it is a letter is position in the alphabet.
        1. char are store in C as ASCII int values.
    */

    int value = -1;
    if (character >= 65 && character <= 90)
    {
        value = character - 65;
    }
    else if (character >= 97 && character <= 122)
    {
        value = character - 97;
    }

    return value;
}

void print_winner(int score1, int score2)
{
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

