//
// Created by Thomas on 02/11/2021.
//

#include "mesfonctions.h"
#include <string.h>
#include <stdlib.h>

void menuPrincipal() {
    int choix=0;

    do {
        printf("=====| Que souhaitez vous faire ? |=====\n");
        printf("1/ Lancer une nouvelle partie.\n"
               "2/ Sauvegarder la partie en cours.\n"
               "3/ Charger une ancienne partie.\n"
               "4/ Afficher les regles.\n"
               "5/ Afficher le nom des membres de l'equipe du projet.\n"
               "6/ Quitter.\n>\n");
        scanf("%d",&choix);
        switch(choix) {
            case 1 :
                //Lancer une nouvelle partie.
                break;

            case 2 :
                //Sauvegarder la partie en cours.
                break;

            case 3 :
                //Charger une ancienne partie.
                break;

            case 4 :
                //Afficher les regles.
                break;

            case 5 :
                //Afficher le nom des membres de l'équipe du projet.
                break;

            case 6 :
                //Quitter la partie.
                break;

            default : {
                printf("Choix invalide !\n>");
                break;
            }
        }
    }while(choix != 6);

}


//====================================================================================================================//
//Procédure en référence au choix 1 du menu principal.
void nouvellePartie() {
    int i=0;
    unsigned int nbJoueurs=0;

    printf("Combien de joueur etes-vous ?\n>");
    scanf("%d",&nbJoueurs);
    Joueur* listeJoueurs = (Joueur*) malloc( nbJoueurs * sizeof(char) );  // NE PAS OUBLIER DE FREE LISTEJOUEURS

    for(i=1;i<=nbJoueurs;i++){
        printf("Entrez le nom du joueur %d\n",i);
        scanf("%s", listeJoueurs[i].nomJoueur);
    }
    //RESTE DU CODE

}


//====================================================================================================================//
//Procédure en référence au choix 5 du menu principal.
void afficherNomsEquipeProjet(){
    printf("=====| Liste des membres |=====\n");
    printf("MABILLE Thomas\n"
           "etc\n\n");
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





