#include "biblioLC.h"
#include "entreeSortieLC.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Livre *creer_livre(int num,char *titre,char *auteur){
  Livre *l = (Livre *)malloc(sizeof(Livre)) ;
  //test 
  if( l == NULL ){
    printf("\nrip\n");
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

    if( b != NULL ){
        Livre *l = b->L;

        while(l){
            affiche_livre(l);
            l = l->suiv;
        }
    }
}

int recherche_ouvrage_num(Biblio *b, int numero){

  if( b != NULL ){
    Livre *l = b->L ;

    while( l ){
      if( l->num == numero ){
        affiche_livre( l ) ;
        return 0 ;
      }
      l = l->suiv ;
    }
  }

  printf("\nLivre %d non trouve\n",numero);
  return 1 ;
}

int recherche_ouvrage_titre(Biblio *b, char *t){

    if( b != NULL ){
    Livre *l = b->L ;

    while( l ){
      if( strcmp( l->titre , t) == 0 ){
        affiche_livre( l ) ;
        return 0 ;
      }
      l = l->suiv ;
    }
  }

  printf("\nLivre %s non trouve\n", t);
  return 1 ;
  
}

Biblio *recherche_auteur(Biblio *b, char *aut){
  Biblio *bb = creer_biblio();
  if( bb ){
    Livre *l = b->L ;
    
    while( l ){
      if(strcmp( l->auteur , aut ) == 0 ){
        inserer_en_tete( bb , l->num , l->titre , l->auteur );
      }
      l = l->suiv ;
    }
    return bb ;
  }
  else{
    printf("\nBibliotheque vide\n");
    return NULL ;
  }

}

int supprimer_ouvrage(Biblio *b , int numero , char *t , char *aut){

    if( b!=NULL ){
        
        if( b->L!=NULL ){
            Livre *l=b->L;

            if((l->num == numero ) && (strcmp(l->titre, t)==0) && (strcmp(l->auteur, aut)==0)){
                b->L = b->L->suiv;
                liberer_livre(l);
                return 0;
            }
            else{

                while(l->suiv){

                    if((l->suiv->num == numero ) && (strcmp(l->suiv->titre, t)==0) && (strcmp(l->suiv->auteur, aut)==0)){
                        Livre *tmp = l->suiv->suiv;
                        liberer_livre(l->suiv);
                        l->suiv = tmp ;
                        return 0;
                    }
                }
            }
        }
    }return 1 ;
}

void fusion( Biblio *b1 , Biblio *b2 ){
  while( b2->L ){
    inserer_en_tete( b1 , b2->L->num , b2->L->titre , b2->L->auteur ) ;
    b2->L = b2->L->suiv ;
  }
  liberer_biblio( b2 ) ;
}

Biblio *ouvrage_identique(Biblio *b){ 
  
    Biblio *bb = creer_biblio();
    if( bb == NULL ){
        return NULL;
    }
    Livre *l1 = b->L;

    while( l1 ) {
        Livre *l2 = b->L;

        while( l2 ) {

            if( l1 != l2 && strcmp( l1->titre , l2->titre ) == 0 && strcmp( l1->auteur , l2->auteur ) == 0) {
                inserer_en_tete( bb , l1->num , l1->titre , l1->auteur );
                break;
            }l2 = l2->suiv;

        }l1 = l1->suiv;
    }

    return bb;
}


void liberer_livre(Livre *l) {
  if( l != NULL ){
    free( l->titre );
    free( l->auteur );
    free( l ) ;

  }
}

Biblio *creer_biblio(){
  Biblio *b = (Biblio *)malloc(sizeof(Biblio)) ;
  //test
  if( b == NULL ){
    printf("\nrip\n");
    return NULL ;
  }
  b->L = NULL ;
  return b ;
}


void liberer_biblio(Biblio *b){
  if(b != NULL){
    while( b->L ){
      liberer_livre( b->L ) ;
      b->L = b->L->suiv ;
    }
    free( b ) ;
  }
}

void inserer_en_tete(Biblio* b,int numero,char* t,char* aut){
    Livre* l = creer_livre( numero , t , aut );
    l->suiv = b->L;
    b->L = l;
}

