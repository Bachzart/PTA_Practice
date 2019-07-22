#include <cstdio>
const int MAXN = 100000 + 10;
double seq[MAXN] = {0};

int main(int argc, char const *argv[]) {
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%lf", &seq[i]);
	}
	double ans = 0;
	int i = 0;
	ans = seq[0] * n;
	if(n > 1) {
		for(i = 1; i < n - 1; i++) {
			ans += (seq[i] * (i + 1) * (n - i));
		}
		ans += seq[n - 1] * n;
	}
	printf("%.2lf\n", ans);
	return 0;
}
