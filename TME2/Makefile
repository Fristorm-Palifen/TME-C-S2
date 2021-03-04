CC=gcc
CFLAGS=-W -Wall -ansi -pedantic
LDFLAGS=
EXEC=biblioLC

all: main

main: main.o biblioLC.o
    gcc biblioLC.o main.o -o main

biblioLC.o: biblioLC.c biblioLC.h
    gcc -c biblioLC.c -o biblioLC.o

biblioLC: biblioLC.o
    $(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
    $(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -f *.o *~ $(PROGRAMS)
