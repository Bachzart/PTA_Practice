#include <cstdio>
#include <cmath>

int main() {
	int a, d, tmp, digit = 0, b;
	scanf("%d %d", &a, &d);
	tmp = a;
	while(tmp != 0) {
		tmp /= 10;
		digit++;
	}
	tmp = a % (int)pow(10, d);
	b = tmp * pow(10, digit - d) + a / pow(10, d);
	printf("%.2lf", b * 1.0 / a);
}
