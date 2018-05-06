/*teilnehmer.c
<PROGRAMMBESCHREIBUNG>
Datum: May  3 2018
Autor: <NAME> <VORNAME>
Mat.Nr.: <MATRIKELNUMMER>
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TRUE 1
#define FALSE 0
#define BUFFERSIZE 40
#define MAXTEILNEHMER 100

typedef struct teilnehmer_s{
	char name[BUFFERSIZE];
	char firma[BUFFERSIZE];
	float teilnahmebeitrag;
} TEILNEHMER;

TEILNEHMER new_teilnehmer(void);
TEILNEHMER *generate_data_set(int teilnehmeranzahl);
TEILNEHMER einlesen(void);

int save_data(TEILNEHMER *dataset, int teilnehmeranzahl, char *speicherort);

int main(void){
	TEILNEHMER *data = generate_data_set(MAXTEILNEHMER);

	for(int i = 0; i < 5; i++){
		data[i] = einlesen();
	}

	if(save_data(data, MAXTEILNEHMER, "save.dat") == FALSE){
		printf("Speichern des Datensatz fehlgeschlagen!\n");
	}
	return 0;
}

TEILNEHMER new_teilnehmer(void){
	TEILNEHMER new;
	strcpy(new.name, "");
	strcpy(new.firma, "");
	new.teilnahmebeitrag = 0.0f;
	return new;
}

TEILNEHMER *generate_data_set(int teilnehmeranzahl){
	TEILNEHMER *dataset = malloc(teilnehmeranzahl * sizeof(TEILNEHMER));
	for (int i = 0; i < teilnehmeranzahl; i++){
		dataset[i] = new_teilnehmer();
	}
	return dataset;
}

TEILNEHMER einlesen(void){
	TEILNEHMER neuer_teilnehmer = new_teilnehmer();
	printf("Name: ");
	fgets(neuer_teilnehmer.name, BUFFERSIZE, stdin);
	printf("Firma: ");
	fgets(neuer_teilnehmer.firma, BUFFERSIZE, stdin);
	return neuer_teilnehmer;
}

int save_data(TEILNEHMER *dataset, int teilnehmeranzahl, char *speicherort){
	FILE *save_file;
	int status = TRUE;
	if(NULL == (save_file = fopen(speicherort, "w"))){
		status = FALSE;
		printf("Speicherdatei konnte nicht geöffnet werden!\n");
	}
	else{
		for(int i = 0; i < teilnehmeranzahl; i++){
			fprintf(save_file,"Name: %s\tFirma: %s\tBeitrag: %.2f\n",dataset[i].name, dataset[i].firma, dataset[i].teilnahmebeitrag);
		}
		fclose(save_file);
	}
	return status;
}
