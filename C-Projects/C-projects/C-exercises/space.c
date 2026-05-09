#include <stdio.h>
#include <stdlib.h>

int main()
{
    double MacWeight;
    int planet;

    

    printf("Enter your weight and planet: ");
    scanf("%lf", &MacWeight);
    printf("Number of the planet: ");
    scanf("%i", &planet);

    switch (planet)
    {
    case 1:
        printf("Your weight is: %lf", MacWeight * 0.38);
        break;
    case 2:
        printf("Your weight is: %lf", MacWeight * 0.91);
        break;
    case 3:
        printf("Your weight is: %lf", MacWeight * 0.38);
        break;
    case 4:
      printf("Your weight is: %lf", MacWeight*2.34);
      break;
    case 5:
      printf("Your weight is: %lf", MacWeight*1.06);
      break;
    case 6:
      printf("Your weight is: %lf", MacWeight*0.92);
      break;
    case 7:
      printf("Your weight is: %lf", MacWeight*1.19);
      break;
    default:
      printf("Invalid values");
      break;
    }
}