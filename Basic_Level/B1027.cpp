#include <cstdio>
#define ABS(x) ((x) >= 0 ? (x) : -(x))

int main(int argc, char const *argv[]) {
	int N, layers;
	char c;
	scanf("%d %c", &N, &c);
	for(layers = 1; 2 * layers * layers - 1 <= N; layers++);
	layers--;
	for(int i = 0; i < 2 * layers - 1; i++) {
		for(int j = 0; j < layers - ABS(layers - i - 1) - 1; j++) {
			putchar(' ');
		}
		for(int k = 0; k < 2 * ABS(layers - i - 1) + 1; k++) {
			putchar(c);
		}
		putchar('\n');
	}
	printf("%d\n", N - 2 * layers * layers + 1);
	return 0;
} 

