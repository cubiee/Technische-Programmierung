/*feldmin.c
Programm zum 
Datum: 08.01.2018
Autor: 
Compile: gcc -Wall -pedantic -std=c99 feldmin.c -o feldmin 
*/
#include <stdio.h>
#include <limits.h>

#define MAX_LENGTH_ZAHLEN 100
#define WIEDERHLUNGSRATE 5
#define TRUE  1
#define FALSE 0

void flush(void); 
void bubble_sort(int *array, int size); 
int get_usr_int(char *prompt, int min, int max);
double berechne_mittelwert(int *array, int size);

int main(void){
	//Arbeitsvariablen
	int repeat_flag = TRUE;
	int i = 0, j = 0;
	int startpunkt = 0;
	char check_if_n = ' ';
	//Uservariablen
	int userzahlen[MAX_LENGTH_ZAHLEN] = {0};
	int userzahlen_sort[MAX_LENGTH_ZAHLEN] = {0};
	int userzahlen_size = 0;
	double mittelwert = 0.0;
	int min_position = 0;
	//Werte Einlesen
	do{
		printf("Bitte %i Werte eingeben : \n", WIEDERHLUNGSRATE);
		for(i = 0; i < WIEDERHLUNGSRATE; i++){
			userzahlen[startpunkt + i] = get_usr_int("",INT_MIN,INT_MAX);
		}
		startpunkt += WIEDERHLUNGSRATE;
		if(startpunkt <= MAX_LENGTH_ZAHLEN - WIEDERHLUNGSRATE){
			printf("Weiter? nein=n, sonst beliebiges Zeichen eingeben : ");
			flush();
			scanf("%c", &check_if_n);
			if(check_if_n == 'n'){
				repeat_flag = FALSE;
				userzahlen_size = startpunkt;
			}
		}else{
			printf("Maximalanzahl erreicht!\n");
			repeat_flag = FALSE;
		}
	}while(repeat_flag == TRUE);
	//Mittelwert Berechnen
	mittelwert = berechne_mittelwert(userzahlen, userzahlen_size);
	//Userarray kopieren
	for(i = 0; i <	userzahlen_size; i++){
		userzahlen_sort[i] = userzahlen[i];
	}
	//sortieren
	bubble_sort(userzahlen_sort, userzahlen_size);
	//position des kleinsten element im unsortierten array suchen
	repeat_flag = TRUE;
	i = 0;
	do{
		if(userzahlen[i] == userzahlen_sort[0]){
			min_position = i;
			repeat_flag = FALSE;
		}else{
			i++;
		}
	}while(repeat_flag == TRUE);
	//Ausgabe der werte
	printf("Ausgabe Werte :\n");
	for(i = 0; i < userzahlen_size; i += WIEDERHLUNGSRATE){
		for(j = 0; j < WIEDERHLUNGSRATE; j++){
			printf("%5i",userzahlen[i+j]);
		}
		printf("\n");
	}
	printf("Min Wert : %i kommt erstmalig vor an position %i\n",userzahlen_sort[0],min_position);
	printf("Mittelwert : %g\n",mittelwert);
	//falls gewünscht sortierte ausgabe
	printf("Soll das array sortiert ausgegeben werden (j = ja)?");
	flush();
	scanf("%c", &check_if_n);
	if(check_if_n == 'j'){
		for(i = 0; i < userzahlen_size; i += WIEDERHLUNGSRATE){
			for(j = 0; j < WIEDERHLUNGSRATE; j++){
				printf("%5i",userzahlen_sort[i+j]);
			}
			printf("\n");
		}
	}
	return 0;
}
//Integer Wert vom nutzer einlesen
int get_usr_int(char *prompt, int min, int max){
	int user_value = 0;
	printf("%s",prompt);
	int char_buffer = 0;
	int pruefe = scanf("%i",&user_value);
	while((pruefe != 1)||(user_value < min)||(user_value > max)){
		while((char_buffer = getchar()) != '\n' && char_buffer != EOF) {}
		printf("Ungueltige eingabe!\n");
		pruefe = scanf("%i",&user_value);
	}
	return user_value;
}
//Sortierfunktion
void bubble_sort(int *array, int size){
	int iterations = size - 1;
	int counter = 0;
	int in_order = 0;
	do{
		in_order = 0;
		for(counter = 0; counter < iterations; counter++){
			if(array[counter] > array[counter + 1]){
				int array_buffer = array[counter];
				array[counter] = array[counter + 1];
				array[counter + 1] = array_buffer;
			}else{
				in_order++;
			}
		}
		iterations--;
	}while((iterations > 0)&&(in_order < (size -1)));
}
//Mittelwert berechnen
double berechne_mittelwert(int *array, int size){
	double buffer = 0.0;
	for(int counter = 0; counter < size; counter++){
		buffer = buffer + array[counter];
	}
	double mittelwert = buffer / size;
	return mittelwert;
}
//Inputbuffer löschen
void flush(void){
	int char_buffer = 0;
	while((char_buffer = getchar()) != '\n' && char_buffer != EOF) {}
}


















