/* FRANCE-IOI exercice 10) Choix des emplacements*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
   //Déclaration des variables
   int nbEmplacement, tampon1, tampon2;

   //Saisie des variables
   scanf("%d", &nbEmplacement);

   //Saisie des numéros des marchands
   int numMarchand[nbEmplacement];
   for (int i = 0; i < nbEmplacement; i++)
   {
      scanf("%d", &numMarchand[i]);
   }

   //"Saisie" des positions des emplacements
   int numEmplacement[nbEmplacement];
   for (int i = 0; i < nbEmplacement; i++)
   {
      numEmplacement[i] = i;
   }

   //Tri du tableau numEmplacement en fonction de numMarchand
   for ( int i = 0; i < nbEmplacement - 1; i++)
   {
      for ( int j = 0; j < nbEmplacement -(i+1); j++)
      {
         if (numMarchand[j] > numMarchand[j+1] )
         {
            //Tri de numMarchand
            tampon1 = numMarchand[j];
            numMarchand[j] = numMarchand[j+1];
            numMarchand[j+1] = tampon1;

            //Tri de numEmplacement
            tampon2 = numEmplacement[j];
            numEmplacement[j] = numEmplacement[j+1];
            numEmplacement[j+1] = tampon2;
         }   
      }  
   }

   //Affichage des emplacements par ordre des numéros des marchands
   for (int i = 0; i < nbEmplacement; i++)
   {
      printf("%d\n", numEmplacement[i]);
   }

   return 0;
}

/*
Leur correction
#include <stdio.h>
int main()
{
   int nbEmplacements;
   scanf("%d", &nbEmplacements);
   int emplMarchands[nbEmplacements];
   for (int i = 0; i < nbEmplacements; i = i + 1)
   {
      int numMarchand;
      scanf("%d", &numMarchand);
      emplMarchands[numMarchand] = i;
   }
   for (int j = 0; j < nbEmplacements; j = j + 1)
   {
      printf("%d\n", emplMarchands[j]);
   }
}
*/