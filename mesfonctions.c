//
// Created by Thomas on 02/11/2021.
//

#include "mesfonctions.h"
#include "prison.h"
#include "cartes.h"
#include "plateau.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "propriete.h"


//====================================================================================================================//
void menuPrincipal() {
    printf("=====| Que souhaitez vous faire ? |=======================|\n");
    printf("1/ Lancer une nouvelle partie.                            |\n"
           "2/ Sauvegarder la partie en cours.                        |\n"
           "3/ Charger une ancienne partie.                           |\n"
           "4/ Afficher les regles.                                   |\n"
           "5/ Afficher le nom des membres de l'equipe du projet.     |\n"
           "6/ Quitter.                                               |\n");
    printf("==========================================================|\n>");
}

int menuJoueur(){
    int choix=0;
    printf("\n=====| Menu Joueur |=====\n"
           "que souhaitez vous faire ?\n"
           "1/ Lancer les des\n"
           "2/ Acheter une propriete\n"
           "3/ Acheter une maison\n"
           "4/ Acheter un hotel\n"
           "5/ Hypothequer une propriete\n"
           "6/ Vendre une propriete\n"
           "7/ Acheter une propriete\n"
           "0/ Passer son tour.\n"
           "=========================\n>");
    scanf("%d",&choix);
    return choix;
}

int lancerLesDes(){
    int de1 = 0, de2 = 0, somme=0, nbDoubles = 0;
    do{
        printf("\nLancement des des ! ");
        //Affectation de valeurs aléatoires pour nos 2 dés (1 à 6).
        de1 = rand()%6+1;
        de2 = rand()%6+1;

        somme += de1 + de2;

        printf("> de1 = %d , de2 = %d , somme = %d. ==> ", de1, de2, somme);

        if(de1 != de2){
            printf("Vous avancez de %d cases\n",somme);
            return somme;
        }
        else if(de1==de2){
            printf("Vous avez fait un DOUBLE!\n");
            nbDoubles += 1;
        }
    }while( (de1==de2) && nbDoubles < 3 );     //Conditions pour relancer les dés, max 3 lancés.

    if( nbDoubles == 3 ){                      //Si 3 doubles alors le joueur va en prison.
        printf("3 DOUBLES D'AFFILE !!!\n"
               "Trop de chance finit par porter mal chance ! Aller directement en prison :c\n");
        return 0;
    }

}

int nouvellePosition(int actuelle, int sommeDes){
    int nouvelle = 0;
    nouvelle = actuelle + sommeDes;

    if(nouvelle > 32){
        nouvelle = nouvelle - 32;
        return nouvelle;
    }
    else if(nouvelle <= 0){
        nouvelle = nouvelle + 32;
    }

    return nouvelle;
}

//====================================================================================================================//
//Fonctions en référence au choix 1 du menu principal.

//Initialisation de la liste de joueurs ( nombre, nom, argent, position sur le plateau ).
Joueur* initJoueur(int* nbJoueurs) {

    //initialisation des variables utiles.
    int i=0;
    int alea=0;
    Joueur tmp;

    //Entrée du nombre de joueurs ainsi que de leurs noms.
    printf("\n=====| Combien de joueur etes-vous ? |=====\n>");
    scanf("%d",nbJoueurs);
    Joueur* listeJoueurs = (Joueur*) malloc(*nbJoueurs * sizeof(Joueur) );

    for(i=0;i<*nbJoueurs;i++){
        listeJoueurs[i].nomJoueur = (char*) malloc(sizeof(char));
        printf("\nEntrez le nom du joueur %d :",i+1);
        scanf("%s", listeJoueurs[i].nomJoueur);

        //initialisation des attributs du joueur.
        listeJoueurs[i].money = 1500;
        listeJoueurs[i].position = 1;
        listeJoueurs[i].prison = 0;
        listeJoueurs[i].nbCSP = 0;
        listeJoueurs[i].tourEnPrison = 0;
        printf("Banque: Vous recevez 1500 euros de bienvenue.\n");
    }

    //On mélange l'ordre des joueurs dans la liste.
    srand(time(NULL));
    for(i=0;i<*nbJoueurs;i++){
        alea = rand()%*nbJoueurs;
        tmp = listeJoueurs[alea];
        listeJoueurs[alea] = listeJoueurs[i];
        listeJoueurs[i] = tmp;
    }
    printf("\nVos numeros de joueurs ont ete modifies, voici le nouvel ordre de passage :\n");
    for(i=0;i<*nbJoueurs;i++){
        printf("Joueur %d = %s\n",i+1,listeJoueurs[i].nomJoueur);
    } printf("\n");

    return listeJoueurs;
}

void nouvellePartie(int* nbJoueurs, Joueur* listeJoueurs, Case* cases, char** listeCartesChance, char** listeCartesComm, int* nbCarteC,int*  nbCarteComm,Banque* banque) {
    int tour = 0, choix = 0;
    do {
        tour += 1;
        printf("=======================================================| Tour %d |=======================================================", tour);
        affichagePlateau(listeJoueurs,nbJoueurs);
        for (int i = 0; i < *nbJoueurs; i++) {
            //Initialisation des variables a chaque tour de chaque joueurs.
            int lanceDeDes = 0;
            int position = 0, sommeDes = 0;

            printf("> ********************* C'est a %s de joueur ! *********************\n", listeJoueurs[i].nomJoueur);
            do {
                //Si le joueur est en prison, on affiche les options qui lui sont possible pour en sortir.
                optionPrison(listeJoueurs,i,listeCartesChance,nbCarteC,listeCartesComm,nbJoueurs);

                choix = menuJoueur();
                switch ( choix ) {
                    case 1 :
                        //Lancer les dés. (Appel de la fonction lancerLesDes 1 fois par personne par tour).

                        //On vérif si le joueur n'est pas en prison.
                        //Si c'est le cas alors il n'a le droit qu'a un seul lancé par tour, même si c'est un double.
                        if(listeJoueurs[i].prison == 1){
                            if(lanceDeDes != 1)
                                lancerDesPrison(listeJoueurs,cases,i,&lanceDeDes);
                            else
                                printf("Vous avez deja lance les des!\n");
                        }

                        //On vérifie si le joueur (hors cas de prison) n'a pas déjà lancé les dés.
                        if(lanceDeDes == 1){
                            printf("Vous avez deja lance les des!\n");
                            break;
                        }

                        //S'il n'a pas déjà lancé alors il peut les lancer.
                        //On modifie la position des joueurs.
                        position = listeJoueurs[i].position;
                        sommeDes = lancerLesDes();

                        //La procédure lancerLesDes renvoie 0 si le joueur a fait 3 doubles d'affilée.
                        //On le met donc en prison.
                        if(sommeDes == 0){
                            listeJoueurs[i].prison = 1;
                            listeJoueurs[i].tourEnPrison = 3;   //Il a au plus encore 3 tours à faire en prison.
                            lanceDeDes = 1;
                            break;   //On break pour qu'il ne prenne pas la prime de 200 euros dans le cas ou il passerait par la case depart.
                        }
                        else{
                            //Sinon on actualise la position
                            listeJoueurs[i].position = nouvellePosition( listeJoueurs[i].position, sommeDes );
                            lanceDeDes = 1;
                        }

                        //On ajoute 200 euros au joueur s'il est/ou passe par la case depart.
                        depart(listeJoueurs,i,position,sommeDes);

                        //Affichage position joueur sur le plateau.
                        //Et des différentes actions correspondantes.
                        positionPlateau(listeJoueurs,nbJoueurs,cases,i,listeCartesChance,listeCartesComm,nbCarteC,nbCarteComm);

                        break;
                    case 2 :
                        //Acheter une propriete.
                        acheterPropriete(listeJoueurs,i,cases,nbJoueurs);
                        break;
                    case 3 :
                        //Acheter une maison.
                        acheterMaison(banque,listeJoueurs,i,cases);
                        break;
                    case 4:
                        //Acheter un hotel.
                        acheterHotel(banque,listeJoueurs,i,cases);
                        break;
                    case 0:
                        //Passer son tour.
                        break;
                    default :
                        printf("Choix invalide!\n");
                        break;
                }
            }while (choix != 0);
        }
    }while (*nbJoueurs != 0);
}






















//====================================================================================================================//
//Procédure en référence au choix 5 du menu principal.
void afficherNomsEquipeProjet(){
    printf("=====| Liste des membres |=====\n");
    printf("MABILLE Thomas\n"
           "ROBERT Theo\n\n");
}


//====================================================================================================================//
//Procédure en référence au choix 6 du menu principal.
void quitter(){
    char verifChoix[4];
    do{
        printf("Etes vous sur de vouloir quitter ?\n"
               "OUI ou NON\n>");
        scanf("%s",&verifChoix);

        //Comparaison de chaînes pour savoir si ce que l'utilisateur à entré est valide ou non.
        if( strcmp(verifChoix,"oui") == 0 || strcmp(verifChoix,"OUI") == 0 ){              //stcrmp return 0 si les 2
            printf("A très bientot !\n");                                                  //chaînes sont identiques.
            break;
        }
        else if( strcmp(verifChoix,"non") == 0 || strcmp(verifChoix,"NON") == 0 ){
            break;
        }
    }while( (strcmp(verifChoix,"oui") != 0 && strcmp(verifChoix,"OUI") != 0)
            &&
            (strcmp(verifChoix,"non") != 0 && strcmp(verifChoix,"NON")) != 0 );

}





