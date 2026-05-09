#include <stdio.h>
#include <stdlib.h>

int main()
{
    const char *colours[10] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
    //char color[6];
    int indexColor;
    char usercolour;
    char *colour;
    int i = 0;

    printf("Enter a number: ");
    scanf("%i", &indexColor);
    printf("%s\n", colours[indexColor]);

    printf("Enter a colour: ");
    scanf("%s", usercolour);

    while (i < 10)
    {
        if (usercolour == colours[i])
        {
            printf("%i has index: ", i);
        }
        i++;
    }

    return 0;
}

