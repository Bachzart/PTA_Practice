#include <stdio.h>
#include <stdbool.h>
#define maxn 100005
int array[maxn], n;
void swap(int *p1, int *p2) {
	int t = *p1;
	*p1 = *p2;
	*p2 = t;
}
int scanformin(int *array, int left, int end) {
	int minpost = left, min = array[left];
	for(int i = left + 1; i < end; i++) {
		if(min > array[i]) {
			min = array[i];
			minpost = i;
		}
	}
	return minpost;
}
void selection_sort(int *array, int n) {
	for(int i = 0; i < n; i++) {
		int minpost = scanformin(array, i, n);
		swap(&array[minpost], &array[i]);
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", array + i);
	}
	selection_sort(array, n);
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
