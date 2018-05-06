/* waehrungsrechner.c
Programm zur ausgabe von einer umrechnungstabelle
Autor: 
Datum: 30. Nov. 2017
Kontakt: 
Compile: gcc -Wall -pedantic waehrungsrechner.c -o waehrungsrechner -std=c99
*/

#include <stdio.h>

void flush(void);

int main(void){
	float umrechnungskurs = 0;
	printf("Umrechnungstabelle USD -> EUR\n");
	printf("Bitte geben Sie den Wechselkurs (USD->EUR) ein: ");
	scanf("%f", &umrechnungskurs );
	printf("%f", umrechnungskurs);
	while ((umrechnungskurs <= 0)||(umrechnungskurs > 49.99950)) {
		flush();
		printf("Ungültiger Eingabewert Umrechnungskurs bitte erneut eingeben!\n");
		printf("Bitte geben Sie den Wechselkurs (USD->EUR) ein: ");
		scanf("%f", &umrechnungskurs );
	}
	
	printf(" ------------------------\n");	
	for(int i = 1; i <= 20; i++){
		printf("|%6.2f USD = %6.2f EUR |\n",(float)i,(float)i * umrechnungskurs);
	}
	printf(" ------------------------\n");
	return 0;
}

void flush(void){
	int c = 0;
	while ((c = getchar()) != '\n' && c != EOF) { }
}