/* sizeof.c
Programm zur ausgabe der speichergroesse verschiedener dateiformate
Name:
Datum: 7. dez. 2017
Kontakt: 
Compile: gcc -Wall -pedantic sizeof.c -o sizeof -std=c99
*/



#include <stdio.h>

int main(void){
	printf("Anzahl Bits von unsigned char : %i\n", (int)(sizeof(unsigned char)*8));
	printf("Anzahl Bits von char : %i\n", (int)(sizeof(char)*8));
	printf("Anzahl Bits von unsigned int : %i\n", (int)(sizeof(unsigned int)*8));
	printf("Anzahl Bits von int : %i\n", (int)(sizeof(int)*8));
	printf("Anzahl Bits von unsigned short : %i\n", (int)(sizeof(unsigned short)*8));
	printf("Anzahl Bits von short : %i\n", (int)(sizeof(short)*8));
	printf("Anzahl Bits von unsigned long : %i\n", (int)(sizeof(unsigned long)*8));
	printf("Anzahl Bits von long : %i\n", (int)(sizeof(long)*8));
	return 0;
}