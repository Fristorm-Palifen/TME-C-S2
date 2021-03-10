
all : prog


main.o: main.c
    gcc -c main.c

entreeSortieLC.o: entreeSortieLC.c entreeSortieLC.h
    gcc -c entreeSortieLC.c

biblioLC.o: biblioLC.c biblioLC.h
    gcc -c biblioLC.c

prog: main.o entreeSortieLC.o biblioLC.o entreeSortieH.o biblioH.o entreeSortieLC.h biblioLC.h entreeSortieH.h biblioH.h
    gcc -o prog main.o entreeSortieLC.o biblioLC.o entreSortieH.o biblioH.o

entreeSortieH.o: entreeSortieH.c entreeSortieH.h
    gcc -c entreeSortieH.c

biblioH.o: biblioH.h biblioH.c
    gcc -c biblioH.c


clean:
    rm *.o; rm prog





