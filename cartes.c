//
// Created by Thomas on 27/11/2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "cartes.h"
#include "mesfonctions.h"


//Procédure d'initialisation des 10 cartes chance.
void initCarteChance(char** listeCartesChance){
    int alea = 0;
    char* tmp;

    //On initialise la liste des cartes chance.
    listeCartesChance[0] = "Allez a la case de depart. (Collectez 200euros)";
    listeCartesChance[1] = "Allez a PLACE DES TERREAUX. Collectez votre salaire si vous passez la case depart";
    listeCartesChance[2] = "Allez a GUILLOTIERE. Collectez votre salaire si vous passez la case depart";
    listeCartesChance[3] = "La banque vous paie 50euros";
    listeCartesChance[4] = "Carte sortez de prison";
    listeCartesChance[5] = "Reculez de 3 cases";
    listeCartesChance[6] = "Allez directement en prison, vous ne passez pas par la case depart";
    listeCartesChance[7] = "Vous faites des reparations sur vos proprietes : Payez 25euros/maison et 100euros/hotel.";
    listeCartesChance[8] = "Vous avez ete elu maire, payez 50euros a chaque joueur";
    listeCartesChance[9] = "Exces de vitesse : payez 100euros";

    //On mélange la pile de carte.
    srand(time(NULL));
    for(int i=0;i<10;i++){
        alea = rand()%10;
        tmp = listeCartesChance[alea];
        listeCartesChance[alea] = listeCartesChance[i];
        listeCartesChance[i] = tmp;
    }
}

//Procédure d'initialisation des 10 cartes communauté.
void initCarteCommunaute(char** listeCartesComm){
    int alea = 0;
    char* tmp;

    //On initialise la liste des cartes communauté.
    listeCartesComm[0] = "Allez a la case depart. (Collectez 200euros)";
    listeCartesComm[1] = "Frais de docteur. Payez 50euros";
    listeCartesComm[2] = "Carte sortie de prison";
    listeCartesComm[3] = "Allez directement en prison, vous ne passez pas par la case depart";
    listeCartesComm[4] = "Vous faites un vide grenier et gagnez 30euros";
    listeCartesComm[5] = "C’est votre anniversaire, collectez 10euros de chaque joueur";
    listeCartesComm[6] = "Vous recuperez des rentes : gagnez 100euros";
    listeCartesComm[7] = "Payez des frais d’hopital de 100euros";
    listeCartesComm[8] = "Vous avez obtenu la seconde place d’un concours de beaute : gagnez 10euros";
    listeCartesComm[9] = "Vous heritez de 100euros";

    //On mélange la pile de carte.
    srand(time(NULL));
    for(int i=0;i<10;i++){
        alea = rand()%10;
        tmp = listeCartesComm[alea];
        listeCartesComm[alea] = listeCartesComm[i];
        listeCartesComm[i] = tmp;
    }
}

int tirerCarte(char** listeCartes, int* nbCartes, Joueur* listeJoueurs,int i, int* nbJoueurs){

    printf("Vous avez tirez la carte :\n"
           "\t==> %s\n",listeCartes[0]);

    if(strcmp(listeCartes[0],"Carte sortez de prison")==0){
        *nbCartes -= 1;
        for(int j=0;j<*nbCartes;j++){
            strcpy(listeCartes[j],listeCartes[j+1]);
        }
        return 1;
    }
    else{
        if(strcmp(listeCartes[0],"Allez a la case de depart. (Collectez 200euros)")==0){
            listeJoueurs[i].position = 1;
            listeJoueurs[i].money += 200;
        }
        if(strcmp(listeCartes[0],"Allez a PLACE DES TERREAUX. Collectez votre salaire si vous passez la case depart")==0){
            listeJoueurs[i].position = 4;
            printf("\nBanque: Passage par la case depart, vous recevez 200 euros!\n");
            listeJoueurs[i].money += 200;
        }
        if(strcmp(listeCartes[0],"Allez a GUILLOTIERE. Collectez votre salaire si vous passez la case depart")==0){
            if(listeJoueurs[i].position > 26 ){
                printf("\nBanque: Passage par la case depart, vous recevez 200 euros!\n");
                listeJoueurs[i].money += 200;
            }
            listeJoueurs[i].position = 26;

        }
        if(strcmp(listeCartes[0],"La banque vous paie 50euros")==0){
            listeJoueurs[i].money += 50;
        }
        if(strcmp(listeCartes[0],"Reculez de 3 cases")==0){
            if( listeJoueurs[i].position - 3 >= 0 ){
                nouvellePosition(listeJoueurs[i].position,3);
            }
            else{
                nouvellePosition(listeJoueurs[i].position,-3);
            }
        }
        if(strcmp(listeCartes[0],"Allez directement en prison, vous ne passez pas par la case depart")==0){
            listeJoueurs[i].position = 9;
            listeJoueurs[i].prison = 1;
            listeJoueurs[i].tourEnPrison = 3;
        }
        if(strcmp(listeCartes[0],"Vous faites des reparations sur vos proprietes : Payez 25euros/maison et 100euros/hotel.")==0){
            verifArgent(listeJoueurs,i,25*listeJoueurs[i].maisons + 100*listeJoueurs[i].hotel);
        }
        if(strcmp(listeCartes[0],"Vous avez ete elu maire, payez 50euros a chaque joueur")==0){

            for(int j=0;j<*nbJoueurs;j++){
                verifArgent(listeJoueurs,i,50);
                if( listeJoueurs[i].faillite == false ){
                    if(i==j);
                    else{
                        listeJoueurs[j].money += 50;
                    }
                }
                else if( listeJoueurs[i].faillite == true ){
                    printf("Vous ne pouvez pas payer %s\n",listeJoueurs[j].nomJoueur);
                    //On ne paye pas le joueur j pour ne pas creer de l'argent.
                }


            }
        }
        if(strcmp(listeCartes[0],"Exces de vitesse : payez 100euros")==0){
            verifArgent(listeJoueurs,i,100);
        }
        if(strcmp(listeCartes[0],"Frais de docteur. Payez 50euros")==0){
            verifArgent(listeJoueurs,i,50);
        }
        if(strcmp(listeCartes[0],"Vous faites un vide grenier et gagnez 30euros")==0){
            listeJoueurs[i].money += 30;
        }
        if(strcmp(listeCartes[0],"C’est votre anniversaire, collectez 10euros de chaque joueur")==0){
            for(int j=0;j<*nbJoueurs;j++){
                if(i==j);
                else{
                    if(listeJoueurs[j].money - 10 < 0 ){
                        printf("%s n'a pas assez d'argent pour vous payer!\n"
                               "Il est place en faillite, s'il ne trouvez pas de l'argent avant la fin de son tour,\n"
                               "il sera elimine de la partie !\n",
                               listeJoueurs[j].nomJoueur);

                        listeJoueurs[j].money -= 10;
                        listeJoueurs[j].faillite = true;
                    }
                    else{
                        listeJoueurs[j].money -= 10;
                        listeJoueurs[i].money += 10;
                    }
                }
            }
        }
        if(strcmp(listeCartes[0],"Vous recuperez des rentes : gagnez 100euros")==0){
            listeJoueurs[i].money += 100;
        }
        if(strcmp(listeCartes[0],"Payez des frais d hopital de 100euros")==0){
            verifArgent(listeJoueurs,i,100);
        }
        if(strcmp(listeCartes[0],"Vous avez obtenu la seconde place d un concours de beaute : gagnez 10euros")==0){
            listeJoueurs[i].money += 10;
        }
        if(strcmp(listeCartes[0],"Vous héritez de 100euros")==0){
            listeJoueurs[i].money += 100;
        }

        char* temp = listeCartes[0];
        for(int i=0;i<*nbCartes-1;i++){
            listeCartes[i] = listeCartes[i+1];
        }
        listeCartes[*nbCartes-1] = temp;
        return 0;
    }
}









