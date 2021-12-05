//
// Created by Thomas on 27/11/2021.
//

#include <stdio.h>
#include "propriete.h"
#include "mesfonctions.h"
#include <string.h>
#include <windows.h>

void acheterPropriete(Joueur* listeJoueurs,int i, Case* cases,const int* nbJoueurs){
    int choix=0;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //On vérifie que le joueur se trouve bien sur une case de type propriété.
    if(cases[listeJoueurs[i].position-1].typeCase == 1) {

        //Ensuite que la propriété est bien disponible à l'achat.
        if( strcmp(cases[listeJoueurs[i].position-1].proprio,"Disponible") == 0 ){

            //On vérifie que le joueur a assez d'argent.
            if( listeJoueurs[i].money < cases[listeJoueurs[i].position-1].prix ){
                SetConsoleTextAttribute(hConsole,4);
                printf("Vous n'avez pas assez d'argent\n");
                SetConsoleTextAttribute(hConsole,7);
                return;
            }

            printf("Vous etes sur le point d'acheter %s pour %d euros ! Confirmez vous ? ( 1 = OUI / 2 = NON )\n>"
                    ,cases[listeJoueurs[i].position-1].nomCase, cases[listeJoueurs[i].position-1].prix );

            choix = verifChoix();
            switch (choix) {
                case 1:
                    //On actualise l'argent
                    listeJoueurs[i].money -= cases[listeJoueurs[i].position-1].prix;
                    listeJoueurs[i].prop += 1;
                    cases[listeJoueurs[i].position-1].proprio = listeJoueurs[i].nomJoueur;
                    break;
                case 2:
                    break;
                default:
                    SetConsoleTextAttribute(hConsole,4);
                    puts("Choix Invalide!");
                    SetConsoleTextAttribute(hConsole,7);
                    break;
            }

        }
        //Si elle n'est pas disponible, on cherche à qui elle appartient.
        else {
            for(int j=0;j<*nbJoueurs;j++){
                //On affiche le nom du propriétaire.
                if( strcmp( cases[listeJoueurs[i].position-1].proprio, listeJoueurs[j].nomJoueur ) == 0 ){
                    printf("%s en est deja le proprietaire!\n", listeJoueurs[j].nomJoueur);
                }

                //Si la propriété est hypothéquée alors :
                if( cases[listeJoueurs[i].position-1].hypotheque == true ){
                    printf("Mais vous pouvez acquerir cette propriete en remboursant son hypotheque avec un interet de 10%%, total : %d euros\n"
                           ,(1+1/10)*(cases[listeJoueurs[i].position-1].prix-cases[listeJoueurs[i].position-1].loyerMaisons[0]));
                    printf("Souhaitez vous racheter cette propriete ? ( 1 = OUI / 2 = NON )\n");
                    choix = verifChoix();


                    switch (choix) {
                        case 1 :
                            //On vérifie que le joueur a assez d'argent.
                            if( listeJoueurs[i].money < (1+1/10)*(cases[listeJoueurs[i].position-1].prix-cases[listeJoueurs[i].position-1].loyerMaisons[0]) ){
                                SetConsoleTextAttribute(hConsole,4);
                                printf("Vous n'avez pas assez d'argent\n");
                                SetConsoleTextAttribute(hConsole,7);
                                break;
                            }
                            //S'il a assez et qu'il souhaite racheter la prop alors :
                            else{
                                listeJoueurs[i].money -= (1+1/10)*(cases[listeJoueurs[i].position-1].prix-cases[listeJoueurs[i].position-1].loyerMaisons[0]);
                                listeJoueurs[i].prop += 1;
                                cases[listeJoueurs[i].position-1].proprio = listeJoueurs[i].nomJoueur;
                                cases[listeJoueurs[i].position-1].hypotheque = false;
                                break;
                            }
                        case 2:
                            break;
                        default:
                            SetConsoleTextAttribute(hConsole,4);
                            puts("Choix Invalide!");
                            SetConsoleTextAttribute(hConsole,7);
                            break;

                    }

                }
            }
        }
    }
    else
        puts("Vous n'etes pas sur une case propriete");
}

void acheterMaison(Banque* banque,Joueur* listeJoueurs,int i, Case* cases){
    int choix=0;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if(cases[listeJoueurs[i].position-1].typeCase == 1) {

        if( strcmp(listeJoueurs[i].nomJoueur,cases[listeJoueurs[i].position-1].proprio) == 0 && cases[listeJoueurs[i].position-1].hypotheque == false ) {
            if( banque->maison != 0 ){
                if( cases[listeJoueurs[i].position-1].nbMaisons == 4 || cases[listeJoueurs[i].position-1].nbHotel == 1 ){
                    puts("4/4 Maisons construites ou un Hotel ! Vous ne pouvez plus construire sur ce terrain!");
                    if(cases[listeJoueurs[i].position-1].nbHotel != 1){
                        printf("Construisez-y un hotel !\n");
                    }
                }
                else{
                    if( listeJoueurs[i].money < 100 ){
                        SetConsoleTextAttribute(hConsole,4);
                        printf("Vous n'avez pas assez d'argent\n");
                        SetConsoleTextAttribute(hConsole,7);
                        return;
                    }
                    printf("%d / 4 maisons sont construite(s) sur ce terrain\n",cases[listeJoueurs[i].position-1].nbMaisons);
                    printf("Vous etes sur le point d'acheter une maison pour 100 euros ! Confirmez vous ? ( 1 = OUI / 2 = NON )\n>");
                    choix = verifChoix();
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
                            SetConsoleTextAttribute(hConsole,4);
                            puts("Choix Invalide!");
                            SetConsoleTextAttribute(hConsole,7);
                            break;
                    }
                }
            }
            else{
                puts("La Banque ne possede plus de maisons..Attendez qu'un joueur en vende une !");
            }
        }
        else if(strcmp(listeJoueurs[i].nomJoueur,cases[listeJoueurs[i].position-1].proprio) == 0 && cases[listeJoueurs[i].position-1].hypotheque == true){
            printf("Rembourser d'abord l'hypotheque avec un interet de 10% !\n");
            printf("Racheter la prop pour %d euros ? ( 1 = OUI / 2 = NON )\n>",(1+1/10)*(cases[listeJoueurs[i].position-1].prix-cases[listeJoueurs[i].position-1].loyerMaisons[0]) );
            choix=verifChoix();
            switch (choix) {
                case 1:
                    if(listeJoueurs[i].money < (1+1/10)*(cases[listeJoueurs[i].position-1].prix-cases[listeJoueurs[i].position-1].loyerMaisons[0])){
                        SetConsoleTextAttribute(hConsole,4);
                        printf("Vous n'avez pas assez d'argent\n");
                        SetConsoleTextAttribute(hConsole,7);
                    }
                    else{
                        listeJoueurs[i].money -= (1+1/10)*(cases[listeJoueurs[i].position-1].prix-cases[listeJoueurs[i].position-1].loyerMaisons[0]);
                        listeJoueurs[i].prop += 1;
                        cases[listeJoueurs[i].position-1].proprio = listeJoueurs[i].nomJoueur;
                        cases[listeJoueurs[i].position-1].hypotheque = false;
                    }
                    break;
                case 2:
                    break;
                default:
                    SetConsoleTextAttribute(hConsole,4);
                    puts("Choix Invalide!");
                    SetConsoleTextAttribute(hConsole,7);
                    break;
            }
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
                    if( listeJoueurs[i].money < 200 ){
                        printf("Vous n'avez pas assez d'argent\n");
                        return;
                    }
                    printf("Vous etes sur le point de construire un hotel contre 4 maisons pour 200 euros. Confirmez vous ? ( 1 = OUI / 2 = NON )\n>");
                    choix = verifChoix();
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
            else{
                puts("La Banque ne possede plus d'hotel..Attendez qu'un joueur en vende un !");
            }
        }
        else
            puts("Ce terrain ne vous appartient pas !");
    }
}

void hypothequer(Joueur* listeJoueurs,int i, Case* cases,Banque* banque){
    int choixHypo=0;
    int choix=0;


    if(listeJoueurs[i].prop != 0){
        printf("Propriete(s) que vous possedez : \n");
        for(int j=0;j<32;j++){
            if( cases[j].typeCase == 1 && strcmp(cases[j].proprio,listeJoueurs[i].nomJoueur) == 0 ){
                printf("\tCase %d : %s ==> %d/4 maisons | %d/1 hotel , valeur hypothecaire = %d euros, hypotheque ? %s\n"
                        ,j+1, cases[j].nomCase, cases[j].nbMaisons, cases[j].nbHotel, cases[j].prix - cases[j].loyerMaisons[0],cases[j].hypotheque ? "true" : "false");
            }
        }
        printf("\nSi vous souhaitez hypothequer une de vos proprietes, vous devrez vendre toutes les maisons/hotel que vous avez construit dessus\n");
        printf("Quelle propriete souhaitez vous hypothequer (entrez le numero de la case) ?\n>");
        choixHypo=verifChoix();

        printf("Confirmez vous ? ( 1 = OUI / 2 = NON )\n>");
        choix = verifChoix();

        switch (choix) {
            case 1:
                if( cases[choixHypo-1].typeCase == 1 && strcmp(cases[choixHypo-1].proprio,listeJoueurs[i].nomJoueur) == 0 && cases[choixHypo-1].nbHotel==1 ){

                    cases[choixHypo-1].nbHotel -= 1;
                    listeJoueurs[i].hotel -= 1;
                    banque->hotel += 1;

                    printf(">Banque: Vous recevez : %d euros\n",200 + cases[choixHypo-1].prix - cases[choixHypo-1].loyerMaisons[0] );
                    listeJoueurs[i].money += 200 + cases[choixHypo-1].prix - cases[choixHypo-1].loyerMaisons[0];
                    listeJoueurs[i].prop -= 1;
                    cases[choixHypo-1].hypotheque = true;

                }
                else if( cases[choixHypo-1].typeCase == 1 && strcmp(cases[choixHypo-1].proprio,listeJoueurs[i].nomJoueur) == 0 && cases[choixHypo-1].nbMaisons>=0 ){
                    printf("Banque> Vous recevez : %d euros\n",50*cases[choixHypo-1].nbMaisons
                                                               + cases[choixHypo-1].prix
                                                               - cases[choixHypo-1].loyerMaisons[0] );

                    listeJoueurs[i].money += 50*cases[choixHypo-1].nbMaisons
                                             + cases[choixHypo-1].prix
                                             - cases[choixHypo-1].loyerMaisons[0];

                    listeJoueurs[i].prop -= 1;
                    cases[choixHypo-1].hypotheque = true;

                    listeJoueurs[i].maisons -= cases[choixHypo-1].nbMaisons;
                    banque->maison += cases[choixHypo-1].nbMaisons;
                    cases[choixHypo-1].nbMaisons = 0;
                }
                else{
                    printf("Choix invalide!\n");
                }
                break;
            case 2:
                break;
            default:
                puts("Choix invalide!");
                break;
        }

    }
    else
        puts("Vous ne possedez pas de propriete");
}

void vendre(Joueur* listeJoueurs,int i, Case* cases,Banque* banque){
    int choixVendre=0;
    int choix=0;


    if(listeJoueurs[i].prop != 0){
        printf("Propriete(s) que vous possedez : \n");
        for(int j=0;j<32;j++){
            if( cases[j].typeCase == 1 && strcmp(cases[j].proprio,listeJoueurs[i].nomJoueur) == 0 ){
                printf("\tCase %d : %s ==> %d/4 maisons | %d/1 hotel , valeur vente = %d euros\n"
                        ,j+1, cases[j].nomCase, cases[j].nbMaisons, cases[j].nbHotel, cases[j].prix / 2 );
            }
        }
        printf("Si vous souhaitez vendre une de vos proprietes, vous devrez vendre toutes les maisons/hotel que vous avez construit dessus\n");
        printf("Quelle propriete souhaitez vous vendre (entrez le numero de la case) ?\n>");
        choixVendre=verifChoix();

        printf("Confirmez vous ? ( 1 = OUI / 2 = NON )\n>");
        choix = verifChoix();

        switch (choix) {
            case 1:
                if( cases[choixVendre-1].typeCase == 1 && strcmp(cases[choixVendre-1].proprio,listeJoueurs[i].nomJoueur) == 0 ){

                    cases[choixVendre-1].nbHotel -= 1;
                    listeJoueurs[i].hotel -= 1;
                    banque->hotel += 1;

                    printf(">Banque: Vous recevez : %d euros\n",200 + cases[choixVendre-1].prix / 2 );
                    listeJoueurs[i].money += 200 + cases[choixVendre-1].prix / 2;

                    listeJoueurs[i].prop -= 1;
                    cases[listeJoueurs[i].position-1].proprio = "Disponible";
                }
                else if( cases[choixVendre-1].typeCase == 1 && strcmp(cases[choixVendre-1].proprio,listeJoueurs[i].nomJoueur) == 0 && cases[choixVendre-1].nbMaisons >=0 ){
                    printf("Banque> Vous recevez : %d euros\n",50*cases[choixVendre-1].nbMaisons
                                                               + cases[choixVendre-1].prix / 2);

                    listeJoueurs[i].money += 50*cases[choixVendre-1].nbMaisons
                                             + cases[choixVendre-1].prix / 2;

                    listeJoueurs[i].prop -= 1;

                    listeJoueurs[i].maisons -= cases[choixVendre-1].nbMaisons;
                    banque->maison += cases[choixVendre-1].nbMaisons;
                    cases[choixVendre-1].nbMaisons = 0;

                    cases[listeJoueurs[i].position-1].proprio = "Disponible";
                }

                break;
            case 2:
                break;
            default:
                puts("Choix invalide!");
                break;
        }

    }
    else if(listeJoueurs[i].prop == 0 ){
        printf("Vous ne possedez pas de propriete");
    }
}


