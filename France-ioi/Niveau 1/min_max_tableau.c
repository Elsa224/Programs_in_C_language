#include <stdio.h>
#define repeat(nb) for(int _loop = 1, _max = (nb) ; _loop <= _max ; _loop++)
int main()
{
   int nbMaisons, minX, maxX, minY, maxY, i;

   //Saisie du nombre de maisons
   scanf("%d", &nbMaisons);

    int tabX[nbMaisons], tabY[nbMaisons];

   //Coordonnées du périmètre minimum pour englober toutes les maisons

    //Saisie des données de tabX et tabY
   for ( i = 0; i < nbMaisons; i++ )
      scanf("%d %d", &tabX[i], &tabY[i]); 
   
   //Déterminer minX, maxX, minY, maxY
  minX = tabX[0];
  for ( i = 0; i < nbMaisons; i++ )
  {
    if( minX > tabX[i])
      minX = tabX[i];
  }
  maxX = tabX[0];
  for ( i = 0; i < nbMaisons; i++ )
  {
    if( maxX < tabX[i])
      maxX = tabX[i];
  } 

  minY = tabY[0];
  for ( i = 0; i < nbMaisons; i++ )
  {
    if( minY > tabY[i])
      minY = tabY[i];
  }
  maxY = tabY[0];
  for ( i = 0; i < nbMaisons; i++ )
  {
    if( maxY < tabY[i])
      maxY = tabY[i];
  } 

  printf("%d %d\n\n", maxX, maxY);
  printf("%d %d\n\n", minX, minY);

  //Calcul et affichage du périmètre
  int longueur, largeur;
  longueur = maxY - minY;
  largeur = maxX - minX;
  printf("%d\n", 2 * (longueur + largeur) );

    return 0;
}


/*Leur correction

#include <stdio.h>
#define repeat(nb) for(int _loop = 1, _max = (nb) ; _loop <= _max ; _loop++)
int main()
{
   int nbMaisons;
   scanf("%d", &nbMaisons);
    
   int xMin = 1000 * 1000, xMax = 0, yMin = 1000 * 1000, yMax = 0;
   repeat(nbMaisons)
   {
      int posX, posY;
      scanf("%d%d", &posX, &posY);
      if(posX < xMin)
      {
         xMin = posX;
      }
      if(posX > xMax)
      {
         xMax = posX;
      }
      if(posY < yMin)
      {
         yMin = posY;    
      }
      if(posY > yMax)
      {
         yMax = posY;
      }
   }      
   int largeur = xMax - xMin, hauteur = yMax - yMin;
   int perimetre = 2 * (largeur + hauteur);
   printf("%d", perimetre);
}
*/
