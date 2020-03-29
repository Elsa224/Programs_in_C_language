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
        creationFICH_VRAC(fichierBD_initial, prepa2);
        creationFICH_BASE(fichierBD_initial, prepa2, nbStudentInFile(fichVRAC));
      break;

      case '2':
        ajoutEtudiant(fichierBD_initial, prepa2, nbStudentInFile(fichBASE));
      break;

      case '3':
        correctionEmail(fichierBD_initial, prepa2, nbStudentInFile(fichBASE));
      break;
         
      case '4':
        creationFICH_FINAL(fichierBD_initial, prepa2,nbStudentInFile(fichBASE));
      break;
   }
   return 0;
}