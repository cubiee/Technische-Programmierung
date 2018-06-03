#ifndef KLIMADATENANALYSE_H
#define KLIMADATENANALYSE_H

#define TRUE 1
#define FALSE 0

#define input_name_to_long 100
#define forbidden_chars_in_filename 101

#define FORBIDDEN_CHARS " \\/"

#define MAX_NAMESIZE 11
#define MAX_KOPF_ZEILE 10
#define MAX_DATA_SETS 500
#define BUFFERSIZE 200
#define ARRAYSIZE 1000 

/*
Struktur zum speichern der eingelesenen daten aus der klimadatendatei
*/
typedef struct klimadaten_s{
	int stat;
	int jjjjmmdd;
	int qn;
	double tg;
	double tn;
	double tm;
	double tx;
	double rfm;
	double fm;
	double fx;
	double so;
	double nm;
	double rr;
	double pm;
} KLIMADATEN;

KLIMADATEN new_klimadaten(void);

/*
Struktur zum speichern des datums in temperatur
*/
typedef struct datum_s{
	int jahr;
	char monat[16];
	int tag;
}DATUM;

/*
Struktur zum speichern der verarbeiteten daten 
*/
typedef struct temperatur_s{
	int stat;
	DATUM datum;
	double tg;
	double tn;
	double tm;
	double tx;
} TEMPERATUR;

TEMPERATUR new_temperatur(void);

//Vorgegebene Funktionen
/*
Funktion zum einlesen der klimadaten aus einer datei
*/
int lese_Klimadaten(FILE* datei, KLIMADATEN k[], int anzahl_kopfzeilen, int max_anzahl, int* anzahl);

/*
Funktion zum verarbeiten der eingelesenen klimadaten
*/
void mache_temperatur(KLIMADATEN k[], TEMPERATUR t[], int anzahl);

/*
Funktion zum ausgeben der verabeiteten temperaturdaten
*/
void ausgabe_temperaturen(TEMPERATUR t[], int anzahl);

/*
Funktion zum finden des temperatur maximums
*/
TEMPERATUR findeMaxTemperatur(TEMPERATUR t[], int anzahl);

/*
Funktion zum ausgeben einzelner temperaturwerte
*/
void ausgabe_temperatur(TEMPERATUR t);

//Eigene Funktionen
/*
Funktion zum ueberpruefe des input parameter
*/
int check_input_parameter(char *parameter);


#endif