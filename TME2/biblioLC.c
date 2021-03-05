#include "biblioLC.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

void affiche_livre(Livre *l){
  printf("num = %d, titre = %s, auteur = %s\n",l->num,l->titre,l->auteur);
}

void affiche_biblio(Biblio *b){
  Biblio *temp=b;
  while( b->L ){
      affiche_livre(b->L);
      b->L = b->L->suiv;
  }
}

void recherche_ouvrage_num(Biblio *b, int numero){
  while(b->L && b->L->num!=numero){
    b->L = b->L->suiv ;
  }
  if(b->L->num == numero ){
    affiche_livre( b->L );
  }
  else{
    printf("livre %d non trouve\n",numero);
  }
}

void recherche_ouvrage_titre(Biblio *b, char *t){
  while(b->L && strcmp( b->L->titre , t )==1 ) {
    b->L = b->L->suiv ;
  }
  if( strcmp(b->L->titre , t ) == 0 ){
    affiche_livre( b->L );
  }
  else{
    printf("Livre %s non trouve\n", t);
  }
}

Biblio *recherche_auteur(Biblio *b, char *aut){
  Biblio *biblio = creer_biblio();
  while( b->L ){
    if(strcmp( b->L->auteur , aut ) == 0 ){
      inserer_en_tete( biblio , b->L->num , b->L->titre , b->L->auteur );
    }
    b->L = b->L->suiv ;
  }
  return biblio ;
}

Biblio *supprimer_ouvrage(Biblio *b , int n , char *t , char *aut){
  Biblio *biblio = creer_biblio() ;
  while( b->L ){
    if(b->L->num != n && strcmp( b->L->titre , t )==1 && strcmp( b->L->auteur , aut) == 1) {
      inserer_en_tete( biblio , b->L->num , b->L->titre , b->L->auteur) ;
    }
  }
  liberer_biblio( b ) ;
  return biblio ;
}

void fusion( Biblio *b1 , Biblio *b2 ){
  while( b2->L ){
    inserer_en_tete( b1 , b2->L->num , b2->L->titre , b2->L->auteur ) ;
    b2->L = b2->L->suiv ;
  }
  liberer_biblio( b2 ) ;
}

Biblio *ouvrage_identique(Biblio *b){ // à modifier
    Biblio *res = creer_biblio();
    Livre *l1 = b->L;
    
    while(l1 != NULL) {

        Livre *l2 = b->L;

        while(l2 != NULL) {

            if (l1 == l2){
                continue;
            }

            if (strcmp(l1->auteur, l2->auteur) == 0 && strcmp(l1->titre, l2->titre)) {
                inserer_en_tete(res, l1->num, l1->titre, l1->auteur);
                break;
            }
        }
    }return  res ;
}


void liberer_livre(Livre *l) {
  free( l->titre );
  free( l->auteur );
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
  while( b->L ){
     liberer_livre( b->L ) ;
     b->L = b->L->suiv ;
  }
  free( b ) ;
}

void inserer_en_tete(Biblio *b,int num,char *titre,char *auteur){
  Livre *l = creer_livre( num , titre , auteur ) ;
  l->suiv =  b->L ;
  b->L = l ;
}