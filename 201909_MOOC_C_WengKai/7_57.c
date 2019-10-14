#include <stdio.h>

int main() {
	int n, x, i, temp;
	scanf("%d %d", &n, &x);
	for(i = 0; i < n; i++) {
		scanf("%d", &temp);
		if(temp == x) break;
	}
	if(i < n) printf("%d", i);
	else printf("Not Found");
	return 0;
}
