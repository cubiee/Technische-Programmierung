#include <stdio.h>
#include "pythagoras.h"

// m und n (m, n element N und m > n)
void pythagoras(int endwert){
	int max = 0;
	int m = 0;
	int n = 0;
	int a, b, c;

	while ((2 * max * max - 2 * max + 1) <= endwert){
		max++;
	}

	for (m = 2; m <= max; m++){
		for (n = 1; n < m; n++){
			a = (m*m) - (n*n);
			b = 2 * m*n;
			c = m*m + n*n;
			if ((m + n) % 2){
				printf("%4i^2 + %4i^2 = %4i^2\n", a, b, c);
			}
		}
	}
    return;
}