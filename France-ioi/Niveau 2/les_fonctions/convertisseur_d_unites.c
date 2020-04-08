/*FRANCE-IOI exercice 2-3.9) : Convertisseur d'unités */

#include <stdio.h>  //Librairies et constantes
#define INCH_TO_METER 0.3048
#define METER_TO_INCH (1 / INCH_TO_METER)
#define GRAM_TO_POUND 0.002205
#define FAHRENHEIT_TO_CELSIUS (32 + (1.8 * (double)valeurAConvertir))

int main()
{
    int nbConversions; scanf("%d", &nbConversions); //Saisie du nombre de conversions
    for (int i = 0; i < nbConversions; i++)
    {
        double valeurAConvertir; char unite;
        scanf("%lf %c", &valeurAConvertir, &unite);

        switch (unite)  //Détermination de la conversion à faire
        {
            case 'm': //Meter to inch (pied en français)
                printf("%lf p\n", valeurAConvertir * METER_TO_INCH);
                break;

            case 'g': //Gram to pound (livre en français)
                printf("%lf l\n", valeurAConvertir * GRAM_TO_POUND);
                break;

            case 'c': //Celsius to Fahrenheit
                printf("%lf f\n", FAHRENHEIT_TO_CELSIUS);
                break;
        }
    }
    return 0;
}
/*
Pas besoin de leur correction aujourd'hui !! 
Leur code fait 40 lignes alors que le mien fait 28.*/
