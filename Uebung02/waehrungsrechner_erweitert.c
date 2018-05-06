/* waehrungsrechner_erweitert.c
Erweiterter waehrungsrechner
Autor: Joshua Harig
Datum: 30. Nov. 2017
Kontakt: 
Compile: gcc -Wall -pedantic waehrungsrechner_erweitert.c -o waehrungsrechner_erweitert -std=c99
*/

/*
Bsp:
 --------------------------------------------------------------------------------
|	1.00 USD = 0.81 EUR | 10.00 USD = 8.06 EUR	|	 100.00 USD = 80.57 EUR		|
|	2.00 USD = 1.61 EUR | 15.00 USD = 12.09 EUR |	 200.00 USD = 161.14 EUR	|
|	3.00 USD = 2.42 EUR | 20.00 USD = 16.11 EUR |	 300.00 USD = 241.71 EUR	|
|	4.00 USD = 3.22 EUR | 25.00 USD = 20.14 EUR |	 400.00 USD = 322.28 EUR	|
|	5.00 USD = 4.03 EUR | 30.00 USD = 24.17 EUR |	 500.00 USD = 402.85 EUR	|
|	6.00 USD = 4.83 EUR | 35.00 USD = 28.20 EUR |	 600.00 USD = 483.42 EUR	|
|	7.00 USD = 5.64 EUR | 40.00 USD = 32.23 EUR |	 700.00 USD = 563.99 EUR	|
|	8.00 USD = 6.45 EUR | 45.00 USD = 36.26 EUR |	 800.00 USD = 644.56 EUR	|
|	9.00 USD = 7.25 EUR | 50.00 USD = 40.28 EUR |	 900.00 USD = 725.13 EUR	|
|						| 55.00 USD = 44.31 EUR |	1000.00 USD = 805.70 EUR	|
|						| 60.00 USD = 48.34 EUR |	1100.00 USD = 886.27 EUR	|
|						| 65.00 USD = 52.37 EUR |	1200.00 USD = 966.84 EUR	|
|						| 70.00 USD = 56.40 EUR |	1300.00 USD = 1047.41 EUR	|
|						| 75.00 USD = 60.43 EUR |	1400.00 USD = 1127.98 EUR	|
|						| 80.00 USD = 64.46 EUR |	1500.00 USD = 1208.55 EUR	|
|						| 85.00 USD = 68.48 EUR |								|
|						| 90.00 USD = 72.51 EUR |								|
|						| 95.00 USD = 76.54 EUR |								|
 --------------------------------------------------------------------------------
*/


#include <stdio.h>

void flush(void);

int main(void){
	float umrechnungskurs = 0;
	printf("Umrechnungstabelle USD -> EUR\n");
	printf("Bitte geben Sie den Wechselkurs (USD->EUR) ein: ");
	scanf("%f", &umrechnungskurs);
	
	
	while ((umrechnungskurs <= 0) || (umrechnungskurs > 49)) {
		flush();
		printf("Ungültiger Eingabewert Umrechnungskurs bitte erneut eingeben!\n");
		printf("Bitte geben Sie den Wechselkurs (USD->EUR) ein: ");
		scanf("%f", &umrechnungskurs);
	}
	
	int einer = 1;
	int zehner = 10;
	int hunderter = 100;
	printf(" ------------------------------------------------------------------------- \n");
	for (int count = 1; count <= 18; count++){
		if(einer < 10){
			printf("| %4.2f USD = %4.2f EUR ", (float)einer, (float)einer * umrechnungskurs);
			einer++;
		}else{
			printf("|                     ");
		}
		
		if(zehner < 100){
			printf("| %5.2f USD = %5.2f EUR " ,(float)zehner, (float)zehner * umrechnungskurs);
			zehner = zehner + 5;
		}else{
			printf("|                       ");
		}
		
		if(hunderter < 1600){
			printf("| %7.2f USD = %7.2f EUR ", (float)hunderter, (float)hunderter * umrechnungskurs);
			hunderter = hunderter + 100;
		}else{
			printf("|                           ");
		}
		
		printf("|\n");
	}
	printf(" ------------------------------------------------------------------------- \n");
	return 0;
}

void flush(void){
	int c = 0;
	while ((c = getchar()) != '\n' && c != EOF) {}
}