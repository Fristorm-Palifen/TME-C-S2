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

    LivreH *l = (LivreH *)malloc(sizeof(LivreH)); //alloue la memoire

    if(l == NULL) { // probleme d'allocation
      printf("\nrip\n");
        return NULL;
    }

    //initialise les attributs
    l->num = numero ;
    l->titre = strdup(t);
    l->auteur = strdup(aut);
    l->cle = fonctionClef(aut) ; // donne la cle grace à aut
    l->suivant = NULL;

    return l;
}

void liberer_livreH(LivreH* l) { // libere la memoire du livre H
  free( l->titre ); // libere la memoire
  free( l->auteur );
  free( l ) ;
}

BiblioH *creer_biblioH(int m){ // cree la bibliotheque H
  BiblioH *b = malloc(sizeof(BiblioH));
  if( b==NULL ){ // probleme d'allocation
    printf("\nErreur d'allocation\n");
    return NULL ;
  }

  //initialise les attributs
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
  
  for(int i = 0 ; i < b->m ; i++) { // parcours T

      LivreH *l = b->T[i];

      while( l ){ // parcours les livres
        LivreH *tmp = l->suivant;
        liberer_livreH( l ) ; // libere chaque livres de T
        l = tmp;
      }

  }
  // libere T et b
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

  if( b != NULL ){//si b non vide

    for (int i = 0; i < b->m ; i++) {// parcours T
        LivreH *l = (b->T)[i]; // pour ne pas perdre nos données

        while( l ) { //affiche la liste des livres
            affiche_livreH( l );
            l = l->suivant;
        }
    }
  }
}



int recherche_ouvrage_numH(BiblioH *b, int numero) { // affiche le livre trouver avec ce numero

  if( b != NULL ){

    for (int i = 0; i < b->m ; i++) { //parcours T
        LivreH *l = (b->T)[i];

        while ( l ) { //parcours tous les livres
            if( l->num == numero ) { //si c'est le numero qu'on cherche
                affiche_livreH( l ) ;
                return 0 ;
            }
            l = l->suivant;
        }
    }
  }//passé ici c'est que l'on a pas trouvé
  printf("\nLivre %d non trouve\n",numero);
  return 1;
}



int recherche_ouvrage_titreH(BiblioH *b, char *t) { // affiche le livre trouver avec ce titre

  if( b != NULL ){

    for (int i = 0; i < b->m ; i++) {//parcours T
        LivreH *l = (b->T)[i];

        while ( l ) {//parcours les livres
            if( strcmp( l->titre , t) == 0 ) { // si ce sont les memes titres
                affiche_livreH( l );
                return 0 ;
            }
            l = l->suivant;
        }
    }
  }
  printf("\nLivre %s non trouve\n", t); //titre non trouver
  return 1 ;
}

BiblioH *recherche_auteurH(BiblioH *b, char *aut) { // cree une bibliotheque des livres de cette auteur

	if (b != NULL) {
    BiblioH *bb = creer_biblioH(b->m); //creer la bibliotheque
    int c = fonctionHachage( fonctionClef( aut ) , b->m ); // on prend la place de l'auteur grace à nos fonctions
    LivreH *l = (b->T)[c];

    while ( l ) { // parcours les livres

        if(strcmp( l->auteur , aut ) == 0) { //si ce sont les memes auteurs
            inserer(bb, l->num, l->titre, l->auteur); //on ajoute le livre a notre bibliotheque resultat
        }l = l->suivant;
    }
    
    return bb;
  }

  else{
    printf("\nBibliotheque vide\n");
    return NULL ;
  }
}

int supprimer_ouvrageH(BiblioH *b, int numero, char *t, char *aut) {

    int cle = fonctionHachage(fonctionClef(aut ), b->m ); // prend la cle grace a aut
    LivreH *l = b->T[cle]; // prend les livres de la case cle

    if( l == NULL ) { //si il n'y a pas de livre
        return 1 ; // valeur d'echec
    }
    else {
        if(l->num == numero && strcmp(l->titre, t) == 0) { //pas besoin de verifier aut==auteur car on se trouve dans la cle de auteur
            b->T[cle] = b->T[cle]->suivant; //supprime en tete
            liberer_livreH(l);
            b->nE--;
        }
        else {
            LivreH *tmp = l;
            
            while( l ) { //parcours les livres jusqu'à celui chercher
                if(l->num == numero && strcmp(l->titre, t) == 0) {
                    tmp->suivant = l->suivant;
                    liberer_livreH(l); // supprime le livre
                    return 0;
                }
                tmp = l;
                l = l->suivant;
            }
        }
    }
}



void fusionH(BiblioH* b1, BiblioH* b2) { // fusionne deux bibliotheques H
  
  for (int i = 0; i<b2->m; i++) { // parcours T
      LivreH *l = (b2->T)[i];

      while( l ) { //parcours les livres
          inserer(b1, l->num, l->titre, l->auteur); //ajoute les livres de b2 dans b1
          l = l->suivant;
      }
  }
  b1->nE += b2->nE ; // prend le nombre d'éléments de b2 en plus
  liberer_biblioH(b2);
}



BiblioH *ouvrage_identiqueH(BiblioH *b){ // retourne une bibliotheque avec les livres identiques dans b
    BiblioH* bb = creer_biblioH(b->m);
    if( bb == NULL ){ // si bibliotheque vide
      return NULL ;
    }

    for (int i = 0; i < b->m ; i++) {//parcours T
        LivreH *l1 = (b->T)[i];

        while ( l1 ) {   // parcours les livres
                LivreH *l2 = (b->T)[i] ;

                while( l2 ) { // re parcours les livres

                    if( l1 != l2 && strcmp( l1->titre , l2->titre ) == 0 && strcmp( l1->auteur , l2->auteur ) == 0) { // si ce n'est pas le meme livre mais qu'ils ont les memes attributs

                        inserer(bb, l1->num, l1->titre, l1->auteur); // on ajoute le livre à notre bibliotheque resultat
                        break ;
                    }
                    l2 = l2->suivant;
                }
            
            l1 = l1->suivant; // on continu d'avancer
        }
    }
    return bb;
}


