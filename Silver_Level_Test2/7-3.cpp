#include <cstdio>
#include <cmath>

int main() {
	double weight, height, res;
	scanf("%lf %lf", &weight, &height);
	res = weight / pow(height, 2);
	printf("%.1lf\n", res);
	if(res > 25) printf("PANG\n");
	else printf("Hai Xing\n");
	return 0;
}
