#ifndef ENTREESORTIELC_H
#define ENTREESORTIELC_H
#include "biblioLC.h"
// pour pouvoir utiliser les fonctions de entreeSortieLc.c dans d'autres fichiers

Biblio *charger_n_entrees(char *nomfic, int n); 
void enregistrer_biblio(Biblio *b, char *nomfic); 


#endif 