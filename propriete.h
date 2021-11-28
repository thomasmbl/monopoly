//
// Created by Thomas on 27/11/2021.
//

#ifndef PROJET_MONOPOLY_PROPRIETE_H
#define PROJET_MONOPOLY_PROPRIETE_H
#include "mesfonctions.h"

void acheterPropriete(Joueur* listeJoueurs,int i, Case* cases,const int* nbJoueurs);

void acheterMaison(Banque* banque,Joueur* listeJoueurs,int i, Case* cases);

void acheterHotel(Banque* banque,Joueur* listeJoueurs,int i, Case* cases);

#endif //PROJET_MONOPOLY_PROPRIETE_H
