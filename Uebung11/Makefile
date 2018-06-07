CC = gcc
CFLAGS = -Wall -pedantic -std=c99 -c
OBJECTS = main.o pythagoras.o quersumme.o teilbar.o wertlesen.o
PROJECTNAME = funktionen


all: compile clean

compile: $(OBJECTS)
	$(CC) $(OBJECTS) -o $(PROJECTNAME)

main.o: main.c pythagoras.h quersumme.h teilbar.h wertlesen.h
	$(CC) $(CFLAGS) main.c

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