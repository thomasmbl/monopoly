//
// Created by Thomas on 02/11/2021.
//

#include "mesfonctions.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>

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
           "2/ \n"
           "3/ \n"
           "4/ \n"
           "5/ \n"
           "6/Passer son tour.\n"
           "=========================\n>");
    scanf("%d",&choix);
    return choix;
}

int lancerLesDes(){
    int de1 = 0, de2 = 0, somme=0, nbDoubles = 0;
    do{
        printf("\nLancement des des ! \n");
        //Affectation de valeurs aléatoires pour nos 2 dés (1 à 6).
        de1 = rand()%6+1;
        de2 = rand()%6+1;

        somme += de1 + de2;

        printf("> de1 = %d , de2 = %d , somme = %d\n", de1, de2, somme);

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

    if(nouvelle == 32){                //position = 32 équivaut à la case départ donc 0
        nouvelle = 1;
        return nouvelle;
    }
    else if(nouvelle > 32){
        nouvelle = nouvelle - 32;
        return nouvelle;
    }
}

//====================================================================================================================//
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
    cases[1].prix = 999999999 ;
    cases[1].proprio = "Disponible";


    //2. Taxe d’habitation : Payez 100€
    cases[2].nomCase = "TAXE D'HABITATION";
    cases[2].typeCase = 0;


    //3. Propriété 2 du groupe 1
    cases[3].nomCase = "PLACE DES TERREAUX";
    cases[3].typeCase = 1;
    cases[3].groupe = 1;
    cases[3].prix = 999999999 ;
    cases[3].proprio = "Disponible";


    //4. Raccourci : Avancez à la case 13
    cases[4].nomCase = "RACCOURCI";
    cases[4].typeCase = 0;


    //5. Propriété 1 du groupe 2
    cases[5].nomCase = "PLACE BELLECOUR";
    cases[5].typeCase = 1;
    cases[5].groupe = 2;
    cases[5].prix = 999999999 ;
    cases[5].proprio = "Disponible";


    //6. Tirez une carte communauté
    cases[6].nomCase = "TIRAGE CARTE COMMUNAUTE";
    cases[6].typeCase = 0;


    //7. Propriété 2 du groupe 2
    cases[7].nomCase = "CONFLUENCE";
    cases[7].typeCase = 1;
    cases[7].groupe = 2;
    cases[7].prix = 999999999 ;
    cases[7].proprio = "Disponible";


    //8. Case prison
    cases[8].nomCase = "CASE PRISON";
    cases[8].typeCase = 0;


    //9. Propriété 1 du groupe 3
    cases[9].nomCase = "PART DIEU";
    cases[9].typeCase = 1;
    cases[9].groupe = 3;
    cases[9].prix = 999999999 ;
    cases[9].proprio = "Disponible";


    //10. Impôt sur la fortune : Payez 100€
    cases[10].nomCase = "IMPOT SUR LA FORTUNE";
    cases[10].typeCase = 0;


    //11. Propriété 2 du groupe 3
    cases[11].nomCase = "LES HALLES";
    cases[11].typeCase = 1;
    cases[11].groupe = 3;
    cases[11].prix = 999999999 ;
    cases[11].proprio = "Disponible";


    //12. Raccourci : Avancez à la case 21
    cases[12].nomCase = "RACCOURCI";
    cases[12].typeCase = 0;


    //13. Propriété 1 du groupe 4
    cases[13].nomCase = "PLACE DE LA CROIX ROUSSE";
    cases[13].typeCase = 1;
    cases[13].groupe = 4;
    cases[13].prix = 999999999 ;
    cases[13].proprio = "Disponible";


    //14. Tirez une carte chance
    cases[14].nomCase = "TIRAGE CARTE CHANCE";
    cases[14].typeCase = 0;


    //15. Propriété 2 du groupe 4
    cases[15].nomCase = "THEATRE";
    cases[15].typeCase = 1;
    cases[15].groupe = 4;
    cases[15].prix = 999999999 ;
    cases[15].proprio = "Disponible";


    //16. Case stationnement gratuit
    cases[16].nomCase = "STATIONNEMENT GRATUIT";
    cases[16].typeCase = 0;


    //17. Propriété 1 du groupe 5
    cases[17].nomCase = "BASILIQUE NOTRE DAME DE FOURVIERE";
    cases[17].typeCase = 1;
    cases[17].groupe = 5;
    cases[17].prix = 999999999 ;
    cases[17].proprio = "Disponible";


    //18. Taxe sur les produits de luxe : Payez 200€
    cases[18].nomCase = "TAXE SUR LES PRODUITS DE LUXE";
    cases[18].typeCase = 0;


    //19. Propriété 2 du groupe 5
    cases[19].nomCase = "THEATRE ROMAIN";
    cases[19].typeCase = 1;
    cases[19].groupe = 5;
    cases[19].prix = 999999999 ;
    cases[19].proprio = "Disponible";


    //20. Raccourci : Avancez à la case 29
    cases[20].nomCase = "RACCOURCI";
    cases[20].typeCase = 0;


    //21. Propriété 1 du groupe 6
    cases[21].nomCase = "BROTTEAUX";
    cases[21].typeCase = 1;
    cases[21].groupe = 6;
    cases[21].prix = 999999999 ;
    cases[21].proprio = "Disponible";


    //22. Tirez une carte communauté
    cases[22].nomCase = "TIRAGE CARTE COMMUNAUTE";
    cases[22].typeCase = 0;


    //23. Propriété 2 du groupe 6
    cases[23].nomCase = "PARC DE LA TETE D'OR";
    cases[23].typeCase = 1;
    cases[23].groupe = 6;
    cases[23].prix = 999999999 ;
    cases[23].proprio = "Disponible";


    //24. Allez en prison
    cases[24].nomCase = "ALLER EN PRISON";
    cases[24].typeCase = 0;



    //25. Propriété 1 du groupe 7
    cases[25].nomCase = "GUILLOTIERE";
    cases[25].typeCase = 1;
    cases[25].groupe = 7;
    cases[25].prix = 999999999 ;
    cases[25].proprio = "Disponible";


    //26. Vous trouvez 50€ par terre.
    cases[26].nomCase = "VOUS TROUVEZ 50EUROS";
    cases[26].typeCase = 0;


    //27. Propriété 2 du groupe 7
    cases[27].nomCase = "GERLAND";
    cases[27].typeCase = 1;
    cases[27].groupe = 7;
    cases[27].prix = 999999999 ;
    cases[27].proprio = "Disponible";


    //28. Raccourci : Avancez à la case 5 (Vous passez par la case départ et collectez 200€)
    cases[28].nomCase = "RACCOURCI";
    cases[28].typeCase = 0;


    //29. Propriété 1 du groupe 8
    cases[29].nomCase = "MANUFACTURE DES TABACS";
    cases[29].typeCase = 1;
    cases[29].groupe = 8;
    cases[29].prix = 999999999 ;
    cases[29].proprio = "Disponible";


    //30. Tirez une carte chance
    cases[30].nomCase = "TIRAGE CARTE CHANCE";
    cases[30].typeCase = 0;


    //31. Propriété 2 du groupe 8
    cases[31].nomCase = "MON PLAISIR";
    cases[31].typeCase = 1;
    cases[31].groupe = 8;
    cases[31].prix = 999999999 ;
    cases[31].proprio = "Disponible";



    return cases;
}

//Fonction d'affichage du "plateau" en console ainsi que les informations des joueurs dans la partie.
void affichagePlateau(Joueur* listeJoueurs,int* nbJoueurs) {
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
        printf("Joueur %d : %s - %d euros - Case : %d\n"
               "", i+1, listeJoueurs[i].nomJoueur, listeJoueurs[i].money, listeJoueurs[i].position);
    }
    printf("======================================================\n\n");

}


//====================================================================================================================//
//Fonctions en référence au choix 1 du menu principal.

//Initialisation de la liste de joueurs ( nombre, nom, argent, position sur le plateau).
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

        //initialisation de leurs porte feuille ainsi que de leurs position sur le plateau ( case 0 = départ ).
        listeJoueurs[i].money = 1500;
        listeJoueurs[i].position = 1;
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


void nouvellePartie(int* nbJoueurs, Joueur* listeJoueurs, Case* cases) {
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
                if(listeJoueurs[i].prison == 1){
                    printf("Vous etes en prison ! Pour vous en echapper :\n"
                           "\t1/Faire un double sur l'un de vos %d prochains tours.\n"
                           "\t2/Utiliser la carte : sortie de prison gratuite.\n"
                           "\t3/Acheter la carte : sortie de prison gratuite a un autre joueur et la jouer\n"
                           "\t4/Payer une amande de 50euros avant de lancer les des lors d'un de vos 2 prochains tours\n"
                           "\t5/Si vous ne parvenez pas a faire un double a votre 3eme tour (tour restant : %d), vous payez 50euros\n"
                           ,listeJoueurs[i].tourEnPrison,listeJoueurs[i].tourEnPrison);
                }

                choix = menuJoueur();
                switch ( choix ) {
                    case 1 :
                        //Lancer les dés. (Appel de la fonction lancerLesDes 1 fois par personne par tour).

                        //On verif si le joueur n'est pas en prison.
                        //Si c'est le cas alors il n'a le droit qu'a un seul lancé par tour, même si c'est un double.
                        if(listeJoueurs[i].prison == 1){

                            if(lanceDeDes == 1){
                                printf("Vous avez deja lance les des!\n");
                                break;
                            }

                            if(listeJoueurs[i].tourEnPrison != 1){
                                int de1 = rand()%6 +1;
                                int de2 = rand()%6 +1;
                                lanceDeDes = 1;

                                if(de1==de2) {
                                    printf("Dés : %d et %d"
                                           "Bravo vous etes libre !\n"
                                           "Vous avancez de %d cases.\n",2*de1);
                                    listeJoueurs[i].prison = 0;
                                    listeJoueurs[i].tourEnPrison = 0;
                                    listeJoueurs[i].position = nouvellePosition(listeJoueurs[i].position, de1 + de2);
                                    printf("\nVous etes maintenant sur la case %d : %s\n",listeJoueurs[i].position, cases[listeJoueurs[i].position-1].nomCase);
                                    break;
                                }
                                else{
                                    printf("Vous n'avez pas fait de double, dommage reessayez au tour prochain\n");
                                    listeJoueurs[i].tourEnPrison -= 1;
                                    break;
                                }
                            }

                            else if(listeJoueurs[i].tourEnPrison == 1){
                                int de1 = rand()%6 +1;
                                int de2 = rand()%6 +1;
                                lanceDeDes = 1;

                                if(de1==de2) {
                                    printf("Bravo vous etes libre !\n"
                                           "Vous avancez de %d cases.\n",2*de1);
                                    listeJoueurs[i].prison = 0;
                                    listeJoueurs[i].tourEnPrison = 0;
                                    listeJoueurs[i].position = nouvellePosition(listeJoueurs[i].position, de1 + de2);
                                    printf("\nVous etes maintenant sur la case %d : %s\n",listeJoueurs[i].position, cases[listeJoueurs[i].position-1].nomCase);
                                    break;
                                }
                                else{
                                    printf("Vous n'avez pas fait de double, payez 50 euros pour votre liberation\n");
                                    listeJoueurs[i].money -= 50;
                                    listeJoueurs[i].prison = 0;
                                    listeJoueurs[i].tourEnPrison = 0;
                                    listeJoueurs[i].position = nouvellePosition(listeJoueurs[i].position, de1 + de2);
                                    printf("\nVous etes maintenant sur la case %d : %s\n",listeJoueurs[i].position, cases[listeJoueurs[i].position-1].nomCase);
                                    break;
                                }

                            }

                        }

                        //Donc on vérifie si le joueur (hors cas de prison) n'a pas déjà lancé les dés.
                        if(lanceDeDes == 1){
                            printf("Vous avez deja lance les des!\n");
                            break;
                        }

                        //Si il n'a pas déjà lancé alors il peut les lancer.
                        //On modifie la position des joueurs.
                        position = listeJoueurs[i].position;
                        sommeDes = lancerLesDes();
                        if(sommeDes == 0){
                            listeJoueurs[i].prison = 1;
                            listeJoueurs[i].tourEnPrison = 3;   //Il a au plus encore 3 tours à faire en prison.
                            break;
                        }
                        listeJoueurs[i].position = nouvellePosition( listeJoueurs[i].position, sommeDes );
                        lanceDeDes = 1;


                        //Differentes actions en fonction de la case sur laquelle se trouve le joueur ================//
                        //On ajoute 200 euros au joueur si il est/ou passe par la case depart.
                        if( listeJoueurs[i].position == 1 || position+sommeDes >= 32 ){
                            printf("\nBanque: Passage par la case depart, vous recevez 200 euros!\n");
                            listeJoueurs[i].money += 200;
                        }

                        printf("\nVous etes maintenant sur la case %d : %s\n",listeJoueurs[i].position, cases[listeJoueurs[i].position-1].nomCase);

                        //Si le joueur se trouve sur une propriete, on affiche les informations utiles.
                        if(cases[listeJoueurs[i].position-1].typeCase == 1){
                            printf("==> Vous vous trouvez sur une case PROPRIETE\n"
                                   "\tStatus : %s\n"
                                   "\tPrix d'achat : %d\n"
                                   "\tGroupe : %d\n"
                                   ,cases[listeJoueurs[i].position-1].proprio
                                   ,cases[listeJoueurs[i].position-1].prix
                                   ,cases[listeJoueurs[i].position-1].groupe);
                        }
                        //Cases tirage carte communauté.
                        else if(cases[listeJoueurs[i].position-1].typeCase == 2){
                            printf("Tirage carte communaute\n");
                            //Faire fonction sur les tirages de carte communaute.
                        }
                        //Cases tirage carte chance.
                        else if(cases[listeJoueurs[i].position-1].typeCase == 3){
                            printf("Tirage carte carte\n");
                            //Faire fonction sur les tirages de carte chance.
                        }

                        else if(listeJoueurs[i].position == 3){
                            printf("Banque: taxe d'habitation, payez 100euros !\n");
                            listeJoueurs[i].money -= 100;
                        }

                        else if(listeJoueurs[i].position == 5){
                            printf("Raccourci: Hop direct a la case 13 !\n");
                            listeJoueurs[i].position = 13;
                        }

                        else if(listeJoueurs[i].position == 9){
                            printf("Vous etes en visite en Prison, ne craignez rien...\n");
                        }

                        else if(listeJoueurs[i].position == 11){
                            printf("Banque: Impot sur la fortune, payez 100euros !\n");
                            listeJoueurs[i].money -= 100;
                        }

                        else if(listeJoueurs[i].position == 13){
                            printf("Raccourci: Hop direct a la case 21 !\n");
                            listeJoueurs[i].position = 21;
                        }

                        else if(listeJoueurs[i].position == 19){
                            printf("Banque: Taxe sur les produits de luxe, payez 200euros !\n"),
                                    listeJoueurs[i].money -= 200;
                        }

                        else if(listeJoueurs[i].position == 21){
                            printf("Raccourci: Hop direct a la case 29 !\n");
                            listeJoueurs[i].position = 29;
                        }

                        else if(listeJoueurs[i].position == 25){
                            printf("Raccourci PRISON HAHA: Hop direct a la case 9 ( sans argent :c )\n");
                            listeJoueurs[i].position = 9;
                            listeJoueurs[i].prison = 1;
                            listeJoueurs[i].tourEnPrison = 3;
                        }

                        else if(listeJoueurs[i].position == 27){
                            printf("La chance..vous trouvez 50euros par terre !\n");
                            listeJoueurs[i].money += 50;
                        }

                        else if(listeJoueurs[i].position == 29){
                            printf("Raccourci: Hop direct a la case 5 !\n");
                            printf("Banque: Passage par la case depart, vous recevez 200 euros!\n");
                            listeJoueurs[i].position = 5;
                            listeJoueurs[i].money += 200;
                        }

                        break;
                    case 2 :
                        break;
                        //
                    case 6 :
                        //Passer son tour.
                        break;
                    default :
                        printf("Choix invalide!\n");
                        break;
                }
            }while (choix != 6);
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





