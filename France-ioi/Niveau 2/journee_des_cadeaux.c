/* FRANCE-IOI exercice 7) Journée des tableaux*/

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
   int nbHabitants;

   //Saisie de nbHabitants fortunes
   scanf("%d", &nbHabitants);
   int richesses[nbHabitants];
   for (int i = 0; i < nbHabitants; i++)
   {
      scanf("%d", &richesses[i]); 
   }

   //Tri de la fonction pour déterminer "le(s) riche(s) moyen(s)"
   qsort(richesses, nbHabitants, sizeof(nbHabitants), compare);

   //Détermination de la valeur recherchée
   int valeur = nbHabitants/2;;
   float val;
   if (nbHabitants%2 != 0) //Si nbHabitants impair
      {printf("%d\n", richesses[valeur] );}
   else
   {
      val = richesses[valeur-1] + richesses[valeur];
      printf("%.1lf\n", val/2);
   }

   return 0;
}

/*
Leur correction

#include <stdio.h>
#include <stdlib.h>
 
int compare (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}
 
int main()
{
   int nbPersonnes;
   scanf("%d\n",&nbPersonnes);
   int fortune[nbPersonnes];
   for (int idPersonne = 0; idPersonne < nbPersonnes; idPersonne = idPersonne + 1)
   {
      scanf("%d\n",&fortune[idPersonne]);
   }
     
   qsort( fortune, nbPersonnes, sizeof(int), compare );
     
   if ((nbPersonnes % 2) == 1)
   {
      int milieu = (nbPersonnes - 1) / 2;
      printf("%d\n", fortune[milieu] );
   }
   else
   {
      int milieu = nbPersonnes / 2;
      printf("%.1lf\n", (double)( fortune[milieu - 1] + fortune[milieu] ) / 2 );
   }
}
*/