#include <cstdio>
#include <cmath>
const int maxn = 100 + 5;
int fact[maxn] = {0}, iswolf[maxn], lie[maxn];

int main() {
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &fact[i]);
	}
	for(int i = 1; i <= n; i++) {
		for(int j = i + 1; j <= n; j++) {
			for(int i = 1; i <= n; i++) {
				iswolf[i] = 1;
			}
			iswolf[i] = iswolf[j] = -1;
			int index = 0;
			for(int k = 1; k <= n; k++) {
				if(fact[k] * iswolf[abs(fact[k])] < 0) lie[index++] = k;
			}
			if(index == 2 && iswolf[lie[0]] + iswolf[lie[1]] == 0) {
				printf("%d %d\n", i, j);
				return 0;
			}
		}
	}
	printf("No Solution");
	return 0;
} 
