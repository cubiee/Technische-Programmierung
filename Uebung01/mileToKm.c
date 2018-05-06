/* mileToKm.c
Programm zur Umrechnung von Meile zu Kilometer
Autor: Joshua Harig
Datum: 22. Nov. 2017
Kontakt: ms.joshua.harig@htwsaar.de
Compile: gcc mileToKm.c -o mileToKm
*/

#include <stdio.h>


int main(void) {
  float umrechnungskonstante = 1609.344;

  float meile = 0.0;
  float kilometer = 0.0;

  printf("Einheitenrechner Meile -> Kilometer:\n");
  printf("Bitte strecke in Meilen eingeben : ");
  scanf("%f", & meile);
  if (meile > 0) {
    kilometer = (meile * umrechnungskonstante)/ 1000 ;
    printf("%f Meilen sind %f Kilometer\n", meile, kilometer);
  } else {
    printf("Ungültige Eingabe Wert muss > 0 sein\n");
  }

  return 0;
}
