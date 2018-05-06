#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menue(void);


int main(int argc, char *argv[]){
	if (argc != 2){
		menue();
	}
	else{
		FILE *datei;
		if (NULL == (datei = fopen(argv[1], "r"))){
			printf("Konnte datei nicht öffnen\n");
			menue();
		}
		else{
			fseek(datei, 0, SEEK_END);
			int anzahl_zeichen = ftell(datei);
			rewind(datei);
			char character;
			int grossbuchstaben = 0;
			int kleinbuchstaben = 0;
			int sonderzeichen = 0;
			int sonstige_zeichen = 0;
			int zeilenanzahl = 1;

			for (int i = 0; i <= anzahl_zeichen; i++){
				character = fgetc(datei);
				if (NULL != strchr("ABCDEFGHIJKLMNOPQRSTUVWXYZ", character)){
					grossbuchstaben++;
				}
				else if (NULL != strchr("abcdefghijklmnopqrstuvwxyz", character)){
					kleinbuchstaben++;
				}
				else if (NULL != strchr("!\"'$%&'()*+,./:;<=>?@[\\]^_`{|}~0123456789", character)){
					sonderzeichen++;
				}
				else{
					sonstige_zeichen++;
					if (character == '\n'){
						zeilenanzahl++;
					}
				}
			}
			printf("%s\n", argv[1]);
			printf("Zeilenanzahl: %d\n", zeilenanzahl);
			printf("Grossbuchstaben: %d\n", grossbuchstaben);
			printf("Kleinbuchstaben: %d\n", kleinbuchstaben);
			printf("Sonderzeichen: %d\n", sonderzeichen);
			printf("Sonstige Zeichen: %d\n", sonstige_zeichen);
		}
		



	}
	return 0;
}

void menue(void){
	printf("Aufruf durch:\n");
	printf("\t./analyse <dateiname>\n");
}