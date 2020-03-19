#include <stdio.h>
#define repeat(nb) for(int _loop = 1, _max = (nb) ; _loop <= _max ; _loop++)
int nbMarchands, prixMin = 1000 * 1000, posMarchand = 0, posFin;

int main()
{
   //Saisie du nombre de marchands
   scanf("%d", &nbMarchands);
   repeat(nbMarchands)
   {
      int prixMarchand;
      scanf("%d", &prixMarchand);
      posMarchand = posMarchand + 1;

      //Plus petit prix des galettes et sa position
      if(prixMarchand <= prixMin)
      {
          prixMin = prixMarchand;
          posFin = posMarchand;
      }
   }
   printf("%d", posFin);
}
