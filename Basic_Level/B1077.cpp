#include <cstdio>

int main() {
	int n, m, tea_score;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++) {
		scanf("%d", &tea_score);
		int sum = 0, valid = 0, tmp, max = -1, min = m + 1;
		for(int j = 0; j < n - 1; j++) {
			scanf("%d", &tmp);
			if(0 <= tmp && tmp <= m) {
				sum += tmp;
				valid++;
				if(tmp > max) max = tmp;
				if(tmp < min) min = tmp;
			}
		}
		double ans = (double)(sum - max - min) / (valid - 2);
		printf("%d\n", (int)((ans + tea_score) / 2 + 0.5));
	}
	return 0;
}
