/*FRANCE-IOI exercice 2-3.6) : Phénomène numérique*/
#include <stdio.h>

int termeSuivant(int terme) //Fonction pour déterminer le termeSuivant
{
    int num1 = terme;
    if (num1 == 1)
        return num1;

    else if (num1 % 2 == 0) //si le terme est pair
        return num1 / 2;

    return (num1 * 3) + 1;  //Sinon
}

int main()
{
    int nombre;
    scanf("%d", &nombre);
    do
    {
        nombre = termeSuivant(nombre);
        printf("%d ", nombre);
    }while (nombre != 1);    //Tant que termeSuivant n'est pas égal à 1, on affiche le terme
    return 0;
}
