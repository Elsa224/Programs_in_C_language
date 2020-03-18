/* FRANCE-IOI exercice 8) Course à trois jambes*/

#include <stdio.h>
#include <stdlib.h>

//Fonction déjà fourni de tri
int compare (const void* a, const void* b)
{
   return ( *(int*)(a) - *(int*)(b) );
}

int main(int argc, char const *argv[])
{
   //Déclaration des variables
   int nbParticipants;

   //Saisie de nbParticipants entiers
   scanf("%d", &nbParticipants);
   int valeurLibre[nbParticipants];
   for (int i = 0; i < nbParticipants; i++)
   {
      scanf("%d", &valeurLibre[i]); 
   }

   //Tri du tableau
   qsort(valeurLibre, nbParticipants, sizeof(nbParticipants), compare);

   //Affichage des équipes
   for (int i = 0; i < nbParticipants/2; i++)
   {
      printf("%d %d\n", valeurLibre[i], valeurLibre[nbParticipants-i-1]);
   }
   
   return 0;
}
/*
Leur correction est pareil que mon code !
*/