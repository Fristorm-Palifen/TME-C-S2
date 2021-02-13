#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define N 20

int **alloue_matrice(int n ){
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
            tab[i][j] = rand()%v;
        }
    }
}

void affiche_matrice( int **tab , int n ){
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < n ; j++ ){
            printf("%5d ", tab[i][j] );
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

int algo2(int **tab, int n, int v) {
    int *m = malloc(v*sizeof(int)) ;
    for(int i = 0; i < v; i++)
        m[ i ] = 0;
    

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(m[tab[i][j]] != 0) {
                return 0;
            }
            
            m[tab[i][j]] = 1;
        }
    }
    free(m) ;

    return 1;
}


void remplir_Sup(int **m, int n ){
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++){
      if (i > j)
        m[i][j] = 0;
    }
}

void remplir_Inf(int **m, int n ){
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++){
      if (i < j)
        m[i][j] = 0;
    }
}
int **produit_matrice1(int **tab1, int **tab2, int n){
  int **res= alloue_matrice( n ) ;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++){
      res[i][j]=0;
      for (int k = 0; k < n; k++)
        res[i][j] += tab1[i][k] * tab2[k][j];
    }
  return res ;
}

int  **produit_matrice2(int **tab1, int **tab2, int n){
  int **res = alloue_matrice( n ) ;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++){
      res[i][j]=0;
      for (int k = i; k < n; k++)
        res[i][j] += tab1[i][k] * tab2[k][j];
    }
  return res ;
}

int equals( int **mt1, int **mt2, int n) {
    for(int i =0; i<n;i++) {
        for (int j = 0; j < n; j++)
        {
            if (mt1[i][j]!=mt2[i][j]){
                return 0;
            }
        }
    }
    return 1;
}

int main(){
    srand(time(NULL));
    //Jeux de test//
    int **mtest1 = alloue_matrice(15);
    int **mtest2 = alloue_matrice(15);
    int **mtesta = NULL; 
    int **mtestb = NULL;
    remplir_matrice( mtest1 , 15 , 200 );
    remplir_matrice( mtest2 , 15 ,200 ) ;
    if (equals(mtest1,mtest1,15)!=1) //verification de l'algorithme de verif par experience temoin
    {
        printf("L'algorithme de verification est erroné!\n");
        desalloue_matrice(&mtest1, 15);
        desalloue_matrice(&mtest2, 15);
        return 1;
    }
    
    if (equals(mtest1,mtest2,15)==1) //verification de la difference des 2 matrice (on ne veux pas 2 matrice egale!!)
    {
        desalloue_matrice(&mtest1, 15);
        desalloue_matrice(&mtest2, 15);
        return main();
    }
    mtesta = produit_matrice1( mtest1 , mtest2 , 15 ) ;
    remplir_Sup( mtest1 , 15 ) ;
    remplir_Inf( mtest2 , 15 ) ;
    mtestb = produit_matrice2( mtest1 , mtest2 , 15 ) ;
    if (equals(mtesta,mtestb,15)!=1)
    {
        printf("Erreur les 2 algo de produit donne pas le meme resultat!!\n");
        desalloue_matrice(&mtest1, 15);
        desalloue_matrice(&mtest2, 15);
        desalloue_matrice(&mtesta, 15);
        desalloue_matrice(&mtestb, 15);
        return 0;
    }
    desalloue_matrice(&mtest1, 15);
    desalloue_matrice(&mtest2, 15);
    desalloue_matrice(&mtesta, 15);
    desalloue_matrice(&mtestb, 15);
    //Fin du jeu de test

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

    printf("\nProduit de mat1 et mat2 :\n");
    m = produit_matrice1( mat1 , mat2 , n ) ;
    affiche_matrice( m , n );
    
    printf("\nProduit de mat2 et mat1 :\n");
    m2 = produit_matrice1( mat2 , mat1 , n ) ;
    affiche_matrice( m2 , n ) ;


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


    printf("\n\nCPU 1 : %f\n", temps1 );
    printf("\n\nCPU 2 : %f\n", temps2 );


    remplir_Sup( mat1 , n ) ;
    remplir_Inf( mat2 , n ) ;
    int **m_triangulaire = NULL ;
    
    printf("\nPassage aux matrices trianglaire :\n") ;

    printf("\nMatrice 1 :\n");
    affiche_matrice( mat1 , n ) ;
    printf("\nMatrice 2 : \n");
    affiche_matrice( mat2 , n ) ;

    printf("\nProduit 1 de mat1 et mat2 :\n");
    m_triangulaire = produit_matrice1( mat1, mat2, n) ;
    affiche_matrice( m_triangulaire , n ) ;

    printf("\nProduit 2 de mat1 et mat2 :\n");
    m_triangulaire = produit_matrice2( mat1 , mat2 , n ) ;
    affiche_matrice( m_triangulaire , n );

    desalloue_matrice( &mat1 , n ); 
    desalloue_matrice( &mat2 , n );
    desalloue_matrice( &m , n ) ;
    desalloue_matrice( &m2 , n ) ;
    desalloue_matrice( &m_triangulaire , n ) ;
    



    FILE *f=fopen("sortie_vitesse_differents.txt", "w");
    for(int i = 0; i < N; i++) {

        mat1 = alloue_matrice( n ) ;
        remplir_matrice(mat1 , n , v);

        temps_initial1 = clock() ;
        algo1( mat1 , n );
        temps_final1 = clock() ;
        temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

        temps_initial2 = clock() ;
        algo2( mat1 , n, v ) ;
        temps_final2 = clock() ;
        temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;

        fprintf(f, "%d %f %f\n", n, temps1, temps2);

        desalloue_matrice( &mat1 , n );
        n++;
    }
    fclose(f) ;

    FILE *f2 = fopen("sortie_vitesse_prodMat.txt", "w");
    for(int i = 0 ; i < N ; i++ ){
      mat1 = alloue_matrice( n ) ;
      mat2 = alloue_matrice( n ) ;
      remplir_matrice( mat1 , n , v);
      remplir_matrice( mat2 , n , v );

      temps_initial1 = clock() ;
      m = produit_matrice1( mat1 , mat2 , n );
      temps_final1 = clock() ;
      temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

      remplir_Sup( mat1 , n ) ; 
      remplir_Inf( mat2 , n ) ;

      temps_initial2 = clock() ;
      m2 = produit_matrice2( mat1 , mat2 , n ) ;
      temps_final2 = clock() ;
      temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;

      fprintf(f, "%d %f %f\n", n, temps1, temps2);

      desalloue_matrice( &mat1 , n );
      desalloue_matrice( &mat2 , n );
      desalloue_matrice( &m , n );
      desalloue_matrice( &m2 , n );
      n++;
    }
    fclose( f2 ) ;


    return 0 ;
    
}

