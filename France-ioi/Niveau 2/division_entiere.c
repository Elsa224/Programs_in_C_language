#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)

int sommeArgent, prixLivre, totalLivres;

int main()
{
   //Saisie de la somme d'argent et du prix d'un livre
   scanf("%d", &sommeArgent);
   scanf("%d", &prixLivre);

   //Calcul et affichage du total de livres
   totalLivres = sommeArgent / prixLivre;
   printf("%d\n", totalLivres);

    return 0;
}
