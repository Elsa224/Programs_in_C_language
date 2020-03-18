#include <stdio.h>
#include <stdbool.h>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)

int nbPierres, totalPierres = 0, hauteur = 1, total;

int main()
{
    //Saisie du nombre maximum de pierres
    scanf("%d", &nbPierres);

        //Détermination du nombre de pierres nécessaires pour la pyramide
    while (totalPierres + hauteur * hauteur <= nbPierres)
    {
        totalPierres = totalPierres + hauteur * hauteur;
        hauteur = hauteur + 1;
    }
    printf("%d\n%d\n", hauteur - 1, totalPierres);
}