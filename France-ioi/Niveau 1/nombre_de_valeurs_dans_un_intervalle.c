#include <stdio.h>
#define repeat(nb) for(int _loop = 1, _max = (nb) ; _loop <= _max ; _loop++)
int rectMinX, rectMaxX, rectMinY, rectMaxY, nbMaisons, nombreTotal = 0;

int main()
{
    //Saisie des abscisses et ordonnées du rectangle
    scanf("%d%d", &rectMinX, &rectMaxX);
    scanf("%d%d", &rectMinY, &rectMaxY);

    //Saisie du nombre de maisons
    scanf("%d", &nbMaisons);

    //Saisie des abscisses et ordonnées de chaque maison
    repeat(nbMaisons)
    {
        int maisonX, maisonY;
        scanf("%d%d", &maisonX, &maisonY);

        //Comparaison entre les coordonnées des maisons et du rectangle
        if ( ( (rectMinX <= maisonX) && (maisonX <= rectMaxX) ) && ( (rectMinY <= maisonY) && (maisonY <= rectMaxY) ) )
            nombreTotal = nombreTotal + 1;  
    }
      printf("%d", nombreTotal);
}