
/*FRANCE-IOI exercice 2-8) : Impression d'étiquettes*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_N 51

int main(int argc, char const *argv[])
{
    //Déclaration des variables
    int longueur;
    char titreLivre[TAILLE_N];

    //Saisie du titreLivre et calcul de la longueur de titreLivre
    scanf("%[^\n]", titreLivre);
    longueur = strlen(titreLivre);

    //Affichage du titre caractère par caractère
    for (int i = 0; i < longueur; i++)
    {
        printf("%c\n", titreLivre[i]);
    }
    return 0;
}