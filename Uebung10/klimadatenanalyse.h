#ifndef KLIMADATENANALYSE_H
#define KLIMADATENANALYSE_H

typedef struct klimadaten_s{
	int stat;
	int jjjjmmdd;
	int qn;
	float tg;
	float tn;
	float tm;
	float tx;
	float rfm;
	float fm;
	float fx;
	float so;
	float nm;
	float rr;
	float pm;
} KLIMADATEN;

typedef struct temperatur_s{
	int stat;
	int jahr;
	char monat[16];
	int tag;
	double tg;
	double tn;
	double tm;
	double tx;
} TEMPERATUR;

int lese_Klimadaten(FILE* datei, KLIMADATEN k[], int anzahl_kopfzeilen, int max_anzahl, int* anzahl);

void mache_temperatur(KLIMADATEN k[], TEMPERATUR t[], int anzahl);

void ausgabe_temperaturen(TEMPERATUR t[], int anzahl);

TEMPERATUR findeMaxTemperatur(TEMPERATUR t[], int anzahl);

void ausgabe_temperatur(TEMPERATUR t);
#endif