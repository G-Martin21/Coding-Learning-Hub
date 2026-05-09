#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string);
void print_cipher(string, string);
char rotate(char, int);


int main(int argc, string argv[])
{
    int error = 0;
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        error = 1;
    }
    else if (argc == 2)
    {
        if (!only_digits(argv[1]))
        {
            printf("Usage: ./caesar key\n");
            error = 1;
        }
        else
        {
            string text = get_string("plaintext:  ");
            print_cipher(text, argv[1]);
        }
    }
    return error;
}

bool only_digits(string key)
{
    int i = 0;
    while (key[i] != '\0')
    {
        if (!isdigit(key[i]))
        {
            return false;
        }
        i++;
    }
    return true;
}

void print_cipher(string text, string skey)
{
    int i = 0;
    char ciphertext[strlen(text)];
    int key = atoi(skey) % 26;

    while (text[i] != '\0')
    {
        ciphertext[i] = rotate(text[i], key);
        i++;
    }
    printf("ciphertext: %s\n", ciphertext);
    return;
}

char rotate(char character, int key)
{
    char value = character;
    int index;
    if (isalpha(value))
    {
        if (islower(value))
        {
            index = (value - 97 + key) % 26;
            value = (char)(index + 97);
        }
        else
        {
            index = (value - 65 + key) % 26;
            value = (char)(index + 65);
        }
        //index = (islower(value)) ? (value - 97 + key) : (value - 65 + key);
    }
    return value;
}