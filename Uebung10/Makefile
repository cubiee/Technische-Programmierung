CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -c
OUTNAME = klimadaten

all: compile clean

compile: main.o klimadatenanalyse.o klimadatenanalyse.h
	$(CC) -o $(OUTNAME) main.o klimadatenanalyse.o

main.o: main.c klimadatenanalyse.h
	$(CC) $(CFLAGS) main.c

klimadatenanalyse.o: klimadatenanalyse.c klimadatenanalyse.h
	$(CC) $(CFLAGS) klimadatenanalyse.c

clean:
	rm -f *.o