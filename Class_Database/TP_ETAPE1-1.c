/*TP final : Gestion d'une classe étudiants en utilisant une base de données (fichiers)*/

#include "variables_functions_ok.h"
const char* fichVRAC = "fichier_VRAC.txt";
const char* fichBASE = "fichier_BASE.txt";
const char* fichFINAL = "fichier_FINAL.txt";

///Etape (i) : Création de la BD de 10 étudiants dans un fichier
int main(int argc, char const *argv[])
{
    char result = menuDeTravail();
    //Ensuite mettre les procédures des différentes tâches
    switch (result)
    {
    case '1':
        //creationFICH_VRAC(fichierBD_initial, prepa2);
        creationFICH_BASE(fichierBD_initial, prepa2, nbStudentInFile("fichier_VRAC.txt"));
        break;

    case '2':
        ajoutEtudiant(fichierBD_initial, prepa2, nbStudentInFile("fichier_BASE.txt"));
        break;

    case '3':
        correctionEmail(fichierBD_initial, prepa2, nbStudentInFile("fichier_BASE.txt"));
        break;
        
    case '4':
        creationFICH_FINAL(fichierBD_initial, prepa2,nbStudentInFile("fichier_BASE.txt") );
        break;

    default:
        //Retour(); //peut-être que je vais l'ajouter
        break;
    }
    return 0;
}