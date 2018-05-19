#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEILNEHMERANZAHL 100
#define BUFFERSIZE 100

#define FORBIDDENCHARS "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz" "!\"'$%&'()*-+,./:;<=>?@[\\]^_`{|}~"

#define TRUE 1
#define FALSE 0

//Struct definition + Konstruktorfunktion
typedef struct teilnehmer_s{
    char name[BUFFERSIZE];
    char firma[BUFFERSIZE];
    int teilnahmebeitrag;
} TEILNEHMER;

TEILNEHMER new_teilnehmer(void);

//Helferfunktionen
void menue(void);

//Arbeiterfunktionen
TEILNEHMER *generate_dataset(void);
int speichern(char *dateiname, TEILNEHMER *datensatz, int anzahl);
TEILNEHMER einlesen(void);

int main(int argc, char *argv[]){
    if(2 != argc){
        menue();
    }
    else{
        TEILNEHMER *datensatz = generate_dataset();
        for(int i = 0; i < 2; i++){
            datensatz[i] = einlesen();
        }
		speichern("save.dat", datensatz, TEILNEHMERANZAHL);
    }
    return 0;
}

//Struct konstruktor
TEILNEHMER new_teilnehmer(void){
    TEILNEHMER new_teilnehmer;
    memset(new_teilnehmer.name, '\0', BUFFERSIZE);
    memset(new_teilnehmer.firma, '\0', BUFFERSIZE);
    new_teilnehmer.teilnahmebeitrag = 0;
    return new_teilnehmer;
}

//menue ausgeben
void menue(void){
    printf("Aufruf durch:\n");
    printf("\t./teilnehmer <ausgabedatei>\n");
    return;
}

//datensatz erstellen
TEILNEHMER *generate_dataset(void){
    TEILNEHMER *dataset = malloc(TEILNEHMERANZAHL * sizeof(TEILNEHMER));
    for(int i = 0; i < TEILNEHMERANZAHL; i++){
        dataset[i] = new_teilnehmer();
    }
    return dataset;
}

//datensatz speichern
int speichern(char *dateiname, TEILNEHMER *datensatz, int anzahl){
	int status;
	FILE *datei;
	if (NULL == (datei = fopen(dateiname, "w"))){
		printf("Speichern Fehlgeschlagen\n");
		status = FALSE;
	}
	else{
		for (int i = 0; i < anzahl; i++){
			fprintf(datei, "Name: %s ; Firma: %s ; Betrag: %d\n", datensatz[i].name, datensatz[i].firma, datensatz[i].teilnahmebeitrag);
		}
		status = TRUE;
	}
	return status;
}

//teilnehmerdaten einlesen
TEILNEHMER einlesen(void){
	char buffer[BUFFERSIZE];
	TEILNEHMER teilnehmer = new_teilnehmer();
	printf("Bitte Name eingeben: ");
	memset(buffer, '\0', BUFFERSIZE);
	fgets(buffer, BUFFERSIZE, stdin);
	strtok(buffer, "\n");
	strcpy(teilnehmer.name, buffer);

	printf("Bitte Firma eingeben: ");
	memset(buffer, '\0', BUFFERSIZE);
	fgets(buffer, BUFFERSIZE, stdin);
	strtok(buffer, "\n");
	strcpy(teilnehmer.firma, buffer);

	printf("Bitte Teilnahmebeitrag eingeben: ");
	memset(buffer, '\0', BUFFERSIZE);
	fgets(buffer, BUFFERSIZE, stdin);
	strtok(buffer, "\n");
	while ((NULL != strpbrk(buffer, FORBIDDENCHARS)) || (0 == atoi(buffer))){
		printf("Ungueltiger Eingabewert (keine zahl oder zahl <= 0)\n");
		printf("Bitte Teilnahmebeitrag eingeben: ");
		memset(buffer, '\0', BUFFERSIZE);
		fgets(buffer, BUFFERSIZE, stdin);
		strtok(buffer, "\n");
	}
	teilnehmer.teilnahmebeitrag = atoi(buffer);
	return teilnehmer;
}

