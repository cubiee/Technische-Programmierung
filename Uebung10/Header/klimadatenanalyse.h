#ifndef KLIMADATENANALYSE_H
#define KLIMADATENANALYSE_H

//Vorgegebene Funktionen
/*
Funktion zum einlesen der klimadaten aus einer datei
*/
int lese_Klimadaten(FILE* datei, KLIMADATEN *k, int anzahl_kopfzeilen, int max_anzahl, int* anzahl);

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

#endif