/* umrechner.c
Programm zur Umrechnung von Meile zu Kilometer und umgekehrt
Autor: 
Datum: 22. Nov. 2017
Kontakt: 
Compile: gcc umrechner.c -o umrechner
*/

#include <stdio.h>


int main(void) {
  float umrechnungskonstante = 1609.344;

  float meile = 0.0;
  float kilometer = 0.0;
  int rechenart = 0;


  printf("Rechner zur Umwandlung Kilometer <-> Meilen\n");
  printf("Bitte Rechenart wählen (1 = Km -> M ; 2 = M -> Km) : ");
  scanf("%i", & rechenart);


  if ((rechenart == 1) || (rechenart == 2)) {
    if (rechenart == 1) {
      /* km in meile*/
      printf("Bitte strecke in Kilometer eingeben : ");
      scanf("%f", & kilometer);
      if (kilometer > 0) {
        meile = kilometer * (1000/ umrechnungskonstante);
        printf("%f Kilometer sind %f Meilen\n", kilometer, meile);
      }else{
        printf("Ungültige Eingabe Wert muss > 0 sein\n");
      }
    }else{
      /*meile in km*/
      printf("Bitte strecke in Meilen eingeben : ");
      scanf("%f", & meile);
      if (meile > 0) {
        kilometer = (meile *  umrechnungskonstante)/1000 ;
        printf("%f Meilen sind %f Kilometer\n", meile, kilometer);
      } else {
        printf("Ungültige Eingabe Wert muss > 0 sein\n");
      }
    }
  } else {
    printf("Ungültige Rechenart ausgewählt! Bitte 1 oder 2 wählen\n");
  }
  return 0;
}
