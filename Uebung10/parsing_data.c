#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "klimadatenanalyse.h"
#include "parsing_data.h"

int check_data_file(FILE *datei, FILEINFORMATION *info){
	int i = 0;
	int stop = 0;
	char buffer[BUFFERSIZE] = { '\0' };
	int kopfzeilen = 0;
	while (stop != 1 && i < MAX_KOPF_ZEILE){
		fgets(buffer, 1000, datei);
		if (0 == strcmp(buffer, "----- -------- -- ------ ------ ------ ------ ------ ------ ------ ------ ------ ------ ------\n")){
			stop = 1;
			i++;
		}
		else{
			i++;
		}
	}
	if (i >= 10){
		//Formatfehler
		return FALSE;
	}
	else{
		kopfzeilen = i;
		i = 0;
		stop = 0;
		while (stop != 1 && i < MAX_DATA_SETS){
			fgets(buffer, 1000, datei);
			if (0 == strcmp(buffer, "</pre>\n")){
				stop = 1;
			}
			else{
				i++;
			}
		}
		if (i >= 1000){
			//Formatfehler
			return FALSE;
		}
		else{
			info->kopfzeilen = kopfzeilen;
			info->anzahl_datensaetze = i;
			return TRUE;
		}
	}
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
	fiels_read = sscanf(string, "%i %i %i %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf %lf\n", &dest->stat, &dest->jjjjmmdd, &dest->qn, &dest->tg, &dest->tn, &dest->tm, &dest->tx, &dest->rfm, &dest->fm, &dest->fx, &dest->so, &dest->nm, &dest->rr, &dest->pm);
	return fiels_read;
}
