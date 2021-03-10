#include "biblioH.h"
#include "entreeSortieH.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>



int fonctionClef(char* auteur){ // permet d'avoir la cle 
  int cle = 0 , i = 0 ;

  while( auteur[i]!='\0' ){
    cle += (int)auteur[i] ; // somme des valeurs ASCII
    i++;
  }return cle ;
} 

LivreH *creer_livreH(int numero, char *t, char *aut) { // cree un livre H

    LivreH *l = (LivreH *)malloc(sizeof(LivreH));

    if(l == NULL) {
      printf("\nrip\n");
        return NULL;
    }

    l->num = numero ;
    l->titre = strdup(t);
    l->auteur = strdup(aut);
    l->cle = fonctionClef(aut) ; // donne la cle grace à aut
    l->suivant = NULL;

    return l;
}

void liberer_livreH(LivreH* l) { // libere la memoire du livre H
  free( l->titre );
  free( l->auteur );
  free( l ) ;
}

BiblioH *creer_biblioH(int m){ // cree la bibliotheque H
  BiblioH *b = malloc(sizeof(BiblioH));
  if( b==NULL ){
    printf("\nErreur d'allocation\n");
    return NULL ;
  }

  b-> m = m ;
  b->nE = 0 ; // 0 elements à la base
  b->T = malloc(sizeof(LivreH *)*m);
  if(b->T == NULL) { // si T mal alloué
    free(b);
    return NULL;
  }

  for(int i = 0; i < b->m ; i++){ // initialise T
    b->T[ i ] = NULL;
  }

  return b;
}

void liberer_biblioH(BiblioH *b){ // libere la mémoire de la bibliotheque
  
  for(int i = 0 ; i < b->m ; i++) {

      LivreH *l = b->T[i];

      while( l ){ // parcours les livres
        LivreH *tmp = l->suivant;
        liberer_livreH( l ) ;
        l = tmp;
      }

  }
  free(b->T);
  free( b );

}

int fonctionHachage(int cle, int m){ // transforme la cle en valeur entiere utilisable par la table de hachage
  float A = ( sqrt(5.0)-1.0 ) / 2.0;
  return (int)( m*( cle*A - (int)( cle*A ))) ;
}


void inserer(BiblioH* b,int num,char* titre,char* auteur){ // insere un livre dans b

    LivreH *l = creer_livreH(num, titre, auteur); //cree le livre
    l->suivant = b->T[ fonctionHachage(l->cle, b->m) ]; // utilise la cle
    b->T[ fonctionHachage(l->cle, b->m) ] = l; // pose le libre à sa clé
    b->nE = b->nE + 1 ; // +1 livre
}


void affiche_livreH(LivreH *l) { // affiche le livre
    printf("num = %d, titre = %s, auteur = %s\n",l->num,l->titre,l->auteur);
}
    
    
void affiche_biblioH(BiblioH* b) { // affiche la bibliotheque

  if( b != NULL ){
    for (int i = 0; i < b->m ; i++) {
        LivreH *l = (b->T)[i];
        while( l ) {
            affiche_livreH( l );
            l = l->suivant;
        }
    }
  }
}



int recherche_ouvrage_numH(BiblioH *b, int numero) { // affiche le livre trouver avec ce numero

  if( b != NULL ){
    for (int i = 0; i < b->m ; i++) {
        LivreH *l = (b->T)[i];
        while ( l ) {
            if( l->num == numero ) {
                affiche_livreH( l ) ;
                return 0 ;
            }
            l = l->suivant;
        }
    }
  }
  printf("\nLivre %d non trouve\n",numero);
  return 1;
}



int recherche_ouvrage_titreH(BiblioH *b, char *t) { // affiche le livre trouver avec ce titre

  if( b != NULL ){

    for (int i = 0; i < b->m ; i++) {
        LivreH *l = (b->T)[i];

        while ( l ) {
            if( strcmp( l->titre , t) == 0 ) {
                affiche_livreH( l );
                return 0 ;
            }
            l = l->suivant;
        }
    }
  }
  printf("\nLivre %s non trouve\n", t);
  return 1 ;
}

BiblioH *recherche_auteurH(BiblioH *b, char *aut) { // cree une bibliotheque des livres de cette auteur

	if (b != NULL) {
    BiblioH *bb = creer_biblioH(b->m);

    for (int i = 0; i < b->m ; i++) {
        LivreH *l = (b->T)[i];

        while ( l ) {

            if(strcmp( l->auteur , aut ) == 0) {
                inserer(bb, l->num, l->titre, l->auteur);
            }l = l->suivant;
        }
    }
    return bb;
  }
  else{
    printf("\nBibliotheque vide\n");
    return NULL ;
  }
}



void fusionH(BiblioH* b1, BiblioH* b2) { // fusionne deux bibliotheques H
  
  for (int i = 0; i<b2->m; i++) {
      LivreH *l = (b2->T)[i];

      while( l ) {
          inserer(b1, l->num, l->titre, l->auteur);
          l = l->suivant;
      }
  }
  b1->nE += b2->nE ; // prend le nombre d'éléments de b2 en plus
  liberer_biblioH(b2);
}



BiblioH *ouvrage_identiqueH(BiblioH *b){ // retourne une bibliotheque avec les livres identiques dans b
    BiblioH* bb = creer_biblioH(b->m);
    if( bb == NULL ){
      return NULL ;
    }

    for (int i = 0; i < b->m ; i++) {
        LivreH *l1 = (b->T)[i];

        while ( l1 ) {  
                LivreH *l2 = (b->T)[i] ;

                while( l2 ) {

                    if( l1 != l2 && strcmp( l1->titre , l2->titre ) == 0 && strcmp( l1->auteur , l2->auteur ) == 0) {
                        inserer(bb, l1->num, l1->titre, l1->auteur);
                        break ;
                    }
                    l2 = l2->suivant;
                }
            
            l1 = l1->suivant;
        }
    }
    return bb;
}


