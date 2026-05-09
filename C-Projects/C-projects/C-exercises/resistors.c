//https://stackoverflow.com/questions/37019527/calculating-the-resistor-value-with-its-color-bands-as-input
#include <stdio.h>
#include <stdlib.h>

int main()
{
    typedef enum
    {
        BLACK,
        BROWN,
        RED,
        ORANGE,
        YELLOW,
        GREEN,
        BLUE,
        VIOLET,
        GREY,
        WHITE
    } resistor_band_t;
    
    char colorToCheck[6];
    int value;
    resistor_band_t color;

    printf("Enter a number to check: ");
    scanf("%i", &value);
    color = value;
    printf("The value has a color of %i\n", color);

    printf("Enter a color to check: ");
    scanf("%s", colorToCheck);
    color = (resistor_band_t) "BLACK";

    printf("Color has value: %i\n", color );
   
   return 0;
}
