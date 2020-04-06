/*
FRANCE-IOI NIVEAU 2-3) exercice 3: une ligne sur deux
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_N 101

int main(int argc, char const *argv[])
{
    //Déclaration et saisie du nombre
    int nbLignes;
    scanf("%d\n", &nbLignes);
    for (int i = 0; i < nbLignes; i++)
    {
        //Déclaration des variables
        char ligne[TAILLE_N];

        //Saisie des variables
        scanf("%[^\n]\n", ligne);

        //Affichage de la ligne
        if (i % 2 == 0)
            printf("%s", ligne);
    }

    return 0;
}
