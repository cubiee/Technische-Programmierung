#include <stdio.h>
#include <string.h>

#include <klima_defines.h>
#include <daten_verarbeiten.h>
#include <bool.h>

/*
Funktion zum herausfinden wieviele kopfzeilen und datensaetze vorhanden sind
*/
int check_data_file(FILE *datei, FILEINFORMATION *info){
	int i = 0;
	int stop = 0;
	char buffer[BUFFERSIZE] = { '\0' };
	int kopfzeilen = 0;
	BOOL status = TRUE;
	//suchen nach ---- ab dort beginnen die datensaetze
	while (stop != 1 && i < MAX_KOPF_ZEILE){
		fgets(buffer, BUFFERSIZE, datei);
		if (NULL != strstr(buffer, "-----")){
			stop = 1;
			i++;
		}
		else{
			i++;
		}
	}
	//maximalanzahl kopfzeilen ueberschritten?
	if (i >= 10){
		printf("Maximalazahl Kopfzeilen ueberschritten !\n");
		status = FALSE;
	}
	else{
		kopfzeilen = i;
		i = 0;
		stop = 0;
		//suchen nach ende des datensatz "</pre>"
		while ((stop != 1) && (i < MAX_DATA_SETS)){
			fgets(buffer, BUFFERSIZE, datei);
			if (NULL != strstr(buffer, "</pre>")){
				stop = 1;
			}
			else{
				i++;
			}
		}
		//maximalanzahl datensaetze ueberschritten?
		if (i >= MAX_DATA_SETS){
			status = FALSE;
		}
		else{
			//info speichern und datei auf anfang
			info->kopfzeilen = kopfzeilen;
			info->anzahl_datensaetze = i;
			rewind(datei);
			status = TRUE;
		}
	}
	return status;
}

/*
Funktion zum ueberpruefen ob der eingabeparameter in ordnung ist
*/
int check_input_parameter(char *parameter){
	BOOL status = TRUE;
	//leerer dateiname ?
	if (0 == strlen(parameter)){
		status = FALSE;
	}
	else{
		char suchstring[] = {
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz"
			"0123456789+-"
			"!\"'$%&'()*,./:;<=>?@[\\]^_`{|}~"
		};
		//nur leerzeichen ?
		if (NULL == strpbrk(parameter, suchstring)){
			status = FALSE;
		}
		else{
			status = TRUE;
		}
	}
	return status;
}

/*
Funktion zum konvertieren von int zu datum
*/
int jjjjmmdd_to_date(int jjjjmmdd, DATUM *date){
	char *monate[] = {
		"hier steht muell damit januar = 1 usw.",
		"Januar",
		"Februar",
		"Maerz",
		"April",
		"Mai",
		"Juni",
		"Juli",
		"August",
		"September",
		"Oktober",
		"November",
		"Dezember"
	};
	int status;
	int tag;
	int monat;
	int jahr;
	tag = jjjjmmdd % 100;
	jjjjmmdd = jjjjmmdd / 100;
	monat = jjjjmmdd % 100;
	jjjjmmdd = jjjjmmdd / 100;
	jahr = jjjjmmdd;
	//jahr groesser 2100 ?
	if (jahr > 2100 || jahr < 1800){
		status = FALSE;
		date->jahr = 1;
		strcpy(date->monat, monate[1]);
		date->tag = 1;
	}
	else{
		//monat groesser 12 ?
		if (monat < 0 || monat > 12){
			status = FALSE;
			date->jahr = 1;
			strcpy(date->monat, monate[1]);
			date->tag = 1;
		}
		else{
			//tag groesser 31 ?
			if (tag < 0 || tag>31){
				status = FALSE;
				date->jahr = 1;
				strcpy(date->monat, monate[1]);
				date->tag = 1;
			}
			else{
				//speichern
				status = TRUE;
				date->jahr = jahr;
				strcpy(date->monat, monate[monat]);
				date->tag = tag;
			}
		}
	}
	return status;
}

/*
Funktion zum verarbeuten eines rohdatenstring zu KLIMADATEN struct
*/
int parse_raw_data(char *string, KLIMADATEN *dest){
	int fiels_read = 0;
	fiels_read = sscanf(string, "%5i %8i %2i %6lf %6lf %6lf %6lf %6lf %6lf %6lf %6lf %6lf %6lf %6lf\n", &dest->stat, &dest->jjjjmmdd, &dest->qn, &dest->tg, &dest->tn, &dest->tm, &dest->tx, &dest->rfm, &dest->fm, &dest->fx, &dest->so, &dest->nm, &dest->rr, &dest->pm);
	return fiels_read;
}
