#ifdef KLIMADATENANALYSE_H
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
}KLIMADATEN;

int leseKlimadaten(FILE* datei, KLIMADATEN k[], int anzahl_kopfzeilen, int max_anzahl, int* anzahl);


#endif