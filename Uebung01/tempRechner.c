/* tempRechner.c
 Programm zur Berechnung von Fahrenheit in Celsius und umgekehrt
 Autor: 
 Datum: 20. Nov. 2017
 Kontakt: 
 Compile: gcc tempRechner.c -o tempRechner
*/

#include "stdio.h"

int main(void) {
  float celsius = 0.0;
  float Fahrenheit = 0.0;
  int rechenweg = 0;

  printf("Umrechnung Fahrenheit <-> Celsius\n");
  printf("Bitte Rechenweg angeben (1 = F -> C , 2 = C -> F): ");
  scanf("%i", & rechenweg);
  switch (rechenweg) {
    case 1: printf("Bitte Temperatur in Fahrenheit eingeben: ");
            scanf("%f", & Fahrenheit);
            printf("%f Fahrenheit sind %f Celsius\n", Fahrenheit, (5.0/9.0)*(Fahrenheit - 32.0));
            break;
    case 2: printf("Bitte Temperatur in Celsius eingeben: ");
            scanf("%f", & celsius);
            printf("%f Celsius sind %f Fahrenheit\n", celsius, celsius*(9.0/5.0) + 32.0);
            break;
    default: printf("Ungültige Rechenart ausgewählt! Bitte 1 oder 2 wählen\n");
  }
  return 0;
}
