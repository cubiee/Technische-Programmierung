#ifndef KLIMA_DEFINES_H
#define KLIMA_DEFINES_H

#define MAX_KOPF_ZEILE 10
#define MAX_DATA_SETS 1000

#define BUFFERSIZE 200


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

void setze_werte_0(KLIMADATEN *k);

/*
Struktur zum speichern des datums in temperatur
*/
typedef struct datum_s{
	int jahr;
	char monat[16];
	int tag;
}DATUM;

DATUM new_datum(void);

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

/*
Structur zum speichern von Datei Informationen
*/
typedef struct fileinformation_s{
	int kopfzeilen;
	int anzahl_datensaetze;
} FILEINFORMATION;

FILEINFORMATION new_fileinformation(void);

#endif