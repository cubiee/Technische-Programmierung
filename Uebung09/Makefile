CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -c
OUTNAME = teilnehmer

all: compile clean

compile: teilnehmer.o
	$(CC) -o $(OUTNAME) teilnehmer.o

teilnehmer.o: teilnehmer.c
	$(CC) $(CFLAGS) teilnehmer.c

clean:
	rm -f *.o
