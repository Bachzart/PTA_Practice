#include <cstdio>

int main() {
	int tmp, i = 1;
	while(scanf("%d", &tmp) != EOF) {
		if(tmp == 250) break;
		i++;
	}
	printf("%d", i);
	return 0;
}
