#ifndef PARSING_DATA_H
#define PARSING_DATA_H

typedef struct fileinformation_s{
	int kopfzeilen;
	int anzahl_datensaetze;
}FILEINFORMATION;

int check_data_file(FILE *datei, FILEINFORMATION *info);

int jjjjmmdd_to_date(int jjjjmmdd, DATUM *date);

int parse_raw_data(char *string, KLIMADATEN *dest);

#endif 
