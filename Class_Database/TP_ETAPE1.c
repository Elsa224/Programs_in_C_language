/*TP final : Gestion d'une classe étudiants en utilisant une base de données (fichiers)*/

#include "variables_functions.h"


///Etape (i) : Création de la BD de 10 étudiants dans un fichier
int main(int argc, char const *argv[])
{
    char result = menuDeTravail(), answer[4];
    //Ensuite mettre les procédures des différentes tâches
    switch (result)
    {
    case '1':
        //creationFICH_VRAC(fichierBD_initial, prepa2);
        creationFICH_BASE(fichierBD_initial, prepa2);
        creationFICH_FINAL(fichierBD_initial, prepa2);
        break;
    case '2':
        ajoutEtudiant(fichierBD_initial, prepa2Ajout);
        break;
    case '3':
        system("clear"); printf("\n\tAviez-vous au prealable ajoute un etudiant ? (\"oui\"/\"non\"): "); 
        scanf("%s", answer);
        while (strcmp(answer, "oui") != 0 && strcmp(answer, "non") != 0)
            {printf("\n\n\tVeuillez recommencer s'il vous plait : "); scanf("%s", answer);}
        if (strcmp(answer, "oui") == 0)
            {correctionEmail(fichierBD_initial, prepa2Ajout, TAILLE_N+1);}
        else
            {correctionEmail(fichierBD_initial, prepa2, TAILLE_N);}
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