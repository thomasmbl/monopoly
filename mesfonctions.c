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
#include <windows.h>




//====================================================================================================================//
void menuPrincipal() {
    printf("=====| Que souhaitez vous faire ? |=======================|\n");
    printf("1/ Lancer une nouvelle partie.                            |\n"
           "2/ Charger une ancienne partie.                           |\n"
           "3/ Afficher les regles.                                   |\n"
           "4/ Afficher le nom des membres de l'equipe du projet.     |\n"
           "5/ Quitter.                                               |\n");
    printf("==========================================================|\n>");
}

void sauvegarder(int* nbJoueurs, Joueur* listeJoueurs, Case* cases, char** listeCartesChance, char** listeCartesComm, int* nbCarteC,int* nbCarteComm,Banque* banque){

    FILE* pf = NULL;

    printf("Sauvegarde en cours\n");
    if((pf = fopen("./sauvegarde1.dat","w"))==NULL){
        printf("Erreur d'ouverture du fichier.\n");
    }
    fwrite(nbJoueurs,sizeof(int),1,pf);
    if( fwrite(listeJoueurs,sizeof(Joueur),*nbJoueurs,pf) != *nbJoueurs ) {
        printf("Problemes d'ecriture dans le fichier\n");
    }
    if( fwrite(cases,sizeof(Case),32,pf) != 32 ) {
        printf("Problemes d'ecriture dans le fichier\n");
    }
    fwrite(nbCarteC,sizeof(int),1,pf);
    fwrite(nbCarteComm,sizeof(int),1,pf);
    if( fwrite(listeCartesChance,sizeof(char*),*nbCarteC,pf) != *nbCarteC ) {
        printf("Problemes d'ecriture dans le fichier\n");
    }
    if( fwrite(listeCartesComm,sizeof(char*),*nbCarteComm,pf) != *nbCarteComm ) {
        printf("Problemes d'ecriture dans le fichier\n");
    }
    fwrite(banque,sizeof(Banque),1,pf);

    puts("Partie sauvegarde!");
    fclose(pf);
    pf = NULL;


}

int verifChoix(){
    char chaine[30];
    int entier=0;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    fflush(stdout);
    fgets(chaine,sizeof chaine,stdin);
    while( !((entier=atoi(chaine)) || *chaine=='0' )){      //la fonction atoi : ASCII to Integer renvoie 0 si chaine est un caract??re.

        SetConsoleTextAttribute(hConsole,4);
        puts("Choix invalide! Entrez un entier");
        SetConsoleTextAttribute(hConsole,5);
        printf(">");
        SetConsoleTextAttribute(hConsole,7);

        fflush(stdout);
        fgets(chaine,sizeof chaine,stdin);
    }
    return entier;
}

void verifArgent(Joueur* listeJoueurs,int i,int aSoustraire){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    if(listeJoueurs[i].money - aSoustraire < 0 ){

        SetConsoleTextAttribute(hConsole,4);
        printf("Vous n'avez pas assez d'argent pour payer vos dettes !\n");
        SetConsoleTextAttribute(hConsole,5);
        printf("Vous etes placez en faillite, si vous ne trouvez pas de l'argent avant la fin de votre tour,\n"
               "sous serez elimine de la partie !\n");
        SetConsoleTextAttribute(hConsole,7);

        listeJoueurs[i].money -= aSoustraire;           //On soustrait qd m??me pour que le joueur puisse rembourser
                                                        //sa "dette" mais on le place en ??tat de faillite.
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
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole,5);
    printf("\n=====| Menu Joueur |=====\n"
           "que souhaitez vous faire ?\n"
           "1/ Lancer les des\n"
           "2/ Acheter une propriete\n"
           "3/ Acheter une maison\n"
           "4/ Acheter un hotel\n"
           "5/ Hypothequer une propriete\n"
           "6/ Vendre des biens\n"
           "7/ Menu Principal\n"
           "0/ Passer son tour.\n"
           "=========================\n>");
    SetConsoleTextAttribute(hConsole,7);
}

int lancerLesDes(int* nbDoubles,int* lanceDeDes){
    int de1 = 0, de2 = 0, somme=0;

    printf("\nLancement des des !");
    //Affectation de valeurs al??atoires pour nos 2 d??s (1 ?? 6).
    de1 = rand()%6+1;
    de2 = rand()%6+1;

    somme = de1 + de2;

    printf("\nde1 = %d\nde2 = %d\n==> ", de1, de2);

    if(de1 != de2){
        printf("Vous avancez de %d cases\n",somme);
        *lanceDeDes = 1;
        return somme;
    }
    else if(de1==de2 && *nbDoubles < 3 ){
        printf("Vous avez fait un DOUBLE!\n>Vous avez le droit a un autres lance de des.\n");
        *nbDoubles += 1;
        return somme;
    }
    else if( (de1==de2) && *nbDoubles == 3 ){                      //Si 3 doubles alors le joueur va en prison.
        printf("3 DOUBLES D'AFFILE !!!\n"
               ">Trop de chance finit par porter mal chance ! Allez directement en prison :c\n");
        *lanceDeDes = 1;
        return 0;                                   //inutile de return la somme puisque le joueur va en prison.
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
//Fonctions en r??f??rence au choix 1 du menu principal.

//Initialisation de la liste de joueurs ( nombre, nom, argent, position sur le plateau ).
Joueur* initJoueur(int* nbJoueurs) {

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //initialisation des variables utiles.
    int i=0;
    int alea=0;
    Joueur tmp;
    char flush;

    //Entr??e du nombre de joueurs ainsi que de leurs noms.
    SetConsoleTextAttribute(hConsole,5);
    printf("\n=====| Combien de joueur etes-vous ? |=====\n>");
    *nbJoueurs = verifChoix();
    Joueur* listeJoueurs = (Joueur*) malloc(*nbJoueurs * sizeof(Joueur) );

    for(i=0;i<*nbJoueurs;i++){
        listeJoueurs[i].nomJoueur = (char*) malloc(sizeof(char));
        SetConsoleTextAttribute(hConsole,5);
        printf("\nEntrez le nom du joueur %d :",i+1);
        scanf("%s", listeJoueurs[i].nomJoueur);
        scanf("%c",&flush);

        //initialisation des attributs du joueur.
        listeJoueurs[i].money = 1500;
        listeJoueurs[i].position = 1;
        listeJoueurs[i].prison = 0;
        listeJoueurs[i].nbCSP = 0;
        listeJoueurs[i].tourEnPrison = 0;
        listeJoueurs[i].prop = 0;
        listeJoueurs[i].maisons = 0;
        listeJoueurs[i].hotel = 0;
        listeJoueurs[i].faillite = false;
        SetConsoleTextAttribute(hConsole,10);
        printf("Banque: Vous recevez 1500 euros de bienvenue.\n");
        SetConsoleTextAttribute(hConsole,5);
    }

    //On m??lange l'ordre des joueurs dans la liste.
    srand(time(NULL));
    for(i=0;i<*nbJoueurs;i++){
        alea = rand()%*nbJoueurs;
        tmp = listeJoueurs[alea];
        listeJoueurs[alea] = listeJoueurs[i];
        listeJoueurs[i] = tmp;
    }
    printf("\nVos numeros de joueurs ont ete modifies, voici le nouvel ordre de passage :\n");
    for(i=0;i<*nbJoueurs;i++){
        printf("Joueur %d = ",i+1);
        SetConsoleTextAttribute(hConsole,14);
        printf("%s\n",listeJoueurs[i].nomJoueur);
        SetConsoleTextAttribute(hConsole,5);
    } printf("\n");
    SetConsoleTextAttribute(hConsole,7);

    return listeJoueurs;
}


void nouvellePartie(int* nbJoueurs, Joueur* listeJoueurs, Case* cases, char** listeCartesChance, char** listeCartesComm, int* nbCarteC,int* nbCarteComm, Banque* banque) {
    int tour = 0;
    int choix = 0;
    int choixbis = 0;
    int nbJoueursDepart = *nbJoueurs;

    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    do {
        tour += 1;
        SetConsoleTextAttribute(hConsole,5);
        printf("=======================================================| ");
        SetConsoleTextAttribute(hConsole,14);
        printf("Tour %d",tour);
        SetConsoleTextAttribute(hConsole,5);
        printf(" |======================================================");
        SetConsoleTextAttribute(hConsole,7);

        affichagePlateau(listeJoueurs,nbJoueurs,cases);
        for (int i = 0; i < *nbJoueurs; i++) {
            //Initialisation des variables a chaque tour de chaque joueur.
            int nbDoubles =0, lanceDeDes = 0;
            int position = 0, sommeDes = 0;

            SetConsoleTextAttribute(hConsole,14);
            printf("=======*********************| C'est a %s de joueur ! |*********************=======\n", listeJoueurs[i].nomJoueur);
            SetConsoleTextAttribute(hConsole,7);
            do {
                printf("\n* Votre solde : %d euros - Case %d : %s\n",listeJoueurs[i].money,listeJoueurs[i].position,cases[listeJoueurs[i].position-1].nomCase);
                if(listeJoueurs[i].faillite == true){
                    printf("Vous etes en faillite, trouvez de l'argent avant la fin de votre tour sinon vous serez elimine\n");
                }

                //Si le joueur est en prison, on affiche les options qui lui sont possible pour en sortir.
                optionPrison(listeJoueurs,i,listeCartesChance,nbCarteC,listeCartesComm,nbCarteComm,nbJoueurs);

                //On affiche le menu joueur.
                menuJoueur();

                //Verification que choix est bien de type int.
                choix = verifChoix();
                switch ( choix ) {
                    case 1 :
                        //Lancer les d??s. (Appel de la fonction lancerLesDes 1 fois par personne par tour)============//

                        //On v??rif si le joueur n'est pas en prison.
                        //Si c'est le cas alors il n'a le droit qu'a un seul lanc?? par tour, m??me si c'est un double.
                        if(listeJoueurs[i].prison == 1){
                            if(lanceDeDes != 1)
                                lancerDesPrison(listeJoueurs,cases,i,&lanceDeDes);
                            else
                                SetConsoleTextAttribute(hConsole,4);
                                printf("Vous avez deja lance les des!\n");
                                SetConsoleTextAttribute(hConsole,7);
                                break;
                        }

                        //On v??rifie si le joueur (hors cas de prison) n'a pas d??j?? lanc?? les d??s.
                        if(lanceDeDes == 1){
                            SetConsoleTextAttribute(hConsole,4);
                            printf("Vous avez deja lance les des!\n");
                            SetConsoleTextAttribute(hConsole,7);
                            break;
                        }

                        //S'il n'a pas d??j?? lanc?? alors il peut les lancer.
                        //On enregistre la position pr??c??dente du joueur et le retour de la fonction lancerLesDes.
                        position = listeJoueurs[i].position;
                        sommeDes = lancerLesDes(&nbDoubles,&lanceDeDes);

                        //La proc??dure lancerLesDes renvoie 0 si le joueur a fait 3 doubles d'affil??e.
                        //On le met donc en prison.
                        if(sommeDes == 0){
                            listeJoueurs[i].prison = 1;
                            listeJoueurs[i].tourEnPrison = 3;   //Il a au plus encore 3 tours ?? faire en prison.
                            break;   //On break pour qu'il ne prenne pas la prime de 200 euros dans le cas ou il passerait par la case depart.
                        }
                        else{
                            //Sinon on actualise la position.
                            listeJoueurs[i].position = nouvellePosition( listeJoueurs[i].position, sommeDes );
                        }

                        //On ajoute 200 euros au joueur s'il est/ou passe par la case depart.
                        depart(listeJoueurs,i,position,sommeDes);

                        //Affichage position joueur sur le plateau.
                        //Et des diff??rentes actions correspondantes.
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
                        //Hypoth??quer une propri??t??.
                        hypothequer(listeJoueurs,i,cases,banque);
                        break;
                    case 6:
                        //Vendre des biens.
                        vendre(listeJoueurs,i,cases,banque);
                        break;
                    case 7:
                        //Menu Principal
                        printf("=====| Que souhaitez vous faire ? |=======================|\n");
                        printf("1/ Sauvegarder la partie en cours.                        |\n"
                               "2/ Charger une ancienne partie.                           |\n"
                               "3/ Afficher les regles.                                   |\n"
                               "4/ Afficher le nom des membres de l'equipe du projet.     |\n"
                               "5/ Quitter.                                               |\n");
                        printf("==========================================================|\n>");
                        choixbis = verifChoix();
                        switch (choixbis) {
                            case 1:
                                //Sauvegarder la partie.
                                sauvegarder(nbJoueurs,listeJoueurs,cases,listeCartesChance,listeCartesComm,nbCarteC,nbCarteComm,banque);
                                break;
                            case 2:
                                //Charger une partie.
                                break;
                            case 3:
                                //Afficher les regles.
                                printf("Affichage des regles....");
                                break;
                            case 4:
                                //Afficher le nom des membres de l'??quipe du projet.
                                afficherNomsEquipeProjet();
                                break;
                            case 5:
                                //Revenir ?? l'??cran d'accueil.
                                return;
                            default:
                                puts("Choix invalide !");
                                break;
                        }



                    case 0:
                        //Passer son tour.
                        if(listeJoueurs[i].faillite == true && listeJoueurs[i].money < 0 ){
                            printf("Vous etes en faillite!\n"
                                   "Si vous quittez vous serez elimine!\n");
                            printf("> Passer votre tour ? ( 1 = OUI / 2 = NON )\n>");
                            choixbis = verifChoix();
                            switch(choixbis){
                                case 1:
                                    //Le joueur est elimine.
                                    //Proc??dure qui le supprime de la liste des joueurs.
                                    printf("Joueur %d : %s est elimine !\n",i+1,listeJoueurs[i].nomJoueur);
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
                        else if(listeJoueurs[i].faillite == true && listeJoueurs[i].money > 0 ){
                            listeJoueurs[i].faillite = false;
                        }
                        break;
                    default :
                        SetConsoleTextAttribute(hConsole,4);
                        printf("Choix invalide!\n");
                        SetConsoleTextAttribute(hConsole,7);
                        break;
                }
            }while (choix != 0 && *nbJoueurs > 1);
        }
    }while (*nbJoueurs > 1);
    SetConsoleTextAttribute(hConsole,14);
    printf("\n                      __________                      \n"
           "*--------------*|======MONOPOLY======|*--------------*\n"
           "                  GAGNANT : %s                        \n"
           "                                                      \n"
           "                  Argent : %d euros                   \n"
           "*--------------*|====================|*--------------*\n\n"
            ,listeJoueurs[0].nomJoueur,listeJoueurs[0].money );
    SetConsoleTextAttribute(hConsole,7);


    for(int i=0;i<nbJoueursDepart;i++){
        free(listeJoueurs[i].nomJoueur);
    }
    free(listeJoueurs);
    free(cases);
}


//====================================================================================================================//
//Proc??dure en r??f??rence au choix 5 du menu principal.
void afficherNomsEquipeProjet(){
    printf("=====| Liste des membres |=====\n");
    printf("MABILLE Thomas\n"
           "ROBERT Theo\n\n");
}


//====================================================================================================================//





