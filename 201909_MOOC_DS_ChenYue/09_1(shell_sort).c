#include <stdio.h>
#include <stdbool.h>
#define maxn 100005
int array[maxn], n;
void shell_sort(int *array, int n) {
	int si, d, i, j, tmp;
	int Sedgewick[] = {929, 505, 209, 109, 41, 19, 5, 1, 0};
	for(si = 0; Sedgewick[si] >= n; si++);
	for(d = Sedgewick[si]; d > 0; d = Sedgewick[++si]) {
		for(i = d; i < n; i++) {
			tmp = array[i];
			for(j = i; j >= d && array[j - d] > tmp; j -= d) {
				array[j] = array[j - d];
			}
			array[j] = tmp;
		}
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", array + i);
	}
	shell_sort(array, n);
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
