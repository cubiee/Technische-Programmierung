/* teiler.c
Programm zur Überprüfung ob Zahl A glatt durch Zahl B teilbar ist
Autor: Joshua Harig
Datum: 22. Nov. 2017
Kontakt: ms.joshua.harig@htwsaar.de
Compile: gcc teiler.c -o teiler
*/


#include <stdio.h>

int main(void) {

  int zahl_A = 0;
  int zahl_B = 0;

  printf("Programm zur Überprüfung ob Zahl A glatt durch Zahl B teilbar ist\n");
  printf("Zahl A eingeben : ");
  scanf("%i", & zahl_A);
  printf("Zahl B eingeben : ");
  scanf("%i", & zahl_B);

  if (zahl_B != 0) {
    if (zahl_A % zahl_B == 0) {
      printf("%i ist durch %i glatt teilbar\n", zahl_A, zahl_B);
    } else {
      printf("%i ist durch %i nicht glatt teilbar\n", zahl_A, zahl_B);
    }
  } else {
    printf("Zahl B darf nicht 0 sein !\n");
  }
  return 0;
}
