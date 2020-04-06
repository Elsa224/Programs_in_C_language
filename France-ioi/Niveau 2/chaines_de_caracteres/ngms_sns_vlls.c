/*FRANCE-IOI exercice 2-11) : ngms sns vlls*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_N 1001

int main(int argc, char const *argv[])
{
    //Déclaration des variables
    char titreLivre[TAILLE_N], nomAuteur[TAILLE_N], destTitre[TAILLE_N], destAuteur[TAILLE_N];
    int longueurAuteur, longueurTitre, j = 0, k = 0;

    //Saisie du titre du livre, du nom de l'auteur
    scanf("%[^\n]\n", titreLivre);
    scanf("%[^\n]\n", nomAuteur);
    longueurTitre = strlen(titreLivre);
    longueurAuteur = strlen(nomAuteur);

    //Identifier les consonnes sans espace
    for (int i = 0; i < longueurTitre; i++)
    {
        if (titreLivre[i] != ' ' && titreLivre[i] != 'A' && titreLivre[i] != 'E' && titreLivre[i] != 'I' && titreLivre[i] != 'O' && titreLivre[i] != 'U' && titreLivre[i] != 'Y')
        {
            destTitre[j] = titreLivre[i];
            j++;
        }
    }

    for (int l = 0; l < longueurAuteur; l++)
    {
        if (nomAuteur[l] != ' ' && nomAuteur[l] != 'A' && nomAuteur[l] != 'E' && nomAuteur[l] != 'I' && nomAuteur[l] != 'O' && nomAuteur[l] != 'U' && nomAuteur[l] != 'Y')
        {
            destAuteur[k] = nomAuteur[l];
            k++;
        }
    }

    //Affichage des titres sans voyelle ni espace
    printf("%s\n", destTitre);
    printf("%s\n", destAuteur);

    return 0;
}

/*

Leur correction
#include <stdio.h>
#include <string.h>
int main()
{
   for (int idLigne = 0; idLigne < 2; idLigne = idLigne + 1)
    {
       char ligne[101];
       scanf("%[^\n]\n", ligne);
       int longueurLigne = strlen(ligne);
       for (int idLettre = 0; idLettre < longueurLigne; idLettre = idLettre + 1)
    	{

            char car = ligne[idLettre];
            if (car != ' ' && car != 'A' && car != 'E' && car != 'I' &&
            car != 'O' && car != 'U' && car != 'Y')
            {
                printf("%c", car);
            }
        }
      	printf("\n");
   }
}*/