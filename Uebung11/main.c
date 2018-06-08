#include <stdio.h>
#include <menue.h>
#include <pythagoras.h>
#include <quersumme.h>
#include <teilbar.h>
#include <wertlesen.h>

#define ZAHL 10
#define TEILER 5 

int main(void){
    printf("TEST\n");
    int wert = 0;

    if(0 == wert_lesen("Bitte Integer eingeben: ", 0, 100, &wert)){
        printf("fehler kein integer!\n");
    }
    else{
        printf("Nummer: %i\n", wert);
    }

    if(0 == teilbar( ZAHL, TEILER)){
        printf("%i ist nicht durch %i teilbar!\n", ZAHL, TEILER);
    }
    else{
        printf("%i / %i = %i \n", ZAHL, TEILER, ZAHL / TEILER);
    }

	pythagoras(30);

    printf("Quersumme 12345 %d\n",quersumme(12345));
    return 0;
}