#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)

double quantiteCiment;
int quantiteTotal = 0, prixTotal = 0;

int main()
{
    //Saisie de la quantité de ciment nécessaire
    scanf("%lf", &quantiteCiment);

    //Calcul et affichage du coût total du ciment
    while (quantiteTotal < quantiteCiment)
    {
        prixTotal = prixTotal + 45;
        quantiteTotal = quantiteTotal + 60;
    }
    printf("%d\n", prixTotal);

    return 0;
}

/*
Leur correction

#include <stdio.h>
#include <math.h>
int main()
{
   double quantiteCiment;
   scanf("%lf\n", &quantiteCiment);
   int nbSacs = ceil(quantiteCiment / 60);
   int prix = nbSacs * 45;
   printf("%d\n",prix);
   
   return 0;
}
*/