#include <stdio.h>
#include <stdbool.h>
#define repeat(nb) for (int _loop = 1, _max = (nb); _loop <= _max; _loop++)

int nbPersonnes;

int main()
{
    //Saisie du nombre de personnes à considérer
    scanf("%d", &nbPersonnes);

    //Vérification des critères pour chaque personne
    repeat(nbPersonnes)
    {
        int taille, age, poids, cheval, brun;
        scanf("%d", &taille);
        scanf("%d", &age);
        scanf("%d", &poids);
        scanf("%d", &cheval);
        scanf("%d", &brun);

        bool espionTaille = (178 <= taille && taille <= 182);
        bool espionAge = (age >= 34);
        bool espionPoids = (poids < 70);
        bool espionBrun = (brun == 1);
        bool espionCheval = (cheval != 1);

        if (espionTaille && espionAge && espionPoids && espionCheval && espionBrun)
        {
            printf("Très probable\n");
        }
        else if ((espionTaille && espionAge && espionPoids && espionCheval && !espionBrun) ||
                 (espionTaille && espionAge && espionPoids && !espionCheval && espionBrun) ||
                 (espionTaille && espionAge && !espionPoids && espionCheval && espionBrun) ||
                 (espionTaille && !espionAge && espionPoids && espionCheval && espionBrun) ||
                 (!espionTaille && espionAge && espionPoids && espionCheval && espionBrun) ||
                 (espionTaille && espionAge && espionPoids && !espionCheval && !espionBrun) ||
                 (espionTaille && espionAge && !espionPoids && espionCheval && !espionBrun) ||
                 (espionTaille && !espionAge && espionPoids && espionCheval && !espionBrun) ||
                 (!espionTaille && espionAge && espionPoids && espionCheval && !espionBrun) ||
                 (espionTaille && espionAge && !espionPoids && !espionCheval && espionBrun) ||
                 (espionTaille && !espionAge && espionPoids && !espionCheval && espionBrun) ||
                 (!espionTaille && espionAge && espionPoids && !espionCheval && espionBrun) ||
                 (espionTaille && !espionAge && !espionPoids && espionCheval && espionBrun) ||
                 (!espionTaille && espionAge && !espionPoids && espionCheval && espionBrun) ||
                 (!espionTaille && !espionAge && espionPoids && espionCheval && espionBrun))
        {
            printf("Probable\n");
        }
        else if (!espionTaille && !espionAge && !espionPoids && !espionCheval && !espionBrun)
        {
            printf("Impossible\n");
        }
        else
        {
            printf("Peu probable\n");
        }
    }
}

/*
Leur correction

#define repeat(nb) for(int _loop = 1, _max = (nb) ; _loop <= _max ; _loop++)
#include <stdio.h>
int main()
{
   int nbPersonnes;
   scanf("%d", &nbPersonnes);
   repeat(nbPersonnes)
   {
      int nbCriteres = 0;
      int taille, age, poids, aCheval, aLesCheveuxBruns;
      scanf("%d", &taille);
      if((178 <= taille) && (taille <= 182))
      {
         nbCriteres = nbCriteres + 1;
      }
      scanf("%d", &age);
      if(age >= 34)
      {
         nbCriteres = nbCriteres + 1;
      }
      scanf("%d", &poids);
      if(poids < 70)
      {
         nbCriteres = nbCriteres + 1;
      }
      scanf("%d", &aCheval);
      if(aCheval == 0)
      {
         nbCriteres = nbCriteres + 1;
      }
      scanf("%d", &aLesCheveuxBruns);
      if(aLesCheveuxBruns == 1)
      {
         nbCriteres = nbCriteres + 1;
      }
       
      if(nbCriteres == 0)
      {
         printf("Impossible\n");
      }
      else if(nbCriteres == 5)
      {
         printf("Très probable\n");
      }
      else if(nbCriteres >= 3)
      {
         printf("Probable\n");
      }
      else
      {
         printf("Peu probable\n");
      }
   }
}
*/