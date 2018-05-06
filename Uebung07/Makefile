CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -c
OUTNAME = rechner

all: compile clean

compile: rechner.o 
	$(CC) -o $(OUTNAME) rechner.o
rechner.o: rechner.c
	$(CC) $(CFLAGS) rechner.c
clean:
	rm -f *.o