#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

void pythagoras(int max);
int get_usr_int(char *prompt, int min, int max);

int main(void){
	char prompt[200];
	int minimum = 25;
	int maximum = 999999999;
	sprintf(prompt,"Bitte Maximalwert für c^2 eingeben(zwischen %d und %d): ",minimum,maximum);
	int user = get_usr_int(prompt,minimum,maximum);
	pythagoras(user);
	return 0;
}


void pythagoras(int max){
	int m = 2;
	int n = 0;
	int a = 0;
	int b = 0;
	int c = 0;
	int counter = 0;
	do{
		for(n = 1; n <=(m-1); n++){
			a = m*m - n*n;
			b = 2*m*n;
			c = m*m +n*n;
			counter++;
			printf("%d.\tFuer a = %6d, b = %6d, c = %6d: %9d + %9d = %9d\n",counter,a,b,c,a*a,b*b,c*c);
		}
		m++;
	}while(c*c < max);
}

int get_usr_int(char *prompt, int min, int max){
	int user_value = 0;
	printf("%s",prompt);
	int char_buffer = 0;
	int pruefe = scanf("%i",&user_value);
	while((pruefe != 1)||(user_value < min)||(user_value > max)){
		while((char_buffer = getchar()) != '\n' && char_buffer != EOF) {}
		printf("Ungueltige eingabe!\n");
		printf("%s",prompt);
		pruefe = scanf("%i",&user_value);
	}
	return user_value;
}