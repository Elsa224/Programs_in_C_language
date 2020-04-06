#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)

double taxeActuelle, taxeNouvelle, prixTaxeActuelle;

int main()
{
    //Saisie des 3 valeurs
    scanf("%lf", &taxeActuelle);
    scanf("%lf", &taxeNouvelle);
    scanf("%lf", &prixTaxeActuelle);

    //Déclaration des variables 
    double taxeAAjouter, prixHorsTaxe, prixTaxeNouvelle;

    //Formules et calcul pour trouver la taxeAAjouter, le prixHorsTaxe et le prixTaxeNouvelle
    taxeAAjouter = prixTaxeActuelle * (taxeActuelle / (100 + taxeActuelle));
    prixHorsTaxe = prixTaxeActuelle - taxeAAjouter;
    prixTaxeNouvelle =(prixHorsTaxe + (prixHorsTaxe * (taxeNouvelle / 100))); //)));

    //Affichage du prix avec la nouvelle taxe
    printf("%.2f\n", prixTaxeNouvelle);

    return 0;
}
/*
Leur correction
#include <stdio.h>
#include <math.h>
 
int main()
{
   double taxeActuelle;
   double taxeFuture;
   double prixLegume;
   scanf("%lf%lf%lf\n", &taxeActuelle, &taxeFuture, &prixLegume);
     
   double nouveauPrix = prixLegume / ( 1 + taxeActuelle / 100) * (1 + taxeFuture / 100);
   nouveauPrix = round(nouveauPrix * 100) / 100;
   printf("%lf\n", nouveauPrix);
    
   return 0;
}*/