#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

#define MAX_NAME_SIZE 31

#define DEBUG

typedef struct input_parameter_s{
	char input_file[MAX_NAME_SIZE ];
	char output_file[MAX_NAME_SIZE];
	int key;
} INPUT_PARAMETER;

INPUT_PARAMETER new_input_parameter(void);

typedef struct file_information{
	char filename[MAX_NAME_SIZE];
	int anzahl_zeichen;
}FILE_INFORMATION;

FILE_INFORMATION new_file_information(void);


void menue(void);
void print_input_args(INPUT_PARAMETER args);
void print_file_info(FILE_INFORMATION info);


int check_input_parameter(char **parameter_list, INPUT_PARAMETER *parameter);
FILE *load_file(char *filename, FILE_INFORMATION *file_info);
FILE *create_new_file(char *filename);


int main(int argc, char *argv[]){
	if (argc != 4){
		menue();
	}
	else{
		INPUT_PARAMETER input_parameter = new_input_parameter();
		FILE_INFORMATION input_file_information = new_file_information();

		FILE *input_file;
		FILE *output_file;

		if (FALSE == check_input_parameter(argv, &input_parameter)){
			printf("Wert fuer den schluessel ungueltig (kein integer oder 0)!\n");
			menue();
		}
		else if(NULL == (input_file = load_file(input_parameter.input_file, &input_file_information))){
			printf("Konnte Eingabedatei nicht oeffnen (nicht vorhanden oder keine zugriffsrechte)!\n");
			menue();
		}
		else if (NULL == (output_file = create_new_file(input_parameter.output_file))){
			printf("Konnte Ausgabedatei nicht oeffnen (Datei bereits vorhanden oder Fehler aufgetreten)!\n");
			menue();
		}
		else{
			printf("alles in ordnung soweit\n");
			//verschluesseln
		}
#ifdef DEBUG
			print_input_args(input_parameter);
			print_file_info(input_file_information);
#endif
	}
	return 0;
}

INPUT_PARAMETER new_input_parameter(void){
	INPUT_PARAMETER new_parameter;
	memset(new_parameter.input_file, '\0', MAX_NAME_SIZE);
	memset(new_parameter.output_file, '\0', MAX_NAME_SIZE);
	new_parameter.key = 0;
	return new_parameter;
}

FILE_INFORMATION new_file_information(void){
	FILE_INFORMATION new_file_information;
	memset(new_file_information.filename, '\0', MAX_NAME_SIZE);
	new_file_information.anzahl_zeichen = 0;
	return new_file_information;
}

void menue(void){
	printf("Aufruf durch:\n");
	printf("\t./geheim <schluessel> <eingabedatei> <ausgabedatei>\n");
}

void print_input_args(INPUT_PARAMETER args){
	printf("Input Argumente:\n");
	printf("Input:          %s\n", args.input_file);
	printf("Output:         %s\n", args.output_file);
	printf("key:            %d\n", args.key);
	return;
}

void print_file_info(FILE_INFORMATION info){
	printf("File information:\n");
	printf("Filename:       %s\n", info.filename);
	printf("Zeichenanzahl:  %d\n", info.anzahl_zeichen);
	return;
}

FILE *load_file(char *filename, FILE_INFORMATION *file_info){
	FILE *file;
	if (NULL == (file = fopen(filename, "r"))){
		return NULL;
	}
	else{
		strncpy(file_info->filename, filename, MAX_NAME_SIZE - 1);
		fseek(file, 0, SEEK_END);
		file_info->anzahl_zeichen = ftell(file);
		rewind(file);
		return file;
	}
}

FILE *create_new_file(char *filename){
	FILE *datei;
	if (NULL !=  fopen(filename, "r")){
		return NULL; // datei bereits vorhanden
	}
	else if(NULL == (datei = fopen(filename, "w"))){
		return NULL; // datei nicht beschreibbar
	}
	else{
		return datei;
	}
}

int check_input_parameter(char **parameter_list, INPUT_PARAMETER *parameter){
	int status = 0;
	int key = 0;
	char suchstring[] = {
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz"
		"!\"'$%&'()*+,./:;<=>?@[\\]^_`{|}~"
	};
	if ((NULL != strpbrk(parameter_list[1], suchstring)) || (0 == atoi(parameter_list[1]))){
		status = FALSE;
	}
	else{
		key = atoi(parameter_list[1]);
		strncpy(parameter->input_file, parameter_list[2], MAX_NAME_SIZE - 1);
		strncpy(parameter->output_file, parameter_list[3], MAX_NAME_SIZE - 1);
		key = atoi(parameter_list[1]);

		if (key < 0){
			key = key * (-1);
			key = key % 26;
			key = 26 - key;
			parameter->key = key;
		}
		else{
			key = key % 26;
			parameter->key = key;
		}
		status = TRUE;
	}
	return status;
}