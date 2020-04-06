
/*FRANCE IOI : Découverte des tableaux, exercice 3) grand inventaire*/

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int nbOperations, somme = 0;
    int quantiteFinale[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

    //Saisie de nbOperations
    scanf("%d", &nbOperations);

    //Déclaration des tableaux
    int numIngredient[nbOperations]; 
    int quantiteIngredient[nbOperations]; 

    //Saisie des numéros et quantités d'ingrédients 
    for (int i = 0; i < nbOperations; i++)
    {
        scanf("%d", &numIngredient[i]);
        scanf("%d", &quantiteIngredient[i]);
    }

    //Calcul des quantités 
    for (int i = 0; i < nbOperations; i++)
    {
        if (numIngredient[i] == 1)
        {
            somme = somme + quantiteIngredient[i];
            quantiteFinale[0] = somme;
        }
    }
    somme = 0;
    for (int i = 0; i < nbOperations; i++)
    {
        if (numIngredient[i] == 2)
        {
            somme = somme + quantiteIngredient[i];
            quantiteFinale[1] = somme;
        }
    }
    somme = 0;
    for (int i = 0; i < nbOperations; i++)
    {
        if (numIngredient[i] == 3)
        {
            somme = somme + quantiteIngredient[i];
            quantiteFinale[2] = somme;
        }
    }
    somme = 0;
    for (int i = 0; i < nbOperations; i++)
    {
        if (numIngredient[i] == 4)
        {
            somme = somme + quantiteIngredient[i];
            quantiteFinale[3] = somme;
        }
    }
    somme = 0;
    for (int i = 0; i < nbOperations; i++)
    {
        if (numIngredient[i] == 5)
        {
            somme = somme + quantiteIngredient[i];
            quantiteFinale[4] = somme;
        }
    }
    somme = 0;
    for (int i = 0; i < nbOperations; i++)
    {
        if (numIngredient[i] == 6)
        {
            somme = somme + quantiteIngredient[i];
            quantiteFinale[5] = somme;
        }
    }
    somme = 0;
    for (int i = 0; i < nbOperations; i++)
    {
        if (numIngredient[i] == 7)
        {
            somme = somme + quantiteIngredient[i];
            quantiteFinale[6] = somme;
        }
        
    }
    somme = 0;
    for (int i = 0; i < nbOperations; i++)
    {
        if (numIngredient[i] == 8)
        {
            somme = somme + quantiteIngredient[i];
            quantiteFinale[7] = somme;
        }
    }
    somme = 0;
    for (int i = 0; i < nbOperations; i++)
    {
        if (numIngredient[i] == 9)
        {
            somme = somme + quantiteIngredient[i];
            quantiteFinale[8] = somme;
        }  
    }
    somme = 0;
    for (int i = 0; i < nbOperations; i++)
    {
        if (numIngredient[i] == 10)
        {
            somme = somme + quantiteIngredient[i];
            quantiteFinale[9] = somme;
        }
    }
    somme = 0;

    //Affichage
    for (int i = 0; i < 10; i++)
    {
        printf("%d\n", quantiteFinale[i]);
    }
    
    
    printf("\n");
    return 0;
}/*J'ai utilisé plein de for et de if parce que j'étais desespérée :( :( :( Mais... ça mmaarcchheee !!!*/

/*Leur correction

#include <stdio.h>
 
int main()
{
   int quantite[11] = {0};
   int nbLignes;
   scanf("%d\n",&nbLignes);
   
   for (int idLigne = 0; idLigne < nbLignes; idLigne = idLigne + 1)
   {
      int numeroProduit;
      int variation;
      scanf("%d%d\n", &numeroProduit, &variation);
      quantite[numeroProduit] = quantite[numeroProduit] + variation;
   }
   for (int numeroProduit = 1; numeroProduit <= 10; numeroProduit = numeroProduit + 1)
   {
      printf("%d\n",quantite[numeroProduit]);
   }
}
*/