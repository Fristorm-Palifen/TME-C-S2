# TME 1
## 3000028 +

### Exercice 1
    Q1.1: 
    - Le programme aloue un tableau d'entier de 10 places dans l'ordre décroissant.
    - Il y a une erreur de segmentation!


    Q1.2: 
    - Après i = 0, i essaye de prendre la valeur 4294967295 ( INT_MAX ) car i ne peut pas etre negatif car unsigned int.
    - A l'occurrence d'après, la condition du for est toujours respecter car i est toujours supérieur ou égale à 0 et donc on essaye d'accéder à une valeur non allouée du tableau ( car initialiser à 10 places ), donc segmentation fault.


    Q1.3: 
    Il y a deux solutions pour corriger l'erreur :
    - On retire >= par > ligne 12 et après la boucle on rajoute tab[i]=0
    - On déclare i en `int` et non en `unsigned int`


    Q1.4: 
    - A la lecture du code, le programme ne fait qu'enregistrer une adresse mise en parametre puis l'affiche.
    - Erreur de segmentation

    Q1.5: 
    - Le print new->rue affiche `0x0`
    - Après le break 16, l'erreur survient à la ligne 15. 
    - La cause de l'erreur : on essaye de mettre dans un espace memoire pointé par new->rue sur un emplacement non alloué, il y a donc une segmentation fault.
    - Afin de corriger le programme nous pouvons :
        - mettre un malloc sur new->rue : ``malloc(strlen(r)*sizeof(char))``
        - déclarer rue statiquement ``char rue[100];``
    Ce qui alloue à new->rue un emplacement capable de prendre rue.

    Q1.6: 
    - Il crée un tableau dans une structure de donnée prévu à cet effet, il crée un tableau de 100 places pour des int.
    - Il place des int dans le tableau et affiche le tableau.
    - Le programme séxécute bien, sans erreur apparante.

    Q1.7: 
    - Le programme ne libère pas le tableau avec un free(t), il libère seulement maxTaille et position.

    Q1.8: 
    - Les 400 bytes perdues correspondent au tableau perdu puisque le free(t) ne libère pas la mémoire de tab alloué dans initTableau.

    Q1.9: 
    - free(t->tab); à la ligne juste avant free(t);

### Exercice 2
    Q2.1: 
    - Nous avons choisi la 2ème méthode pour avoir moins de mémoire allouée ( 1ère méthode copie tableau)

```C
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
```

    Q2.2: 
    1)
```C
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
```

    2) PAS REUSSI A TROUVER LE 2EME ALGO



    Q2.3:  COMPARER LES 2 ALGO

    Q2.4: PROBLEME ALLOCATION ( dsl jsuis pas fort en 2D, alloue_matrice fonctionne elle alloue 16 bytes mais desalloue_matrice ne fonctionne pas )
```C
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

void alloue_matrice( int **tab , int n ){
    *tab = (int *)malloc( n *sizeof(int));
    for(int i = 0 ; i < n ; i++ ){
        tab[i] = (int *)malloc( n * sizeof(int));
    }
}

void desalloue_matrice( int **tab , int n ){
    for(int i=0 ; i<n ;i++){
        free(tab[i]);
    }free(*tab);
}

void remplir_matrice( int **tab , int n , int v ){
    for(int i = 0 ; i < n ; i++){
        for( int j = 0 ; j < n ; j++ ){
            tab[i][j] = rand()%(v) ;
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


int main(){
    srand(time(NULL));
    int **tab = NULL ; 
    int n = 4 , v = 100 ;
    alloue_matrice( tab , n ) ;
    remplir_matrice( tab , n , v );
    affiche_matrice( tab , n ) ;

    desalloue_matrice( tab , n ); //pb dans cette fonction
}
```

    Q2.5: PRB 2EME ALGO ( j'ai pas reussi la meilleure complexité )
```C
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
```

    Q2.6: PRB 2EME ALGO, FAIRE LA COMPARAISON
```C
int **produit_matrice1(int ** m1, int **m2, int n){
    int **res = NULL ;
    alloue_matrice( res , n ) ;

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
```
