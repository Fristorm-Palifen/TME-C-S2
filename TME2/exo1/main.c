#include "entreeSortieLC.h"
#include "biblioLC.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void menu() { // presente les choix à l'utilisateur
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
  if (argc !=3){
    printf("\e[1;31m");
    printf("\n\n\nLe nombre d'arguments n'est pas bon!!\n\n\n");
    printf("\e[0m");
    return 1;
  }
  Biblio *b = charger_n_entrees( argv[1] , atoi(argv[2]) ) ; // cree une bibliotheque de reference pour faire quelques tests avec
  int fin =0;
  do{

    menu();
    int choix_menu;
    char buffer[256];

    char fichier[30] ;
    fflush(stdin);
    fgets(buffer, 256, stdin); 
    sscanf(buffer, "%1d", &choix_menu);
    printf("\n");
    fflush(stdin);
    
    switch(choix_menu){ //traite chaque cas {0..8}
      case 0:
        printf("Vous avez choisi de creer une bibliotheque\n");
        printf("\nVous allez creer une bibliotheque de n lignes à partir du fichier %s",argv[1] ) ;
        fflush(stdin);
        int nlignes ;
        printf("\nentreer le nombre de lignes : "); // demande à l'utilisateur combien de lignes il souhaite
        fgets(buffer , 256, stdin ) ;
        sscanf( buffer , "%6d", &nlignes ) ;
        Biblio *bb = charger_n_entrees( argv[1] , nlignes ) ;
        affiche_biblio( bb ) ;

        char rep[1] ; // permet de sauvegarder les donnees de la bibliotheque créer dans un fichier si l'utilisateur le souhaite
        printf("\nVoulez-vous sauvegarder cette bibiliotheque [Y/N]?");
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

      case 1:
        printf("Vous avez choisi d'ajouter un livre a la bilbiotheque");
        printf("\nChoisir quel livre ajouter") ;

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

        inserer_en_tete( b , numero , titre , auteur ) ;
        affiche_biblio( b ) ;

        printf("\nVoulez-vous sauvegarder cette bibiliotheque [Y/N]? ");
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
      case 2:
        printf("Affichage : \n");
        affiche_biblio( b );
        break;
      case 3:

        printf("Vous avez choisi de chercher un livre par son numero");
        fflush(stdin);
        printf("\nentreer le numero : ") ;
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%6d", &numero);
        printf("\n");

        recherche_ouvrage_num( b, numero) ;

        break;
      case 4:

        printf("Vous avez choisi de chercher un livre par son titre");
        printf("\nentreer le titre : ");
        fflush(stdin);
        fgets(buffer, 256, stdin) ;
        sscanf(buffer, "%100s", titre) ;

        recherche_ouvrage_titre( b , titre ) ;

        break;
      case 5:

        printf("Vous avez choisi de cherche tous les livres d'un auteur");
        printf("\nentreer l'auteur : ") ;
        fflush(stdin);
        fgets( buffer ,256 ,stdin) ;
        sscanf( buffer , "%100s", auteur) ;
        bb = recherche_auteur( b , auteur ) ;
        affiche_biblio( bb ) ;

        printf("\nVoulez-vous sauvegarder cette bibiliotheque [Y/N]? ");
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
      case 6:
        printf("Vous avez choisi de supprimer un livre");
  
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
        
        supprimer_ouvrage( b , numero , titre , auteur );
        affiche_biblio( b ) ;

        printf("\nVoulez-vous sauvegarder cette bibiliotheque [Y/N]? ");
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
      case 7:
        printf("Vous avez choisi de fusionner deux bibliotheques");

        printf("\nTout d'abord, nous allons creer une bibliotheque de n lignes à partir du fichier %s pour la faire fusionner avec notre bibliotheque de reference\n",argv[1] ) ;
        fflush(stdin);
        printf("\nentreer le nombre de lignes : ");
        fgets(buffer , 256, stdin ) ;
        sscanf( buffer , "%6d", &nlignes ) ;
        bb = charger_n_entrees( argv[1] , nlignes ) ;

        printf("\nVoici nos deux bibliotheques :\n");

        affiche_biblio( b ) ;printf("\n\n");
        affiche_biblio( bb ) ;
        printf("\nNous allons maintenant les fusionner :\n");
        fusion( b , bb ) ;

        printf("\nResultat de la fusion :\n");
        affiche_biblio( b );

        printf("\nVoulez-vous sauvegarder cette bibiliotheque [Y/N]? ");
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
      case 8:
        printf("\nVous avez choisi de chercher les ouvrages identiques\n");
        
        bb = ouvrage_identique( b ) ;
        affiche_biblio( bb ) ;

        liberer_biblio( bb ) ;

        break;
      case 9:
        printf("\nMerci et aurevoir\n\n");
        fin=1;
        break;
      default:
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
