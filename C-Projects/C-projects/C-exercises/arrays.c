#include <stdio.h>
#include <stdlib.h>

int main()
{
    char colors[] = {"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"};
    char color[6];
    int indexColor;

    printf("Enter a number: \n");
    scanf("%i", &indexColor);
    printf("%s", &colors[indexColor]);

    return 0;
}

