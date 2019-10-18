/* method 1: print directly */
#include <stdio.h>
int main() {
	int i, n, array[15];
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	for(i = n - 1; i >= 0; i--) {
		printf("%d", array[i]);
		if(i != 0) printf(" ");
	}
	return 0;
}

/* method 2: reverse array

#include <stdio.h>
#define maxn 15
int main() {
	int n, array[maxn], i;
	scanf("%d", &n);
	for(i = 0; i < n; i++) {
		scanf("%d", &array[i]);
	}
	int j;
	for(i = 0, j = n - 1; i <= j; i++, j--) {
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
	}
	for(i = 0; i < n; i++) {
		printf("%d", array[i]);
		if(i < n - 1) printf(" ");
	}
	return 0;
}

*/

/* other method: also can use stack */
