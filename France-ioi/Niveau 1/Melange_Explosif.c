#include <stdio.h>
#include <stdbool.h>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)

int nbMesures, tempMin, tempMax, mesure;

int main()
{
    //Saisie du nombre de mesures et des températures min et max 
    scanf("%d", &nbMesures);
    scanf("%d", &tempMin);
    scanf("%d", &tempMax);
    repeat(nbMesures)
    {
        scanf("%d", &mesure);

        if (!(tempMin > mesure || mesure > tempMax))
            printf("Rien à signaler\n");
        else
            printf("Alerte !!\n");

        break;
    }
}

/*
Leur correction

int main()
{
    int nbMesures, tempMin, tempMax;
    scanf("%d%d%d", &nbMesures, &tempMin, &tempMax);
    int numMesure = 0;
    bool tempValide = true;
    while (numMesure < nbMesures && tempValide)
    {
        int temperature;
        scanf("%d", &temperature);
        tempValide = (tempMin <= temperature && temperature <= tempMax);
        if (tempValide)
            printf("Rien à signaler\n");
        else
            printf("Alerte !!\n");
        numMesure = numMesure + 1;
    }
}
Très simple en plus !!
*/