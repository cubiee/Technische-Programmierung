#include <stdio.h>
#include <stdlib.h>

#include <bool.h>
#include <klima_defines.h>
#include <klimadatenanalyse.h>
#include <menue.h>
#include <daten_verarbeiten.h>


int main(int argc, char *argv[]){
	if (argc != 2){
		printf("Falsche Anzahl Parameter beim aufruf von ./klimadatenanalyse!\n");
		menue();
	}
	else{
		if (!check_input_parameter(argv[1])){
			printf("Ungueltiger dateiname!\n");
			menue();
		}
		else{
			FILE *datafile;
			if (NULL == (datafile = fopen(argv[1], "r"))){
				printf("Oeffnen des Datensatz nicht moeglich!\n");
				menue();
			}
			else{
				FILEINFORMATION info = new_fileinformation();
				if (!check_data_file(datafile, &info)){
					printf("Formatfehler!\n");
					menue();
				}
				else{
					printf("Kopfzeilen  : %i\n", info.kopfzeilen);
					printf("Datensaetze : %i\n", info.anzahl_datensaetze);
					KLIMADATEN *rohdaten = malloc(info.anzahl_datensaetze * sizeof(KLIMADATEN));
					TEMPERATUR *temperaturdaten = malloc(info.anzahl_datensaetze * sizeof(TEMPERATUR));
					if (NULL == rohdaten || NULL == temperaturdaten){
						printf("Speicherbereitstellung fehlgeschlagen\n");
					}
					else{
						int i = 0;
						for (i = 0; i < info.anzahl_datensaetze; i++){
							rohdaten[i] = new_klimadaten();
							temperaturdaten[i] = new_temperatur();
						}
						if (lese_Klimadaten(datafile, rohdaten, info.kopfzeilen, info.anzahl_datensaetze, &i)){
							mache_temperatur(rohdaten, temperaturdaten, info.anzahl_datensaetze);
							ausgabe_temperaturen(temperaturdaten, info.anzahl_datensaetze);
							printf("Maximaltemperatur:\n");
							ausgabe_temperatur(findeMaxTemperatur(temperaturdaten, info.anzahl_datensaetze));
						}
					}
				}
			}
		}
	}
	return 0;
}