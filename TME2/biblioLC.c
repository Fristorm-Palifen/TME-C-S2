#include "biblioLC.h"
#include <stdlib.h>
#include <string.h>

Livre *creer_livre(int num,char *titre,char *auteur){
  Livre *l = (Livre *)malloc(sizeof(Livre)) ;
  //test 
  if( l == NULL ){
    return NULL ;
  }
  l->num = num ;
  l->titre = strdup(titre) ;
  l->auteur = strdup(auteur) ;
  l->suiv = NULL ;

  return l ;

}

void liberer_livre(Livre *l) {
  while( l ) {
    free( l->titre );
    free( l->auteur );
    l = l->suiv ;
  }
  free( l ) ;

}

Biblio *creer_biblio(){
  Biblio *b = (Biblio *)malloc(sizeof(Biblio)) ;
  //test
  if( b == NULL ){
    return NULL ;
  }
  b->L = NULL ;
  return b ;
}


void liberer_biblio(Biblio *b){
  liberer_livre( b->L ) ;
  free( b ) ;
}

void inserer_en_tete(Biblio *b,int num,char *titre,char *auteur){
  Livre *l = creer_livre( num , titre , auteur ) ;
  l->suiv =  b->L ;
  b->L = l ;
}