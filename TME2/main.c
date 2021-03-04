#include "entreeSortieLC.h"
#include "biblioLC.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

  Biblio *b = charger_n_entrees( argv[1] , atoi(argv[2]) ) ;
  enregistrer_biblio( b, "save_b.txt" ) ;
  liberer_biblio( b ) ;



  return 0 ;




}