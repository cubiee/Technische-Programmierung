/* waehrungsrechner.c
 Programm zur Berechnung von Dollar in Euro anhand eines eingegebenen Wechselkurses
 Autor: 
 Datum: 20. Nov. 2017
 Kontakt: 
 Compile: gcc waehrungsrechner.c -o waehrungsrechner
*/


#include "stdio.h"

void flush(void);

int main(void) {
	int repeat_flag = 1;
	do{
		float euro = 0.0;
		float dollar = 0.0;
		float wechselkurs = 0.0;

		printf("Währungsrechner\n");
		printf("Bitte aktuellen Wechselkurs USD->EUR eingeben: ");
		scanf("%f", & wechselkurs);
		flush();
		printf("Bitte Betrag in USD eingeben: ");
		scanf("%f", & dollar);
		flush();

		if ((wechselkurs > 0) && (dollar > 0)) {
			euro = dollar * wechselkurs;
			printf("%f Dollar sind %f Euro\n", dollar, euro);
		}else{
			printf("Nur Werte groesser 0 eingeben!\n");
		}
		
		char check_if_n = ' ';
		printf("Weiter? nein=n, sonst beliebiges Zeichen eingeben : ");
		scanf("%c", & check_if_n);
		if(check_if_n == 'n'){
			repeat_flag = 0;
		}
	}while(repeat_flag != 0);
	return 0;
}

void flush(void){
	int char_buffer = 0;
	while((char_buffer = getchar()) != '\n' && char_buffer != EOF) {}
}




