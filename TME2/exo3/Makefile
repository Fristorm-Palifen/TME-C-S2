GFLAGS = -g -Wall
CC = gcc
EXE = main


all : $(EXE)
%.o : %.c %.h
	$(CC) -c $(GFLAG) $<

main :main.o biblioH.o entreeSortieH.o biblioLC.o entreeSortieLC.o
	$(CC) -o  $@ $(GFLAG) $^

clean :
	rm -f *.o





