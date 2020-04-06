/*FRANCE IOI: Exercice 5) Répartition du poids*/

#include <stdio.h>
#define TAILLE_N 3000

int main(int argc, char const *argv[])
{
   //Déclaration des variables
   int nbCharettes;
   double poidsCharettes[TAILLE_N], poidsTotal  = 0, poidsMoyen, poidsX[TAILLE_N];
    
   //Saisie des variables
   do
    {scanf("%d", &nbCharettes);} 
    while (nbCharettes > 3000 || nbCharettes <= 0);

    //Saisie de nbCharettes entiers
    for (int i = 0; i < nbCharettes; i++)
    {
        scanf("%f", &poidsCharettes[i]);
        poidsTotal = poidsTotal + poidsCharettes[i];
    }

   //Calcul du poids que toutes les charettes doivent transporter
   poidsMoyen = poidsTotal / (double) nbCharettes;

   //Calcul du poids manquant de chaque charette à déterminer
   for (int i = 0; i < nbCharettes; i++)
   {
      poidsX[i] = poidsMoyen - poidsCharettes[i];
   }

   //Affichage des poids à ajouter ou retirer
   for (int i = 0; i < nbCharettes; i++)
   {
      printf("%f\n", poidsX[i]);
   }

   return 0;
}

/*
Leur correction
#include <stdio.h>
 
int main()
{
   int nbCharrettes;
   scanf("%d\n",&nbCharrettes);
   double poids[nbCharrettes];
     
   double poidsTotal = 0.0;
   
   for (int numero = 0; numero < nbCharrettes; numero = numero + 1)
   {
      scanf("%lf\n",&poids[numero]);
      poidsTotal = poidsTotal + poids[numero];
   }
     
   double poidsMoyen = poidsTotal / nbCharrettes;
     
   for (int numero = 0; numero < nbCharrettes; numero = numero + 1)  
   {
      printf("%lf\n",poidsMoyen - poids[numero]);
   }
}
*/
