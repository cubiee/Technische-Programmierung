CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -c
OUTNAME = klimadaten

all: compile

compile: main.o klimadatenanalyse.o klimadatenanalyse.h parsing_data.o parsing_data.h
	$(CC) -o $(OUTNAME) main.o klimadatenanalyse.o parsing_data.o

main.o: main.c klimadatenanalyse.h
	$(CC) $(CFLAGS) main.c

klimadatenanalyse.o: klimadatenanalyse.c klimadatenanalyse.h
	$(CC) $(CFLAGS) klimadatenanalyse.c

parsing_data.o: parsing_data.c parsing_data.h
	$(CC) $(CFLAGS) parsing_data.c

clean:
	rm -f *.o