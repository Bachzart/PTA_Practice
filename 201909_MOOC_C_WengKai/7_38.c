#include <stdio.h>
#include <stdbool.h>
int main() {
	int n, y, f;
	scanf("%d", &n);
	bool flag = false;
	for(y = 0; y < 200; y++) {
		for(f = 0; f < 100; f++) {
			if(f * 98 - 199 * y == n) {
				flag = true;
				break;
			}
		}
		if(flag) break;
	}
	if(flag) printf("%d.%d", y, f);
	else printf("No Solution");
	return 0;
} 
