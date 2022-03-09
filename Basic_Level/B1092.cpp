#include <cstdio>
const int maxn = 1000 + 5;
int sales[maxn] = {0};

int main() {
	int n, m, tmp;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		for(int j = 1; j <= n; j++) {
			scanf("%d", &tmp);
			sales[j] += tmp;
		}
	}
	int max = sales[1];
	for(int i = 2; i <= n; i++) {
		if(max < sales[i]) max = sales[i];
	}
	printf("%d\n", max);
	bool flag = true;
	for(int i = 1; i <= n; i++) {
		if(max == sales[i]) {
			if(flag) {
				printf("%d", i);
				flag = false;
			} else printf(" %d", i);
		}
	}
	return 0;
}
