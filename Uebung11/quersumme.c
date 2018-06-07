#include "quersumme.h"

int quersumme(int zahl){
    int summe = 0;
    if(zahl < 0){
        return -1;
    }
    else{
        while(zahl >= 10){
            summe = summe + (zahl % 10);
            zahl /= 10;
        }
        summe = summe + zahl;
        return summe;
    }
}