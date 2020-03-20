/*TP final : Gestion d'une classe étudiants en utilisant une base de données (fichiers)*/
#include "variables_functions.h"


///Etape (i) : Création de la BD de 10 étudiants dans un fichier
int main(int argc, char const *argv[])
{
    char result = menuDeTravail();
    //Ensuite mettre les procédures des différentes tâches
    switch (result)
    {
    case '1':
        //creationDeFICH_VRAC(fichierBD_initial, prepa2);
        lectureFICH_VRAC(fichierBD_initial, prepa2);
        break;
    case '2':
        //ajoutEtudiant();
        break;
    case '3':
        //correctionE_mail();
        break;
    case '4':
        //creationFichierFinal();
        break;

    default:
        //Retour(); //peut-être que je vais l'ajouter
        break;
    }
    return 0;
}