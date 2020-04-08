/*FRANCE-IOI exercice 2-3.8) : Formes creuses

Perso, j'ai utilisé les fonctions qu'ils ont données dans le cours "struturer son programme"
donc j'ai compris maid bon... */

#include <stdio.h>

void afficheLigne(int nbColonnes, char motif)
{
    for (int i = 0; i < nbColonnes; i++)
    {
        printf("%c", motif);
    }
}

void afficheTriangle(int nbLignes, char motif)
{
    int j = 0;
    afficheLigne(1, motif);
    printf("\n");
    afficheLigne(2, motif);
    printf("\n");
    if (nbLignes != 2)
    {
        for (int i = 3; i < nbLignes; i++) //Le vide dans le triangle
        {
            afficheLigne(1, motif);
            afficheLigne(++j, ' ');
            afficheLigne(1, motif);
            printf("\n");
        }
        afficheLigne(nbLignes, motif);
        printf("\n");
    }
}

void afficheRectangle(int nbLignes, int nbColonnes, char motif)
{
    if (nbColonnes == 1)
    {
        for (int i = 0; i < nbLignes; i++)
        {
            afficheLigne(nbColonnes, motif);
            printf("\n");
        }
    }
    else
    {
        afficheLigne(nbColonnes, motif);
        printf("\n");
        for (int i = 1; i < nbLignes - 1; i++) //Le vide dans le rectangle
        {
            afficheLigne(1, motif);
            afficheLigne(nbColonnes - 2, ' ');
            afficheLigne(1, motif);
            printf("\n");
        }
        afficheLigne(nbColonnes, motif);
        printf("\n");
    }
}

int main()
{
    int nbColonnes, nbLignes;
    scanf("%d", &nbColonnes);
    afficheLigne(nbColonnes, 'X');
    printf("\n");
    printf("\n");
    scanf("%d%d", &nbLignes, &nbColonnes);
    afficheRectangle(nbLignes, nbColonnes, '#');
    printf("\n");
    scanf("%d", &nbLignes);
    afficheTriangle(nbLignes, '@');
}

/* Leur correction
#include <stdio.h>

void ligne(int longueur, char motif)
{
    for (int iCol = 1; iCol <= longueur; iCol = iCol + 1)
    {
        printf("%c", motif);
    }
    printf("\n");
}
void ligneCreuse(int longueur, char motif)
{
    if (longueur > 1)
    {
        printf("%c", motif);
        for (int iCol = 2; iCol < longueur; iCol = iCol + 1)
        {
            printf(" ");
        }
    }
    printf("%c\n", motif);
}
void rectangle(int hauteur, int longueur, char motif)
{
    if (hauteur > 1)
    {
        ligne(longueur, motif);
        for (int iLigne = 2; iLigne < hauteur; iLigne = iLigne + 1)
        {
            ligneCreuse(longueur, motif);
        }
    }
    ligne(longueur, motif);
}
void triangle(int hauteur, char motif)
{
    for (int iLigne = 1; iLigne < hauteur; iLigne = iLigne + 1)
    {
        ligneCreuse(iLigne, motif);
    }
    ligne(hauteur, motif);
}
int main()
{
    int longueurLigne;
    scanf("%d", &longueurLigne);
    ligne(longueurLigne, 'X');
    printf("\n");
    int hauteurRectangle, largeurRectangle;
    scanf("%d%d", &hauteurRectangle, &largeurRectangle);
    rectangle(hauteurRectangle, largeurRectangle, '#');
    printf("\n");
    int hauteurTriangle;
    scanf("%d", &hauteurTriangle);
    triangle(hauteurTriangle, '@');
} */
