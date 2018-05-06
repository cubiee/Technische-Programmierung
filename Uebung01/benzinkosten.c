/* benzinkosten.c
Programm zur berechnung von Benzinkosten bei gegebener Strecke, Kraftstoffpreis und verbrauchtem Benzin
Autor: Joshua Harig
Datum: 22. Nov. 2017
Kontakt: ms.joshua.harig@htwsaar.de
Compile: gcc benzinkosten.c -o benzinkosten
*/


#include <stdio.h>

int main() {
  float gefahrene_strecke = 0.0;
  float verbrauchtes_benzin = 0.0;
  float kosten_pro_liter = 0.0;

  float verbrauch_pro_100km = 0.0;
  float kosten_pro_100km = 0.0;

  printf("Benzinkostenrechner:\n");
  printf("Bitte gefahrene Strecke eingeben (in km): ");
  scanf("%f", &gefahrene_strecke);
  printf("Bitte verbrauchtes Benzin eingeben (in Liter): ");
  scanf("%f", &verbrauchtes_benzin);
  printf("Bitte Preis pro Liter Benzin eingeben (in Euro/Liter): ");
  scanf("%f", &kosten_pro_liter);


  if ((gefahrene_strecke > 0) && (verbrauchtes_benzin > 0) && (kosten_pro_liter > 0)) {
    verbrauch_pro_100km = (verbrauchtes_benzin * 100)/gefahrene_strecke;
    kosten_pro_100km = verbrauch_pro_100km * kosten_pro_liter;
    printf("Verbrauch auf 100 km sind : %.3f Liter\n", verbrauch_pro_100km);
    printf("Kosten pro 100 km sind : %.2f Euro\n", kosten_pro_100km);
  }else{
    printf("Ungültige Eingabe Werte müssen > 0 sein\n");
  }

  return 0;
}
