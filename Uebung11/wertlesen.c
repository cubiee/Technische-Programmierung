#include <stdio.h>
#include "wertlesen.h"


int wert_lesen(char *prompt, int min, int max, int *zahl){
    int nmbr;
    int status;
    if (min > max){
        int buffer = min;
        min = max;
        max = buffer;
    }
    if(min == max){
        status = 0;
    }
    else{
        printf(prompt);
        int pruefe;
        if(1 != (pruefe = scanf("%d", &nmbr))){
            status = 0;
        }else{
            *zahl = nmbr;
            status = 1;
        }
    }
    return status;
}