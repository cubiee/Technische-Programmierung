#include <stdio.h>
#include <menue.h>
#include <wertlesen.h>


int menue(void){
	char auswahl[] = {
		"Bitte waehlen Sie :\n"
		"  1 - Berechnung der Quersumme\n"
		"  2 - Berechnung Pythagoras\n"
		"  3 - Zahl n durch t teilbar\n"
		"  0 - Ende\n"
	};
	printf(auswahl);
	int wahl = 0;
	while (!wert_lesen("", 0, 4, &wahl)){
		printf("Ungueltige eingabe!\nBitte erneut eingeben :");
	}
	return wahl;
}