#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY 55
#define TRUE 1
#define FALSE 0

int load_file(char *filename, char **buffer);
int write_file(char *filename, char *data);

char verschluesseln(char character, int n);
char entschluesseln(char character, int n);

int main(int argc,char *argv[]){
	if (argc != 5){
		printf("wrong input parameters\n");
	}
	else
	{
		char *datei_inhalt = NULL;
		int written_chars = 0;
		if (0 > (written_chars = load_file(argv[1], &datei_inhalt))){
			printf("Konnte dateinhalt nicht lesen!\n");
		}
		else
		{
			if (strcmp(argv[4], "decode") == 0){
				for (int i = 0; i < written_chars; i++){
					datei_inhalt[i] = entschluesseln(datei_inhalt[i], atoi(argv[3]));
				}
			}
			else if (strcmp(argv[4], "encode") == 0){
				for (int i = 0; i < written_chars; i++){
					datei_inhalt[i] = verschluesseln(datei_inhalt[i], atoi(argv[3]));
				}
			}

			if (write_file(argv[2], datei_inhalt) == 0){
				printf("konnte datei nicht schreiben\n");
			}
			else
			{
				printf("erfolgreich\n");
			}
		}
	}

	return 0;
}

int load_file(char *filename, char **buffer){
	FILE *datei;
	if (NULL == (datei = fopen(filename, "r"))){
		return -1;
	}
	else
	{
		fseek(datei, 0, SEEK_END);
		long anzahl_zeichen = ftell(datei);
		*buffer = malloc((anzahl_zeichen + 1)*sizeof(char));
		rewind(datei);
		for (int i = 0; i < anzahl_zeichen; i++){
			(*buffer)[i] = fgetc(datei);
		}
		fclose(datei);
		(*buffer)[anzahl_zeichen] = '\0';
		return anzahl_zeichen;
	}
}

int write_file(char *filename, char *data){
	FILE *datei;
	if (NULL == (datei = fopen(filename, "w"))){
		return FALSE;
	}
	else
	{
		fputs(data, datei);
		fclose(datei);
		return TRUE;
	}
}

char verschluesseln(char character, int key){
	key = key % 26;
	if (character >= 'a' && character <= 'z'){
		return ((character - 'a' + key) % 26 ) + 'a';
	}
	if (character >= 'A' && character <= 'Z'){
		return ((character - 'A' + key) % 26) + 'A';
	}
	else
	{
		return character;
	}
}

char entschluesseln(char character, int key){
	key = key % 26;
	if (character >= 'a' && character <= 'z'){
		return ((character - 'a' + (26 - key)) % 26) + 'a';
	}
	if (character >= 'A' && character <= 'Z'){
		return ((character - 'A' + (26 - key)) % 26) + 'A';
	}
	else
	{
		return character;
	}
}