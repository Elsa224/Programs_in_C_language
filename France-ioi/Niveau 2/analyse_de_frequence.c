/*FRANCE-IOI exercice 2-7) : Analyse de fréquence*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_N 101

int nbLignes, nbMots, compteur, taille;
int main()
{
    //saisie du nombre de lignes et du nombre de mots
    scanf("%d\n", &nbLignes);
    scanf("%d\n", &nbMots);
    taille = nbLignes * nbMots;

    //Déclaration du tableau contenant les catégories (mots de 1 lettre, 2 lettres, ...)
    int tabMots[taille], frequence[taille];

    //Saisie des différents mots dans le tableau
    for (int i = 0; i < taille; i++)
    {
        char mot[TAILLE_N];
        scanf("%s", mot);
        tabMots[i] = strlen(mot);

        /*Initialize frequencies to -1*/
        frequence[i] = -1;
    }

    //Maintenant le tri
    int tampon;
    for (int i = 0; i < taille - 1; i++)
    {
        for (int j = 0; j < taille - (i + 1); j++)
        {
            if (tabMots[j] > tabMots[j + 1])
            {
                tampon = tabMots[j];
                tabMots[j] = tabMots[j + 1];
                tabMots[j + 1] = tampon;
            }
        }
    }

    //Détermination du nombre de mots par catégorie
    for (int j = 0; j < taille; j++)
    {
        compteur = 1;
        for (int k = j + 1; k < taille; k++)
        {
            if (tabMots[j] == tabMots[k])
            {
                compteur++;
                /* Make sure not to compteur frequency of same element again */
                frequence[k] = 0;
            }
        }

        /* If frequency of current element is not counted */
        if (frequence[j] != 0)
        {
            frequence[j] = compteur;
        }
    }

    //Affichage
    for (int j = 0; j < taille; j++)
    {
        if (frequence[j] != 0)
        {
            printf("%d : %d\n", tabMots[j], frequence[j]);
        }
    }
    return 0;
}

/*Leur correction
#include <stdio.h>
#include <string.h>
int main()
{

    int nbLignes, nbMots;
    int histogramme[101] = {0};
    scanf("%d%d\n", &nbLignes, &nbMots);
    for (int idLigne = 0; idLigne < nbLignes; idLigne = idLigne + 1)
    {
        for (int idMot = 0; idMot < nbMots; idMot = idMot + 1)
        {
            char mot[101];
            scanf("%s", mot);
            int longueur = strlen(mot);
            histogramme[longueur] = histogramme[longueur] + 1;
        }
    }
   for (int longueur = 1; longueur <= 100; longueur = longueur + 1)
   {
       if (histogramme[longueur] > 0)
        {
            printf("%d : %d\n", longueur, histogramme[longueur]);
        }
   }
}
*/