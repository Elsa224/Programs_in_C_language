/*TP final : Gestion d'une classe étudiants en utilisant une base de données (fichiers)*/

#include "variables_functions.h"
const char* fichVRAC = "fichier_VRAC1.txt";
const char* fichBASE = "fichier_BASE1.txt";
const char* fichFINAL = "fichier_FINAL1.txt";

///Etape (i) : Création de la BD de 10 étudiants dans un fichier
int main(int argc, char const *argv[])
{

    char result = menuDeTravail();
    //Ensuite mettre les procédures des différentes tâches
    switch (result)
    {
    case '1':
        createFICH_VRAC(fichVRAC);
        createFICH_BASE(fichBASE,TAILLE_N/5);
        
        break;
    case '2':
         add_a_student(fichVRAC);// Ajout d'un étudiant dans le fichier VRAC
         createFICH_BASE(fichBASE, ((TAILLE_N/5) +1)); // on l'ajoute également dans fich BASE
        break;
    case '3':
        //correctionE_mail();
        break;
    case '4':
        createFICH_FINAL(fichFINAL); // Et aussi dans le fichier FINAL. Pas encore terminé
        break;

    default:
        //Retour(); //peut-être que je vais l'ajouter
        break;
    }
    return 0;
}