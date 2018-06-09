#include <stdio.h>
#include <bool.h>
#include <wertlesen.h>



int wert_lesen(char *prompt, int min, int max, int *zahl){
    int nmbr;
    int status;
    if (min > max){
        int buffer = min;
        min = max;
        max = buffer;
    }
    if(min == max){
        status = FALSE;
    }
    else{
        printf(prompt);
        int pruefe;
        if(1 != (pruefe = scanf("%d", &nmbr))){
            status = FALSE;
        }else{
            *zahl = nmbr;
            status = TRUE;
        }
    }
    return status;
}