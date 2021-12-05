//
// Created by Thomas on 02/11/2021.
//

#include <stdio.h>
#include <stdbool.h>

#ifndef PROJET_MONOPOLY_MESFONCTIONS_H
#define PROJET_MONOPOLY_MESFONCTIONS_H

//Structure CASE, renseigne les informations de la propriété ciblée.
typedef struct{
    char* nomCase;          //Nom de la case.
    int typeCase;           //1 si case propriété / 2 case carte communauté / 3 carte chance / 0 sinon


    int groupe;             //Groupe auquel elle appartient (1 à 8).
    int prix;               //Prix de la propriété.
    char* proprio;          //Nom du joueur qui possèderait cette propriété.
    int loyerMaisons[4];    //Loyer en fonction du nb de maison sur la propriété
    int nbMaisons;          //nbMaisons acheté sur la propriété. 0 à 4

    int loyerHotel;         //Loyer hotel
    int nbHotel;            //nbHotel acheté sur la propriété. 0 ou 1

    bool hypotheque;        //true / false

} Case;

//Structure Joueur, renseigne les informations du joueur ciblé.
typedef struct{
    char* nomJoueur;        //Nom du Joueur.
    int money;              //Argent que le joueur possède au cours de la partie. (valeur toujours positive)
    int position;           //position du joueur sur le plateau (1 à 32).
    int prison;             //1 VRAI 0 FAUX.
    int tourEnPrison;       //Max 3 tours en prison. Après il est libéré.
    int nbCSP;              //nombre de cartes sortie de prison que le joueur possède 0,1 ou 2.

    int prop;               //Nombre de prop (non hypothéqué) que possède le joueur
    int maisons;            //Nombre de maisons du joueur
    int hotel;              //Nombre d'hôtels du joueur

    bool faillite;          //false par défaut.
} Joueur;

//Structure Banque.
typedef struct{
    int maison;             //nb de maisons que possède la banque ( 32 )
    int hotel;              //nb d'hôtels que possède la banque   ( 12 )
}Banque;



void menuPrincipal();

void sauvegarder(int* nbJoueurs, Joueur* listeJoueurs, Case* cases, char** listeCartesChance, char** listeCartesComm, int* nbCarteC,int* nbCarteComm,Banque* banque);

void verifArgent(Joueur* listeJoueurs,int i,int aSoustraire);
void supprimerJoueur(Joueur* listeJoueurs, int i,int* nbJoueurs);
void menuJoueur();

int verifChoix();

int lancerLesDes(int* nbDoubles,int* lanceDeDes);
int nouvellePosition(int actuelle, int sommeDes);

Joueur* initJoueur(int* nbJoueurs);

void nouvellePartie(int* nbJoueurs, Joueur* listeJoueurs, Case* cases, char** listeCartesChance, char** listeCartesComm, int* nbCarteC,int*  nbCarteComm, Banque* banque);

void afficherNomsEquipeProjet();





#endif //PROJET_MONOPOLY_MESFONCTIONS_H

