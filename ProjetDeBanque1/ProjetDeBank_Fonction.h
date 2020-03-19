#ifndef PROJETDEBANK_FONCTION_H_INCLUDED
#define PROJETDEBANK_FONCTION_H_INCLUDED

//Pour parcourir le fichier et récupérer les infos
#define TAILLE_NOM_MAX 20
#define TAILLE_PRENOM_MAX 50
#define TAILLE_ID_MAX 20
#define TAILLE_PassWorD_MAX 20
#define TAILLE_IDNumCard_MAX 15

    void LogIn();
     int positionPass(); //pour récupérer le mot de passe
    void RecupCompte();
    void RecupNomPrenomGenre();

//Déclaration des types
typedef struct DATEOP
        {
            int jour;
            int mois;
            int annee;
        }DATEOP;

typedef struct operation  //pour l'historique des opérations
    {
        char typeOp[15];
        float montantOp;
        DATEOP dateop;
    }OPERATION;

    // Déclaration des types pour les informations du client et du tiers
    struct personneBank
    {
        char Nom[15];
        char Prenoms[15];
        char SexClient[5];
        char Pwd[15];
        char confPwd[15];
        char OldPwd[15];
        char IDAccount[15];
        char IDNumCard[15];
        int Age;
        int MoneyRegister;
        float SoldeActuel ;
    };

    struct personneTiers  //pour le chèque
    {
        char NomTiers[15];
        char PrenomsTiers[15];
        char SexTiers[5];
    };

    //Nom du fichier
        FILE *Client_Info, *ficheExistOrNot = NULL ;

    //Déclaration des variables globales
   OPERATION tOp[15] , tempo;                                                                   //variable temporaire
    int nmbOp = 0, i = 0, j = 1 ;                                                               //initialisation du nombre d'opération
    int MoneyCheck, closeAccount, continuerOuPas, numlen;
    float SommeAVerser = 0, SommeARetirer = 0;
    char start, choix, choixDeCompte, choixAction, typeDeCompte[20], tempor[30], motDePasse[TAILLE_PassWorD_MAX], numCNI[20], temporNom[20], temporPrenom[20];
    struct personneBank theClient = { " ",  " ",  " ",  " ",  " ",  " ",  " ",  " ",  0,  0,  0};
    struct personneTiers  leTiers = { " ",  " ",  " "};
    const double tauxInteret = 2.5/100 ;
    const char* KindAccount[] = {"COMPTE COURANT", "COMPTE EPARGNE"};
    const char* GenderTiers[] = {"M", "F"};
    const char* Gender[] = {"M", "F"};
    int k = 0 , l = 1;

                                                    //TimeFunctions
    time_t temps;
    struct tm date;
    const char * NomJourSemaine[] = {"dimanche", "lundi", "mardi", "mercredi", "jeudi", "vendredi", "samedi"};
    const char * NomMois[] = {"janvier", "f\202vrier", "mars" , "avril"  , "mai"     , "juin"    ,
                          "juillet", "ao\226t"  , "septembre", "octobre", "novembre", "d\202cembre"};


//Procédures et fonctions
void Hour()                         /*Afficher la date et l'heure courante !*/
{
    //TimeFunctions
    time(&temps);
    date = *localtime(&temps);
    int heures = date.tm_hour;
    int min = date.tm_min;
    printf(" %02u heures et %02u minutes (heure locale)\n", heures, min);  //%02u ou %04u c'est pour rajouter des zéros si le nombre n'a pas assez de chiffre ; ici "1" sera "transformé" en "01"
}

void Day() //Pour juste avoir la date des opérations en lettres
{
    //TimeFunctions
    time(&temps);
    date = *localtime(&temps);
    printf("%s %02u %s %04u ", NomJourSemaine[date.tm_wday], date.tm_mday, NomMois[date.tm_mon], 1900 + date.tm_year);
}

void Loading()
{
    for (int i=0 ; i<=25; i++)
    {
        for(int i=0; i<=15; i++)
        {
            printf("    Veuillez patienter s'il vous pla\214t....Connexion au compte en cours...... \\\n\n");
            printf("    Veuillez patienter s'il vous pla\214t....Connexion au compte en cours...... //\n\n");
        }
    }
}

void showTimeOp()
{
                tempo.dateop.jour = date.tm_mday; // 1 à 31
                tempo.dateop.mois = date.tm_mon+1; /* Months *since* january: 1-12 */
                tempo.dateop.annee = 1900+date.tm_year;
                tOp[nmbOp] = tempo;
                nmbOp++ ;
}

void Hello()
{

        ///Contrôle de saisie
            do
            {
                system("cls");
                system("color f0");
                printf("\n\n\t\t\t\t\t\t\tBonjour!\n");
                printf("\t\t\t\t\t\tBienvenue \205 NIS'Bank!!\n\n");
                printf("\n\n\n\tQue souhaitez-vous faire \77 : \n\t\t1. Commencer\n\t\t2. Quitter\n\t");
                scanf("%s", &start);
                 if(start !='1' && start !='2')
                {
                    system("color 4f");
                    printf("\nVeuillez saisir 1 ou 2 s'il vous pla\214t.\n\t");
                    system("pause");
                }
            }while(start !='1' && start !='2');

            if(start == '1')
                MenuAcceuil();

            if (start == '2')
                Retour();

}  //fin de Hello()

void ModifierPwd()
{
                Loading();
                system("cls");
                do {
                printf("\n\t\tEntrez votre ancien mot de passe s'il vous pla\214t : "); scanf("%s", &theClient.OldPwd);
                   if(strcmp(theClient.Pwd, theClient.OldPwd) != 0)
                {
                    system("color 4f");
                    printf("\n\t\tLes mots de passe ne correspondent pas !! Veuillez recommencer.\n\n\t");
                    system("pause");
                }
        }while(strcmp(theClient.Pwd, theClient.OldPwd) != 0);
                ConfirmPassWord();

                //Ajouter le nouveau mot de passe dans le fichier du client !!
        /*Client_Info = fopen(theClient.IDAccount , "a") ;                     //a = append
        fprintf(Client_Info, "\n\n\t\tNouveau mot de passe : %s", theClient.Pwd)
        fclose(Client_Info);
        motDePasse = theClient.Pwd;  On verra ça après*/


                printf("\n\n\t Mot de passe modifi\202 avec succ\212s !!!!\n");
                printf("\n\n\t");
                system("pause");

}

void LogOff()
{
            printf("\n\n\t==========Retour \205 l'acceuil============\n\n\t\t");
            system("pause");
            MenuAcceuil();
}

void Versement()
{
      Loading();
     do{
             system("cls");
             system("color 0e");
             printf("\n\t--------------------------------------------------------------------------------------------------------\n");
             printf("\n\t\t\t\t\tGESTION        DES        VERSEMENTS       \n ");
             printf("\n\t--------------------------------------------------------------------------------------------------------\n");
             printf("\n\n\t");
             system("pause");
             printf("\n\n\t\tOp\202ration du  : "); Day(); printf("\n\n");
             printf("\t\tVotre solde actuel est de :    %2.f FCFA\n\n", theClient.SoldeActuel);
             printf("\n\n\tVeuillez entrer la somme que vous souhaitez verser sur votre compte s'il vous pla\214t : "); scanf("%f", &SommeAVerser);
             if(SommeAVerser < 0)
                {
                      printf("\n\n\tVeuillez entrer une somme sup\202rieure \205 0 s'il vous pla\214t.\n\n\t");
                      system("pause");
                }
             }while(SommeAVerser < 0);
             printf("\n\n\t");
             system("pause");
             printf("\n\n\44\44\44\44\44\44\44\44\44\44 Yaaayyyyee!!! Versement r\202ussi !!!!  \44\44\44\44\44\44\44\44\44\44");
             printf("\n\n\44\44\44\44\44\44\44\44\44\44 Nouveau solde  :        %2.f  FCFA  \44\44\44\44\44\44\44\44\44\44", theClient.SoldeActuel+SommeAVerser);
             theClient.SoldeActuel = theClient.SoldeActuel + SommeAVerser;
             printf("\n\n\t");
              system("pause");

              ///SAVE OPERATIONS
                strcpy(tempo.typeOp, "Versement" ) ;
                tempo.montantOp = SommeAVerser ;
                showTimeOp();

    }

void Solde()
{
                Loading();
                system("cls");
                printf("\n\t--------------------------------------------------------------------------------------------------------\n");
                printf("\n\t\t\t\t\tCONSULTATION   \t  DU \t   SOLDE          \n ");
                printf("\n\t--------------------------------------------------------------------------------------------------------\n");
                printf("\n\n\t\t=======================================================================================\n");
                printf("\n\t\t\t\tVotre solde actuel est de : %2.f  FCFA\n", theClient.SoldeActuel);
                printf("\n\t\t=======================================================================================\n");
                printf("\n\n\t");
                system("pause");
}

void BankCheck()
{
  /*const char* GenderTiers[] = {"M", "F"};
    const char* Gender[] = {"M", "F"};
    int k = 0 , l = 1;*/
    system("cls");
    printf("\n\n\n\n\tVeuillez entrer le nom et un (1) pr\202nom du b\202n\202ficiaire s'il vous pla\214t : ");
    scanf("%s%s", &leTiers.NomTiers, &leTiers.PrenomsTiers);
     do{
                printf("\n\tSexe (M/F) : ");
                scanf("%s", &leTiers.SexTiers);
        }while(strcmp(leTiers.SexTiers, "M") != 0 && strcmp(leTiers.SexTiers, "F") != 0 );
        do
        {
             system("color 0e");
             printf("\n\tVeuillez entrer le montant s'il vous pla\214t : ");
             scanf("%d", &MoneyCheck);
            if(MoneyCheck <0 || theClient.SoldeActuel < MoneyCheck)
                {
                    system("color 4f");
                    printf("\n\tVotre solde est insuffisant pour effectuer cette op\202ration. Veuillez recommencer.\n\n\t");
                    system("pause");
                }
        }while(MoneyCheck <0 || theClient.SoldeActuel < MoneyCheck);

         if( theClient.SoldeActuel > MoneyCheck || theClient.SoldeActuel == MoneyCheck )
    {
            printf("\n\n\t");
            system("pause");
            system("cls");
            theClient.SoldeActuel = theClient.SoldeActuel - MoneyCheck;

    if( (strcmp(GenderTiers[k], leTiers.SexTiers) == 0) && (strcmp(Gender[k], theClient.SexClient) == 0)  ) //si c'est M et M
            afficheque("M.", "M.", MoneyCheck,  leTiers.NomTiers,  leTiers.PrenomsTiers,  theClient.Nom, theClient.Prenoms);

    if( (strcmp(GenderTiers[l], leTiers.SexTiers) == 0) && (strcmp(Gender[l], theClient.SexClient) == 0) )  //si c'est F et F
            afficheque("Mlle / Mme", "Mme", MoneyCheck,  leTiers.NomTiers,  leTiers.PrenomsTiers,  theClient.Nom, theClient.Prenoms);

    if( (strcmp(GenderTiers[k], leTiers.SexTiers) == 0) && (strcmp(Gender[l], theClient.SexClient) == 0) )  // si c'est  M et F
            afficheque("M.", "Mme", MoneyCheck,  leTiers.NomTiers,  leTiers.PrenomsTiers,  theClient.Nom, theClient.Prenoms);

    if( (strcmp(GenderTiers[l], leTiers.SexTiers) == 0) && (strcmp(Gender[k], theClient.SexClient) == 0) ) //si c'est F et M
            afficheque("Mlle / Mme", "M.", MoneyCheck,  leTiers.NomTiers,  leTiers.PrenomsTiers,  theClient.Nom, theClient.Prenoms);
     system("pause");

    }

            ///SAVE OPERATIONS
                strcpy(tempo.typeOp, "Ch\212que \202mis" ) ;
                tempo.montantOp = MoneyCheck ;
                showTimeOp();
}

void Interet()
{
    system("cls");
    printf("\n\n\tGarder une somme sur votre compte vous g\202n\212re des revenus \205 raison de 2,5 %% d'int\202r\210t par an");
    printf("\n\n\tVotre solde actuel est de %.0f francs CFA et donc les revenus g\202n\202r\202s par ce taux sont de %.2f francs CFA par an !!! \n\n\t ",  theClient.SoldeActuel,  theClient.SoldeActuel * tauxInteret);
    system("pause");
}

void Historique()
{
    Loading();
    int nmbOp_afficher;
            do
                {
                    system("cls");
                    printf("\n\n\t\t=======================================================================================\n");
                    printf("\n\t\t\t\t\t\tHISTORIQUE     DES      OPERATIONS                                                                                                        ");
                    printf("\n\t\t=======================================================================================\n\n\t");
                    system("pause");
                    printf("\n\t\tVeuillez entrer le nombre d'op\202rations \205 afficher s'il vous pla\214t [2-5] : ");
                    scanf("%d", &nmbOp_afficher);
                }while(nmbOp_afficher < 0 && nmbOp_afficher > 5);
                printf("\n\n\t\t\tDATES\t\t\t    LIBELLES\t\t\t    MONTANTS\n\n");
            for( int i = 0 ; i<nmbOp_afficher ; i++)
            {
                printf("\t\t      %02u/%02u/%04u\t\t   %s\t\t\t     %.2f\n\n",tOp[i].dateop.jour, tOp[i].dateop.mois , tOp[i].dateop.annee,  tOp[i].typeOp, tOp[i].montantOp);
            }
                printf("\n\n\t");
                system("pause");
}

void MenuSimple()
{
        printf("\n");
        if(choixAction == '1') //Faire un versement
             Versement();
        if(choixAction == '2' )  //Faire un retrait
                Retrait();
        if(choixAction == '3')    //Consulter le solde
                Solde();
        if(choixAction == '5')  //Historique des opérations
                Historique();
        if(choixAction == '6')  //Modifier pwd
            ModifierPwd();
        if(choixAction == '7')  //Déconnexion
            LogOff();
}

///MENU COURANT
void MenuCC()
{
    do
    {
        system("cls");
        system("color 0e");
        printf("\n\t--------------------------------------------------------------------------------------------------------\n");
        printf("\n\t\t\t\t\tGESTION    DES    COMPTES    COURANTS   \n ");
        printf("\n\t--------------------------------------------------------------------------------------------------------\n");
        printf("\n\n\t\t\t\1741\174 : \tFaire un versement\n\n\t\t\t\1742\174 : \tFaire un retrait"
               "\n\n\t\t\t\1743\174 : \tConsulter son solde\n\n\t\t\t\1744\174 : \tD\202livrer un ch\212que\n\n\t\t\t\1745\174 : \tConsulter l'historique des op\202rations"
                  "\n\n\t\t\t\1746\174 : \tModifier mon mot de passe\n\n\t\t\t\1747\174 : \tSe d\202connecter\n");
        printf("\n\n\n\tQue voulez-vous faire \77 : ");
        scanf("%s", &choixAction);
        if(choixAction != '1' &&  choixAction != '2' && choixAction != '3' && choixAction != '4' && choixAction != '5' && choixAction != '6' && choixAction != '7'  )
                {
                    system("color 4f");
                    printf("\nVeuillez saisir un chiffre entre \1331-2-3-4-5-6-7\135 s'il vous pla\214t.\n\t");
                    system("pause");
                }
    }while(choixAction != '1' &&  choixAction != '2' && choixAction != '3' && choixAction != '4' && choixAction != '5' && choixAction != '6' && choixAction != '7');

        MenuSimple();
        if(choixAction == '4') //Faire un chèque
            BankCheck();

}  ///fin de MenuCC

void ConfirmPassWord()
{
    do
    {
        system("color 06");
        printf("\n\t\tEntrez votre mot de passe s'il vous pla\214t : ");
        scanf("%s", &theClient.Pwd);
        printf("\n\t\tVeuillez confirmer votre mot de passe s'il vous pla\214t : ");
        scanf("%s", &theClient.confPwd);

        if(strcmp(theClient.Pwd, theClient.confPwd) != 0)
        {
                system("color 4f");
                printf("\n\t\tLes mots de passe ne correspondent pas !! Veuillez recommencer.\n\n\t");
                system("pause");
        }
    }while(strcmp(theClient.Pwd, theClient.confPwd) != 0);

}

            //Argent d'inscription
void RegisterAmountCC()
{
  do
                {
                printf("\n\n\tVous devez d\202bourser une somme de 25 000 francs CFA pour l'ouverture de votre compte : ");
                scanf("%i", &theClient.MoneyRegister);
                if(theClient.MoneyRegister <25000)
                    printf("\n\n\tD\202sol\202.... %i francs CFA ne correspond pas \205 la somme demand\202e\n\n\t", theClient.MoneyRegister);
                }while(theClient.MoneyRegister < 25000);
        if(theClient.MoneyRegister == 25000)
            printf("\n\n\tMerci ! Passons \205 la suite \n\n\t");
        if(theClient.MoneyRegister > 25000)
        {
             printf("\n\n\tMerci ! Le reste de %i francs CFA sera ajout\202 \205 votre solde\n\n\t ", (theClient.MoneyRegister - 25000));
             theClient.SoldeActuel = theClient.SoldeActuel + (theClient.MoneyRegister - 25000);
        }
        system("pause");
}

void RegisterAmountCd_E()
{
  do
                {
                printf("\n\n\tVous devez d\202bourser une somme de 10 000 francs CFA pour l'ouverture de votre compte \n\t "
                            "et vous devez faire un d\202p\223t d'au moins 10 000 francs CFA pour d\202buter : ");
                scanf("%i", &theClient.MoneyRegister);
                if(theClient.MoneyRegister <=10000)
                    printf("\n\n\tD\202sol\202.... %i francs CFA ne correspond pas \205 la somme demand\202e\n\t", theClient.MoneyRegister);
                }while(theClient.MoneyRegister <= 10000);
                if(theClient.MoneyRegister == 20000)
                {
                    printf("\n\n\tMerci ! Les 10 000 francs CFA restants seront vers\202s sur votre compte! Passons \205 la suite \n\n\t");
                    theClient.SoldeActuel = theClient.SoldeActuel + (theClient.MoneyRegister - 10000);
                }
                if(theClient.MoneyRegister > 20000)
                {
                    printf("\n\n\tMerci ! Le reste de %i francs CFA sera ajout\202 \205 votre solde\n\n\t ", (theClient.MoneyRegister - 20000));
                    theClient.SoldeActuel = theClient.SoldeActuel + (theClient.MoneyRegister - 20000);
                }
        system("pause");
}

void Informations()
{
        printf("\n\n\tVeuillez entrer les informations suivantes s'il vous pla\214t : \n\n");
        printf("\t\tNom: "); scanf("%s", &theClient.Nom);
        printf("\n\t\tPr\202nom (veuillez \205 n'entrer qu'1 seul pr\202nom) : "); scanf("%s", &theClient.Prenoms);
         do{
                printf("\n\t\tSexe (M ou F): ");
                scanf("%s", &theClient.SexClient);
        }while(strcmp(theClient.SexClient, "M") != 0 && strcmp(theClient.SexClient, "F") != 0 );
        do
        {
          printf("\n\t\tEntrez un identifiant pour votre compte s'il vous pla\214t  (maximum 10 caract\212res)  : "); scanf("%s", &theClient.IDAccount);
          ficheExistOrNot = fopen(theClient.IDAccount, "r+");
          if(ficheExistOrNot != NULL) //it means that file already exists
          {
                printf("D\202sol\202....Cet identifiant existe d\202j\205 !\n\n\t");
                system("pause");
                fclose(ficheExistOrNot);
          }
        }while(ficheExistOrNot != NULL);
        printf("\n\t\tEntrez votre num\202ro de carte d'identit\202 : "); scanf("%s", &theClient.IDNumCard);
        ConfirmPassWord(); printf("\n\n\t");
        system("pause");
}

void affichInfos()
{
          printf("\n\n\t  Compte cr\202\202 le "); Day(); printf("\205"); Hour();
          printf("\n\n\t  Voici vos informations: \n");
            if(strcmp(theClient.SexClient, "F") == 0 )
                    printf("\n\t\tPropri\202taire du compte : Mme %s %s ", theClient.Nom, theClient.Prenoms);
            if(strcmp(theClient.SexClient, "M") == 0)
                        printf("\n\t\tPropri\202taire du compte : M. %s %s ", theClient.Nom, theClient.Prenoms);
        printf("\n\t\tIdentifiant du compte :  %s", theClient.IDAccount);
        printf("\n\t\tMot de passe :  %s \n\n\t  ", theClient.Pwd);
        system("pause ");

     //Ajout sur le fichier physique
        Client_Info = fopen(theClient.IDAccount , "a") ;                     //a = append
        fprintf(Client_Info, "\n\t\tNom : %s\n\t\tPrénom : %s\n\t\tAge : %i ans\n\t\tSexe : %s\n\t\tIdentifiant du compte : %s\n\t\tMot de passe : %s\n\t\tNuméro de carteID : %s"/*\n\t\tSolde Actuel : %.2f*/"\n\t\tFrais d'inscription : %i""\n\n\tCompte créé le %s %02u %s %04u",
                theClient.Nom, theClient.Prenoms, theClient.Age, theClient.SexClient, theClient.IDAccount, theClient.Pwd, theClient.IDNumCard, /*theClient.SoldeActuel,*/theClient.MoneyRegister, NomJourSemaine[date.tm_wday], date.tm_mday, NomMois[date.tm_mon], 1900 + date.tm_year);
        fclose(Client_Info);

}

void CreateAccount()
{
              do
                {
                    system("cls");
                    system("color f0");
                    printf("\n\n\t\t\t\t\t\t\tBonjour!\n");
                    printf("\t\t\t\t\t\tBienvenue \205 NIS'Bank!!\n\n");
                    printf("\n\n\n\tQuel \203ge avez-vous s'il vous pla\214t : ");
                    scanf("%d", &theClient.Age);
                    if(theClient.Age < 18)
                        {
                            system("color 4f");
                            printf("\n\tD\202sol\202... Vous n'avez pas l'\203ge requis pour utiliser ce programme.\n\tVeuillez recommencer\n\n");
                            system("pause");
                        }
                    else
                        {
                            system("color 2f");
                            printf("\n\tSuper! Vous avez %d ans ! Passons \205 l'\202tape suivante.\n\n", theClient.Age);
                            system("pause");
                        }
                }while(theClient.Age <18);  ///fin du contrôle de l'âge

            ///Créer un compte
        do
          {
            system("cls");
            system("color 06");
            printf("\n\t--------------------------------------------------------------------------------------------------------\n");
            printf("\n\t\t\t\t\t\t\tCREATION    DE    COMPTE   \n ");
            printf("\n\t--------------------------------------------------------------------------------------------------------\n");
            printf("\n\n   Nous mettons \205 votre disposition deux types de comptes que sont:\n\n"
            "\t\t1\176\176 Un compte courant:\n"
            "\tLes frais d\'entretien d\'un compte courant s\'\202l\212vent \205 15000 "
            "francs\n\tCFA par mois. Si votre solde est inf\202rieur \205 15000 francs CFA, le pr\202l\212vement des frais "
            "d\'entretien rendra\n\tvotre compte d\202biteur. L'ouverture du compte co\226te 25000 francs CFA et il n\'y a pas "
            "de montant minimal devant\n\tfigurer sur le compte. Vous ne b\202n\202ficiez d\'aucun int\202r\210t avec ce compte. "
            "N\202anmoins, vous disposerez d'un\n\tch\202quier permettant de r\202gler des paiements au profit d\'un "
            "tiers.\n\n"
            "\t\t2\176\176 Un compte d'\202pargne:\n"
            "\t\267 la diff\202rence d\'un compte courant, "
            "vous pouvez faire des\n\tretraits ou d\202p\223t d\'esp\212ce et m\210me effectuer vos paiements \205 "
            "l\'aide d'une carte magn\202tique. L'ouverture du\n"
            "\tcompte co\226te 10000 francs CFA et vous devez faire un d\202p\223t d\'au moins 10000 francs CFA pour d\202buter.Cette\n"
            "\tsomme est le montant minimal devant figurer sur le compte. En outre, garder une somme sur votre compte vous\n"
            "\tg\202n\212re des revenus \205 raison de 2,5 %% d\'int\202r\210t par an et aucun "
            "pr\202l\212vement de notre part n\'est op\202r\202 sur\n\tvotre compte.\n\n\n"
            "   Veuillez entrer 1 si vous voulez cr\202er un compte courant ou 2 pour un compte d'\202pargne : ");
            scanf("%s", &choixDeCompte);
            if(choixDeCompte != '1' && choixDeCompte != '2')
                {
                    system("color 4f");
                    printf("\nVeuillez saisir 1 ou 2 s'il vous pla\214t.\n\t");
                    system("pause");
                }
    }while(choixDeCompte != '1' && choixDeCompte != '2');

    ///Compte Courant
    if (choixDeCompte == '1')
    {
        system("cls");
        printf("\n\t--------------------------------------------------------------------------------------------------------\n");
        printf("\n\t\t\t\t\tCREATION    DE    COMPTE    COURANT   \n ");
        printf("\n\t--------------------------------------------------------------------------------------------------------\n");
        Informations();
        RegisterAmountCC();

        system("cls");
        printf("\n\t--------------------------------------------------------------------------------------------------------\n");
        printf("\n\t\t\t\t\tCOMPTE    COURANT    CR\220\220    AVEC    SUCC\324S    !!!!!!!!!!!!!\n ");
        printf("\n\t--------------------------------------------------------------------------------------------------------\n");

        //Ecriture sur le fichier physique
        Client_Info = fopen(theClient.IDAccount, "w");
        fprintf(Client_Info, "\n\tCOMPTE COURANT");
        fclose(Client_Info);
        affichInfos();

        do
        {
           MenuCC();
        }while(choixAction != '7');


    }  //fin de if(compte courant)

    if(choixDeCompte == '2')
    {
        system("cls");
        printf("\n\t--------------------------------------------------------------------------------------------------------\n");
        printf("\n\t\t\t\t\tCREATION    DE    COMPTE    D'  \220PARGNE   \n ");
        printf("\n\t--------------------------------------------------------------------------------------------------------\n");
        Informations();
        RegisterAmountCd_E();

        system("cls");
        printf("\n\t--------------------------------------------------------------------------------------------------------\n");
        printf("\n\t\t\t\t\tCOMPTE  D' \220PARGNE  CR\220\220    AVEC    SUCC\324S    !!!!!!!!!!!!!\n ");
        printf("\n\t--------------------------------------------------------------------------------------------------------\n");

         //Ecriture sur le fichier physique
        Client_Info = fopen(theClient.IDAccount, "w");
        fprintf(Client_Info, "\n\tCOMPTE EPARGNE");
        fclose(Client_Info);
        affichInfos();

        do
        {
           MenuCd_E();
        }while(choixAction != '7');

    }

} //fin de void CreateAccount()

    ///ACCEUIL
void MenuAcceuil()
{
        do
        {
        system("cls");
        system("color f0");
        printf("\n\t--------------------------------------------------------------------------------------------------------\n");
        printf("\n\t\t\t\t\t\t\tNIS'BANK\n ");
        printf("\n\t--------------------------------------------------------------------------------------------------------\n");
        printf("\n\n\t\t\t\1741\174 : \tCr\202er son compte\n\t\t\t\1742\174 : \tSe connecter \205 son compte"
                  "\n\t\t\t\1743\174 : \tRetour\n");
        printf("\n\n\n\tQue voulez-vous faire \77 : ");
        scanf("%s", &choix);
        if(choix != '1' && choix != '2' && choix != '3')
        {
            system("color 4f");
            printf("\nVeuillez saisir 1, 2 ou 3 s'il vous pla\214t.\n\t");
            system("pause");
        }
        }while(choix != '1'&& choix != '2' && choix != '3');

         if (choix == '1')
           CreateAccount();
         if (choix == '2')
           LogIn();
         if (choix == '3')
           Retour();
}

    ///MENU EPARGNE
void MenuCd_E()
{
     do
    {
        system("cls");
        system("color 0e");
        printf("\n\t--------------------------------------------------------------------------------------------------------\n");
        printf("\n\t\t\t\t\tGESTION    DES    COMPTES   D ' \220PARGNE   \n ");
        printf("\n\t--------------------------------------------------------------------------------------------------------\n");
        printf("\n\n\t\t\t\1741\174 : \tFaire un versement\n\n\t\t\t\1742\174 : \tFaire un retrait"
                  "\n\n\t\t\t\1743\174 : \tConsulter son solde\n\n\t\t\t\1744\174 : \tTaux d'int\202r\210t\n\n\t\t\t\1745\174 : \tConsulter l'historique des op\202rations"
                  "\n\n\t\t\t\1746\174 : \tModifier mon mot de passe\n\n\t\t\t\1747\174 : \tSe d\202connecter\n");
        printf("\n\n\n\tQue voulez-vous faire \77 : ");
        scanf("%s", &choixAction);
        if(choixAction != '1' &&  choixAction != '2' && choixAction != '3' && choixAction != '4' && choixAction != '5' && choixAction != '6' && choixAction != '7'  )
                {
                    system("color 4f");
                    printf("\nVeuillez saisir un chiffre entre \1331-2-3-4-5-6-7\135 s'il vous pla\214t.\n\t");
                    system("pause");
                }
    }while(choixAction != '1' &&  choixAction != '2' && choixAction != '3' && choixAction != '4' && choixAction != '5' && choixAction != '6' && choixAction != '7');

    MenuSimple();
    if(choixAction == '4') //Voir le taux d'intérêt
                Interet();
}

void afficheque( char* sexeTiersToShow,char* sexeToShow, int MoneyCheck,  char* NomTiers,  char* PrenomsTiers, char* Nom,  char* Prenoms)
{
    time(&temps);
    date = *localtime(&temps);
    system("color 8f");
              printf("\n\tTenez. Remettez lui ce ch\212que.\n\n"
            "\t\t_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n"
            "\t       |\t\t\t\t\tNIS'Bank\t\t\t\t |\n\n"
            "\t       |\t\t\t\t\t\t\t\t\t\t |\n"
            "\t\t Retirez contre ce ch\212que la somme\t\t\t\t  fait \205 Abidjan\n"
            "\t       |\t\t\t\t\t\t\t\t\t\t |\n"
            "\t\t de %i francs CFA.\t\t\t\t\t\t   le %02u/%02u/%04u\n"
            "\t       |\t\t\t\t\t\t\t\t\t\t |\n\n"
            "\t       |\t\t\t\t\t\t\t\t\t\t |\n"
            "\t\t \205 %s %s %s\n"
            "\t       |\t\t\t\t\t\t\t\t\t\t |\n\n"
            "\t       |\t\t\t\t\t\t\t\t\t\t |\n"
            "\t\t Payable en C\223te d\'ivoire et dans toute la CEDEAO.\n"
            "\t       |\t\t\t\t\t\t\t\t\t\t |\n"
            "\t\t T\202l\202phone: +225 65 66 45 46\t\t\t\t %s %s %s \n"
            "\t       |\t\t\t\t\t\t\t\t\t\t |\n"
            "\t\t\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356"
            "\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356"
            "\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356\356"
            "\356\356\356\356\356\356\n\n", MoneyCheck,date.tm_mday, date.tm_mon+1, 1900 + date.tm_year, sexeTiersToShow, NomTiers, PrenomsTiers, sexeToShow, Nom,
            Prenoms);
            printf("\n\n\t");
}

void Retour()
{
                system("cls");
                system("color 0f");
                printf("\n\t--------------------------------------------------------------------------------------------------------\n");
                printf("\n\t\t\t\tMERCI      D'    AVOIR      UTILIS\220      NOTRE       PROGRAMME !!!  \n ");
                printf("\n\t--------------------------------------------------------------------------------------------------------\n");
                printf("\n\n\t  Passez\tune\texcellente\tjourn\202e\t\tet\t\205\tbient\223t !!!!! \n\n");
                printf("\n\n\n");
}

void LogIn()
{
    system("cls"); system("color 06");
    printf("\n\n\tVeuillez entrer l'identifiant de votre compte s'il vous pla\214t : ");
    scanf("%s", &theClient.IDAccount);
    ficheExistOrNot = fopen(theClient.IDAccount, "r+");

          if(ficheExistOrNot != NULL) //it means that file already exists
          {
              printf("\n\n\tVeuillez entrer votre mot de passe s'il vous pla\214t : ");
              scanf("%s", &theClient.Pwd);

               //Récupérer le mot de passe
              int position = positionPass();
              fgets(motDePasse,TAILLE_PassWorD_MAX,ficheExistOrNot);// on se trouve à la fin de PassWord
              int pwdlen = strlen(motDePasse);


               //Comparaison entre mot de passe saisi et mot de passe stocké
               if(strncmp(motDePasse, theClient.Pwd, pwdlen-1) == 0)
               {
                   system("color 2f");
                   printf("\n\n\tSuper !!! Vous \210tes connect\202 !!\n\n\t");
                   system("pause"); system("cls");

                   //Récupérer le genre du client (M ou F)
                    RecupNomPrenomGenre();
                    Loading();
                    RecupCompte();

               }

        else
            {
                   char oubliPwd;
                   do
                   {
                       system("cls"); system("color 04");
                       printf("\n\n\tD\202sol\202... Ce mot de passe ne figure pas dans notre base de donn\202es !!");
                       printf("\n\n\tVeuillez taper a/A pour retourner \205 l'acceuil  ou b/B si vous avez oubli\202 votre mot de passe : ");
                       scanf("%s", &oubliPwd);
                       if( oubliPwd != 'a' && oubliPwd != 'A' && oubliPwd != 'b' && oubliPwd != 'B' )
                       {
                          system("color 4f");
                          printf("\n\t\tVeuillez saisir a/A ou b/B s'il vous pla\214t.\n\n\t\t");
                          system("pause");
                       }
                   }while( oubliPwd != 'a'&& oubliPwd != 'A' && oubliPwd != 'b' && oubliPwd != 'B' );

                   if ( oubliPwd == 'a' || oubliPwd == 'A' )
                   {
                       printf("\n\t======== Retour \205 l'acceuil =======\n\n\t");
                       system("pause");
                       MenuAcceuil();
                   }

                   if ( oubliPwd == 'b'|| oubliPwd == 'B' )
                   {
                        system("color 06");
                        printf("\n\n\tVeuillez entrer le num\202ro de votre carte d'identit\202 s'il vous pla\214t : ");
                        scanf("%s", &theClient.IDNumCard);

                         //Récupérer l'IDNumCard
              position = ftell(ficheExistOrNot); // on se trouve à la fin de PassWord
              fseek(ficheExistOrNot, position+1, SEEK_SET); // On est sur la ligne de ID
              fgets(tempor, 22, ficheExistOrNot);
              position = ftell(ficheExistOrNot); //début de IDNumCard
              fgets(numCNI, TAILLE_IDNumCard_MAX, ficheExistOrNot);
              numlen = strlen(numCNI);


               //Comparaison entre IDNumCard saisi et IDNumCard stocké
               if(strncmp(numCNI, theClient.IDNumCard, numlen-1) != 0 )
               {
                    printf("\n\n\t\tNum\202ro de carte incorrect !!! Retour au menu principal\n\n\t\t");
                    system("pause");
                    MenuAcceuil();
               }

               if(strncmp(numCNI, theClient.IDNumCard, numlen-1) == 0)
               {
                   system("color 2f");
                   printf("\n\n\tSuper !!! Vous \210tes connect\202 !!\n\n\t");
                   position = positionPass();
                   fgets(motDePasse,TAILLE_PassWorD_MAX,ficheExistOrNot);
                   printf("Votre mot de passe est : %s \n\n\t\t ", motDePasse);
                   system("pause"); system("cls");

                   //Récupérer les infos du client (nom, prénom, genre)
                    RecupNomPrenomGenre();

                    //On ferme le fichier
                    fclose(ficheExistOrNot);

                    Loading();
                    RecupCompte();

               }
                   } //fin de oubliPwd == b ou B
            } //fin du else (motDePasse incorrect)


             //Récupérer le solde actuel aussi SI POSSIBLE !!!!
          }

          else
          {
              system("cls"); system("color 04");
              printf("\n\n\tD\202sol\202... Cet identifiant ne figure pas dans notre base de donn\202es !!\n");
              printf("\n\t======== Retour \205 l'acceuil =======\n\n\t");
              system("pause");
              MenuAcceuil();
          }
}  //fin de LogIn()

void RecupCompte()
 {
     //Récupérer le type de compte ("COURANT" ou "EPARGNE" ) dans le fichier
      rewind(ficheExistOrNot); // on se positionne en début de fichier
      fseek(ficheExistOrNot, 3, 0);
      fgets(typeDeCompte, 15 ,ficheExistOrNot);

    //Afficher et parcourir le menu soit COURANT soit EPARGNE
  if(strcmp(KindAccount[i], typeDeCompte) == 0)
    {
     do
       {
           MenuCC();
       }while(choixAction != '7');
    }

  if(strcmp(KindAccount[j], typeDeCompte) == 0)
    {
      do
        {
            MenuCd_E();
        }while(choixAction != '7');
    }
 }

int positionPass()
{

               rewind(ficheExistOrNot); // on se positionne en début de fichier

               fseek(ficheExistOrNot, 27, SEEK_SET);
               fgets(tempor,TAILLE_NOM_MAX,ficheExistOrNot);
               int position = ftell(ficheExistOrNot); // On se trouve à la fin de nom

               fseek(ficheExistOrNot, position+1, SEEK_SET);// On se trouve sur la ligne de Prénom
               fgets(tempor, 10, ficheExistOrNot);
               position = ftell(ficheExistOrNot);
               fgets(tempor, TAILLE_PRENOM_MAX, ficheExistOrNot);
               position = ftell(ficheExistOrNot); //Normalement on doit être à la fin  de prénom

               fseek(ficheExistOrNot, position+1, SEEK_SET); // On est sur la ligne de Age
               fgets(tempor, 8, ficheExistOrNot);
               position = ftell(ficheExistOrNot);
               fgets(tempor, 8, ficheExistOrNot);// on se trouve à la fin de Age
               position = ftell(ficheExistOrNot);

               fseek(ficheExistOrNot, position+1, SEEK_SET); // On se trouve sur la ligne de sexe
               fgets(tempor, 11, ficheExistOrNot);
               position = ftell(ficheExistOrNot);   //on est à la fin de sexe

               fseek(ficheExistOrNot, position+1, SEEK_SET); // On est sur la ligne de Identifiant
               fgets(tempor, 26, ficheExistOrNot);
               position = ftell(ficheExistOrNot);
               fgets(tempor, TAILLE_ID_MAX, ficheExistOrNot);// on se trouve à la fin de Identifiant
               position = ftell(ficheExistOrNot);

               fseek(ficheExistOrNot,position+1,SEEK_SET); // On se trouve sur la ligne de pwd
               fgets(tempor,17,ficheExistOrNot);  //début de pwd
               position = ftell(ficheExistOrNot);

                 return position;
}
void RecupNomPrenomGenre()
{
     int namelen, surnamelen;
               rewind(ficheExistOrNot); // on se positionne en début de fichier
               fseek(ficheExistOrNot, 27, SEEK_SET);
               fgets(temporNom,TAILLE_NOM_MAX,ficheExistOrNot);
               namelen = strlen(temporNom);
               strncpy(theClient.Nom, temporNom, namelen-1);
               int position = ftell(ficheExistOrNot); // On se trouve à la fin de nom

               fseek(ficheExistOrNot, position+1, SEEK_SET);// On se trouve sur la ligne de Prénom
               fgets(temporPrenom, 11, ficheExistOrNot);
               position = ftell(ficheExistOrNot);
               fgets(temporPrenom, TAILLE_PRENOM_MAX, ficheExistOrNot);
               surnamelen = strlen(temporPrenom);
               strncpy(theClient.Prenoms, temporPrenom, surnamelen-1);
               position = ftell(ficheExistOrNot); //Normalement on doit être à la fin  de prénom

               fseek(ficheExistOrNot, position+1, SEEK_SET); // On est sur la ligne de Age
               fgets(tempor, 8, ficheExistOrNot);
               position = ftell(ficheExistOrNot);
               fgets(tempor, 8, ficheExistOrNot);// on se trouve à la fin de Age
               position = ftell(ficheExistOrNot);

               fseek(ficheExistOrNot, position+1, SEEK_SET); // On se trouve sur la ligne de sexe
               fgets(tempor, 9, ficheExistOrNot);
               position = ftell(ficheExistOrNot);   //début de sexe
               fgets(theClient.SexClient, 2, ficheExistOrNot);
               position = ftell(ficheExistOrNot);  //fin de sexe normally

}

#endif // PROJETDEBANK_FONCTION_H_INCLUDED
