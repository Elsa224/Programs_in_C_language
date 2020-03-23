#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TAILLE_N 10 //N = 10
#define NOM_PRENOM_LENGTH 22
#define EMAIL_LENGTH 27
#define MATRICULE_LENGTH 11

//Déclaration avec typedef la structure Etudiant
typedef struct etudiant
{
    char nomPrenoms[NOM_PRENOM_LENGTH];
    char matricule[MATRICULE_LENGTH];
    int age;
    char email[EMAIL_LENGTH];
    float tabDonnees[7]; //Ici il y' aura les 4 notes, la moyenne, le rang et le statut de l'édutiant (Redoublant(1) ou Passant(0))
} etudiant;

//-----------------Prototypes des fonctions--------------------------------//
double average(int taille, float tableau[]);
void triBulleAlphabetique(int taille, etudiant tableau[]);
void triBulleMoyenne(int taille, etudiant tableau[]);
void verificationAjout();

void creationFichier(FILE *pointeurFichier, etudiant tableau[], int taille);
void lectureFichier(FILE *pointeurFichier, etudiant tableau[], int taille);
void creationFICH_VRAC(FILE *pointeurFichier, etudiant tableau[]);
void creationFICH_BASE(FILE *pointeurFichier, etudiant tableau[], int taille);
void creationFICH_FINAL(FILE *pointeurFichier, etudiant tableau[], int taille);
void ajoutEtudiant(FILE *pointeurFichier, etudiant tableau[]);
void correctionEmail(FILE *pointeurFichier, etudiant tableau[], int taille);

char menuDeTravail();
//------------------------------------------------------------------------//

//Déclaration des variables globales
FILE *fichierBD_initial;
int i, j, k = 1, nbNotes = 4;
char choixMenu, answer[4];
etudiant prepa2[TAILLE_N], prepa2Ajout[TAILLE_N + 1];

//Fonction moyenne
double average(int taille, float tableau[])
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

///Étape intermédiaire : Tri selon le nom le tableau par ordre alphabétique
void triBulleAlphabetique(int taille, etudiant tableau[]) //Procédure de tri
{
    int ok = 0, i;
    etudiant tamp;
    while (ok == 0)
    {
        ok = 1;
        for (i = 0; i < taille - 1; i++)
        {
            if (strcmp(tableau[i].nomPrenoms, tableau[i + 1].nomPrenoms) > 0)
            {
                tamp = tableau[i];
                tableau[i] = tableau[i + 1];
                tableau[i + 1] = tamp;
                ok = 0;
            }
        }
    }
}

///Etape intermédiaire : tri décroissant selon la moyenne pour trouver le rang
void triBulleMoyenne(int taille, etudiant tableau[]) //Procédure de tri
{
    etudiant tampon;
    for (i = 0; i < taille - 1; i++)
    {
        for (j = 0; j < taille - (i + 1); j++)
        {
            if (tableau[j].tabDonnees[4] < tableau[j + 1].tabDonnees[4])
            {
                tampon = tableau[j];
                tableau[j] = tableau[j + 1];
                tableau[j + 1] = tampon;
            }
        }
    }
    for (i = 0; i < taille; i++) //Pour avoir le rang
        {tableau[i].tabDonnees[5] = i + 1;}

    for (i = 0; i < taille; i++)
    {
        if (tableau[i].tabDonnees[4] == tableau[i + 1].tabDonnees[4]) //Pour les ex-aequo
            {tableau[i + 1].tabDonnees[5] = tableau[i].tabDonnees[5];}
    }
}

//Procédure de saisie des valeurs de chaque étudiant
void saisieEtudiant(etudiant tableau[], int taille)
{
    //Saisie des valeurs de chaque étudiant
    for (i = 0; i < taille; i++)
    {
        strcpy(tableau[i].matricule, "ENSIT_"); //Initialisation des 6 premiers char du matricule
        system("clear");
        printf("\nEtudiant n* %d : \n\t", i + 1);
        printf("Saisissez les nom et prenom s'il vous plait (ex: Ametchi_Liam) : ");
        scanf("%s", tableau[i].nomPrenoms);
        printf("\tMatricule : \"ENSIT_***\". Saisissez les 3 derniers chiffres (\"***\") du matricule s'il vous plait : ");
        char chiffreMatricule[4];
        scanf("%s", chiffreMatricule);
        strcat(tableau[i].matricule, chiffreMatricule);
        printf("\tSaisissez l'age s'il vous plait : ");
        scanf("%d", &tableau[i].age);
        do
        {
            printf("\tSaisissez l'email s'il vous plait (25 caracteres pas plus pas moins) : ");
            scanf("%s", tableau[i].email);

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

//Procédure de création d'un fichier
void creationFichier(FILE *pointeurFichier, etudiant tableau[], int taille)
{
    for (i = 0; i < taille; i++)
    {
        //Création de la BD
        fprintf(pointeurFichier, "%s\t\t%s\t%d\t%s\t"
                                 "%.2lf\t%.2lf\t%.2lf\t%.2lf\t"
                                 "%.2lf\t%.0lf\t%.0lf\n",
                tableau[i].nomPrenoms, tableau[i].matricule, tableau[i].age, tableau[i].email, tableau[i].tabDonnees[0], tableau[i].tabDonnees[1], tableau[i].tabDonnees[2], tableau[i].tabDonnees[3], tableau[i].tabDonnees[4], tableau[i].tabDonnees[5], tableau[i].tabDonnees[6]);
    }
    fclose(pointeurFichier);
}

//Etape intermédiaire : lecture de la BD
void lectureFichier(FILE *pointeurFichier, etudiant tableau[], int taille)
{
    if (pointeurFichier == NULL)
    {
        printf("Desole, fichier introuvable. Veuillez d'abord creer le fichier avant de le lire!\n");
    }

    else
    {
        printf("NomPrenoms\t\tMle\t\tAge\t\tE-mail\t\t\t"
               "AL\tAN\tE\tP\t"
               "Moyenne\tRang\tStatut\n\n");

        for (i = 0; i < taille; i++)
        {
            fscanf(pointeurFichier, "%s\t\t%s\t%d\t%s\t%g\t%g\t%g\t%g\t%g\t%g\t%g\n", tableau[i].nomPrenoms, tableau[i].matricule, &tableau[i].age, tableau[i].email, &tableau[i].tabDonnees[0], &tableau[i].tabDonnees[1], &tableau[i].tabDonnees[2], &tableau[i].tabDonnees[3], &tableau[i].tabDonnees[4], &tableau[i].tabDonnees[5], &tableau[i].tabDonnees[6]);
        }
        fclose(pointeurFichier);

        //Affichage
        for (i = 0; i < taille; i++)
        {
            printf("%s\t\t%s\t%d\t%s\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.2lf\t%.0lf\t%.0lf\n",
                   tableau[i].nomPrenoms, tableau[i].matricule, tableau[i].age, tableau[i].email, tableau[i].tabDonnees[0], tableau[i].tabDonnees[1], tableau[i].tabDonnees[2], tableau[i].tabDonnees[3], tableau[i].tabDonnees[4], tableau[i].tabDonnees[5], tableau[i].tabDonnees[6]);
        }
    }
} //fin de lecture FICHIER

///Etape (i) : création de FICH_VRAC
void creationFICH_VRAC(FILE *pointeurFichier, etudiant tableau[])
{
    //Partie saisie dans la console
    saisieEtudiant(tableau, TAILLE_N);

    //Partie saisie dans le fichier
    pointeurFichier = fopen("fichier_VRAC.txt", "w");
    creationFichier(pointeurFichier, tableau, TAILLE_N);

    //Lecture et affichage du fichier créé
    printf("\n\nLa saisie obtenue est la suivante :\n\n");
    pointeurFichier = fopen("fichier_VRAC.txt", "r");
    lectureFichier(pointeurFichier, tableau, TAILLE_N);

} //fin de creationFICH_VRAC

//Etape (ii) : création du fichier avec les noms rangés par ordre alphabétique
void creationFICH_BASE(FILE *pointeurFichier, etudiant tableau[], int taille)
{
    //lecture du fichier FICH_VRAC
    printf("\n\nLa saisie obtenue dans le fichier donne :\n\n");
    pointeurFichier = fopen("fichier_VRAC.txt", "r");
    lectureFichier(pointeurFichier, tableau, taille);

    //Tri par ordre alphabétique
    triBulleAlphabetique(taille, tableau);

    //Création du fichier FICH_BASE
    pointeurFichier = fopen("fichier_BASE.txt", "w");
    creationFichier(pointeurFichier, tableau, taille);

    //lecture du fichier FICH_BASE
    printf("\n\nLe tri par ordre alphabetique donne :\n\n");
    pointeurFichier = fopen("fichier_BASE.txt", "r");
    lectureFichier(pointeurFichier, tableau, taille);
}

//Etape (iii) : création du fichier avec les noms rangés par ordre alphabétique et la colonne de rang
void creationFICH_FINAL(FILE *pointeurFichier, etudiant tableau[], int taille)
{
    //lecture du fichier FICH_BASE
    printf("\n\nOn lit encore le fichier rangé :\n\n");
    pointeurFichier = fopen("fichier_BASE.txt", "r");
    lectureFichier(pointeurFichier, tableau, taille);

    //Tri par la moyenne pour obtenir les rangs avec existence des ex-aequo s'il y a
    triBulleMoyenne(taille, tableau);

    //Tri par ordre alphabétique
    triBulleAlphabetique(taille, tableau);

    //Création du fichier FICH_FINAL
    pointeurFichier = fopen("fichier_FINAL.txt", "w");
    creationFichier(pointeurFichier, tableau, taille);

    //Lecture du fichier FICH_FINAL
    printf("\n\nApres toutes les modifications apportees, le fichier final donne :\n\n");
    pointeurFichier = fopen("fichier_FINAL.txt", "r");
    lectureFichier(pointeurFichier, tableau, taille);
}

// Choix 2 : ajouter un étudiant
void ajoutEtudiant(FILE *pointeurFichier, etudiant tableau[])
{
    //Test d'ouverture du fichier BASE
    pointeurFichier = fopen("fichier_BASE.txt", "r");
    if (pointeurFichier == NULL)
    {
        printf("Desole, fichier introuvable. Veuillez d'abord creer le fichier avant de le lire!\n");
    }
    fclose(pointeurFichier);

    //Partie saisie dans la console
    saisieEtudiant(tableau, 1); //parce qu'on va ajouter 1 seul étudiant

    //Ouverture du fichier FICH_BASE pour ajout
    pointeurFichier = fopen("fichier_BASE.txt", "a+");
    fprintf(pointeurFichier, "\n");
    creationFichier(pointeurFichier, tableau, 1);

    //Lecture et affichage du fichier créé
    printf("\n\nLa saisie obtenue est la suivante :\n\n");
    pointeurFichier = fopen("fichier_BASE.txt", "r");
    lectureFichier(pointeurFichier, tableau, TAILLE_N + 1);

    //Tri par ordre alphabétique
    triBulleAlphabetique(TAILLE_N + 1, tableau);

    //Création du fichier FICH_BASE avec ajout
    pointeurFichier = fopen("fichier_BASE.txt", "w");
    creationFichier(pointeurFichier, tableau, TAILLE_N + 1);

    //lecture du fichier FICH_BASE avec ajout
    printf("\n\nLe tri par ordre alphabetique avec l'ajout donne :\n\n");
    pointeurFichier = fopen("fichier_BASE.txt", "r");
    lectureFichier(pointeurFichier, tableau, TAILLE_N + 1);
}

//Choix 3: correction de l'adresse e-mail
void correctionEmail(FILE *pointeurFichier, etudiant tableau[], int taille)
{
    char nomEtudiant[NOM_PRENOM_LENGTH], emailEtudiant[EMAIL_LENGTH], emailCorrigee[EMAIL_LENGTH];
    system("clear");

    //Test d'ouverture du fichier BASE
    pointeurFichier = fopen("fichier_BASE.txt", "r"); //à remplacer par fichier BASE après test
    if (pointeurFichier == NULL)
        {printf("\n\nDesole, fichier introuvable. Veuillez d'abord creer le fichier avant de le lire!\n");}
    else
    {
        //lecture du fichier FICH_BASE
        printf("\nVoici la liste initiale : \n\n");
        lectureFichier(pointeurFichier, tableau, taille);
        printf("\n\n\tVeuillez saisir le nom de l'etudiant dont vous souhaitez changer l'email : ");
        scanf("%s", nomEtudiant);

        for ( i = 0; i < taille; i++)
        {
            if (strcmp(tableau[i].nomPrenoms, nomEtudiant) == 0)
            {
                do
                {
                    printf("\n\tVeuillez saisir l'ancienne email: ");
                    scanf("%s", emailEtudiant);
                } while (strcmp(tableau[i].email, emailEtudiant) != 0);

                do
                {
                    printf("\n\tVeuillez saisir la nouvelle adresse mail (25 caracteres pas plus pas moins): ");
                    scanf("%s", emailCorrigee);
                } while (strlen(emailCorrigee) != 25);

                //Maintenant qu'on a corrigé l'email, on la remplace dans le tableau
                strcpy(tableau[i].email, emailCorrigee);

                //Création du fichier FICH_BASE_EMAIL_CORRIGEE
                pointeurFichier = fopen("fichier_BASE.txt", "w");
                creationFichier(pointeurFichier, tableau, taille);

                //Lecture du fichier FICH_BASE_...
                printf("\n\nApres correction de l'email, on a :\n\n");
                pointeurFichier = fopen("fichier_BASE.txt", "r");
                lectureFichier(pointeurFichier, tableau, taille);
            }
            else
                {if(i==taille-1){printf("\n\tCe nom n'existe pas. Veuillez recommencer s'il vous plait\n\n");i++;}}
                //Ajouter ma fonction retour
        }
    }
}

void verificationAjout()
{
    system("clear"); printf("\n\tAviez-vous au prealable ajoute un etudiant ? (\"oui\"/\"non\"): "); 
    scanf("%s", answer);
    while (strcmp(answer, "oui") != 0 && strcmp(answer, "non") != 0)
        {printf("\n\n\tVeuillez recommencer s'il vous plait : "); scanf("%s", answer);}
}

//Le menu
char menuDeTravail()
{
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
    while (choixMenu != '1' && choixMenu != '2' && choixMenu != '3' && choixMenu != '4')
    {
        system("color 4f");
        printf("\nVeuillez saisir 1 ou 2 s'il vous pla\214t.\n\t");
        scanf("%s", &choixMenu);
        system("pause");
    }

    //Si jamais l'on retourne un caractère c'est parce que l'utilisateur a sélectionné l'une des options proposées
    return choixMenu;
}