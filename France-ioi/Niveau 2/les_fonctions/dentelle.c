/* FRANCE-IOI : exercice 2.3-3) : Dentelles*/

#include <stdio.h>
#include <stdlib.h>

//Procédure de saisie de la "dentelle"
void dentelle(char caractere, int longueur)
{
    for (int i = 0; i < longueur; i++)
    {
        printf("%c", caractere);
    }
    printf("\n");
}

int main()
{
    int longueur;
    scanf("%d\n", &longueur);
    dentelle('X', longueur);
    dentelle('#', longueur);
    dentelle('i', longueur);
    return 0;
}