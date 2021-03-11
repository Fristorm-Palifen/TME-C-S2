#include "entreeSortieLC.h"
#include "biblioLC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void menu() { // affiche sur la console les actions possibles sur la bibliotheques
  printf("\e[1;92m");
  printf("Bienvenue sur le mini Projet 2 de Theophane et Francois-Xavier\nEXERCICE 1 :\n\nVous allez devoir choisir entre plusieurs options afin de naviguer dans le programme.\n\n");
  printf("\e[1;36m");
  printf("\nPour creer une bibiliotheque tapez 0\nPour ajouter un Livre a la bibliotheque tapez 1 \nPour Afficher une biblioteque tapez 2\nPour rechercher un ouvrage par son numero tapez 3 \nPour rechercher un ouvrage par son titre tapez 4\nPour rechercher de tous les livres d’un meme auteur tapez 5 \nPour supprimer un ouvrage tapez 6 \nPour fusionner deux bibliotheques tapez 7 \nPour rechercher tous les ouvrages avec plusieurs exemplaires tapez 8");
  printf("\e[1;31m");
  printf("\n\nEnfin Pour quitter le programme tapez 9\n");
  printf("\n");
  printf("\e[0m");
  printf("Veuillez entrer votre choix: ");
  
}


int main(int argc, char** argv) {
  if (argc !=3){ // verifie que le nombre d'argument est respecter
    printf("\e[1;31m");
    printf("\n\n\nLe nombre d'arguments n'est pas bon!!\n\n\n");
    printf("\e[0m");
    return 1;
  }
  Biblio *b = charger_n_entrees( argv[1] , atoi(argv[2]) ) ; // bibliotheque de reference
  int fin =0;
  do{

    menu(); //affiche les options
    int choix_menu;
    char buffer[256];

    char fichier[30] ;
    fflush(stdin);
    fgets(buffer, 256, stdin); //recupere la demande de l'utilisateur sur le clavier
    sscanf(buffer, "%1d", &choix_menu);
    printf("\n");
    fflush(stdin); // nettoie
    
    switch(choix_menu){
      case 0: //creer une binliotheque
        printf("Vous avez choisi de creer une bibliotheque\n");
        printf("\nVous allez creer une bibliotheque de n lignes à partir du fichier %s",argv[1] ) ;
        fflush(stdin);
        int nlignes ;
        printf("\nentreer le nombre de lignes : ");//on demande d'entreer le nombre de lignes/livres souhaiter pour la bibliotheque
        fgets(buffer , 256, stdin ) ;
        sscanf( buffer , "%6d", &nlignes ) ;
        Biblio *bb = charger_n_entrees( argv[1] , nlignes ) ; // et on crée la bibliotheque en fonction du choix
        affiche_biblio( bb ) ; //affiche la nibliotheque créer

        char rep[1] ;
        printf("\nVoulez-vous sauvegarder cette bibiliotheque [Y/N]?"); //demande si il souhaite enregistrer cette bibliotheque dans un fichier
        fgets( buffer , 256 , stdin );
        sscanf( buffer , "%s" , rep );
        fflush(stdin);

        if( strcmp( rep , "Y") == 0 ){ //si Y alors on sauvegarde

          printf("\nDans quel fichier souhaitez-vous sauvegarder votre bibiliotheque ?\n");
          fgets(buffer , 256 , stdin ) ; //demande le nom du fichier souhaiter
          sscanf( buffer , "%s" , fichier );
          fflush(stdin) ;

          enregistrer_biblio( bb , fichier ); //écrit la biliotheque dans le fichier
          printf("\nLa bibliotheque a ete sauvegarder dans %s\n",fichier);
        }


        liberer_biblio( bb ) ;
        break;

      case 1: // ajouter un livre à la bibliotheque de reference
        printf("Vous avez choisi d'ajouter un livre\n");
        printf("\nChoisir quel livre ajouter") ;
        //demande les attributs du livre à l'utilisateur

        char auteur[30], titre[30] ; int numero ;
        char buffer[256] ;
        printf("\nentrer le numero : ");
        fgets( buffer , 256 , stdin ) ;
        sscanf( buffer , "%6d", &numero ) ;
        printf("\nnum = %d\n",numero);
        fflush(stdin) ;
 
        printf("\nentrer le titre : ");
        fgets( buffer , 256 , stdin );
        sscanf( buffer , "%s" , titre );
        fflush(stdin) ;
        printf("\ntitre = %s\n",titre);

        printf("\nentrer l'auteur : ") ;
        fgets( buffer , 256 , stdin ) ;
        sscanf( buffer , "%s" , auteur );
        fflush(stdin) ;
        printf("\nauteur = %s\n",auteur) ;

        printf("\nnum=%d , titre=%s , auteur=%s\n\n",numero,titre,auteur);

        inserer_en_tete( b , numero , titre , auteur ) ; //ajoute le livre
        affiche_biblio( b ) ;

        printf("\nVoulez-vous sauvegarder cette bibiliotheque [Y/N]? "); //demande de sauvegarde, car modification sur la bibliotheque
        fgets( buffer , 256 , stdin );
        sscanf( buffer , "%s" , rep );
        fflush(stdin);

        if( strcmp( rep , "Y") == 0 ){

          printf("\nDans quel fichier souhaitez-vous sauvegarder votre bibiliotheque ?\n");
          fgets(buffer , 256 , stdin ) ;
          sscanf( buffer , "%s" , fichier );
          fflush(stdin) ;

          enregistrer_biblio( b , fichier );
          printf("\nLa bibliotheque a ete sauvegarder dans %s\n",fichier);
        }
        

        break;
      case 2: //afficher la bibliotheque de reference
        printf("Affichage :\n");
        affiche_biblio( b );
        break;

      case 3: //chercher un livre avec son num

        printf("Vous allez chercher un livre avec son numero");
        fflush(stdin);
        printf("\nentreer le numero : ") ; //demande le numero
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%6d", &numero);
        printf("\n");

        recherche_ouvrage_num( b, numero) ; //cherche le livre

        break;
      case 4: // cherche un livre avec son titre

        printf("Vous allez chercher un livre par son titre");
        printf("\nentreer le titre : "); //demande le titre
        fflush(stdin);
        fgets(buffer, 256, stdin) ;
        sscanf(buffer, "%100s", titre) ;

        recherche_ouvrage_titre( b , titre ) ; //cherche le livre

        break;
      case 5: //cherche les livres d'un auteur

        printf("Vous alle chercher les livres d'un auteur");
        printf("\nentreer l'auteur : ") ; //demande l'auteur
        fflush(stdin);
        fgets( buffer ,256 ,stdin) ;
        sscanf( buffer , "%100s", auteur) ;
        bb = recherche_auteur( b , auteur ) ; //on prend la bibliotheque resultat
        affiche_biblio( bb ) ; //on l'affiche

        printf("\nVoulez-vous sauvegarder cette bibiliotheque [Y/N]? "); //demande de sauvegarde
        fgets( buffer , 256 , stdin );
        sscanf( buffer , "%s" , rep );
        fflush(stdin);

        if( strcmp( rep , "Y") == 0 ){
          
          printf("\nDans quel fichier souhaitez-vous sauvegarder votre bibiliotheque ?\n");
          fgets(buffer , 256 , stdin ) ;
          sscanf( buffer , "%s" , fichier );
          fflush(stdin) ;

          enregistrer_biblio( bb , fichier );
          printf("\nLa bibliotheque a ete sauvegarder dans %s\n",fichier);
        }
        liberer_biblio( bb ) ;

        break;
      case 6: //supprimer un livre
        printf("Vous alle supprimer un livre");

        //demande les attributs du livre
  
        printf("\nentrer le numero : ");
        fgets( buffer , 256 , stdin ) ;
        sscanf( buffer , "%6d", &numero ) ;
        fflush(stdin);
 
        printf("\nentrer le titre : ");
        fgets( buffer , 256 , stdin ) ;
        sscanf( buffer , "%15s" , titre);
        fflush(stdin);

        printf("\nentrer l'auteur : ") ;
        fgets( buffer , 256 , stdin ) ;
        sscanf( buffer , "%15s" , auteur);
        fflush(stdin);

        printf("\nnum = %d , titre = %s , auteur = %s\n",numero,titre,auteur);
        
        supprimer_ouvrage( b , numero , titre , auteur ); //cherche à supprimer le livre
        affiche_biblio( b ) ; //affiche la bibliotheque sans le livre

        printf("\nVoulez-vous sauvegarder cette bibiliotheque [Y/N]? ");//demande de sauvegarde car modification sur la bibliotheque
        fgets( buffer , 256 , stdin );
        sscanf( buffer , "%s" , rep );
        fflush(stdin);

        if( strcmp( rep , "Y") == 0 ){
          
          printf("\nDans quel fichier souhaitez-vous sauvegarder votre bibiliotheque ?\n");
          fgets(buffer , 256 , stdin ) ;
          sscanf( buffer , "%s" , fichier );
          fflush(stdin) ;

          enregistrer_biblio( b , fichier );
          printf("\nLa bibliotheque a ete sauvegarder dans %s\n",fichier);
        }

        
        break;
      case 7://fusionner 2 bibliotheques
        printf("Vous allez fusinner deux bibliotheques");

        printf("\nTout d'abord, nous allons creer une bibliotheque de n lignes à partir du fichier %s pour la faire fusionner avec notre bibliotheque de reference\n",argv[1] ) ;
        fflush(stdin);
        //crée une biblio pour la fusionner à celle de reference
        printf("\nentreer le nombre de lignes : ");//demande donc le nombre de lignes
        fgets(buffer , 256, stdin ) ;
        sscanf( buffer , "%6d", &nlignes ) ;
        bb = charger_n_entrees( argv[1] , nlignes ) ;

        printf("\nVoici nos deux bibliotheques :\n");
        //affiche les deux bibliotheques
        affiche_biblio( b ) ;printf("\n\n");
        affiche_biblio( bb ) ;
        printf("\nNous allons maintenant les fusionner :\n");
        fusion( b , bb ) ;//les fusionne

        printf("\nResultat de la fusion :\n");
        affiche_biblio( b );//affiche le resultat

        printf("\nVoulez-vous sauvegarder cette bibiliotheque [Y/N]? ");//demande de sauvegarde
        fgets( buffer , 256 , stdin );
        sscanf( buffer , "%s" , rep );
        fflush(stdin);

        if( strcmp( rep , "Y") == 0 ){
          
          printf("\nDans quel fichier souhaitez-vous sauvegarder votre bibiliotheque ?\n");
          fgets(buffer , 256 , stdin ) ;
          sscanf( buffer , "%s" , fichier );
          fflush(stdin) ;

          enregistrer_biblio( b , fichier );
          printf("\nLa bibliotheque a ete sauvegarder dans %s\n",fichier);
        }

        break;
      case 8://cherche exemplaires identiques
        printf("\nVous avez choisi d'avoir les livres en doubles\n");
        
        bb = ouvrage_identique( b ) ; // sort la bibliotheque resultat
        affiche_biblio( bb ) ; // l'affiche

        printf("\nVoulez-vous sauvegarder cette bibiliotheque [Y/N]? ");//demande de sauvegarde
        fgets( buffer , 256 , stdin );
        sscanf( buffer , "%s" , rep );
        fflush(stdin);

        if( strcmp( rep , "Y") == 0 ){
          
          printf("\nDans quel fichier souhaitez-vous sauvegarder votre bibiliotheque ?\n");
          fgets(buffer , 256 , stdin ) ;
          sscanf( buffer , "%s" , fichier );
          fflush(stdin) ;

          enregistrer_biblio( bb , fichier );
          printf("\nLa bibliotheque a ete sauvegarder dans %s\n",fichier);
        }

        liberer_biblio( bb ) ;

        break;
      case 9:
        printf("\nMerci et aurevoir\n\n");
        fin=1;
        break;
      default://si erreur de saisie
        printf("Erreur, Veuillez relancer le programme\n");
        fin=1;
        break;


    }
    if (fin==1){ break;}
    printf("\n\n");
  }while(1);

  liberer_biblio( b ) ;




  
  return 0 ;
}
