#include <stdio.h>
#include <stdbool.h>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)
int nbJetons;
int main()
{
    //Saisie du nombre de jetons
    scanf("%d", &nbJetons);
    repeat(nbJetons)
    {
        int abscisse, ordonnee;
        //Saisie de l'abscisse et de l'ordonnée
        scanf("%d", &abscisse);
        scanf("%d", &ordonnee);
        //Qualification de chaque jeton
        if (((10 < abscisse && abscisse < 85) && (10 < ordonnee && ordonnee < 20)) || ((10 < abscisse && abscisse < 85) && (45 < ordonnee && ordonnee < 55)) ||
            ((10 < abscisse && abscisse < 25) && (10 < ordonnee && ordonnee < 55)) || ((50 < abscisse && abscisse < 85) && (10 < ordonnee && ordonnee < 55)))
        {
            printf("Dans une zone bleue\n");
        }
        else if ( ((15 < abscisse && abscisse < 45) && (60 < ordonnee && ordonnee < 70) )|| ((60 < abscisse && abscisse < 85) && (60 < ordonnee && ordonnee < 70)) )
        {
            printf("Dans une zone rouge\n");
        }
        else if (abscisse < 0 || abscisse > 90 || ordonnee < 0 || ordonnee > 70 )
        {
            printf("En dehors de la feuille\n");
        }
        else
        {
            printf("Dans une zone jaune\n");
        }
        
    }
}