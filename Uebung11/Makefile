CC = gcc
LIBDIR = ./Header
VPATH = $(LIBDIR)
CFLAGS = -Wall -pedantic -std=c99 -c -I $(LIBDIR)
OBJECTS = main.o menue.o pythagoras.o quersumme.o teilbar.o wertlesen.o
PROJECTNAME = funktionen



all: compile clean

compile: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROJECTNAME)

main.o: main.c bool.h menue.h pythagoras.h quersumme.h teilbar.h wertlesen.h 
	$(CC) $(CFLAGS) main.c

menue.o: menue.c menue.h
	$(CC) $(CFLAGS) menue.c

pythagoras.o: pythagoras.c pythagoras.h
	$(CC) $(CFLAGS) pythagoras.c

quersumme.o: quersumme.c quersumme.h
	$(CC) $(CFLAGS) quersumme.c

teilbar.o: teilbar.c teilbar.h
	$(CC) $(CFLAGS) teilbar.c

wertlesen.o: wertlesen.c wertlesen.h
	$(CC) $(CFLAGS) wertlesen.c

clean:
	rm -rf *.o
