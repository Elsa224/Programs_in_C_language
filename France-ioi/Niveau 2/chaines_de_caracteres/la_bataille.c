/*FRANCE-IOI exercice 2-12) : La bataille*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_N 53

int main(int argc, char const *argv[])
{
    //Déclaration des variables
    char cartesJoueur1[TAILLE_N], cartesJoueur2[TAILLE_N], charGagnant;
    int longJoueur1, longJoueur2, compteur = 0;

    //Saisie des cartes des joueur 1 et 2 et calcul de la taille
    scanf("%s", cartesJoueur1);
    scanf("%s", cartesJoueur2);
    longJoueur1 = strlen(cartesJoueur1);
    longJoueur2 = strlen(cartesJoueur2);

    //D'abord on va déterminer si l'un des tableaux a une taille différente
    if (longJoueur1 > longJoueur2)
    {
        charGagnant = '1';
        for (int i = 0; i < longJoueur2; i++)
        {
            if (cartesJoueur2[i] == cartesJoueur1[i])
                compteur++;
            else
            {
                if ((int)cartesJoueur1[i] < (int)cartesJoueur2[i])
                {
                    charGagnant = '1';
                    break;
                }
                else if ((int)cartesJoueur1[i] > (int)cartesJoueur2[i])
                {
                    charGagnant = '2';
                    break;
                }
            }
        }
        printf("%c\n%d\n", charGagnant, compteur);
    }
    else if (longJoueur1 < longJoueur2)
    {
        charGagnant = '2';
        for (int i = 0; i < longJoueur1; i++)
        {
            if (cartesJoueur1[i] == cartesJoueur2[i])
                compteur++;
            else
            {
                if ((int)cartesJoueur1[i] < (int)cartesJoueur2[i])
                {
                    charGagnant = '1';
                    break;
                }
                else if ((int)cartesJoueur1[i] > (int)cartesJoueur2[i])
                {
                    charGagnant = '2';
                    break;
                }
            }
        }
        printf("%c\n%d\n", charGagnant, compteur);
    }
    else //longT1 = longT2
    {
        compteur = 0;
        for (int i = 0; i < longJoueur1; i++)
        {
            if ((int)cartesJoueur1[i] != (int)cartesJoueur2[i])
            {
                if ((int)cartesJoueur1[i] < (int)cartesJoueur2[i])
                {
                    charGagnant = '1';
                    break;
                }
                else if ((int)cartesJoueur1[i] > (int)cartesJoueur2[i])
                {
                    charGagnant = '2';
                    break;
                }
            }
            else if ((int)cartesJoueur1[i] == (int)cartesJoueur2[i])
            {
                charGagnant = '=';
                compteur++;
            }
        }
        printf("%c\n%d\n", charGagnant, compteur);
    }
    return 0;
}

/*
Leur correction
#include <stdio.h>
#include <string.h>

int main()
{
    char main1[53];
    char main2[53];
    scanf("%s %s",main1,main2);

    int long1 = strlen(main1);
    int long2 = strlen(main2);
    int nbEgalites = 0;

    //Détermination du nombre d'égalités
    while (nbEgalites < long1 && nbEgalites < long2 && main1[nbEgalites] == main2[nbEgalites])
        nbEgalites++;

    //Différentes sorties du jeu
        //Si il y a égalité
    if (nbEgalites == long1 && nbEgalites == long2)
        printf("=");

        //Si le joueur 1 gagne
    else if (nbEgalites == long2 || (nbEgalites < long1 && main1[nbEgalites] < main2[nbEgalites]))
        printf("1");

        //Si le joueur 2 gagne
    else
        printf("2");

    //Affichage
    printf("\n%d\n", nbEgalites);
    return 0;
}
*/