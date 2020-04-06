/*
FRANCE-IOI NIVEAU 2-3) exercice 1: petites fiches et gros détails
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_N 201

int main(int argc, char const *argv[])
{
    for (int i = 0; i < 6; i++)
    {
        //Déclaration des variables
        char nomAuteur[TAILLE_N];
        char titreLivre[TAILLE_N];

        //Saisie des variables
        scanf("%[^\n]\n", nomAuteur);
        scanf("%[^\n]\n", titreLivre);

        //Affichage du livre et du nom de l'auteur
        printf("%s\n", titreLivre);
        printf("%s\n", nomAuteur);
    }

    return 0;
}
