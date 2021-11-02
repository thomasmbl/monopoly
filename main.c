#include <stdio.h>
#include <stdlib.h>
#include "mesfonctions.h"


int main() {
    printf("==========| MONOPOLY-ECE-2021 |==========\n");
    int choix=0;

    do {
        printf("=====| Que souhaitez vous faire ? |=====\n");
        printf("1/ Lancer une nouvelle partie.\n"
               "2/ Sauvegarder la partie en cours.\n"
               "3/ Charger une ancienne partie.\n"
               "4/ Afficher les regles.\n"
               "5/ Afficher le nom des membres de l'equipe du projet.\n"
               "6/ Quitter.\n>\n");
        scanf("%d",&choix);
        switch(choix) {
            case 1 :
                //Lancer une nouvelle partie.
                nouvellePartie();
                break;

            case 2 :
                //Sauvegarder la partie en cours.
                break;

            case 3 :
                //Charger une ancienne partie.
                break;

            case 4 :
                //Afficher les regles.
                break;

            case 5 :
                //Afficher le nom des membres de l'équipe du projet.
                afficherNomsEquipeProjet();
                break;

            case 6 :
                quitter();
                break;

            default : {
                printf("Choix invalide\n>");
                break;
            }
        }
    }while(choix != 6);









    return 0;
}
