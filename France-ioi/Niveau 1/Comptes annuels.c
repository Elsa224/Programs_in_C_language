#include <stdio.h>
#include <stdbool.h>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)

int depense = 0, totalAnnuel = 0;

int main()
{

    //Calcul des dépenses annuelles
    while (depense != -1)
    {
        totalAnnuel = totalAnnuel + depense;
        scanf("%d", &depense);
    }
    printf("%d\n", totalAnnuel);
}