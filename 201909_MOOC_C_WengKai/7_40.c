#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	double diff, height, weight, standard;
	while(n--) {
		scanf("%lf %lf", &height, &weight);
		standard = (height - 100) * 0.9 * 2;
		diff = weight - standard;
		if(-standard * 0.1 < diff && diff < standard * 0.1) {
			printf("You are wan mei!\n");
		} else if(diff <= -standard * 0.1) printf("You are tai shou le!\n");
		else printf("You are tai pang le!\n");
	}
	return 0;
} 
