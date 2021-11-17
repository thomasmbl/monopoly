//
// Created by Thomas on 02/11/2021.
//

#include <stdio.h>

#ifndef PROJET_MONOPOLY_MESFONCTIONS_H
#define PROJET_MONOPOLY_MESFONCTIONS_H

//Structure CASE, renseigne les informations de la propriétée ciblée.
typedef struct{
    char* nomCase;          //Nom de la case.
    int typeCase;           // 1 si case propriete 0 sinon.

    int groupe;             //Groupe auquelle elle appartient (1 à 8).
    int prix;               //Prix de la propriétée.
    char* proprio;          //Nom du joueur qui possèderait cette propriétée.
} Case;



//Structure Joueur, renseigne les informations du joueur ciblé.
typedef struct{
    char* nomJoueur;        //Nom du Joueur.
    int money;              //Argent que le joueur possède au cours de la partie. ( valeur toujours positive )
    int position;           //position du joueur sur le plateau (case 1 à 32).
    int de1;                //Valeur du dé 1 au dernier lancé.
    int de2;                //Valeur du dé 2 au dernier lancé.
    int SerieDouble;        //Compte les séries de double.
} Joueur;


void menuPrincipal();



Case* initPlateau(Case* cases);
Joueur* initJoueur(int* nbJoueurs);
void affichagePlateau(Joueur* listeJoueurs,int* nbJoueurs);


void nouvellePartie(int* nbJoueurs, Case* cases);









void afficherNomsEquipeProjet();

void quitter();




#endif //PROJET_MONOPOLY_MESFONCTIONS_H


