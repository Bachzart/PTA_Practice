#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 100 + 5;
int origin[MAXN], tempOri[MAXN], changed[MAXN];
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
	putchar('\n');
}

bool InsertSort() {
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
		if(flag == true) {
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
		if(flag == true) {
			showArray(tempOri);
			return;
		}
	}
}

int main(int argc, char const *argv[]) {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &origin[i]);
		tempOri[i] = origin[i];
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &changed[i]);
	}
	if(InsertSort()) {
		printf("Insertion Sort\n");
		showArray(tempOri);
	} else {
		printf("Merge Sort\n");
		for(int i = 0; i < n; i++) {
			tempOri[i] = origin[i];
		}
		MergeSort();
	}
	return 0;
}
