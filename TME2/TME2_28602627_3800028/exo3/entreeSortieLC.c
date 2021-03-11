#include "entreeSortieLC.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


Biblio *charger_n_entrees(char *nomfic, int n) {

    FILE *f = fopen(nomfic, "r"); // ouvre le fichier en lecture
    Biblio *b = creer_biblio();

    char buffer[512];
    int num;
    char titre[256];
    char auteur[256];
    int i = n-1;

    while(i >= 0 && fgets(buffer, 512, f)) { // donne les n lignes du fichier

        sscanf(buffer, "%d %s %s\n", &num, titre, auteur);  // donne les valeurs aux attributs
        inserer_en_tete(b, num, titre, auteur); // pour les inserer dans la bibliotheque
        i --;
    }

    fclose(f); // ferme le fichier
    return b;
}

void enregistrer_biblio(Biblio *b, char *nomfic){ // permet de sauvegarder une bilbio dans un fichier
  FILE *f = fopen( nomfic , "w" ) ; // fichier en ecriture
  Biblio *tmp= b;
  while( tmp->L){ //parcourt la bilio
    fprintf( f , "%d %s %s\n" , tmp->L->num , tmp->L->titre , tmp->L->auteur ); // ecrit le livre 
    tmp->L=tmp->L->suiv ;
  }
  fclose( f ) ;
}



