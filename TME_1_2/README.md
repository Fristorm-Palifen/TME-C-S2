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
#define N 20


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

int main(){
    srand(time(NULL));
    int n = 500, v = 100;

    int *tab = NULL ;
    alloue_tableau(&tab, n );
    remplir_tableau(&tab, v, n );
    affiche_tableau(&tab, n );

    desalloue_tableau(tab);
    return 0;
}
```

    Q2.2: 
    1)
```C
int algo1(int *tab, int n){
    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            res += pcarre( tab[i] - tab[j] ) ;
    return res ;
    
}

int algo2(int *tab, int n){
    int res = 0;
    int sommeCarre = 0;

    for(int i = 0; i < n; i++) {
        res += tab[ i ];
        sommeCarre += tab[ i ] * tab[ i ];
    }

    return 2 * n * sommeCarre - 2 * pcarre(res) ;
    
}
```




    Q2.3:  
```C
    int *t = NULL ;
    FILE *f=fopen("sortie_vitesse.txt", "w");
    for(int i = 0; i < N; i++) {

        alloue_tableau(&t , n);
        remplir_tableau(&t, v, n);

        temps_initial1 = clock();
        algo1(t, n);
        temps_final1 = clock();
        temps1 = ((double) (temps_final1 - temps_initial1)) / CLOCKS_PER_SEC;

        temps_initial2 = clock();
        algo2(t, n);
        temps_final2 = clock();
        temps2 = ((double) (temps_final2 - temps_initial2)) / CLOCKS_PER_SEC;

        fprintf(f, "%d %f %f\n", n, temps1, temps2);

        desalloue_tableau(t);
        n++;
    }
    fclose(f) ;
```
    METTRE LES GRAPHES

    Q2.4:
```C
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


int main(){
    srand(time(NULL));
    int n = 4 , v = 100 ;
    int **mat1 = alloue_matrice(n);
    int **mat2 = alloue_matrice(n) ;

    remplir_matrice( mat1 , n , v );
    remplir_matrice( mat2 , n ,v ) ;

    printf("\nMatrice 1 :\n");
    affiche_matrice( mat1 , n ) ;
    printf("\nMatrice 2 : \n");
    affiche_matrice( mat2 , n ) ;

    desalloue_matrice( &mat1 , n ); 
    desalloue_matrice( &mat2 , n );
}
```

    Q2.5: 
```C
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


    main :
```C
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
```
