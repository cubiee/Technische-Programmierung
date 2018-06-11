CC = gcc
LIBDIR = ./Header
VPATH = $(LIBDIR)
CFLAGS = -I $(LIBDIR) -Wall -pedantic -std=c99 -c 
OBJECTS = main.o menue.o daten_verarbeiten.o klima_defines.o klimadatenanalyse.o
PROJECTNAME = klimadatenanalyse

all: compile clean

compile: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROJECTNAME)

main.o: main.c bool.h menue.h bool.h daten_verarbeiten.h klima_defines.h klimadatenanalyse.h
	$(CC) $(CFLAGS) main.c

menue.o: menue.c menue.h
	$(CC) $(CFLAGS) menue.c

daten_verarbeiten.o: daten_verarbeiten.c daten_verarbeiten.h klima_defines.h bool.h
	$(CC) $(CFLAGS) daten_verarbeiten.c

klima_defines.o: klima_defines.c  klima_defines.h
	$(CC) $(CFLAGS) klima_defines.c

klimadatenanalyse.o: klimadatenanalyse.c daten_verarbeiten.h klima_defines.h bool.h
	$(CC) $(CFLAGS) klimadatenanalyse.c

clean:
	rm -rf *.o
