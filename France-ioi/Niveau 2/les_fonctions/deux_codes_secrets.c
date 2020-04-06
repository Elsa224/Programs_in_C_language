/* FRANCE-IOI : exercice 2.3-2) : Deux codes secrets*/

#include <stdio.h>
#include <stdlib.h>

//Procédure de saisie du code
void saisieDuCode(int codeSecret)
{
    int codeSaisi; //Code à saisir
    do
    {
        printf("Entrez le code : \n");
        scanf("%d\n", &codeSaisi);
    } while (codeSaisi != codeSecret);
}

int main()
{
    //Saisie du premier code
    saisieDuCode(4242);
    printf("Premier code bon.\n");

    //Saisie du second code
    saisieDuCode(2121);
    printf("Bravo.\n");
    return 0;
}