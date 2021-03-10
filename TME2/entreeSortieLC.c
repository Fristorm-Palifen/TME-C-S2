#include "entreeSortieLC.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


Biblio *charger_n_entrees(char *nomfic, int n) {

    FILE *f = fopen(nomfic, "r");
    Biblio *b = creer_biblio();

    char buffer[512];
    int num;
    char titre[256];
    char auteur[256];
    int i = n-1;

    while(i >= 0 && fgets(buffer, 512, f)) {

        sscanf(buffer, "%d %s %s\n", &num, titre, auteur);
        inserer_en_tete(b, num, titre, auteur);
        i --;
    }

    fclose(f);
    return b;
}

void enregistrer_biblio(Biblio *b, char *nomfic){
  FILE *f = fopen( nomfic , "w" ) ;
  Biblio *tmp= b;
  while( tmp->L){
    fprintf( f , "%d %s %s\n" , tmp->L->num , tmp->L->titre , tmp->L->auteur );
    tmp->L=tmp->L->suiv ;
  }
  fclose( f ) ;
}



