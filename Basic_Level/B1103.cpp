#include <cstdio>
#include <cmath>
typedef long long LL;
int main() {
	LL m, n, a, b, c, tmp;
	scanf("%lld %lld", &m, &n);
	bool flag = false;
	for(; m <= n; m++) {
		a = m;
		tmp = a * a * a - (a - 1) * (a - 1) * (a - 1);
		c = sqrt(tmp);
		if(c * c != tmp) continue;
		else {
			for(b = 1; b < c; b++) {
				if(c == b * b + (b - 1) * (b - 1)) {
					flag = true;
					printf("%lld %lld\n", a, b);
				}
			}
		}
	}
	if(!flag) printf("No Solution\n");
	return 0;
}
