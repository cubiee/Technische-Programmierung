#ifndef DATEN_VERARBEITEN_H
#define DATEN_VERARBEITEN_H

int check_data_file(FILE *datei, FILEINFORMATION *info);

int check_input_parameter(char *parameter);

int jjjjmmdd_to_date(int jjjjmmdd, DATUM *date);

int parse_raw_data(char *string, KLIMADATEN *dest);

#endif