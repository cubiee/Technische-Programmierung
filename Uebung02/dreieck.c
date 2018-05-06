/* dreieck.c
Programm zur ausgabe von einem Dreieck
Autor: 
Datum: 22. Nov. 2017
Kontakt: 
Compile: gcc -Wall -pedantic dreieck.c -o dreieck -std=c99
*/

/*
Beispiel:
hoehe = 5
breite = 2*hoehe - 1

Sterne im bereich von spalte = [hoehe-zeile , hoehe+zeile]
    1   2   3   4   5   6   7   8   9
0   _   _   _   _   *   _   _   _   _
1   _   _   _   *   *   *   _   _   _
2   _   _   *   *   *   *   *   _   _
3   _   *   *   *   *   *   *   *   _
4   *   *   *   *   *   *   *   *   *
*/




#include <stdio.h>


void flush(void);

int main(void) {
	int hoehe = 0;
	int breite = 0;
	printf("Programm zur ausgabe eines Dreiecks\n");
	printf("Bitte hoehe des Dreiecks angeben (h > 0): ");
	scanf("%i", &hoehe );

	while (hoehe <= 0) {  
		flush();
		printf("Ungültiger Eingabewert Hoehe bitte erneut eingeben!\n");
		printf("Bitte hoehe des Dreiecks angeben (h > 0): ");
		scanf("%i", &hoehe );
	}

	breite = 2*hoehe - 1;

	for (int zeile = 0; zeile < hoehe; zeile++) {
		for (int spalte = 1; spalte <= breite; spalte++) {
			if ((spalte >= hoehe - zeile) && (spalte <= hoehe + zeile)) {
				printf("*");
			}else{
				printf(" ");
			}
		}
		printf("\n");
	}
	return 0;
}


void flush(void) {
	int c = 0;
	while ((c = getchar()) != '\n' && c != EOF) { }
}
