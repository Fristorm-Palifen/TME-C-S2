#include "entreeSortieLC.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Biblio *charger_n_entrees(char *nomfic, int n) {

    FILE *f = fopen( nomfic , "r");
    Biblio *b = creer_biblio();
    char buffer[512];
    char num;
    int nu;
    char titre[256];
    char auteur[256];

    int i = 0;
    while(i < n && fgets(buffer, 512, f)) {

        sscanf( "%s %s %s", &num , titre , auteur);
        nu= atoi(&num);
        titre[strlen(titre) - 1] = "\0";
        auteur[strlen(auteur) - 1] = "\0";
        inserer_en_tete(b, nu , titre , auteur);
        i++;
    }

    fclose(f);
    return b;
}

void enregistrer_biblio(Biblio *b, char *nomfic){
  FILE *f = fopen( nomfic , "w" ) ;
  while( b->L ){
    fprintf( f , "%d %s %s\n" , b->L->num , b->L->titre , b->L->auteur );
    b->L->suiv ;
  }
  fclose( f ) ;
}



