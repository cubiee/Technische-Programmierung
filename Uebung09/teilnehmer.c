#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TEILNEHMERANZAHL 100
#define BUFFERSIZE 41

//Struct definition + Konstruktorfunktion
typedef struct teilnehmer_s{
    char name[BUFFERSIZE];
    char firma[BUFFERSIZE];
    float teilnahmebeitrag;
} TEILNEHMER;

TEILNEHMER new_teilnehmer(void);

//Helferfunktionen
void menue(void);

//Arbeiterfunktionen
TEILNEHMER *generate_dataset(void);

int main(int argc, char *argv[]){
    if(2 != argc){
        menue();
    }
    else{
        TEILNEHMER *datensatz = generate_dataset();
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