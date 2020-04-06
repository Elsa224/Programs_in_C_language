/* FRANCE-IOI : exercice 2-14) : Sans espaces*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_N 101

//Déclaration des variables
int i, occurrenceDeEspace = 0;
int main()
{
    //Déclaration et saisie des variables
    char texte[TAILLE_N];
    scanf("%[^\n]\n", texte);

    //Comptage des occurences de ' '
    for (int i = 0; i < strlen(texte); i++)
    {
        if (texte[i] == ' ')
            texte[i] = '_';
    }

    //Affichage
    printf("%s\n", texte);
    return 0;
}
