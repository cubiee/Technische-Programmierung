/* binomialkoeffizient.c
berechnung des binomialkoeffizient
Autor: 
Datum: 30. Nov. 2017
Kontakt: 
Compile: gcc -Wall -pedantic binomialkoeffizient.c -o binomialkoeffizient -std=c99
*/



#include <stdio.h>

void flush(void);

int main(void){
	int wert_n = 0;
	int wert_k = 0;
	printf("Binomialkoeffizient\n");
	printf("Bitte wert für N eingeben: ");
	scanf("%i", & wert_n);
	while(wert_n <= 0){
		flush();
		printf("Ungültiger Eingabewert bitte Wert erneut angeben!\n");
		printf("Bitte wert für N eingeben: ");
		scanf("%i", & wert_n);
	}
	printf("Bitte wert für K eingeben: ");
	scanf("%i", & wert_k);
	while((wert_k <= 0)&&(wert_k < wert_n)){
		flush();
		printf("Ungültiger Eingabewert bitte Wert erneut angeben!\n");
		printf("Bitte wert für K eingeben(k < n und k,n > 0): ");
		scanf("%i", & wert_k);
	}
	
	unsigned long long zaehler = wert_n;
	unsigned long long nenner = 1;
	for(unsigned long long zaehler_count = 1; zaehler_count < wert_k; zaehler_count++){
		zaehler = zaehler * (wert_n - zaehler_count);
	}
	for(unsigned long long nenner_count = 1; nenner_count <= wert_k; nenner_count++){
		nenner = nenner * nenner_count;
	}
	unsigned long long ergebnis = zaehler / nenner;
	
	printf("Binomialkoeffizient für N = %i und K = %i ist gleich : %lli\n",wert_n ,wert_k ,ergebnis);
	return 0;
}


void flush(void){
	char char_buff = 0;
	while ((char_buff = getchar()) != '\n' && char_buff != EOF) { }
}