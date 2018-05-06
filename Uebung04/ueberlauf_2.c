/* ueberlauf.c
Programm zum visualieren des ueberlaufen einer variable
Name:
Datum: 7. dez. 2017
Kontakt: 
Compile: gcc -Wall -pedantic ueberlauf_2.c -o ueberlauf_2 -std=c99
*/


#include <stdio.h>

long int exponetiate(long int base ,long int exponent);

int main(void){
	unsigned char zahl_1 = 0;
	char zahl_2 = 0;
	long int max_value_1 = 0;
	long int max_value_2 = 0;
	
	max_value_1 = exponetiate(2,(long int)(sizeof(unsigned char)*8))-1; 
	max_value_2 =(exponetiate(2,(long int)(sizeof(char)*8))/2)-1;

	
	printf("max_value_1 %li\n",max_value_1);
	printf("max_value_2 %li\n",max_value_2);
	
	for( int counter = -6; counter <= 6; counter++){
		zahl_1 = max_value_1 + counter;
		zahl_2 = max_value_2 + counter;		
		printf("Zahl 1: %li \t\tZahl 2: %li\n",(long int)zahl_1 , (long int)zahl_2);
	}	
	return 0;
}

long int exponetiate(long int base ,long int exponent){
	long int result = 1;
	for(int exponent_counter = 1; exponent_counter <= exponent; exponent_counter++){
		result = result * base;
	}
	return result;
}