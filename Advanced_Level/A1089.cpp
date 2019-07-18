#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 10;
int ori[MAXN], tempOri[MAXN], changed[MAXN];
int n;

bool isSame(int A[], int B[]) {
	for(int i = 0; i < n; i++) {
		if(A[i] != B[i]) return false;
	}
	return true;
}

void showArray(int A[]) {
	for(int i = 0; i < n; i++) {
		printf("%d", A[i]);
		if(i < n - 1) putchar(' ');
	}
}

bool InsertionSort() {
	bool flag = false;
	for(int i = 1; i < n; i++) {
		if(i != 1 && isSame(tempOri, changed)) {
			flag = true;
		}
		int temp = tempOri[i], j = i;
		while(j > 0 && tempOri[j - 1] > temp) {
			tempOri[j] = tempOri[j - 1];
			j--;
		}
		tempOri[j] = temp;
		if(flag) {
			return true;
		}
	}
	return false;
}

void MergeSort() {
	bool flag = false;
	for(int step = 2; step / 2 <= n; step *= 2) {
		if(step != 2 && isSame(tempOri, changed)) {
			flag = true;
		}
		for(int i = 0; i < n; i += step) {
			sort(tempOri + i, tempOri + min(i + step, n));
		}
		if(flag) {
			showArray(tempOri);
			return;
		} 
	}
}

int main(int argc, char const *argv[]) {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &ori[i]);
		tempOri[i] = ori[i];
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &changed[i]);
	}
	if(InsertionSort()) {
		printf("Insertion Sort\n");
		showArray(tempOri);
	} else {
		printf("Merge Sort\n");
		for(int i = 0; i < n; i++) {
			tempOri[i] = ori[i];
		}
		MergeSort();
	}
	return 0;
}
