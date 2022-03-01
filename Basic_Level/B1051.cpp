#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[]) {
	double R1, P1, R2, P2, R, P;
	scanf("%lf %lf %lf %lf", &R1, &P1, &R2, &P2);
	R = R1 * R2 * (cos(P1) * cos(P2) - sin(P1) * sin(P2));
	P = R1 * R2 * (cos(P1) * sin(P2) + sin(P1) * cos(P2));
	// prevent to print "-0.00"
	if(-0.01 < R && R < 0) R = 0.0;
	if(-0.01 < P && P < 0) P = 0.0;
	printf("%.2lf", R);
	if(P >= 0) {
		printf("+%.2lfi\n", P);
	} else {
		printf("-%.2lfi\n", fabs(P));
	}
	return 0;
} 
