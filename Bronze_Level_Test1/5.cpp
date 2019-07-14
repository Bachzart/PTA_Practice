#include <cstdio>

int main(int argc, char const *argv[]) {
	int A, B;
	scanf("%d %d", &A, &B);
	double result = (double)A / B;
	if(B == 0) {
		printf("%d/%d=Error", A, B);
	} else if(B < 0) {
		printf("%d/(%d)=%.2lf", A, B, result);
	} else {
		printf("%d/%d=%.2lf", A, B, result);
	}
	return 0;
} 
