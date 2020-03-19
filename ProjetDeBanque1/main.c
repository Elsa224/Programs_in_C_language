#include "libDeBase.h"
#include "ProjetDeBank_Fonction.h"

//Prototypes des fonctions
    void CreateAccount();
    void MenuAcceuil();
    void MenuCC();
    void MenuCd_E();
    void MenuSimple();
    void showTimeOp();

    void Versement();                   //MENU
    void Retrait();
    void Solde();
    void BankCheck();
    void afficheque();
    void Interet();
    void Historique();
    void LogOff();
    void LogIn();                         //FinMENU

    void RegisterAmountCC();
    void RegisterAmountCd_E();
    void Informations();
    void affichInfos();
    void ConfirmPassWord();
    void RecupCompte();
    void RecupNomPrenomGenre();
     int positionPass();

//Nom du fichier
        FILE* Client_Info ;

int main()
{

    if(SommeARetirer > theClient.SoldeActuel || SommeARetirer == theClient.SoldeActuel || SommeAVerser < 0 || theClient.SoldeActuel <= 0 || SommeARetirer < 0)
            theClient.SoldeActuel = theClient.SoldeActuel ;
    Hello();

    return 0;
}

void Retrait()
{
    Loading();
    system("cls");
    system("color 0b");
    printf("\n\t--------------------------------------------------------------------------------------------------------\n");
    printf("\n\t\t\t\t\tGESTION        DES        RETRAITS       \n ");
    printf("\n\t--------------------------------------------------------------------------------------------------------\n");
    printf("\n\n\t");
    system("pause");
    printf("\n\n\t\tOp\202ration du  : "); Day(); printf("\n\n");
    printf("\t\tVotre solde actuel est de :     %.0f FCFA\n\n", theClient.SoldeActuel);
    printf("\n\n\tVeuillez entrer la somme que vous souhaitez retirer de votre compte s'il vous pla\214t : "); scanf("%f", &SommeARetirer);
    printf("\n\n\t");
    system("pause");

                ///SAVE OPERATIONS
                strcpy(tempo.typeOp, "Retrait" ) ;
                tempo.montantOp = SommeARetirer ;
                showTimeOp();

                if (SommeARetirer > 0 && SommeARetirer < theClient.SoldeActuel)
                    {
                         system("color 2f");
                         printf("\n\n\44\44\44\44\44\44\44\44\44\44 Yaaayyyyee!!! Retrait des %2.f francs CFA r\202ussi !!!! "
                                   "\44\44\44\44\44\44\44\44\44\44", SommeARetirer);
                         printf("\n\n\44\44\44\44\44\44\44\44\44\44 NOUVEAU SOLDE  :    %2.f  FCFA "
                                   "\44\44\44\44\44\44\44\44\44\44", theClient.SoldeActuel-SommeARetirer);
                                   printf("\n\n\t");
                                   system("pause");
                    }

            if(SommeARetirer < 0 || SommeARetirer > theClient.SoldeActuel)
                {
                    do
                                {
                    system("color 4f");
                    printf("\n\n\t\t---ERREUR--- : Solde insuffisant pour cette op\202ration     !!!!!\n\n\t\t");
                    system("pause");
                    printf("\n\tVeuillez entrer 1 ou 2 pour recommencer : "); scanf("%d", &continuerOuPas);
                    if(continuerOuPas <=0 || continuerOuPas >= 3  )
                        {
                            system("color 4f");
                            printf("\nVeuillez saisir 1 ou 2 s'il vous pla\214t.\n");
                            system("pause");
                        }

                    }while(continuerOuPas <=0 || continuerOuPas >= 3 );
                    if(continuerOuPas == 1 || continuerOuPas == 2)
                            {
                                printf("\n\n\tRetour au menu principal !!\n\t");
                                printf("\n\n\t");
                                system("pause");
                            }

                }

                    //Cas où la somme à retirer est > Solde Actuel
                    if(SommeAVerser > 0 ||  SommeARetirer < theClient.SoldeActuel)
                theClient.SoldeActuel = theClient.SoldeActuel - SommeARetirer ;

                    else if (SommeARetirer == theClient.SoldeActuel )
                    {
                        do
                        {
                         system("cls");
                         system("color 4f");
                         printf("\n\t--------------------------------------------------------------------------------------------------------\n");
                         printf("\n\t\t\t\t\tGESTION        DES        RETRAITS       \n ");
                         printf("\n\t--------------------------------------------------------------------------------------------------------\n");
                         printf("\n\n\t");
                         system("pause");
                         printf("\n\n\t\t---ERREUR--- : \267 moins que vous ne veuillez fermer votre compte, vous ne pouvez retirer"
                                   " la totalit\202 de votre compte\n\n\t\tVoulez-vous fermer votre compte \77 : \n\t\t\t1. Oui\n\t\t\t2. Non\n\t");
                        scanf("%d", &closeAccount);
                        if(closeAccount<=0 || closeAccount>=4)
                        {
                             printf("\nVeuillez saisir 1, 2 ou 3 s'il vous pla\214t.\n");
                             system("pause");
                        }
                        }while(closeAccount<=0 || closeAccount>=3);

                        if(closeAccount == 1)
                        {
                            system("cls");
                            system("color 06");
                            printf("\n\t--------------------------------------------------------------------------------------------------------\n");
                            printf("\n\t\t\t\t\tFERMETURE       DE      COMPTE         \n ");
                            printf("\n\t--------------------------------------------------------------------------------------------------------\n");
                            printf("\n\t\tPour la fermeture du compte, veuillez passer au guichet n\370 s'il vous pla\214t\n\n");
                            printf("\n\n\t");
                            system("pause");
                        }
                        if(closeAccount == 2)
                        {
                            printf("\n\nRetour au menu principal !!\n\t");
                            printf("\n\n\t");
                            system("pause");
                        }

                    } //fin du elseif.
}
