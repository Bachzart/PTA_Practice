#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define maxn 105
int tar[maxn], arr[maxn], tmparr[maxn], n;
void swap(int *p1, int *p2) {
	int t = *p1;
	*p1 = *p2;
	*p2 = t;
}
bool issame(int *a) {
    for(int i = 0; i < n; i++) {
        if(a[i] != tar[i]) return false;
    }
    return true;
}
void printarray(const int *array, int size) {
    for(int i = 0; i < n; i++) {
        printf("%d", array[i]);
        if(i < n - 1) putchar(' ');
    }
}
void insert_pass(int *array, int pos) {
    int tmp = array[pos], j;
    for(j = pos; j > 0 && tmp < array[j - 1]; j--) {
        array[j] = array[j - 1];
    }
    array[j] = tmp;
}
bool isinsert(int *array, int n, int *round) {
    for(int i = 1; i < n; i++) {
        insert_pass(array, i);
        if(issame(array)) {
            *round = i + 1;
            return true;
        }
    }
    return false;
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
	int i;
	for(i = n - 1; i > 0; i--) {
		if(issame(array)) break;
		swap(&array[0], &array[i]);
		Percolatedown(array, 0, i);
	}
	swap(&array[0], &array[i]);
	Percolatedown(array, 0, i);
	printarray(array, n);
}
int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        tmparr[i] = arr[i];
    }
    for(int i = 0; i < n; i++) {
        scanf("%d", &tar[i]);
    }
    int round = 0;
    if(isinsert(tmparr, n, &round)) {
        printf("Insertion Sort\n");
        insert_pass(tmparr, round);
        printarray(tmparr, n);
    } else {
        for(int i = 0; i < n; i++) tmparr[i] = arr[i];
		printf("Heap Sort\n");
        heap_sort(tmparr, n);
    }
    return 0;
}

/*
samples:
in:
10
3 1 2 8 7 5 9 4 6 0
1 2 3 7 8 5 9 4 6 0
out:
Insertion Sort
1 2 3 5 7 8 9 4 6 0

in:
10
3 1 2 8 7 5 9 4 6 0
6 4 5 1 0 3 2 7 8 9
out:
Heap Sort
5 4 3 1 0 2 6 7 8 9


*/
