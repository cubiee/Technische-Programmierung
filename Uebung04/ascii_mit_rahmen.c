/* ascii_mit_rahmen.c
Programm zur ausgabe der ASCII Tabelle
Name:
Datum: 7. dez. 2017
Kontakt: Compile: gcc -Wall -pedantic ascii_mit_rahmen.c -o ascii_mit_rahmen -std=c99
*/

#include <stdio.h>

int main(void){
	int character = 32;
	printf(" -------------------------------------------------------------------------------------\n");
	printf("| INT    HEX   CHAR  |  INT    HEX   CHAR  |  INT    HEX   CHAR  |  INT    HEX   CHAR |\n");
	for(int count = 0; count < 24; count++){
		printf("| %3i = 0x%x = %4c  |  ",character,character,(char)character);
		printf("%3i = 0x%x = %4c  |  ",character+1,character+1,(char)(character+1));
		printf("%3i = 0x%x = %4c  |  ",character+2,character+2,(char)(character+2));
		printf("%3i = 0x%x = %4c ",character+3,character+3,(char)(character+3));
		if((character+3) == 127){
			printf("  |\n");
		}else{
			printf("|\n");
		}
		character = character + 4;
	}
	printf(" -------------------------------------------------------------------------------------\n");
	return 0;
}