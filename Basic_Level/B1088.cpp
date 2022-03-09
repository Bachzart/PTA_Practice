#include <cstdio>
#include <cmath>
int m, x, y, a, b, tmp, i, j;
double c, k;
void print(double t) {
	if(m < t) printf(" Cong");
	else if(m == t) printf(" Ping");
	else printf(" Gai");
}
int main() {
	scanf("%d %d %d", &m, &x, &y);
	bool flag = false;
	for(i = 10; i <= 99; i++) {
		tmp = i;
		j = tmp % 10 * 10 + tmp / 10;
		k = abs(i - j) * 1.0 / x;
		if(j == y * k) {
			flag = true;
			a = i, b = j, c = k;
		}
	}
	if(flag) {
		printf("%d", a);
		print(a), print(b), print(c);
	} else printf("No Solution");
	return 0;
}
