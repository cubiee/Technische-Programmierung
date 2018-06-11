#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <bool.h>
#include <wertlesen.h>

#define BUFFERSIZE 200

int wert_lesen(char *prompt, int min, int max, int *zahl){
    int nmbr;
    BOOL status;
    if (min > max){
        int buffer = min;
        min = max;
        max = buffer;
    }
    if(min == max){
        status = FALSE;
    }
    else{
		char buffer[BUFFERSIZE] = { '\0' };
		char suchstring[] = {
			"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
			"abcdefghijklmnopqrstuvwxyz"
			"!\"'$%&'()*+,./:;<=>?@[\\]^_`{|}~"
		};

		printf(prompt);
		fgets(buffer, BUFFERSIZE, stdin);
		buffer[strcspn(buffer, "\n")] = '\0';
		if ((NULL != strpbrk(buffer, suchstring)) || (0 == strlen(buffer))){
			status = FALSE;
		}
		else{
			nmbr = atoi(buffer);
			if (nmbr > max || nmbr < min){
				status = FALSE;
			}
			else{
				*zahl = nmbr;
				status = TRUE;
			}
		}
    }
    return status;
}