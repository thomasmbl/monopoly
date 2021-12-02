#include <stdio.h>
#include <stdlib.h>
#include "mesfonctions.h"
#include "cartes.h"
#include "plateau.h"
#include <windows.h>


int main() {
    //Initialisation des variables.
    int choix=0,i=0;
    int nbJoueurs=0;
    Joueur* listeJoueurs;
    Case* cases;
    char* listeCartesChance[10];
    char* listeCartesComm[10];
    int nbCarteC = 10, nbCarteComm = 10;
    Banque banque = {32,12};

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Je m'amuse avec les couleurs.....
    SetConsoleTextAttribute(hConsole,14);
    printf("|=*************************************************************=|\n"
           "|=====================| ");

    SetConsoleTextAttribute(hConsole,10);
    printf("MONOPOLY");
    SetConsoleTextAttribute(hConsole,14);
    printf("-");
    SetConsoleTextAttribute(hConsole,10);
    printf("ECE");
    SetConsoleTextAttribute(hConsole,14);
    printf("-");
    SetConsoleTextAttribute(hConsole,10);
    printf("2021");

    SetConsoleTextAttribute(hConsole,14);
    printf(                                          " |=====================|\n"
           "|=*************************************************************=|\n\n");
    SetConsoleTextAttribute(hConsole,7);


    do {
        SetConsoleTextAttribute(hConsole,5);
        menuPrincipal();
        SetConsoleTextAttribute(hConsole,7);

        choix = verifChoix();      //On vérifie que choix est bien un entier.

        switch(choix) {
            case 1 :
                //Lancer une nouvelle partie.
                SetConsoleTextAttribute(hConsole,0);
                printf("Lancement nouvelle partie...\n");

                //Initialisation du plateau de jeu.
                printf("Initialisation du plateau de jeu....\n");
                SetConsoleTextAttribute(hConsole,7);
                cases = initPlateau(cases);

                //Initialisation des piles de cartes chance et communauté.
                initCarteChance(listeCartesChance);
                initCarteCommunaute(listeCartesComm);

                //Initialisation des joueurs.
                listeJoueurs = initJoueur(&nbJoueurs);

                //Lancement de la nouvelle partie.
                nouvellePartie(&nbJoueurs,listeJoueurs,cases,listeCartesChance,listeCartesComm,&nbCarteC,&nbCarteComm,&banque);

                break;

            case 2 :
                //Sauvegarder la partie en cours.
                break;

            case 3 :
                //Charger une ancienne partie.
                //                       Faire passer la variable tour en paramètre via un pointeur.
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