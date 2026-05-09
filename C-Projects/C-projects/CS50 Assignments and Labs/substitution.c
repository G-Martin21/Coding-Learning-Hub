#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int check_key(string);
bool is_alpha(string);
bool is_unique_values(string);
void print_cipher(string, string);
int get_index(int);


int main(int argc, string argv[])
{
    /*key provide as a commang line argument
        argc number of command line arguments
        argv[] command line arguments provided

        check key length
        check for non alphabetic characters
        check for repeated characters (case-insensitive)

    get the substitution cipher from the user
    check if it is correct
        26 letters, no repetitions, no other char
    store the substitution in a array (string)
    prompt the user for a string to cipher
        get_string
        "plaintext: "
        check the imput is correct
        get the cipher text, preserving letters case and any other non-letter char and spaces
         for each alphabetic characte, determin what letter it maps to
         preserve case
         leave non-alphabetic characters as-is

        "ciphertext: "

  Test cases
    is entry < 26 char? => "Key must contain 26 characters." return a status code of 1 to indicate error
    has entry 26 char plus a digit? => "Key must only contain alphabetic characters." return 1
    has entry repeated characater= => "Key must not contain repeated characters." exit with return code 1
    is entry case insensitive?
    is entry mix case indifferent?
    no key input? => "Usage: ./substituion KEY" ok

    is case preserved?  ok
    is any other char, punctuation or space preserve  ok
    */

    //string key = "YTNSHKVEFXRBAUQZCLWDMIPGJO";
    string text = "Hello, Friends Zz";

    /*printf("\ncmdline args count=%i", argc);

    /* First argument is executable name only
    printf("\nexe name=%s\n", argv[0]);*/


    if (argc != 2)
    {
        printf("Usage: ./substitution KEY\n");
    } else if (argc == 2)
    {
        if (check_key(argv[1]) != -1)
        {
            print_cipher(text, argv[1]);
        }
    }
}

int check_key(string key)
{
    int error = 1;
    if (strlen(key) < 26 || strlen(key) > 26)
    {
        printf("Key must contain 26 characters.\n");
        error = -1;
    } else
    {
        if (!is_alpha(key))
        {
            printf("Key must only contain alphabetic characters.\n");
            error = -1;
        } else if (!is_unique_values(key))
        {
            printf("Key must not contain repeated characters.\n");
            error = -1;
        }
    }
    return error;
}

bool is_alpha(string text)
{
    /*
       Check if the string provide contain only letters;letter A to Z (ASCII 65 to 97) or a to z (97 to 122).
    */

    for (int i = 0; i < strlen(text); i++)
    {
        if (!((text[i] >= 65 && text[i] <= 90) || (text[i] >= 97 && text[i] <= 122)))
        {
            return false;
        }
    }
    return true;
}

bool is_unique_values(string text)
{
    char char_i, char_j;
    for (int i = 0; i < strlen(text); i++)
    {
        for (int j = i + 1; j < strlen(text); j++)
        {
            char_i = (islower(text[i])) ? text[i] : text[i] + 32;
            char_j = (islower(text[j])) ? text[j] : text[j] + 32;
            if (char_i == char_j)
            {
                return false;
            }
        }
    }
    return true;
}

void print_cipher(string text, string key)
{
     /*
        Given a string and a key prints the cipher text.
    */

    char ciphertext[strlen(text)];
    printf("len %lu\n", strlen(text));
    int i = 0;
    while (text[i] != '\0')
    {
        int index = get_index(text[i]);
        if (index != -1)
        {
            if (islower(text[i]))
            {
                // If key[index] is in uppercase, we get its ASCCII code for lowercase adding 32 and if
                // key[index] is in lowercase, we get its ASCII code for uppercase substracting 32.
                ciphertext[i] = (islower(key[index])) ? key[index] : key[index] + 32;
            }
            else
            {
                ciphertext[i] = (islower(key[index])) ? key[index] - 32: key[index];
            }
        }
        else
        {
            ciphertext[i] = text[i];
        }
        i++;
    }
    printf("ciphertext: %s\n", ciphertext);
}


int get_index(int character)
{
    /*
       Check if the argument provide is a letter A to Z (ASCII 65 to 97) or a to z (97 to 122).
       Return -1 if it is not a letter or if it is a letter is position in the alphabet, 0 to 25.
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
