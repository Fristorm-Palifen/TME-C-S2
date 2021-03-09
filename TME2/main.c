#include "entreeSortieLC.h"
#include "biblioLC.h"
#include "biblioH.h"
#include "entreeSortieH.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

void menu() {
  printf("\e[1;92m");
  printf("Bienvenue sur le mini Projet 2 de Theophane et Francois-Xavier\nVous allez devoir choisir entre plusieurs options afin de naviguer dans le programme.\n\n");
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
  Biblio *b = charger_n_entrees( argv[1] , atoi(argv[2]) ) ;
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
    
    switch(choix_menu){
      case 0:
        printf("Place_holder\n");
        printf("\nVous allez creer une bibliotheque de n lignes à partir du fichier %s",argv[1] ) ;
        fflush(stdin);
        int nlignes ;
        printf("\nentreer le nombre de lignes : ");
        fgets(buffer , 256, stdin ) ;
        sscanf( buffer , "%6d", &nlignes ) ;
        Biblio *bb = charger_n_entrees( argv[1] , nlignes ) ;
        affiche_biblio( bb ) ;

        char rep[1] ;
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
        printf("Place_holder");
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
        printf("Place_holder\n");
        affiche_biblio( b );
        break;
      case 3:

        printf("Place_holder");
        fflush(stdin);
        printf("\nentreer le numero : ") ;
        fgets(buffer, 256, stdin);
        sscanf(buffer, "%6d", &numero);
        printf("\n");

        recherche_ouvrage_num( b, numero) ;

        break;
      case 4:

        printf("Place_holder");
        printf("\nentreer le titre : ");
        fflush(stdin);
        fgets(buffer, 256, stdin) ;
        sscanf(buffer, "%100s", titre) ;

        recherche_ouvrage_titre( b , titre ) ;

        break;
      case 5:

        printf("Place_holder");
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
        printf("Place_holder");
  
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
        printf("Place_holder");

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
        printf("\nPlace_holder\n");
        
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

  enregistrer_biblio( b, "save_b.txt" ) ;
  liberer_biblio( b ) ;








  //EXERCICE 3 :

  printf("\n\n\nLES RESULTATS QUI VONT S'AFFICHER SONT DES RESULTATS POUR L'EXERCICE 3, POUR COMPARER LES TEMPS DE CALCULS DES STRUCTURES.\nILS NE VOUS SONT DONC D'AUCUNE UTILITE ICI.\n\n\n");
  usleep(10000000) ;
 


  unsigned long temps_initial1, temps_initial2, temps_final1, temps_final2 ; // pour pouvoir faire nos graphiques
  double temps1, temps2 ;
  int n ;
  Biblio *b1 ; 
  BiblioH *b2 ;

  //pour comparer les temps pour trouver num
  //=========================================================================
  FILE *f1 = fopen( "comparaison_num.txt" , "w");
  for( n = 100 ; n < 5000 ; n+=100 ){

   
    b1 = charger_n_entrees( "GdeBiblio.txt" , n );
    b2 = charger_n_entreesH( "GdeBiblio.txt" , n );
    //calcule les temps cpu
    temps_initial1 = clock() ;
    recherche_ouvrage_num( b1 , n-10 ) ;
    temps_final1 = clock() ;
    temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

    temps_initial2 = clock() ;
    recherche_ouvrage_numH( b2 , n-10 );
    temps_final2 = clock() ;
    temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;

    fprintf(f1, "%d %f %f\n", n, temps1, temps2); // écrit les resultats dans le fichier
    liberer_biblio( b1 ) ;
    liberer_biblioH( b2 );
  }
  fclose( f1 );
  //voir avec les courbes
  //=========================================================================


  //pour comparer les temps de recherce titre
  //=========================================================================
  

  FILE *f2 = fopen( "comparaison_titre.txt", "w") ;
  b1 = charger_n_entrees( "GdeBiblio.txt" , 100 );
  b2 = charger_n_entreesH( "GdeBiblio.txt" , 100 );

  temps_initial1 = clock() ;
  recherche_ouvrage_titre( b1 , "WEWPJVYGEH" );
  temps_final1 = clock() ;
  temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

  temps_initial2 = clock() ;
  recherche_ouvrage_titreH( b2 , "WEWPJVYGEH" );
  temps_final2 = clock() ;
  temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;

  fprintf(f2, "%d %f %f\n", n, temps1, temps2); // écrit les resultats dans le fichier

  temps_initial1 = clock() ;
  recherche_ouvrage_titre( b1 , "TYCBMJAWWMNINEPFD" );
  temps_final1 = clock() ;
  temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

  temps_initial2 = clock() ;
  recherche_ouvrage_titreH( b2 , "TYCBMJAWWMNINEPFD" );
  temps_final2 = clock() ;
  temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;

  fprintf(f2, "%d %f %f\n", n, temps1, temps2); // écrit les resultats dans le fichier

  temps_initial1 = clock() ;
  recherche_ouvrage_titre( b1 , "QSEKEJHZKSKLF" );
  temps_final1 = clock() ;
  temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

  temps_initial2 = clock() ;
  recherche_ouvrage_titreH( b2 , "QSEKEJHZKSKLF" );
  temps_final2 = clock() ;
  temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;

  fprintf(f2, "%d %f %f\n", n, temps1, temps2); // écrit les resultats dans le fichier

  temps_initial1 = clock() ;
  recherche_ouvrage_titre( b1 , "non" );
  temps_final1 = clock() ;
  temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

  temps_initial2 = clock() ;
  recherche_ouvrage_titreH( b2 , "non" );
  temps_final2 = clock() ;
  temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;

  fprintf(f2, "%d %f %f\n", n, temps1, temps2); // écrit les resultats dans le fichier

  fclose( f2 );

  //temps hachage meilleur que liste
  //=========================================================================


  //comparaison des recherches auteur 
  //=========================================================================

  Biblio *bb1 ; BiblioH *bb2 ;
  liberer_biblio( b1 ) ;
  liberer_biblioH( b2 ) ;

  b1 = charger_n_entrees( "GdeBiblio.txt" , 5000 );
  b2 = charger_n_entreesH( "GdeBiblio.txt" , 5000 );

  FILE *f3 = fopen( "comparaison_auteur.txt", "w" );

  temps_initial1 = clock() ;
  bb1 = recherche_auteur( b1 , "plu" );
  temps_final1 = clock() ;
  temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

  temps_initial2 = clock() ;
  bb2 = recherche_auteurH( b2 , "plu" );
  temps_final2 = clock() ;
  temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;

  liberer_biblio( bb1 ); liberer_biblioH( bb2 );

  fprintf(f3, "%d %f %f\n", n, temps1, temps2); // écrit les resultats dans le fichier



  temps_initial1 = clock() ;
  bb1 = recherche_auteur( b1 , "ndyhygxnptnf" );
  temps_final1 = clock() ;
  temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

  temps_initial2 = clock() ;
  bb2 = recherche_auteurH( b2 , "ndyhygxnptnf" );
  temps_final2 = clock() ;
  temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;

  liberer_biblio( bb1 ); liberer_biblioH( bb2 );

  fprintf(f3, "%d %f %f\n", n, temps1, temps2); // écrit les resultats dans le fichier

  temps_initial1 = clock() ;
  bb1 = recherche_auteur( b1 , "kzyoyymcv" );
  temps_final1 = clock() ;
  temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

  temps_initial2 = clock() ;
  bb2 = recherche_auteurH( b2 , "kzyoyymcv" );
  temps_final2 = clock() ;
  temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;

  liberer_biblio( bb1 ); liberer_biblioH( bb2 );

  fprintf(f3, "%d %f %f\n", n, temps1, temps2); // écrit les resultats dans le fichier

  temps_initial1 = clock() ;
  bb1 = recherche_auteur( b1 , "szhwx" );
  temps_final1 = clock() ;
  temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

  temps_initial2 = clock() ;
  bb2 = recherche_auteurH( b2 , "szhwx" );
  temps_final2 = clock() ;
  temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;

  liberer_biblio( bb1 ); liberer_biblioH( bb2 );

  fprintf(f3, "%d %f %f\n", n, temps1, temps2); // écrit les resultats dans le fichier

  fclose( f3 );
  // temps liste meilleur que temps hachage
  //=========================================================================


  //Modification de la taille de hachage
  //=========================================================================
  //Pour recherche num :

  FILE *f4 = fopen("num_diminue_taille_hachage.txt","w");
  for(int i = 0 ; i < 100 ; i++ ){ // on baisse la taille à chaque iterations
    b2->m -= 20 ;

    temps_initial1 = clock() ;
    recherche_ouvrage_num( b1 , 4000 ) ;
    temps_final1 = clock() ;
    temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

    temps_initial2 = clock() ;
    recherche_ouvrage_numH( b2 , 4000 );
    temps_final2 = clock() ;
    temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;
    fprintf(f4 ,"%d %f %f\n",b2->m, temps1,temps2);

  }fclose(f4);

  for(int i = 0 ; i < 100 ; i++ ){ // pour revenir à la taille de base
    b2->m += 20 ;
  }

  FILE *f5 = fopen("num_augmente_taille_hachage.txt","w");
  for(int i = 0 ; i < 100 ; i++ ){ // on augmente la taille à chaque iterations
    b2->m += 20 ;

    temps_initial1 = clock() ;
    recherche_ouvrage_num( b1 , 4000 ) ;
    temps_final1 = clock() ;
    temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

    temps_initial2 = clock() ;
    recherche_ouvrage_numH( b2 , 4000 );
    temps_final2 = clock() ;
    temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;
    fprintf(f5 ,"%d %f %f\n",b2->m, temps1,temps2);

  }fclose(f5);

  for(int i = 0 ; i < 100 ; i++ ){ // remettre la taille de base
    b2->m -= 20 ;
  }


  //pour recherche titre  :
  FILE *f6 = fopen("titre_diminue_taille_hachage.txt","w");
  for(int i = 0 ; i < 100 ; i++ ){ // on baisse la taille à chaque iterations
    b2->m -= 20 ;

    temps_initial1 = clock() ;
    recherche_ouvrage_num( b1 , 4000 ) ;
    temps_final1 = clock() ;
    temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

    temps_initial2 = clock() ;
    recherche_ouvrage_numH( b2 , 4000 );
    temps_final2 = clock() ;
    temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;
    fprintf(f6 ,"%d %f %f\n",b2->m, temps1,temps2);

  }fclose(f6);

  for(int i = 0 ; i < 100 ; i++ ){ // pour revenir à la taille de base
    b2->m += 20 ;
  }

  FILE *f7 = fopen("titre_augmente_taille_hachage.txt","w");
  for(int i = 0 ; i < 100 ; i++ ){ // on augmente la taille à chaque iterations
    b2->m += 20 ;

    temps_initial1 = clock() ;
    recherche_ouvrage_num( b1 , 4000 ) ;
    temps_final1 = clock() ;
    temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

    temps_initial2 = clock() ;
    recherche_ouvrage_numH( b2 , 4000 );
    temps_final2 = clock() ;
    temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;
    fprintf(f7 ,"%d %f %f\n",b2->m, temps1,temps2);

  }fclose(f7);

  for(int i = 0 ; i < 100 ; i++ ){ // remettre la taille de base
    b2->m -= 20 ;
  }




  //=========================================================================


  
  return 0 ;
}
