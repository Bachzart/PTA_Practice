#include <cstdio>
int grade[101] = {0};

int main(int argc, char const *argv[]) {
	int N, K, temp;
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &temp);
		grade[temp]++;
	}
	scanf("%d", &K);
	while(K--) {
		scanf("%d", &temp);
		printf("%d", grade[temp]);
		if(K > 0) putchar(' ');
	}
	return 0;
}
