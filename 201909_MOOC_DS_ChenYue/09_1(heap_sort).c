#include <stdio.h>
#include <stdbool.h>
#define maxn 100005
int array[maxn], n;
void swap(int *p1, int *p2) {
	int t = *p1;
	*p1 = *p2;
	*p2 = t;
}
void Percolatedown(int *heap, int pos, int size) {
	int parent, child, tmp = heap[pos];
	for(parent = pos; parent * 2 + 1 <= size - 1; parent = child) {
		child = parent * 2 + 1;
		if(child != size - 1 && heap[child] < heap[child + 1]) child++;
		if(tmp >= heap[child]) break;
		else heap[parent] = heap[child];
	}
	heap[parent] = tmp;
}
void heap_sort(int *array, int n) {
	for(int i = n / 2 - 1; i >= 0; i--) {
		Percolatedown(array, i, n);
	}
	for(int i = n - 1; i > 0; i--) {
		swap(&array[0], &array[i]);
		Percolatedown(array, 0, i);
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", array + i);
	}
	heap_sort(array, n);
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
