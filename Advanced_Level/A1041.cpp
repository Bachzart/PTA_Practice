#include <cstdio>
const int MAXN = 100000 + 5;

int main(int argc, char const *argv[]) {
	int N, Num[MAXN] = {0}, times[MAXN] = {0};
	scanf("%d", &N);
	for(int i = 0; i < N; i++) {
		scanf("%d", &Num[i]);
		times[Num[i]]++;
	}
	int i;
	for(i = 0; i < N; i++) {
		if(times[Num[i]] == 1) {
			printf("%d", Num[i]);
			break;
		}
	}
	if(i == N) {
		printf("None");
	}
	return 0;
}
