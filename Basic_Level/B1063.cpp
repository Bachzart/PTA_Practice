#include <cstdio>
#include <cmath>

int main() {
	int n;
	scanf("%d", &n);
	double rep, imp, pradius = 0.0, tmp;
	while(n--) {
		scanf("%lf %lf", &rep, &imp);
		tmp = sqrt(rep * rep + imp * imp);
		if(tmp > pradius) pradius = tmp;
	}
	printf("%.2lf", pradius);
	return 0;
} 
