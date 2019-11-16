#include <stdio.h>
#include <stdlib.h>
#define maxn 100005
int array[maxn], n;
void merge(int *array, int *tmparr, int left, int right, int rightend) {
	int leftend = right - 1, tmp = left;
	int numofelements = rightend - left + 1;
	while(left <= leftend && right <= rightend) {
		if(array[left] < array[right]) tmparr[tmp++] = array[left++];
		else tmparr[tmp++] = array[right++];
	}
	while(left <= leftend) tmparr[tmp++] = array[left++];
	while(right <= rightend) tmparr[tmp++] = array[right++];
	for(int i = 0; i < numofelements; i++, rightend--) {
		array[rightend] = tmparr[rightend];
	}
}
void merge_pass(int *array, int *tmparr, int n, int length) {
	int i, j;
	for(i = 0; i <= n - 2 * length; i += (2 * length)) {
		merge(array, tmparr, i, i + length, i + 2 * length - 1);
	}
	if(i + length < n) merge(array, tmparr, i, i + length, n - 1);
	else for(j = i; j < n; j++) tmparr[j] = array[j];
}
void merge_sort(int *array, int n) {
	int *tmparr;
	tmparr = (int*)malloc(n * sizeof(int));
	if(tmparr != NULL) {
		int length = 1;
		while(length < n) {
			merge_pass(array, tmparr, n, length);
			length *= 2;
			merge_pass(tmparr, array, n, length);
			length *= 2;
		}
		free(tmparr);
	} else return;
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", array + i);
	}
	merge_sort(array, n);
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
