/*TP final : Gestion d'une classe étudiants en utilisant une base de données (fichiers)*/

//Inclure le fichier des librairies et de toutes les procédures et fonctions utilisées
#include "variables_functions.h"

int main(int argc, char const *argv[])
{
    do
    {
        result = menuDeTravail(); //Pour avoir le choix de l'utilisateur
        switch (result)
        {
            case '1': //Créer FICHIER_VRAC
                creationFICH_VRAC(fichierBD, prepa2);
                creationFICH_BASE(fichierBD, prepa2, nbStudentInFile(fichVRAC));
            break;

            case '2': //Ajout d'un étudiant
                ajoutEtudiant(fichierBD, prepa2, nbStudentInFile(fichBASE));
            break;

            case '3': //Corriger l'adresse email
                correctionEmail(fichierBD, prepa2, nbStudentInFile(fichBASE));
            break;
                
            case '4': //Créer FICHIER_FINAL
                creationFICH_FINAL(fichierBD, prepa2,nbStudentInFile(fichBASE));
            break;

            case '5': //Quitter le programme
                printf("\n\n\t\t\tMerci pour votre participation! A bientot :) :)\n\n");
            break;
        }
    }while(result != '5'); //
    return 0;
}