/*FRANCE-IOI exercice 2-9) : Écriture en miroir*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_N 1001

int main(int argc, char const *argv[])
{
    //Déclaration des variables
    int nbLignes, longueur, i, j;

    //Saisie du nombre de lignes, du texte et calcul de la longueur de texte
    scanf("%d\n", &nbLignes);
    for (i = 0; i < nbLignes; i++)
    {
        char texte[TAILLE_N];
        scanf("%[^\n]\n", texte);
        longueur = strlen(texte);

        //Affichage du titre caractère par caractère
        for (j = longueur - 1; j >= 0; j--)
        {
            printf("%c", texte[j]);
        }
        printf("\n");
    }
    return 0;
}