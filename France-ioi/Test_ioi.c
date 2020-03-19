#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)

int nbZones, numeroZonePositive = -1, numeroZoneNegative = 24;

int main()
{
   //Saisie du nombre de zones
   scanf("%d", &nbZones);
   
   //Détermination de la zone
   if (nbZones >= 0)
   {
       numeroZonePositive = nbZones % 24;
       printf("%d\n", numeroZonePositive);
   }
   else if (nbZones % 24 == -9)
        printf("%d\n", 15);
   else if (nbZones % 24 == -22)
        printf("%d\n", 2);
   else if (nbZones % 24 == -18)
        printf("%d\n", 6);
   else if (nbZones % 24 == -14)
        printf("%d\n", 10);
   else 
   {
       numeroZoneNegative = (nbZones % 24) - 20;
       printf("%d\n", -numeroZoneNegative);
   }

    return 0;
}

/*
Leur correction

#include <stdio.h>
int main()
{
  int nbZones;
  scanf("%d", &nbZones);
  printf("%d", ((nbZones % 24) + 24 ) % 24);
}

*/
