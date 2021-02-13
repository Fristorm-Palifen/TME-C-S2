#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define N 20 //variable qui servira pour l'écriture en fichier


void alloue_tableau(int **t, int n){
    *t=malloc(n*sizeof(int)); // alooue un tableau de n cases

}

void desalloue_tableau(int *t){
    free(t); // libere la mémoire du tableau
}

void remplir_tableau(int **tab, int v, int n){
    for (int i=0; i<n; i++)
    {
        (*tab)[i]=rand()%v; //remplit le tableau avec des valeurs entre 0 et (v-1)
    }
    
}

void affiche_tableau(int **t, int n){
    for (int i=0; i<n; i++)
    {
        printf("tab[%d] = %d\n", i , (*t)[i]);
    }
    
}

int pcarre(int n){return n*n ; } //renvoie n au carré


int algo1(int *tab, int n){
    int res = 0; //somme

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            res += pcarre( tab[i] - tab[j] ) ; //calcule de l'énoncé
        }
    }

    return res ;
    
}

int algo2(int *tab, int n){
    int res = 0; // somme des elements du tableau
    int sommeCarre = 0; // somme des carrés

    for(int i = 0; i < n; i++) {
        res += tab[ i ];
        sommeCarre += tab[ i ] * tab[ i ];
    }

    return  ( 2 * n )  * sommeCarre - ( 2 * pcarre(res) ) ;
    
}

int main(){
    srand(time(NULL));
    unsigned long temps_initial1, temps_initial2, temps_final1, temps_final2 ;
    double temps1, temps2 ; // pour les temps cpu 
    int n = 500, v = 100;

    int *tab = NULL ;
    alloue_tableau(&tab, n );
    remplir_tableau(&tab, v, n );
    affiche_tableau(&tab, n ); // affiche le tableau 

    if( algo1( tab , n) != algo2( tab , n) ){ //test si les resultats sont bons
      desalloue_tableau(tab);
      printf("\nLes résultats des calculs ne sont pas les memes !! ") ;
      return 0 ;
    }else{
        printf("\n\nresultat 1 : %d\n",algo1(tab, n ));
        printf("\n\nresultat 2 : %d\n",algo2(tab, n ));
    }



    // petit test des temps cpu
    temps_initial1 = clock() ;
    algo1(tab, n );
    temps_final1 = clock() ;
    temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

    temps_initial2 = clock() ;
    algo2(tab , n ) ;
    temps_final2 = clock() ;
    temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;

    printf("\n\nCPU 1 : %f\n", temps1 );
    printf("\n\nCPU 2 : %f\n", temps2 );

    desalloue_tableau(tab);

    int *t = NULL ;
    FILE *f=fopen("sortie_vitesse.txt", "w"); // pour placer les résultats de la question 2.3
    for(int i = 0; i < N; i++) {

        alloue_tableau(&t , n);
        remplir_tableau(&t, v, n); // crée notre tableu de test

        //calcule les temps cpu avec les deux algorithmes
        temps_initial1 = clock();
        algo1(t, n);
        temps_final1 = clock();
        temps1 = ((double) (temps_final1 - temps_initial1)) / CLOCKS_PER_SEC;

        temps_initial2 = clock();
        algo2(t, n);
        temps_final2 = clock();
        temps2 = ((double) (temps_final2 - temps_initial2)) / CLOCKS_PER_SEC;

        fprintf(f, "%d %f %f\n", n, temps1, temps2); // écrit les resultats

        desalloue_tableau(t);
        n++; // augmente la tabille
    }
    fclose(f) ; //ferme le fichier
    
    return 0;
}


/*
=============================
RESULTAT D'UN MAIN :
==============================
tab[0] = 34
tab[1] = 19
tab[2] = 2
tab[3] = 86
tab[4] = 59
tab[5] = 83
.
.
.
tab[498] = 63
tab[499] = 42


resultat 1 : 386041488


resultat 2 : 386041488


CPU 1 : 0.001462


CPU 2 : 0.000002
*/