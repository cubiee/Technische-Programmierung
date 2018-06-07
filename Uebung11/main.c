#include <stdio.h>
#include "pythagoras.h"
#include "quersumme.h"
#include "teilbar.h"
#include "wertlesen.h"



int main(void){
    printf("TEST\n");
    int wert = 0;
    if(0 == wert_lesen("Bitte Integer eingeben: ", 0, 100, &wert)){
        printf("fehler!\n");
    }else{
        printf("Nummer: %i\n", wert);
    }
    return 0;
}