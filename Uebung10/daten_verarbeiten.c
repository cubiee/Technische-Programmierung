#include <stdio.h>
#include <string.h>

#include <klima_defines.h>
#include <daten_verarbeiten.h>
#include <bool.h>

int check_data_file(FILE *datei, FILEINFORMATION *info){
	int i = 0;
	int stop = 0;
	char buffer[BUFFERSIZE] = { '\0' };
	int kopfzeilen = 0;
	BOOL status = TRUE;
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
	if (i >= 10){
		//Formatfehler
		printf("Maximalazahl Kopfzeilen ueberschritten !\n");
		status = FALSE;
	}
	else{
		kopfzeilen = i;
		i = 0;
		stop = 0;
		while ((stop != 1) && (i < MAX_DATA_SETS)){
			fgets(buffer, BUFFERSIZE, datei);
			if (NULL != strstr(buffer, "</pre>")){
				stop = 1;
			}
			else{
				i++;
			}
		}
		if (i >= MAX_DATA_SETS){
			//Formatfehler
			status = FALSE;
		}
		else{
			info->kopfzeilen = kopfzeilen;
			info->anzahl_datensaetze = i;
			rewind(datei);
			status = TRUE;
		}
	}
	return status;
}

int check_input_parameter(char *parameter){
	BOOL status = TRUE;
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
		if (NULL == strpbrk(parameter, suchstring)){
			status = FALSE;
		}
		else{
			status = TRUE;
		}
	}
	return status;
}

int jjjjmmdd_to_date(int jjjjmmdd, DATUM *date){
	char *monate[] = {
		" ",
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
	if (jahr > 2100 || jahr < 1800){
		status = FALSE;
		date->jahr = 1;
		strcpy(date->monat, monate[1]);
		date->tag = 1;
	}
	else{
		if (monat < 0 || monat > 12){
			status = FALSE;
			date->jahr = 1;
			strcpy(date->monat, monate[1]);
			date->tag = 1;
		}
		else{
			if (tag < 0 || tag>31){
				status = FALSE;
				date->jahr = 1;
				strcpy(date->monat, monate[1]);
				date->tag = 1;
			}
			else{
				status = TRUE;
				date->jahr = jahr;
				strcpy(date->monat, monate[monat]);
				date->tag = tag;
			}
		}
	}
	return status;
}

int parse_raw_data(char *string, KLIMADATEN *dest){
	int fiels_read = 0;
	fiels_read = sscanf(string, "%5i %8i %2i %6lf %6lf %6lf %6lf %6lf %6lf %6lf %6lf %6lf %6lf %6lf\n", &dest->stat, &dest->jjjjmmdd, &dest->qn, &dest->tg, &dest->tn, &dest->tm, &dest->tx, &dest->rfm, &dest->fm, &dest->fx, &dest->so, &dest->nm, &dest->rr, &dest->pm);
	return fiels_read;
}
