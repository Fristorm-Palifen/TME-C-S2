#include "entreeSortieLC.h"
#include "biblioH.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



BiblioH *charger_n_entreesH(char *nomfic, int n){
    FILE *f = fopen(nomfic, "r");
    BiblioH *b = creer_biblioH( (int)( n / 2) );

    char buffer[512];
    int num;
    char titre[256];
    char auteur[256];
    int i = n-1;

    while(i >= 0 && fgets(buffer, 512, f)) {

        sscanf(buffer, "%d %s %s\n", &num, titre, auteur);
        inserer(b, num, titre, auteur);
        i --;
    }

    fclose(f);
    return b;

}
void enregistrer_biblioH(BiblioH *b, char *nomfic){

  FILE *f = fopen( nomfic , "w" ) ;
  for (int i = 0; i < b->m ; i++) {
      LivreH* tmp = (b->T)[i];
      while( tmp ){
        fprintf( f , "%d %s %s\n" , tmp->num , tmp->titre , tmp->auteur );
        tmp = tmp->suivant ;
      }
  }
  fclose( f ) ;
}