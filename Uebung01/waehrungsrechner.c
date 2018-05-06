/* waehrungsrechner.c
 Programm zur Berechnung von Dollar in Euro anhand eines eingegebenen Wechselkurses
 Autor: Joshua Harig Mat.Nr.: 3666212
 Datum: 20. Nov. 2017
 Kontakt: ms.joshua.harig@htwsaar.de
 Compile: gcc waehrungsrechner.c -o waehrungsrechner
*/


#include "stdio.h"

int main(void) {
  float euro = 0.0;
  float dollar = 0.0;
  float wechselkurs = 0.0;

  printf("Währungsrechner\n");
  printf("Bitte aktuellen Wechselkurs USD->EUR eingeben: ");
  scanf("%f", & wechselkurs);
  printf("Bitte Betrag in USD eingeben: ");
  scanf("%f", & dollar);

  if ((wechselkurs > 0) && (dollar > 0)) {
    euro = dollar * wechselkurs;
    printf("%f Dollar sind %f Euro\n", dollar, euro);
  }else{
    printf("Nur Werte groesser 0 eingeben!\n");
  }
  return 0;
}
