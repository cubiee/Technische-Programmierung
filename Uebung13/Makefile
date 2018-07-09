all: led clean

led: mapping.o LED.o main.o 
	gcc -Wall -pedantic mapping.o LED.o main.o -o led

mapping.o: mapping.c
	gcc -Wall -pedantic -c mapping.c

LED.o: LED.c
	gcc -Wall -pedantic -c LED.c

main.o: main.c
	gcc -Wall -pedantic -c main.c

clean:
	rm -f *.o