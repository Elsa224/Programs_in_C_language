/*FRANCE-IOI exercice 2-7) : Fiches d'inscription*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_N 101

int nbPersonnes;
int main()
{
    //saisie du nombre de personnes
    scanf("%d\n", &nbPersonnes);

    //Saisie des oms et prénoms et affichage dans le bon ordre
    for (int i = 0; i < nbPersonnes; i++)
    {
        char nom[TAILLE_N];
        char preNom[TAILLE_N];
        scanf("%s", preNom);
        scanf("%s", nom);
        printf("%s %s", nom, preNom);
        printf("\n");
    }
    return 0;
}