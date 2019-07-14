#include <cstdio>

int main(int argc, char const *argv[]) {
	int D;
	scanf("%d", &D);
	D += 2;
	if(D > 7) {
		D -= 7;
	}
	printf("%d", D);
	return 0;
}
