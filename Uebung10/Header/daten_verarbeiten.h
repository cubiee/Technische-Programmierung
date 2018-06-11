#ifndef DATEN_VERARBEITEN_H
#define DATEN_VERARBEITEN_H

/*
Funktion zum herausfinden wieviele kopfzeilen und datensaetze vorhanden sind
*/
int check_data_file(FILE *datei, FILEINFORMATION *info);

/*
Funktion zum ueberpruefen ob der eingabeparameter in ordnung ist
*/
int check_input_parameter(char *parameter);

/*
Funktion zum konvertieren von int zu datum
*/
int jjjjmmdd_to_date(int jjjjmmdd, DATUM *date);

/*
Funktion zum verarbeuten eines rohdatenstring zu KLIMADATEN struct
*/
int parse_raw_data(char *string, KLIMADATEN *dest);

#endif