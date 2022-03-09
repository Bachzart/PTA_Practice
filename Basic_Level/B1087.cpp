#include <cstdio>
const int maxn = 20000 + 5;
int appear[maxn] = {0};
int main() {
	int N, n, ans = 0;
	scanf("%d", &N);
	for(n = 1; n <= N; n++) {
		appear[n / 2 + n / 3 + n / 5]++;
	}
	for(n = 0; n <= maxn; n++) {
		if(appear[n]) ans++;
	}
	printf("%d", ans);
	return 0;
}
