#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "klimadatenanalyse.h"
#include "parsing_data.h"



int main(int argv , char *argc[]){
	if (argv == 2){
		int fehlercode = check_input_parameter(argc[1]);
		printf("Fehlercode: %d\n", fehlercode);
		
		int i = 0;
		KLIMADATEN klimadaten[ARRAYSIZE];
		for (i = 0; i < ARRAYSIZE; i++){
			klimadaten[i] = new_klimadaten();
		}
		TEMPERATUR temperatur[ARRAYSIZE];
		for (i = 0; i < ARRAYSIZE; i++){
			temperatur[i] = new_temperatur();
		}

		FILE *file;
		file = fopen("testdatei.txt", "r");
		FILEINFORMATION info;
		check_data_file(file, &info);
		printf("Kopfzeilen: %d\n Datensaetze: %d\n", info.kopfzeilen, info.anzahl_datensaetze);


		int nmbr = 0;
		int *anzahl;
		anzahl = &nmbr;
		if (0 == lese_Klimadaten(file, klimadaten, 5, 200, anzahl)){
			printf("2   %d   \n", *anzahl);
			mache_temperatur(klimadaten, temperatur, 200);
			ausgabe_temperaturen(temperatur, 200);
		}
		printf("Maximum\n");
		TEMPERATUR maximum = findeMaxTemperatur(temperatur, 200);
		ausgabe_temperatur(maximum);
	}
	return EXIT_SUCCESS;
}