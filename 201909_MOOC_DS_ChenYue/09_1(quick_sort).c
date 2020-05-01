#include <stdio.h>
#include <stdbool.h>
#define maxn 100005
int array[maxn], n;
void swap(int *p1, int *p2) {
	int t = *p1;
	*p1 = *p2;
	*p2 = t;
}
void insertion_sort(int *array, int n) {
	for(int i = 1; i < n; i++) {
		int tmp = array[i], j;
		for(j = i; j > 0 && tmp < array[j - 1]; j--) {
			array[j] = array[j - 1];
		}
		array[j] = tmp;
	}
}
int median3(int *array, int left, int right) {
	int center = (left + right) / 2;
	if(array[left] > array[center]) swap(&array[left], &array[center]);
	if(array[left] > array[right]) swap(&array[left], &array[right]);
	if(array[center] > array[right]) swap(&array[center], &array[right]);
	swap(&array[center], &array[right - 1]);
	return array[right - 1];
}
void myqsort(int *array, int left, int right) {
	int pivot, cutoff, low, high;
	cutoff = 3;
	if(cutoff <= right - left) {
		pivot = median3(array, left, right);
		low = left, high = right - 1;
		
		printf("pivot = %d\n", pivot);
		for(int i = 0; i < n; i++) {
			printf("%d ", array[i]);
		} 
		printf("\n");
		
		while(true) {
			while(array[++low] < pivot);
			while(array[--high] > pivot);
			if(low < high) swap(&array[low], &array[high]);
			else break;
		}
		swap(&array[low], &array[right - 1]);
		
		for(int i = 0; i < n; i++) {
			printf("%d ", array[i]);
		} 
		printf("\n");
		
		myqsort(array, left, low - 1);
		myqsort(array, low + 1, right);
	} else insertion_sort(array + left, right - left + 1);
}
void quick_sort(int *array, int n) {
	myqsort(array, 0, n - 1);
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", array + i);
	}
	quick_sort(array, n);
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
