#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include "Chaine.h"




Chaines* lectureChaines(FILE *f){

  Chaines *c = malloc(sizeof(Chaines *));
  if( c==NULL ){
    return NULL ;
  }

  int i = 0 , nbchaine , nbPoints ;
  char buffer[256] ;
  fgets( buffer , 256 , f);
  sscanf( buffer , "NbChain: %d\n", &nbchaine );
  c->nbChaines = nbchaine ;
  int gamma ;
  fgets( buffer , 256 , f);
  sscanf( buffer , "Gamma: %d\n", &gamma );
  c->gamma = gamma ;
  printf("%d %d\n",c->nbChaines,c->gamma);

  while( i < c->nbchaine && fgets( buffer , 256 , f) ){
    c->chaines->numero = i ;
    sscanf( buffer , "i %d" , %nbPoints );
    int x,y ;
    fgets( buffer , 256 , f );
    sscanf(  )
    c->chaines->points->x = 


    i++;

  }

  return NULL ;
  


}

int main(int argc, char** argv){
  FILE *f = fopen( "00014_burma.cha" , "r" ) ;
  Chaines *c = lectureChaines( f );

  fclose(f);
  return 0 ;

}