//
// Created by Thomas on 27/11/2021.
//

#include "propriete.h"
#include "mesfonctions.h"
#include <string.h>

void acheterPropriete(Joueur* listeJoueurs,int i, Case* cases,const int* nbJoueurs){
    int choix=0;
    if(cases[listeJoueurs[i].position-1].typeCase == 1) {
        if( strcmp(cases[listeJoueurs[i].position-1].proprio,"Disponible") == 0 ){
            printf("Vous etes sur le point d'acheter %s pour %d euros ! Confirmez vous ? ( 1 = OUI / 2 = NON )\n"
                    ,cases[listeJoueurs[i].position-1].nomCase, cases[listeJoueurs[i].position-1].prix );

            scanf("%d",&choix);

            switch (choix) {
                case 1:
                    listeJoueurs[i].money -= cases[listeJoueurs[i].position-1].prix;
                    strcpy( cases[listeJoueurs[i].position-1].proprio , listeJoueurs[i].nomJoueur );
                    break;
                case 2:
                    break;
                default:
                    puts("Choix invalide!");
                    break;
            }

        }
        else {
            for(int j=0;j<*nbJoueurs;j++){
                if( strcmp( cases[listeJoueurs[i].position-1].proprio, listeJoueurs[j].nomJoueur ) == 0 ){
                    printf("%s en est deja le proprietaire, vous pouvez peut etre lui racheter !\n", listeJoueurs[j].nomJoueur);
                }
            }
        }
    }
    else
        puts("Vous n'etes pas sur une case propriete");
}

void acheterMaison(Banque* banque,Joueur* listeJoueurs,int i, Case* cases){
    int choix=0;

    if(cases[listeJoueurs[i].position-1].typeCase == 1) {
        if( strcmp(listeJoueurs[i].nomJoueur,cases[listeJoueurs[i].position-1].proprio) == 0) {
            if( banque->maison != 0 ){
                if( cases[listeJoueurs[i].position-1].nbMaisons == 4 || cases[listeJoueurs[i].position-1].nbHotel == 1 ){
                    puts("4/4 Maisons construites ! Vous ne pouvez plus en acheter ce terrain!");
                    if(cases[listeJoueurs[i].position-1].nbHotel == 1){
                        printf("Construisez-y un hotel !\n");
                    }
                }
                else{
                    printf("%d / 4 maisons sont construite(s) sur ce terrain\n",cases[listeJoueurs[i].position-1].nbMaisons);
                    printf("Vous etes sur le point d'acheter une maison pour 100 euros ! Confirmez vous ? ( 1 = OUI / 2 = NON )\n");
                    scanf("%d",&choix);
                    switch (choix) {
                        case 1:
                            listeJoueurs[i].money -= 100;
                            cases[listeJoueurs[i].position-1].nbMaisons += 1;
                            banque->maison -= 1;
                            listeJoueurs[i].maisons += 1;
                            break;
                        case 2:
                            break;
                        default:
                            puts("Choix invalide!");
                            break;
                    }
                }
            }
            puts("La Banque ne possede plus de maisons..Attendez qu'un joueur en vende une !");
        }
        else
            puts("Ce terrain ne vous appartient pas !");
    }
}

void acheterHotel(Banque* banque,Joueur* listeJoueurs,int i, Case* cases){
    int choix=0;

    if(cases[listeJoueurs[i].position-1].typeCase == 1) {
        if( strcmp(listeJoueurs[i].nomJoueur,cases[listeJoueurs[i].position-1].proprio) == 0) {
            if( banque->hotel != 0 ){
                if( cases[listeJoueurs[i].position-1].nbHotel == 1 || cases[listeJoueurs[i].position-1].nbMaisons != 4 ){
                    puts("Vous ne pouvez pas construire d'hotel sur ce terrain !");
                }
                else{
                    printf("Vous etes sur le point de construire un hotel contre 4 maisons pour 200 euros. Confirmez vous ?( 1 = OUI / 2 = NON )\n");
                    scanf("%d",&choix);
                    switch (choix) {
                        case 1:
                            listeJoueurs[i].money -= 200;
                            cases[listeJoueurs[i].position-1].nbMaisons -= 4;
                            cases[listeJoueurs[i].position-1].nbHotel += 1;

                            banque->maison += 4;
                            banque->hotel -= 1;

                            listeJoueurs[i].maisons -= 4;
                            listeJoueurs[i].hotel += 1;
                            break;
                        case 2:
                            break;
                        default:
                            puts("Choix invalide!");
                            break;
                    }
                }
            }
            puts("La Banque ne possede plus d'hotel..Attendez qu'un joueur en vende un !");
        }
        else
            puts("Ce terrain ne vous appartient pas !");
    }
}

