/* FRANCE-IOI exercice 9) Banquet municipal*/

#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[])
{
   //Déclaration des variables
   int nbPosition, nbChangement, tampon;

   //Saisie des variables
   scanf("%d%d", &nbPosition, &nbChangement);
   
   //Saisie des nbPosition personnes
   int numPersonne[nbPosition];
   for (int i = 0; i < nbPosition; i++)
   {
      scanf("%d", &numPersonne[i]);
   }

   //Saisie des changements et échange
   for (int i = 0; i < nbChangement; i++)
   {
      int position1, position2;
      scanf("%d%d", &position1, &position2);
      tampon = numPersonne[position1];
      numPersonne[position1] = numPersonne[position2];
      numPersonne[position2] = tampon;
   }

   //Affichage final
   for (int i = 0; i < nbPosition; i++)
   {
      printf("%d\n", numPersonne[i]);
   }
   
   return 0;
}
/*
Leur correction est pareil que mon code !
*/