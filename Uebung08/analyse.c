#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAMEBUFFER_SIZE 30
#define LINEBUFFER_SIZE 1000
#define UPPERCASE "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define LOWERCASE "abcdefghijklmnopqrstuvwxyz"
#define SPECIAL_CHAR "!\"'$%&'()*+,./:;<=>?@[\\]^_`{|}~0123456789"

//struct zum speichern der dateiniformationen (heufigkeit buchstabensorten)
typedef struct fileinfo_s{
	char name[NAMEBUFFER_SIZE];
	int uppercase;
	int lowercase;
	int special_char;
	int rows;
}FILEINFO;

//helferfunktion
void menue(void);

//arbeiterfunktion
FILEINFO new_file_info(void);
FILE *open_new_file(char *filename, char *mode, FILEINFO *fileinfo_buffer);
void analyse_file(FILE* datei, FILEINFO *fileinfo_buffer);
void print_file_info(FILEINFO fileinfo);


int main(int argc, char *argv[]){
	if (argc != 2){
		menue();
	}
	else{
		FILE *datei;
		FILEINFO file_info = new_file_info();

		if (NULL == (datei = open_new_file(argv[1], "r", &file_info))){
			menue();
		}
		else{
			print_file_info(file_info);
		}
	}
	return 0;
}

void menue(void){
	printf("Aufruf durch:\n");
	printf("\t./analyse <dateiname>\n");
}

//erstellen eines structs mit defaultwerten
FILEINFO new_file_info(void){
	FILEINFO new_fileinfo;
	new_fileinfo.name[0] = '\0';
	new_fileinfo.lowercase = 0;
	new_fileinfo.uppercase = 0;
	new_fileinfo.special_char = 0;
	new_fileinfo.rows = 0;
	return new_fileinfo;
}

void print_file_info(FILEINFO fileinfo){
	printf("Name:            %s\n", fileinfo.name);
	printf("Zeilenanzahl:    %i\n", fileinfo.rows);
	printf("Grossbuchstaben: %i\n", fileinfo.uppercase);
	printf("Kleinbuchstaben: %i\n", fileinfo.lowercase);
	printf("Sonderzeichen:   %i\n", fileinfo.special_char);
}

//oeffnet datei und analysiert auf buchstabenvorkommen
FILE *open_new_file(char *filename, char *mode, FILEINFO *fileinfo_buffer){
	FILE *datei;
	if (NULL == (datei = fopen(filename, mode))){
		perror("FEHLER");
		return NULL;
	}
	else{
		strncpy(fileinfo_buffer->name, filename, NAMEBUFFER_SIZE);
		analyse_file(datei, fileinfo_buffer);
		return datei;
	}
}

//analysefunktion zaehlt zeichenweise die buchstabenvorkommen
void analyse_file(FILE *datei, FILEINFO *fileinfo_buffer){
	char linebuffer[LINEBUFFER_SIZE] = { '\0' };
	while (NULL != fgets(linebuffer, LINEBUFFER_SIZE, datei)){
		fileinfo_buffer->rows += 1;
		for (int i = 0; i < strlen(linebuffer); i++){
			if (NULL != strchr(UPPERCASE, linebuffer[i])){
				fileinfo_buffer->uppercase += 1;
			}
			else if (NULL != strchr(LOWERCASE, linebuffer[i])){
				fileinfo_buffer->lowercase += 1;
			}
			else if (NULL != strchr(SPECIAL_CHAR, linebuffer[i])){
				fileinfo_buffer->special_char += 1;
			}
		}
	}
	rewind(datei);
	return;
}