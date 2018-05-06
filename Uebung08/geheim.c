#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

typedef struct main_args_s{
	char *inputfile_name;
	char *outputfile_name;
	int key;
}MAIN_ARGS;

void menue(void);
int load_file(char *filename, char **buffer);
int write_file(char *filename, char *data);
int validate_input(char *input[], MAIN_ARGS *parameter);
char verschluesseln(char character, int n);

int main(int argc, char *argv[]){
    if(argc < 4){
        menue();
    }else{
		char *datei_inhalt;
		int characters_loaded = 0;
		MAIN_ARGS input_parameter;

		if (validate_input(argv, &input_parameter) == FALSE){
			printf("Key hat ungueltiges format! Bitte nur integer grösser 0 eingeben!\n");
			menue();
		}
		else if ((characters_loaded = load_file(input_parameter.inputfile_name, &datei_inhalt)) < 0){
			printf("Eingabedatei konnte nicht geöffnet werden!\n");
			menue();
		}
		else{
			for (int i = 0; i < characters_loaded; i++){
				datei_inhalt[i] = verschluesseln(datei_inhalt[i], input_parameter.key);
			}
			if ((write_file(input_parameter.outputfile_name, datei_inhalt)) == FALSE){
				printf("Ausgabedatei konnte nicht geöffnet werden!\n");
			}
		}
    }
    return 0;
}

void menue(void){
	printf("Aufruf durch:\n");
	printf("\t./geheim <schluessel> <eingabedatei> <ausgabedatei>\n");
}

int load_file(char *filename, char **buffer){
	FILE *datei;
	if (NULL == (datei = fopen(filename, "r"))){
		return -1;
	}
	else{
		fseek(datei, 0, SEEK_END);
		long anzahl_zeichen = ftell(datei);
		*buffer = malloc((anzahl_zeichen + 1)*sizeof(char));
		rewind(datei);
		for (int i = 0; i < anzahl_zeichen; i++){
			(*buffer)[i] = fgetc(datei);
		}
		(*buffer)[anzahl_zeichen] = '\0';
		fclose(datei);
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

int validate_input(char *input[], MAIN_ARGS *parameter){
	char suchstring[] = {
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"!\"'$%&'()*+-,./:;<=>?@[\\]^_`{|}~"
	};

	int status;

	if ((strpbrk(input[1], suchstring) != NULL) || (atoi(input[1]) == 0)){
		status = FALSE;
	}
	else{
		parameter->inputfile_name = input[2];
		parameter->outputfile_name = input[3];
		parameter->key = atoi(input[1]);
		status = TRUE;
	}
	return status;
}

char verschluesseln(char character, int key){
	key = key % 26;
	if (character >= 'a' && character <= 'z'){
		return ((character - 'a' + key) % 26) + 'a';
	}
	if (character >= 'A' && character <= 'Z'){
		return ((character - 'A' + key) % 26) + 'A';
	}
	else
	{
		return character;
	}
}