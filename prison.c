//
// Created by Thomas on 27/11/2021.
//

#include <stdio.h>
#include "prison.h"
#include "mesfonctions.h"
#include <time.h>
#include <stdlib.h>
#include <string.h>

void optionPrison(Joueur* listeJoueurs, int i, char** listeCartesChance, int* nbCarteC,char** listeCartesComm, int* nbJoueurs){
    if(listeJoueurs[i].prison == 1){
        printf("Vous etes en prison ! Pour vous en echapper :\n"
               "\t- Faire un double sur l'un de vos %d prochains tours.\n"
               "\t- Utiliser la carte : sortie de prison gratuite ( %d / 2 ).\n"
               "\t- Acheter la carte : sortie de prison gratuite a un autre joueur et la jouer\n"
               "\t- Payer une amande de 50euros avant de lancer les des lors d'un de vos 2 prochains tours\n"
               "\t- Si vous ne parvenez pas a faire un double a votre 3eme tour (tour restant : %d), vous payez 50euros\n"
                ,listeJoueurs[i].nbCSP,listeJoueurs[i].tourEnPrison,listeJoueurs[i].tourEnPrison);
        int choix=0;

        if(listeJoueurs[i].nbCSP!=0){
            printf("Vous avez %d carte(s) sortie de prison gratuite\n"
                   "Voulez vous en utiliser une ? ( 1 = OUI / 2 = NON )\n",listeJoueurs[i].nbCSP);
            choix = verifChoix();
            switch(choix){
                case 1:
                    listeJoueurs[i].nbCSP -= 1;
                    if(*nbCarteC==9){
                        strcpy(listeCartesChance[9],"Carte sortez de prison");
                        break;
                    }
                    else{
                        strcpy(listeCartesComm[9],"Carte sortez de prison");
                        break;
                    }
                case 2:
                    break;
                default :
                    printf("Choix Invalide !\n");
                    break;
            }
        }
        else{
            printf("Joueur(s) qui en possède au moins une : \n");
            for(int j=0;j<*nbJoueurs;j++){

                if(listeJoueurs[j].nbCSP >= 1){
                    printf("%s\n",listeJoueurs[j].nomJoueur);
                    puts("Souhaitez vous lui acheter? (1:OUI 2:NON)");
                    choix = verifChoix();

                    switch(choix){
                        case 1:
                            if(listeJoueurs[j].money-50 < 0){
                                printf("Vous n'avez pas assez d'argent pour acheter cette carte (50 euros)\n");
                                break;
                            }
                            printf(">Joueur %d : %s, %s souhaite vous acheter votre carte sortie de prison pour 50 euros, acceptez vous ? (1:OUI 2:NON)\n"
                                    ,j,listeJoueurs[j].nomJoueur, listeJoueurs[i].nomJoueur);
                            scanf("%d",&choix);
                            switch (choix) {
                                case 1:
                                    //On actualise l'argent.
                                    listeJoueurs[i].money -= 50;
                                    listeJoueurs[j].money += 50;
                                    //On actualise le nb de carte sortie de prison des joueurs.
                                    listeJoueurs[j].nbCSP -= 1;
                                    listeJoueurs[i].nbCSP += 1;
                                    break;
                                case 2:
                                    printf("Desole, %s ne souhaite pas vous la vendre :/ \n",listeJoueurs[j].nomJoueur);
                                    break;
                                default:
                                    puts("Choix invalide!");
                                    break;
                            }
                            break;
                        case 2:
                            break;
                        default:
                            puts("choix invalide");
                            break;

                    }
                }

            }
        }

    }


}

void lancerDesPrison(Joueur* listeJoueurs, Case* cases, int i, int* lanceDeDes){
    if(listeJoueurs[i].tourEnPrison != 1){
        int de1 = rand()%6 +1;
        int de2 = rand()%6 +1;
        *lanceDeDes = 1;

        if(de1==de2) {
            printf("Des : %d et %d : Bravo vous etes libre ! ===> Vous avancez de %d cases.\n",de1,de2,2*de1);
            listeJoueurs[i].prison = 0;
            listeJoueurs[i].tourEnPrison = 0;
            listeJoueurs[i].position = nouvellePosition(listeJoueurs[i].position, de1 + de2);
            printf("\nVous etes maintenant sur la case %d : %s\n",listeJoueurs[i].position, cases[listeJoueurs[i].position-1].nomCase);
        }
        else{
            printf("Vous n'avez pas fait de double, dommage reessayez au tour prochain\n");
            listeJoueurs[i].tourEnPrison -= 1;
        }
    }

    else if(listeJoueurs[i].tourEnPrison == 1){
        int de1 = rand()%6 +1;
        int de2 = rand()%6 +1;
        *lanceDeDes = 1;

        if(de1==de2) {
            printf("Dés : %d et %d\n"
                   "Bravo vous etes libre !\n"
                   "Vous avancez de %d cases.\n",2*de1);
            listeJoueurs[i].prison = 0;
            listeJoueurs[i].tourEnPrison = 0;
            listeJoueurs[i].position = nouvellePosition(listeJoueurs[i].position, de1 + de2);
            printf("\nVous etes maintenant sur la case %d : %s\n",listeJoueurs[i].position, cases[listeJoueurs[i].position-1].nomCase);
        }
        else{
            printf("Vous n'avez pas fait de double, payez 50 euros pour votre liberation\n");
            verifArgent(listeJoueurs,i,50);     //Verifier si le joueur a assez d'argent..
            listeJoueurs[i].prison = 0;
            listeJoueurs[i].tourEnPrison = 0;
            listeJoueurs[i].position = nouvellePosition(listeJoueurs[i].position, de1 + de2);
            printf("\nVous etes maintenant sur la case %d : %s\n",listeJoueurs[i].position, cases[listeJoueurs[i].position-1].nomCase);
        }

    }
}