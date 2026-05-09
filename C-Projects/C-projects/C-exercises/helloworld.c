#include <stdio.h>
#include <stdlib.h>

int main()
{
    char  name[20];
    printf("Enter your name: ");
    fgets(name, 20, stdin);
    printf("You name is %s text\n", name);

} 