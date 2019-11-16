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
void msort(int *array, int *tmparr, int left, int rightend) {
	int center;
	if(left < rightend) {
		center = (left + rightend) / 2;
		msort(array, tmparr, left, center);
		msort(array, tmparr, center + 1, rightend);
		merge(array, tmparr, left, center + 1, rightend);
	}
}
void merge_sort(int *array, int n) {
	int *tmparr;
	tmparr = (int*)malloc(n * sizeof(int));
	if(tmparr != NULL) {
		msort(array, tmparr, 0, n - 1);
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
