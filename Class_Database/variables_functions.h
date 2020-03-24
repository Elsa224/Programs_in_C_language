#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define TAILLE_N 10 //N = 10 
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

//-----------------Prototypes des fonctions--------------------------------//
double average(int taille, float tableau[]);
void triBulleAlphabetique(int taille, etudiant tableau[]);
void triBulleMoyenne(int taille, etudiant tableau[]);

void creationFichier(FILE *pointeurFichier, etudiant tableau[], int taille);
void lectureFichier(FILE *pointeurFichier, etudiant tableau[], int taille);
void creationFICH_VRAC(FILE *pointeurFichier, etudiant tableau[]);
void creationFICH_BASE(FILE *pointeurFichier, etudiant tableau[]);
void creationFICH_FINAL(FILE *pointeurFichier, etudiant tableau[]);
char menuDeTravail();

int nbStudentInFile(const char* filename);
void add_a_student(const char* filename);
void createFICH_VRAC(const char* filename);
void createFICH_BASE(const char* filename,int taille);
void createFICH_FINAL(const char* filename);
void scanf_student(etudiant* tmp);
void insertStudentInFile(etudiant tmp, const char* filename);
void read_info_from_file(const char* filename, etudiant* etudiant,int taille);
bool doesFileExist(const char* filename);

//------------------------------------------------------------------------//

//Déclaration des variables globales
FILE* fichierBD_initial;
int i, j, k = 1, nbNotes = 4, tabTaille;
char choixMenu; etudiant prepa2[TAILLE_N]; 

//Fonction moyenne
double average(int taille, float tableau[]){
    int i;
    float somme = 0.0, moy;
    for (i = 0; i < taille; i++)
    {
        somme = somme + tableau[i];
        moy = (double)(somme / (i + 1));
    }
    return moy;
}

///Étape intermédiaire : Tri selon le nom le tableau par ordre alphabétique
void triBulleAlphabetique(int taille, etudiant tableau[])   //Procédure de tri
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
void triBulleMoyenne(int taille, etudiant tableau[])    //Procédure de tri
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
    for ( i = 0; i < taille; i++) //Pour avoir le rang
        {tableau[i].tabDonnees[5] = i+1;}

    for ( i = 0; i < taille; i++)
    {
        if (tableau[i].tabDonnees[4] == tableau[i+1].tabDonnees[4]) //Pour les ex-aequo
            {tableau[i+1].tabDonnees[5] = tableau[i].tabDonnees[5];}
    }
    
}

//Procédure de saisie des valeurs de chaque étudiant
void saisieEtudiant(etudiant tableau[], int taille){
    //Saisie des valeurs de chaque étudiant
        for (i = 0; i < taille; i++)
        {
            strcpy(tableau[i].matricule, "ENSIT_"); //Initialisation des 6 premiers char du matricule
            system("clear");
            printf("\nEtudiant n* %d : \n\t", i + 1);
            printf("Saisissez les nom et prenom s'il vous plait (ex: Ametchi_Liam) : ");
            scanf("%s", tableau[i].nomPrenoms);
            printf("\tMatricule : \"ENSIT_***\". Saisissez les 3 derniers chiffres (\"***\") du matricule s'il vous plait : ");
            char chiffreMatricule[4]; scanf("%s", chiffreMatricule); strcat(tableau[i].matricule, chiffreMatricule);
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
void creationFichier(FILE *pointeurFichier, etudiant tableau[], int taille){
    for ( i = 0; i < taille; i++)
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
}

//Etape intermédiaire : lecture de la BD
void lectureFichier(FILE *pointeurFichier, etudiant tableau[], int taille){
    if (pointeurFichier == NULL)
    {
        printf("Desole, fichier introuvable. Veuillez d'abord creer le fichier avant de le lire!\n");
    }
    else
    {
        printf("NomPrenoms\t\tMle\t\tAge\t\tE-mail\t\t\t"
                   "AL\tAN\tE\tP\t"
                   "Moyenne\tRang\tStatut\n\n");

        for ( i = 0; i < taille; i++)
        {  
            fscanf(pointeurFichier, "%s\t\t%s\t%d\t%s\t%g\t%g\t%g\t%g\t%g\t%g\t%g\n"
                                  , tableau[i].nomPrenoms, tableau[i].matricule, &tableau[i].age
                                  , tableau[i].email, &tableau[i].tabDonnees[0], &tableau[i].tabDonnees[1]
                                  , &tableau[i].tabDonnees[2], &tableau[i].tabDonnees[3], &tableau[i].tabDonnees[4]
                                  , &tableau[i].tabDonnees[5], &tableau[i].tabDonnees[6] );

        }
        fclose(pointeurFichier);                                                                                             
    
        //Affichage
        for ( i = 0; i < taille; i++)
        {
            printf("%s\t\t%s\t%d\t%s\t"
                    "%.2lf\t%.2lf\t%.2lf\t%.2lf\t"
                    "%.2lf\t%.0lf\t%.0lf\n", tableau[i].nomPrenoms, tableau[i].matricule, tableau[i].age
                                                          , tableau[i].email, tableau[i].tabDonnees[0], tableau[i].tabDonnees[1]
                                                          , tableau[i].tabDonnees[2], tableau[i].tabDonnees[3], tableau[i].tabDonnees[4]
                                                          , tableau[i].tabDonnees[5], tableau[i].tabDonnees[6] );
        }                                                                                                                                                               
    }            
} //fin de lecture FICHIER

///Etape (i) : création de FICH_VRAC
void creationFICH_VRAC(FILE *pointeurFichier, etudiant tableau[]){
    //Partie saisie dans la console
    saisieEtudiant(tableau, TAILLE_N);

    //Partie saisie dans le fichier
    pointeurFichier = fopen("fichier_VRAC.txt", "w" );
    creationFichier(pointeurFichier, tableau, TAILLE_N);

    //Lecture et affichage du fichier créé
    printf("\n\nLa saisie obtenue est la suivante :\n\n");
    pointeurFichier = fopen("fichier_VRAC.txt", "r" );
    lectureFichier(pointeurFichier, tableau, TAILLE_N);


}   //fin de creationFICH_VRAC


//Etape (ii) : création du fichier avec les noms rangés par ordre alphabétique
void creationFICH_BASE(FILE *pointeurFichier, etudiant tableau[]){
    //lecture du fichier FICH_VRAC
    printf("\n\nLa saisie obtenue dans le fichier donne :\n\n");
    pointeurFichier = fopen("fichier_VRAC.txt", "r");
    lectureFichier(pointeurFichier, tableau, TAILLE_N);

    //Tri par ordre alphabétique
    triBulleAlphabetique(TAILLE_N, tableau);

    //Création du fichier FICH_BASE
    pointeurFichier = fopen("fichier_BASE.txt", "w");
    creationFichier(pointeurFichier, tableau, TAILLE_N);

    //lecture du fichier FICH_BASE
    printf("\n\nLe tri par ordre alphabetique donne :\n\n");
    pointeurFichier = fopen("fichier_BASE.txt", "r");
    lectureFichier(pointeurFichier, tableau, TAILLE_N);
}

//Etape (iii) : création du fichier avec les noms rangés par ordre alphabétique et la colonne de rang
void creationFICH_FINAL(FILE *pointeurFichier, etudiant tableau[]){
    //lecture du fichier FICH_BASE
    printf("\n\nOn lit encore le fichier rangé :\n\n");
    pointeurFichier = fopen("fichier_BASE.txt", "r");
    lectureFichier(pointeurFichier, tableau, TAILLE_N);

    //Tri par la moyenne pour obtenir les rangs avec existence des ex-aequo s'il y a
    triBulleMoyenne(TAILLE_N, tableau);

    //Tri par ordre alphabétique
    triBulleAlphabetique(TAILLE_N, tableau);

    //Création du fichier FICH_FINAL
    pointeurFichier = fopen("fichier_FINAL.txt", "w");
    creationFichier(pointeurFichier, tableau, TAILLE_N);

    //lecture du fichier FICH_BASE
    printf("\n\nLe fichier range selon l'ordre alphabetique et le rang renseigne donne :\n\n");
    pointeurFichier = fopen("fichier_FINAL.txt", "r");
    lectureFichier(pointeurFichier, tableau, TAILLE_N);
}

//Tout d'abord le menu
char menuDeTravail(){

    //Affichage du menu de travail
    system("clear");
    printf("TAILLE_N = %d\n\n",TAILLE_N);
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



//TODO penser d'abord à déterminer s'il s'agit de la première fois que l'on exécute ce programme 
//De sorte à utiliser TAILLE_N sinon utiliser nbStudenInFile afin de déterminer le nb d'étudiants
//Comment est-ce possible de savoir cela? Si le fichier VRAC existe alors le code a été exécuté au moins une fois
void scanf_student(etudiant* tmp){
    strcpy(tmp->matricule, "ENSIT_"); //Initialisation des 6 premiers char du matricule
            system("clear");
            printf("\nEtudiant n* %d : \n\t", i + 1);
            printf("Saisissez les nom et prenom s'il vous plait (ex: Ametchi_Liam) : ");
            scanf("%s", tmp->nomPrenoms);
            printf("\tMatricule : \"ENSIT_***\". Saisissez les 3 derniers chiffres (\"***\") du matricule s'il vous plait : ");
            char chiffreMatricule[4]; scanf("%s", chiffreMatricule); strcat(tmp->matricule, chiffreMatricule);
            printf("\tSaisissez l'age s'il vous plait : ");
            scanf("%d", &tmp->age);
            do
            {
                printf("\tSaisissez l'email s'il vous plait (25 caracteres pas plus pas moins) : ");
                scanf("%s", tmp->email);

            } while (strlen(tmp->email) != 25);
            
            printf("\tSaisissez ses notes (AL, AN, E, P) s'il vous plait : \n");
            for (j = 0; j < nbNotes; j++) //Il y a 4 notes
            {
                printf("\t\tNote n* %d : ", j + 1);
                scanf("%f", &tmp->tabDonnees[j]);
            }
            //Calcul de la moyenne
            tmp->tabDonnees[4] = average(nbNotes, tmp->tabDonnees);

            printf("\n\tSaisissez le statut (\"1\" pour Redoublant et \"0\" pour Passant ) s'il vous plait : ");
            scanf("%f", &tmp->tabDonnees[6]);
}

// Etape 2 : Ajout Etudiant
void add_a_student(const char* filename){
    int nbEnregistrement = TAILLE_N;
    FILE* fichier = fopen(filename, "a"); // Ouverture du fichier en mode ajout
    if(fichier == NULL)
        printf("Erreur lors de la lecture du fichier");
    else{
        etudiant tmp;
        tmp.tabDonnees[5] = 0; // Initialisation du rang à 0;
        scanf_student(&tmp);
        printf("Après l'appel de de scanf_, on a : \n\n%s\t\t%s\t%d\t%s\t"
                                     "%.2lf\t%.2lf\t%.2lf\t%.2lf\t"
                                     "%.2lf\t%.0lf\t%.0lf\n", tmp.nomPrenoms, tmp.matricule, tmp.age
                                                            , tmp.email, tmp.tabDonnees[0], tmp.tabDonnees[1]
                                                            , tmp.tabDonnees[2], tmp.tabDonnees[3], tmp.tabDonnees[4]
                                                            , tmp.tabDonnees[5], tmp.tabDonnees[6] );
       
        fprintf(fichier, "%s\t\t%s\t%d\t%s\t"
                                     "%.2lf\t%.2lf\t%.2lf\t%.2lf\t"
                                     "%.2lf\t%.0lf\t%.0lf\n", tmp.nomPrenoms, tmp.matricule, tmp.age
                                                            , tmp.email, tmp.tabDonnees[0], tmp.tabDonnees[1]
                                                            , tmp.tabDonnees[2], tmp.tabDonnees[3], tmp.tabDonnees[4]
                                                            , tmp.tabDonnees[5], tmp.tabDonnees[6] );
    }

    fclose(fichier);//fermeture du fichier
}

int nbStudentInFile(const char* filename){
    FILE* fichier = fopen(filename,"r"); // Ouverture du fichier en mode lecture
    int nbStudent = 0;

    if(fichier == NULL){
        printf("Erreur lors de la lecture du fichier");
        exit(-1); // quitte le programme avec comme id 0 comme return 0
    }else{
        //rewind(fichier);
        while( !feof(fichier)){
            char *buffer = (char*) malloc(10*sizeof(etudiant));
            fgets(buffer,10*sizeof(etudiant),fichier);
            if(strcmp("",buffer) == 0)
                break;
            else{
            //printf("buffer = %s\n",buffer);
            nbStudent += 1;
            free(buffer); // Libération de la mémoire allouée à buffer
            }
        }
    }
    //Si jamais cette phrase est affichée alors la fonction s'est bien exécutée
    printf("nbStudentInFile invoked\n");

    return nbStudent;
    
}

void read_info_from_file(const char* filename,etudiant* tmp,int taille){
    //tmp = NULL; //Initialisation d'un tableau vide
    FILE* fichier = fopen(filename,"r");
    if(fichier == NULL)
        printf("Erreur lors de la lecture du fichier");
    else{
        
       // tmp = malloc(taille * sizeof(etudiant)); // Allocation d'un tableau de TAILLE_N etudiants
        for(int i = 0; i < taille; i++){
            fscanf(fichier, "%s\t\t%s\t%d\t%s\t%g\t%g\t%g\t%g\t%g\t%g\t%g\n"
                                    , tmp[i].nomPrenoms, tmp[i].matricule, &tmp[i].age
                                    , tmp[i].email, &tmp[i].tabDonnees[0], &tmp[i].tabDonnees[1]
                                    , &tmp[i].tabDonnees[2], &tmp[i].tabDonnees[3], &tmp[i].tabDonnees[4]
                                    , &tmp[i].tabDonnees[5], &tmp[i].tabDonnees[6] );

        }
    }
    
    printf("read_info_from_file invoked\n");
}

void createFICH_VRAC(const char* filename){
    //FICH_VRAC est le fichier de début et par convention on débute avec 10 étudiants TAILLE_N
    for (i = 0; i < TAILLE_N/5; i++)
        add_a_student(filename);     
} 

void createFICH_BASE(const char* filename,int taille){
    //Le second fichier trié par ordre alphabétique
    FILE* fichier = fopen(filename,"w");
    if(fichier == NULL){
        printf("Erreur lors de la création du fichier");
        exit(-1); //Quitte le programme
    }else{
        //int nbEnregistrement = nbStudentInFile(filename);
        read_info_from_file("fichier_VRAC1.txt",prepa2,taille);
        triBulleAlphabetique(taille,prepa2);

        for(i = 0; i < taille; i++){
            printf("tmp[i].nom = %s", prepa2[i].nomPrenoms);
            insertStudentInFile(prepa2[i],filename);
        }
    }
} 
void createFICH_FINAL(const char* filname){
    //Pour créer le fichier FINAL on vérifie l'existence de fich BASE car si Fich Base existe alors fich VRAC existe
    bool fileExists = doesFileExist("fichier_BASE1.txt");
    if(fileExists){
        printf("Boo\n");
        int nbStudent = nbStudentInFile("fichier_BASE1.txt");
        printf("nbStudent = %d\n",nbStudent);
        printf("createFICH_FINAL invoked\n");
    }
    else{
        printf("Veuillez d'abord creer les fichiers VRAC et BASE\n");
        exit(-2);
    }
}

void insertStudentInFile(etudiant tmp, const char* filename){
     //This function is to add directly the tmp etudiant in the file "filename"
    FILE* fichier = fopen(filename,"a"); // Opening the file in the append mode

    if(fichier == NULL){
        printf("Erreur lors de la création du fichier, Fermeture du programme…\n");
        fclose(fichier);
        exit(-1);
    }else{
        fprintf(fichier, "%s\t\t%s\t%d\t%s\t"
                                     "%.2lf\t%.2lf\t%.2lf\t%.2lf\t"
                                     "%.2lf\t%.0lf\t%.0lf\n", tmp.nomPrenoms, tmp.matricule, tmp.age
                                                            , tmp.email, tmp.tabDonnees[0], tmp.tabDonnees[1]
                                                            , tmp.tabDonnees[2], tmp.tabDonnees[3], tmp.tabDonnees[4]
                                                            , tmp.tabDonnees[5], tmp.tabDonnees[6] );
    }
    fclose(fichier);
}

bool doesFileExist(const char* filename){
    FILE* fichier = fopen(filename,"r");
    if(fichier == NULL)
        return false;
    else
        return true;
}