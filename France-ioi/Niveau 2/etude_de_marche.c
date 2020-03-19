/*FRANCE IOI: Exercice 4) Etude de marché*/

#include <stdio.h>
#define TAILLE_N 1000

int main(int argc, char const *argv[])
{
    //Déclaration des variables
    int nbProduits;
    int nbPersonnes;
    int nbProduitPrefere[TAILLE_N];


    //Saisie des variables
    scanf("%d", &nbProduits);
    for (int i = 0; i < nbProduits; i++)
        {nbProduitPrefere[i] = 0;}
    
    do
    {
        scanf("%d", &nbPersonnes);
    } 
    while (nbPersonnes > 1000 || nbPersonnes <= 0);

    //Saisie de nbPersonnes entiers
    for (int i = 0; i < nbPersonnes; i++)
    {
        int numProduit;
        scanf("%d", &numProduit);
        nbProduitPrefere[numProduit] = nbProduitPrefere[numProduit] + 1; 
    }

    //Affichage
    for (int i = 0; i < nbProduits; i++)
    {
        printf("%d\n", nbProduitPrefere[i]);
    }
    
    return 0;
}

/*
Leur correction

#include <stdio.h>
 
int main()
{
   int nbProduits;
   scanf("%d\n",&nbProduits);
    
   int nbSouhaits[nbProduits];
   for (int numeroProduit = 0; numeroProduit < nbProduits; numeroProduit = numeroProduit + 1)
   {
      nbSouhaits[numeroProduit] = 0;
   }
    
   int nbPersonnes;
   scanf("%d\n",&nbPersonnes);
   for (int idPersonne = 0; idPersonne < nbPersonnes; idPersonne = idPersonne + 1)
   {
      int numeroProduit;
      scanf("%d\n",&numeroProduit);
      nbSouhaits[numeroProduit] = nbSouhaits[numeroProduit] + 1;
   }
     
   for (int numeroProduit = 0; numeroProduit < nbProduits; numeroProduit = numeroProduit + 1)
   {
      printf("%d\n",nbSouhaits[numeroProduit]);
   }
}
*/
