/* FRANCE-IOI : exercice 2-13) : Analyse d'une langue*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_N 1001

//Déclaration des variables
int i, nbOccurrence = 0;
int main()
{
    //Déclaration et saisie des variables
    char caractere;
    int nbLignes;
    scanf("%c\n", &caractere);
    scanf("%d\n", &nbLignes);

    //Saisie des lignes du texte
    for (i = 0; i < nbLignes; i++)
    {
        char texte[TAILLE_N];
        scanf("%[^\n]\n", texte);
        int longueurMot = strlen(texte);

        //Comptage des occurences du caractère saisi
        for (int i = 0; i < longueurMot; i++)
        {
            if (texte[i] == caractere)
                nbOccurrence++;
        }
    }

    //Affichage
    printf("%d\n", nbOccurrence);
    return 0;
}