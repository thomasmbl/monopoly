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

int verifChoix(){
    char chaine[30];
    int entier=0;
    fflush(stdout);
    fgets(chaine,sizeof chaine,stdin);
    while( !((entier=atoi(chaine)) || *chaine=='0' )){
        printf("Choix invalide! Entrez un entier\n>");
        fflush(stdout);
        fgets(chaine,sizeof chaine,stdin);
    }
    return entier;
}

void verifArgent(Joueur* listeJoueurs,int i,int aSoustraire){
    if(listeJoueurs[i].money - aSoustraire < 0 ){
        printf("Vous n'avez pas assez d'argent pour payer vos dettes !\n"
               "Vous etes placez en faillite, si vous ne trouvez pas de l'argent avant la fin de votre tour,\n"
               "sous serez elimine de la partie !\n");
        listeJoueurs[i].money -= aSoustraire;           //On soustrait qd même pour que le joueur puisse rembourser
                                                        //sa "dette" mais on le place en état de faillite.
        listeJoueurs[i].faillite = true;
    }
    else{
        listeJoueurs[i].money -= aSoustraire;
    }
}

void supprimerJoueur(Joueur* listeJoueurs, int i,int* nbJoueurs){
    if(i==0){
        for(int j=0;j<*nbJoueurs-1;j++){
            listeJoueurs[j] = listeJoueurs[j+1];
        }
    }
    else if(i==*nbJoueurs-1){
    }
    else{
        for(int j=i;j<*nbJoueurs-1;j++){
            listeJoueurs[j] = listeJoueurs[j+1];
        }
    }
}


void menuJoueur(){
    printf("\n=====| Menu Joueur |=====\n"
           "que souhaitez vous faire ?\n"
           "1/ Lancer les des\n"
           "2/ Acheter une propriete\n"
           "3/ Acheter une maison\n"
           "4/ Acheter un hotel\n"
           "5/ Hypothequer une propriete\n"
           "6/ Vendre une propriete\n"
           "0/ Passer son tour.\n"
           "=========================\n>");
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
    char flush;

    //Entrée du nombre de joueurs ainsi que de leurs noms.
    printf("\n=====| Combien de joueur etes-vous ? |=====\n>");
    *nbJoueurs = verifChoix();
    Joueur* listeJoueurs = (Joueur*) malloc(*nbJoueurs * sizeof(Joueur) );

    for(i=0;i<*nbJoueurs;i++){
        listeJoueurs[i].nomJoueur = (char*) malloc(sizeof(char));
        printf("\nEntrez le nom du joueur %d :",i+1);
        scanf("%s", listeJoueurs[i].nomJoueur);
        scanf("%c",&flush);

        //initialisation des attributs du joueur.
        listeJoueurs[i].money = 1500;
        listeJoueurs[i].position = 1;
        listeJoueurs[i].prison = 0;
        listeJoueurs[i].nbCSP = 0;
        listeJoueurs[i].tourEnPrison = 0;
        listeJoueurs[i].maisons = 0;
        listeJoueurs[i].hotel = 0;
        listeJoueurs[i].faillite = false;
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
    int tour = 0;
    int choix = 0;
    int choixbis = 0;

    do {
        tour += 1;
        printf("=======================================================| Tour %d |======================================================", tour);
        affichagePlateau(listeJoueurs,nbJoueurs,cases);
        for (int i = 0; i < *nbJoueurs; i++) {
            //Initialisation des variables a chaque tour de chaque joueurs.
            int lanceDeDes = 0;
            int position = 0, sommeDes = 0;

            printf("> ********************* C'est a %s de joueur ! *********************\n", listeJoueurs[i].nomJoueur);
            do {
                printf("Solde : %d euros - Case %d : %s\n",listeJoueurs[i].money,listeJoueurs[i].position,cases[listeJoueurs[i].position-1].nomCase);
                if(listeJoueurs[i].faillite == true){
                    printf("Vous etes en faillite, trouvez de l'argent avant la fin de votre tour sinon vous serez elimine\n");
                }

                //Si le joueur est en prison, on affiche les options qui lui sont possible pour en sortir.
                optionPrison(listeJoueurs,i,listeCartesChance,nbCarteC,listeCartesComm,nbJoueurs);

                //On affiche le menu joueur.
                menuJoueur();

                //Verification que choix est bien de type int.
                choix = verifChoix();
                switch ( choix ) {
                    case 1 :
                        //Lancer les dés. (Appel de la fonction lancerLesDes 1 fois par personne par tour)============//

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
                        //On enregistre la position précédente du joueur et le retour de la fonction lancerLesDes.
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
                            //Sinon on actualise la position.
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
                    case 5:
                        //Hypothéquer une propriété.
                        hypothequer(listeJoueurs,i,cases,banque);
                        break;
                    case 0:
                        //Passer son tour.
                        if(listeJoueurs[i].faillite == true){
                            printf("Vous etes en faillite!\n"
                                   "Si vous quittez vous serez elimine!\n");
                            printf("> Passer votre tour ? ( 1 = OUI / 2 = NON )\n>");
                            choixbis = verifChoix();
                            switch(choixbis){
                                case 1:
                                    //Le joueur est elimine.
                                    //Procédure qui le supprime de la liste des joueurs.
                                    printf("Joueur %d : %s est elimine !\n",i,listeJoueurs[i].nomJoueur);
                                    supprimerJoueur(listeJoueurs,i,nbJoueurs);
                                    *nbJoueurs -= 1;
                                    i-=1;
                                    break;
                                case 2:
                                    break;
                                default:
                                    puts("Choix invalide!");
                                    break;
                            }
                        }
                        break;
                    default :
                        printf("Choix invalide!\n");
                        break;
                }
            }while (choix != 0);
        }
    }while (*nbJoueurs > 1);
    printf("\n                    __________                      \n"
           "*--------------*|======MONOPOLY======|*--------------*\n"
           "                       GAGNANT :                      \n"
           "                        %s                            \n"
           "                       argent : %d euros              \n"
           "*--------------*|====================|*--------------*\n\n"
           ,listeJoueurs[0].nomJoueur,listeJoueurs[0].money );
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
    char flush;
    do{
        printf("Etes vous sur de vouloir quitter ?\n"
               "OUI ou NON\n>");
        scanf("%s",&verifChoix);
        scanf("%c",&flush);

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





