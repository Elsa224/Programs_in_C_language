/*FRANCE-IOI exercice 2.3-4) : Motif rectangulaire*/
#include <stdio.h>

void motif(int ligne, int colonne, char caractere)
{ //Procédure de saisie du motif
    for (int i = 0; i < ligne; i++)
    {
        for (int j = 0; j < colonne; j++)
            printf("%c", caractere);
        printf("\n");
    }
}

main()
{
    int row, column;
    char character; //Déclaration et saisie des variables
    scanf("%d%d %c", &row, &column, &character);
    motif(row, column, character); //Procédure d'affichage du motif
}