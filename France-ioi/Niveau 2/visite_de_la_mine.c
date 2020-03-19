/*FRANCE IOI: Exercice 6) Visite de la mine

   Il existe 5 types de déplacements, représentés par 5 entiers différents : 
   aller à gauche (1) 
   aller à droite (2)
   aller tout droit (3)
   monter (4)
   descendre (5)
*/

#include <stdio.h>
#define TAILLE_N 1000

int main(int argc, char const *argv[])
{
   //Déclaration des variables
   int nbDeplacements;
   int typeDeplacement[TAILLE_N];
    
   //Saisie des variables
   do
    {scanf("%d", &nbDeplacements);} 
    while (nbDeplacements > TAILLE_N || nbDeplacements <= 0);

    //Saisie de nbDeplacements entiers
    for (int i = 0; i < nbDeplacements; i++)
    {
      scanf("%d", &typeDeplacement[i]);
    }

    //Parcours du tableau et afficher l'inverse
   for (int i = nbDeplacements - 1; i >= 0; i--)
   {
      switch (typeDeplacement[i])
      {
         case 1:
            printf("2\n");
         break;
         case 2:
            printf("1\n");
         break;
         case 3:
            printf("3\n");
         break;
         case 4:
            printf("5\n");
         break;
         case 5:
            printf("4\n");
         break;

         default:
         break;
      }
   }
   
   return 0;
}

/*
Leur correction
#include <stdio.h>
 
int main()
{
   int deplacementInverse[6] = {0, 2, 1, 3, 5, 4};
 
   int nbDeplacements;
   scanf("%d\n",&nbDeplacements);
   int chemin[nbDeplacements];
     
   for (int numero = 0; numero < nbDeplacements; numero = numero + 1)
   {
      scanf("%d\n",&chemin[numero]);
   }
     
   for (int numero = nbDeplacements-1; numero >= 0; numero = numero - 1)
   {
      int deplacement = chemin[numero];
      printf("%d\n",deplacementInverse[deplacement]);
   }
}

*/
