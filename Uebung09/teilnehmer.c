#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEILNEHMERANZAHL 100
#define BUFFERSIZE 40

#define TRUE 1
#define FALSE 0

//Struct definition + Konstruktorfunktion
typedef struct teilnehmer_s{
    char name[BUFFERSIZE];
    char firma[BUFFERSIZE];
    float teilnahmebeitrag;
} TEILNEHMER;

TEILNEHMER new_teilnehmer(void);

//Helferfunktionen
void menue(void);
void flush(void);

//Arbeiterfunktionen
TEILNEHMER *generate_dataset(void);
int einlesen(TEILNEHMER *teilnehmer);

int main(int argc, char *argv[]){
    if(2 != argc){
        menue();
    }
    else{
        TEILNEHMER *datensatz = generate_dataset();
        for(int i = 0; i < 2; i++){
            einlesen(&(datensatz[i]));
        }
    }
    return 0;
}

//Struct konstruktor
TEILNEHMER new_teilnehmer(void){
    TEILNEHMER new_teilnehmer;
    memset(new_teilnehmer.name, '\0', BUFFERSIZE);
    memset(new_teilnehmer.firma, '\0', BUFFERSIZE);
    new_teilnehmer.teilnahmebeitrag = 0.0f;
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

//teilnehmerdaten einlesen
int einlesen(TEILNEHMER *teilnehmer){
    int status;
    char buffer[10 * BUFFERSIZE];
    printf("Name: ");
    gets(buffer);
    strncpy(teilnehmer->name, strtok(buffer, "\n"), BUFFERSIZE);
    memset(buffer, '\0', BUFFERSIZE);
    flush();
    printf("Firma: ");
    gets(buffer);
    strncpy(teilnehmer->firma, strtok(buffer, "\n"), BUFFERSIZE);
    memset(buffer, '\0', BUFFERSIZE);
    flush();
    return TRUE;
}

//inputbuffer leeren
void flush(void){
    char char_buff = 0;
    while ((char_buff = getchar()) != '\n' && char_buff != EOF) { }
}