#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define N 20

int **alloue_matrice(int n ){
    int **tab = malloc( n *sizeof(int*));
    for(int i = 0 ; i < n ; i++ ){ // alloue toutes les cases du tableau de n cases
        tab[i] = (int *)malloc( n * sizeof(int *));
    }
    return tab; //retourne la matrcie allouée
}

void desalloue_matrice( int ***tab , int n ){
    for(int i=0 ; i<n ;i++){ //parcourt la matrice
        int *temp=(*tab)[i];
        free(temp); // libere tous les tableaux contenus dans tab
    }
    free(*tab);
}

void remplir_matrice( int **tab , int n , int v ){
    //parcourt l'ensemble de la matrcie
    for(int i = 0 ; i < n ; i++){
        for( int j = 0 ; j < n ; j++ ){
            tab[i][j] = rand()%v;//retourne un entier entre 0 et (v-1)
        }
    }
}

void affiche_matrice( int **tab , int n ){
    for( int i = 0 ; i < n ; i++ ){
        for( int j = 0 ; j < n ; j++ ){ //parcourt la matrice
            printf("%5d ", tab[i][j] ); //affiche avec %5 pour ce soit plus beau
        }
        printf("\n"); //saute une ligne à chaque fin de lignes
    }
}

int algo1( int **tab, int n ) { //tous_différents

    for (int i1 = 0; i1 < n; i1++){
        for (int j1 = 0; j1 < n; j1++){
          //parcourt tous les elements du tableau pour savoir si ils sont présents à d'autres endroits

            for (int i2 = 0; i2 < n; i2++){
                for (int j2 = 0; j2 < n; j2++){
                  //re parcourt le tableau pour savoir si tab[i][j] est présent ailleurs qu'à la position i,j

                    if ((i1 != i2 || j1 != j2) && (tab[i1][j1] == tab[i2][j2])){ //si c'est le cas alors return 0, false
                        return 0; 
                    }

                }
            }

        }
    }//si on arrive ici c'est que tous les elements sont differents car on a pas return 0
    return 1; //on peut donc dire que c'est vrai, ils sont tous differents
}

int algo2(int **tab, int n, int v) { //tous_différents, meilleure complexite
    int *m = malloc(v*sizeof(int)) ; //crée un tableau de v(borne) cases
    for(int i = 0; i < v; i++){
        m[ i ] = 0; // on l'initialise avec des 0
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(m[tab[i][j]] != 0) { // ce n'est pas égale à 0 donc il y a déjà une valeur à cette position
                return 0; //donc il y a doublons
            }
            
            m[tab[i][j]] = 1; // sinon on pose un 1 à cette position
        }
    }
    free(m) ; // on libère la mémoire de notre tableau

    return 1;
}


void remplir_Sup(int **tab, int n ){

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){

      if (i > j){ //remplit tab de 0 en dessous de la diagonale
        tab[i][j] = 0;
      }

    }
  }
}

void remplir_Inf(int **tab, int n ){

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){

      if (i < j){
        tab[i][j] = 0;
      }

    }
  }
}


int **produit_matrice1(int **tab1, int **tab2, int n){ // retourne le produit des matrices
  int **res= alloue_matrice( n ) ;

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      res[i][j] = 0 ; //initialise notre matrice de 0

      for (int k = 0; k < n; k++){
        res[i][j] += tab1[i][k] * tab2[k][j]; //calculs les prduits de matrice
      }

    }
  }

  return res ;
}

int  **produit_matrice2(int **tab1, int **tab2, int n){
  int **res = alloue_matrice( n ) ;

  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      res[i][j]=0;

      for (int k = i; k < n; k++){ //meme chose que produit_matrice1 sauf que l'on évite les calculs inutiles
        res[i][j] += tab1[i][k] * tab2[k][j];
      }

    }
  }

  return res ;
}

int equals( int **mt1, int **mt2, int n) { // fonction qui vérifie si des matrices sont égales
// ( on s'en sert pour un petit jeu de test )
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
    remplir_Sup( mtest1 , 15 ) ;
    remplir_Inf( mtest2 , 15 ) ;
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


    // on test le fonctionnement de nos fonctions

    remplir_matrice( mat1 , n , v ); //pour bien remplir les matrices
    remplir_matrice( mat2 , n ,v ) ;

    printf("\nMatrice 1 :\n");
    affiche_matrice( mat1 , n ) ; // pour afficher nos matrices
    printf("\nMatrice 2 : \n");
    affiche_matrice( mat2 , n ) ;

    if ( algo1( mat1 , n ) == 1 ){ //tests si les elements sont differents ou non
        printf("\nTous les elements de mat1 sont différents\n");
    }else{
        printf("\nLes éléments de mat1 ne sont pas tous différents\n");
    }
    
    if ( algo2( mat2 , n , v ) == 1 ){ //test les algo1 et algo2 pour une meme matrice
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
    m = produit_matrice1( mat1 , mat2 , n ) ; // tests le prduit_matrice1
    affiche_matrice( m , n );
    
    printf("\nProduit de mat2 et mat1 :\n");
    m2 = produit_matrice1( mat2 , mat1 , n ) ;
    affiche_matrice( m2 , n ) ;


    unsigned long temps_initial1, temps_initial2, temps_final1, temps_final2 ; // pour pouvoir faire nos graphiques
    double temps1, temps2 ;

    // petit test de temps cpu pour tester les différences entre les algorithmes tous_differents
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


    remplir_Sup( mat1 , n ) ; //test les matrices triangulaire supérieures et inférieures
    remplir_Inf( mat2 , n ) ;
    int **m_triangulaire = NULL ;
    
    printf("\nPassage aux matrices trianglaire :\n") ;

    printf("\nMatrice 1 :\n");
    affiche_matrice( mat1 , n ) ;
    printf("\nMatrice 2 : \n");
    affiche_matrice( mat2 , n ) ;

    printf("\nProduit 1 de mat1 et mat2 :\n");
    m_triangulaire = produit_matrice1( mat1, mat2, n) ; //test le produit de matrices triangulaires avec nos deux algorithmes
    affiche_matrice( m_triangulaire , n ) ;

    printf("\nProduit 2 de mat1 et mat2 :\n");
    m_triangulaire = produit_matrice2( mat1 , mat2 , n ) ;
    affiche_matrice( m_triangulaire , n );

    //libere la mémoire utilisé
    desalloue_matrice( &mat1 , n ); 
    desalloue_matrice( &mat2 , n );
    desalloue_matrice( &m , n ) ;
    desalloue_matrice( &m2 , n ) ;
    desalloue_matrice( &m_triangulaire , n ) ;
    



    FILE *f=fopen("sortie_vitesse_differents.txt", "w"); // pour placer les resultats attendus en question 2.5.3
    for(int i = 0; i < N; i++) {

        mat1 = alloue_matrice( n ) ;
        remplir_matrice(mat1 , n , v);

        //calcule les temps cpu pour les deux algorithmes
        temps_initial1 = clock() ;
        algo1( mat1 , n );
        temps_final1 = clock() ;
        temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

        temps_initial2 = clock() ;
        algo2( mat1 , n, v ) ;
        temps_final2 = clock() ;
        temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;

        fprintf(f, "%d %f %f\n", n, temps1, temps2); //écrit les resultats dans le fichier

        desalloue_matrice( &mat1 , n );
        n++; // on augmente la taille de la matrice
    }
    fclose(f) ; // on oublie pas de fermer le fichier

    //pour les resultats 2.6.4
    FILE *f2 = fopen("sortie_vitesse_prodMat.txt", "w");
    for(int i = 0 ; i < N ; i++ ){

      mat1 = alloue_matrice( n ) ;
      mat2 = alloue_matrice( n ) ;

      remplir_matrice( mat1 , n , v);
      remplir_matrice( mat2 , n , v );
      //transforme les matrices en matrices supérieures et inférieures
      remplir_Sup( mat1 , n ) ; 
      remplir_Inf( mat2 , n ) ;


      //calcule les temps cpu
      temps_initial1 = clock() ;
      m = produit_matrice1( mat1 , mat2 , n );
      temps_final1 = clock() ;
      temps1 = ((double)(temps_final1 - temps_initial1)) / CLOCKS_PER_SEC ;

      temps_initial2 = clock() ;
      m2 = produit_matrice2( mat1 , mat2 , n ) ;
      temps_final2 = clock() ;
      temps2 = ((double)(temps_final2 - temps_initial2)) / CLOCKS_PER_SEC ;

      fprintf(f, "%d %f %f\n", n, temps1, temps2); // écrit les resultats dans le fichier


      desalloue_matrice( &mat1 , n );
      desalloue_matrice( &mat2 , n );
      desalloue_matrice( &m , n );
      desalloue_matrice( &m2 , n );
      n++; // augmente la taille des matrices 
    }
    fclose( f2 ) ; //ferme le fichier


    return 0 ;
    
}

/*
=============================
RESULTAT D'UN MAIN :
=============================


Matrice 1 :
   64    55    63    16 
   53    89    29    81 
   68    99    80    87 
   15    71    95    58 

Matrice 2 : 
   66    80    61    59 
   93    75    19    23 
   92    34    51    72 
   34    56     6    51 

Tous les elements de mat1 sont différents
Les éléments de mat2 ne sont pas tous différents
Les éléments de mat2 ne sont pas tous différents

Produit de mat1 et mat2 :
15679 12283  8258 10393 
17197 16437  6889 11393 
24013 20457 10631 16486 
18305 13003  7457 12316 

Produit de mat2 et mat1 :
13497 20978 16963 16265 
11564 15304 11739 10550 
12238 18247 17702 12839 
 6317 11069  9091  8560 


CPU 1 : 0.000005


CPU 2 : 0.000003

Passage aux matrices trianglaire :

Matrice 1 :
   64    55    63    16 
    0    89    29    81 
    0     0    80    87 
    0     0     0    58 

Matrice 2 : 
   66     0     0     0 
   93    75     0     0 
   92    34    51     0 
   34    56     6    51 

Produit 1 de mat1 et mat2 :
15679  7163  3309   816 
13699 12197  1965  4131 
10318  7592  4602  4437 
 1972  3248   348  2958 

Produit 2 de mat1 et mat2 :
15679  7163  3309   816 
13699 12197  1965  4131 
10318  7592  4602  4437 
 1972  3248   348  2958 
 */

