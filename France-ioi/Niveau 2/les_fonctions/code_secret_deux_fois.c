/* FRANCE-IOI : exercice 2.3-1) : Code secret deux fois*/

#include <stdio.h>
#include <stdlib.h>
#define CODE_SECRET 4242 //Le code secret à trouver

//Procédure de saisie du code
void saisieDuCode()
{
    int codeSaisi; //Code à saisir
    do
    {
        printf("Entrez le code : \n");
        scanf("%d\n", &codeSaisi);
    } while (codeSaisi != CODE_SECRET);
}

int main()
{
    //Saisie du code une première fois
    saisieDuCode();
    printf("Encore une fois.\n");

    //Saisie du code une deuxième fois
    saisieDuCode();
    printf("Bravo.\n");
    return 0;
}