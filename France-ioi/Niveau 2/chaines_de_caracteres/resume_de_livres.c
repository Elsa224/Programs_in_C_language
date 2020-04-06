/*
FRANCE-IOI NIVEAU 2-3) exercice 4: résumés de livres
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_N 1001

int main(int argc, char const *argv[]) // int main()
{
    //Déclaration des variables
    char titreLivre[TAILLE_N];
    char resume[TAILLE_N];

    //Déclaration et saisie des nombres
    int nbLivres, longueurMin, longueurResume = strlen(resume);
    scanf("%d\n", &nbLivres);
    scanf("%d\n", &longueurMin);
    for (int i = 0; i < nbLivres; i++)
    {

        //Saisie des variables
        scanf("%[^\n]\n", titreLivre);
        scanf("%[^\n]\n", resume);

        //Affichage du titre du livre dont le résumé n'est pas long
        if (longueurResume < longueurMin)
            printf("%s\n", titreLivre);
    }
    return 0;
}

/*
Leur correction
#include <stdio.h>
#include <string.h>
int main()
{
   int nbLivres, longueurMinimale;
   char titre[1001], resume[1001];
   scanf("%d", &nbLivres);
   scanf("%d\n", &longueurMinimale);
   for (int idLivre = 0; idLivre < nbLivres; idLivre = idLivre + 1)
   {
      scanf("%[^\n]\n", titre);
      scanf("%[^\n]\n", resume);
      if (strlen(resume) < longueurMinimale)
      {
         printf("%s\n", titre);
      }
   }
}*/