//
// Created by thoma on 24/11/2021.
//

#ifndef MONOPOLY_MESFONCTIONS_H
#define MONOPOLY_MESFONCTIONS_H

//Structure CASE, renseigne les informations de la propriété ciblée.
typedef struct{
    char* nomCase;          //Nom de la case.
    int typeCase;           //1 si case propriété / 2 case carte communauté / 3 carte chance / 0 sinon


    int groupe;             //Groupe auquel elle appartient (1 à 8).
    int prix;               //Prix de la propriété.
    char* proprio;          //Nom du joueur qui possèderait cette propriété.
} Case;

//Structure Joueur, renseigne les informations du joueur ciblé.
typedef struct{
    char* nomJoueur;        //Nom du Joueur.
    int money;              //Argent que le joueur possède au cours de la partie. (valeur toujours positive)
    int position;           //position du joueur sur le plateau (1 à 32).
    int prison;             //1 VRAI 0 FAUX.
    int tourEnPrison;       //Max 3 tours en prison. Après il est libéré.
    int nbCSP;              //nombre de cartes sortie de prison que le joueur possède 0,1 ou 2.
} Joueur;

//Structure des cartes chance.
typedef struct{
    char* nom;            //nom de la carte chance.
    int taille;           //10 ou 9 si la carte sortie de prison a été pioché, mais pas joué.
}CChance;

//Structure des cartes communauté.
typedef struct{
    char* nom;            //nom de la carte communauté.
}CCommunaute;



void menuPrincipal();
int menuJoueur();

int lancerLesDes();
int nouvellePosition(int actuelle, int sommeDes);



Case* initPlateau(Case* cases);
CChance* initCarteChance(CChance* listeCartesChance);
CCommunaute* initCarteCommunaute(CCommunaute* listeCartesComm);

Joueur* initJoueur(int* nbJoueurs);
void affichagePlateau(Joueur* listeJoueurs,int* nbJoueurs);


void nouvellePartie(int* nbJoueurs, Joueur* listeJoueurs, Case* cases, CChance* listeCartesChance, CCommunaute* listeCartesComm,int* nbCarteC,int* nbCarteComm);









void afficherNomsEquipeProjet();

void quitter();


#endif //MONOPOLY_MESFONCTIONS_H
