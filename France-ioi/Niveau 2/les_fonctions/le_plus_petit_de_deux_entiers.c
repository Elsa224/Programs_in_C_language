/*FRANCE-IOI exercice 2-3.5) : le plus petit de deux entiers*/
#include <stdio.h>

main()
{
    int tableau[10];

    for (int i = 0; i < 10; i++) // Stocker le nombre saisi par l'utilisateur
        scanf("%d", &tableau[i]);

    for (int i = 1; i < 10; i++) // Boucle pour stocker le min dans tab[0]
    {
        if (tableau[0] > tableau[i])
            tableau[0] = tableau[i];
    }
    printf("%d\n", tableau[0]);
}

/*
Leur correction
#include <stdio.h>

int minimum(int num1, int num2)     //Fonction pour déterminer le minimum
{
   if (num1 < num2)
      return num1;  
   return num2;
}

int main()
{
   int nombreMin;
   scanf("%d", &nombreMin);
   
   for (int i = 1; i < 10; i++)
   {
      int nombre;
      scanf("%d", &nombre);
      nombreMin = minimum(nombreMin, nombre);
   }
   printf("%d\n", nombreMin);
   return 0;
}
*/