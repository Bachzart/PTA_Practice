#include <stdio.h>
#define maxn 100005
int array[maxn], n;
void insertion_sort(int *array, int n) {
	for(int i = 1; i < n; i++) {
		int tmp = array[i], j;
		for(j = i; j > 0 && tmp < array[j - 1]; j--) {
			array[j] = array[j - 1];
		}
		array[j] = tmp;
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", array + i);
	}
	insertion_sort(array, n);
	for(int i = 0; i < n; i++) {
		printf("%d", array[i]);
		if(i < n - 1) putchar(' ');
	}
	return 0;
} 

/*
samples:
in:
11
4 981 10 -17 0 -20 29 50 8 43 -5
out:
-20 -17 -5 0 4 8 10 29 43 50 981

*/
