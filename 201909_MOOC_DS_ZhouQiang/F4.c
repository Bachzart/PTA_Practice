#include <stdio.h>
void reverse(int* array, int size);
int main()
{
	int n;
	scanf("%d", &n);
	int array[n];
	for (int i = 0; i < n; i++) scanf("%d", array + i);
	reverse(array, n);
	for (int i = 0; i < n - 1; i++) printf("%d ", array[i]);
	printf("%d", array[n - 1]);
	return 0;
}

void reverse(int* array, int size) {
	int i = 0, temp;
	for (; i < size / 2; i++) {
		temp = a[i];
		a[i] = a[size - i - 1];
		a[size - i - 1] = temp;
	}
}