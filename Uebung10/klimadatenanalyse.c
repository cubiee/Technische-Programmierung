#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "klimadatenanalyse.h"
#include "parsing_data.h"

KLIMADATEN new_klimadaten(void){
	KLIMADATEN neu;
	neu.stat = 0;
	neu.jjjjmmdd = 0;
	neu.qn = 0;
	neu.tg = 0.0;
	neu.tn = 0.0;
	neu.tm = 0.0;
	neu.tx = 0.0;
	neu.rfm = 0.0;
	neu.fm = 0.0;
	neu.fx = 0.0;
	neu.so = 0.0;
	neu.nm = 0.0;
	neu.rr = 0.0;
	neu.pm = 0.0;
	return neu;
}

TEMPERATUR new_temperatur(void){
	TEMPERATUR neu;
	neu.stat = 0;
	neu.datum.jahr = 0;
	memset(neu.datum.monat, '\0', 16);
	neu.datum.tag = 0;
	neu.tg = 0.0;
	neu.tn = 0.0;
	neu.tm = 0.0;
	neu.tx = 0.0;
	return neu;
}

int lese_Klimadaten(FILE* datei, KLIMADATEN k[], int anzahl_kopfzeilen, int max_anzahl, int *anzahl){
	//hier sollen die klimadaten eingelesen werden
	char buffer[BUFFERSIZE] = { '\0' };
	int fehler_flag = 0;
	int i = 0;

	for (i = 0; i < anzahl_kopfzeilen; i++){
		fgets(buffer, BUFFERSIZE, datei);
	}

	i = 0;
	while ((i < max_anzahl) && (fehler_flag == 0)){
		fgets(buffer, BUFFERSIZE, datei);
		if (0 == strcmp(buffer, "</pre>\n")){
			//ende der datei
			*anzahl = i;
			fehler_flag = 0;
		}
		else{
			if (14 != parse_raw_data(buffer, &(k[i]))){
				fehler_flag = 1;
				printf("%d\n", i);
			}
			else{
				i++;
			}
		}
	}
	return fehler_flag;
}

void mache_temperatur(KLIMADATEN k[], TEMPERATUR t[], int anzahl){
	//hier werden die klimadaten ausgewertet und in einem struct gespeichert
	for (int i = 0; i < anzahl; i++){
		jjjjmmdd_to_date(k[i].jjjjmmdd, &(t[i].datum));
		t[i].stat = k[i].stat;
		t[i].tg= k[i].tg;
		t[i].tn = k[i].tn;
		t[i].tm = k[i].tm;
		t[i].tx = k[i].tx;
	}
	return;
}

void ausgabe_temperaturen(TEMPERATUR t[], int anzahl){
	//hier werden die temperaturen ausgegeben;
	printf("1\n");
	for (int i = 0; i < anzahl; i++){
		printf("Temperaturen am %2i. %9s %4i: TG %7.2lf / TN %7.2lf / TM %7.2lf / TX %7.2lf\n", t[i].datum.tag, t[i].datum.monat, t[i].datum.jahr, t[i].tg, t[i].tn, t[i].tm, t[i].tx);
	}
	return;
}

int compare_temperature(const void *t1, const void *t2){
	const TEMPERATUR *temp1 = t1;
	const TEMPERATUR *temp2 = t2;

	if (temp1->tx < temp1->tx){
		return -1;
	}
	else if (temp1->tx > temp2->tx){
		return 1;
	}
	else{
		return 0;
	}
}

TEMPERATUR findeMaxTemperatur(TEMPERATUR t[], int anzahl){
	//hier soll die maximaltemperatur gesucht werden
	TEMPERATUR sorted[ARRAYSIZE];
	for (int i = 0; i < ARRAYSIZE; i++){
		sorted[i] = t[i];
	}
	qsort(sorted, anzahl, sizeof(TEMPERATUR), compare_temperature);
	return sorted[anzahl-1];
}

void ausgabe_temperatur(TEMPERATUR t){
	//hier wird eine temperatur ausgegeben
	printf("Temperaturen am %2i. %9s %4i: TG %7.2lf / TN %7.2lf / TM %7.2lf / TX %7.2lf\n", t.datum.tag, t.datum.monat, t.datum.jahr, t.tg, t.tn, t.tm, t.tx);
	return;
}


int check_input_parameter(char *parameter){
	int status = 0;
	char file_name[MAX_NAMESIZE] = { '\0' };
	int length = strlen(parameter);

	if (length > MAX_NAMESIZE - 1){
		status = input_name_to_long;
	}
	else{
		strcpy(file_name, parameter);
		if (NULL != strpbrk(file_name, FORBIDDEN_CHARS)){
			status = forbidden_chars_in_filename;
		}
		else{
			printf("%s\n", file_name);
			status = 0;
		}
	}
	return status;
}

