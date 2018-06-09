#include <stdio.h>

#include <bool.h>
#include <menue.h>
#include <pythagoras.h>
#include <quersumme.h>
#include <teilbar.h>
#include <wertlesen.h>


int main(void){
	int auswahl;
	int zahl;
	int teiler;
	BOOL stop = FALSE;

	while(stop == FALSE){
		auswahl = menue();
		switch (auswahl){
		case CMD_QUER:
			//quersumme
			while (!wert_lesen("Von welcher Zahl soll die quersumme gebildet werden? ", 0, 2147483647, &zahl)){
				printf("Ungueltige eingabe!\n");
			}
			printf("Die Quersumme von %i ist %i\n",zahl, quersumme(zahl));
			printf("\n");
			break;
		case CMD_PYTH:
			//pythagoras
			while (!wert_lesen("Bis zu welcher zahl sollen die tripel ausgegeben werden? ", 0, 100000, &zahl)){
				printf("Ungueltige eingabe!\n");
			}
			pythagoras(zahl);
			printf("\n");
			break;
		case CMD_TBAR:
			//teilbar
			while (!wert_lesen("Bitte Zahl eingeben: ", 0, 10000, &zahl)){
				printf("Ungueltige eingabe!\n");
			}
			while (!wert_lesen("Bitte Teiler eingeben: ", 0, 10000, &teiler)){
				printf("Ungueltige eingabe!\n");
			}
			if (teilbar(zahl, teiler)){
				printf("%i / %i = %i\n", zahl, teiler, zahl / teiler);
			}
			else{
				printf("Nicht teilbar\n");
			}
			printf("\n");
			break;
		case CMD_ENDE:
			//ende
			printf("Ende\n");
			stop = TRUE;
			break;
		}
	}
    return 0;
}