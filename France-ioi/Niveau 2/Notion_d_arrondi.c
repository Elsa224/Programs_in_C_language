#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)

int nbHabitants;
double croissance, totalNewHabitants, pourcentageHab;

int main()
{
   //Saisie de la population actuelle et de la croissance prévue
   scanf("%d", &nbHabitants);
   scanf("%lf", &croissance);

    //Calcul du pourcentage de la nouvelle population
   pourcentageHab = nbHabitants * (croissance / 100);
   totalNewHabitants = nbHabitants + pourcentageHab;

   //Arrondià l'entier inférieur
   totalNewHabitants = floor(totalNewHabitants); //floor = sol

    //Affichage de la nouvelle population
    printf("%d\n", ((int)(totalNewHabitants)));

    return 0;
}

/*Arrondi à l'entier supérieur
totalNewHabitants = ceil(totalNewHabitants); // ceiling = plafond */