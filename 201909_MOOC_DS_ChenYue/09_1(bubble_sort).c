#include <stdio.h>
#include <stdbool.h>
#define maxn 100005
int array[maxn], n;
void swap(int *p1, int *p2) {
	int t = *p1;
	*p1 = *p2;
	*p2 = t;
}
void bubble_sort(int *array, int n) {
	for(int i = n - 1; i > 0; i--) {
		bool flag = true;
		for(int j = 0; j < i; j++) {
			if(array[j] > array[j + 1]){
				swap(&array[j], &array[j + 1]);
				flag = false;
			}
		}
		if(flag) break;
	}
}
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", array + i);
	}
	bubble_sort(array, n);
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
