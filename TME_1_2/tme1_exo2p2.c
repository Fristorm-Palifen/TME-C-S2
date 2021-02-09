#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

int ** alloue_matrice(int n ){
    int **tab = malloc( n *sizeof(int*));
    for(int i = 0 ; i < n ; i++ ){
        tab[i] = (int *)malloc( n * sizeof(int *));
    }
    return tab;
}

//fonction pas bonne
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
    for( int i =0 ; i<n ;i++ ){
        for( int j=0 ;j<n ;j++){

            for( int i2 = 0 ; i2 < n ; i2++){
                for( int j2 = 0 ; j2 < n ; j2++){

                    if( tab[i][j] == tab[i2][j2] && i!=i2 && j!=j2){
                        return 0 ;
                    }

                }
            }

        }
    }
    return 1 ;
}

//pas réussi à faire le plus complexe mais l'idée est bonne
int algo2( int **tab, int n , int v ) {
    for( int i =0 ; i<n ;i++ ){
        for( int j=0 ;j<n ;j++){

            if( tab[i][j] < v ){
                
                for( int i2 = 0 ; i2 < n ; i2++){
                    for( int j2 = 0 ; j2 < n ; j2++){

                        if( tab[i][j] == tab[i2][j2] && i!=i2 && j!=j2 ){
                            return 0 ;
                        }

                    }
                }

            }else{
                return 0 ;
            }

        }
    }
    return 1 ;
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
    int **m = NULL; 

    remplir_matrice( mat1 , n , v );
    remplir_matrice( mat2 , n ,v ) ;

    affiche_matrice( mat1 , n ) ;
    affiche_matrice( mat2 , n ) ;

    printf("Produit de m1 et m2 :\n");
    m = produit_matrice1( mat1 , mat2 , n ) ;
    affiche_matrice( m , n );

    desalloue_matrice( &mat1 , n ); //pb dans cette fonction
    desalloue_matrice( &mat2 , n );
    desalloue_matrice( &m , n ) ;
}

