/*TP final : Gestion d'une classe étudiants en utilisant une base de données (fichiers)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_N 2 //N = 10 mais pour la mise au point des programmes, utiliser tab[6] ou tab[7]

//Déclaration avec typedef la structure Etudiant
typedef struct etudiant
{
    char nomPrenoms[21];
    char matricule[10];
    int age;
    char email[26];
    double tabDonnees[7];       //Ici il y' aura les 4 notes, la moyenne, le rang et le statut de l'édutiant (Redoublant(1) ou Passant(0))
}etudiant;

//Déclaration des variables globales
FILE* fichierBD_initial, fichierBD_modifie;
char choixMenu; etudiant prepa2[TAILLE_N]; 
int nbNotes = 4, i, j, k;
int longueurPremierePhrase = strlen("NomPrenoms\t\tMle\t\tAge\t\tE-mail\t\t\t"
                                              "AL\tAN\tE\tP\t"
                                              "Moyenne\tRang\tStatut\n\n");

//Fonction moyenne
double average(int taille, double tableau[])
{
    int i;
    double somme = 0, moy;
    for (i = 0; i < taille; i++)
    {
        somme = somme + tableau[i];
        moy = (double)(somme / (i + 1));
    }
    return moy;
}

//Procédure de saisie des valeurs de chaque étudiant
void saisieEtudiant(etudiant tableau[])
{
    //Saisie des valeurs de chaque étudiant
        //Comme les 6 premiers caractères du matricule sont "ENSIT_", je vais déjà les initialiser
        for (i = 0; i < TAILLE_N; i++)
        {
            tableau[i].matricule[0] = 'E';
            tableau[i].matricule[1] = 'N';
            tableau[i].matricule[2] = 'S';
            tableau[i].matricule[3] = 'I';
            tableau[i].matricule[4] = 'T';
            tableau[i].matricule[5] = '_';
        }

        for (i = 0; i < TAILLE_N; i++)
        {
            system("cls");
            printf("\nEtudiant n* %d : \n\t", i + 1);
            printf("Saisissez les nom et prenom s'il vous plait (ex: Ametchi_Liam) : ");
            scanf("%s", tableau[i].nomPrenoms);
            printf("\tMatricule : \"ENSIT_***\". Saisissez les 3 derniers chiffres (\"***\") du matricule s'il vous plait : ");
            for (k = 6; k < 9; k++)
            {
                scanf("%s", &tableau[i].matricule[k]);
            }
            printf("\tSaisissez l'age s'il vous plait : ");
            scanf("%d", &tableau[i].age);
            do
            {
                printf("\tSaisissez l'email s'il vous plait (25 caracteres pas plus pas moins) : ");
                scanf("%s", &tableau[i].email);

            } while (strlen(tableau[i].email) != 25);
            
            printf("\tSaisissez ses notes (AL, AN, E, P) s'il vous plait : \n");
            for (j = 0; j < nbNotes; j++) //Il y a 4 notes
            {
                printf("\t\tNote n* %d : ", j + 1);
                scanf("%lf", &tableau[i].tabDonnees[j]);
            }
            //Calcul de la moyenne
            tableau[i].tabDonnees[4] = average(nbNotes, tableau[i].tabDonnees);

            printf("\n\tSaisissez le statut (\"1\" pour Redoublant et \"0\" pour Passant ) s'il vous plait : ");
            scanf("%lf", &tableau[i].tabDonnees[6]);
        }
}

///Etape (i) : création de FICH_VRAC
void creationDeFICH_VRAC( FILE *pointeurFichier, etudiant tableau[] )
{
    //Partie saisie dans la console
        saisieEtudiant(tableau);

    //Partie saisie dans le fichier
        pointeurFichier = fopen("C:\\TP_ZOUGOURI_ELSA\\fichier_VRAC.txt", "w" );

        //Saisie de la ligne "NomPrenoms.....Mle.....Age"
        fprintf(pointeurFichier, "NomPrenoms\t\tMle\t\tAge\t\tE-mail\t\t\t"
                                              "AL\tAN\tE\tP\t"
                                              "Moyenne\tRang\tStatut\n\n");

        for ( i = 0; i < TAILLE_N; i++)
        {  
            //Création de la BD
            fprintf(pointeurFichier, "%s\t\t%s\t%d\t%s\t"
                                                  "%.2lf\t%.2lf\t%.2lf\t%.2lf\t"
                                                  "%.2lf\t%.0lf\t%.0lf\n", tableau[i].nomPrenoms, tableau[i].matricule, tableau[i].age
                                                                                        , tableau[i].email, tableau[i].tabDonnees[0], tableau[i].tabDonnees[1]
                                                                                        , tableau[i].tabDonnees[2], tableau[i].tabDonnees[3], tableau[i].tabDonnees[4]
                                                                                        , tableau[i].tabDonnees[5], tableau[i].tabDonnees[6] );
        }
        fclose(pointeurFichier);

}   //fin de creationDeFICH_VRAC

//Etape intermédiaire : lecture de la BD
void lectureFICH_VRAC(FILE *pointeurFichier, etudiant tableau[])
{
    pointeurFichier = fopen("C:\\TP_ZOUGOURI_ELSA\\fichier_VRAC.txt", "r" );
    if (pointeurFichier == NULL)
    {
        printf("Desole, fichier introuvable. Veuillez d'abord creer le fichier avant de le lire!\n");
    }
    else
    {
        printf("\n\nLa saisie obtenue est la suivante :\n\n");
        printf("NomPrenoms\t\tMle\t\tAge\t\tE-mail\t\t\t"
                   "AL\tAN\tE\tP\t"
                   "Moyenne\tRang\tStatut\n\n");

        //Positionnement à partir du premier nom de la liste
        fseek(pointeurFichier, 62, SEEK_SET);
        for ( i = 0; i < TAILLE_N; i++)
        {  
            //Lecture de la BD
            fscanf(pointeurFichier, "%s\t\t%s\t%d\t%s\t"
                                                  "%.2lf\t%.2lf\t%.2lf\t%.2lf\t"
                                                  "%.2lf\t%.0lf\t%.0lf\n", tableau[i].nomPrenoms, tableau[i].matricule, tableau[i].age
                                                                                        , tableau[i].email, tableau[i].tabDonnees[0], tableau[i].tabDonnees[1]
                                                                                        , tableau[i].tabDonnees[2], tableau[i].tabDonnees[3], tableau[i].tabDonnees[4]
                                                                                        , tableau[i].tabDonnees[5], tableau[i].tabDonnees[6] );
        }
        fclose(pointeurFichier);                                                                                             
    
        //Affichage
        for ( i = 0; i < TAILLE_N; i++)
        {
            printf("%s\t\t%s\t%d\t%s\t"
                    "%.2lf\t%.2lf\t%.2lf\t%.2lf\t"
                    "%.2lf\t%.0lf\t%.0lf\n", tableau[i].nomPrenoms, tableau[i].matricule, tableau[i].age
                                                          , tableau[i].email, tableau[i].tabDonnees[0], tableau[i].tabDonnees[1]
                                                          , tableau[i].tabDonnees[2], tableau[i].tabDonnees[3], tableau[i].tabDonnees[4]
                                                          , tableau[i].tabDonnees[5], tableau[i].tabDonnees[6] );
        }                                                                                                                                                               
    }            
} //fin de lecture FICH_VRAC


//Tout d'abord le menu
void menuDeTravail()
{
    //Contrôle de saisie
    do
    {
        system("cls");
        system("color 0e");
        printf("\n\t\tBonjour et bienvenue dans le programme de gestion des etudiants de l'ENSIT!"
                    "\n\tQue souhaitez-vous faire?\n"
                        "\n\t\t\t       (1).    Creer le fichier FICH_VRAC"
                        "\n\t\t\t       (2).    Ajouter un etudiant"
                        "\n\t\t\t       (3).    Corriger l'adresse e-mail"
                        "\n\t\t\t       (4).    Creer le fichier final FICH_FINAL"
                    "\n\n\n\tTapez votre choix [1-2-3-4] : ");
                    
        scanf("%s", &choixMenu);
        if(choixMenu != '1' && choixMenu != '2' && choixMenu != '3' && choixMenu != '4')
        {
            system("color 4f");
            printf("\nVeuillez saisir 1 ou 2 s'il vous pla\214t.\n\t");
            system("pause");
        }
    }
    while(choixMenu != '1' && choixMenu != '2' && choixMenu != '3' && choixMenu != '4');

//Ensuite mettre les procédures des différentes tâches
    switch (choixMenu)
    {
    case '1':
        creationDeFICH_VRAC(fichierBD_initial, prepa2);
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

}

///Etape (i) : Création de la BD de 10 étudiants dans un fichier
int main(int argc, char const *argv[])
{
    menuDeTravail();

    return 0;
}