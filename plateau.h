//
// Created by Thomas on 27/11/2021.
//

#ifndef PROJET_MONOPOLY_PLATEAU_H
#define PROJET_MONOPOLY_PLATEAU_H

#include "mesfonctions.h"

Case* initPlateau(Case* cases);

void affichagePlateau(Joueur* listeJoueurs,int* nbJoueurs,Case* cases);

void depart(Joueur* listeJoueurs, int i, int position, int sommeDes);
void positionPlateau(Joueur* listeJoueurs,int* nbJoueurs, Case* cases, int i, char** listeCartesChance, char** listeCartesComm, int* nbCarteC,int*  nbCarteComm);

#endif //PROJET_MONOPOLY_PLATEAU_H