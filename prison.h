//
// Created by Thomas on 27/11/2021.
//

#ifndef PROJET_MONOPOLY_PRISON_H
#define PROJET_MONOPOLY_PRISON_H

#include "mesfonctions.h"

void optionPrison(Joueur* listeJoueurs, int i, char** listeCartesChance, int* nbCarteC,char** listeCartesComm, int* nbJoueurs);

void lancerDesPrison(Joueur* listeJoueurs, Case* cases, int i, int* lanceDeDes);

#endif //PROJET_MONOPOLY_PRISON_H