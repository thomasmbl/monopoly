//
// Created by Thomas on 02/11/2021.
//

#include <stdio.h>

#ifndef PROJET_MONOPOLY_MESFONCTIONS_H
#define PROJET_MONOPOLY_MESFONCTIONS_H

//Structure Propriétée, renseigne les informations de la propriétée ciblée.
typedef struct{
    char nomPropriete[30];  //Nom de la propriétée.
    int groupe;             //Groupe auquelle elle appartient (1 à 8).
    int position;           //Sa position sur la plateau (sa case).
    int prix;               //Prix de la propriétée.
    char proprio[30];       //Nom du joueur qui possèderait cette propriétée.
} Propriete;

//Structure Joueur, renseigne les informations du joueur ciblé.
typedef struct{
    char* nomJoueur;        //Nom du Joueur.
    int idJoueur;           //ID qui sert d'ordre de passage (ex Joueur1, Joueur2 etc... ).
    int money;              //Argent que le joueur possède au cours de la partie. ( valeur toujours positive )
    int position;           //position du joueur sur le plateau (case 1 à 32).
    int de1;                //Valeur du dé 1 au dernier lancé.
    int de2;                //Valeur du dé 2 au dernier lancé.
    int SerieDouble;        //Compte les séries de double.
} Joueur;


int menuPrincipal();

Joueur* nouvellePartie(int* nbJoueurs);



void afficherNomsEquipeProjet();

void quitter();




#endif //PROJET_MONOPOLY_MESFONCTIONS_H

/* idée de groupe...
 * TAVERNY
 * VLF/MER
 * DJIBOUTI
 * LUCENAY
 * LE PLESSIS ROBINSON
 * BANDOL
 * TOULON
 * LYON
 */
