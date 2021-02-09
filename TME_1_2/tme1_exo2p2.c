#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define N 20

int ** alloue_matrice(int n ){
    int **tab = malloc( n *sizeof(int*));
    for(int i = 0 ; i < n ; i++ ){
        tab[i] = (int *)malloc( n * sizeof(int *));
    }
    return tab;
}

void desalloue_matrice( int ***tab , int n ){
    for(int i=0 ; i<n ;i++){
        int *temp=(*tab)[i];
        free(temp);
    }
    free(*tab);
}

void remplir_matrice( int **tab , int n , int v ){
    for(int i = 0 ; i < n ; i++){
        for( int j = 0 ; j < n ; j++ ){
            tab[i][j] = rand()%v ;
        }
    }
}

void affiche_matrice( int **tab , int n ){
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            printf("%d ", tab[i][j] );
        }
        printf("\n");
    }
}

int algo1( int **tab, int n ) {

    for (int i1 = 0; i1 < n; i1++){
        for (int j1 = 0; j1 < n; j1++){

            for (int i2 = 0; i2 < n; i2++){
                for (int j2 = 0; j2 < n; j2++){

                    if ((i1 != i2 || j1 != j2) && (tab[i1][j1] == tab[i2][j2])){
                        return 0; 
                    }

                }
            }

        }
    }
    return 1; 
}

int algo2(int **tab, int n, int v){
    int *temp = calloc(sizeof(int), v);
  
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (temp[ tab[i][j] - 1 ] == 1){
                free(temp);
                return 0;
        }
        else
            temp[ tab[i][j] - 1 ] = 1;
        }
    }
    free(temp);
    return 1;
}


int **produit_matrice1(int ** m1, int **m2, int n){
    int **res = alloue_matrice(n) ;
    

    for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < n ; j++)
		{
			for (int k = 0 ; k < n ; k++)
			{
				res[i][j] += m1[i][k] * m2[k][j] ;
			}
		}
	}
    return res ;
}


int main(){
    srand(time(NULL));
    int n = 4 , v = 100 ;
    int **mat1 = alloue_matrice(n);
    int **mat2 = alloue_matrice(n) ;
    int **m = NULL, **m2 = NULL ; 

    remplir_matrice( mat1 , n , v );
    remplir_matrice( mat2 , n ,v ) ;

    printf("\nMatrice 1 :\n");
    affiche_matrice( mat1 , n ) ;
    printf("\nMatrice 2 : \n");
    affiche_matrice( mat2 , n ) ;

    printf("\nProduit de mat1 et mat2 :\n");
    m = produit_matrice1( mat1 , mat2 , n ) ;
    affiche_matrice( m , n );

    printf("\nProduit de mat2 et mat1 :\n");
    m2 = produit_matrice1( mat2 , mat1 , n ) ;
    affiche_matrice( m2 , n );

    if ( algo1( mat1 , n ) == 1 ){
        printf("\nTous les elements de mat1 sont différents\n");
    }else{
        printf("\nLes éléments de mat1 ne sont pas tous différents\n");
    }
    
    if ( algo2( mat2 , n , v ) == 1 ){
        printf("Tous les elements de mat2 sont différents\n");
    }else{
        printf("Les éléments de mat2 ne sont pas tous différents\n");
    }
    if ( algo1( mat2 , n ) == 1 ){
        printf("Tous les elements de mat2 sont différents\n");
    }else{
        printf("Les éléments de mat2 ne sont pas tous différents\n");
    }



    unsigned long temps_initial1, temps_initial2, temps_final1, temps_final2 ;
    double temps1, temps2 ;

    temps_initial1 = clock() ;
    algo1(mat1, n );
    temps_final1 = clock() ;
    temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

    temps_initial2 = clock() ;
    algo2(mat1 , n, v ) ;
    temps_final2 = clock() ;
    temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;

    desalloue_matrice( &mat1 , n ); 
    desalloue_matrice( &mat2 , n );
    desalloue_matrice( &m , n ) ;
    desalloue_matrice( &m2 , n ) ;


    printf("\n\nCPU 1 : %f\n", temps1 );
    printf("\n\nCPU 2 : %f\n", temps2 );



    FILE *f=fopen("sortie_vitesse_differents.txt", "w");
    for(int i = 0; i < N; i++) {

        int **t = alloue_matrice( n ) ;
        remplir_matrice(t , n , v);

        temps_initial1 = clock() ;
        algo1(t, n );
        temps_final1 = clock() ;
        temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

        temps_initial2 = clock() ;
        algo2(t , n, v ) ;
        temps_final2 = clock() ;
        temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;

        fprintf(f, "%d %f %f\n", n, temps1, temps2);

        desalloue_matrice( &t , n );
        n++;
    }
    fclose(f) ;
    



}

