#include <stdio.h>
#include <stdbool.h>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)

int nbHabitants, totalMalades = 1, jourJ = 1;

int main()
{
    //Saisie du nombre d'habitants dans la ville
    scanf("%d", &nbHabitants);

    //Détermination du jour où toute la population serait malade
    while (totalMalades < nbHabitants)
    {
        totalMalades = totalMalades + totalMalades * 2; //ce qui fait totalMalades * 3
        jourJ = jourJ + 1;
    }
    
    printf("%d\n", jourJ);
}