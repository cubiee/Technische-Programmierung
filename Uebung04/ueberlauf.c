/* ueberlauf.c
Programm zum visualieren des ueberlaufen einer variable
Name:
Datum: 7. dez. 2017
Kontakt: 
Compile: gcc -Wall -pedantic ueberlauf.c -o ueberlauf -std=c99
*/


#include <stdio.h>


int main(void){
	unsigned char zahl_1 = 0;
	char zahl_2 = 0;
	int max_value_1 = 255; 
	int max_value_2 = 127;

	printf("max_value_1 %i\n",max_value_1);
	printf("max_value_2 %i\n",max_value_2);
	
	for( int counter = -6; counter <= 6; counter++){
		zahl_1 = max_value_1 + counter;
		zahl_2 = max_value_2 + counter;		
		printf("Zahl 1: %5i  Zahl 2: %5i\n",zahl_1 , zahl_2);
	}	
	return 0;
}

