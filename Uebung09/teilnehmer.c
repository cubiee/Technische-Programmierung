#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEILNEHMERANZAHL 100
#define BUFFERSIZE 100

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
int get_user_int(char *prompt, int min, int max, int *number);
int get_user_string(char *prompt, char *string);

//Arbeiterfunktionen
TEILNEHMER *generate_dataset(void);
TEILNEHMER einlesen(void);
int speichern(char *dateiname, TEILNEHMER *datensatz, int anzahl);

int main(int argc, char *argv[]){
	if (2 != argc){
		menue();
	}
	else{
		TEILNEHMER *datensatz = generate_dataset();
        if(NULL == datensatz){
            printf("Abbruch!\n");
            return 0;
        }
        else{
            int stop = 1;
            int n = 0;
            while ((stop != 0) && (n < TEILNEHMERANZAHL)){
                printf("Neuer Teilnehmer:\n");
                datensatz[n] = einlesen();
                n++;
                while (get_user_int("Weiter ?(1 = Ja ; 0 = Nein): ", 0, 1, &stop) == FALSE){
                    printf("Ungueltige eingabe!\n");
                }
                if (n == TEILNEHMERANZAHL){
                    printf("Maximale teilnehmeranzahl erreicht!\n");
                }
            }
            if (FALSE == speichern(argv[1], datensatz, n)){
                printf("Speichern fehlgeschlagen!\n");
            }
            free(datensatz);
        }
		
	}
	return 0;
}

/*
Struct mit default werten erstellen
*/
TEILNEHMER new_teilnehmer(void){
    TEILNEHMER new_teilnehmer;
    memset(new_teilnehmer.name, '\0', BUFFERSIZE);
    memset(new_teilnehmer.firma, '\0', BUFFERSIZE);
    new_teilnehmer.teilnahmebeitrag = 0;
    return new_teilnehmer;
}

/*
//menue ausgeben
*/
void menue(void){
    printf("Aufruf durch:\n");
    printf("\t./teilnehmer <ausgabedatei>\n");
    return;
}

/*
integer von benutzer auslesen
*/
int get_user_int(char *prompt, int min, int max, int *number){
	//min und max vertauschen fals min > max
	if (max < min){
		int c = max;
		max = min;
		min = c;
	}
	//puffer und variablen anlegen 
	int status;
	char buffer[BUFFERSIZE] = { '\0' };
	int zahl = 0;
	char suchstring[] = {
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"!\"'$%&'()*+,./:;<=>?@[\\]^_`{|}~ "
	};
	//einlesen und verarbeiten
	printf(prompt);
	fgets(buffer, BUFFERSIZE, stdin);
	strtok(buffer, "\n");
	if (NULL != strpbrk(buffer, suchstring)){
		//eingabe keine zahl
		status = FALSE;
	}
	else{
		zahl = atoi(buffer);
		if ((zahl < min) || (zahl > max)){
			//ausserhalb der grenzen
			status = FALSE;
		}
		else{
			*number = zahl;
			status = TRUE;
		}
	}
	return status;
}

/*
String von benutzer in puffer einlesen
*/
int get_user_string(char *prompt, char *string){
    char buffer[BUFFERSIZE] = {'\0'};
    //einlesen
    printf(prompt);
    fgets(buffer, BUFFERSIZE, stdin);
    //verarbeiten
    strtok(buffer, "\n");
    char suchstring[] = {
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "!\"'$%&'()*+,./:;<=>?@[\\]^_`{|}~"
    };
    if (NULL == strpbrk(buffer, suchstring)){
        //string besteht nur aus lehrzeichen oder ist nicht vorhanden
        return FALSE;
    }
    else{
        strcpy(string, buffer);
        return TRUE;
    }
}


/*
datensatz erstellen
*/
TEILNEHMER *generate_dataset(void){
    TEILNEHMER *dataset;
    if(NULL == (dataset = malloc(TEILNEHMERANZAHL * sizeof(TEILNEHMER)))){
        return NULL;
    }else{
        for(int i = 0; i < TEILNEHMERANZAHL; i++){
            dataset[i] = new_teilnehmer();
        }
        return dataset;
    }
}

/*
teilnehmerdaten einlesen
*/
TEILNEHMER einlesen(void){
	char buffer[BUFFERSIZE];
	int beitrag = 0;
	TEILNEHMER teilnehmer = new_teilnehmer();

	//Name
    while (FALSE == get_user_string("Bitte Name eingeben: ", buffer)){
        printf("Ungueltige eingabe!\n");
    }
    strcpy(teilnehmer.name, buffer);
    
	//Firma
    while (FALSE == get_user_string("Bitte Firma eingeben: ", buffer)){
        printf("Ungueltige eingabe!\n");
    }
	strcpy(teilnehmer.firma, buffer);

	//Teilnahmebeitrag
	while (FALSE == get_user_int("Bitte Teilnahmebeitrag eingeben: ", 1, 99999999, &beitrag)){
		printf("Ungueltige eingabe!\n");
	}
	teilnehmer.teilnahmebeitrag = beitrag;

	return teilnehmer;
}

/*
datensatz speichern
*/
int speichern(char *dateiname, TEILNEHMER *datensatz, int anzahl){
	int status;
	FILE *datei;
	//pruefen ob datei bereits vorhanden
	if (NULL != (datei = fopen(dateiname, "r"))){
		fclose(datei);
		//alte datei umbenennen <alter name> + _renamed_
		char buffer[BUFFERSIZE + 9] = { '\0' };
		strcat(buffer, dateiname);
		strcat(buffer, "_renamed_");
		rename(dateiname, buffer);
	}
	//datei neu anlegen
	if (NULL == (datei = fopen(dateiname, "w"))){
		status = FALSE;
	}
	else{
		for (int i = 0; i < anzahl; i++){
			fprintf(datei, "%s - %s - %d EUR\n", datensatz[i].name, datensatz[i].firma, datensatz[i].teilnahmebeitrag);
		}
		fprintf(datei, "ENDE LISTE\n");
		fclose(datei);
		status = TRUE;
	}
	return status;
}
