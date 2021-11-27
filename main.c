#include <stdio.h>
#include <stdlib.h>
#include "mesfonctions.h"

int main() {
    int choix=0,i=0;
    int nbJoueurs=0;
    Joueur* listeJoueurs;
    Case* cases;

    CChance* listeCartesChance;
    CCommunaute* listeCartesComm;
    int nbCChance = 10;
    int nbCComm = 10;

    printf("|=*************************************************************=|\n"
           "|=====================| MONOPOLY-ECE-2021 |=====================|\n"
           "|=*************************************************************=|\n\n");
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
//Initialisation des piles de cartes chance et communauté.
                listeCartesChance = initCarteChance(listeCartesChance);
                listeCartesComm = initCarteCommunaute(listeCartesComm);
//Initialisation des joueurs.
                listeJoueurs = initJoueur(&nbJoueurs);
//Lancement de la nouvelle partie.
                nouvellePartie(&nbJoueurs,listeJoueurs,cases,listeCartesChance,listeCartesComm,&nbCChance,&nbCComm);
                break;
            case 2 :
//Sauvegarder la partie en cours.
                break;
            case 3 :
//Charger une ancienne partie.
// Faire passer la variable tour en paramètre via un pointeur.
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
