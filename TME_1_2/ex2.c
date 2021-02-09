#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>


void alloue_tableau(int **t, int n){
    *t=malloc(n*sizeof(int));

}

void desalloue_tableau(int *t){
    free(t);
}

void remplir_tableau(int **tab, int v, int n){
    for (int i=0; i<n; i++)
    {
        (*tab)[i]=rand()%v;
    }
    
}

void affiche_tableau(int **t, int n){
    for (int i=0; i<n; i++)
    {
        printf("tab[%d] = %d\n", i , (*t)[i]);
    }
    
}

int pcarre(int n){return n*n ; }


int algo1(int *tab, int n){
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res += pcarre( tab[i] - tab[j] ) ;
    return res ;
    
}

int algo2(int *tab , int n) {
    int res = 0;
    for( int i = 0 ; i < n ; i++ ){
        res += tab[i] ;
    }
    return pcarre( res ) ;
}

int main(){
    srand(time(NULL));
    unsigned long temps_initial1, temps_initial2, temps_final1, temps_final2 ;
    double temps1, temps2 ;
    int n = 500 ;





    int *tab=NULL;
    alloue_tableau(&tab, n );
    remplir_tableau(&tab, 100, n );
    affiche_tableau(&tab, n );

    printf("\n\nresultat 1 : %d\n",algo1(tab, n ));
    printf("\n\nresultat 2 : %d\n",algo2(tab, n ));

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
    return 0;
}