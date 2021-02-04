#include<stdio.h>
#include<stdlib.h>
#include <string.h>
#include <time.h>


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
        printf("%d\n",(*t)[i]);
    }
    
}

int algo1(int *tab, int n){
    int res=0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i!=j)
            {
                res+=(tab[i]-tab[j])*(tab[i]-tab[j]);
            }
            
        }
        
    }
    return res;
    
}

int main(){
    srand(time(NULL));
    int *tab=NULL;
    alloue_tableau(&tab,10);
    remplir_tableau(&tab, 100, 10);
    affiche_tableau(&tab,10);
    printf("\n\n resultat: %d\n",algo1(tab,10));

    desalloue_tableau(tab);
    return 0;
}