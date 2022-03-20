#include <cstdio>
#include <cmath>

int main() {
	int n, height, weight;
	double standard = 0.0;
	scanf("%d", &n);
	while(n--) {
		scanf("%d %d", &height, &weight);
		standard = (height - 100) * 0.9 * 2;
		if(fabs(weight - standard) < standard * 0.1) printf("You are wan mei!\n");
		else if(weight - standard < 0) printf("You are tai shou le!\n");
		else printf("You are tai pang le!\n");
	}
	return 0;
}
