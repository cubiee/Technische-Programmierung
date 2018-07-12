#include "Random.h"
#include <stdlib.h>
#include <time.h>


void init_rand(void){
	long sec = 0L;
	time(&sec);
	srand(sec);
}

int  get_random_number(int min, int max){
	int value = 0;
	value = rand();
	value = (value % (max - min + 1)) + min;
	return value;
}