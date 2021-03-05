#include "entreeSortieLC.h"
#include "biblioLC.h"
#include <stdio.h>
#include <stdlib.h>

void menu() {
  printf("\e[1;92m");
  printf("Bienvenue sur le mini Projet 2 de Theophane et Francois-Xavier\n Vous allez devoir choisir entre plusieurs options afin de naviguer dans le programme.\n\n");
  printf("\e[1;36m");
  printf("\nPour ajouter un Livre a la bibliotheque tapez 0 \nPour afficher un livre tapez 1 \nPour Afficher une biblioteque tapez 2\nPour rechercher un ouvrage par son numero tapez 3 \nPour rechercher un ouvrage par son titre tapez 4\nPour rechercher de tous les livres d’un meme auteur tapez 5 \nPour supprimer un ouvrage tapez 6 \nPour fusionner de deux bibliotheques tapez 7 \nPour rechercher tous les ouvrages avec plusieurs exemplaires tapez 8");
  printf("\e[1;31m");
  printf("\n\nEnfin Pour quitter le programme tapez 9\n");
  printf("\n");
  printf("\e[0m");
  printf("Veuillez entrer votre choix: ");
  
}


int main(int argc, char** argv) {
  if (argc !=3){
    printf("\e[1;31m");
    printf("\n\n\nLe nombre d'arguments n'est pas bon!!\n\n\n");
    printf("\e[0m");
    return 1;
  }
  Biblio *b = charger_n_entrees( argv[1] , atoi(argv[2]) ) ;
  enregistrer_biblio( b, "save_b.txt" ) ;
  int fin =0;
  do{
    menu();
    char buffer[256];
    fgets(buffer, 256, stdin);
    int choix_menu; 
    sscanf(buffer, "%1d", &choix_menu);
    printf("\n");
    switch(choix_menu){
      case 0:
        printf("Place_holder");
        
        break;
      case 1:
        printf("Place_holder");
        //affiche_livre( l ) ;
        break;
      case 2:
        printf("Place_holder");
        affiche_biblio( b );
        break;
      case 3:
        printf("Place_holder");
        char buff[256];
        fgets(buff, 256, stdin);
        int numero; 
        sscanf(buffer, "%1d", &num);
        printf("\n");
        recherche_ouvrage_num( b, numero) ;
        break;
      case 4:
        printf("Place_holder");
        char buf[256] ;
        fgets(buf, 256, stdin) ;
        char *titre ;
        sscanf(buf, "%1s")
        recherche_ouvrage__titre( b , titre ) ;
        break;
      case 5:
        printf("Place_holder");
        break;
      case 6:
        printf("Place_holder");
        break;
      case 7:
        printf("Place_holder");
        break;
      case 8:
        printf("Place_holder");
        break;
      case 9:
        printf("\nMerci et aurevoir\n");
        fin=1;
        break;
      default:
        printf("Erreur, Veuillez relancer le programme\n");
        fin=1;
        break;
    }
    if (fin==1){ break;}
    printf("\n\n");
  }while(1);
  liberer_biblio( b ) ;
  return 0 ;
}