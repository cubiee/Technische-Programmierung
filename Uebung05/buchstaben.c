/*buchstaben.c
Programm zum analysieren der nutzereingabe auf zeichenhäufigkeit
Datum: 07.01.2018
Autor: 
Compile: gcc -Wall -pedantic -std=c99 buchstabe.c -o buchstabe 
*/
#include <stdio.h>
#define MAX_LENGTH_ZEICHEN 1000
#define MAX_LENGTH_SEARCH 1000


int main(void){
	char user_data[MAX_LENGTH_ZEICHEN];
	int counter = 0;
	char buffer = 0;
	int anzahl = 0;
	int i = 0, j = 0;
	char buchstaben[] = {'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','*'};
	int buchstaben_anzahl[MAX_LENGTH_SEARCH] = { 0 };
	int size_buchstaben = sizeof(buchstaben)/sizeof(char);
	

	printf("Eingabe Zeichen:\n");
	while((buffer = getchar()) != '#'){
		user_data[counter] = buffer;
		counter++;
	}
	
	for(i = 0; i < counter ; i++){
		for(j = 0; j < size_buchstaben - 1; j++){
			if((user_data[i] == buchstaben[j])||(user_data[i] == buchstaben[j]+32)){
				buchstaben_anzahl[j]++;
				anzahl++;
			}
		}
	}
	buchstaben_anzahl[size_buchstaben-1] = counter - anzahl;
	for(i = 0; i < size_buchstaben; i++){
		printf("%3c",buchstaben[i]);
	}
	printf("\n");
	for(i = 0; i < size_buchstaben; i++){
		printf("%3i",buchstaben_anzahl[i]);
	}
	printf("\n");
	return 0;
}


