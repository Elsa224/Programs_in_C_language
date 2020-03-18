#include <stdio.h>
#define repeat(nb) for(int _loop = 1, _max = (nb) ; _loop <= _max ; _loop++)
int numMois;

int main()
{
    //Saisie du numéro du mois
    scanf("%d", &numMois);

    //Détermination du nombre de jours dans le mois
    if (numMois == 11)
        printf("%d\n", 29);
    else
    {
        if ((1 <= numMois && numMois <= 3) || (7 <= numMois && numMois <= 9))
            printf("%d\n", 30);
        else
            printf("%d\n", 31);
    }
}