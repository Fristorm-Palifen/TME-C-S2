#include "biblioH.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>



int fonctionClef(char* auteur){
  int cle = 0 , i = 0 ;

  while( auteur[i]!='\0' ){
    cle += (int)auteur[i] ;
    i++;
  }return cle ;
} 

LivreH* creer_livreH(int num,char* titre,char* auteur) {
  LivreH *l = malloc(sizeof(LivreH)) ;
  if( l!=NULL){
    l->num = num ;
    l->titre = titre ;
    l->auteur = auteur ;
    l->cle = fonctionClef( auteur ) ;
  }else{
    return NULL ;
  }
  return l ;
}

void liberer_livreH(LivreH* l) {
  free( l->titre );
  free( l->auteur );
  free( l ) ;
}

BiblioH *creer_biblioH(int m){
  BiblioH *b = malloc(sizeof(BiblioH));
  if( b==NULL ){
    return NULL ;
  }
  b->m = m ;
  b->nE = 0 ;
  b->T = NULL ;
}

void liberer_biblioH(BiblioH* b){
  int i=0;
    while (b->T[i] !=NULL){
      LivreH * tmp = b->T[i];
      while (tmp->suivant !=NULL){
        LivreH * tmptmp = tmp;
        tmp=tmp->suivant;
        liberer_livreH( tmptmp ) ;
      }
      liberer_livreH( tmp ) ;
      i++;
    }
  free( b );
  
}

int fonctionHachage(int cle, int m){
  float A = ( sqrt(5.0)-1.0 ) / 2.0;
  return (int)( m*( cle*A - (int)( cle*A ))) ;
}
/*
void inserer(BiblioH* b,int num,char* titre,char* auteur){

}*/

