#ifndef BIBLIOLC_H
#define BIBLIOLC_H

typedef struct livre {
  int num ;
  char * titre ;
  char * auteur ;
  struct livre * suiv ;
} Livre ;

typedef struct { /* Tete fictive */
  Livre * L ; /* Premier element */
} Biblio ;

Livre *creer_livre(int num,char *titre,char *auteur);
void liberer_livre(Livre *l);
Biblio *creer_biblio();
void liberer_biblio(Biblio *b);
void inserer_en_tete(Biblio *b,int num,char *titre,char *auteur);
void affiche_livre(Livre *l) ;
void affiche_biblio(Biblio *b) ;
int recherche_ouvrage_num(Biblio *b, int numero) ;
int recherche_ouvrage_titre(Biblio *b, char *t) ;
Biblio *recherche_auteur(Biblio *b, char *aut);
int supprimer_ouvrage(Biblio *b , int n , char *t , char *aut);
void fusion( Biblio *b1 , Biblio *b2 );
Biblio *ouvrage_identique(Biblio *b);

#endif 