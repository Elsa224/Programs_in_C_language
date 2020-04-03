/*FRANCE-IOI exercice 2-5) : Lire ou ne pas lire, telle est la question*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_N 1001

int plusGrand = 0, nbLivres;

int main()
{
    //saisie du nombre de livres
    scanf("%d\n", &nbLivres);

    //Détermination de la taille la plus grande
    for (int i = 0; i < nbLivres; i++)
    {
        char titreLivre[TAILLE_N];
        scanf("%[^\n]\n", titreLivre);
        if (plusGrand < strlen(titreLivre))
        {
            plusGrand = strlen(titreLivre);
            printf("%s", titreLivre);
            printf("\n");
        }
    }
    return 0;
}