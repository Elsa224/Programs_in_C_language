#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_N 2 //N = 10 mais pour la mise au point des programmes, utiliser tab[6] ou tab[7]
#define NOM_PRENOM_LENGTH 22 
#define EMAIL_LENGTH 27 
#define MATRICULE_LENGTH 11 



//Déclaration avec typedef la structure Etudiant
typedef struct etudiant{
    char nomPrenoms[NOM_PRENOM_LENGTH];
    char matricule[MATRICULE_LENGTH];
    int age;
    char email[EMAIL_LENGTH];
    float tabDonnees[7];       //Ici il y' aura les 4 notes, la moyenne, le rang et le statut de l'édutiant (Redoublant(1) ou Passant(0))
}etudiant;

//-----------------Prototypes des fonctions--------------------------------
double average(int taille, float tableau[]);
void creationDeFICH_VRAC( FILE *pointeurFichier, etudiant tableau[] );
void lectureFICH_VRAC(FILE *pointeurFichier, etudiant tableau[]);
char menuDeTravail();
//------------------------------------------------------------------------

//Déclaration des variables globales
FILE* fichierBD_initial, fichierBD_modifie;
int i,j,k,nbNotes = 4;
char choixMenu; etudiant prepa2[TAILLE_N]; 


//Fonction moyenne
double average(int taille, float tableau[]){
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
void saisieEtudiant(etudiant tableau[]){
    //Saisie des valeurs de chaque étudiant
        char mat[3]; // Chaine des 3 derniers caractères du matricule
        
        for (i = 0; i < TAILLE_N; i++)
        {
            strcat(tableau[i].matricule,"ENSIT_");//Comme les 6 premiers caractères du matricule sont "ENSIT_", je vais déjà les initialiser
            system("clear");
            printf("\nEtudiant n* %d : \n\t", i + 1);
            printf("Saisissez les nom et prenom s'il vous plait (ex: Ametchi_Liam) : ");
            scanf("%s", tableau[i].nomPrenoms);
            printf("\tMatricule : \"ENSIT_***\". Saisissez les 3 derniers chiffres (\"***\") du matricule s'il vous plait : ");
            scanf("%s",mat);
            strcat(tableau[i].matricule,mat); // Ajout des 3 derniers caractères à la chaine ENSIT_ initialisée plus haut
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
                scanf("%f", &tableau[i].tabDonnees[j]);
            }
            //Calcul de la moyenne
            tableau[i].tabDonnees[4] = average(nbNotes, tableau[i].tabDonnees);

            printf("\n\tSaisissez le statut (\"1\" pour Redoublant et \"0\" pour Passant ) s'il vous plait : ");
            scanf("%f", &tableau[i].tabDonnees[6]);
        }
}

///Etape (i) : création de FICH_VRAC
void creationDeFICH_VRAC( FILE *pointeurFichier, etudiant tableau[] ){
    //Partie saisie dans la console
        saisieEtudiant(tableau);

    //Partie saisie dans le fichier
        pointeurFichier = fopen("fichier_VRAC.txt", "w" );
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
void lectureFICH_VRAC(FILE *pointeurFichier, etudiant tableau[]){
    pointeurFichier = fopen("fichier_VRAC.txt", "r" );
    if (pointeurFichier == NULL)
    {
        printf("Desole, fichier introuvable. Veuillez d'abord creer le fichier avant de le lire!\n");
    }
    else
    {
        printf("\n\nLa saisie obtenue est la suivante :\n\n");
        printf("NomPrenoms\t\tMle\t\tAge\t\tE-mail\t\t\t"
                   "AL\tAN\tE\tP\t"
                   "Moyenne\t Rang\t Statut\n\n");

        for ( i = 0; i < TAILLE_N; i++){  

         fscanf(pointeurFichier, "%s\t\t%s\t%d\t%s\t%g\t%g\t%g\t%g\t%g\t%g\t%g\n", tableau[i].nomPrenoms, tableau[i].matricule, &tableau[i].age
                                                                                        , tableau[i].email, &tableau[i].tabDonnees[0], &tableau[i].tabDonnees[1]
                                                                                        , &tableau[i].tabDonnees[2], &tableau[i].tabDonnees[3], &tableau[i].tabDonnees[4]
                                                                                        , &tableau[i].tabDonnees[5], &tableau[i].tabDonnees[6] );

    }
        fclose(pointeurFichier);                                                                                             
    
        //Affichage
        for ( i = 0; i < TAILLE_N; i++)
        {
            printf("%s\t\t%s\t%d\t%s\t"
                    "%.2lf\t%.2lf\t%.2lf\t%.2lf\t"
                    " %.2lf\t  %.0lf\t  %.0lf\n", tableau[i].nomPrenoms, tableau[i].matricule, tableau[i].age
                                                          , tableau[i].email, tableau[i].tabDonnees[0], tableau[i].tabDonnees[1]
                                                          , tableau[i].tabDonnees[2], tableau[i].tabDonnees[3], tableau[i].tabDonnees[4]
                                                          , tableau[i].tabDonnees[5], tableau[i].tabDonnees[6] );
        }                                                                                                                                                               
    }            
} //fin de lecture FICH_VRAC


//Tout d'abord le menu
char menuDeTravail(){

    //Affichage du menu de travail
    system("clear");
    system("color 0e");
    printf("\n\t\tBonjour et bienvenue dans le programme de gestion des etudiants de l'ENSIT!"
                    "\n\tQue souhaitez-vous faire?\n"
                        "\n\t\t\t       (1).    Creer le fichier FICH_VRAC"
                        "\n\t\t\t       (2).    Ajouter un etudiant"
                        "\n\t\t\t       (3).    Corriger l'adresse e-mail"
                        "\n\t\t\t       (4).    Creer le fichier final FICH_FINAL"
                    "\n\n\n\tTapez votre choix [1-2-3-4] : ");
                    
    scanf("%s", &choixMenu);

    //Contrôle de saisie
    while(choixMenu != '1' && choixMenu != '2' && choixMenu != '3' && choixMenu != '4'){
         system("color 4f");
            printf("\nVeuillez saisir 1 ou 2 s'il vous pla\214t.\n\t");
            scanf("%s",&choixMenu);
            system("pause");
    }

    //Si jamais l'on retourne un caractère c'est parce que l'utilisateur a sélectionné l'une des options proposées
    return choixMenu;

    

}

