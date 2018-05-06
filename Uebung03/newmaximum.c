/* newmaximum.c
Programm zur ausgabe des maximalwertes eingegebener zahlen und berechnung des mittelwertes
zahlenanzahl wird nur durch die groesse des arrays bestimmt
Autor: 
Datum: 18. Dez. 2017
Kontakt: 
Compile: gcc -Wall -pedantic newmaximum.c -o newmaximum -std=c99
*/

#include <stdio.h>
#define ARRAY_SIZE 4

void flush(void);
int read_usr_int(void);

int main(void){
	int repeat_flag = 1;
	int zahlen[ARRAY_SIZE];
	int zahlenanzahl = ARRAY_SIZE;
	int maximum = 0;
	float mittelwert = 0;

	
	do{
		// Zahlen einlesen
		printf("Bitte %i Werte eingeben: \n", zahlenanzahl);
		for(int counter = 0; counter <= ARRAY_SIZE - 1; counter++ ){
			zahlen[counter] =  read_usr_int();
		}
		
		// Maximum suchen
		maximum = zahlen[0];
		for(int counter = 0; counter <= zahlenanzahl - 1; counter++ ){
			if (zahlen[counter] > maximum){
				maximum = zahlen[counter];
			}
		}
		
		// Berechnung des Mittelwerts 
		mittelwert = 0;
		for(int counter = 0; counter <= zahlenanzahl - 1; counter++ ){
			mittelwert = mittelwert + (float)zahlen[counter];
		}
		mittelwert = mittelwert / (float)zahlenanzahl;
		
		// Ausgabe Mittelwert und Maximalwert
		printf("Der maximal wert ist : %i\n", maximum);
		printf("Der mittelwert ist : %.2f\n", mittelwert);
		
		// Neustartblock
		printf("Weiter? nein=n, sonst beliebiges Zeichen eingeben : ");
		char check_if_n = ' ';
		flush();
		scanf("%c", & check_if_n);
		if(check_if_n == 'n'){
			repeat_flag = 0;
		}
	}while(repeat_flag == 1);
	return 0;
}

// Funktion zum leeren des input buffer
void flush(void){
	int char_buffer = 0;
	while((char_buffer = getchar()) != '\n' && char_buffer != EOF) {}
}

// Funktion zum einlesen der eingegebenen zahlen 
int read_usr_int(void){
	int eingabe = 0;
	int check_if_eof = scanf("%i", &eingabe);
	while(check_if_eof != 1){
		flush();
		printf("Keine ganze Zahl bitte letzten Wert erneut eingeben!\n");
		check_if_eof = scanf("%i", &eingabe);
	}
	return eingabe;
}