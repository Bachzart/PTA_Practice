#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 110;
int origin[maxn], tempori[maxn], changed[maxn];
int n;
bool isSame(int A[], int B[]) {
	for(int i = 1; i <= n; i++) {
		if(A[i] != B[i]) return false;
	}
	return true;
}
bool showArray(int A[]) {
	for(int i = 1; i <= n; i++) {
		printf("%d", A[i]);
		if(i < n) putchar(' ');
	}
	putchar('\n');
}
bool insertSort() {
	bool flag = false;
	for(int i = 2; i <= n; i++) {
		if(i != 2 && isSame(tempori, changed)) {
			flag = true;
		}
		sort(tempori, tempori + i + 1);
		if(flag == true) {
			return true;
		}
	}
	return false;
}
void downAdjust(int low, int high) {
	int i = low, j = 2 * i;
	while(j <= high) {
		if(j + 1 <= high && tempori[j + 1] > tempori[j]) {
			j = j + 1;
		}
		if(tempori[j] > tempori[i]) {
			swap(tempori[j], tempori[i]);
			i = j;
			j = i * 2;
		} else {
			break;
		}
	}
}
void heapSort() {
	bool flag = false;
	for(int i = n / 2; i >= 1; i--) {
		downAdjust(i, n);
	}
	for(int i = n; i > 1; i--) {
		if(i != n && isSame(tempori, changed)) {
			flag = true;
		}
		swap(tempori[i], tempori[1]);
		downAdjust(1, i - 1);
		if(flag == true) {
			showArray(tempori);
			return;
		}
	}
}
int main(int argc, char const *argv[]) {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &origin[i]);
		tempori[i] = origin[i];
	}
	for(int i = 1; i <= n; i++) {
		scanf("%d", &changed[i]);
	}
	if(insertSort()) {
		printf("Insertion Sort\n");
		showArray(tempori);
	} else {
		printf("Heap Sort\n");
		for(int i = 1; i <= n; i++) {
			tempori[i] = origin[i];
		}
		heapSort();
	}
	
	return 0;
}
