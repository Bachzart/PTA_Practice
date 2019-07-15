#include <cstdio>

int main(int argc, char const *argv[]) {
	int A, B;
	scanf("%d %d", &A, &B);
	double quotient = (double)A / B;
	if(B < 0) {
		printf("%d/(%d)=%.2lf\n", A, B, quotient);
	} else if(B == 0) {
		printf("%d/%d=Error\n", A, B);
	} else {
		printf("%d/%d=%.2lf", A, B, quotient);
	}
	return 0;
}
