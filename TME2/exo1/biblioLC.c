#include "biblioLC.h"
#include "entreeSortieLC.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

Livre *creer_livre(int num,char *titre,char *auteur){ // cree un livre avec les parametres de la fonction
  Livre *l = (Livre *)malloc(sizeof(Livre)) ; // alloue la memoire
  //test 
  if( l == NULL ){ // verifie si l'allocation a fonctionner
    printf("\nrip\n");
    return NULL ;
  }
  
  //initialise les attributs du livre
  l->num = num ;
  l->titre = strdup(titre) ;
  l->auteur = strdup(auteur) ;
  l->suiv = NULL ;

  return l ;

}

void liberer_livre(Livre *l) { // libere la memoire de l
  if( l != NULL ){ // si l n'est pas déjà vide
    free( l->titre ); // on libere la mémoire de tous les pointeurs
    free( l->auteur );
    free( l ) ;

  }
}

Biblio *creer_biblio(){ // cree une bibliotheque
  Biblio *b = (Biblio *)malloc(sizeof(Biblio)) ; // alloue la memoire
  //test
  if( b == NULL ){ // si erreur d'allocation
    printf("\nrip\n");
    return NULL ;
  }
  b->L = NULL ; //initialise ses livres
  return b ;
}


void liberer_biblio(Biblio *b){ // libere la memoire de la biblio
  if(b != NULL){
    while( b->L ){ // parrcourt ses livres
      liberer_livre( b->L ) ; // libere ses livres
      b->L = b->L->suiv ;
    }
    free( b ) ;
  }
}

void inserer_en_tete(Biblio* b,int numero,char* t,char* aut){ // ajoute un livre avec ces attributs à la bibliotheque
    Livre* l = creer_livre( numero , t , aut ); // cree le livre
    l->suiv = b->L; // ajoute à suiv les livres de  la bibliotheque
    b->L = l; // et remplace les livres de b par notre nouvelle chaine de charactere l
}



void affiche_livre(Livre *l){ // affiche le livre, chacun de ses attributs
    printf("num = %d, titre = %s, auteur = %s\n",l->num,l->titre,l->auteur);
}

void affiche_biblio(Biblio *b){ // affiche les livres d'une bibliotheque

    if( b != NULL ){ // verifie qu'elle n'est pas vide
        Livre *l = b->L;

        while(l){ // tant qu'il y à un livre
            affiche_livre(l); // on affiche ce livre
            l = l->suiv;
        }
    }
}

int recherche_ouvrage_num(Biblio *b, int numero){ // affiche un livre enfonction de son num si il est present dans la bibliotheque

  if( b != NULL ){ //si la biblio n'est pas vide
    Livre *l = b->L ; // variable temporaire pour ne pas perdre les livres

    while( l ){
      if( l->num == numero ){ // si le num du livre est egale a numero alors c'est celui qu'on cherche
        affiche_livre( l ) ; //on l'affiche
        return 0 ; // on sort si on trouve le livre
      }
      l = l->suiv ;
    }
  }

  printf("\nLivre %d non trouve\n",numero); // c'est que l'on a pas trouver
  return 1 ;
}

int recherche_ouvrage_titre(Biblio *b, char *t){ // meme fonctionnement qu'avant mais avec un titre

    if( b != NULL ){ // si non vide
    Livre *l = b->L ; // variable temporaire pour ne pas perdre les livres

    while( l ){
      if( strcmp( l->titre , t) == 0 ){ // on utilise donc strcmp pour des chaines de characteres
        affiche_livre( l ) ;
        return 0 ; // sort si on trouve le livre
      }
      l = l->suiv ;
    }
  }

  printf("\nLivre %s non trouve\n", t); // si on arrive ici c'est qu'on a pas trouvé le livre
  return 1 ;
  
}

Biblio *recherche_auteur(Biblio *b, char *aut){ // retourne une bibliotheque avec tous les livres de aut
  Biblio *bb = creer_biblio(); // creation de la bibliotheque
  if( bb ){
    Livre *l = b->L ;
    
    while( l ){
      if(strcmp( l->auteur , aut ) == 0 ){ // si le livre a pour auteur aut
        inserer_en_tete( bb , l->num , l->titre , l->auteur ); // on ajoute le livre a notre bibliotheque
      }
      l = l->suiv ;
    }
    return bb ;
  }
  else{
    printf("\nBibliotheque vide\n"); // si la biliotheque n'est pas bien alloue
    return NULL ;
  }

}

int supprimer_ouvrage(Biblio *b , int numero , char *t , char *aut){ // cherche le livre avec ces parametres dans b pour le liberer

    if( b!=NULL ){ // si biblio non vide
        
        if( b->L!=NULL ){ // si livre 
            Livre *l=b->L; // variable temporaire pour ne pas perdre les données

            if((l->num == numero ) && (strcmp(l->titre, t)==0) && (strcmp(l->auteur, aut)==0)){ // si c'est notre livre alors on supprime
                b->L = b->L->suiv; // pour ne pas perdre les livres suivants
                liberer_livre(l);
                return 0;
            }
            else{

                while(l->suiv){ // sinon on parcours les livres

                    if((l->suiv->num == numero ) && (strcmp(l->suiv->titre, t)==0) && (strcmp(l->suiv->auteur, aut)==0)){ // si se sont les bons parametres on supprime
                        Livre *tmp = l->suiv->suiv; // pour ne pas perdre la liste
                        liberer_livre(l->suiv); // supprime le livre
                        l->suiv = tmp ;
                        return 0;
                    }
                }
            }
        }
    }return 1 ;
}

void fusion( Biblio *b1 , Biblio *b2 ){ //fusionne 2 bibliotheques
  while( b2->L ){ // parcourt la deuxieme bibliotheque
    inserer_en_tete( b1 , b2->L->num , b2->L->titre , b2->L->auteur ) ; // ajoute ses livres à b1
    b2->L = b2->L->suiv ;
  }
  liberer_biblio( b2 ) ; // supprime la deuxieme bibliotheque
}

Biblio *ouvrage_identique(Biblio *b){ // retourne une bibliotheque avec des ouvrages identiques
  
    Biblio *bb = creer_biblio(); // bibliotheque resultat
    if( bb == NULL ){
        return NULL;
    }
    Livre *l1 = b->L;

    while( l1 ) { // parcourt les livres
        Livre *l2 = b->L;

        while( l2 ) { // re parcourt les livres

            if( l1 != l2 && strcmp( l1->titre , l2->titre ) == 0 && strcmp( l1->auteur , l2->auteur ) == 0) { // si les livres sont égaux
                inserer_en_tete( bb , l1->num , l1->titre , l1->auteur ); // on ajoute au resultat
                break;
            }l2 = l2->suiv;

        }l1 = l1->suiv;
    }

    return bb;
}




