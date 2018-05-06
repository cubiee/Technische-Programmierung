/* kmToMile.c
Programm zur Umrechnung von Kilometer zu Meile
Autor: Joshua Harig
Datum: 22. Nov. 2017
Kontakt: ms.joshua.harig@htwsaar.de
Compile: gcc kmToMile.c -o kmToMile
*/

#include <stdio.h>


int main(void) {
  float umrechnungskonstante = 1609.344;

  float meile = 0.0;
  float kilometer = 0.0;

  printf("Einheitenrechner Kilometer -> Meile:\n");
  printf("Bitte strecke in Kilometer eingeben : ");
  scanf("%f", & kilometer);
  if (kilometer > 0) {
    meile = kilometer * (1000/ umrechnungskonstante);
    printf("%f Kilometer sind %f Meilen\n", kilometer, meile);
  } else {
    printf("Ungültige Eingabe Wert muss > 0 sein\n");
  }

  return 0;
}
