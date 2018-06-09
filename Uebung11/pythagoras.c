#include <stdio.h>
#include <bool.h>
#include <pythagoras.h>

// m und n (m, n element N und m > n)
void pythagoras(int endwert){
	BOOL stop = FALSE;
	int m = 2, n = 1;
	int a, b, c;
	while (!stop){
		while (!stop && (n < m)){
			if ((m + n) % 2){
				if ((m*m + n*n) <= endwert){
					a = (m*m) - (n*n);
					b = 2 * m * n;
					c = m*m + n*n;
					printf("%4i^2 + %4i^2 = %4i^2\n", a, b, c);
				}
				else{
					stop = TRUE;
				}
			}
			n++;
		}
		n = 1;
		m++;
	}
    return;
}