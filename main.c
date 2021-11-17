#include <stdio.h>
#include <stdlib.h>
#include "mesfonctions.h"


int main() {
    int choix=0,i=0;
    int nbJoueurs=0;
    Joueur* listeJoueurs;
    Case* cases;

    printf("|=***************************************=|\n"
           "|==========| MONOPOLY-ECE-2021 |==========|\n"
           "|=***************************************=|\n\n");

    do {
        menuPrincipal();
        scanf("%d",&choix);
        //char flush;
        //scanf("%c", &flush);


        switch(choix) {
            case 1 :
                //Lancer une nouvelle partie.

                printf("Lancement nouvelle partie...\n");

                //Initialisation du plateau de jeu.
                printf("Initialisation du plateau de jeu....\n");
                cases = initPlateau(cases);

                //Initialisation des joueurs.
                listeJoueurs = initJoueur(&nbJoueurs);

                affichagePlateau(listeJoueurs,&nbJoueurs); //ct un test







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
                //Quitter.
                quitter();
                break;

            default : {
                printf("Choix invalide !\n\n");
                break;
            }
        }
    }while(choix != 6);


    return 0;
}
