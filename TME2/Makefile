CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
EXEC=biblioLC

all: main

main: biblioLC.o entreeSortieLC.o main.o
  gcc -Wall -o main biblioLC.o entreeSortieLC.o main.o

main.o: main.c entreeSortieLC.h
  gcc -Wall -o main.o -c main.c

biblioLC.o: biblioLC.c biblioLC.h
  gcc -Wall -o biblioLC.o -c biblioLC.c

entreeSortieLC.o: entreeSortieLC.c entreeSortieLC.h
  gcc -Wall -o entreeSortieLC.o -c entreeSortieLC.c

clear:
  rm -f *.o
  rm -f main


