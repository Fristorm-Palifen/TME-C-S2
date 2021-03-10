#include "entreeSortieLC.h"
#include "biblioLC.h"
#include "biblioH.h"
#include "entreeSortieH.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>




int main(int argc, char** argv) {

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
    recherche_ouvrage_titre( b1 , "DRYGXRXKFHICAINHW" ) ;
    temps_final1 = clock() ;
    temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

    temps_initial2 = clock() ;
    recherche_ouvrage_titreH( b2 , "DRYGXRXKFHICAINHW" );
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
    recherche_ouvrage_titre( b1 , "DRYGXRXKFHICAINHW" ) ;
    temps_final1 = clock() ;
    temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

    temps_initial2 = clock() ;
    recherche_ouvrage_titreH( b2 , "DRYGXRXKFHICAINHW" );
    temps_final2 = clock() ;
    temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;
    fprintf(f7 ,"%d %f %f\n",b2->m, temps1,temps2);

  }fclose(f7);

  for(int i = 0 ; i < 100 ; i++ ){ // remettre la taille de base
    b2->m -= 20 ;
  }




  //=========================================================================

  /*
  FILE *f8 = fopen("auteur_augmente_taille_hachage.txt","w");
  for(int i = 0 ; i < 100 ; i++ ){ // on augmente la taille à chaque iterations
    b2->m += 1 ;

    temps_initial1 = clock() ;
    recherche_auteur( b1 , "lkq" ) ;
    temps_final1 = clock() ;
    temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

    temps_initial2 = clock() ;
    recherche_auteurH( b2 , "lkq" );
    temps_final2 = clock() ;
    temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;
    fprintf(f8 ,"%d %f %f\n",b2->m, temps1,temps2);

  }fclose(f8);*/


  //3.3
  printf("\n\n\n3.3\n\n\n");
  FILE *f9 = fopen("recherche_ouvrages.txt","w") ;
  for(int n = 1000; n <= 50000; n += 1000) {
    b1 = charger_n_entrees(argv[1], n);
    b2 = charger_n_entreesH(argv[1], n);

    temps_initial1 = clock();
    bb1 = ouvrage_identique(b1);
    temps_final1 = clock();
    temps1 = ((double) (temps_final1 - temps_initial1)) / CLOCKS_PER_SEC;

    temps_initial2 = clock();
    bb2 = ouvrage_identiqueH(b2);
    temps_final2 = clock();
    temps2 = ((double) (temps_final2 - temps_initial2)) / CLOCKS_PER_SEC;

    fprintf(f9, "%d %f %f\n", n, temps1, temps2);
    liberer_biblio(b1);
    liberer_biblio(bb1);
    liberer_biblioH(b2);
    liberer_biblioH(bb2);
  }



  
  return 0 ;
}
