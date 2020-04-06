/*FRANCE-IOI exercice 2-10) : Inscription d'étudiants*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_N 51

int main(int argc, char const *argv[])
{
    //Déclaration des variables
    char nomEtudiant[TAILLE_N];

    //Saisie du nom et détermination de la personne chargé de l'inscription
    scanf("%s", nomEtudiant);
    if (nomEtudiant[0] <= 'F')
    {
        printf("1\n");
    }
    else if (nomEtudiant[0] <= 'P')
    {
        printf("2\n");
    }
    else
    {
        printf("3\n");
    }
    return 0;
}