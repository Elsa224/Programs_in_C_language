#include <stdio.h>
#define repeat(nb) for(int _loop = 1, _max = (nb) ; _loop <= _max ; _loop++)
int debutService1, finService1, debutService2, finService2;

int main()
{
    //Saisie des heures de service des deux soldats
    scanf("%d%d", &debutService1, &finService1);
    scanf("%d%d", &debutService2, &finService2);

    //Détermination du nombre de jours dans le mois
    if ( finService2 < debutService1 || finService1 < debutService2 )
        printf("Pas amis\n");
    else
        printf("Amis\n");
}

/*
Leur correction

#include <stdio.h>
int main()
{
    int dateDebutPremier, dateFinPremier, dateDebutSecond, dateFinSecond;
    scanf("%d", &dateDebutPremier);
    scanf("%d", &dateFinPremier);
    scanf("%d", &dateDebutSecond);
    scanf("%d", &dateFinSecond);

    if ((dateFinSecond < dateDebutPremier) || (dateFinPremier < dateDebutSecond))
    {
        printf("Pas amis");
    }
    else
    {
        printf("Amis");
    }
}*/