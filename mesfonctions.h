//
// Created by Thomas on 02/11/2021.
//

#include <stdio.h>

#ifndef PROJET_MONOPOLY_MESFONCTIONS_H
#define PROJET_MONOPOLY_MESFONCTIONS_H

void menuPrincipal();
void nouvellePartie();



void afficherNomsEquipeProjet();
void quitter();

typedef struct{
    char nomJoueur[100];    //Nom du Joueur.
    int idJoueur;           //ID qui sert d'ordre de passage (ex Joueur1, Joueur2 etc... ).
    int money;              //Argent que le joueur possède au cours de la partie.
    int position;           //position du joueur sur le plateau (case 1 à 32).
    int de1;                //Valeur du dé 1 au dernier lancé.
    int de2;                //Valeur du dé 2 au dernier lancé.
    int SerieDouble;        //Compte les séries de double.
} Joueur;

void creationJoueur();

#endif //PROJET_MONOPOLY_MESFONCTIONS_H
