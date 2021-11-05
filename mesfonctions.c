//
// Created by Thomas on 02/11/2021.
//

#include "mesfonctions.h"
#include <string.h>
#include <stdlib.h>

int menuPrincipal() {
    int choix = 0;
    printf("=====| Que souhaitez vous faire ? |=====\n");
    printf("1/ Lancer une nouvelle partie.\n"
           "2/ Sauvegarder la partie en cours.\n"
           "3/ Charger une ancienne partie.\n"
           "4/ Afficher les regles.\n"
           "5/ Afficher le nom des membres de l'equipe du projet.\n"
           "6/ Quitter.\n");
    printf("========================================\n>");
    scanf("%d", &choix);
    return choix;
}



//====================================================================================================================//
//Procédure en référence au choix 1 du menu principal.
Joueur* nouvellePartie(int* nbJoueurs) {
    int i=0;

    printf("\n=====| Combien de joueur etes-vous ? |=====\n>");
    scanf("%d",nbJoueurs);
    Joueur* listeJoueurs = (Joueur*) malloc( *nbJoueurs * sizeof(Joueur) );  // NE PAS OUBLIER DE FREE LISTEJOUEURS!!
                                                                             // LORSQUE LA PARTIE SERA TERMINEE
    for(i=0;i<*nbJoueurs;i++){
        listeJoueurs[i].nomJoueur = (char*) malloc(sizeof(char));
        printf("\n=| Entrez le nom du joueur %d |=\n>",i+1);
        scanf("%s", listeJoueurs[i].nomJoueur);

        listeJoueurs[i].money = 1500;
        listeJoueurs[i].position = 0;
        printf("Banque: Vous recevez 1500 euros de bienvenue.\n\n");
    }
    //RESTE DU CODE


    return listeJoueurs;

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





