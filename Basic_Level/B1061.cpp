#include <cstdio>
const int maxn = 100 + 5;
const int maxm = 100 + 5;
int scores[maxm] = {0}, ans[maxm] = {0};

int main() {
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= m; i++) {
		scanf("%d", &scores[i]);
	}
	for(int i = 1; i <= m; i++) {
		scanf("%d", &ans[i]);
	}
	while(n--) {
		int gre = 0, tmp;
		for(int i = 1; i <= m; i++) {
			scanf("%d", &tmp);
			if(tmp == ans[i]) gre += scores[i];
		}
		printf("%d\n", gre);
	}
	return 0;
} 
