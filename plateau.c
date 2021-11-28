//
// Created by Thomas on 27/11/2021.
//

#include <stdio.h>
#include <stdlib.h>
#include "plateau.h"
#include "mesfonctions.h"
#include "cartes.h"

//Fonction d'initialisation des 32 cases du plateau.
Case* initPlateau(Case* cases) {
    cases = malloc(32*sizeof(Case));

    //0. Case départ
    cases[0].nomCase = "CASE DEPART";
    cases[0].typeCase = 0;


    //1. Propriété 1 du groupe 1
    cases[1].nomCase = "HOTEL DE VILLE";
    cases[1].typeCase = 1;
    cases[1].groupe = 1;
    cases[1].prix = 160 ;
    cases[1].proprio = "Disponible";

    cases[1].loyerMaisons[0] = 60;
    cases[1].loyerMaisons[1] = 180;
    cases[1].loyerMaisons[2] = 500;
    cases[1].loyerMaisons[3] = 700;
    cases[1].nbMaisons = 0;

    cases[1].loyerHotel = 900;
    cases[1].nbHotel = 0;


    //2. Taxe d’habitation : Payez 100€
    cases[2].nomCase = "TAXE D'HABITATION";
    cases[2].typeCase = 0;


    //3. Propriété 2 du groupe 1
    cases[3].nomCase = "PLACE DES TERREAUX";
    cases[3].typeCase = 1;
    cases[3].groupe = 1;
    cases[3].prix = 160 ;
    cases[3].proprio = "Disponible";

    cases[3].loyerMaisons[0] = 60;
    cases[3].loyerMaisons[1] = 180;
    cases[3].loyerMaisons[2] = 500;
    cases[3].loyerMaisons[3] = 700;
    cases[3].nbMaisons = 0;

    cases[3].loyerHotel = 900;
    cases[3].nbHotel = 0;


    //4. Raccourci : Avancez à la case 13
    cases[4].nomCase = "RACCOURCI";
    cases[4].typeCase = 0;


    //5. Propriété 1 du groupe 2
    cases[5].nomCase = "PLACE BELLECOUR";
    cases[5].typeCase = 1;
    cases[5].groupe = 2;
    cases[5].prix = 200 ;
    cases[5].proprio = "Disponible";

    cases[5].loyerMaisons[0] = 80;
    cases[5].loyerMaisons[1] = 220;
    cases[5].loyerMaisons[2] = 600;
    cases[5].loyerMaisons[3] = 800;
    cases[5].nbMaisons = 0;

    cases[5].loyerHotel = 1000;
    cases[5].nbHotel = 0;


    //6. Tirez une carte communauté
    cases[6].nomCase = "TIRAGE CARTE COMMUNAUTE";
    cases[6].typeCase = 2;


    //7. Propriété 2 du groupe 2
    cases[7].nomCase = "CONFLUENCE";
    cases[7].typeCase = 1;
    cases[7].groupe = 2;
    cases[7].prix = 200 ;
    cases[7].proprio = "Disponible";

    cases[7].loyerMaisons[0] = 80;
    cases[7].loyerMaisons[1] = 220;
    cases[7].loyerMaisons[2] = 600;
    cases[7].loyerMaisons[3] = 800;
    cases[7].nbMaisons = 0;

    cases[7].loyerHotel = 1000;
    cases[7].nbHotel = 0;


    //8. Case prison
    cases[8].nomCase = "CASE PRISON";
    cases[8].typeCase = 0;


    //9. Propriété 1 du groupe 3
    cases[9].nomCase = "PART DIEU";
    cases[9].typeCase = 1;
    cases[9].groupe = 3;
    cases[9].prix = 120 ;
    cases[9].proprio = "Disponible";

    cases[9].loyerMaisons[0] = 40;
    cases[9].loyerMaisons[1] = 100;
    cases[9].loyerMaisons[2] = 300;
    cases[9].loyerMaisons[3] = 450;
    cases[9].nbMaisons = 0;

    cases[9].loyerHotel = 600;
    cases[9].nbHotel = 0;


    //10. Impôt sur la fortune : Payez 100€
    cases[10].nomCase = "IMPOT SUR LA FORTUNE";
    cases[10].typeCase = 0;


    //11. Propriété 2 du groupe 3
    cases[11].nomCase = "LES HALLES";
    cases[11].typeCase = 1;
    cases[11].groupe = 3;
    cases[11].prix = 120 ;
    cases[11].proprio = "Disponible";

    cases[11].loyerMaisons[0] = 40;
    cases[11].loyerMaisons[1] = 100;
    cases[11].loyerMaisons[2] = 300;
    cases[11].loyerMaisons[3] = 450;
    cases[11].nbMaisons = 0;

    cases[11].loyerHotel = 600;
    cases[11].nbHotel = 0;


    //12. Raccourci : Avancez à la case 21
    cases[12].nomCase = "RACCOURCI";
    cases[12].typeCase = 0;


    //13. Propriété 1 du groupe 4
    cases[13].nomCase = "PLACE DE LA CROIX ROUSSE";
    cases[13].typeCase = 1;
    cases[13].groupe = 4;
    cases[13].prix = 140 ;
    cases[13].proprio = "Disponible";

    cases[13].loyerMaisons[0] = 50;
    cases[13].loyerMaisons[1] = 150;
    cases[13].loyerMaisons[2] = 450;
    cases[13].loyerMaisons[3] = 625;
    cases[13].nbMaisons = 0;

    cases[13].loyerHotel = 750;
    cases[13].nbHotel = 0;


    //14. Tirez une carte chance
    cases[14].nomCase = "TIRAGE CARTE CHANCE";
    cases[14].typeCase = 3;


    //15. Propriété 2 du groupe 4
    cases[15].nomCase = "THEATRE";
    cases[15].typeCase = 1;
    cases[15].groupe = 4;
    cases[15].prix = 140 ;
    cases[15].proprio = "Disponible";

    cases[15].loyerMaisons[0] = 50;
    cases[15].loyerMaisons[1] = 150;
    cases[15].loyerMaisons[2] = 450;
    cases[15].loyerMaisons[3] = 625;
    cases[15].nbMaisons = 0;

    cases[15].loyerHotel = 750;
    cases[15].nbHotel = 0;


    //16. Case stationnement gratuit
    cases[16].nomCase = "STATIONNEMENT GRATUIT";
    cases[16].typeCase = 0;


    //17. Propriété 1 du groupe 5
    cases[17].nomCase = "BASILIQUE NOTRE DAME DE FOURVIERE";
    cases[17].typeCase = 1;
    cases[17].groupe = 5;
    cases[17].prix = 100 ;
    cases[17].proprio = "Disponible";

    cases[17].loyerMaisons[0] = 30;
    cases[17].loyerMaisons[1] = 90;
    cases[17].loyerMaisons[2] = 270;
    cases[17].loyerMaisons[3] = 400;
    cases[17].nbMaisons = 0;

    cases[17].loyerHotel = 550;
    cases[17].nbHotel = 0;


    //18. Taxe sur les produits de luxe : Payez 200€
    cases[18].nomCase = "TAXE SUR LES PRODUITS DE LUXE";
    cases[18].typeCase = 0;


    //19. Propriété 2 du groupe 5
    cases[19].nomCase = "THEATRE ROMAIN";
    cases[19].typeCase = 1;
    cases[19].groupe = 5;
    cases[19].prix = 100 ;
    cases[19].proprio = "Disponible";

    cases[19].loyerMaisons[0] = 30;
    cases[19].loyerMaisons[1] = 90;
    cases[19].loyerMaisons[2] = 270;
    cases[19].loyerMaisons[3] = 400;
    cases[19].nbMaisons = 0;

    cases[19].loyerHotel = 550;
    cases[19].nbHotel = 0;


    //20. Raccourci : Avancez à la case 29
    cases[20].nomCase = "RACCOURCI";
    cases[20].typeCase = 0;


    //21. Propriété 1 du groupe 6
    cases[21].nomCase = "BROTTEAUX";
    cases[21].typeCase = 1;
    cases[21].groupe = 6;
    cases[21].prix = 180 ;
    cases[21].proprio = "Disponible";

    cases[21].loyerMaisons[0] = 70;
    cases[21].loyerMaisons[1] = 200;
    cases[21].loyerMaisons[2] = 550;
    cases[21].loyerMaisons[3] = 700;
    cases[21].nbMaisons = 0;

    cases[21].loyerHotel = 950;
    cases[21].nbHotel = 0;


    //22. Tirez une carte communauté
    cases[22].nomCase = "TIRAGE CARTE COMMUNAUTE";
    cases[22].typeCase = 2;


    //23. Propriété 2 du groupe 6
    cases[23].nomCase = "PARC DE LA TETE D'OR";
    cases[23].typeCase = 1;
    cases[23].groupe = 6;
    cases[23].prix = 180 ;
    cases[23].proprio = "Disponible";

    cases[23].loyerMaisons[0] = 70;
    cases[23].loyerMaisons[1] = 200;
    cases[23].loyerMaisons[2] = 550;
    cases[23].loyerMaisons[3] = 700;
    cases[23].nbMaisons = 0;

    cases[23].loyerHotel = 950;
    cases[23].nbHotel = 0;


    //24. Allez en prison
    cases[24].nomCase = "ALLER EN PRISON";
    cases[24].typeCase = 0;



    //25. Propriété 1 du groupe 7
    cases[25].nomCase = "GUILLOTIERE";
    cases[25].typeCase = 1;
    cases[25].groupe = 7;
    cases[25].prix = 60 ;
    cases[25].proprio = "Disponible";

    cases[25].loyerMaisons[0] = 20;
    cases[25].loyerMaisons[1] = 60;
    cases[25].loyerMaisons[2] = 180;
    cases[25].loyerMaisons[3] = 320;
    cases[25].nbMaisons = 0;

    cases[25].loyerHotel = 450;
    cases[25].nbHotel = 0;



    //26. Vous trouvez 50€ par terre.
    cases[26].nomCase = "VOUS TROUVEZ 50EUROS";
    cases[26].typeCase = 0;


    //27. Propriété 2 du groupe 7
    cases[27].nomCase = "GERLAND";
    cases[27].typeCase = 1;
    cases[27].groupe = 7;
    cases[27].prix = 60 ;
    cases[27].proprio = "Disponible";

    cases[27].loyerMaisons[0] = 20;
    cases[27].loyerMaisons[1] = 60;
    cases[27].loyerMaisons[2] = 180;
    cases[27].loyerMaisons[3] = 320;
    cases[27].nbMaisons = 0;

    cases[27].loyerHotel = 450;
    cases[27].nbHotel = 0;


    //28. Raccourci : Avancez à la case 5 (Vous passez par la case départ et collectez 200€)
    cases[28].nomCase = "RACCOURCI";
    cases[28].typeCase = 0;


    //29. Propriété 1 du groupe 8
    cases[29].nomCase = "MANUFACTURE DES TABACS";
    cases[29].typeCase = 1;
    cases[29].groupe = 8;
    cases[29].prix = 50 ;
    cases[29].proprio = "Disponible";

    cases[29].loyerMaisons[0] = 10;
    cases[29].loyerMaisons[1] = 30;
    cases[29].loyerMaisons[2] = 90;
    cases[29].loyerMaisons[3] = 160;
    cases[29].nbMaisons = 0;

    cases[29].loyerHotel = 250;
    cases[29].nbHotel = 0;


    //30. Tirez une carte chance
    cases[30].nomCase = "TIRAGE CARTE CHANCE";
    cases[30].typeCase = 3;


    //31. Propriété 2 du groupe 8
    cases[31].nomCase = "MON PLAISIR";
    cases[31].typeCase = 1;
    cases[31].groupe = 8;
    cases[31].prix = 50 ;
    cases[31].proprio = "Disponible";

    cases[31].loyerMaisons[0] = 10;
    cases[31].loyerMaisons[1] = 30;
    cases[31].loyerMaisons[2] = 90;
    cases[31].loyerMaisons[3] = 160;
    cases[31].nbMaisons = 0;

    cases[31].loyerHotel = 250;
    cases[31].nbHotel = 0;



    return cases;
}

//Fonction d'affichage du "plateau" en console ainsi que les informations des joueurs dans la partie.
void affichagePlateau(Joueur* listeJoueurs,int* nbJoueurs,Case* cases) {
    //Affichage des numeros de case du plateau ( 1 à 32 ).
    printf("\n===================================================| Plateau de jeu |================"
           "===================================\n\n");
    for(int i=1;i<=32;i++){
        printf(" CASE %d \t",i);
        //Condition pour le retour a la ligne en console ( tableau de 4 lignes par 8 colonnes ).
        if(i%8==0){
            printf("\n");
        }
    }
    printf("======================================================================================="
           "=================================\n");

    //Affichage de la position de chaque joueur sur le plateau ainsi que leur argent.
    printf("\n=====| Informations des joueurs dans la partie |======\n");
    for(int i=0;i<*nbJoueurs;i++){
        printf("Joueur %d : %s - %d euros - Case %d : %s\n"
               "", i+1, listeJoueurs[i].nomJoueur, listeJoueurs[i].money, listeJoueurs[i].position,cases[listeJoueurs[i].position-1].nomCase);
    }
    printf("======================================================\n\n");

}

void depart(Joueur* listeJoueurs, int i, int position, int sommeDes){
    if( listeJoueurs[i].position == 1 || position+sommeDes >= 32 ){
        printf("\nBanque: Passage par la case depart, vous recevez 200 euros!\n");
        listeJoueurs[i].money += 200;
    }
}

void positionPlateau(Joueur* listeJoueurs,int* nbJoueurs, Case* cases, int i, char** listeCartesChance, char** listeCartesComm, int* nbCarteC,int*  nbCarteComm){

    printf("\nVous etes maintenant sur la case %d : %s\n",listeJoueurs[i].position, cases[listeJoueurs[i].position-1].nomCase);

    //Type de case
    //Si le joueur se trouve sur une propriété, on affiche les informations utiles.
    if(cases[listeJoueurs[i].position-1].typeCase == 1){
        printf("==> Vous vous trouvez sur une case PROPRIETE\n"
               "\tStatus : %s\n"
               "\tPrix d'achat : %d euros\n"
               "\tGroupe : %d\n"
               "\tNb Maisons : %d / 4\n"
               "\tNb Hotel : %d / 1\n"
               "\tValeur Hypothecaire : %d euros\n"
                ,cases[listeJoueurs[i].position-1].proprio
                ,cases[listeJoueurs[i].position-1].prix
                ,cases[listeJoueurs[i].position-1].groupe
                ,cases[listeJoueurs[i].position-1].nbMaisons
                ,cases[listeJoueurs[i].position-1].nbHotel
                ,cases[listeJoueurs[i].position-1].loyerMaisons[0]+cases[listeJoueurs[i].position-1].loyerMaisons[1]);
    }
    //Cases tirage carte communauté.
    else if(cases[listeJoueurs[i].position-1].typeCase == 2){
        printf(">Tirage carte communaute\n");
        listeJoueurs[i].nbCSP += tirerCarte(listeCartesComm,nbCarteComm,listeJoueurs,i,nbJoueurs);
    }
    //Cases tirage carte chance.
    else if(cases[listeJoueurs[i].position-1].typeCase == 3){
        printf(">Tirage carte carte\n");
        listeJoueurs[i].nbCSP += tirerCarte(listeCartesChance,nbCarteC,listeJoueurs,i,nbJoueurs);
    }


    //Position du joueur sur le plateau.
    else if(listeJoueurs[i].position == 3){
        printf(">Banque: taxe d'habitation, payez 100euros !\n");
        verifArgent(listeJoueurs,i,100);
    }

    else if(listeJoueurs[i].position == 5){
        printf(">Raccourci: Hop direct a la case 13 !\n");
        listeJoueurs[i].position = 13;
    }

    else if(listeJoueurs[i].position == 9){
        printf(">Vous etes en visite en Prison, ne craignez rien...\n");
    }

    else if(listeJoueurs[i].position == 11){
        printf(">Banque: Impot sur la fortune, payez 100euros !\n");
        verifArgent(listeJoueurs,i,100);
    }

    else if(listeJoueurs[i].position == 13){
        printf(">Raccourci: Hop direct a la case 21 !\n");
        listeJoueurs[i].position = 21;
    }

    else if(listeJoueurs[i].position == 19){
        printf(">Banque: Taxe sur les produits de luxe, payez 200euros !\n");
        verifArgent(listeJoueurs,i,200);
    }

    else if(listeJoueurs[i].position == 21){
        printf(">Raccourci: Hop direct a la case 29 !\n");
        listeJoueurs[i].position = 29;
    }

    else if(listeJoueurs[i].position == 25){
        printf(">Raccourci PRISON HAHA: Hop direct a la case 9 ( sans argent :c )\n");
        listeJoueurs[i].position = 9;
        listeJoueurs[i].prison = 1;
        listeJoueurs[i].tourEnPrison = 3;
    }

    else if(listeJoueurs[i].position == 27){
        printf(">La chance..vous trouvez 50euros par terre !\n");
        listeJoueurs[i].money += 50;
    }

    else if(listeJoueurs[i].position == 29){
        printf(">Raccourci: Hop direct a la case 5 !\n");
        printf(">Banque: Passage par la case depart, vous recevez 200 euros!\n");
        listeJoueurs[i].position = 5;
        listeJoueurs[i].money += 200;
    }
}