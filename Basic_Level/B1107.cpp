#include <cstdio>

int main() {
	int n, m, tmp, max2 = -1;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		int max1 = -1;
		for(int j = 0; j < m; j++) {
			scanf("%d", &tmp);
			if(max1 < tmp) max1 = tmp;
		}
		printf("%d", max1);
		if(i != n - 1) printf(" ");
		if(max1 > max2) max2 = max1;
	}
	printf("\n%d", max2);
	return 0;
}
