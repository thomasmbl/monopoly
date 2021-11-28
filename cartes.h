//
// Created by Thomas on 27/11/2021.
//

#ifndef PROJET_MONOPOLY_CARTES_H
#define PROJET_MONOPOLY_CARTES_H
#include "mesfonctions.h"

void initCarteChance(char** listeCartesChance);
void initCarteCommunaute(char** listeCartesComm);

int tirerCarte(char** listeCartes, int* nbCartes, Joueur* listeJoueurs,int i, int* nbJoueurs);


#endif //PROJET_MONOPOLY_CARTES_H
