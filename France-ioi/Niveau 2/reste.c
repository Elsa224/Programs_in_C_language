#include <stdio.h>
#include <stdbool.h>
#include <math.h>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)

int nbPersonnes, nbFruits;

int main()
{
   //Saisie du nombre de personnes et du nombre de fruits
   scanf("%d", &nbPersonnes);
   scanf("%d", &nbFruits);

   //Multiple ou pas ?
   if (nbFruits % nbPersonnes == 0)
        printf("oui\n");
    else
        printf("non\n");
    return 0;
}
