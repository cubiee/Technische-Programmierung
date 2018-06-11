#include <stdio.h>
#include <string.h>

#include <bool.h>
#include <klima_defines.h>
#include <klimadatenanalyse.h>
#include <daten_verarbeiten.h>

/*
Funktion zum auslesen der Klimadaten aus angegebener datei
*/
int lese_Klimadaten(FILE* datei, KLIMADATEN *k, int anzahl_kopfzeilen, int max_anzahl, int *anzahl){
	BOOL status = TRUE;
	char buffer[BUFFERSIZE] = { '\0' };
	KLIMADATEN puffer = new_klimadaten();

	int i = 0;
	//kopfzeilen ueberspringen
	for (i = 0; i < anzahl_kopfzeilen; i++){
		if (NULL == fgets(buffer, BUFFERSIZE, datei)){
			//fehler beim einlesen der kopfzeilen
			printf("NULLK\n");
		}
	}

	i = 0;
	int stop = 0;
	int pruefe = 0;
	//daten einlesen
	while ((i < max_anzahl) && (stop == 0)){
		memset(buffer, '\0', BUFFERSIZE);
		if (NULL == fgets(buffer, BUFFERSIZE, datei)){
			//fehler beim einlesen der daten
			printf("NULLD\n");
		}
		
		pruefe = 0;
		pruefe = parse_raw_data(buffer, &puffer);
		//pruefen ob formatfehler vorliegen
		if (pruefe < 14){
			if (pruefe < 3){
				//schwerwiegender fehler
				printf("Schwerwiegender Formatfehler in zeile %i , Programmabbruch ausfuehren:\n", i + anzahl_kopfzeilen + 1);
				stop = 1;
				status = FALSE;
			}
			else{
				//formatfehler
				printf("Formatfehler in zeile %i setze werte = 0.0\n", i + anzahl_kopfzeilen + 1);
				setze_werte_0(&puffer);
			}
		}
		//speichern in k
		if (stop == 0){
			k[i] = puffer;
			i++;
		}
	}
	return status;
}

/*
Funktion zum verarbeiten der eingelesenen klimadaten
*/
void mache_temperatur(KLIMADATEN k[], TEMPERATUR t[], int anzahl){
	for (int i = 0; i < anzahl; i++){
		jjjjmmdd_to_date(k[i].jjjjmmdd, &(t[i].datum));
		t[i].stat = k[i].stat;
		t[i].tg = k[i].tg;
		t[i].tn = k[i].tn;
		t[i].tm = k[i].tm;
		t[i].tx = k[i].tx;
	}
	return;
}

/*
Funktion zum ausgeben einzelner temperaturwerte
*/
void ausgabe_temperatur(TEMPERATUR t){
	printf("Temperaturen am %2i. %-9s %4i: TG %7.2lf / TN %7.2lf / TM %7.2lf / TX %7.2lf\n", t.datum.tag, t.datum.monat, t.datum.jahr, t.tg, t.tn, t.tm, t.tx);
	return;
}

/*
Funktion zum ausgeben der verabeiteten temperaturdaten
*/
void ausgabe_temperaturen(TEMPERATUR t[], int anzahl){
	for (int i = 0; i < anzahl; i++){
		printf("Temperaturen am %2i. %-9s %4i: TG %7.2lf / TN %7.2lf / TM %7.2lf / TX %7.2lf\n", t[i].datum.tag, t[i].datum.monat, t[i].datum.jahr, t[i].tg, t[i].tn, t[i].tm, t[i].tx);
	}
	return;
}

/*
Funktion zum finden des temperatur maximums
*/
TEMPERATUR findeMaxTemperatur(TEMPERATUR t[], int anzahl){
	TEMPERATUR maximum = new_temperatur();
	maximum = t[0];
	for (int i = 0; i < anzahl; i++){
		if (maximum.tx < t[i].tx){
			maximum = t[i];
		}
	}
	return maximum;
}
