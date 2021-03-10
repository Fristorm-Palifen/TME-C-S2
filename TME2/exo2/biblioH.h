#ifndef BIBLIOH_H
#define BIBLIOH_H
#include "biblioH.h"

typedef struct livreh {
  int cle ;
  /* int num; ... toutes les donnees permettant de representer un livre */
  int num ;
  char *titre ;
  char *auteur ;
  struct livreh * suivant ;
} LivreH ;


typedef struct table {
  int nE ; /*nombre d’elements contenus dans la table de hachage */
  int m ; /*taille de la table de hachage */
  LivreH **T ; /*table de hachage avec resolution des collisions par chainage */
} BiblioH ;

//def des fonctions de biblioH.c
int fonctionClef(char* auteur);
LivreH* creer_livreH(int num,char* titre,char* auteur) ;
void liberer_livreH(LivreH* l)  ;
BiblioH* creer_biblioH(int m) ;
void liberer_biblioH(BiblioH* b);
int fonctionHachage(int cle, int m); 
void inserer(BiblioH* b,int num,char* titre,char* auteur);
void affiche_livreH(LivreH *l);
void affiche_biblioH(BiblioH* b);
int recherche_ouvrage_numH(BiblioH *b, int numero);
int recherche_ouvrage_titreH(BiblioH *b, char *t);
BiblioH *recherche_auteurH(BiblioH *b, char *aut);
int supprimer_ouvrageH( BiblioH *b , int numero , char *t, char *aut) ;
void fusionH(BiblioH* b1, BiblioH* b2);
BiblioH *ouvrage_identiqueH(BiblioH *b);



#endif